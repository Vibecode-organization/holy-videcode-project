// FUN_fffffff009c2bc3c @ fffffff009c2bc3c size=440

/* WARNING: Removing unreachable block (ram,0xfffffff009c2bce0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2bd88) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2bc8c) */

undefined8 FUN_fffffff009c2bc3c(long param_1,long param_2,undefined8 param_3,int param_4)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x40);
  if (lVar3 == 0) {
    return 0;
  }
  if (lVar3 == 0) {
    return 0;
  }
  if (param_4 == 0) {
    lVar2 = *(long *)(lVar3 + 0x150);
    if ((lVar2 == 0) || (*(long *)(lVar3 + 0x170) != param_2)) {
      if (*(long *)(param_1 + 0x48) != 0) {
        return 1;
      }
      lVar3 = FUN_fffffff009c22264();
      if (lVar3 == 0) {
        return 0;
      }
      plVar1 = (long *)thunk_EXT_FUN_801100000396cb64(lVar3,param_2,0,param_3,0,0);
      if (*(long **)(param_1 + 0x48) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x48) + 0x28))();
      }
      *(long **)(param_1 + 0x48) = plVar1;
      if (plVar1 == (long *)0x0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,"%s: createMappingInTask() failed\n");
        return 0;
      }
      lVar3 = (**(code **)(*plVar1 + 0x78))(plVar1);
      lVar2 = *(long *)(param_1 + 0x40);
      if (lVar2 == 0) {
        lVar2 = 0;
      }
      lVar2 = FUN_fffffff009c22410(lVar2);
      lVar2 = lVar2 + lVar3;
    }
    *(long *)(param_1 + 0x50) = lVar2;
  }
  else {
    *(undefined8 *)(param_1 + 0x50) = 0;
  }
  return 1;
}

