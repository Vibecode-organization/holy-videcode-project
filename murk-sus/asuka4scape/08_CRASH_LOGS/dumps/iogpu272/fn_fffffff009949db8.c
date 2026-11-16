// FUN_fffffff009949db8 @ fffffff009949db8 size=4

undefined8 FUN_fffffff009949db8(long *param_1)

{
  undefined1 uVar1;
  long *plVar2;
  long lVar3;
  
  plVar2 = (long *)(**(code **)(*(long *)param_1[0x1f] + 0x550))
                             ((long *)param_1[0x1f],param_1 + 0x23);
  param_1[0x21] = (long)plVar2;
  if (plVar2 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: getStampMemory failed\n");
  }
  else {
    (**(code **)(*plVar2 + 0x20))();
    lVar3 = thunk_EXT_FUN_801100000396cb64
                      (param_1[0x21],*(undefined8 *)param_1[0x1b],0,0x4001001,0,0);
    param_1[0x22] = lVar3;
    if (lVar3 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: fStampMemoryMap creation failed\n")
      ;
    }
    else {
      lVar3 = (**(code **)(*(long *)param_1[0x1f] + 0x588))
                        ((long *)param_1[0x1f],*(undefined8 *)param_1[0x1b],param_1[0x25]);
      param_1[0x24] = lVar3;
      if (lVar3 != 0) {
        lVar3 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
        param_1[0x1d] = lVar3;
        uVar1 = FUN_fffffff0099658e8(param_1[0x24]);
        *(undefined1 *)((long)param_1 + 0x103) = uVar1;
        plVar2 = (long *)thunk_EXT_FUN_80110000038cb1e8(param_1,FUN_fffffff009949fe0,0);
        if (plVar2 == (long *)0x0) {
          return 1;
        }
        (**(code **)(*param_1 + 200))(param_1,"AppUsage",plVar2);
        (**(code **)(*plVar2 + 0x28))(plVar2);
        return 1;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: createDevice failed\n");
    }
  }
  FUN_fffffff009949ff0(param_1);
  return 0;
}

