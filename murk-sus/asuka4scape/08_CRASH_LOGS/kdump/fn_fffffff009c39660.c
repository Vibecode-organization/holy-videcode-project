// FUN_fffffff009c39660 @ fffffff009c39660 size=28
// CALLERS:
//   fffffff00afec073 ?
//   fffffff008068ff0 ?
// CALLS:
//   fffffff009c3d838 FUN_fffffff009c3d838

undefined4
FUN_fffffff009c39660
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8,long param_9)

{
  undefined4 uVar1;
  
  uVar1 = FUN_fffffff009c3d838
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                     **(uint **)(param_9 + 0x20),*(undefined8 **)(param_9 + 0x58),
                     (undefined4 *)(param_9 + 0x60));
  return uVar1;
}

