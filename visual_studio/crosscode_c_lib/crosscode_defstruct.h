#pragma once

 

#ifdef CROSSCODE_C_LIB_EXPORTS
#define CROSSCODE_C_LIB_API __declspec(dllexport)
#else
#define CROSSCODE_C_LIB_API __declspec(dllimport)
#endif


typedef int (*CallbackFunc)(double* pDoubleArray);
typedef BOOL (*CopyStructCallbackFunc)(PVOID pStruct);

typedef struct _UnrestrictedAlignmentStruct {
	int	intField;
	TCHAR charField;
	CallbackFunc funcptrField;
	float floatField;
	wchar_t stringField[15];
	double dubaryField[10];
} UnrestrictedAlignmentStruct, * pUnrestrictedAlignmentStruct;

#pragma pack(push, 1)
typedef struct _RestrictedAlignmentStruct {
	int	intField;
	TCHAR charField;
	CallbackFunc funcptrField;
	float floatField;
	wchar_t stringField[15];
	double dubaryField[10];
} RestrictedAlignmentStruct, *pRestrictedAlignmentStruct;
#pragma pack(pop)



