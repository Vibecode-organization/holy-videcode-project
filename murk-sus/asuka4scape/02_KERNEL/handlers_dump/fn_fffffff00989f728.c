// FUN_fffffff00989f728 @ fffffff00989f728 size=4 depth=0
// CALLERS:
//   fffffff00afe4496 ?
//   fffffff007fc18f8 ?
// CALLS:

undefined8 FUN_fffffff00989f728(long *param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  long *plVar5;
  undefined8 *puVar6;
  ulong uVar7;
  long extraout_x16;
  long extraout_x16_00;
  long extraout_x16_01;
  long extraout_x16_02;
  long extraout_x16_03;
  long extraout_x16_04;
  long extraout_x16_05;
  long extraout_x16_06;
  undefined8 uVar8;
  undefined8 *puVar9;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 auVar10 [16];
  undefined8 uStack_48;
  
  uStack_48 = 0;
  FUN_fffffff00985a958();
  if (param_1[0x1c] == 0) {
    FUN_fffffff0097cb984();
  }
  else {
    FUN_fffffff0097bc290();
    (**(code **)(extraout_x16 + 0xa8))();
  }
  uVar8 = 0xe00002c2;
  auVar10 = FUN_fffffff0097bc27c();
  thunk_FUN_fffffff00a8df19c
            (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,auVar10._0_8_,auVar10._8_8_,2,
             (byte *)"%s::%s(): Copying cached LDCM waveform... (target: %s)\n");
  if ((((*(long *)(param_3 + 0x20) != 0) && (*(long *)(param_3 + 0x58) != 0)) &&
      (*(long *)(param_3 + 0x48) != 0)) &&
     ((uVar8 = 0xe00002c0, param_1[0x1d] != 0 &&
      (uVar1 = thunk_FUN_fffffff00a92d93c(param_1), (uVar1 & 1) == 0)))) {
    iVar2 = FUN_fffffff0097f0234(param_1[0x1d]);
    if ((iVar2 == 4) || (iVar2 = FUN_fffffff0097f0234(param_1[0x1d]), iVar2 == 5)) {
      auVar10 = FUN_fffffff0097bc290();
      plVar5 = (long *)(**(code **)(extraout_x16_00 + 0x650))
                                 (auVar10._0_8_,auVar10._8_8_,&uStack_48);
      if (plVar5 == (long *)0x0) {
        *(undefined4 *)(param_3 + 0x60) = 0;
        FUN_fffffff00985a90c();
        auVar10 = FUN_fffffff0097bc27c();
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0_01,in_q1,in_s2,in_s3,in_s4,in_s5,auVar10._0_8_,auVar10._8_8_,2,
                   (byte *)"%s::%s(): No cached waveform available\n");
        uVar8 = 0xe00002f0;
      }
      else {
        iVar2 = (**(code **)(*plVar5 + 0xa0))();
        if (iVar2 == 0) {
          *(undefined4 *)(param_3 + 0x60) = 0;
          FUN_fffffff00985a90c();
          auVar10 = FUN_fffffff0097bc27c();
          thunk_FUN_fffffff00a8df19c
                    (extraout_q0_02,in_q1,in_s2,in_s3,in_s4,in_s5,auVar10._0_8_,auVar10._8_8_,2,
                     (byte *)"%s::%s(): No cached waveform available\n");
          uVar8 = 0xe00002f0;
        }
        else {
          uVar1 = *(uint *)(param_3 + 0x60);
          FUN_fffffff00985a970();
          uVar3 = (**(code **)(extraout_x16_01 + 0xa0))(plVar5);
          if (uVar1 < uVar3) {
            FUN_fffffff00985a958();
            FUN_fffffff00985a970();
            (**(code **)(extraout_x16_06 + 0xa0))(plVar5);
            auVar10 = FUN_fffffff0097bc27c();
            thunk_FUN_fffffff00a8df19c
                      (extraout_q0_03,in_q1,in_s2,in_s3,in_s4,in_s5,auVar10._0_8_,auVar10._8_8_,0x10
                       ,(byte *)"%s::%s(): Output buffer too small: %u < %u\n");
            uVar8 = 0xe00002e8;
          }
          else {
            puVar9 = *(undefined8 **)(param_3 + 0x58);
            FUN_fffffff00985a970();
            puVar6 = (undefined8 *)(**(code **)(extraout_x16_02 + 0xd8))(plVar5);
            FUN_fffffff00985a970();
            uVar7 = (**(code **)(extraout_x16_03 + 0xa0))(plVar5);
            thunk_FUN_fffffff00aa65b10(puVar9,puVar6,uVar7 & 0xffffffff);
            FUN_fffffff00985a970();
            uVar4 = (**(code **)(extraout_x16_04 + 0xa0))(plVar5);
            *(undefined4 *)(param_3 + 0x60) = uVar4;
            **(undefined8 **)(param_3 + 0x48) = uStack_48;
            *(undefined4 *)(param_3 + 0x50) = 1;
            FUN_fffffff00985a958();
            FUN_fffffff00985a970();
            (**(code **)(extraout_x16_05 + 0xa0))(plVar5);
            auVar10 = FUN_fffffff0097bc27c();
            thunk_FUN_fffffff00a8df19c
                      (extraout_q0_00,in_q1,in_s2,in_s3,in_s4,in_s5,auVar10._0_8_,auVar10._8_8_,0,
                       (byte *)
                       "%s::%s(): Successfully copied cached waveform (size: %u bytes, timestamp: %llu)\n"
                      );
            uVar8 = 0;
          }
        }
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
    }
    else {
      uVar8 = 0xe00002c7;
    }
  }
  return uVar8;
}

