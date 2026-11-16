// FUN_fffffff009c4ac34 @ fffffff009c4ac34

long * FUN_fffffff009c4ac34
                 (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                 undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
                 long param_8,undefined8 *param_9,undefined1 *param_10)

{
  uint uVar1;
  undefined1 auVar2 [16];
  bool bVar3;
  int iVar4;
  long *plVar5;
  undefined8 *puVar6;
  long *plVar7;
  long extraout_x0;
  undefined8 *extraout_x1;
  ulong uVar8;
  
  plVar5 = (long *)thunk_FUN_fffffff00a8983cc
                             (param_1,param_2,param_3,param_4,param_5,param_6,
                              (long *)&DAT_fffffff00806d9b8,(ulong *)&DAT_00000038);
  puVar6 = (undefined8 *)thunk_FUN_fffffff00a8984ec(plVar5);
  *puVar6 = &PTR_thunk_FUN_fffffff00a8982e0_fffffff00806d7f0;
  thunk_FUN_fffffff00a8962a0(-0xff50b7900);
  plVar5[2] = (long)param_7;
  plVar5[3] = param_8;
  plVar7 = thunk_FUN_fffffff00a8d2200(*param_9);
  plVar5[4] = (long)plVar7;
  uVar1 = *(uint *)(param_9 + 2);
  uVar8 = param_9[1];
  plVar5[5] = uVar8;
  if (uVar1 < 3) {
    *(uint *)(plVar5 + 6) = uVar1;
    (**(code **)(*param_7 + 0x20))(param_7);
    bVar3 = FUN_fffffff009c4b268((long)plVar5,param_10);
    if (!bVar3) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
      plVar5 = (long *)0x0;
    }
    return plVar5;
  }
  auVar2._8_8_ = 0;
  auVar2._0_8_ = uVar8;
  FUN_fffffff009c4b730(auVar2,param_2,param_3,param_4,param_5,param_6);
  plVar7 = thunk_FUN_fffffff00a89ca6c(*(undefined8 *)(extraout_x0 + 0x90));
  plVar5 = (long *)(**(code **)(*plVar7 + 0x88))();
  while (plVar5 != (long *)0x0) {
    plVar5 = thunk_FUN_fffffff00a894f30(plVar5,-0xff50b7900);
    if ((((plVar5 != (long *)0x0) &&
         (iVar4 = (**(code **)(*(long *)plVar5[4] + 0xb8))((long *)plVar5[4],*extraout_x1),
         iVar4 != 0)) && ((int)plVar5[5] == *(int *)(extraout_x1 + 1))) &&
       (*(int *)((long)plVar5 + 0x2c) == *(int *)((long)extraout_x1 + 0xc)))
    goto LAB_fffffff009c4ae18;
    plVar5 = (long *)(**(code **)(*plVar7 + 0x88))(plVar7);
  }
  plVar5 = (long *)0x0;
LAB_fffffff009c4ae18:
  (**(code **)(*plVar7 + 0x28))(plVar7);
  return plVar5;
}

