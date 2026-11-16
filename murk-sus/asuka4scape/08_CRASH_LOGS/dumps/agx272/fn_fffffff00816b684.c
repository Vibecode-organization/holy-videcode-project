// FUN_fffffff00816b684 @ fffffff00816b684 size=4

void FUN_fffffff00816b684(long param_1)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  undefined8 *puVar4;
  ulong unaff_x30;
  undefined *puStack_58;
  undefined8 uStack_50;
  code *pcStack_48;
  undefined *puStack_40;
  long lStack_38;
  
  bVar1 = *(byte *)(param_1 + 0x189e8);
  if ((bVar1 < 2) &&
     (iVar3 = thunk_EXT_FUN_8011000003222c9c(*(undefined8 *)(param_1 + 0x11d88)), iVar3 == 0)) {
    puVar4 = (undefined8 *)(**(long **)(param_1 + 0x310) + 0xe8);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00816b7b8);
      (*pcVar2)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff00816b7c0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*puVar4)(*(long **)(param_1 + 0x310),FUN_fffffff00816e9e8,0,0,0,0,puVar4);
    return;
  }
  puStack_58 = PTR_DAT_fffffff007ca5f90;
  uStack_50 = DAT_fffffff007113e50;
  pcStack_48 = FUN_fffffff00816b7c4;
  puStack_40 = &DAT_fffffff007c92f28;
  lStack_38 = param_1;
  thunk_EXT_FUN_801100000395c120(&puStack_40,*(undefined8 *)(param_1 + 0x310),&puStack_58);
  if (bVar1 < 2) {
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x11d88));
  }
  return;
}

