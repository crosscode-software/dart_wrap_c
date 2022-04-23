
#include <windows.h>  
#include "pch.h"
#include <stdio.h>
#include <strsafe.h>
#include "crosscode_c_plusplus_class.h"

#ifdef __cplusplus
extern "C" {
#endif


	CrossCode_WapCLibClass::CrossCode_WapCLibClass() {}

	CrossCode_WapCLibClass::~CrossCode_WapCLibClass() {}
	 
	int CrossCode_WapCLibClass::GetSizeOfRestrictedAlignmentStruct(RestrictedAlignmentStruct sStrut)
	{
		return sizeof(sStrut);
	}

	int CrossCode_WapCLibClass::GetSizeOfUnrestrictedAlignmentStruct(UnrestrictedAlignmentStruct sStrut)
	{
		return sizeof(sStrut);
	}

	static const TCHAR* pCmpStr = L"Test String";
	
	BOOL CrossCode_WapCLibClass::CompareStringOfRestrictedAlignmentStruct(pRestrictedAlignmentStruct pStruct ){
		
		return wcscmp(pStruct->stringField,  pCmpStr) == 0;
	}

	BOOL CrossCode_WapCLibClass::CompareStringOfUnrestrictedAlignmentStruct(pUnrestrictedAlignmentStruct pStruct) {

		return wcscmp(pStruct->stringField,  pCmpStr) == 0;
	}	 

	static double notifyDouble[] = {
		 0, 0.1, 2.2, 3.33, 44.44, 55.555, 666.666, 777.7777,
		8888.8888, 99999.9999
	};

	BOOL CrossCode_WapCLibClass::NotifyCallbackOfUnrestrictedAlignmentStruct(pUnrestrictedAlignmentStruct pStruct) {

		return pStruct->funcptrField(pStruct->dubaryField);
	}
	
	BOOL CrossCode_WapCLibClass::NotifyCallbackOfRestrictedAlignmentStruct(pRestrictedAlignmentStruct pStruct) {

		return pStruct->funcptrField(pStruct->dubaryField);
	}

	int CopyCallbackFunc(double* tenArray) {
		for (int i = 0; i < 10; i++) {
			if (tenArray[i] != notifyDouble[i])
				return 0;
		}
		return 1;
	}	 

	BOOL CrossCode_WapCLibClass::CopyDataOfUnrestrictedAlignmentStructWithCallback(UnrestrictedAlignmentStruct pStruct, CopyStructCallbackFunc pCopyCallbackFunc) {

		UnrestrictedAlignmentStruct sPacked = { 0 };
		sPacked.charField = pStruct.charField;
		sPacked.floatField = pStruct.floatField;
		sPacked.intField = pStruct.intField;
		sPacked.funcptrField = CopyCallbackFunc;		
		wcsncpy_s(sPacked.stringField, wcslen(pStruct.stringField) + 1, pStruct.stringField, sizeof(pStruct.stringField));
		
		for (int i = 0; i < 10; i++) {
			sPacked.dubaryField[i]  = pStruct.dubaryField[i];
		}
		return pCopyCallbackFunc(&sPacked);
	}

	BOOL CrossCode_WapCLibClass::CopyDataOfRestrictedAlignmentStructWithCallback(RestrictedAlignmentStruct pStruct, CopyStructCallbackFunc pCopyCallbackFunc) {
		RestrictedAlignmentStruct sPacked = { 0 };
		sPacked.charField = pStruct.charField;
		sPacked.floatField = pStruct.floatField;
		sPacked.intField = pStruct.intField ;
		sPacked.funcptrField = CopyCallbackFunc;
		wcsncpy_s(sPacked.stringField, wcslen(pStruct.stringField) + 1, pStruct.stringField, sizeof(pStruct.stringField));

		for (int i = 0; i < 10; i++) {
			sPacked.dubaryField[i] = pStruct.dubaryField[i];
		}

		return pCopyCallbackFunc(&sPacked);
	}

#ifdef __cplusplus
}
#endif
