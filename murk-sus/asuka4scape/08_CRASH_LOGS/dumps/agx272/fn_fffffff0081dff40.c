// FUN_fffffff0081dff40 @ fffffff0081dff40 size=388

void FUN_fffffff0081dff40(long *param_1,long *param_2,uint param_3)

{
  int *piVar1;
  undefined8 *puVar2;
  uint *puVar3;
  code *pcVar4;
  undefined8 uVar5;
  long lVar6;
  int iVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  ulong unaff_x30;
  
  if ((param_3 == 0xffffffff) || ((int)param_1[2] <= (int)param_3)) {
    return;
  }
  lVar10 = param_1[1];
  thunk_EXT_FUN_80110000038ff214(lVar10);
  lVar6 = param_1[4];
  uVar8 = -(ulong)(param_3 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_3 << 2;
  iVar7 = (int)((ulong)param_3 << 2);
  piVar1 = (int *)(lVar6 + iVar7);
  if (uVar8 != (long)iVar7) {
    piVar1 = (int *)(lVar6 + uVar8 & 0xffffffffffff | 0x2bad000000000000);
  }
  if (*piVar1 != 0) {
    iVar7 = *piVar1 + -1;
    lVar9 = (long)(int)param_3 * 4;
    piVar1 = (int *)(lVar6 + (int)lVar9);
    if (lVar9 - (int)lVar9 != 0) {
      piVar1 = (int *)(lVar6 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *piVar1 = iVar7;
    if (iVar7 != 0) {
      uVar5 = 0;
      goto LAB_fffffff0081e0080;
    }
  }
  uVar8 = (ulong)(param_3 >> 3) & 0x1ffffff8;
  *(ulong *)(param_1[5] + uVar8) = *(ulong *)(param_1[5] + uVar8) | 1L << ((ulong)param_3 & 0x3f);
  if (param_3 != *(uint *)(param_2 + 2)) {
    lVar6 = (long)(int)param_3 * 8;
    puVar2 = (undefined8 *)(param_1[3] + (long)(int)lVar6);
    if (lVar6 - (int)lVar6 != 0) {
      puVar2 = (undefined8 *)(param_1[3] + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar2 = 0;
    lVar6 = (long)(int)param_1[7] + 1;
    *(int *)(param_1 + 7) = (int)lVar6;
    lVar6 = lVar6 * 4;
    puVar3 = (uint *)(param_1[6] + (long)(int)lVar6);
    if (lVar6 - (int)lVar6 != 0) {
      puVar3 = (uint *)(param_1[6] + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar3 = param_3;
  }
  if ((*(byte *)((long)param_1 + 0x14) & 1) != 0) {
    thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*param_1 + 0x160));
  }
  uVar5 = 1;
LAB_fffffff0081e0080:
  (**(code **)(*param_2 + 0x88))(param_2,uVar5);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e00c0);
    (*pcVar4)();
  }
  thunk_EXT_FUN_80110000038ff2e0(lVar10);
  return;
}

