// FUN_fffffff009c3dd58 @ fffffff009c3dd58 size=556

/* WARNING: Removing unreachable block (ram,0xfffffff009c3ddc8) */

undefined8
FUN_fffffff009c3dd58
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6)

{
  undefined8 uVar1;
  long lVar2;
  undefined *local_c0;
  undefined8 local_b8;
  code *local_b0;
  undefined *local_a8;
  undefined8 *local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  code *local_78;
  code *local_70;
  long *local_68;
  long *local_60;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff00806ca40;
  local_60 = (long *)0x0;
  lVar2 = *(long *)(param_1 + 0xf8);
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  uVar1 = thunk_EXT_FUN_80110000039a3bc0(lVar2,param_2,&local_60);
  if ((int)uVar1 == 0) {
    uVar1 = 0xe00002c2;
    lVar2 = thunk_EXT_FUN_8011000003890f30(local_60,DAT_fffffff0080668c8);
    if (lVar2 != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
      local_a0 = &local_90;
      local_90 = 0;
      local_80 = DAT_fffffff0078a1298;
      local_78 = FUN_fffffff009c402b4;
      local_70 = FUN_fffffff009c402c8;
      local_68 = (long *)0x0;
      local_c0 = PTR_DAT_fffffff00806c9b8;
      local_b8 = DAT_fffffff0078a1290;
      local_b0 = FUN_fffffff009c40314;
      local_a8 = &DAT_fffffff00806a0f0;
      uStack_98 = param_3;
      local_88 = local_a0;
      thunk_EXT_FUN_801100000389794c(*(undefined8 *)(param_1 + 0x100),&local_c0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
      if (local_88[5] != 0) {
        uVar1 = FUN_fffffff009c16750(lVar2);
        uVar1 = FUN_fffffff009c176a0(uVar1,local_88[5],param_6,param_4,param_5);
      }
      thunk_EXT_FUN_80110000038e9dac(&local_90,8);
      if (local_68 != (long *)0x0) {
        (**(code **)(*local_68 + 0x28))();
      }
    }
  }
  if (local_60 != (long *)0x0) {
    (**(code **)(*local_60 + 0x28))();
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_58) {
    return uVar1;
  }
  uVar1 = thunk_EXT_FUN_8011000003a48590();
  return uVar1;
}

