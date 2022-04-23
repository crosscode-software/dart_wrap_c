#pragma once

#include "crosscode_defstruct.h"

#ifdef __cplusplus

extern "C" 
{
#endif

	CROSSCODE_WRAP_CLIB_API BOOL  __stdcall CreateClassInstance(HANDLE *ppClassHandle);

	CROSSCODE_WRAP_CLIB_API void __stdcall DeleteClassInstance(HANDLE pClassHandle);

	CROSSCODE_WRAP_CLIB_API int __stdcall GetSizeOfRestrictedAlignmentStruct(HANDLE pClassHandle, RestrictedAlignmentStruct sStrut);
	
	CROSSCODE_WRAP_CLIB_API int __stdcall GetSizeOfUnrestrictedAlignmentStruct(HANDLE pClassHandle, UnrestrictedAlignmentStruct sStrut);

	CROSSCODE_WRAP_CLIB_API BOOL  __stdcall CompareStringOfRestrictedAlignmentStruct(HANDLE pClassHandle, pRestrictedAlignmentStruct pStruct);
	
	CROSSCODE_WRAP_CLIB_API BOOL  __stdcall CompareStringOfUnrestrictedAlignmentStruct(HANDLE pClassHandle, pUnrestrictedAlignmentStruct pStruct);

	CROSSCODE_WRAP_CLIB_API BOOL  __stdcall NotifyCallbackOfUnrestrictedAlignmentStruct(HANDLE pClassHandle, pUnrestrictedAlignmentStruct pStruct);
	
	CROSSCODE_WRAP_CLIB_API BOOL  __stdcall NotifyCallbackOfRestrictedAlignmentStruct(HANDLE pClassHandle, pRestrictedAlignmentStruct pStruct);

	CROSSCODE_WRAP_CLIB_API BOOL  __stdcall CopyDataOfUnrestrictedAlignmentStructWithCallback(HANDLE pClassHandle, UnrestrictedAlignmentStruct pStruct, CopyStructCallbackFunc pCopyCallbackFunc);
	
	CROSSCODE_WRAP_CLIB_API BOOL  __stdcall CopyDataOfRestrictedAlignmentStructWithCallback(HANDLE pClassHandle, RestrictedAlignmentStruct pStruct, CopyStructCallbackFunc pCopyCallbackFunc);

#ifdef __cplusplus
}
#endif