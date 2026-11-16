// FUN_fffffff00821244c @ fffffff00821244c size=428

undefined8 FUN_fffffff00821244c(long param_1,ulong *param_2,ulong *param_3)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  long lVar5;
  ulong local_68;
  ulong uStack_60;
  ulong local_58;
  ulong local_50;
  ulong uStack_48;
  ulong local_40;
  
  local_68 = param_2[2];
  if ((((local_68 < *param_2) || (uStack_60 = local_68 + 0x9a8, 0xfffffffffffff657 < local_68)) ||
      (param_2[1] < uStack_60)) || (param_2[2] = uStack_60, uStack_60 == local_68)) {
    *(undefined4 *)(param_1 + 0xc) = 0x100;
    return 0;
  }
  local_58 = local_68;
  uVar2 = (*(code *)**(undefined8 **)(param_1 + 0x10))((undefined8 *)(param_1 + 0x10),&local_68);
  if ((uVar2 & 1) == 0) {
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x35c);
    return 0;
  }
  local_40 = *param_3;
  uStack_48 = param_3[1];
  if (uStack_48 < local_40) {
    uStack_48 = 0;
    local_40 = 0;
  }
  local_50 = local_40;
  iVar1 = (*(code *)**(undefined8 **)(param_1 + 0x1d8))
                    ((undefined8 *)(param_1 + 0x1d8),param_2,&local_50);
  if (iVar1 == 0) {
    lVar5 = 0x1e4;
  }
  else {
    if ((*(byte *)(param_1 + 0x1e0) & 1) == 0) {
      uVar3 = thunk_EXT_FUN_8011000003a49114
                        ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n")
      ;
      return uVar3;
    }
    if (*(int *)(param_1 + 0x26c) != 0) {
      uVar4 = 10;
      goto LAB_fffffff0082125ec;
    }
    if (*(int *)(param_1 + 0x288) != 1) {
      uVar4 = 0x106;
      goto LAB_fffffff0082125ec;
    }
    uVar2 = (*(code *)**(undefined8 **)(param_1 + 0x350))(param_1 + 0x350,param_1 + 0x2a8);
    if ((uVar2 & 1) != 0) {
      *(undefined1 *)(param_1 + 8) = 1;
      return 1;
    }
    lVar5 = 0x35c;
  }
  uVar4 = *(undefined4 *)(param_1 + lVar5);
LAB_fffffff0082125ec:
  *(undefined4 *)(param_1 + 0xc) = uVar4;
  return 0;
}

