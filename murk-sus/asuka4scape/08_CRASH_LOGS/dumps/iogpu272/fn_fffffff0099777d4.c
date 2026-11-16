// FUN_fffffff0099777d4 @ fffffff0099777d4 size=1948

void FUN_fffffff0099777d4(long *param_1,undefined4 *param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  long *plVar13;
  undefined4 uVar14;
  undefined8 *puVar15;
  code *UNRECOVERED_JUMPTABLE;
  int iVar16;
  undefined8 *puVar17;
  ulong unaff_x30;
  ulong local_b0;
  ulong local_70;
  
  *(int *)((long)param_1 + 0x544) = *(int *)((long)param_1 + 0x544) + 1;
  plVar4 = (long *)FUN_fffffff009965b58(param_1[0x91],*param_2);
  if (param_2[2] == 0) {
    plVar5 = (long *)0x0;
  }
  else {
    plVar5 = (long *)FUN_fffffff009965b58(param_1[0x91]);
  }
  plVar6 = (long *)FUN_fffffff009965b58(param_1[0x91],param_2[1]);
  if ((plVar6 == (long *)0x0 || plVar4 == (long *)0x0) || (2 < *(uint *)((long)param_1 + 0x544))) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: invalid segment shmem\n");
    *(undefined4 *)(param_1 + 0xa4) = 9;
    if (plVar4 != (long *)0x0) {
LAB_fffffff0099779d0:
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    if (plVar6 != (long *)0x0) {
      (**(code **)(*plVar6 + 0x28))(plVar6);
    }
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
    *(int *)((long)param_1 + 0x544) = *(int *)((long)param_1 + 0x544) + -1;
  }
  else {
    lVar7 = (**(code **)(*plVar4 + 0x80))(plVar4);
    if (lVar7 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: kernelCommandBufferShmem (PID=%d) failed to map into kernel\n");
      *(undefined4 *)(param_1 + 0xa4) = 8;
      *(int *)((long)param_1 + 0x544) = *(int *)((long)param_1 + 0x544) + -1;
      (**(code **)(*plVar4 + 0x28))(plVar4);
      UNRECOVERED_JUMPTABLE = *(code **)(*plVar6 + 0x28);
    }
    else {
      uVar8 = (**(code **)(*plVar4 + 0x98))(plVar4);
      uVar9 = (**(code **)(*plVar6 + 0x98))(plVar6);
      uVar10 = (**(code **)(*plVar6 + 0x80))(plVar6);
      if (uVar10 != 0) {
        puVar15 = (undefined8 *)(uVar10 + uVar9);
        if (((uVar10 ^ (ulong)puVar15) & 0xffc0000000000000) != 0) {
          puVar15 = (undefined8 *)((ulong)puVar15 & 0xffffffffffff | 0xc8a2000000000000);
        }
        if (plVar5 == (long *)0x0) {
          local_b0 = 0;
          local_70 = 0;
        }
        else {
          local_b0 = (**(code **)(*plVar5 + 0x80))(plVar5);
          if (local_b0 == 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s: sidebandBufferShmem (PID=%d) failed to map into kernel\n");
            (**(code **)(*plVar4 + 0x88))(plVar4);
            (**(code **)(*plVar6 + 0x88))(plVar6);
            *(undefined4 *)(param_1 + 0xa4) = 8;
            *(int *)((long)param_1 + 0x544) = *(int *)((long)param_1 + 0x544) + -1;
            (**(code **)(*plVar4 + 0x28))(plVar4);
            (**(code **)(*plVar6 + 0x28))(plVar6);
            puVar15 = (undefined8 *)(*plVar5 + 0x28);
            UNRECOVERED_JUMPTABLE = (code *)*puVar15;
            goto LAB_fffffff009977b74;
          }
          lVar11 = (**(code **)(*plVar5 + 0x98))(plVar5);
          local_70 = local_b0 + (long)(int)lVar11;
          if (lVar11 != (int)lVar11) {
            local_70 = local_b0 + lVar11 & 0xffffffffffff | 0x2bad000000000000;
          }
        }
        lVar11 = uVar9 - 0x10;
        if ((0xf < uVar9) && (iVar16 = *(int *)(uVar10 + 8), 0 < iVar16)) {
          puVar17 = (undefined8 *)(uVar10 + 0x10);
          do {
            if ((int)param_1[0xa4] != 0) break;
            if (lVar11 < 0x20) {
LAB_fffffff009977f04:
              uVar14 = 10;
LAB_fffffff009977f08:
              *(undefined4 *)(param_1 + 0xa4) = uVar14;
              break;
            }
            if (DAT_fffffff00af227e8 != 0) {
              lVar12 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
              param_1[0x82] = lVar12;
              if (DAT_fffffff00af227e8 != 0) {
                thunk_EXT_FUN_80110000036da494
                          (0x85180001,param_1[0xaa],param_1[0x83],lVar12,*puVar17,0);
              }
            }
            uVar3 = *(uint *)((long)puVar17 + 0x1c);
            if (((uVar3 >> 0x1a != 0) ||
                (puVar1 = puVar17 + 4 + (ulong)uVar3 * 8,
                CARRY8((ulong)(puVar17 + 4),(ulong)uVar3 * 0x40))) ||
               (uVar9 = local_b0 + *(uint *)(puVar17 + 2),
               CARRY8(local_b0,(ulong)*(uint *)(puVar17 + 2)))) goto LAB_fffffff009977f04;
            uVar3 = *(uint *)(puVar17 + 1);
            uVar2 = *(uint *)((long)puVar17 + 0xc);
            if (((uVar8 < uVar2) || (uVar2 < uVar3)) || ((puVar15 < puVar1 || (local_70 < uVar9))))
            {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                         "%s: kernelCommandStart(%u) or kernelCommandEnd(%u) exceeds kernelCommandDataSize(%lu)\n"
                        );
              goto LAB_fffffff009977f04;
            }
            FUN_fffffff009965604(param_1[0x91]);
            plVar13 = (long *)(**(code **)(*param_1 + 0xc0))(param_1,param_1[0x91],puVar17,plVar6);
            FUN_fffffff009965610(param_1[0x91]);
            if (plVar13 == (long *)0x0) {
              uVar14 = 9;
              goto LAB_fffffff009977f08;
            }
            if (DAT_fffffff00af227e8 != 0) {
              thunk_EXT_FUN_80110000036da494
                        (0x85180069,param_1[0xaa],param_1[0x83],param_1[0x82],*puVar17,0);
            }
            (**(code **)(*param_1 + 0x90))
                      (param_1,plVar13,lVar7 + (ulong)uVar3,lVar7 + (ulong)uVar2,uVar9,local_70,
                       param_2);
            if (DAT_fffffff00af227e8 != 0) {
              thunk_EXT_FUN_80110000036da494
                        (0x8518006a,param_1[0xaa],param_1[0x83],param_1[0x82],
                         (long)(int)param_1[0x92],0);
            }
            (**(code **)(*param_1 + 0x108))(param_1,plVar13);
            (**(code **)(*plVar13 + 0x28))(plVar13);
            if (DAT_fffffff00af227e8 != 0) {
              thunk_EXT_FUN_80110000036da494
                        (0x85180002,param_1[0xaa],param_1[0x83],param_1[0x82],
                         (long)(int)param_1[0x92],0);
            }
            lVar11 = (long)puVar17 + (lVar11 - (long)puVar1);
            iVar16 = iVar16 + -1;
            puVar17 = puVar1;
          } while (iVar16 != 0);
        }
        (**(code **)(*plVar6 + 0x88))(plVar6);
        (**(code **)(*plVar4 + 0x88))(plVar4);
        if (plVar5 != (long *)0x0) {
          (**(code **)(*plVar5 + 0x88))(plVar5);
        }
        goto LAB_fffffff0099779d0;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: segmentListShmem (PID=%d) failed to map into kernel\n");
      (**(code **)(*plVar4 + 0x88))(plVar4);
      *(undefined4 *)(param_1 + 0xa4) = 8;
      *(int *)((long)param_1 + 0x544) = *(int *)((long)param_1 + 0x544) + -1;
      (**(code **)(*plVar4 + 0x28))(plVar4);
      UNRECOVERED_JUMPTABLE = *(code **)(*plVar6 + 0x28);
    }
    (*UNRECOVERED_JUMPTABLE)(plVar6);
    if (plVar5 != (long *)0x0) {
      puVar15 = (undefined8 *)(*plVar5 + 0x28);
      UNRECOVERED_JUMPTABLE = (code *)*puVar15;
LAB_fffffff009977b74:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff009977bac);
        (*UNRECOVERED_JUMPTABLE)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff009977bb4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(plVar5,puVar15);
      return;
    }
  }
  return;
}

