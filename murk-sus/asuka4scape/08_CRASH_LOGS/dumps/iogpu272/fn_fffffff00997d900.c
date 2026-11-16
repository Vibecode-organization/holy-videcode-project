// FUN_fffffff00997d900 @ fffffff00997d900 size=220

void FUN_fffffff00997d900(long param_1,long param_2)

{
  ulong uVar1;
  long *plVar2;
  undefined8 *puVar3;
  int iVar4;
  code *pcVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  ulong unaff_x30;
  undefined8 uVar9;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x28));
  *(undefined1 *)(param_2 + 0x34) = 1;
  if (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x18) < *(int *)(param_1 + 0x10) / 2) {
    if (*(int *)(param_1 + 0x14) == *(int *)(param_1 + 0x10)) {
      FUN_fffffff00997da88(param_1);
    }
  }
  else {
    FUN_fffffff00997d9dc(param_1);
  }
  lVar6 = *(long *)(param_1 + 8);
  uVar7 = *(undefined8 *)(param_2 + 0x18);
  uVar9 = *(undefined8 *)(param_1 + 0x14);
  iVar4 = *(int *)(param_1 + 0x14);
  lVar8 = (long)iVar4 * 0x10;
  plVar2 = (long *)(lVar6 + (int)lVar8);
  if (lVar8 - (int)lVar8 != 0) {
    plVar2 = (long *)(lVar6 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *plVar2 = param_2;
  uVar1 = (long)iVar4 << 4 | 8;
  puVar3 = (undefined8 *)(lVar6 + (int)uVar1);
  if (uVar1 != (long)(int)uVar1) {
    puVar3 = (undefined8 *)(lVar6 + uVar1 & 0xffffffffffff | 0x2bad000000000000);
  }
  *puVar3 = uVar7;
  *(int *)(param_2 + 0x20) = iVar4;
  *(ulong *)(param_1 + 0x14) = CONCAT44((int)((ulong)uVar9 >> 0x20) + 1,(int)uVar9 + 1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997d9d8);
    (*pcVar5)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x28));
  return;
}

