// FUN_fffffff0081c09d8 @ fffffff0081c09d8 size=220

/* WARNING: Removing unreachable block (ram,0xfffffff0081c0a7c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c0a3c) */

void FUN_fffffff0081c09d8(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  ulong unaff_x30;
  
  plVar2 = (long *)(**(code **)(**(long **)(param_1 + 0x1460) + 0x370))();
  uVar3 = (**(code **)(*plVar2 + 0x370))(*plVar2 + 0x370);
  lVar4 = **(long **)(param_1 + 0x1460);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081c0ab0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar4 + 0x588))(*(long **)(param_1 + 0x1460),param_3,uVar3,0,lVar4 + 0x588);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081c0aa8);
  (*pcVar1)();
}

