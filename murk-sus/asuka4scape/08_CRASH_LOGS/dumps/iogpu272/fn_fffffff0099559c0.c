// FUN_fffffff0099559c0 @ fffffff0099559c0 size=492

void FUN_fffffff0099559c0(long param_1,undefined8 param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  long lVar7;
  int iVar8;
  undefined8 uVar9;
  ulong unaff_x30;
  
  uVar1 = *(uint *)(param_1 + 0x10) & 0xff;
  uVar6 = uVar1;
  if (((*(uint *)(param_1 + 0x10) & 0xf) == 0) && (*(long *)(param_1 + 0x30) != 0)) {
    uVar9 = *(undefined8 *)(param_1 + 0x28);
    uVar4 = thunk_EXT_FUN_8011000002c1e35c(*(undefined8 *)(*(long *)(param_1 + 0x30) + 0x10));
    FUN_fffffff00997b894(param_2,uVar9,uVar4);
    uVar6 = (uint)*(byte *)(param_1 + 0x10);
  }
  lVar7 = param_1;
  if (uVar6 == 0x82) {
    lVar7 = *(long *)(param_1 + 0x30);
  }
  if (*(long *)(param_1 + 0x68) == 0) {
    iVar8 = -1;
  }
  else {
    iVar8 = *(int *)(*(long *)(param_1 + 0x68) + 0x5c);
  }
  if (uVar1 == 0x82) {
    if ((lVar7 != 0) && (*(long *)(lVar7 + 0x28) != 0)) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        thunk_FUN_fffffff00997b958(param_2,*(long *)(lVar7 + 0x28),iVar8);
        return;
      }
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009955a80);
      (*pcVar2)();
    }
  }
  else if ((((uVar6 & 0xf) == 0) && (*(long *)(param_1 + 0x28) != 0)) && (iVar8 != -1)) {
    thunk_FUN_fffffff00997b958(param_2,*(long *)(param_1 + 0x28),iVar8);
    uVar4 = *(undefined8 *)(param_1 + 0x28);
    if (*(long **)(param_1 + 0x90) == (long *)0x0) {
      lVar7 = thunk_EXT_FUN_8011000003890f30(uVar4,DAT_fffffff007fefaf0);
      if (lVar7 == 0) {
        return;
      }
      iVar3 = FUN_fffffff009981ce0();
      if (iVar3 == 0) {
        return;
      }
      uVar4 = *(undefined8 *)(param_1 + 0x28);
      uVar9 = FUN_fffffff009981cf4(lVar7);
      uVar5 = (**(code **)(**(long **)(param_1 + 0x28) + 0x88))();
    }
    else {
      uVar9 = (**(code **)(**(long **)(param_1 + 0x90) + 0x78))();
      uVar5 = (**(code **)(**(long **)(param_1 + 0x90) + 0x88))();
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      FUN_fffffff00997bc34(param_2,uVar4,iVar8,uVar9,uVar5);
      return;
    }
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009955b3c);
    (*pcVar2)();
  }
  return;
}

