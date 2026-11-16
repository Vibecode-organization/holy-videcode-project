// FUN_fffffff009ca6880 @ fffffff009ca6880

undefined8 *
FUN_fffffff009ca6880
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)
           thunk_FUN_fffffff00a8983cc
                     (param_1,param_2,param_3,param_4,param_5,param_6,(long *)&DAT_fffffff00807f4f8,
                      (ulong *)0x90);
  puVar2 = (undefined8 *)thunk_FUN_fffffff00a969de8(puVar1);
  *puVar2 = &PTR_thunk_FUN_fffffff00a969e48_fffffff00807ece8;
  thunk_FUN_fffffff00a8962a0(-0xff50b6e88);
  return puVar1;
}

