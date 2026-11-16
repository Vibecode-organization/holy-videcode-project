// FUN_fffffff00998207c @ fffffff00998207c size=4

/* WARNING: Removing unreachable block (ram,0xfffffff009982268) */
/* WARNING: Removing unreachable block (ram,0xfffffff009982138) */
/* WARNING: Removing unreachable block (ram,0xfffffff009982198) */

void FUN_fffffff00998207c(undefined8 param_1,long *param_2)

{
  undefined *puVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long lStack_58;
  long lStack_50;
  long lStack_48;
  
  (*DAT_fffffff007fe90d0)();
  lStack_50 = 0;
  lStack_48 = 0;
  lStack_58 = 0;
  plVar3 = (long *)FUN_fffffff009981d0c(param_1);
  iVar2 = thunk_EXT_FUN_8011000003977f9c(plVar3,&lStack_48,&lStack_50,&lStack_58);
  puVar1 = PTR_DAT_fffffff007ff2838;
  if ((iVar2 == 0) || (iVar2 == -0x1ffffd28)) {
    plVar4 = (long *)thunk_EXT_FUN_80110000038c6e24
                               ((lStack_58 + lStack_50) * *(long *)PTR_DAT_fffffff007ff2838,0x40);
    (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"DirtySize",plVar4);
    plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(*(long *)puVar1 * lStack_48,0x40);
    (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"ResidentSize",plVar5);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: IOMemoryDescriptor::getPageCounts returned 0x%08x\n");
  }
  FUN_fffffff0099437e4(param_1);
  plVar4 = (long *)thunk_EXT_FUN_80110000038970c4();
  (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"Wired",plVar4);
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return;
}

