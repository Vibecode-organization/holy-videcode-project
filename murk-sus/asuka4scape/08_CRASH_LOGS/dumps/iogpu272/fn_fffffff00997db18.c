// FUN_fffffff00997db18 @ fffffff00997db18 size=156

void FUN_fffffff00997db18(long param_1,long param_2)

{
  ulong uVar1;
  undefined8 *puVar2;
  uint uVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x28));
  uVar3 = *(uint *)(param_2 + 0x20);
  lVar5 = *(long *)(param_1 + 8);
  lVar6 = (ulong)uVar3 * 0x10;
  puVar2 = (undefined8 *)(lVar5 + (int)lVar6);
  if (lVar6 - (int)lVar6 != 0) {
    puVar2 = (undefined8 *)(lVar5 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar2 = 0;
  uVar1 = (ulong)uVar3 << 4 | 8;
  puVar2 = (undefined8 *)(lVar5 + (int)uVar1);
  if (uVar1 != (long)(int)uVar1) {
    puVar2 = (undefined8 *)(lVar5 + uVar1 & 0xffffffffffff | 0x2bad000000000000);
  }
  *puVar2 = 0xffffffffffffffff;
  *(undefined1 *)(param_2 + 0x34) = 0;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997dbb0);
    (*pcVar4)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x28));
  return;
}

