// FUN_fffffff0081ce930 @ fffffff0081ce930 size=3088

/* WARNING: Removing unreachable block (ram,0xfffffff0081ceca4) */

void FUN_fffffff0081ce930(long *param_1)

{
  uint *puVar1;
  undefined *puVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  long *plVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  uint *puVar12;
  long lVar13;
  long lVar14;
  long *local_b0;
  undefined8 local_a8;
  long **pplStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  long *local_88;
  long *plStack_80;
  undefined8 local_78;
  long *local_70;
  long *plStack_68;
  undefined8 local_60;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff007ca61a0;
  iVar4 = FUN_fffffff0081aa30c();
  if (iVar4 != 0) {
    uVar5 = (**(code **)(*param_1 + 0x288))(param_1);
    puVar2 = PTR_DAT_fffffff007ca5f88;
    iVar4 = 1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f);
    plVar7 = (long *)thunk_EXT_FUN_8011000003962c64
                               (0x13,-iVar4 & ((-1 << (ulong)(uVar5 & 0x1f)) - iVar4 ^ 0xffffffffU),
                                (long)iVar4);
    if (plVar7 != (long *)0x0) {
      lVar8 = (**(code **)(*plVar7 + 0xe8))(plVar7,0);
      param_1[0x28d] = lVar8;
      if (lVar8 == 0) goto LAB_fffffff0081cf520;
      lVar8 = FUN_fffffff0081b6bf8(param_1,plVar7,0,8);
      param_1[0x28e] = lVar8;
      (**(code **)(*plVar7 + 0x28))(plVar7);
      if (lVar8 != 0) {
        uVar5 = *(uint *)puVar2;
        uVar6 = (**(code **)(*param_1 + 0x288))(param_1);
        if ((uint)(1 << (ulong)(uVar6 & 0x1f)) >> (ulong)(uVar5 & 0x1f) == 0) {
          uVar5 = *(uint *)puVar2;
          uVar6 = uVar5;
        }
        else {
          uVar5 = (**(code **)(*param_1 + 0x288))(param_1);
          uVar6 = *(uint *)puVar2;
        }
        iVar4 = 1 << (ulong)(uVar5 & 0x1f);
        plVar7 = (long *)thunk_EXT_FUN_8011000003962c64
                                   (0x13,iVar4 + 0xfffU & -iVar4,(long)(1 << (ulong)(uVar6 & 0x1f)))
        ;
        if (plVar7 != (long *)0x0) {
          lVar8 = (**(code **)(*plVar7 + 0xe8))(plVar7,0);
          param_1[0x293] = lVar8;
          if (lVar8 != 0) {
            lVar8 = FUN_fffffff0081b6bf8(param_1,plVar7,0,8);
            param_1[0x294] = lVar8;
            if (lVar8 != 0) {
              (**(code **)(*plVar7 + 0x28))(plVar7);
              uVar5 = *(uint *)puVar2;
              uVar6 = (**(code **)(*param_1 + 0x288))(param_1);
              if ((uint)(1 << (ulong)(uVar6 & 0x1f)) >> (ulong)(uVar5 & 0x1f) == 0) {
                uVar5 = *(uint *)puVar2;
                uVar6 = uVar5;
              }
              else {
                uVar5 = (**(code **)(*param_1 + 0x288))(param_1);
                uVar6 = *(uint *)puVar2;
              }
              iVar4 = 1 << (ulong)(uVar5 & 0x1f);
              plVar7 = (long *)thunk_EXT_FUN_8011000003962c64
                                         (0x13,iVar4 + 0x3fffU & -iVar4,
                                          (long)(1 << (ulong)(uVar6 & 0x1f)));
              if (plVar7 != (long *)0x0) {
                lVar8 = (**(code **)(*plVar7 + 0xe8))(plVar7,0);
                param_1[0x28f] = lVar8;
                (**(code **)(*plVar7 + 0x28))(plVar7);
                if ((lVar8 != 0) && (lVar8 = thunk_EXT_FUN_80110000038ff134(), lVar8 != 0)) {
                  param_1[0x29a] = lVar8;
                  local_88 = param_1 + 0x296;
                  plStack_80 = param_1 + 0x298;
                  local_78 = DAT_fffffff007113f50;
                  local_70 = param_1 + 0x297;
                  plStack_68 = param_1 + 0x299;
                  local_60 = DAT_fffffff007113f20;
                  local_a8 = 0;
                  uStack_90 = 0;
                  local_b0 = param_1 + 0x295;
                  pplStack_a0 = &local_88;
                  local_98 = 2;
                  iVar4 = (**(code **)(*param_1 + 0x7c0))(*param_1 + 0x7c0,param_1,&local_b0,0);
                  if (iVar4 != 0) {
                    lVar8 = 0;
                    uVar10 = 0;
                    lVar14 = param_1[0x50];
                    puVar1 = (uint *)(lVar14 + 0x678);
                    do {
                      uVar5 = puVar1[lVar8 * 0x10e + 1];
                      uVar11 = (ulong)uVar5;
                      if (1 < uVar5) {
                        puVar12 = puVar1 + lVar8 * 0x10e + 2;
                        if (*(long *)puVar12 == 0) {
                          uVar6 = 0;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 4) == 0) {
                          uVar6 = 1;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 6) == 0) {
                          uVar6 = 2;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 8) == 0) {
                          uVar6 = 3;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 10) == 0) {
                          uVar6 = 4;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0xc) == 0) {
                          uVar6 = 5;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0xe) == 0) {
                          uVar6 = 6;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x10) == 0) {
                          uVar6 = 7;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x12) == 0) {
                          uVar6 = 8;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x14) == 0) {
                          uVar6 = 9;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x16) == 0) {
                          uVar6 = 10;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x18) == 0) {
                          uVar6 = 0xb;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x1a) == 0) {
                          uVar6 = 0xc;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x1c) == 0) {
                          uVar6 = 0xd;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x1e) == 0) {
                          uVar6 = 0xe;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x20) == 0) {
                          uVar6 = 0xf;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x22) == 0) {
                          uVar6 = 0x10;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x24) == 0) {
                          uVar6 = 0x11;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x26) == 0) {
                          uVar6 = 0x12;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x28) == 0) {
                          uVar6 = 0x13;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x2a) == 0) {
                          uVar6 = 0x14;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x2c) == 0) {
                          uVar6 = 0x15;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x2e) == 0) {
                          uVar6 = 0x16;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x30) == 0) {
                          uVar6 = 0x17;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x32) == 0) {
                          uVar6 = 0x18;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x34) == 0) {
                          uVar6 = 0x19;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x36) == 0) {
                          uVar6 = 0x1a;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x38) == 0) {
                          uVar6 = 0x1b;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x3a) == 0) {
                          uVar6 = 0x1c;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x3c) == 0) {
                          uVar6 = 0x1d;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x3e) == 0) {
                          uVar6 = 0x1e;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x40) == 0) {
                          uVar6 = 0x1f;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x42) == 0) {
                          uVar6 = 0x20;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x44) == 0) {
                          uVar6 = 0x21;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x46) == 0) {
                          uVar6 = 0x22;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x48) == 0) {
                          uVar6 = 0x23;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x4a) == 0) {
                          uVar6 = 0x24;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x4c) == 0) {
                          uVar6 = 0x25;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x4e) == 0) {
                          uVar6 = 0x26;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x50) == 0) {
                          uVar6 = 0x27;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x52) == 0) {
                          uVar6 = 0x28;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x54) == 0) {
                          uVar6 = 0x29;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x56) == 0) {
                          uVar6 = 0x2a;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x58) == 0) {
                          uVar6 = 0x2b;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x5a) == 0) {
                          uVar6 = 0x2c;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x5c) == 0) {
                          uVar6 = 0x2d;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x5e) == 0) {
                          uVar6 = 0x2e;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x60) == 0) {
                          uVar6 = 0x2f;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x62) == 0) {
                          uVar6 = 0x30;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 100) == 0) {
                          uVar6 = 0x31;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x66) == 0) {
                          uVar6 = 0x32;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x68) == 0) {
                          uVar6 = 0x33;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x6a) == 0) {
                          uVar6 = 0x34;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x6c) == 0) {
                          uVar6 = 0x35;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x6e) == 0) {
                          uVar6 = 0x36;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x70) == 0) {
                          uVar6 = 0x37;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x72) == 0) {
                          uVar6 = 0x38;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x74) == 0) {
                          uVar6 = 0x39;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x76) == 0) {
                          uVar6 = 0x3a;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x78) == 0) {
                          uVar6 = 0x3b;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x7a) == 0) {
                          uVar6 = 0x3c;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x7c) == 0) {
                          uVar6 = 0x3d;
                        }
                        else if (*(long *)(puVar1 + lVar8 * 0x10e + 0x7e) == 0) {
                          uVar6 = 0x3e;
                        }
                        else {
                          uVar6 = 0x3f;
                          if (*(long *)(puVar1 + lVar8 * 0x10e + 0x80) != 0) {
                            uVar6 = 0x40;
                          }
                        }
                        if (uVar6 != uVar5) goto LAB_fffffff0081cf4e8;
                        if (uVar5 < 0x40) {
                          lVar13 = uVar11 - 0x40;
                          do {
                            iVar4 = (int)(uVar11 * 8);
                            plVar7 = (long *)((long)puVar12 + (long)iVar4);
                            if (uVar11 * 8 - (long)iVar4 != 0) {
                              plVar7 = (long *)((ulong)(puVar12 + uVar11 * 2) & 0xffffffffffff |
                                               0x2bad000000000000);
                            }
                            if (*plVar7 != 0) goto LAB_fffffff0081cf4e8;
                            uVar11 = uVar11 + 1;
                            bVar3 = lVar13 != -1;
                            lVar13 = lVar13 + 1;
                          } while (bVar3);
                        }
                      }
                      uVar10 = uVar10 + uVar5 * puVar1[lVar8 * 0x10e + 0x82];
                      lVar8 = lVar8 + 1;
                    } while (lVar8 != 0x3c);
                    if (uVar10 >> 0x16 < 5) {
                      if (((*(long *)(lVar14 + 0x680) != 0) && (*(int *)(lVar14 + 0x880) != 0)) &&
                         ((*puVar1 & 1) == 0)) {
                        lVar8 = FUN_fffffff0081b6a04
                                          (param_1,lVar14 + 0x680,*(int *)(lVar14 + 0x880),
                                           param_1 + 0x2da,*puVar1 >> 1 & 1,
                                           *(undefined4 *)(lVar14 + 0x67c),10);
                        param_1[0x29e] = lVar8;
                        if (lVar8 == 0) goto LAB_fffffff0081cf4e8;
                      }
                      if (((*(long *)(lVar14 + 0x898) == 0) || (*(int *)(lVar14 + 0xa98) == 0)) ||
                         (((*(byte *)(lVar14 + 0x890) & 1) != 0 ||
                          (iVar4 = FUN_fffffff00817dcf8(param_1[0x50],0,0), iVar4 != 0)))) {
                        if (((*(long *)(lVar14 + 0xab8) != 0) && (*(int *)(lVar14 + 0xcb8) != 0)) &&
                           ((*(uint *)(lVar14 + 0xab0) & 1) == 0)) {
                          lVar8 = FUN_fffffff0081b6a04
                                            (param_1,lVar14 + 0xab8,*(int *)(lVar14 + 0xcb8),
                                             (long)param_1 + 0x16d4,
                                             *(uint *)(lVar14 + 0xab0) >> 1 & 1,
                                             *(undefined4 *)(lVar14 + 0xab4),10);
                          param_1[0x29f] = lVar8;
                          if (lVar8 == 0) goto LAB_fffffff0081cf4e8;
                        }
                        if ((((*(long *)(lVar14 + 0xcd0) == 0) || (*(int *)(lVar14 + 0xed0) == 0))
                            || ((*(byte *)(lVar14 + 0xcc8) & 1) != 0)) ||
                           (iVar4 = FUN_fffffff00817dcf8(param_1[0x50],1,0), iVar4 != 0)) {
                          if (((*(long *)(lVar14 + 0xef0) != 0) && (*(int *)(lVar14 + 0x10f0) != 0))
                             && ((*(uint *)(lVar14 + 0xee8) & 1) == 0)) {
                            lVar8 = FUN_fffffff0081b6a04
                                              (param_1,lVar14 + 0xef0,*(int *)(lVar14 + 0x10f0),
                                               param_1 + 0x2db,*(uint *)(lVar14 + 0xee8) >> 1 & 1,
                                               *(undefined4 *)(lVar14 + 0xeec),10);
                            param_1[0x2a0] = lVar8;
                            if (lVar8 == 0) goto LAB_fffffff0081cf4e8;
                          }
                          if (((*(long *)(lVar14 + 0x1108) == 0) || (*(int *)(lVar14 + 0x1308) == 0)
                              ) || (((*(byte *)(lVar14 + 0x1100) & 1) != 0 ||
                                    (iVar4 = FUN_fffffff00817dcf8(param_1[0x50],2,0), iVar4 != 0))))
                          {
                            if (((*(long *)(lVar14 + 0x1328) != 0) &&
                                (*(int *)(lVar14 + 0x1528) != 0)) &&
                               ((*(uint *)(lVar14 + 0x1320) & 1) == 0)) {
                              lVar8 = FUN_fffffff0081b6a04
                                                (param_1,lVar14 + 0x1328,*(int *)(lVar14 + 0x1528),
                                                 (long)param_1 + 0x16dc,
                                                 *(uint *)(lVar14 + 0x1320) >> 1 & 1,
                                                 *(undefined4 *)(lVar14 + 0x1324),10);
                              param_1[0x2a1] = lVar8;
                              if (lVar8 == 0) goto LAB_fffffff0081cf4e8;
                            }
                            if (((*(long *)(lVar14 + 0x1540) == 0) ||
                                (*(int *)(lVar14 + 0x1740) == 0)) ||
                               (((*(byte *)(lVar14 + 0x1538) & 1) != 0 ||
                                (iVar4 = FUN_fffffff00817dcf8(param_1[0x50],3,0x100), iVar4 != 0))))
                            {
                              lVar14 = -0x38;
                              lVar8 = 4;
                              do {
                                puVar12 = puVar1 + lVar8 * 0x10e;
                                if (((*(long *)(puVar12 + 2) != 0) && (puVar12[0x82] != 0)) &&
                                   ((lVar14 != -0x13 && ((*puVar12 & 1) == 0)))) {
                                  lVar13 = FUN_fffffff0081b6a04
                                                     (param_1,puVar12 + 2,puVar12[0x82],
                                                      (long)(param_1 + 0x2da) + lVar8 * 4,
                                                      *puVar12 >> 1 & 1,puVar12[1],10);
                                  param_1[lVar8 + 0x29e] = lVar13;
                                  if (lVar13 == 0) goto LAB_fffffff0081cf4e8;
                                }
                                if ((((*(long *)(puVar12 + 0x88) != 0) && (puVar12[0x108] != 0)) &&
                                    ((puVar12[0x86] & 1) == 0)) &&
                                   (iVar4 = FUN_fffffff00817dcf8(param_1[0x50],(int)lVar14 + 0x3c,0)
                                   , iVar4 == 0)) goto LAB_fffffff0081cf4e8;
                                lVar8 = lVar8 + 1;
                                bVar3 = lVar14 != -1;
                                lVar14 = lVar14 + 1;
                              } while (bVar3);
                              lVar8 = param_1[0x50];
                              if ((*(long *)(lVar8 + 0x103a0) != 0) &&
                                 (*(int *)(lVar8 + 0x105a0) != 0)) {
                                lVar8 = FUN_fffffff0081b6a04
                                                  (param_1,lVar8 + 0x103a0,*(int *)(lVar8 + 0x105a0)
                                                   ,&local_88,*(uint *)(lVar8 + 0x10398) >> 1 & 1,
                                                   *(undefined4 *)(lVar8 + 0x1039c),8);
                                param_1[0x2f8] = lVar8;
                                lVar8 = param_1[0x50];
                              }
                              (**(code **)(param_1[0x1ed] + 0x20))
                                        (param_1 + 0x1ed,lVar8,0x40,"AGFICmdQueueSchedState",9,1,0,0
                                        );
                              iVar4 = (**(code **)(param_1[0x1ed] + 0x30))(param_1 + 0x1ed);
                              if (iVar4 != 0) {
                                (**(code **)(param_1[0x204] + 0x20))
                                          (param_1 + 0x204,param_1[0x50],0x40,
                                           "AGFIMeshShadersEmuMemoryState",9,1,0,0);
                                uVar10 = (**(code **)(param_1[0x204] + 0x30))(param_1 + 0x204);
                                uVar9 = 1;
                                if ((uVar10 & 1) != 0) goto LAB_fffffff0081cf4ec;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              goto LAB_fffffff0081cf4e8;
            }
          }
LAB_fffffff0081cf520:
          (**(code **)(*plVar7 + 0x28))(plVar7);
        }
      }
    }
  }
LAB_fffffff0081cf4e8:
  uVar9 = 0;
LAB_fffffff0081cf4ec:
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_58) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar9);
  return;
}

