#include <windows.h>  
#include "pch.h"
#include "crosscode_c_plusplus_class.h"
#include "crosscode_c_func.h"

#ifdef __cplusplus
extern "C" {
#endif

	CROSSCODE_C_LIB_API BOOL __stdcall CreateClassInstance(__inout HANDLE* ppClassHandle)
	{
		bool RetVal = false;

		*ppClassHandle = static_cast<void*> (new CrossCode_WapCLibClass());

		return (*ppClassHandle != NULL);
	}

	CROSSCODE_C_LIB_API void __stdcall DeleteClassInstance(HANDLE pClassHandle)
	{
		if (pClassHandle != NULL)
		{
			//	cleanup_socket();
			delete (CrossCode_WapCLibClass*) pClassHandle;
		}

		pClassHandle = NULL;
	}

	CROSSCODE_C_LIB_API int __stdcall GetSizeOfRestrictedAlignmentStruct(HANDLE pClassHandle , RestrictedAlignmentStruct ConfirmStrut) {
		
		if (pClassHandle != NULL)
		{ 
			CrossCode_WapCLibClass* WrapCClass = (CrossCode_WapCLibClass*) pClassHandle;
			return WrapCClass->GetSizeOfRestrictedAlignmentStruct(ConfirmStrut);
		}
		return 0;
	}

	CROSSCODE_C_LIB_API int __stdcall GetSizeOfUnrestrictedAlignmentStruct(HANDLE pClassHandle, UnrestrictedAlignmentStruct ConfirmStrut) {
		if (pClassHandle != NULL)
		{
			CrossCode_WapCLibClass* WrapCClass = (CrossCode_WapCLibClass*)pClassHandle;
			return WrapCClass->GetSizeOfUnrestrictedAlignmentStruct(ConfirmStrut);
		}
		return 0;
	}

	CROSSCODE_C_LIB_API BOOL __stdcall CompareStringOfRestrictedAlignmentStruct(HANDLE pClassHandle, pRestrictedAlignmentStruct pStruct) {
		if (pClassHandle != NULL)
		{
			CrossCode_WapCLibClass* WrapCClass = (CrossCode_WapCLibClass*)pClassHandle;
			return WrapCClass->CompareStringOfRestrictedAlignmentStruct(pStruct);
		}
		return FALSE;
	}

	CROSSCODE_C_LIB_API BOOL __stdcall CompareStringOfUnrestrictedAlignmentStruct(HANDLE pClassHandle, pUnrestrictedAlignmentStruct pUnpackedStruct) {

		if (pClassHandle != NULL)
		{
			CrossCode_WapCLibClass* WrapCClass = (CrossCode_WapCLibClass*) pClassHandle;
			return WrapCClass->CompareStringOfUnrestrictedAlignmentStruct(pUnpackedStruct);
		}
		return FALSE;

	}

	CROSSCODE_C_LIB_API BOOL __stdcall NotifyCallbackOfUnrestrictedAlignmentStruct(HANDLE pClassHandle, pUnrestrictedAlignmentStruct pStruct) {
		
		if (pClassHandle != NULL)
		{
			CrossCode_WapCLibClass* WrapCClass = (CrossCode_WapCLibClass*)pClassHandle;
			return WrapCClass->NotifyCallbackOfUnrestrictedAlignmentStruct(pStruct);
		}
		return FALSE;
	
	}

	CROSSCODE_C_LIB_API BOOL __stdcall NotifyCallbackOfRestrictedAlignmentStruct(HANDLE pClassHandle, pRestrictedAlignmentStruct pStruct) {

		if (pClassHandle != NULL)
		{
			CrossCode_WapCLibClass* WrapCClass = (CrossCode_WapCLibClass*) pClassHandle;
			return WrapCClass->NotifyCallbackOfRestrictedAlignmentStruct(pStruct);
		}
		return FALSE;
	}

	CROSSCODE_C_LIB_API BOOL __stdcall CopyDataOfUnrestrictedAlignmentStructWithCallback(HANDLE pClassHandle, UnrestrictedAlignmentStruct sStruct, CopyStructCallbackFunc pCopyCallbackFunc) {

		if (pClassHandle != NULL)
		{
			CrossCode_WapCLibClass* WrapCClass = (CrossCode_WapCLibClass*) pClassHandle;
			return WrapCClass->CopyDataOfUnrestrictedAlignmentStructWithCallback(sStruct, pCopyCallbackFunc);
		}
		return FALSE;
	}

	CROSSCODE_C_LIB_API BOOL __stdcall CopyDataOfRestrictedAlignmentStructWithCallback(HANDLE pClassHandle, RestrictedAlignmentStruct sStruct, CopyStructCallbackFunc pCopyCallbackFunc) {

		if (pClassHandle != NULL)
		{
			CrossCode_WapCLibClass* WrapCClass = (CrossCode_WapCLibClass*) pClassHandle;
			return WrapCClass->CopyDataOfRestrictedAlignmentStructWithCallback(sStruct, pCopyCallbackFunc);
		}
		return FALSE;
	}
#ifdef __cplusplus
}
#endif
