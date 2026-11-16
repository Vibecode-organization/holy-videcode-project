// FUN_fffffff009c2302c @ fffffff009c2302c size=440

/* WARNING: Removing unreachable block (ram,0xfffffff009c23090) */

void FUN_fffffff009c2302c(long param_1,undefined8 param_2)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  code *pcVar5;
  bool bVar6;
  bool bVar7;
  long lVar8;
  undefined8 uVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  int iVar13;
  ulong unaff_x30;
  
  if ((uint)param_2 < 2) {
    do {
      if ((*(byte *)(param_1 + 0x3d2) >> 5 & 1) != 0) {
        lVar8 = thunk_EXT_FUN_8011000003721814();
        if (lVar8 == 0) {
          uVar9 = 0xffffffff;
        }
        else {
          uVar9 = thunk_EXT_FUN_8011000003720f30();
          thunk_EXT_FUN_8011000003720838(lVar8);
        }
        iVar4 = *(int *)(param_1 + 0x3d4);
        bVar6 = iVar4 != DAT_fffffff00af48590;
        iVar13 = (int)uVar9;
        bVar7 = iVar13 != DAT_fffffff00af48594;
        if (bVar6 || bVar7) {
          DAT_fffffff00af48590 = iVar4;
          DAT_fffffff00af48594 = iVar13;
        }
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
          FUN_fffffff009c231e4(bVar6 || bVar7,"decrement",iVar4,uVar9,param_2);
          return;
        }
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c231e0);
        (*pcVar5)();
      }
      do {
        uVar12 = *(ulong *)(*(long *)(param_1 + 0x178) + 0x18);
        uVar11 = 0;
        if (uVar12 >> 0x20 != 0) {
          uVar11 = (uVar12 & 0xffffffff00000000) - 0x100000000;
        }
        uVar10 = (int)uVar12 - 1;
        uVar2 = 0;
        if ((int)uVar12 != 0) {
          uVar2 = (ulong)uVar10;
        }
        uVar3 = 0xffffffff;
        bVar6 = (uVar12 & 0xffffffff00000000) == 0x100000000;
        if ((uint)param_2 == 0) {
          uVar3 = 0xffffffff00000000;
          bVar6 = uVar10 == 0;
          uVar11 = uVar2;
        }
        uVar11 = uVar11 | uVar3 & uVar12;
        puVar1 = (ulong *)(*(long *)(param_1 + 0x178) + 0x18);
      } while (*puVar1 != uVar12);
      *puVar1 = uVar11;
      bVar7 = false;
      if (uVar11 == 0) {
        bVar7 = bVar6;
      }
      if (bVar7) {
        uVar10 = *(uint *)(param_1 + 0x3d0);
        if ((uVar10 >> 6 & 1) != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
          *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xfffffff3;
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
          uVar10 = *(uint *)(param_1 + 0x3d0);
        }
        if ((uVar10 >> 7 & 1) != 0) {
          FUN_fffffff009c23234(param_1);
        }
        FUN_fffffff009c35a60(DAT_fffffff00af483b0,0,param_1);
      }
      param_1 = *(long *)(param_1 + 0x378);
    } while (param_1 != 0);
  }
  return;
}

