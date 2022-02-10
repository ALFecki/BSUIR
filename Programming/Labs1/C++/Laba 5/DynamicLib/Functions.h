#pragma once


#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif


extern "C" DYNAMICLIB_API int function(int a, int b);

