#pragma once

#include "crosscode_defstruct.h"

#ifdef __cplusplus

extern "C" 
{
#endif

	CROSSCODE_C_LIB_API BOOL __stdcall CreateClassInstance(HANDLE *ppClassHandle);

	CROSSCODE_C_LIB_API void __stdcall DeleteClassInstance(HANDLE pClassHandle);

	CROSSCODE_C_LIB_API int __stdcall GetSizeOfRestrictedAlignmentStruct(HANDLE pClassHandle, RestrictedAlignmentStruct sStrut);
	
	CROSSCODE_C_LIB_API int __stdcall GetSizeOfUnrestrictedAlignmentStruct(HANDLE pClassHandle, UnrestrictedAlignmentStruct sStrut);

	CROSSCODE_C_LIB_API BOOL __stdcall CompareStringOfRestrictedAlignmentStruct(HANDLE pClassHandle, pRestrictedAlignmentStruct pStruct);
	
	CROSSCODE_C_LIB_API BOOL __stdcall CompareStringOfUnrestrictedAlignmentStruct(HANDLE pClassHandle, pUnrestrictedAlignmentStruct pStruct);

	CROSSCODE_C_LIB_API BOOL __stdcall NotifyCallbackOfUnrestrictedAlignmentStruct(HANDLE pClassHandle, pUnrestrictedAlignmentStruct pStruct);
	
	CROSSCODE_C_LIB_API BOOL __stdcall NotifyCallbackOfRestrictedAlignmentStruct(HANDLE pClassHandle, pRestrictedAlignmentStruct pStruct);

	CROSSCODE_C_LIB_API BOOL __stdcall CopyDataOfUnrestrictedAlignmentStructWithCallback(HANDLE pClassHandle, UnrestrictedAlignmentStruct pStruct, CopyStructCallbackFunc pCopyCallbackFunc);
	
	CROSSCODE_C_LIB_API BOOL __stdcall CopyDataOfRestrictedAlignmentStructWithCallback(HANDLE pClassHandle, RestrictedAlignmentStruct pStruct, CopyStructCallbackFunc pCopyCallbackFunc);

#ifdef __cplusplus
}
#endif