// FUN_fffffff009994f34 @ fffffff009994f34 size=4 depth=0
// CALLERS:
//   fffffff00afe67ce ?
//   fffffff007ff3060 ?
// CALLS:

ulong FUN_fffffff009994f34(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  undefined8 uVar6;
  long *plVar7;
  ulong *in_x3;
  undefined *in_x4;
  long extraout_x16;
  long extraout_x16_00;
  long extraout_x16_01;
  long extraout_x16_02;
  long extraout_x16_03;
  long extraout_x16_04;
  long extraout_x16_05;
  long extraout_x16_06;
  long extraout_x16_07;
  long extraout_x16_08;
  long extraout_x16_09;
  long extraout_x16_10;
  long extraout_x16_11;
  long extraout_x16_12;
  long extraout_x16_13;
  long extraout_x16_14;
  long extraout_x16_15;
  long extraout_x16_16;
  long extraout_x16_17;
  long extraout_x16_18;
  long extraout_x16_19;
  ulong uVar8;
  undefined1 extraout_q0 [16];
  undefined1 in_q1 [16];
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  long *plStack_60;
  long *plStack_58;
  
  lVar5 = param_3;
  uVar1 = FUN_fffffff0099861b4(param_1,param_2,param_3);
  uVar8 = (ulong)uVar1;
  if (uVar1 == 0) {
    uVar8 = 0xe00002c9;
    plVar3 = FUN_fffffff009985f54(&plStack_58);
    if (plVar3 == (long *)0x0) {
      uVar8 = 0xe00002c2;
    }
    else {
      plVar4 = FUN_fffffff009995ba8
                         (extraout_q0,in_q1,in_q2,in_q3,in_s4,in_s5,param_1,param_3,lVar5,in_x3,
                          in_x4);
      if (plVar4 != (long *)0x0) {
        lVar5 = (**(code **)(*plVar4 + 0x138))(plVar4,"QueueID");
        if (lVar5 != 0) {
          FUN_fffffff0099861d8();
          lVar5 = (**(code **)(extraout_x16 + 0x148))(plVar3,"QueueID");
          if (lVar5 == 0) {
            FUN_fffffff00998618c();
            (**(code **)(extraout_x16_02 + 0x118))(plVar4,"QueueID");
          }
          else {
            FUN_fffffff00998616c();
            uVar6 = (**(code **)(extraout_x16_00 + 0x20))();
            FUN_fffffff0099861fc(uVar6,"QueueID");
            if (plStack_60 != (long *)0x0) {
              (**(code **)(*plStack_60 + 0x28))();
            }
            FUN_fffffff0099861f0();
            (**(code **)(extraout_x16_01 + 0x28))();
          }
        }
        FUN_fffffff00998618c();
        lVar5 = (**(code **)(extraout_x16_03 + 0x138))(plVar4,"QueueGuard");
        if (lVar5 != 0) {
          FUN_fffffff0099861d8();
          lVar5 = (**(code **)(extraout_x16_04 + 0x148))(plVar3,"QueueGuard");
          if (lVar5 == 0) {
            FUN_fffffff00998618c();
            (**(code **)(extraout_x16_07 + 0x118))(plVar4,"QueueGuard");
          }
          else {
            FUN_fffffff00998616c();
            uVar6 = (**(code **)(extraout_x16_05 + 0x20))();
            FUN_fffffff0099861fc(uVar6,"QueueGuard");
            if (plStack_60 != (long *)0x0) {
              (**(code **)(*plStack_60 + 0x28))();
            }
            FUN_fffffff0099861f0();
            (**(code **)(extraout_x16_06 + 0x28))();
          }
        }
        FUN_fffffff00998618c();
        lVar5 = (**(code **)(extraout_x16_08 + 0x138))(plVar4,"QueueMemorySize");
        if (lVar5 != 0) {
          FUN_fffffff0099861d8();
          lVar5 = (**(code **)(extraout_x16_09 + 0x148))(plVar3,"QueueMemorySize");
          if (lVar5 == 0) {
            FUN_fffffff00998618c();
            (**(code **)(extraout_x16_12 + 0x118))(plVar4,"QueueMemorySize");
          }
          else {
            FUN_fffffff00998616c();
            uVar6 = (**(code **)(extraout_x16_10 + 0x20))();
            FUN_fffffff0099861fc(uVar6,"QueueMemorySize");
            if (plStack_60 != (long *)0x0) {
              (**(code **)(*plStack_60 + 0x28))();
            }
            FUN_fffffff0099861f0();
            (**(code **)(extraout_x16_11 + 0x28))();
          }
        }
        FUN_fffffff00998618c();
        lVar5 = (**(code **)(extraout_x16_13 + 0x138))(plVar4,"QueueEntrySize");
        if (lVar5 != 0) {
          FUN_fffffff0099861d8();
          lVar5 = (**(code **)(extraout_x16_14 + 0x148))(plVar3,"QueueEntrySize");
          if (lVar5 == 0) {
            FUN_fffffff00998618c();
            (**(code **)(extraout_x16_17 + 0x118))(plVar4,"QueueEntrySize");
          }
          else {
            FUN_fffffff00998616c();
            uVar6 = (**(code **)(extraout_x16_15 + 0x20))();
            FUN_fffffff0099861fc(uVar6,"QueueEntrySize");
            if (plStack_60 != (long *)0x0) {
              (**(code **)(*plStack_60 + 0x28))();
            }
            FUN_fffffff0099861f0();
            (**(code **)(extraout_x16_16 + 0x28))();
          }
        }
        plVar7 = thunk_FUN_fffffff00a8d8814(0x1000,0,0);
        if (plVar7 == (long *)0x0) {
          uVar8 = 0xe00002bd;
        }
        else {
          FUN_fffffff00998618c();
          iVar2 = (**(code **)(extraout_x16_18 + 0x30))(plVar4,plVar7);
          if (iVar2 == 0) {
            (**(code **)(*plVar7 + 0x28))(plVar7);
          }
          else {
            uVar8 = 0;
            **(undefined8 **)(param_3 + 0x78) = plVar7;
          }
        }
        FUN_fffffff00998618c();
        (**(code **)(extraout_x16_19 + 0x28))(plVar4);
      }
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
  }
  if (plStack_58 != (long *)0x0) {
    (**(code **)(*plStack_58 + 0x28))();
  }
  return uVar8;
}

