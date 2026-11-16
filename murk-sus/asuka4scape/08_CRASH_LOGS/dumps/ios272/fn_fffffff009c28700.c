// FUN_fffffff009c28700 @ fffffff009c28700 size=164

undefined8 FUN_fffffff009c28700(undefined8 param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  if (param_2 != 0) {
    plVar2 = (long *)thunk_EXT_FUN_80110000038d0088(param_2);
    uVar3 = FUN_fffffff009c24f6c(param_1,plVar2,param_3);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    return uVar3;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c287a0);
    (*pcVar1)();
  }
  uVar3 = FUN_fffffff009c24f6c(param_1,0,param_3);
  return uVar3;
}

