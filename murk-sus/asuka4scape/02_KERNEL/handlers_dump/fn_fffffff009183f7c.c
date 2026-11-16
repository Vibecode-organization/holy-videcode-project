// FUN_fffffff009183f7c @ fffffff009183f7c size=72 depth=0
// CALLERS:
//   fffffff00afdb21b ?
//   fffffff007ecb5c8 ?
// CALLS:
//   fffffff009196114 FUN_fffffff009196114

/* WARNING: Removing unreachable block (ram,0xfffffff009184054) */
/* WARNING: Removing unreachable block (ram,0xfffffff009184000) */

ulong FUN_fffffff009183f7c
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                undefined8 param_8,long param_9,undefined8 param_10,undefined *param_11)

{
  undefined1 uVar1;
  code *pcVar2;
  bool bVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 auVar8 [16];
  undefined1 extraout_q0_05 [16];
  byte abStack_b0 [12];
  uint uStack_a4;
  undefined1 **ppuStack_a0;
  ulong uStack_98;
  long lStack_88;
  long lStack_80;
  long *plStack_78;
  undefined1 *puStack_40;
  ulong uStack_38;
  undefined1 *puStack_30;
  undefined8 uStack_28;
  undefined1 *puStack_20;
  undefined8 uStack_18;
  
  if (*(long **)(param_9 + 0x40) == (long *)0x0) {
    return 0xe00002c2;
  }
  if (*(int *)(param_9 + 0x28) == 4) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009183fb0);
      (*pcVar2)();
    }
    uVar4 = FUN_fffffff009196114
                      (param_1,param_2,param_3,param_4,param_5,param_6,*(long **)(param_7 + 0xd8),
                       *(long **)(param_9 + 0x40),*(undefined1 (**) [16])(param_9 + 0x20),0,1);
    return uVar4;
  }
  lVar5 = FUN_fffffff0091ad5fc(param_1,param_2,param_3,param_4,param_5,param_6);
  if (*(long **)(param_9 + 0x40) == (long *)0x0) {
    return 0xe00002c2;
  }
  if (*(int *)(param_9 + 0x28) == 4) {
    uVar4 = FUN_fffffff009196114
                      (extraout_q0,param_2,param_3,param_4,param_5,param_6,*(long **)(lVar5 + 0xd8),
                       *(long **)(param_9 + 0x40),*(undefined1 (**) [16])(param_9 + 0x20),1,0);
    return uVar4;
  }
  uStack_18 = 0xfffffff009183fd0;
  puStack_20 = &stack0xfffffffffffffff0;
  lVar5 = FUN_fffffff0091ad634(extraout_q0,param_2,param_3,param_4,param_5,param_6);
  if (*(long **)(param_9 + 0x40) == (long *)0x0) {
    return 0xe00002c2;
  }
  if (*(int *)(param_9 + 0x28) == 4) {
    uVar4 = FUN_fffffff009196114
                      (extraout_q0_00,param_2,param_3,param_4,param_5,param_6,
                       *(long **)(lVar5 + 0xd8),*(long **)(param_9 + 0x40),
                       *(undefined1 (**) [16])(param_9 + 0x20),1,1);
    return uVar4;
  }
  uStack_28 = 0xfffffff009184024;
  puStack_30 = (undefined1 *)&puStack_20;
  lVar5 = FUN_fffffff0091ad66c(extraout_q0_00,param_2,param_3,param_4,param_5,param_6);
  uStack_38 = 0xfffffff009184078;
  lVar6 = *(long *)(lVar5 + 0xd8);
  if ((*(byte *)(lVar6 + 0x158) & 1) == 0) {
    puStack_40 = (undefined1 *)&puStack_30;
    bVar3 = FUN_fffffff009194fec(lVar6,&DAT_fffffff0076cc376);
    auVar8 = extraout_q0_03;
    if (bVar3) {
      lStack_88 = 0;
      lStack_80 = 0;
      plStack_78 = (long *)0x0;
      uVar1 = **(undefined1 **)(param_9 + 0x20);
      lVar6 = *(long *)(*(undefined1 **)(param_9 + 0x20) + 8);
      plVar7 = (long *)FUN_fffffff009195dac
                                 (extraout_q0_03,param_2,param_3,param_4,param_5,param_6,
                                  *(long *)(lVar5 + 0xd8),15000);
      auVar8 = extraout_q0_04;
      if (plVar7 != (long *)0x0) {
        uVar4 = FUN_fffffff0091ad3b4(param_9,(long *)0x0,&lStack_88);
        if ((int)uVar4 == 0) {
          if (lVar6 == 0 && lStack_80 != 0) {
            uVar4 = 0xe00002c2;
          }
          else {
            lVar5 = 0;
            if (lStack_80 != 0) {
              lVar5 = lStack_88;
            }
            uVar4 = FUN_fffffff009192fd4(plVar7,uVar1,lVar5,lStack_80,lVar6 != 0);
            if ((int)uVar4 != 0) {
              thunk_FUN_fffffff00a9029a0((byte *)"Failed to commit hash");
            }
          }
        }
        if (plStack_78 != (long *)0x0) {
          (**(code **)(*plStack_78 + 0x28))();
          (**(code **)(**(long **)(param_9 + 0x40) + 0xe0))(*(long **)(param_9 + 0x40),0);
        }
        return uVar4;
      }
      goto LAB_fffffff0091841f4;
    }
  }
  else {
    puStack_40 = (undefined1 *)&puStack_30;
    lVar5 = FUN_fffffff009195cc8(extraout_q0_01,param_2,param_3,param_4,param_5,param_6,lVar6,15000)
    ;
    if (lVar5 != 0) {
      if (((uStack_38 ^ uStack_38 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0091840d8);
        (*pcVar2)();
      }
      if (*(long **)(lVar5 + 0xe8) != (long *)0x0) {
        uVar4 = FUN_fffffff00919d554
                          (extraout_q0_02,param_2,param_3,param_4,param_5,param_6,
                           *(long **)(lVar5 + 0xe8),'\x16',(uint *)0x0,(undefined8 *)0x0,param_11);
        if ((int)uVar4 != 0) {
          thunk_FUN_fffffff00a9029a0((byte *)"AppleSEP:WARNING: Failed commit hash, error %d\n");
        }
        return uVar4;
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0091b536c(extraout_q0_02,param_2,param_3,param_4,param_5,param_6);
    }
    auVar8 = FUN_fffffff0091ad70c(extraout_q0_02,param_2,param_3,param_4,param_5,param_6);
  }
  auVar8 = FUN_fffffff0091ad6a4(auVar8,param_2,param_3,param_4,param_5,param_6);
LAB_fffffff0091841f4:
  FUN_fffffff0091ad6d4(auVar8,param_2,param_3,param_4,param_5,param_6);
  uStack_98 = 0xfffffff0091841f8;
  ppuStack_a0 = &puStack_40;
  plVar7 = (long *)FUN_fffffff009195c8c();
  if (((uStack_98 ^ uStack_98 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009184228);
    (*pcVar2)();
  }
  uStack_a4 = 5000;
  abStack_b0[0] = 0;
  abStack_b0[1] = 0;
  abStack_b0[2] = 0x25;
  abStack_b0[3] = 0;
  abStack_b0[4] = 0;
  abStack_b0[5] = 0;
  abStack_b0[6] = 0;
  abStack_b0[7] = 0;
  uVar4 = FUN_fffffff00918aecc
                    (extraout_q0_05,param_2,param_3,param_4,param_5,param_6,plVar7,abStack_b0,
                     &uStack_a4,(byte *)0x0);
  return uVar4;
}

