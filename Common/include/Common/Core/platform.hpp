#pragma once

#if defined(_WIN32)
#define WINDOWS

#define DLL_PUBLIC __declspec(dllexport)
#define DLL_PRIVATE 
#define DLL_IMPORT __declspec(dllimport)

#elif defined(__linux__)
#define LINUX
// TODO: Figure out linux equivilent
#error Linux exports not done yet. TODO: Implement
#else
#error Unsupported platform!
#endif


#if !defined(NDEBUG) || defined(_DEBUG)
#define DEBUGON 
#endif