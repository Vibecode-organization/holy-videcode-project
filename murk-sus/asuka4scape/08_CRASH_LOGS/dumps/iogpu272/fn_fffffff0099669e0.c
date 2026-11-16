// FUN_fffffff0099669e0 @ fffffff0099669e0 size=2384

undefined4
FUN_fffffff0099669e0(long param_1,uint *param_2,ulong *param_3,ulong param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long *plVar6;
  undefined8 uVar7;
  long *plVar8;
  ulong uVar9;
  undefined8 uVar10;
  long *plVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  long lVar15;
  undefined8 uVar16;
  uint uVar17;
  undefined4 uVar18;
  uint uVar19;
  long local_70;
  long local_68;
  
  uVar18 = 0xe00002c2;
  if (param_4 < 0x58) {
    return 0xe00002c2;
  }
  lVar5 = *(long *)(param_1 + 0x48);
  if ((ulong)*param_5 < (ulong)*(uint *)(lVar5 + 0x234) + 0x58) {
    return 0xe00002c2;
  }
  uVar3 = *param_2;
  if ((uVar3 & 0xf) == 0) {
    if ((-*(long *)PTR_DAT_fffffff007ff2838 &
        (*(long *)(lVar5 + 0x118) * (ulong)*(uint *)(lVar5 + 0x2ec)) / 100) <
        *(ulong *)(param_2 + 0x12)) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s failed: try to wire down too much memory : %llu > %llu\n");
      return 0xe00002c2;
    }
    if ((uVar3 >> 7 & 1) != 0) goto LAB_fffffff009966a4c;
    uVar17 = param_2[1];
    if (9 < (uVar17 >> 8 | uVar17 << 0x18)) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s invalid cache_mode 0x%x\n");
      return 0xe00002c2;
    }
  }
  else {
LAB_fffffff009966a4c:
    uVar17 = 0;
  }
  if (uVar3 == 0x82) {
    plVar6 = (long *)FUN_fffffff009975b40(lVar5,param_2[0xe],*(undefined8 *)(param_1 + 0x50));
    if (plVar6 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s invalid IOSurface ID 0x%x\n");
      return 0xe00002c2;
    }
    uVar3 = thunk_EXT_FUN_8011000002c1e3bc();
    if ((uVar3 != 0) && (uVar3 <= param_2[0xf])) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s invalid plane %d in IOSurface with %d planes\n");
      goto LAB_fffffff009966ef4;
    }
  }
  else {
    plVar6 = (long *)0x0;
  }
  if ((*(byte *)((long)param_2 + 0x15) >> 3 & 1) != 0) {
    uVar3 = param_2[0x14];
    if (uVar3 != 0) goto LAB_fffffff009966b48;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s suballocation flag is set without parent resource id\n");
    goto LAB_fffffff009966ef0;
  }
  uVar3 = 0;
LAB_fffffff009966b48:
  uVar19 = *(uint *)(*(long *)(param_1 + 0x10) + 0x30);
  if (*(uint *)(*(long *)(param_1 + 0x48) + 0x24c) <= uVar19) {
    uVar1 = *(uint *)(*(long *)(param_1 + 0x48) + 0x250);
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = uVar19 / uVar1;
    }
    if (uVar19 == uVar2 * uVar1) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: PID %d may be leaking IOGPUResource (count=%d)\n");
    }
  }
  uVar19 = param_2[0xc];
  uVar1 = param_2[0xd];
  if (uVar19 < 2) {
    uVar19 = 1;
  }
  local_68 = *(long *)(param_2 + 8);
  local_70 = *(long *)(param_2 + 10);
  uVar2 = *param_2;
  if ((int)uVar2 < 0x40) {
    if (uVar2 != 0) {
      if (uVar2 == 3) {
        plVar8 = (long *)FUN_fffffff0099544e0(*(undefined8 *)(param_1 + 0x48),param_1,param_2[0xe]);
        goto LAB_fffffff009966d2c;
      }
LAB_fffffff009966ebc:
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Bogus resType = %d\n");
      param_3[1] = 0;
      param_3[2] = 0;
      goto LAB_fffffff009966eec;
    }
    if (uVar3 != 0) {
      uVar7 = *(undefined8 *)(param_1 + 0x48);
      uVar14 = *(undefined8 *)(param_2 + 6);
      uVar10 = *(undefined8 *)(param_2 + 0x10);
      uVar12 = *(undefined8 *)(param_2 + 0x12);
      uVar16 = *(undefined8 *)(param_2 + 0xe);
      uVar13 = 0;
LAB_fffffff009966d5c:
      plVar8 = (long *)FUN_fffffff00995357c
                                 (uVar7,param_1,uVar13,uVar14,uVar12,uVar16,uVar10,param_3 + 1,uVar3
                                 );
      goto LAB_fffffff009966d64;
    }
    if ((param_2[5] >> 0xd & 1) == 0) {
      lVar15 = *(long *)(param_2 + 6);
      lVar5 = *(long *)(param_1 + 0x48);
      if (lVar15 != 0) goto LAB_fffffff00996703c;
      uVar17 = uVar17 | 0x10063;
    }
    else {
      lVar5 = *(long *)(param_1 + 0x48);
      lVar15 = *(long *)(param_2 + 6);
LAB_fffffff00996703c:
      uVar17 = 99;
      if ((*(byte *)(lVar5 + 0x238) & 0x20) != 0) {
        uVar17 = 0x763;
      }
    }
    plVar8 = (long *)FUN_fffffff009953054
                               (lVar5,param_1,0,lVar15,*(undefined8 *)(param_2 + 0x12),
                                uVar17 | (param_2[5] & 0x40000) << 5,param_3 + 1,param_2,&local_68,
                                &local_70);
    if ((*(byte *)((long)param_2 + 0x16) & 1) == 0) goto LAB_fffffff009966d64;
    uVar18 = 0xe00002be;
    if (plVar8 != (long *)0x0) {
      lVar5 = thunk_EXT_FUN_8011000003890f30(plVar8[5],DAT_fffffff007fefaf0);
      if (lVar5 != 0) {
        uVar10 = FUN_fffffff009981d00();
        iVar4 = thunk_EXT_FUN_8011000003977b2c(uVar10,*(undefined8 *)(param_1 + 0x50),4,1);
        if (iVar4 != 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s: setOwnership with no footprint failed: %08x\n");
          param_3[1] = 0;
          param_3[2] = 0;
          (**(code **)(*plVar8 + 0xb0))(plVar8,param_1);
          goto LAB_fffffff009966ef0;
        }
      }
      goto LAB_fffffff009966d68;
    }
  }
  else {
    if (uVar2 == 0x40) {
      plVar8 = (long *)FUN_fffffff0099547ec(*(undefined8 *)(param_1 + 0x48),param_1,param_2);
      param_3[1] = 0;
      if (plVar8 == (long *)0x0) goto LAB_fffffff009966eec;
      uVar19 = param_2[0x14];
      uVar9 = 0;
      if ((long *)plVar8[0x12] != (long *)0x0) {
        uVar9 = (**(code **)(*(long *)plVar8[0x12] + 0x78))();
      }
      param_3[3] = uVar9;
      goto LAB_fffffff009966d68;
    }
    if (uVar2 == 0x82) {
      plVar8 = (long *)FUN_fffffff009953c54
                                 (*(undefined8 *)(param_1 + 0x48),param_1,plVar6,param_2[0xf],
                                  param_2[0x10]);
LAB_fffffff009966d2c:
      param_3[1] = 0;
    }
    else {
      if (uVar2 != 0x80) goto LAB_fffffff009966ebc;
      if (uVar3 != 0) {
        uVar7 = *(undefined8 *)(param_1 + 0x48);
        uVar14 = *(undefined8 *)(param_2 + 6);
        uVar10 = *(undefined8 *)(param_2 + 0x10);
        uVar12 = *(undefined8 *)(param_2 + 0x12);
        uVar16 = *(undefined8 *)(param_2 + 0xe);
        uVar13 = 0x80;
        goto LAB_fffffff009966d5c;
      }
      if ((*(byte *)((long)param_2 + 0x16) >> 5 & 1) == 0) {
        plVar8 = (long *)FUN_fffffff009952cd4
                                   (*(undefined8 *)(param_1 + 0x48),param_1,0x80,
                                    *(undefined8 *)(param_2 + 0x12),*(undefined8 *)(param_2 + 0xe),
                                    *(undefined8 *)(param_2 + 0x10),param_3 + 1);
      }
      else {
        plVar8 = (long *)FUN_fffffff009953fd0
                                   (*(undefined8 *)(param_1 + 0x48),param_1,param_3 + 1,param_2);
      }
    }
LAB_fffffff009966d64:
    if (plVar8 == (long *)0x0) {
LAB_fffffff009966eec:
      uVar18 = 0xe00002be;
    }
    else {
LAB_fffffff009966d68:
      uVar9 = (**(code **)(*plVar8 + 0x88))(plVar8,param_1,param_2,param_4);
      if ((uVar9 & 1) == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: initialize failed\n");
LAB_fffffff009966e8c:
        uVar18 = 0xe00002bc;
      }
      else {
        uVar9 = FUN_fffffff009952c9c(plVar8);
        param_3[5] = uVar9;
        if (((((byte)param_2[5] >> 6 & 1) != 0) && (plVar8[5] != 0)) &&
           ((*(byte *)((long)plVar8 + 0x11) >> 5 & 1) != 0)) {
          if (plVar8[0x12] == 0) {
            lVar5 = thunk_EXT_FUN_8011000003890f30(plVar8[5],DAT_fffffff007fefaf0);
            if (lVar5 != 0) {
              uVar10 = FUN_fffffff009981d00();
              plVar11 = (long *)thunk_EXT_FUN_801100000396cb64
                                          (uVar10,*(undefined8 *)PTR_DAT_fffffff007ff2830,0,1,0,0);
              if (plVar11 != (long *)0x0) {
                lVar5 = (**(code **)(*plVar11 + 0x78))();
                if (lVar5 != 0) {
                  thunk_EXT_FUN_8011000003a61cc0(lVar5,plVar8[0xf]);
                }
                (**(code **)(*plVar11 + 0x28))();
              }
            }
          }
          else {
            *(uint *)(param_3 + 4) = (uint)param_3[4] | 1;
          }
        }
        uVar10 = (**(code **)(*plVar8 + 0x90))(plVar8,param_2,param_4);
        if ((local_68 == 0) || (local_70 == 0)) {
          if (((uint)uVar10 >> 2 & 1) != 0) {
            iVar4 = (**(code **)(*plVar8 + 0xc0))(plVar8,uVar10,uVar19);
            if (iVar4 == 0) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                         "%s: failed to create mapping.\n");
              goto LAB_fffffff009966e8c;
            }
            goto LAB_fffffff009966f5c;
          }
        }
        else {
          iVar4 = (**(code **)(*plVar8 + 200))(plVar8);
          if (iVar4 == 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s: failed to create mapping at address 0x%llx with length 0x%llx.\n");
            goto LAB_fffffff009966e8c;
          }
LAB_fffffff009966f5c:
          if (plVar8[4] == 0) {
            *param_3 = 0;
            uVar9 = 0;
          }
          else {
            uVar9 = FUN_fffffff009967330(plVar8);
            *param_3 = uVar9 | (ulong)uVar1 << 0x20;
            lVar5 = (**(code **)(*(long *)plVar8[4] + 0xa8))();
            if ((*(byte *)(plVar8 + 2) & 0x7f) == 0) {
              uVar9 = plVar8[9];
            }
            else if (*(byte *)(plVar8 + 2) == 0x82) {
              uVar9 = (ulong)*(uint *)((long)plVar8 + 0x4c);
            }
            else {
              uVar9 = 0;
            }
            uVar9 = lVar5 - uVar9;
          }
          param_3[10] = uVar9;
        }
        FUN_fffffff009954bc0(plVar8,param_3 + 2);
        if (*(int *)(*(long *)(param_1 + 0x48) + 0x234) != 0) {
          (**(code **)(*plVar8 + 0xa8))(plVar8,param_3 + 0xb);
        }
        if ((((*(byte *)((long)param_2 + 0x16) >> 1 & 1) != 0) && (lVar5 = plVar8[4], lVar5 != 0))
           && (iVar4 = FUN_fffffff00997f3fc(lVar5), iVar4 == 0)) {
          FUN_fffffff00997f408(lVar5);
        }
        iVar4 = thunk_FUN_fffffff009944798(*(undefined8 *)(param_1 + 0x10),plVar8);
        *(int *)(plVar8 + 0x11) = iVar4;
        if (iVar4 != 0) {
          *(int *)((long)param_3 + 0x24) = iVar4;
          uVar9 = FUN_fffffff009953a34(plVar8);
          param_3[9] = uVar9;
          param_3[6] = plVar8[0xe];
          lVar5 = FUN_fffffff00995598c(plVar8);
          if ((lVar5 == 0) || (lVar5 = *(long *)(lVar5 + 0x28), lVar5 == 0)) {
            param_3[7] = 0;
          }
          else {
            param_3[7] = *(ulong *)(lVar5 + 0x70);
            lVar5 = thunk_EXT_FUN_8011000003890f30(lVar5,DAT_fffffff007fefaf0);
            if (lVar5 != 0) {
              plVar11 = (long *)FUN_fffffff009981d0c();
              uVar10 = thunk_EXT_FUN_8011000003977aa8();
              if (DAT_fffffff00af227e8 != 0) {
                lVar5 = plVar8[0xe];
                uVar12 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x48));
                thunk_EXT_FUN_80110000036da494(0x85180118,uVar10,lVar5,uVar12,0,0);
              }
              if (plVar11 != (long *)0x0) {
                (**(code **)(*plVar11 + 0x28))(plVar11);
              }
            }
          }
          param_3[8] = 0;
          (**(code **)(*plVar8 + 0x28))(plVar8);
          uVar18 = 0;
          goto LAB_fffffff009966ef0;
        }
        uVar18 = 0xe00002bd;
      }
      (**(code **)(*plVar8 + 0xb0))(plVar8,param_1);
      param_3[2] = 0;
      param_3[1] = 0;
      param_3[8] = 0;
      param_3[7] = 0;
    }
  }
LAB_fffffff009966ef0:
  if (plVar6 == (long *)0x0) {
    return uVar18;
  }
LAB_fffffff009966ef4:
  (**(code **)(*plVar6 + 0x28))(plVar6);
  return uVar18;
}

