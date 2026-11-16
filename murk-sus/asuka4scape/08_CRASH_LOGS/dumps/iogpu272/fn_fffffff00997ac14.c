// FUN_fffffff00997ac14 @ fffffff00997ac14 size=140

void FUN_fffffff00997ac14(long *param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  uVar3 = *(undefined8 *)(param_1[0xa6] + 0x148);
  uVar2 = (**(code **)(*param_1 + 0x130))();
  FUN_fffffff00994c6ac(uVar3,uVar2,param_2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997ac9c);
    (*pcVar1)();
  }
  FUN_fffffff00994c6ac(*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0x9b,param_2);
  return;
}

