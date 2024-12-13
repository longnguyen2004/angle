//
// Copyright 2021 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// EGLDisplaySelectionTest.cpp:
//   Checks display selection and caching with EGL extensions EGL_ANGLE_display_power_preference,
//   EGL_ANGLE_platform_angle, and EGL_ANGLE_device_id
//

#include <gtest/gtest.h>

#include "common/debug.h"
#include "common/string_utils.h"
#include "common/vulkan/vk_headers.h"
#include "common/vulkan/vulkan_icd.h"
#include "gpu_info_util/SystemInfo.h"
#include "test_utils/ANGLETest.h"
#include "test_utils/system_info_util.h"
#include "util/OSWindow.h"

using namespace angle;

class EGLDisplaySelectionTest : public ANGLETest<>
{
  public:
    void testSetUp() override { (void)GetSystemInfo(&mSystemInfo); }

  protected:
    // Returns the index of the low or high power GPU in SystemInfo depending on the argument.
    int findGPU(bool lowPower) const
    {
        if (lowPower)
            return FindLowPowerGPU(mSystemInfo);
        return FindHighPowerGPU(mSystemInfo);
    }

    // Returns the index of the active GPU in SystemInfo based on the renderer string.
    int findActiveGPU() const { return FindActiveOpenGLGPU(mSystemInfo); }

    SystemInfo mSystemInfo;
};

class EGLDisplaySelectionTestNoFixture : public EGLDisplaySelectionTest
{
  protected:
    void terminateWindow()
    {
        if (mOSWindow)
        {
            OSWindow::Delete(&mOSWindow);
        }
    }

    void terminateDisplay(EGLDisplay display)
    {
        EXPECT_EGL_TRUE(eglTerminate(display));
        EXPECT_EGL_SUCCESS();
    }

    void terminateContext(EGLDisplay display, EGLContext context)
    {
        if (context != EGL_NO_CONTEXT)
        {
            eglDestroyContext(display, context);
            ASSERT_EGL_SUCCESS();
        }
    }

    void initializeWindow()
    {
        mOSWindow = OSWindow::New();
        mOSWindow->initialize("EGLDisplaySelectionTestMultiDisplay", kWindowWidth, kWindowHeight);
        setWindowVisible(mOSWindow, true);
    }

    void initializeContextForDisplay(EGLDisplay display, EGLContext *context)
    {
        // Find a default config.
        const EGLint configAttributes[] = {
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT, EGL_RED_SIZE,     EGL_DONT_CARE,  EGL_GREEN_SIZE,
            EGL_DONT_CARE,    EGL_BLUE_SIZE,  EGL_DONT_CARE,    EGL_ALPHA_SIZE, EGL_DONT_CARE,
            EGL_DEPTH_SIZE,   EGL_DONT_CARE,  EGL_STENCIL_SIZE, EGL_DONT_CARE,  EGL_NONE};

        EGLint configCount;
        EGLConfig config;
        EGLint ret = eglChooseConfig(display, configAttributes, &config, 1, &configCount);

        if (!ret || configCount == 0)
        {
            return;
        }

        EGLint contextAttributes[] = {
            EGL_CONTEXT_MAJOR_VERSION_KHR,
            GetParam().majorVersion,
            EGL_CONTEXT_MINOR_VERSION_KHR,
            GetParam().minorVersion,
            EGL_NONE,
        };

        *context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttributes);
        ASSERT_TRUE(*context != EGL_NO_CONTEXT);
    }

    static constexpr int kWindowWidth  = 16;
    static constexpr int kWindowHeight = 8;

    OSWindow *mOSWindow = nullptr;
};

class EGLDisplaySelectionTestMultiDisplay : public EGLDisplaySelectionTestNoFixture
{

  protected:
    void initializeDisplayWithPowerPreference(EGLDisplay *display, EGLAttrib powerPreference)
    {
        GLenum platformType = GetParam().getRenderer();
        GLenum deviceType   = GetParam().getDeviceType();

        std::vector<EGLint> displayAttributes;
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_TYPE_ANGLE);
        displayAttributes.push_back(platformType);
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_MAX_VERSION_MAJOR_ANGLE);
        displayAttributes.push_back(EGL_DONT_CARE);
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_MAX_VERSION_MINOR_ANGLE);
        displayAttributes.push_back(EGL_DONT_CARE);
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_DEVICE_TYPE_ANGLE);
        displayAttributes.push_back(deviceType);
        displayAttributes.push_back(EGL_POWER_PREFERENCE_ANGLE);
        displayAttributes.push_back(powerPreference);
        displayAttributes.push_back(EGL_NONE);

        *display = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE,
                                            reinterpret_cast<void *>(mOSWindow->getNativeDisplay()),
                                            displayAttributes.data());
        ASSERT_TRUE(*display != EGL_NO_DISPLAY);

        EGLint majorVersion, minorVersion;
        ASSERT_TRUE(eglInitialize(*display, &majorVersion, &minorVersion) == EGL_TRUE);

        eglBindAPI(EGL_OPENGL_ES_API);
        ASSERT_EGL_SUCCESS();
    }

    void initializeDisplayWithBackend(EGLDisplay *display, EGLAttrib platformType)
    {
        GLenum deviceType = GetParam().getDeviceType();

        std::vector<EGLint> displayAttributes;
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_TYPE_ANGLE);
        displayAttributes.push_back(platformType);
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_MAX_VERSION_MAJOR_ANGLE);
        displayAttributes.push_back(EGL_DONT_CARE);
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_MAX_VERSION_MINOR_ANGLE);
        displayAttributes.push_back(EGL_DONT_CARE);
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_DEVICE_TYPE_ANGLE);
        displayAttributes.push_back(deviceType);
        displayAttributes.push_back(EGL_NONE);

        *display = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE,
                                            reinterpret_cast<void *>(mOSWindow->getNativeDisplay()),
                                            displayAttributes.data());
        ASSERT_TRUE(*display != EGL_NO_DISPLAY);

        EGLint majorVersion, minorVersion;
        ASSERT_TRUE(eglInitialize(*display, &majorVersion, &minorVersion) == EGL_TRUE);

        eglBindAPI(EGL_OPENGL_ES_API);
        ASSERT_EGL_SUCCESS();
    }

    void runReinitializeDisplayPowerPreference(EGLAttrib powerPreference)
    {
        initializeWindow();

        // Initialize the display with the selected power preference
        EGLDisplay display;
        EGLContext context;
        initializeDisplayWithPowerPreference(&display, powerPreference);
        initializeContextForDisplay(display, &context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, context);

        bool lowPower = (powerPreference == EGL_LOW_POWER_ANGLE);
        ASSERT_EQ(findGPU(lowPower), findActiveGPU());

        // Terminate the display
        terminateContext(display, context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        terminateDisplay(display);

        // Change the power preference
        if (powerPreference == EGL_LOW_POWER_ANGLE)
        {
            powerPreference = EGL_HIGH_POWER_ANGLE;
        }
        else
        {
            powerPreference = EGL_LOW_POWER_ANGLE;
        }

        // Reinitialize the display with a new power preference
        initializeDisplayWithPowerPreference(&display, powerPreference);
        initializeContextForDisplay(display, &context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, context);

        // Expect that the power preference has changed
        lowPower = (powerPreference == EGL_LOW_POWER_ANGLE);
        ASSERT_EQ(findGPU(lowPower), findActiveGPU());

        // Terminate the display
        terminateContext(display, context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        terminateDisplay(display);

        terminateWindow();
    }

    void runMultiDisplayBackend(EGLAttrib backend1,
                                bool(checkFunc1)(void),
                                EGLAttrib backend2,
                                bool(checkFunc2)(void))
    {
        initializeWindow();

        // Initialize the display with the selected backend
        EGLDisplay display1;
        EGLContext context1;
        initializeDisplayWithBackend(&display1, backend1);
        initializeContextForDisplay(display1, &context1);
        eglMakeCurrent(display1, EGL_NO_SURFACE, EGL_NO_SURFACE, context1);

        // Check that the correct backend is chosen
        ASSERT_TRUE(checkFunc1());

        // Initialize the second display with the second backend
        EGLDisplay display2;
        EGLContext context2;
        initializeDisplayWithBackend(&display2, backend2);
        initializeContextForDisplay(display2, &context2);
        eglMakeCurrent(display2, EGL_NO_SURFACE, EGL_NO_SURFACE, context2);

        // Check that the correct backend is chosen
        ASSERT_TRUE(checkFunc2());

        // Switch back to the first display to verify
        eglMakeCurrent(display1, EGL_NO_SURFACE, EGL_NO_SURFACE, context1);
        ASSERT_TRUE(checkFunc1());

        // Terminate the displays
        terminateContext(display1, context1);
        eglMakeCurrent(display1, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        terminateDisplay(display1);
        terminateContext(display2, context2);
        eglMakeCurrent(display2, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        terminateDisplay(display2);

        terminateWindow();
    }

    void runMultiDisplayBackendDefault(EGLAttrib backend, bool(checkFunc)(void))
    {
        initializeWindow();

        // Initialize the display with the selected backend
        EGLDisplay display1;
        EGLContext context1;
        initializeDisplayWithBackend(&display1, backend);
        initializeContextForDisplay(display1, &context1);
        eglMakeCurrent(display1, EGL_NO_SURFACE, EGL_NO_SURFACE, context1);

        // Check that the correct backend is chosen
        ASSERT_TRUE(checkFunc());

        // Initialize the second display with the second backend
        EGLDisplay display2;
        EGLContext context2;
        initializeDisplayWithBackend(&display2, EGL_PLATFORM_ANGLE_TYPE_DEFAULT_ANGLE);
        initializeContextForDisplay(display2, &context2);
        eglMakeCurrent(display2, EGL_NO_SURFACE, EGL_NO_SURFACE, context2);

        bool sameDisplay = false;
        // If this backend is the same as the first display, check that the display is cached
        if (checkFunc())
        {
            ASSERT_EQ(display1, display2);
            sameDisplay = true;
        }
        // If this backend is not the same, check that this is a different display
        else
        {
            ASSERT_NE(display1, display2);
        }

        // Switch back to the first display to verify
        eglMakeCurrent(display1, EGL_NO_SURFACE, EGL_NO_SURFACE, context1);
        ASSERT_TRUE(checkFunc());

        // Terminate the displays
        terminateContext(display1, context1);
        eglMakeCurrent(display1, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        if (!sameDisplay)
        {
            terminateDisplay(display1);
        }
        terminateContext(display2, context2);
        eglMakeCurrent(display2, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        terminateDisplay(display2);

        terminateWindow();
    }

    void runMultiDisplayPowerPreference()
    {
        initializeWindow();

        // Initialize the first display with low power
        EGLDisplay display1;
        EGLContext context1;
        initializeDisplayWithPowerPreference(&display1, EGL_LOW_POWER_ANGLE);
        initializeContextForDisplay(display1, &context1);
        eglMakeCurrent(display1, EGL_NO_SURFACE, EGL_NO_SURFACE, context1);

        ASSERT_EQ(findGPU(true), findActiveGPU());

        // Initialize the second display with high power
        EGLDisplay display2;
        EGLContext context2;
        initializeDisplayWithPowerPreference(&display2, EGL_HIGH_POWER_ANGLE);
        initializeContextForDisplay(display2, &context2);
        eglMakeCurrent(display2, EGL_NO_SURFACE, EGL_NO_SURFACE, context2);

        ASSERT_EQ(findGPU(false), findActiveGPU());

        // Switch back to the first display to verify
        eglMakeCurrent(display1, EGL_NO_SURFACE, EGL_NO_SURFACE, context1);
        ASSERT_EQ(findGPU(true), findActiveGPU());

        // Terminate the displays
        terminateContext(display1, context1);
        eglMakeCurrent(display1, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        terminateDisplay(display1);
        terminateContext(display2, context2);
        eglMakeCurrent(display2, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        terminateDisplay(display2);

        terminateWindow();
    }
};

TEST_P(EGLDisplaySelectionTest, SelectGPU)
{
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_display_power_preference"));
    ASSERT_NE(GetParam().eglParameters.displayPowerPreference, EGL_DONT_CARE);

    bool lowPower = (GetParam().eglParameters.displayPowerPreference == EGL_LOW_POWER_ANGLE);
    ASSERT_EQ(findGPU(lowPower), findActiveGPU());
}

TEST_P(EGLDisplaySelectionTestMultiDisplay, ReInitializePowerPreferenceLowToHigh)
{
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_display_power_preference"));

    runReinitializeDisplayPowerPreference(EGL_LOW_POWER_ANGLE);
}

TEST_P(EGLDisplaySelectionTestMultiDisplay, ReInitializePowerPreferenceHighToLow)
{
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_display_power_preference"));

    runReinitializeDisplayPowerPreference(EGL_HIGH_POWER_ANGLE);
}

TEST_P(EGLDisplaySelectionTestMultiDisplay, BackendMetalOpenGL)
{
    bool missingBackends = true;
#if defined(ANGLE_ENABLE_METAL) && defined(ANGLE_ENABLE_OPENGL)
    missingBackends = false;
#endif
    ANGLE_SKIP_TEST_IF(missingBackends);

    runMultiDisplayBackend(EGL_PLATFORM_ANGLE_TYPE_METAL_ANGLE, IsMetal,
                           EGL_PLATFORM_ANGLE_TYPE_OPENGL_ANGLE, IsOpenGL);
}

TEST_P(EGLDisplaySelectionTestMultiDisplay, BackendOpenGLMetal)
{
    bool missingBackends = true;
#if defined(ANGLE_ENABLE_METAL) && defined(ANGLE_ENABLE_OPENGL)
    missingBackends = false;
#endif
    ANGLE_SKIP_TEST_IF(missingBackends);

    runMultiDisplayBackend(EGL_PLATFORM_ANGLE_TYPE_OPENGL_ANGLE, IsOpenGL,
                           EGL_PLATFORM_ANGLE_TYPE_METAL_ANGLE, IsMetal);
}

TEST_P(EGLDisplaySelectionTestMultiDisplay, BackendVulkanD3D11)
{
    bool missingBackends = true;
#if defined(ANGLE_ENABLE_VULKAN) && defined(ANGLE_ENABLE_D3D11)
    missingBackends = false;
#endif
    ANGLE_SKIP_TEST_IF(missingBackends);

    runMultiDisplayBackend(EGL_PLATFORM_ANGLE_TYPE_VULKAN_ANGLE, IsVulkan,
                           EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE, IsD3D11);
}

TEST_P(EGLDisplaySelectionTestMultiDisplay, BackendD3D11Vulkan)
{
    bool missingBackends = true;
#if defined(ANGLE_ENABLE_VULKAN) && defined(ANGLE_ENABLE_D3D11)
    missingBackends = false;
#endif
    ANGLE_SKIP_TEST_IF(missingBackends);

    runMultiDisplayBackend(EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE, IsD3D11,
                           EGL_PLATFORM_ANGLE_TYPE_VULKAN_ANGLE, IsVulkan);
}

TEST_P(EGLDisplaySelectionTestMultiDisplay, BackendDefaultMetal)
{
    bool missingBackends = true;
#if defined(ANGLE_ENABLE_METAL)
    missingBackends = false;
#endif
    ANGLE_SKIP_TEST_IF(missingBackends);

    runMultiDisplayBackendDefault(EGL_PLATFORM_ANGLE_TYPE_METAL_ANGLE, IsMetal);
}

TEST_P(EGLDisplaySelectionTestMultiDisplay, BackendDefaultOpenGL)
{
    bool missingBackends = true;
#if defined(ANGLE_ENABLE_OPENGL)
    missingBackends = false;
#endif
    ANGLE_SKIP_TEST_IF(missingBackends);

    runMultiDisplayBackendDefault(EGL_PLATFORM_ANGLE_TYPE_OPENGL_ANGLE, IsOpenGL);
}

TEST_P(EGLDisplaySelectionTestMultiDisplay, BackendDefaultD3D11)
{
    bool missingBackends = true;
#if defined(ANGLE_ENABLE_D3D11)
    missingBackends = false;
#endif
    ANGLE_SKIP_TEST_IF(missingBackends);

    runMultiDisplayBackendDefault(EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE, IsD3D11);
}

TEST_P(EGLDisplaySelectionTestMultiDisplay, BackendDefaultVulkan)
{
    bool missingBackends = true;
#if defined(ANGLE_ENABLE_VULKAN)
    missingBackends = false;
#endif
    ANGLE_SKIP_TEST_IF(missingBackends);

    // http://anglebug.com/42265471
    ANGLE_SKIP_TEST_IF(IsMac());

    runMultiDisplayBackendDefault(EGL_PLATFORM_ANGLE_TYPE_VULKAN_ANGLE, IsVulkan);
}

TEST_P(EGLDisplaySelectionTestMultiDisplay, PowerPreference)
{
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_display_power_preference"));

    runMultiDisplayPowerPreference();
}

class EGLDisplaySelectionTestVulkanDeviceUUID : public EGLDisplaySelectionTestNoFixture
{
  public:
    void testSetUp() override { (void)GetSystemInfoVulkan(&mSystemInfo); }

  protected:
    void initializeDisplayWithDevice(EGLDisplay *display,
                                     uint8_t const *deviceUUID,
                                     uint8_t const *driverUUID,
                                     VkDriverId driverId,
                                     bool expectValidDisplay)
    {
        GLenum platformType = GetParam().getRenderer();

        std::vector<EGLAttrib> displayAttributes;
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_TYPE_ANGLE);
        displayAttributes.push_back(platformType);
        if (deviceUUID != nullptr)
        {
            displayAttributes.push_back(EGL_PLATFORM_ANGLE_VULKAN_DEVICE_UUID_ANGLE);
            displayAttributes.push_back(reinterpret_cast<EGLAttrib>(deviceUUID));
        }
        if (driverUUID != nullptr)
        {
            displayAttributes.push_back(EGL_PLATFORM_ANGLE_VULKAN_DRIVER_UUID_ANGLE);
            displayAttributes.push_back(reinterpret_cast<EGLAttrib>(driverUUID));
        }
        if (driverId != 0)
        {
            displayAttributes.push_back(EGL_PLATFORM_ANGLE_VULKAN_DRIVER_ID_ANGLE);
            displayAttributes.push_back(static_cast<EGLAttrib>(driverId));
        }
        displayAttributes.push_back(EGL_NONE);

        *display = eglGetPlatformDisplay(EGL_PLATFORM_ANGLE_ANGLE,
                                         reinterpret_cast<void *>(mOSWindow->getNativeDisplay()),
                                         displayAttributes.data());

        if (expectValidDisplay)
        {
            EXPECT_NE(*display, EGL_NO_DISPLAY);
        }
        else
        {
            EXPECT_EQ(*display, EGL_NO_DISPLAY);
            return;
        }

        EGLint majorVersion, minorVersion;
        ASSERT_TRUE(eglInitialize(*display, &majorVersion, &minorVersion) == EGL_TRUE);

        eglBindAPI(EGL_OPENGL_ES_API);
        ASSERT_EGL_SUCCESS();
    }

    static bool isValidUUID(uint8_t const *uuid)
    {
        // We expect at least one nonzero byte in the UUID.
        for (size_t i = 0; i < 16; ++i)
        {
            if (uuid[i] != 0)
            {
                return true;
            }
        }
        return false;
    }
};

// Test the functionality of the EGL_ANGLE_platform_angle_vulkan_device_uuid,
// ensuring that a passed device UUID is correctly rejected by everything but
// the Vulkan backend, and that the intended device is used for the newly
// created context.
TEST_P(EGLDisplaySelectionTestVulkanDeviceUUID, ValidDeviceUUID)
{
    // Need EGL 1.5's eglGetPlatformDisplay so we pass EGLAttrib instead of EGLint
    ANGLE_SKIP_TEST_IF(!eglGetPlatformDisplay);

    // Need support for Vulkan and the device UUID extension
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_platform_angle_vulkan"));
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_platform_angle_vulkan_device_uuid"));

    // Need device query support to verify device UUIDs match their targets
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_EXT_device_query"));

    // Shouldn't happen, but covering all the bases.
    ANGLE_SKIP_TEST_IF(mSystemInfo.gpus.empty());

    const bool isVulkan = GetParam().isVulkan();

    initializeWindow();

    // For testing the EGL_BAD_ATTRIBUTE path when a device UUID is passed
    // without selecting the Vulkan backend.
    uint8_t const bogusUUID[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    for (size_t i = 0; i < mSystemInfo.gpus.size(); i++)
    {
        // If we're using the Vulkan backend, pass the device UUID. If not, pass
        // a bogus UUID to test the EGL_BAD_ATTRIBUTE path.
        uint8_t const *targetDeviceUUID = isVulkan ? mSystemInfo.gpus[i].deviceUUID : bogusUUID;

        // If device UUID is all zeros, skip this device, it's not Vulkan 1.1 capable.
        if (!isValidUUID(targetDeviceUUID))
        {
            continue;
        }

        // Initialize the display with device UUID for each GPU
        EGLDisplay display;
        EGLContext context;

        // Try to request a display with this specific device UUID. Passing the
        // UUID to a non-Vulkan backend should generate an EGL validation error.
        initializeDisplayWithDevice(&display, targetDeviceUUID, nullptr, static_cast<VkDriverId>(0),
                                    isVulkan);

        if (!isVulkan)
        {
            // We don't need to test against every device to verify that we got
            // the EGL error.
            EXPECT_EGL_ERROR(EGL_BAD_ATTRIBUTE);
            if (display != EGL_NO_DISPLAY)
            {
                terminateDisplay(display);
            }
            terminateWindow();
            return;
        }

        initializeContextForDisplay(display, &context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, context);

        // Now verify that the display's physical device has the same UUID as
        // the one we requested. This requires jumping through several hoops to
        // get the right introspection.
        EGLAttrib result = 0;
        EXPECT_EGL_TRUE(eglQueryDisplayAttribEXT(display, EGL_DEVICE_EXT, &result));

        EGLDeviceEXT device = reinterpret_cast<EGLDeviceEXT>(result);
        EXPECT_NE(EGL_NO_DEVICE_EXT, device);
        EXPECT_TRUE(IsEGLDeviceExtensionEnabled(device, "EGL_ANGLE_device_vulkan"));

#if ANGLE_SHARED_LIBVULKAN
        EXPECT_EGL_TRUE(
            eglQueryDeviceAttribEXT(device, EGL_VULKAN_GET_INSTANCE_PROC_ADDR, &result));
        PFN_vkGetInstanceProcAddr getInstanceProcAddr =
            reinterpret_cast<PFN_vkGetInstanceProcAddr>(result);
        EXPECT_NE(getInstanceProcAddr, nullptr);

        EXPECT_EGL_TRUE(eglQueryDeviceAttribEXT(device, EGL_VULKAN_INSTANCE_ANGLE, &result));
        VkInstance instance = reinterpret_cast<VkInstance>(result);
        EXPECT_NE(instance, static_cast<VkInstance>(VK_NULL_HANDLE));

        vkGetPhysicalDeviceProperties2 = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties2>(
            getInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties2"));
#endif  // ANGLE_SHARED_LIBVULKAN

        EXPECT_EGL_TRUE(eglQueryDeviceAttribEXT(device, EGL_VULKAN_PHYSICAL_DEVICE_ANGLE, &result));
        VkPhysicalDevice physicalDevice = reinterpret_cast<VkPhysicalDevice>(result);
        EXPECT_NE(physicalDevice, static_cast<VkPhysicalDevice>(VK_NULL_HANDLE));

        VkPhysicalDeviceProperties2 deviceProperties2 = {};
        deviceProperties2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;

        VkPhysicalDeviceIDProperties deviceIDProperties = {};
        deviceIDProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;

        deviceProperties2.pNext = &deviceIDProperties;

        vkGetPhysicalDeviceProperties2(physicalDevice, &deviceProperties2);

        EXPECT_EQ(memcmp(targetDeviceUUID, deviceIDProperties.deviceUUID, VK_UUID_SIZE), 0);

        // Terminate the displays
        terminateContext(display, context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        terminateDisplay(display);
        ASSERT_EGL_SUCCESS();
    }

    terminateWindow();

    ASSERT_EGL_SUCCESS();
}

// Test the functionality of the EGL_ANGLE_platform_angle_vulkan_device_uuid,
// ensuring that a passed driver UUID is correctly rejected by everything but
// the Vulkan backend, and that the intended device is used for the newly
// created context.
TEST_P(EGLDisplaySelectionTestVulkanDeviceUUID, ValidDriverUUID)
{
    // Need EGL 1.5's eglGetPlatformDisplay so we pass EGLAttrib instead of EGLint
    ANGLE_SKIP_TEST_IF(!eglGetPlatformDisplay);

    // Need support for Vulkan and the device UUID extension
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_platform_angle_vulkan"));
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_platform_angle_vulkan_device_uuid"));

    // Need device query support to verify driver UUIDs match their targets
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_EXT_device_query"));

    // Shouldn't happen, but covering all the bases.
    ANGLE_SKIP_TEST_IF(mSystemInfo.gpus.empty());

    const bool isVulkan = GetParam().isVulkan();

    initializeWindow();

    // For testing the EGL_BAD_ATTRIBUTE path when a driver UUID is passed
    // without selecting the Vulkan backend.
    uint8_t const bogusUUID[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    for (size_t i = 0; i < mSystemInfo.gpus.size(); i++)
    {
        // If we're using the Vulkan backend, pass the driver UUID. If not, pass
        // a bogus UUID to test the EGL_BAD_ATTRIBUTE path.
        uint8_t const *targetDriverUUID = isVulkan ? mSystemInfo.gpus[i].driverUUID : bogusUUID;

        // If driver UUID is all zeros, skip this device, it's not Vulkan 1.1 capable.
        if (!isValidUUID(targetDriverUUID))
        {
            continue;
        }

        // Initialize the display with driver UUID for each GPU
        EGLDisplay display;
        EGLContext context;

        // Try to request a display with this specific driver UUID. Passing the
        // UUID to a non-Vulkan backend should generate an EGL validation error.
        initializeDisplayWithDevice(&display, nullptr, targetDriverUUID, static_cast<VkDriverId>(0),
                                    isVulkan);

        if (!isVulkan)
        {
            // We don't need to test against every device to verify that we got
            // the EGL error.
            EXPECT_EGL_ERROR(EGL_BAD_ATTRIBUTE);
            if (display != EGL_NO_DISPLAY)
            {
                terminateDisplay(display);
            }
            terminateWindow();
            return;
        }

        initializeContextForDisplay(display, &context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, context);

        // Now verify that the display's physical device has the same driver
        // UUID as the one we requested. This requires jumping through several
        // hoops to get the right introspection.
        EGLAttrib result = 0;
        EXPECT_EGL_TRUE(eglQueryDisplayAttribEXT(display, EGL_DEVICE_EXT, &result));

        EGLDeviceEXT device = reinterpret_cast<EGLDeviceEXT>(result);
        EXPECT_NE(EGL_NO_DEVICE_EXT, device);
        EXPECT_TRUE(IsEGLDeviceExtensionEnabled(device, "EGL_ANGLE_device_vulkan"));

#if ANGLE_SHARED_LIBVULKAN
        EXPECT_EGL_TRUE(
            eglQueryDeviceAttribEXT(device, EGL_VULKAN_GET_INSTANCE_PROC_ADDR, &result));
        PFN_vkGetInstanceProcAddr getInstanceProcAddr =
            reinterpret_cast<PFN_vkGetInstanceProcAddr>(result);
        EXPECT_NE(getInstanceProcAddr, nullptr);

        EXPECT_EGL_TRUE(eglQueryDeviceAttribEXT(device, EGL_VULKAN_INSTANCE_ANGLE, &result));
        VkInstance instance = reinterpret_cast<VkInstance>(result);
        EXPECT_NE(instance, static_cast<VkInstance>(VK_NULL_HANDLE));

        vkGetPhysicalDeviceProperties2 = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties2>(
            getInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties2"));
#endif  // ANGLE_SHARED_LIBVULKAN

        EXPECT_EGL_TRUE(eglQueryDeviceAttribEXT(device, EGL_VULKAN_PHYSICAL_DEVICE_ANGLE, &result));
        VkPhysicalDevice physicalDevice = reinterpret_cast<VkPhysicalDevice>(result);
        EXPECT_NE(physicalDevice, static_cast<VkPhysicalDevice>(VK_NULL_HANDLE));

        VkPhysicalDeviceProperties2 deviceProperties2 = {};
        deviceProperties2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;

        VkPhysicalDeviceIDProperties deviceIDProperties = {};
        deviceIDProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;

        deviceProperties2.pNext = &deviceIDProperties;

        vkGetPhysicalDeviceProperties2(physicalDevice, &deviceProperties2);

        EXPECT_EQ(memcmp(targetDriverUUID, deviceIDProperties.driverUUID, VK_UUID_SIZE), 0);

        // Terminate the displays
        terminateContext(display, context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        terminateDisplay(display);
        ASSERT_EGL_SUCCESS();
    }

    terminateWindow();

    ASSERT_EGL_SUCCESS();
}

// Test the functionality of the EGL_ANGLE_platform_angle_vulkan_device_uuid,
// ensuring that a passed driver ID is correctly rejected by everything but the
// Vulkan backend, and that the intended device is used for the newly created
// context.
TEST_P(EGLDisplaySelectionTestVulkanDeviceUUID, ValidDriverID)
{
    // Need EGL 1.5's eglGetPlatformDisplay so we pass EGLAttrib instead of EGLint
    ANGLE_SKIP_TEST_IF(!eglGetPlatformDisplay);

    // Need support for Vulkan and the device UUID extension
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_platform_angle_vulkan"));
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_platform_angle_vulkan_device_uuid"));

    // Need device query support to verify driver IDs match their targets
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_EXT_device_query"));

    // Shouldn't happen, but covering all the bases.
    ANGLE_SKIP_TEST_IF(mSystemInfo.gpus.empty());

    const bool isVulkan = GetParam().isVulkan();

    initializeWindow();

    for (size_t i = 0; i < mSystemInfo.gpus.size(); i++)
    {
        // When trying to create a display without the Vulkan backend selected,
        // we should reject the passed driver ID attribute with
        // EGL_BAD_ATTRIBUTE. Ensure we have a nonzero attribute to test this
        // situation.
        VkDriverId const targetDriverId =
            isVulkan ? static_cast<VkDriverId>(mSystemInfo.gpus[i].driverId)
                     : VK_DRIVER_ID_MESA_HONEYKRISP;

        // If driver ID is invalid, skip testing this device
        if (targetDriverId == 0)
        {
            continue;
        }

        // Initialize the display with driver ID for each GPU
        EGLDisplay display;
        EGLContext context;

        // Try to request a display with this specific driver ID. Passing the
        // ID to a non-Vulkan backend should generate an EGL validation error.
        initializeDisplayWithDevice(&display, nullptr, nullptr, targetDriverId, isVulkan);

        if (!isVulkan)
        {
            // We don't need to test against every device to verify that we got
            // the EGL error.
            EXPECT_EGL_ERROR(EGL_BAD_ATTRIBUTE);
            if (display != EGL_NO_DISPLAY)
            {
                terminateDisplay(display);
            }
            terminateWindow();
            return;
        }

        initializeContextForDisplay(display, &context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, context);

        // Now verify that the display's physical device has the same UUID as
        // the one we requested. This requires jumping through several hoops to
        // get the right introspection.
        EGLAttrib result = 0;
        EXPECT_EGL_TRUE(eglQueryDisplayAttribEXT(display, EGL_DEVICE_EXT, &result));

        EGLDeviceEXT device = reinterpret_cast<EGLDeviceEXT>(result);
        EXPECT_NE(EGL_NO_DEVICE_EXT, device);
        EXPECT_TRUE(IsEGLDeviceExtensionEnabled(device, "EGL_ANGLE_device_vulkan"));

#if ANGLE_SHARED_LIBVULKAN
        EXPECT_EGL_TRUE(
            eglQueryDeviceAttribEXT(device, EGL_VULKAN_GET_INSTANCE_PROC_ADDR, &result));
        PFN_vkGetInstanceProcAddr getInstanceProcAddr =
            reinterpret_cast<PFN_vkGetInstanceProcAddr>(result);
        EXPECT_NE(getInstanceProcAddr, nullptr);

        EXPECT_EGL_TRUE(eglQueryDeviceAttribEXT(device, EGL_VULKAN_INSTANCE_ANGLE, &result));
        VkInstance instance = reinterpret_cast<VkInstance>(result);
        EXPECT_NE(instance, static_cast<VkInstance>(VK_NULL_HANDLE));

        vkGetPhysicalDeviceProperties2 = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties2>(
            getInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties2"));
#endif  // ANGLE_SHARED_LIBVULKAN

        EXPECT_EGL_TRUE(eglQueryDeviceAttribEXT(device, EGL_VULKAN_PHYSICAL_DEVICE_ANGLE, &result));
        VkPhysicalDevice physicalDevice = reinterpret_cast<VkPhysicalDevice>(result);
        EXPECT_NE(physicalDevice, static_cast<VkPhysicalDevice>(VK_NULL_HANDLE));

        VkPhysicalDeviceProperties2 deviceProperties2 = {};
        deviceProperties2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;

        VkPhysicalDeviceDriverProperties driverProperties = {};
        driverProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES;

        deviceProperties2.pNext = &driverProperties;

        vkGetPhysicalDeviceProperties2(physicalDevice, &deviceProperties2);

        EXPECT_EQ(driverProperties.driverID, targetDriverId);

        // Terminate the displays
        terminateContext(display, context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        terminateDisplay(display);
        ASSERT_EGL_SUCCESS();
    }

    terminateWindow();

    ASSERT_EGL_SUCCESS();
}

class EGLDisplaySelectionTestDeviceId : public EGLDisplaySelectionTestNoFixture
{

  protected:
    void initializeDisplayWithDeviceId(EGLDisplay *display, uint64_t deviceId)
    {
        GLenum platformType          = GetParam().getRenderer();
        GLenum deviceType            = GetParam().getDeviceType();
        GLint displayPowerPreference = GetParam().eglParameters.displayPowerPreference;

        EGLAttrib high = ((deviceId >> 32) & 0xFFFFFFFF);
        EGLAttrib low  = (deviceId & 0xFFFFFFFF);

        std::vector<EGLint> displayAttributes;
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_TYPE_ANGLE);
        displayAttributes.push_back(platformType);
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_MAX_VERSION_MAJOR_ANGLE);
        displayAttributes.push_back(EGL_DONT_CARE);
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_MAX_VERSION_MINOR_ANGLE);
        displayAttributes.push_back(EGL_DONT_CARE);
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_DEVICE_TYPE_ANGLE);
        displayAttributes.push_back(deviceType);
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_DEVICE_ID_HIGH_ANGLE);
        displayAttributes.push_back(high);
        displayAttributes.push_back(EGL_PLATFORM_ANGLE_DEVICE_ID_LOW_ANGLE);
        displayAttributes.push_back(low);
        if (displayPowerPreference != EGL_DONT_CARE)
        {
            displayAttributes.push_back(EGL_POWER_PREFERENCE_ANGLE);
            displayAttributes.push_back(displayPowerPreference);
        }
        displayAttributes.push_back(EGL_NONE);

        *display = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE,
                                            reinterpret_cast<void *>(mOSWindow->getNativeDisplay()),
                                            displayAttributes.data());
        ASSERT_TRUE(*display != EGL_NO_DISPLAY);

        EGLint majorVersion, minorVersion;
        ASSERT_TRUE(eglInitialize(*display, &majorVersion, &minorVersion) == EGL_TRUE);

        eglBindAPI(EGL_OPENGL_ES_API);
        ASSERT_EGL_SUCCESS();
    }
};

TEST_P(EGLDisplaySelectionTestDeviceId, DeviceId)
{
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_platform_angle_device_id"));
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_display_power_preference") &&
                       GetParam().eglParameters.displayPowerPreference != EGL_DONT_CARE);

    initializeWindow();

    for (size_t i = 0; i < mSystemInfo.gpus.size(); i++)
    {
        // Initialize the display with device id for each GPU
        EGLDisplay display;
        EGLContext context;
        initializeDisplayWithDeviceId(&display, mSystemInfo.gpus[i].systemDeviceId);
        initializeContextForDisplay(display, &context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, context);

        ASSERT_EQ(static_cast<int>(i), findActiveGPU());

        // Terminate the displays
        terminateContext(display, context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        terminateDisplay(display);
    }

    terminateWindow();
}

TEST_P(EGLDisplaySelectionTestDeviceId, DeviceIdConcurrently)
{
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_platform_angle_device_id"));
    ANGLE_SKIP_TEST_IF(!IsEGLClientExtensionEnabled("EGL_ANGLE_display_power_preference") &&
                       GetParam().eglParameters.displayPowerPreference != EGL_DONT_CARE);

    initializeWindow();
    struct ContextForDevice
    {
        EGLDisplay display{};
        EGLContext context{};
    };
    std::vector<ContextForDevice> contexts(mSystemInfo.gpus.size());

    for (size_t i = 0; i < contexts.size(); i++)
    {
        auto &display = contexts[i].display;
        auto &context = contexts[i].context;
        initializeDisplayWithDeviceId(&display, mSystemInfo.gpus[i].systemDeviceId);
        initializeContextForDisplay(display, &context);
        eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, context);
        ASSERT_EQ(static_cast<int>(i), findActiveGPU());
    }
    for (auto &context : contexts)
    {
        // Terminate the displays
        terminateContext(context.display, context.context);
        eglMakeCurrent(context.display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        terminateDisplay(context.display);
    }

    terminateWindow();
}

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(EGLDisplaySelectionTest);
ANGLE_INSTANTIATE_TEST(EGLDisplaySelectionTest,
                       WithLowPowerGPU(ES2_METAL()),
                       WithLowPowerGPU(ES3_METAL()),
                       WithHighPowerGPU(ES2_METAL()),
                       WithHighPowerGPU(ES3_METAL()));

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(EGLDisplaySelectionTestMultiDisplay);
ANGLE_INSTANTIATE_TEST(EGLDisplaySelectionTestMultiDisplay,
                       WithNoFixture(ES2_METAL()),
                       WithNoFixture(ES3_METAL()));

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(EGLDisplaySelectionTestDeviceId);
ANGLE_INSTANTIATE_TEST(EGLDisplaySelectionTestDeviceId,
                       WithNoFixture(ES2_D3D11()),
                       WithNoFixture(ES3_D3D11()),
                       WithNoFixture(ES2_METAL()),
                       WithNoFixture(ES3_METAL()),
                       WithNoFixture(WithLowPowerGPU(ES2_METAL())),
                       WithNoFixture(WithLowPowerGPU(ES3_METAL())),
                       WithNoFixture(WithHighPowerGPU(ES2_METAL())),
                       WithNoFixture(WithHighPowerGPU(ES3_METAL())));

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(EGLDisplaySelectionTestVulkanDeviceUUID);
ANGLE_INSTANTIATE_TEST(EGLDisplaySelectionTestVulkanDeviceUUID,
                       WithNoFixture(ES2_OPENGL()),
                       WithNoFixture(ES3_OPENGL()),
                       WithNoFixture(ES2_METAL()),
                       WithNoFixture(ES3_METAL()),
                       WithNoFixture(ES2_D3D11()),
                       WithNoFixture(ES3_D3D11()),
                       WithNoFixture(ES2_VULKAN()),
                       WithNoFixture(ES3_VULKAN()));
