// FUN_fffffff009c33c34 @ fffffff009c33c34 size=400

long * FUN_fffffff009c33c34(undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  int iVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  
  if (param_3 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - no properties\n");
    plVar2 = (long *)0x0;
  }
  else {
    plVar2 = (long *)(**(code **)(*DAT_fffffff008067118 + 0x68))();
    if (plVar2 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "%s error - failed to alloc surface buffer\n");
    }
    else {
      uVar3 = FUN_fffffff009c1a914(plVar2,param_1,param_2,param_3,param_4);
      if ((uVar3 & 1) == 0) {
        (**(code **)(*plVar2 + 0x28))(plVar2);
        plVar2 = (long *)0x0;
      }
      else {
        plVar4 = (long *)plVar2[6];
        if (((plVar4 != (long *)0x0) && ((*(byte *)((long)plVar2 + 0x3d1) >> 3 & 1) != 0)) &&
           (iVar1 = (**(code **)(*plVar4 + 0xd8))(plVar4,0), iVar1 == 0)) {
          (**(code **)(*(long *)plVar2[6] + 0xe0))((long *)plVar2[6],0);
        }
        FUN_fffffff009c1fc5c(plVar2);
      }
    }
    FUN_fffffff009c33ed4(param_1);
  }
  return plVar2;
}

