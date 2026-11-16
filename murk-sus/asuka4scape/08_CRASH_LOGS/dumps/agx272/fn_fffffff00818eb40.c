// FUN_fffffff00818eb40 @ fffffff00818eb40 size=308

void FUN_fffffff00818eb40(long *param_1,long param_2)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong unaff_x30;
  
  uVar2 = (**(code **)(*param_1 + 0x158))(param_1,1);
  if ((uVar2 & 1) == 0) {
    if ((*(byte *)(param_1[0xa6] + 0x1ac44) >> 3 & 1) != 0) {
      FUN_fffffff00817dc48(param_1[0xa6],0x362,2,param_1,1,0,0,0);
    }
    *(undefined4 *)(param_1 + 0xa4) = 8;
    return;
  }
  (**(code **)(**(long **)(param_1[0xc2] + 0xa8) + 0x98))
            (*(long **)(param_1[0xc2] + 0xa8),*(undefined4 *)(param_2 + 0x30),
             *(undefined8 *)(param_2 + 0x38));
  *(undefined2 *)(param_1 + 0xfd) = 0;
  *(undefined1 *)((long)param_1 + 0x7ea) = 0;
  lVar4 = param_1[0xa3];
  if ((*(long *)(lVar4 + 0x130) == 0) && (*(long *)(lVar4 + 0x140) == 0)) {
    uVar3 = thunk_EXT_FUN_8011000003397c88();
    *(undefined8 *)(lVar4 + 0x140) = uVar3;
  }
  *(undefined1 *)(param_1 + 0xc3) = 1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818ec08);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00818ec10. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6130 + 0x128))(param_1,param_2,PTR_DAT_fffffff007ca6130 + 0x128);
  return;
}

