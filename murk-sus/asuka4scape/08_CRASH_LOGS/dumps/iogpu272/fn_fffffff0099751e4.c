// FUN_fffffff0099751e4 @ fffffff0099751e4 size=784

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0099751e4(undefined8 param_1,int param_2,long param_3)

{
  char *pcVar1;
  uint uVar2;
  bool bVar3;
  byte bVar4;
  code *pcVar5;
  bool bVar6;
  long *plVar7;
  long *plVar8;
  long lVar9;
  long *plVar10;
  ulong uVar11;
  long lVar12;
  ulong unaff_x30;
  
  if (param_2 < 2) {
    if (param_2 == 0) {
      if (DAT_fffffff00af227e8 != 0) {
        return;
      }
      if ((*PTR_DAT_fffffff007ff2828 & 1) == 0) {
        return;
      }
      lVar9 = 0;
      lVar12 = 0x1f;
      do {
        pcVar1 = &DAT_fffffff00af227f0 + lVar9;
        lVar9 = lVar9 + 1;
        bVar6 = lVar12 != 0;
        lVar12 = lVar12 + -1;
      } while (*pcVar1 == '\0' && bVar6);
      DAT_fffffff00af227e8 = (uint)(*pcVar1 != '\0' || DAT_fffffff00af22810 != 0);
      DAT_fffffff00af22968 = 0;
    }
    else {
      if (param_2 != 1) {
        return;
      }
      DAT_fffffff00af227e8 = 0;
    }
  }
  else {
    if (param_2 == 2) {
      DAT_fffffff00af22818 = thunk_EXT_FUN_8011000003397c88();
      if ((DAT_fffffff00af22968 & 1) != 0) {
        return;
      }
      bVar6 = false;
      bVar3 = true;
      DAT_fffffff00af22968 = 1;
      goto LAB_fffffff009975398;
    }
    if (param_2 != 3) {
      return;
    }
    uVar11 = 0;
    uRamfffffff00af227f8 = 0;
    _DAT_fffffff00af227f0 = 0;
    uRamfffffff00af22808 = 0;
    _DAT_fffffff00af22800 = 0;
    do {
      uVar2 = 1 << (ulong)((uint)uVar11 & 7);
      if ((uVar2 & *(byte *)(param_3 + (uVar11 >> 3 | 0x10a0))) != 0) {
        (&DAT_fffffff00af227f0)[uVar11 >> 3] = (&DAT_fffffff00af227f0)[uVar11 >> 3] | (byte)uVar2;
      }
      uVar2 = (uint)uVar11 + 1;
      uVar11 = (ulong)uVar2;
    } while (uVar2 != 0x100);
    DAT_fffffff00af227ec = DAT_fffffff00af227f3 & 1;
    bVar4 = *(byte *)(param_3 + 0xc2) >> 2;
    DAT_fffffff00af22810 = bVar4 & 1;
    if ((*PTR_DAT_fffffff007ff2828 & 1) != 0) {
      lVar9 = 0;
      lVar12 = 0x1f;
      do {
        pcVar1 = &DAT_fffffff00af227f0 + lVar9;
        lVar9 = lVar9 + 1;
        bVar6 = lVar12 != 0;
        lVar12 = lVar12 + -1;
      } while (*pcVar1 == '\0' && bVar6);
      DAT_fffffff00af227e8 = (uint)(*pcVar1 != '\0' || (bVar4 & 1) != 0);
    }
  }
  bVar3 = false;
  bVar6 = true;
LAB_fffffff009975398:
  plVar7 = (long *)thunk_EXT_FUN_801100000392ef4c("IOAcceleratorES",0);
  if (plVar7 == (long *)0x0) {
    return;
  }
  plVar8 = (long *)thunk_EXT_FUN_801100000392e6e0();
  if (plVar8 != (long *)0x0) {
    lVar9 = (**(code **)(*plVar8 + 0x88))();
    while (lVar9 != 0) {
      plVar10 = (long *)thunk_EXT_FUN_8011000003890f30(lVar9,&DAT_fffffff00af22790);
      if (plVar10 != (long *)0x0) {
        if (bVar6) {
          uVar2 = DAT_fffffff00af22800 & 1;
          if ((_DAT_fffffff00af227f0 & 0x100) != 0) {
            uVar2 = 1;
          }
          *(uint *)plVar10[0x2f] = uVar2;
          (**(code **)(*plVar10 + 0x6a0))(plVar10);
        }
        if (bVar3) {
          FUN_fffffff0099757a4(plVar10);
        }
      }
      lVar9 = (**(code **)(*plVar8 + 0x88))(plVar8);
    }
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0099754d8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar7 + 0x28))(plVar7,(undefined8 *)(*plVar7 + 0x28));
    return;
  }
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099754d0);
  (*pcVar5)();
}

