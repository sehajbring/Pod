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

#define BIT(x) (1 << x) 