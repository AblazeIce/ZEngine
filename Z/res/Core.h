#pragma once

#ifdef Z_PLATFORM_WINDOWS
#ifdef Z_BUILD_DLL
#define Z_API _declspec(dllexport)
#else
#define Z_API _declspec(dllimport)
#endif // Z_BUILD_DLL
#else
#error Z only supports Windows!
#endif // Z_PLATFORM_WINDOWS

#ifdef Z_ENABLE_ASSERTS

#define Z_ASSERT(x, ...) {if(!(x)){Z_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
#define Z_CORE_ASSERT(x, ...) {if(!(x)){Z_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
#else
#define Z_ASSERT(x,...)
#define Z_CORE_ASSERT(x,...)
#endif // Z_ENABLE_ASSERTS

#define BIT(x) (1<<x) //将数字1左移x位，相当于乘以2的x次方

#define BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)