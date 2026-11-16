// FUN_fffffff00995ce6c @ fffffff00995ce6c size=152

undefined8 FUN_fffffff00995ce6c(undefined8 param_1,long *param_2,int param_3,int param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  if ((*(byte *)((long)param_2 + 0x4c) & 1) == 0) {
    (**(code **)(*param_2 + 0x88))(param_2);
  }
  if ((param_4 != 0) && (param_2[0xd] != 0)) {
    *(int *)(param_2[0xd] + 200) = param_4;
  }
  if (param_3 != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995ceec);
      (*pcVar1)();
    }
    uVar2 = FUN_fffffff00996e568(param_2);
    return uVar2;
  }
  return 0;
}

