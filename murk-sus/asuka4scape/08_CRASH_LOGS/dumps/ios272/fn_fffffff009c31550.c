// FUN_fffffff009c31550 @ fffffff009c31550 size=288

void FUN_fffffff009c31550(long param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  long lVar5;
  ulong unaff_x30;
  
  FUN_fffffff009c31514();
  puVar3 = *(undefined8 **)(param_1 + 0x160);
  while (puVar3 != (undefined8 *)0x0) {
    *(undefined8 *)(param_1 + 0x160) = *puVar3;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b2b0);
    puVar3 = *(undefined8 **)(param_1 + 0x160);
  }
  DAT_fffffff00af483b0 = 0;
  if (*(long **)(param_1 + 0x218) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x218) + 0x28))();
    *(undefined8 *)(param_1 + 0x218) = 0;
  }
  thunk_EXT_FUN_8011000003740d38(&DAT_fffffff00af480b0);
  thunk_EXT_FUN_8011000003740d38(&DAT_fffffff00af48060);
  if (*(long *)(param_1 + 0x228) != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  if (*(long *)(param_1 + 0x230) != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  if (*(long *)(param_1 + 1000) != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  if (*(long *)(param_1 + 0x150) != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  lVar5 = *(ulong *)(param_1 + 0x420) * 0x10;
  lVar1 = -0x8000000000000000;
  if (-1 < lVar5 && (*(ulong *)(param_1 + 0x420) & 0xf000000000000000) == 0) {
    lVar1 = lVar5;
  }
  uVar4 = *(undefined8 *)(param_1 + 0x428);
  *(undefined8 *)(param_1 + 0x428) = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806c0b0,uVar4,lVar1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c31664);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c3166c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca38 + 0x80))(param_1);
  return;
}

