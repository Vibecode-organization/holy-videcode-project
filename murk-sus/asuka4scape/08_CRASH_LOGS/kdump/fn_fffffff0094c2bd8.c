// FUN_fffffff0094c2bd8 @ fffffff0094c2bd8 size=208
// CALLERS:
// CALLS:
//   fffffff0094c264c FUN_fffffff0094c264c

undefined8
FUN_fffffff0094c2bd8
          (uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 uVar1;
  
  uVar1 = 0x50020;
  if ((param_1 & 3) != 0) {
    if (((param_1 & 1) != 0) &&
       (uVar1 = FUN_fffffff0094c264c
                          (param_2,param_3,0,0,param_4,param_5,0,0,0,0,&DAT_fffffff007f5ad68),
       (int)uVar1 == 0)) {
      return uVar1;
    }
    if ((param_1 >> 1 & 1) != 0) {
      uVar1 = FUN_fffffff0094c264c
                        (param_2,param_3,0,0,param_4,param_5,DAT_fffffff007f5b8d0,
                         DAT_fffffff007f5b8d8,0,0,&DAT_fffffff007f5ad68);
    }
  }
  return uVar1;
}

