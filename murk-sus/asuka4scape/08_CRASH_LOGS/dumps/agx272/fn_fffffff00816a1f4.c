// FUN_fffffff00816a1f4 @ fffffff00816a1f4 size=144

/* WARNING: Removing unreachable block (ram,0xfffffff00816a24c) */

void FUN_fffffff00816a1f4(long param_1,long *param_2)

{
  code *pcVar1;
  undefined1 uVar2;
  long lVar3;
  long *plVar4;
  ulong unaff_x30;
  
  plVar4 = *(long **)(param_1 + 0x4b0);
  uVar2 = (**(code **)(*param_2 + 0xe8))(param_2);
  lVar3 = *plVar4;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00816a280. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar3 + 600))(plVar4,uVar2,lVar3 + 600);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00816a278);
  (*pcVar1)();
}

