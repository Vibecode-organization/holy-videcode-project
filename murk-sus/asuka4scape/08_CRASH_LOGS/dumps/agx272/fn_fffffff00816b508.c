// FUN_fffffff00816b508 @ fffffff00816b508 size=344

/* WARNING: Removing unreachable block (ram,0xfffffff00816b604) */

void FUN_fffffff00816b508(long *param_1,undefined8 param_2)

{
  char *pcVar1;
  code *pcVar2;
  long lVar3;
  ulong unaff_x30;
  
  lVar3 = param_1[0x3075];
  if (lVar3 != 0) {
    pcVar1 = "fStampResource[kAGXHostMemoryTimestamp]";
    if (*(char **)(lVar3 + 0x20) != (char *)0x0) {
      pcVar1 = *(char **)(lVar3 + 0x20);
    }
    thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(lVar3 + 0x48),pcVar1);
  }
  lVar3 = param_1[0x3076];
  if (lVar3 != 0) {
    pcVar1 = "fStampResource[kAGXFWMemoryTimestamp]";
    if (*(char **)(lVar3 + 0x20) != (char *)0x0) {
      pcVar1 = *(char **)(lVar3 + 0x20);
    }
    thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(lVar3 + 0x48),pcVar1);
  }
  if (param_1[0x3079] != 0) {
    thunk_EXT_FUN_8011000002977e48
              (param_2,*(undefined8 *)(param_1[0x3079] + 0x18),"fYUVCSCTableMapping");
  }
  (**(code **)(*param_1 + 0xb58))
            ((undefined8 *)(*param_1 + 0xb58),param_1,FUN_fffffff00816b660,param_2);
  lVar3 = *(long *)param_1[0x96];
  (**(code **)(lVar3 + 0x3c0))(lVar3 + 0x3c0,(long *)param_1[0x96],param_2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00816b65c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(PTR_DAT_fffffff007ca6170 + 0x6a0))
              (param_1,param_2,PTR_DAT_fffffff007ca6170 + 0x6a0);
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00816b654);
  (*pcVar2)();
}

