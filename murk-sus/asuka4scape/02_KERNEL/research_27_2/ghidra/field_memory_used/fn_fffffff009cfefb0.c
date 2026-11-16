// FUN_fffffff009cfefb0 @ fffffff009cfefb0

/* WARNING: Removing unreachable block (ram,0xfffffff009cff3c8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cff534) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cff248) */

ulong FUN_fffffff009cfefb0
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  byte *pbVar1;
  undefined1 auVar2 [16];
  bool bVar3;
  uint uVar4;
  long *plVar5;
  byte *pbVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  long *extraout_x0;
  short *psVar10;
  long *plVar11;
  undefined1 extraout_q0 [16];
  undefined1 auVar12 [16];
  undefined4 uVar13;
  undefined1 auVar14 [12];
  undefined4 uVar15;
  undefined1 auVar16 [12];
  byte local_61;
  
  uVar15 = param_4._0_4_;
  auVar16 = param_4._4_12_;
  uVar13 = param_3._0_4_;
  auVar14 = param_3._4_12_;
  plVar5 = (long *)(**(code **)(*(long *)param_7[0x17] + 0x118))
                             ((long *)param_7[0x17],"usb-device-wait-resource");
  plVar5 = thunk_FUN_fffffff00a894f30(plVar5,*(long *)PTR_PTR_fffffff008089cf0);
  uVar7 = 0;
  if (plVar5 != (long *)0x0) {
    pbVar6 = (byte *)(**(code **)(*plVar5 + 0xd8))();
    local_61 = 0;
    uVar4 = thunk_FUN_fffffff00aa14b0c((byte *)"usb-device-skip-wait-resource",(uint *)&local_61,1);
    uVar7 = (ulong)uVar4;
    if ((local_61 & 1) == 0) {
      if (pbVar6 != (byte *)0x0) {
        lVar8 = (**(code **)(*plVar5 + 0xd8))(plVar5);
        uVar7 = (**(code **)(*plVar5 + 0xa0))(plVar5);
        if (pbVar6 < (byte *)(lVar8 + (uVar7 & 0xffffffff))) {
          do {
            if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
              if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
                 (bVar3 = thunk_FUN_fffffff00a394140(), !bVar3)) {
                psVar10 = *(short **)PTR_DAT_fffffff008089cb8;
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                auVar12 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                thunk_FUN_fffffff00a8df19c
                          (auVar12,param_2,uVar13,uVar15,param_5,param_6,&MACH_HEADER,psVar10,0,
                           (byte *)"%s@%s: %s::%s: start waiting for resource %s\n");
              }
              else {
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                (**(code **)(*param_7 + 0x218))(param_7,0);
                thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: start waiting for resource %s\n")
                ;
              }
            }
            plVar9 = thunk_FUN_fffffff00a9336e8(pbVar6,(long *)0x0);
            if (plVar9 == (long *)0x0) {
              plVar11 = (long *)0x0;
            }
            else {
              auVar12._4_12_ = auVar14;
              auVar12._0_4_ = uVar13;
              auVar2._4_12_ = auVar16;
              auVar2._0_4_ = uVar15;
              thunk_FUN_fffffff00a932ce0
                        (extraout_q0,param_2,auVar12,auVar2,param_5,param_6,plVar9,10000000000);
              plVar11 = extraout_x0;
            }
            if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
              if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
                 (bVar3 = thunk_FUN_fffffff00a394140(), !bVar3)) {
                psVar10 = *(short **)PTR_DAT_fffffff008089cb8;
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                auVar12 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                thunk_FUN_fffffff00a8df19c
                          (auVar12,param_2,uVar13,uVar15,param_5,param_6,&MACH_HEADER,psVar10,0,
                           (byte *)"%s@%s: %s::%s: waiting for resource %s, result %s\n");
              }
              else {
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                (**(code **)(*param_7 + 0x218))(param_7,0);
                thunk_FUN_fffffff00a9029a0
                          ((byte *)"%s@%s: %s::%s: waiting for resource %s, result %s\n");
              }
            }
            if (plVar9 != (long *)0x0) {
              (**(code **)(*plVar9 + 0x28))(plVar9);
            }
            if (plVar11 != (long *)0x0) {
              (**(code **)(*plVar11 + 0x28))(plVar11);
            }
            lVar8 = thunk_FUN_fffffff00a1d1550((ulong)pbVar6);
            lVar8 = lVar8 + 1;
            pbVar1 = pbVar6 + lVar8;
            pbVar6 = pbVar6 + (int)lVar8;
            if (lVar8 != (int)lVar8) {
              pbVar6 = (byte *)((ulong)pbVar1 & 0xffffffffffff | 0x2bad000000000000);
            }
            lVar8 = (**(code **)(*plVar5 + 0xd8))(plVar5);
            uVar7 = (**(code **)(*plVar5 + 0xa0))(plVar5);
          } while (pbVar6 < (byte *)(lVar8 + (uVar7 & 0xffffffff)));
        }
      }
    }
    else if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar3 = thunk_FUN_fffffff00a394140(), !bVar3)) {
        psVar10 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar12 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        uVar7 = thunk_FUN_fffffff00a8df19c
                          (auVar12,param_2,uVar13,uVar15,param_5,param_6,&MACH_HEADER,psVar10,0,
                           (byte *)"%s@%s: %s::%s: skipping wait for resource %s\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        uVar7 = thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: skipping wait for resource %s\n")
        ;
      }
    }
  }
  return uVar7;
}

