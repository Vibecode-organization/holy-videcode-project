// FUN_fffffff0099799a8 @ fffffff0099799a8 size=1628

void FUN_fffffff0099799a8(long *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  bool bVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  ulong uVar11;
  long *plVar12;
  long lVar13;
  long lVar14;
  undefined8 uVar15;
  uint uVar16;
  int iVar17;
  long lVar18;
  long *plVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  ulong unaff_x30;
  ulong local_98;
  uint local_74;
  
  plVar8 = (long *)FUN_fffffff009965b58(param_1[0x91],*param_2);
  if (param_2[2] == 0) {
    plVar9 = (long *)0x0;
  }
  else {
    plVar9 = (long *)FUN_fffffff009965b58(param_1[0x91]);
  }
  plVar10 = (long *)FUN_fffffff009965b58(param_1[0x91],param_2[1]);
  if (plVar8 == (long *)0x0 || plVar10 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: invalid segment shmem\n");
    *(undefined4 *)(param_1 + 0xa4) = 9;
    FUN_fffffff00997a004(param_1);
    if (plVar8 != (long *)0x0) {
LAB_fffffff009979f38:
      (**(code **)(*plVar8 + 0x28))(plVar8);
    }
    if (plVar9 != (long *)0x0) {
      (**(code **)(*plVar9 + 0x28))(plVar9);
    }
    plVar9 = plVar10;
    if (plVar10 == (long *)0x0) {
      return;
    }
  }
  else {
    FUN_fffffff009952120(plVar8);
    FUN_fffffff009952120(plVar10);
    if (plVar9 != (long *)0x0) {
      FUN_fffffff009952120(plVar9);
    }
    uVar11 = (**(code **)(*plVar10 + 0xa8))(plVar10);
    if ((long)uVar11 < 0) {
      *(undefined4 *)(param_1 + 0xa4) = 9;
      FUN_fffffff00995212c(plVar10);
      (**(code **)(*plVar10 + 0x28))(plVar10);
      FUN_fffffff00995212c(plVar8);
      pcVar6 = *(code **)(*plVar8 + 0x28);
    }
    else {
      plVar12 = (long *)(**(code **)(*plVar10 + 0xa0))(plVar10);
      lVar13 = (**(code **)(*plVar8 + 0x80))(plVar8);
      if (plVar9 == (long *)0x0) {
        bVar7 = false;
      }
      else {
        lVar14 = (**(code **)(*plVar9 + 0x80))(plVar9);
        bVar7 = lVar14 == 0;
      }
      if ((plVar12 != (long *)0x0 && lVar13 != 0) && !bVar7) {
        lVar14 = *plVar12;
        param_1[0x83] = lVar14;
        uVar3 = *(uint *)((long)param_1 + 0x44c);
        if (uVar3 == 1) {
          uVar16 = (int)param_1[0x8a] << 8;
        }
        else {
          uVar16 = 0x200;
        }
        iVar4 = *(int *)((long)param_1 + 0x454);
        lVar21 = param_1[0xaa];
        uVar15 = thunk_EXT_FUN_801100000390ebc0(param_1[0xa6]);
        thunk_EXT_FUN_80110000036da494(0x85090001,lVar21,lVar14,uVar15,0,0);
        if (0xf < uVar11) {
          lVar14 = 0;
          plVar19 = plVar12;
          do {
            if ((*(byte *)(param_1 + 0xb9) & 1) != 0) {
              *(undefined4 *)(param_1 + 0xa4) = 10;
              break;
            }
            if (lVar14 != (long)plVar19 - (long)plVar12) {
LAB_fffffff009979ff8:
              FUN_fffffff00998406c();
LAB_fffffff009979ffc:
              FUN_fffffff0099840fc();
LAB_fffffff00997a000:
              lVar13 = FUN_fffffff00998409c();
              lVar14 = *(long *)(lVar13 + 0x430);
              uVar11 = (ulong)*(uint *)(lVar14 + 0x148);
              if (*(uint *)(lVar14 + 0x148) != 0) {
                lVar21 = 0;
                do {
                  (**(code **)(**(long **)(lVar14 + 8 + lVar21 * 8) + 0x28))();
                  lVar14 = *(long *)(lVar13 + 0x430);
                  *(undefined8 *)(lVar14 + 8 + lVar21 * 8) = 0;
                  lVar21 = lVar21 + 1;
                  uVar11 = uVar11 - 1;
                } while (uVar11 != 0);
              }
              *(undefined4 *)(lVar14 + 0x148) = 0;
              *(undefined1 *)(lVar14 + 0x2a0) = 0;
              return;
            }
            uVar5 = *(uint *)((long)plVar19 + 0xc);
            local_74 = uVar5 >> 0x1f;
            uVar1 = uVar5 & 0x3fffffff;
            if ((uVar5 & 0x40000000) != 0) {
              uVar1 = 0;
            }
            uVar20 = (ulong)uVar1;
            uVar5 = uVar5 & 0x3fffffff & (int)(uVar5 << 1) >> 0x1f;
            if (uVar5 == 2) {
              uVar11 = 0;
            }
            else if (uVar5 == 1) {
              uVar1 = *(uint *)(plVar19 + 1);
              uVar22 = (ulong)uVar1;
              uVar20 = uVar22 * 8 + 0x10;
              bVar7 = uVar20 <= uVar11;
              uVar11 = uVar11 - uVar20;
              if (bVar7) {
                lVar21 = (**(code **)(*plVar8 + 0x98))(plVar8);
                if (uVar1 != 0) {
                  lVar18 = 0;
                  do {
                    iVar17 = (int)(lVar18 * 8);
                    puVar2 = (uint *)((long)plVar19 + (long)iVar17 + 0x10);
                    if (lVar18 * 8 - (long)iVar17 != 0) {
                      puVar2 = (uint *)((ulong)(plVar19 + lVar18 + 2) & 0xffffffffffff |
                                       0x2bad000000000000);
                    }
                    uVar1 = puVar2[1];
                    if ((long)(ulong)uVar1 <= lVar21 && *puVar2 <= uVar1) {
                      (**(code **)(*param_1 + 200))
                                (param_1,lVar13 + (ulong)*puVar2,lVar13 + (ulong)uVar1);
                    }
                    lVar18 = lVar18 + 1;
                    uVar22 = uVar22 - 1;
                  } while (uVar22 != 0);
                }
                goto LAB_fffffff009979e14;
              }
              uVar11 = 0;
              *(undefined4 *)(param_1 + 0xa4) = 10;
            }
            else if (uVar5 == 0) {
              if (uVar1 == 0) {
                if (lVar14 != 0) goto LAB_fffffff009979db4;
                uVar20 = 0;
                local_98 = 0;
                local_74 = 1;
                lVar21 = 0;
              }
              else if ((uVar1 < 0x10) ||
                      (lVar21 = lVar14, local_98 = uVar11, (long)uVar11 < (long)uVar20))
              goto LAB_fffffff009979db4;
              FUN_fffffff009952018(plVar10,lVar21,uVar11);
              (**(code **)(*param_1 + 0xa8))(param_1,param_2);
              uVar11 = local_98 - uVar20;
LAB_fffffff009979e14:
              lVar14 = lVar14 + uVar20;
              plVar19 = (long *)(uVar20 + (long)plVar19);
            }
            else {
LAB_fffffff009979db4:
              uVar11 = 0;
              *(undefined4 *)(param_1 + 0xa4) = 10;
            }
            if ((int)plVar10[7] < 1) goto LAB_fffffff009979ffc;
            if ((int)plVar8[7] < 1) {
              FUN_fffffff0099840cc();
              goto LAB_fffffff009979ff8;
            }
            if ((plVar9 != (long *)0x0) && ((int)plVar9[7] < 1)) goto LAB_fffffff00997a000;
            uVar1 = 0;
            if (0xf < uVar11) {
              uVar1 = local_74 ^ 1;
            }
          } while (uVar1 != 0);
        }
        FUN_fffffff009952024(plVar10);
        (**(code **)(*plVar10 + 0x88))(plVar10);
        if (plVar9 == (long *)0x0) {
          (**(code **)(*plVar8 + 0x88))(plVar8);
          plVar12 = plVar10;
        }
        else {
          (**(code **)(*plVar9 + 0x88))(plVar9);
          (**(code **)(*plVar8 + 0x88))(plVar8);
          FUN_fffffff00995212c(plVar10);
          plVar12 = plVar9;
        }
        FUN_fffffff00995212c(plVar12);
        FUN_fffffff00995212c(plVar8);
        thunk_EXT_FUN_80110000036da494
                  (0x85090002,param_1[0xaa],iVar4 << 0x10 | uVar16 | uVar3,(long)(int)param_1[0x92],
                   (int)param_1[0xa4],0);
        FUN_fffffff00997a004(param_1);
        goto LAB_fffffff009979f38;
      }
      *(undefined4 *)(param_1 + 0xa4) = 8;
      FUN_fffffff00995212c(plVar10);
      (**(code **)(*plVar10 + 0x28))(plVar10);
      FUN_fffffff00995212c(plVar8);
      pcVar6 = *(code **)(*plVar8 + 0x28);
    }
    (*pcVar6)(plVar8);
    if (plVar9 == (long *)0x0) {
      return;
    }
    FUN_fffffff00995212c(plVar9);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009979fd0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar9 + 0x28))(plVar9,(undefined8 *)(*plVar9 + 0x28));
    return;
  }
                    /* WARNING: Does not return */
  pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009979fc8);
  (*pcVar6)();
}

