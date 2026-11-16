// FUN_fffffff009c5d114 @ fffffff009c5d114

undefined8 *
FUN_fffffff009c5d114
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)
           thunk_FUN_fffffff00a8983cc
                     (param_1,param_2,param_3,param_4,param_5,param_6,(long *)&DAT_fffffff00807a920,
                      (ulong *)&DAT_000000b8);
  puVar2 = (undefined8 *)FUN_fffffff009c4be28(puVar1);
  *puVar2 = &PTR_FUN_fffffff008073a70;
  puVar2[0x16] = 0;
  thunk_FUN_fffffff00a8962a0(-0xff50b74f8);
  return puVar1;
}

