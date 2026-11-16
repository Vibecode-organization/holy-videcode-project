// FUN_fffffff00a8d8238 @ fffffff00a8d8238 size=564
// CALLERS:
//   fffffff00a8d65e8 FUN_fffffff00a8d5ea4@fffffff00a8d5ea4
//   fffffff00a8d66ac FUN_fffffff00a8d5ea4@fffffff00a8d5ea4

long FUN_fffffff00a8d8238(long param_1,long param_2)

{
  ulong uVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  int iVar6;
  long *plVar7;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  local_48 = DAT_fffffff00ad30000;
  plVar3 = *(long **)(param_2 + 0x10);
  *(undefined8 *)(param_2 + 0x10) = 0;
  iVar6 = 0;
  if (plVar3 != (long *)0x0) {
    plVar4 = (long *)0x0;
    do {
      plVar2 = plVar3;
      plVar3 = (long *)*plVar2;
      iVar6 = iVar6 + 1;
      *plVar2 = (long)plVar4;
      *(long **)(param_2 + 0x10) = plVar2;
      plVar4 = plVar2;
    } while (plVar3 != (long *)0x0);
  }
  plVar3 = (long *)(**(code **)(DAT_fffffff00ad95bd0 + 0x68))();
  if ((plVar3 != (long *)0x0) &&
     (uVar1 = (**(code **)(*plVar3 + 0xd0))(plVar3,iVar6), (uVar1 & 1) == 0)) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
    plVar3 = (long *)0x0;
  }
  if (-1 < *(int *)(param_2 + 0x50)) {
    local_58 = 0;
    uStack_50 = 0;
    FUN_fffffff00a76d3ec(&local_58,0x10,"%u");
    lVar5 = **(long **)(param_1 + 0x20);
    (**(code **)(lVar5 + 0x100))(lVar5 + 0x100,*(long **)(param_1 + 0x20),&local_58,plVar3);
  }
  plVar4 = (long *)*(long *)(param_2 + 0x10);
  while (plVar4 != (long *)0x0) {
    plVar2 = (long *)plVar4[3];
    if ((*(code **)(param_1 + 0x48) == (code *)0x0) || ((*(byte *)(param_1 + 0x40) >> 1 & 1) == 0))
    {
      plVar7 = (long *)0x0;
    }
    else {
      plVar2 = (long *)(**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x50),plVar3,0);
      plVar7 = plVar2;
    }
    (**(code **)(*plVar3 + 0xe8))(plVar3,plVar2);
    (**(code **)(*(long *)plVar4[3] + 0x28))();
    plVar4[3] = 0;
    if (plVar7 != (long *)0x0) {
      (**(code **)(*plVar7 + 0x28))(plVar7);
    }
    lVar5 = *plVar4;
    *plVar4 = *(undefined8 *)(param_1 + 0x18);
    *(long **)(param_1 + 0x18) = plVar4;
    plVar4 = (long *)lVar5;
  }
  *(long **)(param_2 + 0x18) = plVar3;
  if (DAT_fffffff00ad30000 != local_48) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4c590();
  }
  return param_2;
}

