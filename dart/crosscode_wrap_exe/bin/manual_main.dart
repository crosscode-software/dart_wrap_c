import 'dart:ffi';
import 'package:ffi/ffi.dart';
import 'package:crosscode_wrapc_exe/crosscode_by_manual.dart';
import 'common.dart';

int getRestrictedAlignmentStructProc(Pointer pStruct){
    
  int iRetVal = 0;
  var pRAS = pStruct.cast<RestrictedAlignmentStruct>();
  List<int> strList = [];
  List<double> doubleList =[] ;
  pRAS.ref.dubaryField.fillFromArray(doubleList,10);
  pRAS.ref.stringField.fillFromArray(strList, 15);
 
  print ('stringField : ${String.fromCharCodes (strList)}   floatField : ${pRAS.ref.floatField}   intField : ${pRAS.ref.intField}   charField : ${String.fromCharCode(pRAS.ref.charField)}'); 
 
  
  var pPassParm = calloc.allocate<Double>(sizeOf<Double>() * 10);
  for (int i = 0;i<10;i++) {
      pPassParm[i] = doubleList[i];
  }      
  
  String isSame = comparArray(pPassParm) == 1 ? "True" : "False";
  print("Verify the data of dubaryField : $isSame");

  final callbackFuncProc = pRAS.ref.funcptrField
        .cast<NativeFunction<CallbackFuncForFFI>>().asFunction<CallbackFuncForDart>();
  
  iRetVal = callbackFuncProc(pPassParm);
  isSame =  iRetVal == 1 ? "True" : "False";
  print ("Execute the function porinter of pointerField : $isSame"); 

  calloc.free(pPassParm);
  
  return iRetVal;
}

int getUnrestrictedAlignmentStructProc(Pointer pStruct){
  
  int iRetVal = 0;
  var pUAS = pStruct.cast<UnrestrictedAlignmentStruct>();
  List<int> strList = [];
  List<double> doubleList =[] ;
  pUAS.ref.dubaryField.fillFromArray(doubleList,10);
  pUAS.ref.stringField.fillFromArray(strList, 15);
 
  print ('stringField : ${String.fromCharCodes (strList)}   floatField : ${pUAS.ref.floatField}   intField : ${pUAS.ref.intField}   charField : ${String.fromCharCode(pUAS.ref.charField)}'); 
 
  
  var pPassParm = calloc.allocate<Double>(sizeOf<Double>() * 10);
  for (int i = 0;i<10;i++) {
      pPassParm[i] = doubleList[i];
  }      
  
  String isSame = comparArray(pPassParm) == 1 ? "True" : "False";
  print("Verify the data of dubaryField : $isSame");

  final callbackFuncProc = pUAS.ref.funcptrField
        .cast<NativeFunction<CallbackFuncForFFI>>().asFunction<CallbackFuncForDart>();

  iRetVal = callbackFuncProc(pPassParm);
  isSame = iRetVal == 1 ? "True" : "False";
  print ("Execute the function porinter of pointerField : $isSame"); 

  calloc.free(pPassParm); 
  return iRetVal;
} 

void main(List<String> arguments) { 

  final convertClass = ManualConvertByCrossCode("crosscode_c_lib.dll");
 
  final classHandle = calloc<Pointer<Pointer>>();
  if (convertClass.createClassInstanceProc(classHandle) == 1) {
    
    print("== Unrestricted Alignment Structure By Manual =="); 
 
    final sUnrestrictedAlignmentStruct = calloc<UnrestrictedAlignmentStruct>()
          ..ref.charField = 'A'.codeUnitAt(0)     
          ..ref.floatField = 456.123
          ..ref.intField = 123
          ..ref.funcptrField = Pointer.fromFunction<CallbackFuncForFFI>(comparArray, 0)       
          ..ref.stringField.fillFromList(pCmpStr.codeUnits)
          ..ref.dubaryField.fillFromList(notifyDouble);   

    int retSize = convertClass.getSizeOfUnrestrictedAlignmentStructProc(classHandle.value, sUnrestrictedAlignmentStruct.ref);
    print("Used memory size of an unrestricted alignment struct in execute(${sizeOf<UnrestrictedAlignmentStruct>()}) and library($retSize)");

    String isSame = convertClass.compareStringOfUnrestrictedAlignmentStructProc(classHandle.value, sUnrestrictedAlignmentStruct) == 1 ? "True" : "False";  
    print("Compare string in C library : $isSame");    

    
    isSame = convertClass.notifyCallbackOfUnrestrictedAlignmentStructProc(classHandle.value, sUnrestrictedAlignmentStruct) == 1 ? "True":"False";
    print("Execute callback function in C library : $isSame");
    
 
    isSame =  convertClass.copyDataOfUnrestrictedAlignmentStructWithCallbackProc(
                classHandle.value, 
                sUnrestrictedAlignmentStruct.ref, 
                Pointer.fromFunction<CopyStructCallbackFuncForFFI>(getUnrestrictedAlignmentStructProc, 0)
              ) == 1 ? "True" : "False";     
    print("Copy structure data in C library : $isSame");


    print("\n== Restricted Alignment Structure By Manual ==");

    final packedStruct = calloc<RestrictedAlignmentStruct>()
          ..ref.charField = 'A'.codeUnitAt(0)     
          ..ref.floatField = 456.123
          ..ref.intField = 123
          ..ref.funcptrField = Pointer.fromFunction<CallbackFuncForFFI>(comparArray, 0)       
          ..ref.stringField.fillFromList(pCmpStr.codeUnits)
          ..ref.dubaryField.fillFromList(notifyDouble);      


    
    retSize = convertClass.getSizeOfRestrictedAlignmentStructProc(classHandle.value, packedStruct.ref);
    print("Used memory size of an restricted alignment struct in execute(${sizeOf<RestrictedAlignmentStruct>()}) and library($retSize)");

   
    isSame =convertClass.compareStringOfRestrictedAlignmentStruct(classHandle.value, packedStruct) == 1 ? "True" : "False";
    print("Compare string in C library : $isSame");    
  
    isSame =convertClass.notifyCallbackOfRestrictedAlignmentStructProc(classHandle.value, packedStruct) == 1 ? "True" : "False";
    print("Execute callback function in C library : $isSame");
   
    isSame =  convertClass.copyDataOfRestrictedAlignmentStructWithCallbackProc(
                classHandle.value, 
                packedStruct.ref, 
                Pointer.fromFunction<CopyStructCallbackFuncForFFI>(getRestrictedAlignmentStructProc, 0)  
              ) == 1 ? "True" : "False";
    print("Copy structure data in C library : $isSame");   
  
    convertClass.deleteClassInstanceProc(classHandle.value);
  }
}