// FUN_fffffff009c49024 @ fffffff009c49024 size=372

void FUN_fffffff009c49024(long param_1,ulong param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000036da494
            (0x5400010,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x80),
             *(undefined8 *)(param_1 + 0x90),
             *(int *)(param_1 + 0x98) << 8 | *(uint *)(param_1 + 0x3d0) >> 9 & 1,0);
  thunk_EXT_FUN_80110000036da494
            (0x5400014,*(undefined4 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x58),
             *(undefined8 *)(param_1 + 0x60),
             (long)(int)((uint)*(byte *)(param_1 + 0x72) << 0x18) |
             (ulong)*(byte *)(param_1 + 0x73) << 0x10 | (ulong)*(ushort *)(param_1 + 0x70),0);
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  if (*(long *)(param_1 + 0x30) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = thunk_EXT_FUN_8011000003977aa8();
  }
  thunk_EXT_FUN_80110000036da494(0x540000c,uVar1,uVar4,0,0,0);
  if (((((param_2 & 1) != 0) && (*(long **)(param_1 + 0x30) != (long *)0x0)) &&
      (uVar5 = (**(code **)(**(long **)(param_1 + 0x30) + 0xa0))(), 1 < uVar5)) &&
     (iVar3 = (**(code **)(**(long **)(param_1 + 0x30) + 0xd8))(*(long **)(param_1 + 0x30),0),
     iVar3 == 0)) {
    thunk_EXT_FUN_8011000003972604(*(undefined8 *)(param_1 + 0x30));
    puVar6 = (undefined8 *)(**(long **)(param_1 + 0x30) + 0xe0);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c4918c);
      (*pcVar2)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c49194. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*puVar6)(*(long **)(param_1 + 0x30),0,puVar6);
    return;
  }
  return;
}

