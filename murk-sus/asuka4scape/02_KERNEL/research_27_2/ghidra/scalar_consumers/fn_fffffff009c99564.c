// FUN_fffffff009c99564 @ fffffff009c99564

undefined8 *
FUN_fffffff009c99564
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)
           thunk_FUN_fffffff00a8983cc
                     (param_1,param_2,param_3,param_4,param_5,param_6,(long *)&DAT_fffffff00807f3f8,
                      (ulong *)&DAT_00000018);
  puVar2 = (undefined8 *)thunk_FUN_fffffff00a8984ec(puVar1);
  *puVar2 = &PTR_thunk_FUN_fffffff00a8982e0_fffffff00807e318;
  thunk_FUN_fffffff00a8962a0(-0xff50b6f28);
  return puVar1;
}

