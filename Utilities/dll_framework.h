/**
 * @file dll_framework.h
 * @brief Contains MACRO for exporting function in dll
 *
 * @author David Algis
 *
 * Company - Studio Nyx
 * Copyright © Studio Nyx. All rights reserved.
 */
#pragma once

// plugin API
// Compatible with C99

#if defined(__CYGWIN32__)
#define PLUGIN_INTERFACE_API __stdcall
#define PLUGIN_INTERFACE_EXPORT __declspec(dllexport)
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) ||               \
    defined(_WIN64) || defined(WINAPI_FAMILY)
#define PLUGIN_INTERFACE_API __stdcall
#define PLUGIN_INTERFACE_EXPORT __declspec(dllexport)
#elif defined(__MACH__) || defined(__ANDROID__) || defined(__linux__)
#define PLUGIN_INTERFACE_API
#define PLUGIN_INTERFACE_EXPORT
#else
#define PLUGIN_INTERFACE_API
#define PLUGIN_INTERFACE_EXPORT
#endif
