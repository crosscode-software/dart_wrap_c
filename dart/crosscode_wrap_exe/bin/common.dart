import 'dart:ffi';

typedef CallbackFuncForDart = int Function( Pointer<Double> pDoubleArray);
typedef CallbackFuncForFFI = Int32 Function(Pointer<Double> pDoubleArray);
typedef CopyStructCallbackFuncForFFI = Int32 Function(Pointer pStruct);

final String pCmpStr  = "Test String";
final List<double> notifyDouble = [ 0, 0.1, 2.2, 3.33, 44.44, 55.555, 666.666, 777.7777,
        8888.8888, 99999.9999];

extension DoubleArrayFill<T> on Array<Double> {
  void fillFromList(List<T> list) {
    for (var i = 0; i < list.length; i++) {
      this[i] = list[i] as double;
    }
  }

  void fillFromArray(List<T> list, int arrylen) {
    for (var i = 0; i < arrylen; i++) {
       list.add(this[i] as T) ;
    }
  }
}

extension StringArrayFill<T> on Array<Int16> {
  void fillFromList(List<T> list) {
    for (var i = 0; i < list.length; i++) {
      this[i] = list[i] as int;
    }
  }

  void fillFromArray(List<T> list, int arrylen) {
    for (var i = 0; i < arrylen; i++) {
       list.add(this[i] as T) ;
    }
  }
}

int comparArray (Pointer<Double> pDouble) {  
  for (int i =0;i<10;i++){
    if ( pDouble.elementAt(i).value != notifyDouble.elementAt(i))
    {
        return 0;
    }
  }
  return 1;
}

int checkArray(List<double> cmpArray){
  for (int i =0; i < cmpArray.length;i++){
    if (cmpArray.elementAt(i) != notifyDouble.elementAt(i)) {  
      return 0;
  }}
  return 1;
}




