// FUN_fffffff009c2200c @ fffffff009c2200c size=308

void FUN_fffffff009c2200c(undefined8 param_1,ulong param_2,ulong param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined4 local_94;
  long local_90;
  ulong local_88;
  undefined8 local_80;
  undefined1 *puStack_78;
  undefined1 *puStack_70;
  undefined1 *puStack_68;
  undefined4 local_60;
  long local_58;
  
  uVar4 = 0;
  local_58 = *(long *)PTR_DAT_fffffff00806ca40;
  local_90 = 0;
  local_88 = param_2;
  do {
    local_94 = 9;
    local_60 = 0xaaaaaaaa;
    puStack_78 = &DAT_aaaaaaaaaaaaaaaa;
    local_80 = &DAT_aaaaaaaaaaaaaaaa;
    puStack_68 = &DAT_aaaaaaaaaaaaaaaa;
    puStack_70 = &DAT_aaaaaaaaaaaaaaaa;
    if (local_90 != 0) {
      uVar4 = local_88 + local_90;
      local_90 = 0;
      local_88 = uVar4;
    }
    uVar3 = thunk_EXT_FUN_80110000032977b0(param_1);
    iVar2 = thunk_EXT_FUN_8011000003340acc(uVar3,&local_88,&local_90,9,&local_80,&local_94,0);
    if (iVar2 != 0) {
LAB_fffffff009c22100:
      uVar3 = 0xe00002c8;
      goto LAB_fffffff009c22108;
    }
    bVar1 = local_88 <= param_2;
    if (uVar4 != 0) {
      bVar1 = uVar4 == local_88;
    }
    if ((!bVar1) || (((byte)local_80 >> 2 & 1) != 0)) goto LAB_fffffff009c22100;
    if ((local_80._4_1_ >> 1 & 1) == 0) {
      *param_4 = 2;
    }
  } while (local_90 + local_88 < param_3);
  uVar3 = 0;
LAB_fffffff009c22108:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_58) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar3);
  return;
}

