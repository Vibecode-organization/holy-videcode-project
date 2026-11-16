// FUN_fffffff009c3aa54 @ fffffff009c3aa54 size=244

/* WARNING: Removing unreachable block (ram,0xfffffff009c3aaf4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3aab8) */

void FUN_fffffff009c3aa54(long param_1,undefined8 param_2)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  if ((*(byte *)(param_1 + 0xf0) & 1) != 0) {
    *(undefined1 *)(param_1 + 0xf0) = 0;
    FUN_fffffff009c35ad4(*(undefined8 *)(param_1 + 0xe8),param_1);
    lVar2 = *(long *)(param_1 + 0xf8);
    if (lVar2 == 0) {
      lVar2 = 0;
    }
    FUN_fffffff009c38088(*(undefined8 *)(param_1 + 0xe8),param_1,lVar2);
    lVar2 = *(long *)(param_1 + 0xf8);
    if (lVar2 == 0) {
      lVar2 = 0;
    }
    FUN_fffffff009c34810(*(undefined8 *)(param_1 + 0xe8),lVar2);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c3ab3c);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c3ab44. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca28 + 0x2c8))(param_1,param_2,PTR_DAT_fffffff00806ca28 + 0x2c8);
  return;
}

