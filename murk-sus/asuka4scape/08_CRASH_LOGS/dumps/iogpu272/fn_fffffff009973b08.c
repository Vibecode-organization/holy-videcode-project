// FUN_fffffff009973b08 @ fffffff009973b08 size=528

undefined8
FUN_fffffff009973b08(long *param_1,long param_2,undefined8 param_3,ulong param_4,long *param_5)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  ulong uVar4;
  undefined8 uVar5;
  
  uVar5 = 0xe00002c2;
  if (param_2 != 0) {
    *param_5 = 0;
    *(undefined4 *)((long)param_1 + 0x184) = 1;
    uVar1 = (uint)param_4 & 0xffff;
    if (uVar1 == 0x21) {
      plVar3 = (long *)(**(code **)(*DAT_fffffff007fef140 + 0x68))();
      if (plVar3 == (long *)0x0) {
        return 0xe00002be;
      }
      uVar4 = (**(code **)(*plVar3 + 0x68))();
    }
    else {
      if (uVar1 != 1) {
        return 0xe00002c2;
      }
      plVar3 = (long *)(**(code **)(*param_1 + 0x638))(param_1);
      if (plVar3 == (long *)0x0) {
        return 0xe00002be;
      }
      (**(code **)(*plVar3 + 0x20))();
      uVar4 = FUN_fffffff009946e10(plVar3,0,param_2,param_4 >> 0x10 & 0xffff);
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    uVar5 = 0xe00002be;
    if ((uVar4 & 1) != 0) {
      iVar2 = (**(code **)(*plVar3 + 0x360))(plVar3,param_1);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(*plVar3 + 0x2b0))(plVar3,param_1);
        if (iVar2 != 0) {
          *param_5 = (long)plVar3;
          return 0;
        }
        (**(code **)(*plVar3 + 0x368))(plVar3,param_1);
      }
      uVar5 = 0xe00002c9;
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return uVar5;
}

