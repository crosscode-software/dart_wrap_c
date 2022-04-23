#pragma once
#include "crosscode_defstruct.h"
#include <stdint.h>
#include <minwindef.h>


#ifdef __cplusplus
extern "C" {
#endif
	

	class CROSSCODE_C_LIB_API CrossCode_WapCLibClass
	{
		public:
			CrossCode_WapCLibClass();
			~CrossCode_WapCLibClass();

		public:		
			int GetSizeOfRestrictedAlignmentStruct( RestrictedAlignmentStruct sStrut);
			int GetSizeOfUnrestrictedAlignmentStruct( UnrestrictedAlignmentStruct sStrut);


			BOOL CompareStringOfRestrictedAlignmentStruct(pRestrictedAlignmentStruct pStruct);
			BOOL CompareStringOfUnrestrictedAlignmentStruct(pUnrestrictedAlignmentStruct pStruct);

			BOOL NotifyCallbackOfUnrestrictedAlignmentStruct(pUnrestrictedAlignmentStruct pStruct);
			BOOL NotifyCallbackOfRestrictedAlignmentStruct(pRestrictedAlignmentStruct pStruct);

			BOOL CopyDataOfUnrestrictedAlignmentStructWithCallback(UnrestrictedAlignmentStruct sStruct, CopyStructCallbackFunc pCopyCallbackFunc);
			BOOL CopyDataOfRestrictedAlignmentStructWithCallback(RestrictedAlignmentStruct sStruct, CopyStructCallbackFunc pCopyCallbackFunc);

		private:
		
	};
 
#ifdef __cplusplus
}
#endif 

