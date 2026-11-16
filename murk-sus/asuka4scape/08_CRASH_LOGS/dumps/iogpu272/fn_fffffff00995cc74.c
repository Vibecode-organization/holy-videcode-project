// FUN_fffffff00995cc74 @ fffffff00995cc74 size=504

undefined8 FUN_fffffff00995cc74(long param_1,undefined8 param_2,ulong param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  long *plVar11;
  undefined8 uVar12;
  ulong unaff_x30;
  
  uVar2 = *(uint *)(param_1 + 0x54);
  uVar4 = 0;
  if (uVar2 != 0) {
    uVar4 = *(uint *)(param_1 + 0x4c) / uVar2;
  }
  lVar3 = (ulong)(*(uint *)(param_1 + 0x4c) - uVar4 * uVar2) * 8;
  puVar1 = (undefined8 *)(*(long *)(param_1 + 0x58) + (long)(int)lVar3);
  if (lVar3 != (int)lVar3) {
    puVar1 = (undefined8 *)
             (*(long *)(param_1 + 0x58) + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
  }
  plVar11 = (long *)*puVar1;
  if ((*(byte *)((long)plVar11 + 0x4c) & 1) == 0) {
    iVar6 = FUN_fffffff009961728(*(undefined8 *)(param_1 + 0x10));
    if (((param_3 & 1) == 0) && (iVar6 != 0)) {
      uVar12 = 0xe00002be;
    }
    else if (*(int *)(*(long *)(param_1 + 0x10) + 0x158) == (int)param_2) {
      if (DAT_fffffff00af227e8 != 0) {
        uVar12 = *(undefined8 *)(param_1 + 200);
        uVar8 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0xc0));
        thunk_EXT_FUN_80110000036da494(0x85180169,uVar12,uVar8,plVar11[0x21],plVar11[0x20],0);
      }
      uVar12 = (**(code **)(*plVar11 + 0x90))(plVar11,param_2);
      iVar6 = (int)uVar12;
      uVar8 = uVar12;
      if (DAT_fffffff00af227e8 != 0) {
        uVar8 = *(undefined8 *)(param_1 + 200);
        uVar9 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0xc0));
        iVar7 = FUN_fffffff00996e4e4(plVar11);
        uVar8 = thunk_EXT_FUN_80110000036da494(0x8518016a,uVar8,uVar9,(long)iVar7,(long)iVar6,0);
      }
      if ((0x1a < iVar6 + 0x1ffffd42U ||
          (1 << (ulong)(iVar6 + 0x1ffffd42U & 0x1f) & 0x4800001U) == 0) && iVar6 != 0) {
        uVar10 = 8;
        if (iVar6 != -0x1ffffd43) {
          uVar10 = 1;
        }
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995ce1c);
          (*pcVar5)();
        }
        uVar12 = FUN_fffffff00995ce6c(uVar8,plVar11,1,uVar10);
        return uVar12;
      }
    }
    else {
      uVar12 = 0xe00002d8;
    }
  }
  else {
    if (*(char *)((long)plVar11 + 0x4d) == '\0') {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995ce48);
        (*pcVar5)();
      }
      uVar12 = FUN_fffffff00996e568(plVar11);
      return uVar12;
    }
    uVar12 = 0xe00002eb;
  }
  return uVar12;
}

