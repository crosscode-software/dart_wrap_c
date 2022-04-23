import 'dart:ffi';


class UnrestrictedAlignmentStruct  extends Struct {
  @Int32()
  external int intField;
  @Uint16()
  external int charField;  
  external Pointer<NativeFunction<Int32 Function(Pointer<Double> pDoubleArray)>> funcptrField;
  @Float()
  external double floatField;
  @Array(15)
  external Array<Int16> stringField;
  @Array(10)
  external Array<Double> dubaryField; 
}

@Packed(1)
class RestrictedAlignmentStruct  extends Struct {
  @Int32()
  external int intField;
  @Int16()
  external int charField;  
  external Pointer<NativeFunction<Int32 Function(Pointer<Double> pDoubleArray)>> funcptrField;
  @Float()
  external double floatField;
  @Array(15)
  external Array<Int16> stringField;
  @Array(10)
  external Array<Double> dubaryField; 
}

typedef CreateClassInstanceForNative = Int32 Function(Pointer pClassHandle);
typedef CreateClassInstanceForDarte = int Function(Pointer pClassHandle);
 
//  Unrestricted Alignment Struct
typedef GetSizeOfUnrestrictedAlignmentStructProcForNative = Int32 Function(Pointer pClassHandle, UnrestrictedAlignmentStruct sStrut);
typedef GetSizeOfUnrestrictedAlignmentStructProcForDart = int Function(Pointer pClassHandle, UnrestrictedAlignmentStruct sStrut);

typedef CompareStringOfUnrestrictedAlignmentStructProcForNative = Int32 Function(Pointer pClassHandle, Pointer<UnrestrictedAlignmentStruct> pStruct);
typedef CompareStringOfUnrestrictedAlignmentStructProcForDart = int Function(Pointer pClassHandle, Pointer<UnrestrictedAlignmentStruct> pStruct);

typedef NotifyCallbackOfUnrestrictedAlignmentStructProcForNative = Int32 Function(Pointer pClassHandle, Pointer<UnrestrictedAlignmentStruct> pStruct);
typedef NotifyCallbackOfUnrestrictedAlignmentStructProcForDart = int Function(Pointer pClassHandle, Pointer<UnrestrictedAlignmentStruct> pStruct);

typedef CopyDataOfUnrestrictedAlignmentStructWithCallbackProcForNative = Int32 Function(Pointer classHandle, UnrestrictedAlignmentStruct sStruct, Pointer<NativeFunction<Int32 Function(Pointer pStruct)>> pCopyCallbackFunc);
typedef CopyDataOfUnrestrictedAlignmentStructWithCallbackProcForDart = int Function(Pointer classHandle, UnrestrictedAlignmentStruct sStruct, Pointer<NativeFunction<Int32 Function(Pointer pStruct)>> pCopyCallbackFunc);
 

// Restricted Alignment Struct
typedef GetSizeOfRestrictedAlignmentStructProcForNative = Int32 Function(Pointer pClassHandle, RestrictedAlignmentStruct sStrut);
typedef GetSizeOfRestrictedAlignmentStructProcForDart = int Function(Pointer pClassHandle, RestrictedAlignmentStruct sStrut);

typedef CompareStringOfRestrictedAlignmentStructProcForNative = Int32 Function(Pointer pClassHandle, Pointer<RestrictedAlignmentStruct> pStruct);
typedef CompareStringOfRestrictedAlignmentStructProcForDart = int Function(Pointer pClassHandle, Pointer<RestrictedAlignmentStruct> pStruct);

typedef NotifyCallbackOfRestrictedAlignmentStructProcForNative = Int32 Function(Pointer pClassHandle, Pointer<RestrictedAlignmentStruct> pStruct);
typedef NotifyCallbackOfRestrictedAlignmentStructProcForDart = int Function(Pointer pClassHandle, Pointer<RestrictedAlignmentStruct> pStruct);

typedef CopyDataOfRestrictedAlignmentStructWithCallbackProcForNative = Int32 Function(Pointer classHandle, RestrictedAlignmentStruct sStruct, Pointer<NativeFunction< Int32 Function(Pointer<Double> pDoubleArray)>> pCopyCallbackFunc);
typedef CopyDataOfRestrictedAlignmentStructWithCallbackProcForDart = int Function(Pointer classHandle, RestrictedAlignmentStruct sStruct, Pointer<NativeFunction< Int32 Function(Pointer<Double> pDoubleArray)>> pCopyCallbackFunc);
 
class ManualConvertByCrossCode {   

  late DynamicLibrary wrapclib;

  ManualConvertByCrossCode(String dllName) {
    wrapclib = DynamicLibrary.open(dllName); 
  }
  
  late final createClassInstanceProc = wrapclib.lookupFunction<
      CreateClassInstanceForNative, 
      CreateClassInstanceForDarte
    >('CreateClassInstance');
  
  late final getSizeOfUnrestrictedAlignmentStructProc = wrapclib.lookupFunction<
        GetSizeOfUnrestrictedAlignmentStructProcForNative,
        GetSizeOfUnrestrictedAlignmentStructProcForDart
      >('GetSizeOfUnrestrictedAlignmentStruct');   
    
  late final compareStringOfUnrestrictedAlignmentStructProc = wrapclib.lookupFunction<
        CompareStringOfUnrestrictedAlignmentStructProcForNative,
        CompareStringOfUnrestrictedAlignmentStructProcForDart
      >('CompareStringOfUnrestrictedAlignmentStruct');  
 

  late final notifyCallbackOfUnrestrictedAlignmentStructProc = wrapclib.lookupFunction<
        NotifyCallbackOfUnrestrictedAlignmentStructProcForNative,
        NotifyCallbackOfUnrestrictedAlignmentStructProcForDart
      >('NotifyCallbackOfUnrestrictedAlignmentStruct');    

  late final copyDataOfUnrestrictedAlignmentStructWithCallbackProc = wrapclib.lookupFunction<
        CopyDataOfUnrestrictedAlignmentStructWithCallbackProcForNative,
        CopyDataOfUnrestrictedAlignmentStructWithCallbackProcForDart
      >('CopyDataOfUnrestrictedAlignmentStructWithCallback');   

  
  late final getSizeOfRestrictedAlignmentStructProc = wrapclib.lookupFunction<
      GetSizeOfRestrictedAlignmentStructProcForNative,
      GetSizeOfRestrictedAlignmentStructProcForDart
    >('GetSizeOfRestrictedAlignmentStruct');   
   

  late final compareStringOfRestrictedAlignmentStruct = wrapclib.lookupFunction<
      CompareStringOfRestrictedAlignmentStructProcForNative,
      CompareStringOfRestrictedAlignmentStructProcForDart
    >('CompareStringOfRestrictedAlignmentStruct');
    
  late final notifyCallbackOfRestrictedAlignmentStructProc = wrapclib.lookupFunction<
      NotifyCallbackOfRestrictedAlignmentStructProcForNative,
      NotifyCallbackOfRestrictedAlignmentStructProcForDart
    >('NotifyCallbackOfRestrictedAlignmentStruct'); 
     
  late final copyDataOfRestrictedAlignmentStructWithCallbackProc = wrapclib.lookupFunction<
      CopyDataOfRestrictedAlignmentStructWithCallbackProcForNative,
      CopyDataOfRestrictedAlignmentStructWithCallbackProcForDart
    >('CopyDataOfRestrictedAlignmentStructWithCallback'); 
    
  late final deleteClassInstanceProc = wrapclib.lookupFunction<
      Void Function(Pointer classHandle),
      void Function(Pointer classHandle)
    >('DeleteClassInstance'); 
  
}
