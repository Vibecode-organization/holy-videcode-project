// FUN_fffffff0099520b0 @ fffffff0099520b0 size=112

void FUN_fffffff0099520b0(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  uVar1 = *(undefined8 *)(param_1 + 0x40);
  uVar3 = (**(code **)(**(long **)(param_1 + 0x48) + 0x78))();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995211c);
    (*pcVar2)();
  }
  FUN_fffffff00997cb7c(param_3,param_2,uVar1,uVar3);
  return;
}

