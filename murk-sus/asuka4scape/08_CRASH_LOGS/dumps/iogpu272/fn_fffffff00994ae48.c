// FUN_fffffff00994ae48 @ fffffff00994ae48 size=204

void FUN_fffffff00994ae48(long param_1,ulong param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  ulong uVar2;
  code *pcVar3;
  undefined8 uVar4;
  int iVar5;
  ulong uVar6;
  ulong unaff_x30;
  
  uVar2 = (param_2 & 0xffffffff) << 3;
  uVar6 = -(param_2 >> 0x1f & 1) & 0xfffffff800000000 | uVar2;
  iVar5 = (int)uVar2;
  puVar1 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar5);
  if (uVar6 != (long)iVar5) {
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x20) + uVar6 & 0xffffffffffff | 0x2bad000000000000)
    ;
  }
  thunk_EXT_FUN_8011000003246024(*puVar1,0,0);
  thunk_EXT_FUN_8011000003246024(param_1,0,0);
  if (DAT_fffffff00af227e8 != 0) {
    uVar4 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994af00);
      (*pcVar3)();
    }
    thunk_EXT_FUN_80110000036da494(0x8518000c,(long)(int)param_2,param_3,uVar4,0,0);
    return;
  }
  return;
}

