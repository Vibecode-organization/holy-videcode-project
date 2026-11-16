// FUN_fffffff009c381bc @ fffffff009c381bc size=176

void FUN_fffffff009c381bc(long param_1,long *param_2)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x430);
  *(long **)(param_1 + 0x430) = param_2;
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  if (param_2 != (long *)0x0) {
    thunk_EXT_FUN_801100000322ffdc("IOSurfaceRoot using IOSurfaceRootParavirtMapperInterface %p");
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0,
               "IOSurfaceRoot using IOSurfaceRootParavirtMapperInterface\n");
  }
  return;
}

