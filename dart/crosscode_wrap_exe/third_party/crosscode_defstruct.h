#pragma once
#define _UNICODE 
#include "windows.h"

#ifdef CROSSCODE_WRAP_CLIB_EXPORTS
	#define CROSSCODE_WRAP_CLIB_API __declspec(dllexport)
#else
	#define CROSSCODE_WRAP_CLIB_API __declspec(dllimport)
#endif


typedef int (*CallbackFunc)(double* pDoubleArray);
typedef BOOL (*CopyStructCallbackFunc)(PVOID pStruct);

typedef struct _UnrestrictedAlignmentStruct {
	int	intField;
	TCHAR charField;
	CallbackFunc funcptrField;
	float floatField;
	TCHAR stringField[15];
	double dubaryField[10];
} UnrestrictedAlignmentStruct, * pUnrestrictedAlignmentStruct;

#pragma pack(push, 1)
typedef struct _RestrictedAlignmentStruct {
	int	intField;
	TCHAR charField;
	CallbackFunc funcptrField;
	float floatField;
	TCHAR stringField[15];
	double dubaryField[10];
} RestrictedAlignmentStruct, *pRestrictedAlignmentStruct;
#pragma pack(pop)

typedef unsigned char uchar;
typedef int (*CallbackFunc2)(double* pDoubleArray);
typedef struct _ExcludeUnrestrictedAlignmentStruct {
	int	intField;
	uchar charField;
	CallbackFunc2 funcptrField;
	float floatField;
	TCHAR stringField[15];
	double dubaryField[10];
} ExcludeUnrestrictedAlignmentStruct, * pExcludeUnrestrictedAlignmentStruct;


typedef struct _ExcludeUnrestrictedAlignmentStruct2 {
	int	intField;
	uchar charField;
	CallbackFunc2 funcptrField;
	float floatField;
	TCHAR stringField[15];
	double dubaryField[10];
} ExcludeUnrestrictedAlignmentStruct2, * pExcludeUnrestrictedAlignmentStruct2;


