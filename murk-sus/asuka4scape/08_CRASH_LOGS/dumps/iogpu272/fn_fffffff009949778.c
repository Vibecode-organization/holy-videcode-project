// FUN_fffffff009949778 @ fffffff009949778 size=192

/* WARNING: Removing unreachable block (ram,0xfffffff0099498c8) */

undefined8
FUN_fffffff009949778
          (long param_1,undefined8 param_2,ulong *param_3,ulong *param_4,ulong param_5,
          undefined8 param_6,undefined8 param_7)

{
  undefined8 uVar1;
  ulong *puVar2;
  undefined1 auVar3 [16];
  ulong local_838 [256];
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff007ff2800;
  puVar2 = param_3;
  if (param_3 < (ulong *)0x101) {
    if (param_3 < (ulong *)0x2) {
      local_838[0] = (ulong)param_4 | param_5 << 0x20;
      if (param_3 == (ulong *)0x0) {
        uVar1 = 0;
        goto LAB_fffffff009949808;
      }
    }
    else {
      puVar2 = (ulong *)((long)param_3 << 3);
      uVar1 = thunk_EXT_FUN_8011000003385b14(param_4,local_838);
      if ((int)uVar1 != 0) goto LAB_fffffff009949808;
    }
    puVar2 = local_838;
    uVar1 = FUN_fffffff009967f2c(*(undefined8 *)(param_1 + 0x120),param_2,puVar2,param_3);
    param_4 = param_3;
  }
  else {
    uVar1 = 0xe00002c2;
  }
LAB_fffffff009949808:
  if (*(long *)PTR_DAT_fffffff007ff2800 == local_38) {
    return uVar1;
  }
  auVar3 = thunk_EXT_FUN_8011000003a48590(uVar1);
  uVar1 = 0xe00002c2;
  if (((puVar2 < (ulong *)0x101) && (param_5 < 0x101)) &&
     (uVar1 = FUN_fffffff009949778(auVar3._0_8_,auVar3._8_8_,param_5,param_6,param_7),
     (int)uVar1 == 0)) {
    uVar1 = FUN_fffffff0099496bc(auVar3._0_8_,auVar3._8_8_,puVar2,param_4);
    return uVar1;
  }
  return uVar1;
}

