// FUN_fffffff00819fcfc @ fffffff00819fcfc size=200

void FUN_fffffff00819fcfc(long param_1,uint param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  ulong uVar8;
  long lVar9;
  ulong unaff_x30;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x10) + 0x480);
  uVar8 = -(ulong)(param_2 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_2 << 2;
  iVar7 = (int)((ulong)param_2 << 2);
  piVar1 = (int *)(lVar5 + iVar7);
  if (uVar8 != (long)iVar7) {
    piVar1 = (int *)(lVar5 + uVar8 & 0xffffffffffff | 0x2bad000000000000);
  }
  lVar6 = *(long *)(*(long *)(param_1 + 0x10) + 0x488);
  lVar9 = (long)(int)param_2 * 4;
  iVar7 = (int)lVar9;
  if (0 < param_3 - *piVar1) {
    piVar1 = (int *)(lVar5 + iVar7);
    if (lVar9 - iVar7 != 0) {
      piVar1 = (int *)(lVar5 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *piVar1 = param_3;
    piVar2 = (int *)(lVar6 + iVar7);
    if (lVar9 - iVar7 != 0) {
      piVar2 = (int *)(lVar6 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *piVar2 = *piVar1;
  }
  puVar3 = (undefined4 *)(lVar5 + iVar7);
  if (lVar9 - iVar7 != 0) {
    puVar3 = (undefined4 *)(lVar5 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
  }
  thunk_EXT_FUN_8011000002946e48(param_1,param_2,*puVar3);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00819fdc0);
    (*pcVar4)();
  }
  thunk_EXT_FUN_8011000002970f9c(*(undefined8 *)(param_1 + 0x10));
  return;
}

