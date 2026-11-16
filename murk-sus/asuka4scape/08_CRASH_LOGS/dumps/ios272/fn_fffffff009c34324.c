// FUN_fffffff009c34324 @ fffffff009c34324 size=324

undefined8 FUN_fffffff009c34324(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  
  plVar2 = (long *)(**(code **)(*DAT_fffffff008067950 + 0x68))();
  plVar3 = (long *)FUN_fffffff009c34468(param_3);
  if ((plVar2 == (long *)0x0 || plVar3 == (long *)0x0) ||
     (iVar1 = (**(code **)(*plVar2 + 0xd0))
                        (plVar2,param_1,plVar3,*(undefined8 *)(param_2 + 8),
                         *(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x10)),
     iVar1 == 0)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
               "Failed to install %s memory region; checking in anyway\n");
    FUN_fffffff009c34034(param_1);
    if (plVar3 == (long *)0x0) goto LAB_fffffff009c34428;
  }
  else {
    FUN_fffffff009c33f94(param_1,plVar2);
  }
  (**(code **)(*plVar3 + 0x28))(plVar3);
LAB_fffffff009c34428:
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return 0;
}

