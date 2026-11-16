// FUN_fffffff009c05e50 @ fffffff009c05e50

undefined8
FUN_fffffff009c05e50
          (long *param_1,long param_2,long param_3,long param_4,uint param_5,undefined8 param_6,
          ulong param_7,undefined *param_8,long *param_9)

{
  undefined *puVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  long *plVar8;
  long *plVar9;
  bool bVar10;
  
  if (param_1[0x12] == 0) {
    lVar6 = thunk_FUN_fffffff00a902074((long *)&DAT_fffffff0080641d8);
    param_1[0x12] = lVar6;
    if (lVar6 == 0) {
      plVar8 = (long *)0x0;
LAB_fffffff009c062c8:
      if ((long *)param_1[0x17] != (long *)0x0) {
        (**(code **)(*(long *)param_1[0x17] + 0x28))();
        param_1[0x17] = 0;
        plVar8 = (long *)param_1[0x12];
      }
      if (plVar8 != (long *)0x0) {
        if ((undefined8 *)*plVar8 != (undefined8 *)0x0) {
          thunk_FUN_fffffff00a903020((undefined8 *)*plVar8);
          plVar8 = (long *)param_1[0x12];
        }
        if ((long *)plVar8[1] != (long *)0x0) {
          (**(code **)(*(long *)plVar8[1] + 0x28))();
          plVar8 = (long *)param_1[0x12];
        }
        param_1[0x12] = 0;
        thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff008064218,plVar8);
      }
      return 0;
    }
    lVar6 = thunk_FUN_fffffff00a903010();
    plVar8 = (long *)param_1[0x12];
    *plVar8 = lVar6;
    if (lVar6 == 0) goto LAB_fffffff009c062c8;
    plVar9 = thunk_FUN_fffffff00a89a1f4(1);
    plVar8 = (long *)param_1[0x12];
    plVar8[1] = (long)plVar9;
    if (plVar9 == (long *)0x0) goto LAB_fffffff009c062c8;
    *(undefined1 *)(plVar8 + 2) = 0;
  }
  if (param_1[0x17] == 0) {
    uVar7 = (*(code *)PTR_FUN_fffffff008063790)(param_1,param_9);
    if ((int)uVar7 == 0) {
      return uVar7;
    }
    bVar10 = false;
    bVar2 = param_1[0x17] == 0;
  }
  else if ((((param_1[0x14] == param_2) && (param_1[0x15] == param_3)) && (param_1[0x19] == param_4)
           ) && ((uint)param_7 == (*(byte *)((long)param_1 + 0x9d) & 1))) {
    bVar2 = false;
    bVar10 = false;
  }
  else {
    bVar2 = false;
    bVar10 = true;
  }
  *(uint *)(param_1 + 0x13) = param_5 | (param_5 & 1) << 1;
  *(char *)((long)param_1 + 0x9c) = (char)param_6;
  *(char *)((long)param_1 + 0x9d) = (char)param_7;
  param_1[0x19] = param_4;
  param_1[0x14] = param_2;
  param_1[0x15] = param_3;
  if (bVar2) {
    plVar8 = thunk_FUN_fffffff00a8a10d8(2);
    param_1[0x17] = (long)plVar8;
    *(undefined4 *)(param_1 + 0x16) = 0;
    if (plVar8 == (long *)0x0) {
      return 0;
    }
    puVar1 = &DAT_fffffff007898c93;
    if (param_8 != (undefined *)0x0) {
      puVar1 = param_8;
    }
    (**(code **)(*param_1 + 0xd0))(param_1,"Content",puVar1);
    (**(code **)(*param_1 + 0xd8))(param_1,&DAT_fffffff007899271,1);
    (**(code **)(*param_1 + 0xd8))(param_1,&DAT_fffffff007899276,0);
    goto LAB_fffffff009c06144;
  }
  plVar8 = thunk_FUN_fffffff00a8d42e4((byte *)"IOStorage");
  if (plVar8 == (long *)0x0) {
    return 0;
  }
  plVar9 = (long *)(**(code **)(*param_1 + 0x280))(param_1,plVar8);
  (**(code **)(*plVar8 + 0x28))(plVar8);
  if (plVar9 == (long *)0x0) {
LAB_fffffff009c06110:
    puVar1 = &DAT_fffffff007898c93;
    if (param_8 != (undefined *)0x0) {
      puVar1 = param_8;
    }
    (**(code **)(*param_1 + 0xd0))(param_1,"Content",puVar1);
  }
  else {
    plVar8 = (long *)(**(code **)(*plVar9 + 0x118))(plVar9,"Content Mask");
    plVar8 = thunk_FUN_fffffff00a894f30(plVar8,*(long *)PTR_PTR_fffffff008064ba8);
    (**(code **)(*plVar9 + 0x28))(plVar9);
    if (plVar8 == (long *)0x0) goto LAB_fffffff009c06110;
  }
  param_7 = param_7 & 0xffffffff;
LAB_fffffff009c06144:
  puVar1 = &DAT_fffffff007898c93;
  if (param_8 != (undefined *)0x0) {
    puVar1 = param_8;
  }
  (**(code **)(*param_1 + 0xd0))(param_1,"Content Hint",puVar1);
  (**(code **)(*param_1 + 0xd8))(param_1,"Ejectable",param_5 & 1);
  (**(code **)(*param_1 + 0xe0))(param_1,"Preferred Block Size",param_4,0x40);
  (**(code **)(*param_1 + 0xd8))(param_1,"Removable",(param_5 & 3) != 0);
  (**(code **)(*param_1 + 0xe0))(param_1,&DAT_fffffff00789929a,param_3,0x40);
  (**(code **)(*param_1 + 0xd8))(param_1,"Whole",param_6);
  (**(code **)(*param_1 + 0xd8))(param_1,"Writable",param_7);
  if (bVar10) {
    plVar8 = thunk_FUN_fffffff00a8d42e4((byte *)"IOStorage");
    if (plVar8 == (long *)0x0) {
      plVar9 = (long *)0x0;
    }
    else {
      plVar9 = (long *)(**(code **)(*param_1 + 0x280))(param_1,plVar8);
      (**(code **)(*plVar8 + 0x28))(plVar8);
    }
    (**(code **)(*param_1 + 0x300))(param_1,1);
    uVar5 = thunk_FUN_fffffff00a92d93c(param_1);
    if ((uVar5 & 1) == 0) {
      if (plVar9 == (long *)0x0) {
        bVar3 = false;
        bVar10 = true;
        bVar2 = true;
      }
      else {
        bVar3 = (int)param_1[0x16] == 0;
        bVar2 = !bVar3;
        bVar10 = bVar3;
      }
    }
    else {
      bVar3 = false;
      bVar2 = false;
      bVar10 = false;
    }
    (**(code **)(*param_1 + 0x308))(param_1);
    if (bVar3) {
      bVar4 = (**(code **)(*plVar9 + 0x2f0))(plVar9,0);
      bVar10 = (bool)(bVar4 & bVar10);
    }
    if (bVar10 != false) {
      (**(code **)(*param_1 + 0x2a0))(param_1,8);
    }
    if (bVar2) {
      (**(code **)(*param_1 + 0x430))(param_1,0xe0010002,0,0);
    }
    if (plVar9 != (long *)0x0) {
      (**(code **)(*plVar9 + 0x28))(plVar9);
    }
  }
  return 1;
}

