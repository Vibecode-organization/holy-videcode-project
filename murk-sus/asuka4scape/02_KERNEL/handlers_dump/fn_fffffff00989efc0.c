// FUN_fffffff00989efc0 @ fffffff00989efc0 size=4 depth=0
// CALLERS:
//   fffffff00afe448c ?
//   fffffff007fc1808 ?
// CALLS:

/* WARNING: Removing unreachable block (ram,0xfffffff00989f0d8) */

undefined8 FUN_fffffff00989efc0(long *param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  ulong uVar4;
  long extraout_x16;
  long lVar5;
  long extraout_x16_00;
  long extraout_x16_01;
  long extraout_x16_02;
  long extraout_x16_03;
  long extraout_x16_04;
  long *plVar6;
  undefined8 uVar7;
  long *plVar8;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 auVar9 [16];
  long *plStack_58;
  
  plStack_58 = (long *)0x0;
  FUN_fffffff00985a958();
  if (param_1[0x1c] == 0) {
    FUN_fffffff0097cb984();
  }
  else {
    FUN_fffffff0097bc290();
    (**(code **)(extraout_x16 + 0xa8))();
  }
  uVar7 = 0xe00002c0;
  auVar9 = FUN_fffffff0097bc27c();
  thunk_FUN_fffffff00a8df19c
            (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,auVar9._0_8_,auVar9._8_8_,0,
             (byte *)"%s::%s(): Copying cached LDCM data... (target: %s)\n");
  if (*(long **)(param_3 + 0x68) == (long *)0x0) {
    plVar6 = thunk_FUN_fffffff00a966e00
                       (*(undefined8 *)(param_3 + 0x58),(ulong)*(uint *)(param_3 + 0x60),3,0);
    plVar8 = plVar6;
    if (plVar6 == (long *)0x0) {
      uVar7 = 0xe00002bd;
      goto LAB_fffffff00989f204;
    }
  }
  else {
    plVar6 = (long *)0x0;
    plVar8 = *(long **)(param_3 + 0x68);
  }
  if ((param_1[0x1d] != 0) && (uVar1 = thunk_FUN_fffffff00a92d93c(param_1), (uVar1 & 1) == 0)) {
    uVar3 = (**(code **)(*plVar8 + 0xb0))(plVar8);
    lVar5 = *(long *)param_1[0x1d];
    uVar7 = (**(code **)(lVar5 + 0x5d0))(lVar5 + 0x5d0,(long *)param_1[0x1d],&plStack_58);
    if ((int)uVar7 == 0) {
      if (plStack_58 == (long *)0x0) {
        uVar7 = 0;
        *(undefined4 *)(param_3 + 0x70) = 0;
        *(undefined4 *)(param_3 + 0x60) = 0;
      }
      else {
        FUN_fffffff0097bc290();
        uVar4 = (**(code **)(extraout_x16_00 + 0xa0))();
        if (uVar3 < (uVar4 & 0xffffffff)) {
          uVar7 = 0xe00002e8;
        }
        else {
          (**(code **)(*plVar8 + 0xd8))(plVar8,0);
          FUN_fffffff0097bc290();
          uVar7 = (**(code **)(extraout_x16_01 + 0xd8))();
          FUN_fffffff0097bc290();
          uVar2 = (**(code **)(extraout_x16_02 + 0xa0))();
          (**(code **)(*plVar8 + 0xd0))(plVar8,0,uVar7,uVar2);
          (**(code **)(*plVar8 + 0xe0))(plVar8,0);
          lVar5 = *(long *)(param_3 + 0x68);
          FUN_fffffff0097bc290();
          uVar2 = (**(code **)(extraout_x16_03 + 0xa0))();
          if (lVar5 == 0) {
            *(undefined4 *)(param_3 + 0x60) = uVar2;
            uVar7 = 0;
          }
          else {
            uVar7 = 0;
            *(undefined4 *)(param_3 + 0x70) = uVar2;
          }
        }
      }
    }
    else {
      if (param_1[0x1c] == 0) {
        FUN_fffffff0097cb984();
      }
      else {
        FUN_fffffff0097bc290();
        (**(code **)(extraout_x16_04 + 0xa8))();
      }
      auVar9 = FUN_fffffff0097bc27c();
      thunk_FUN_fffffff00a8df19c
                (extraout_q0_00,in_q1,in_s2,in_s3,in_s4,in_s5,auVar9._0_8_,auVar9._8_8_,0x10,
                 (byte *)"[ERROR] Failed to copy cached LDCM data! (target: %s)\n");
    }
  }
LAB_fffffff00989f204:
  if (plStack_58 != (long *)0x0) {
    (**(code **)(*plStack_58 + 0x28))();
  }
  plStack_58 = (long *)0x0;
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  return uVar7;
}

