// FUN_fffffff00996c878 @ fffffff00996c878 size=256

bool FUN_fffffff00996c878(long *param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  
  param_1[2] = param_2;
  lVar1 = thunk_EXT_FUN_80110000038ff134();
  param_1[3] = lVar1;
  if (lVar1 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "IOGPUStatistics couldn\'t allocate an IOLock.\n");
  }
  else {
    plVar2 = (long *)thunk_EXT_FUN_80110000038cb1e8(param_1,FUN_fffffff00996c978,0);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*(long *)param_1[2] + 200))((long *)param_1[2],"PerformanceStatistics",plVar2);
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    (**(code **)(*param_1 + 0x88))(param_1);
  }
  return lVar1 != 0;
}

