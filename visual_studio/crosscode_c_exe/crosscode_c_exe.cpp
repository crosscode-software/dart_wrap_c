// crosscode_wrapc_exmexe.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <windows.h>  

#include "../crosscode_c_lib/crosscode_defstruct.h"
#include "../crosscode_c_lib/crosscode_c_func.h"

typedef boolean (__stdcall* CreateClassInstanceProc) (__inout HANDLE* ppClassHandle);
typedef void (__stdcall* DeleteClassInstanceProc) (__inout HANDLE pClassHandle);

typedef int (__stdcall* GetSizeOfRestrictedAlignmentStructProc) ( HANDLE pClassHandle, RestrictedAlignmentStruct sStrut);
typedef int (__stdcall* GetSizeOfUnrestrictedAlignmentStructProc) (HANDLE pClassHandle, UnrestrictedAlignmentStruct sStrut);

typedef boolean (__stdcall* CompareStringOfRestrictedAlignmentStructProc) (HANDLE pClassHandle, pRestrictedAlignmentStruct pStrut);
typedef boolean (__stdcall* CompareStringOfUnrestrictedAlignmentStructProc)(HANDLE pClassHandle, pUnrestrictedAlignmentStruct pStrut);

typedef boolean (__stdcall* NotifyCallbackOfRestrictedAlignmentStructProc) (HANDLE pClassHandle, pRestrictedAlignmentStruct pStruct);
typedef boolean (__stdcall* NotifyCallbackOfUnrestrictedAlignmentStructProc)(HANDLE pClassHandle, pUnrestrictedAlignmentStruct pStruct);

typedef boolean (__stdcall* CopyDataOfRestrictedAlignmentStructWithCallbackProc) (HANDLE pClassHandle, RestrictedAlignmentStruct sStruct, CopyStructCallbackFunc pCopyCallbackFunc);
typedef boolean (__stdcall* CopyDataOfUnrestrictedAlignmentStructWithCallbackProc) (HANDLE pClassHandle, UnrestrictedAlignmentStruct sStruct, CopyStructCallbackFunc pCopyCallbackFunc);

static const TCHAR* pCmpStr = L"Test String";

static double notifyDouble[] = {
        0, 0.1, 2.2, 3.33, 44.44, 55.555, 666.666, 777.7777,
        8888.8888, 99999.9999
};

int comparArray(double *cmpArray) {
    for (int i = 0; i < 10; i++) {
        if (cmpArray[i] != notifyDouble[i])
            return 0;
    }
    return 1;
}

BOOL getUnrestrictedAlignmentStructProc(PVOID pStruct) {
    
    pUnrestrictedAlignmentStruct pUAS = (pUnrestrictedAlignmentStruct) pStruct;
    wprintf(L"stringField : %s    floatField : %f     intField : %d     charField : %c \n",
        
    pUAS->stringField, pUAS->floatField, pUAS->intField, pUAS->charField);
    wprintf(L"Verify the data of dubaryField : %s\n", comparArray(pUAS->dubaryField) == 1 ? L"True" : L"False");

    BOOL bRetVal = pUAS->funcptrField(notifyDouble) == 1;
    wprintf(L"Execute the function porinter of pointerField : %s", bRetVal ? L"True" : L"False");

    return bRetVal;
}

BOOL getRestrictedAlignmentStructProc(PVOID pStruct) {

    pRestrictedAlignmentStruct pRAS = (pRestrictedAlignmentStruct) pStruct;
    wprintf(L"stringField : %s    floatField : %f     intField : %d     charField : %c \n", 
        pRAS->stringField, pRAS->floatField, pRAS->intField, pRAS->charField);
     
    wprintf(L"Verify the data of dubaryField : %s\n", comparArray(pRAS->dubaryField) == 1 ? L"True" : L"False");

    BOOL bRetVal = pRAS->funcptrField(notifyDouble) == 1;
    wprintf(L"Execute the function porinter of pointerField : %s",  bRetVal ? L"True" : L"False");
    
    return bRetVal;
}

int main()
{
    HINSTANCE wrapclib;

    wrapclib = LoadLibrary(TEXT("crosscode_c_lib.dll"));

    if (wrapclib == NULL) {
        wprintf(TEXT("\nDynamic Load DLL is fail.\n"));
        return 0;
    }

    CreateClassInstanceProc createClassInstanceProc =
        (CreateClassInstanceProc) GetProcAddress(wrapclib, "CreateClassInstance");

    HANDLE Handle = INVALID_HANDLE_VALUE;

    if (createClassInstanceProc(&Handle)) {

        wprintf(L"\n== Unrestricted Alignment Structure ==\n");
        UnrestrictedAlignmentStruct sUnrestrictedAlignmentStruct = { 0 };
        sUnrestrictedAlignmentStruct.charField = 'A';
        sUnrestrictedAlignmentStruct.floatField = 456.123f;
        sUnrestrictedAlignmentStruct.intField = 123;
        sUnrestrictedAlignmentStruct.funcptrField = comparArray;
        wcsncpy_s(sUnrestrictedAlignmentStruct.stringField, wcslen(pCmpStr) + 1, pCmpStr, sizeof(sUnrestrictedAlignmentStruct.stringField));
        for (int i = 0; i < 10; i++) {
            sUnrestrictedAlignmentStruct.dubaryField[i] = notifyDouble[i];
        }        
    
        GetSizeOfUnrestrictedAlignmentStructProc getSizeOfUnrestrictedAlignmentStructProc =
            (GetSizeOfUnrestrictedAlignmentStructProc)GetProcAddress(wrapclib, "GetSizeOfUnrestrictedAlignmentStruct");
        wprintf(L"Used memory size of an unrestricted alignment struct in execute(%llu) and library(%d)\n", sizeof(sUnrestrictedAlignmentStruct),
            getSizeOfUnrestrictedAlignmentStructProc(wrapclib, sUnrestrictedAlignmentStruct));
        

        CompareStringOfUnrestrictedAlignmentStructProc compareStringUnrestrictedAlignmentStructProc =
            (CompareStringOfUnrestrictedAlignmentStructProc) GetProcAddress(wrapclib, "CompareStringOfUnrestrictedAlignmentStruct");
        wprintf(L"Compare string in C library : %s\n",
            compareStringUnrestrictedAlignmentStructProc(wrapclib, &sUnrestrictedAlignmentStruct) ? L"True " : L"False");
       
        
        NotifyCallbackOfUnrestrictedAlignmentStructProc notifyCallbackOfUnrestrictedAlignmentStructProc =
            (NotifyCallbackOfUnrestrictedAlignmentStructProc)GetProcAddress(wrapclib, "NotifyCallbackOfUnrestrictedAlignmentStruct");
        wprintf(L"Execute callback function in C library : %s\n", 
            notifyCallbackOfUnrestrictedAlignmentStructProc(wrapclib, &sUnrestrictedAlignmentStruct) ? L"True" : L"False");
       
        CopyDataOfUnrestrictedAlignmentStructWithCallbackProc copyDataOfUnrestrictedAlignmentStructWithCallbackProc =
            (CopyDataOfUnrestrictedAlignmentStructWithCallbackProc) GetProcAddress(wrapclib, "CopyDataOfUnrestrictedAlignmentStructWithCallback");
        wprintf(L"\nCopy structure data in C library : %s\n", 
                copyDataOfUnrestrictedAlignmentStructWithCallbackProc(wrapclib, sUnrestrictedAlignmentStruct, getUnrestrictedAlignmentStructProc) ? L"True" : L"False");

        wprintf(L"\n==  Restricted Alignment Structure ==\n");
        RestrictedAlignmentStruct sRestrictedAlignmentStruct = { 0 };
        sRestrictedAlignmentStruct.charField = 'A';
        sRestrictedAlignmentStruct.floatField = 456.123f;
        sRestrictedAlignmentStruct.intField = 123;
        sRestrictedAlignmentStruct.funcptrField = comparArray;
        wcsncpy_s(sRestrictedAlignmentStruct.stringField, wcslen(pCmpStr) + 1, pCmpStr, sizeof(sRestrictedAlignmentStruct.stringField));

        for (int i = 0; i < 10; i++) {
            sRestrictedAlignmentStruct.dubaryField[i] = notifyDouble[i];
        }

        GetSizeOfRestrictedAlignmentStructProc getSizeOfRestrictedAlignmentStructProc =
            (GetSizeOfRestrictedAlignmentStructProc) GetProcAddress(wrapclib, "GetSizeOfRestrictedAlignmentStruct");
        wprintf(L"Used memory size of an unrestricted alignment struct in execute(%llu) and library(%d)\n", sizeof(sRestrictedAlignmentStruct),
            getSizeOfRestrictedAlignmentStructProc(wrapclib, sRestrictedAlignmentStruct));


        CompareStringOfRestrictedAlignmentStructProc compareStringOfRestrictedAlignmentStructProc =
            (CompareStringOfRestrictedAlignmentStructProc) GetProcAddress(wrapclib, "CompareStringOfRestrictedAlignmentStruct");
        wprintf(L"Compare string in C library : %s\n",
            compareStringOfRestrictedAlignmentStructProc(wrapclib, &sRestrictedAlignmentStruct) == 1 ? L"True " : L"False");

        NotifyCallbackOfRestrictedAlignmentStructProc notifyCallbackOfRestrictedAlignmentStructProc =
            (NotifyCallbackOfRestrictedAlignmentStructProc) GetProcAddress(wrapclib, "NotifyCallbackOfRestrictedAlignmentStruct");
        wprintf(L"Execute callback function in C library : %s\n", notifyCallbackOfRestrictedAlignmentStructProc(wrapclib, &sRestrictedAlignmentStruct) ? L"True" : L"False");

        CopyDataOfRestrictedAlignmentStructWithCallbackProc copyDataOfRestrictedAlignmentStructWithCallbackProc =
            (CopyDataOfRestrictedAlignmentStructWithCallbackProc) GetProcAddress(wrapclib, "CopyDataOfRestrictedAlignmentStructWithCallback");
        wprintf(L"\nCopy structure data in C library : %s\n", copyDataOfRestrictedAlignmentStructWithCallbackProc(wrapclib, sRestrictedAlignmentStruct, getRestrictedAlignmentStructProc) ? L"True" : L"False");
        

        DeleteClassInstanceProc deleteClassInstanceProc =
            (DeleteClassInstanceProc) GetProcAddress(wrapclib, "DeleteClassInstance");
        deleteClassInstanceProc(Handle);
        getchar();
    }
}
 
