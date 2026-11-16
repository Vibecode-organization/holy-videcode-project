// FUN_fffffff0081e69d4 @ fffffff0081e69d4 size=336

void FUN_fffffff0081e69d4(long param_1,ulong param_2,ulong param_3,uint param_4,ulong param_5)

{
  undefined8 *puVar1;
  long *plVar2;
  long lVar3;
  code *pcVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  int iVar8;
  ulong unaff_x30;
  
  thunk_EXT_FUN_801100000296c9fc();
  if ((param_4 == 6) || (param_4 == 0xd)) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Cannot deallocate from unmapped range!\n");
    return;
  }
  if (param_4 == 0) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Cannot deallocate from default range!\n");
    return;
  }
  uVar5 = (ulong)DAT_fffffff00ae2181c;
  param_3 = param_3 >> (uVar5 & 0x3f);
  uVar6 = param_2 >> (uVar5 & 0x3f);
  uVar7 = uVar6 + param_3 & -param_3;
  if (param_3 == 0) {
    uVar7 = uVar6 + 1;
  }
  lVar3 = (ulong)param_4 * 8;
  iVar8 = (int)lVar3;
  puVar1 = (undefined8 *)(param_1 + 0x1f0 + (long)iVar8);
  if (lVar3 != iVar8) {
    puVar1 = (undefined8 *)(param_1 + 0x1f0 + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
  }
  (**(code **)(*(long *)*puVar1 + 0xc0))((long *)*puVar1,param_5 >> (uVar5 & 0x3f),uVar7);
  plVar2 = (long *)(param_1 + 0xb8 + (long)iVar8);
  if (lVar3 != iVar8) {
    plVar2 = (long *)(param_1 + 0xb8 + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *plVar2 = *plVar2 - param_2;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e6ad0);
    (*pcVar4)();
  }
  thunk_EXT_FUN_801100000296ca08(param_1);
  return;
}

