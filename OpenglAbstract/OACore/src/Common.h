#pragma once

#ifdef OA_CORE_DLL
	#define OA_API
	#define OA_API __declspec(dllexport)
#else
	#define OA_API __declspec(dllimport)
#endif