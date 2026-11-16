// FUN_fffffff0081c047c @ fffffff0081c047c size=692

/* WARNING: Removing unreachable block (ram,0xfffffff0081c0704) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c0584) */

undefined8 FUN_fffffff0081c047c(long *param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  undefined4 uVar2;
  byte bVar3;
  uint uVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  undefined8 uVar8;
  long lVar9;
  
  pbVar1 = (byte *)(param_1 + 0x321);
  if (param_2 == 0) {
    if ((*pbVar1 & 1) == 0) {
      return 0;
    }
    param_3 = 0;
    *pbVar1 = 0;
    *(undefined4 *)((long)param_1 + 0x190c) = 0;
  }
  else {
    if ((*pbVar1 & 1) != 0) {
      return 0xe00002c5;
    }
    if (param_3 == 0) {
      param_3 = (**(code **)(*param_1 + 0x6b0))(param_1,2);
    }
    else {
      uVar4 = (int)param_1[0x16e] * 100;
      if (uVar4 <= param_3) {
        param_3 = uVar4;
      }
      if (param_3 < 0x65) {
        param_3 = 100;
      }
    }
  }
  plVar5 = (long *)thunk_EXT_FUN_80110000038ce29c("perf");
  plVar6 = (long *)thunk_EXT_FUN_80110000038ce29c("transfer");
  plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24(param_3,0x20);
  uVar8 = (**(code **)(*param_1 + 800))(*param_1 + 800,param_1,plVar5,plVar6,plVar7);
  if (param_2 != 0) {
    if ((int)uVar8 == 0) {
      DataMemoryBarrier(2,3);
      *pbVar1 = 1;
      *(uint *)((long)param_1 + 0x190c) = param_3;
      *(uint *)(param_1[0x123] + 0x5c9) = param_3 / 100;
    }
    else {
      (**(code **)(*plVar7 + 0xc0))(plVar7,0);
      (**(code **)(*param_1 + 800))(*param_1 + 800,param_1,plVar5,plVar6,plVar7);
    }
  }
  lVar9 = param_1[0x50];
  if ((*(byte *)(lVar9 + 0x1ac44) >> 3 & 1) != 0) {
    bVar3 = *pbVar1;
    uVar2 = *(undefined4 *)((long)param_1 + 0x190c);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar9 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930ca4,1,(int)uVar8 == 0,bVar3 & 1,uVar2,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar9 + 0x1ac48));
  }
  if (plVar7 != (long *)0x0) {
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  return uVar8;
}

