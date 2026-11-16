// FUN_fffffff0081a0304 @ fffffff0081a0304 size=716

void FUN_fffffff0081a0304(long param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  ulong unaff_x30;
  
  uVar4 = 1 << (ulong)((uint)((ulong)param_2 >> 8) & 0x1f);
  iVar3 = *(int *)(param_3 + 4);
  iVar7 = (int)param_2;
  uVar5 = iVar7 << 8;
  if (((iVar3 != 0xff) || (*(int *)(param_3 + 8) != 0xff)) || (*(int *)(param_3 + 0xc) != 0xff)) {
    lVar8 = *(long *)(param_1 + 0x10);
    if ((*(uint *)(lVar8 + 0x1ac44) & uVar4) != 0) {
      uVar1 = *(undefined4 *)(param_3 + 8);
      uVar2 = *(undefined4 *)(param_3 + 0xc);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494
                (uVar5 & 0xf0000 | iVar7 << 2 | 0x85900000,iVar3,uVar1,uVar2,param_4,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x1ac48));
    }
  }
  iVar3 = *(int *)(param_3 + 0x10);
  if (((iVar3 != 0xff) || (*(int *)(param_3 + 0x14) != 0xff)) || (*(int *)(param_3 + 0x18) != 0xff))
  {
    lVar8 = *(long *)(param_1 + 0x10);
    if ((*(uint *)(lVar8 + 0x1ac44) & uVar4) != 0) {
      uVar1 = *(undefined4 *)(param_3 + 0x14);
      uVar2 = *(undefined4 *)(param_3 + 0x18);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494
                (uVar5 & 0xf0000 | iVar7 << 2 | 0x85900000,iVar3,uVar1,uVar2,param_4,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x1ac48));
    }
  }
  iVar3 = *(int *)(param_3 + 0x1c);
  if (((iVar3 != 0xff) || (*(int *)(param_3 + 0x20) != 0xff)) || (*(int *)(param_3 + 0x24) != 0xff))
  {
    lVar8 = *(long *)(param_1 + 0x10);
    if ((*(uint *)(lVar8 + 0x1ac44) & uVar4) != 0) {
      uVar1 = *(undefined4 *)(param_3 + 0x20);
      uVar2 = *(undefined4 *)(param_3 + 0x24);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494
                (uVar5 & 0xf0000 | iVar7 << 2 | 0x85900000,iVar3,uVar1,uVar2,param_4,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x1ac48));
    }
  }
  iVar3 = *(int *)(param_3 + 0x28);
  if (((iVar3 != 0xff) || (*(int *)(param_3 + 0x2c) != 0xff)) || (*(int *)(param_3 + 0x30) != 0xff))
  {
    lVar8 = *(long *)(param_1 + 0x10);
    if ((*(uint *)(lVar8 + 0x1ac44) & uVar4) != 0) {
      uVar1 = *(undefined4 *)(param_3 + 0x2c);
      uVar2 = *(undefined4 *)(param_3 + 0x30);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494
                (uVar5 & 0xf0000 | iVar7 << 2 | 0x85900000,iVar3,uVar1,uVar2,param_4,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x1ac48));
    }
  }
  iVar3 = *(int *)(param_3 + 0x34);
  if (((iVar3 != 0xff) || (*(int *)(param_3 + 0x38) != 0xff)) || (*(int *)(param_3 + 0x3c) != 0xff))
  {
    lVar8 = *(long *)(param_1 + 0x10);
    if ((*(uint *)(lVar8 + 0x1ac44) & uVar4) != 0) {
      uVar1 = *(undefined4 *)(param_3 + 0x38);
      uVar2 = *(undefined4 *)(param_3 + 0x3c);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494
                (uVar5 & 0xf0000 | iVar7 << 2 | 0x85900000,iVar3,uVar1,uVar2,param_4,0);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a05b0);
        (*pcVar6)();
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x1ac48));
      return;
    }
  }
  return;
}

