// FUN_fffffff009c22ee0 @ fffffff009c22ee0 size=320

/* WARNING: Removing unreachable block (ram,0xfffffff009c22f3c) */

void FUN_fffffff009c22ee0(long param_1,undefined8 param_2)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  code *pcVar6;
  bool bVar7;
  bool bVar8;
  long lVar9;
  undefined8 uVar10;
  ulong uVar11;
  int iVar12;
  ulong unaff_x30;
  
  if ((uint)param_2 < 2) {
    do {
      if ((*(byte *)(param_1 + 0x3d2) >> 5 & 1) != 0) {
        lVar9 = thunk_EXT_FUN_8011000003721814();
        if (lVar9 == 0) {
          uVar10 = 0xffffffff;
        }
        else {
          uVar10 = thunk_EXT_FUN_8011000003720f30();
          thunk_EXT_FUN_8011000003720838(lVar9);
        }
        iVar5 = *(int *)(param_1 + 0x3d4);
        bVar7 = iVar5 != DAT_fffffff00af48588;
        iVar12 = (int)uVar10;
        bVar8 = iVar12 != DAT_fffffff00af4858c;
        if (bVar7 || bVar8) {
          DAT_fffffff00af48588 = iVar5;
          DAT_fffffff00af4858c = iVar12;
        }
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
          FUN_fffffff009c231e4(bVar7 || bVar8,"increment",iVar5,uVar10,param_2);
          return;
        }
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2301c);
        (*pcVar6)();
      }
      do {
        uVar11 = *(ulong *)(*(long *)(param_1 + 0x178) + 0x18);
        uVar2 = (uVar11 & 0xffffffff00000000) + 0x100000000;
        if (0xfffffffeffffffff < uVar11) {
          uVar2 = 0xffffffff00000000;
        }
        uVar3 = 0xffffffff;
        if ((int)uVar11 != -1) {
          uVar3 = (ulong)((int)uVar11 + 1);
        }
        uVar4 = 0xffffffff;
        if ((uint)param_2 == 0) {
          uVar4 = 0xffffffff00000000;
          uVar2 = uVar3;
        }
        puVar1 = (ulong *)(*(long *)(param_1 + 0x178) + 0x18);
      } while (*puVar1 != uVar11);
      *puVar1 = uVar2 | uVar4 & uVar11;
      param_1 = *(long *)(param_1 + 0x378);
    } while (param_1 != 0);
  }
  return;
}

