#pragma once

#ifdef POD_PLATFORM_WINDOWS
	
	#ifdef POD_BUILD_DLL
		#define POD_API __declspec(dllexport)
	
	#else
		#define POD_API __declspec(dllimport)
	
	#endif // POD_BUILD_DLL
#else
	#error Pod is only avalible for Windows at the moment! 
#endif // POD_PLATFORM_WINDOWS

#ifdef POD_ENABLE_ASSERTS
	#define POD_ASSERT(x, ...) {if(!(x)){POD_ERROR("Asswetion Failed: {0}", __VA_ARGS__); __debugbreak();} }
	#define POD_CORE_ASSERT(x, ...) {if(!(x)){POD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define POD_ASSERT(x, ...)
	#define POD_CORE_ASSERT(x, ...)

#endif

#define BIT(x) (1 << x) 

#define POD_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)