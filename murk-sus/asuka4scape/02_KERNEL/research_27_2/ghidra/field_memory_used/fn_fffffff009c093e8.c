// FUN_fffffff009c093e8 @ fffffff009c093e8

/* WARNING: Removing unreachable block (ram,0xfffffff009c0a6ac) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0ad00) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c09a6c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c099d0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0a3f4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c09a2c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c09ab4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c09d10) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0afc0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0a510) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0a5a8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0a5e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0a56c) */

ulong FUN_fffffff009c093e8
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,undefined8 param_7,
                long param_8,ulong *param_9,ulong *param_10,long param_11)

{
  byte *pbVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined *puVar13;
  code *pcVar14;
  uint uVar15;
  int iVar16;
  undefined4 uVar17;
  uint uVar18;
  uint uVar19;
  undefined8 uVar20;
  long *plVar21;
  undefined8 uVar22;
  undefined **ppuVar23;
  long *plVar24;
  long *plVar25;
  char *pcVar26;
  undefined8 *puVar27;
  ulong uVar28;
  undefined **extraout_x0;
  ulong uVar29;
  undefined8 uVar30;
  ulong uVar31;
  undefined **ppuVar32;
  ulong *puVar33;
  uint uVar34;
  long lVar35;
  ulong uVar36;
  long lVar37;
  undefined8 *puVar38;
  uint *puVar39;
  ulong *puVar40;
  ulong *puVar41;
  undefined **ppuVar42;
  ulong *puVar43;
  ulong unaff_x30;
  undefined8 extraout_d0;
  undefined8 extraout_d0_05;
  undefined8 extraout_d0_06;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined *extraout_d0_02;
  undefined *extraout_d0_03;
  undefined *puVar44;
  undefined8 extraout_d0_04;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  ulong extraout_var_02;
  ulong extraout_var_03;
  undefined8 extraout_var_04;
  undefined1 auVar45 [16];
  undefined8 extraout_var_05;
  undefined8 extraout_var_06;
  undefined1 auVar46 [12];
  undefined4 uVar47;
  undefined1 auVar48 [12];
  undefined1 auVar49 [16];
  ulong *local_100;
  undefined *local_f0;
  ulong uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long local_70;
  
  puVar13 = PTR_DAT_fffffff008064c08;
  uVar47 = param_4._0_4_;
  auVar48 = param_4._4_12_;
  uVar17 = param_3._0_4_;
  auVar46 = param_3._4_12_;
  local_70 = *(long *)PTR_DAT_fffffff008064be8;
  uVar15 = (uint)param_7;
  if (*(uint *)(DAT_fffffff00af47df8 + 1) <= (uVar15 & 0xffffff)) {
LAB_fffffff009c0950c:
    uVar28 = 9;
    goto LAB_fffffff009c09510;
  }
  pbVar1 = (byte *)(*(long *)(*DAT_fffffff00af47df8 + (ulong)((uVar15 & 0xffffff) >> 6) * 8) +
                   (ulong)(uVar15 & 0x3f) * 0x50);
  if ((*pbVar1 & 5) != 1) goto LAB_fffffff009c0950c;
  if (param_8 < 0x40086440) {
    if (param_8 < 0x4004644c) {
      if (param_8 < 0x40046418) {
        if (param_8 < 0x2000641e) {
          if (param_8 == 0x20006415) {
            plVar25 = *(long **)(pbVar1 + 8);
            plVar21 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x370))();
            plVar24 = thunk_FUN_fffffff00a894f30(plVar21,(long)PTR_DAT_fffffff008060478);
            plVar21 = DAT_fffffff00af47df8;
            if (plVar24 != (long *)0x0) {
              thunk_FUN_fffffff00a2262a8(DAT_fffffff00af47e08);
              thunk_FUN_fffffff00a2262a8(DAT_fffffff00af47e10);
              iVar16 = FUN_fffffff009c0b180(plVar21,*(int *)(pbVar1 + 4));
              if ((iVar16 != 1) ||
                 (iVar16 = (**(code **)(*plVar24 + 0x540))(plVar24,plVar25,0,3), iVar16 == 0)) {
                thunk_FUN_fffffff00a226de0(DAT_fffffff00af47e10);
                goto LAB_fffffff009c0adf8;
              }
              *pbVar1 = *pbVar1 | 4;
              thunk_FUN_fffffff00a226de0(DAT_fffffff00af47e10);
              thunk_FUN_fffffff00a226de0(DAT_fffffff00af47e08);
              lVar35 = **(long **)(pbVar1 + 0x10);
              (**(code **)(lVar35 + 0x2c8))(lVar35 + 0x2c8,*(long **)(pbVar1 + 0x10),plVar25,0);
              (**(code **)(*plVar25 + 0x20))(plVar25);
              uVar20 = (**(code **)(*plVar24 + 0x5e8))(*plVar24 + 0x5e8,plVar24);
              uVar28 = (**(code **)(*plVar24 + 0x478))(*plVar24 + 0x478,plVar24,uVar20);
              (**(code **)(*plVar24 + 0x2c8))(*plVar24 + 0x2c8,plVar24,plVar25,0);
              pcVar14 = *(code **)(*plVar25 + 0x28);
              goto LAB_fffffff009c0ade0;
            }
LAB_fffffff009c0adb0:
            uVar28 = 0x19;
            goto LAB_fffffff009c09510;
          }
          if (param_8 == 0x20006416) {
            uVar20 = *(undefined8 *)(pbVar1 + 8);
            plVar25 = *(long **)(pbVar1 + 0x10);
            pcVar14 = *(code **)(*plVar25 + 0x590);
            uVar28 = 0;
            uVar36 = 0;
            uVar17 = 0;
            goto LAB_fffffff009c09768;
          }
        }
        else {
          if (param_8 == 0x2000641e) {
            plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x370))();
            plVar25 = thunk_FUN_fffffff00a894f30(plVar25,(long)PTR_DAT_fffffff008060478);
            if (plVar25 != (long *)0x0) {
              uVar20 = (**(code **)(*plVar25 + 0x698))();
              goto LAB_fffffff009c0a684;
            }
            goto LAB_fffffff009c0adb0;
          }
          if (param_8 == 0x40046417) {
            uVar17 = (**(code **)(**(long **)(pbVar1 + 0x10) + 0x5c0))();
            goto LAB_fffffff009c0a7a4;
          }
        }
        goto code_r0xfffffff009c0aa9c;
      }
      if (param_8 < 0x4004641d) {
        if (param_8 == 0x40046418) {
LAB_fffffff009c09e44:
          uVar17 = (**(code **)(**(long **)(pbVar1 + 0x10) + 0x5a0))();
LAB_fffffff009c09e6c:
          uVar28 = 0;
          *(undefined4 *)param_9 = uVar17;
          goto LAB_fffffff009c09510;
        }
        if (param_8 != 0x4004641b) goto code_r0xfffffff009c0aa9c;
        plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x118))
                                    (*(long **)(pbVar1 + 0x10),"BSD Unit");
        goto LAB_fffffff009c0a774;
      }
      if (param_8 != 0x4004641d) {
        if (param_8 == 0x40046448) {
          uVar15 = *pbVar1 >> 3 & 1;
          goto LAB_fffffff009c0a928;
        }
        goto code_r0xfffffff009c0aa9c;
      }
      uVar17 = (**(code **)(**(long **)(pbVar1 + 0x10) + 0x5d0))();
    }
    else {
      if (param_8 < 0x40046456) {
        if (param_8 < 0x4004644e) {
          if (param_8 == 0x4004644c) {
            plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x130))
                                        (*(long **)(pbVar1 + 0x10),"IOStorageFeatures",
                                         *(undefined8 *)PTR_DAT_fffffff008064c08,3);
            plVar25 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064b78);
            *(undefined4 *)param_9 = 0;
            if (plVar25 != (long *)0x0) {
              plVar21 = (long *)(**(code **)(*plVar25 + 0x138))(plVar25,"Barrier");
              lVar35 = *(long *)PTR_PTR_fffffff008064bc0;
              plVar21 = thunk_FUN_fffffff00a894f30(plVar21,lVar35);
              puVar38 = *(undefined8 **)PTR_PTR_fffffff008064c18;
              if (plVar21 == (long *)*puVar38) {
                *(uint *)param_9 = (uint)*param_9 | 2;
              }
              plVar21 = (long *)(**(code **)(*plVar25 + 0x138))(plVar25,"Force Unit Access");
              plVar21 = thunk_FUN_fffffff00a894f30(plVar21,lVar35);
              if (plVar21 == (long *)*puVar38) {
                *(uint *)param_9 = (uint)*param_9 | 1;
              }
              plVar21 = (long *)(**(code **)(*plVar25 + 0x138))(plVar25,"Priority");
              plVar21 = thunk_FUN_fffffff00a894f30(plVar21,lVar35);
              if (plVar21 == (long *)*puVar38) {
                *(uint *)param_9 = (uint)*param_9 | 4;
              }
              plVar21 = (long *)(**(code **)(*plVar25 + 0x138))(plVar25,"Unmap");
              plVar21 = thunk_FUN_fffffff00a894f30(plVar21,lVar35);
              if (plVar21 == (long *)*puVar38) {
                *(uint *)param_9 = (uint)*param_9 | 0x10;
              }
              plVar25 = (long *)(**(code **)(*plVar25 + 0x138))(plVar25,"QueuedFlush");
              plVar25 = thunk_FUN_fffffff00a894f30(plVar25,lVar35);
              if (plVar25 == (long *)*puVar38) {
                uVar15 = (uint)*param_9 | 0x20;
                goto LAB_fffffff009c0a928;
              }
            }
            goto LAB_fffffff009c0b048;
          }
          if (param_8 == 0x4004644d) {
            plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x130))
                                        (*(long **)(pbVar1 + 0x10),"Physical Block Size",
                                         *(undefined8 *)PTR_DAT_fffffff008064c08,3);
            plVar25 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064ba0);
            if (plVar25 == (long *)0x0) goto LAB_fffffff009c09e44;
            uVar17 = (**(code **)(*plVar25 + 0xa8))();
            goto LAB_fffffff009c09e6c;
          }
        }
        else {
          if (param_8 == 0x4004644e) {
            plVar25 = *(long **)(pbVar1 + 0x10);
            uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
            pcVar14 = *(code **)(*plVar25 + 0x130);
            pcVar26 = "IOCommandPoolSize";
            goto LAB_fffffff009c0a768;
          }
          if (param_8 == 0x4004644f) {
            plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x130))
                                        (*(long **)(pbVar1 + 0x10),"Device Characteristics",
                                         *(undefined8 *)PTR_DAT_fffffff008064c08,3);
            plVar25 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064b78);
            *(undefined4 *)param_9 = 0;
            if (plVar25 != (long *)0x0) {
              plVar25 = (long *)(**(code **)(*plVar25 + 0x138))(plVar25,"Medium Type");
              plVar25 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064ba8);
              if ((plVar25 != (long *)0x0) &&
                 (iVar16 = (**(code **)(*plVar25 + 0xb8))(plVar25,"Solid State"), iVar16 != 0))
              goto LAB_fffffff009c0a920;
            }
            goto LAB_fffffff009c0b048;
          }
        }
        goto code_r0xfffffff009c0aa9c;
      }
      if (param_8 < 0x40046458) {
        if (param_8 == 0x40046456) {
          plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x130))
                                      (*(long **)(pbVar1 + 0x10),"Controller Characteristics",
                                       *(undefined8 *)PTR_DAT_fffffff008064c08,3);
          plVar25 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064b78);
          *(undefined4 *)param_9 = 0;
          if (plVar25 != (long *)0x0) {
            plVar25 = (long *)(**(code **)(*plVar25 + 0x138))(plVar25,"Encryption Type");
            plVar25 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064ba8);
            if (plVar25 != (long *)0x0) {
              iVar16 = (**(code **)(*plVar25 + 0xb8))(plVar25,"AES-CBC");
              if (iVar16 != 0) goto LAB_fffffff009c0a920;
              iVar16 = (**(code **)(*plVar25 + 0xb8))(plVar25,"AES-XEX");
              if (iVar16 == 0) {
                iVar16 = (**(code **)(*plVar25 + 0xb8))(plVar25,"AES-XTS");
                if (iVar16 == 0) goto LAB_fffffff009c0b048;
                uVar15 = 3;
              }
              else {
                uVar15 = 2;
              }
LAB_fffffff009c0a928:
              uVar28 = 0;
              *(uint *)param_9 = uVar15;
              goto LAB_fffffff009c09510;
            }
          }
        }
        else {
          if (param_8 != 0x40046457) goto code_r0xfffffff009c0aa9c;
          plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x130))
                                      (*(long **)(pbVar1 + 0x10),"Controller Characteristics",
                                       *(undefined8 *)PTR_DAT_fffffff008064c08,3);
          plVar25 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064b78);
          *(undefined4 *)param_9 = 0;
          if (plVar25 != (long *)0x0) {
            plVar25 = (long *)(**(code **)(*plVar25 + 0x138))(plVar25,"Low Power Mode");
            plVar25 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064bc0);
            if (plVar25 == (long *)**(undefined8 **)PTR_PTR_fffffff008064c18) {
LAB_fffffff009c0a920:
              uVar15 = 1;
              goto LAB_fffffff009c0a928;
            }
          }
        }
LAB_fffffff009c0b048:
        uVar28 = 0;
        goto LAB_fffffff009c09510;
      }
      if (param_8 != 0x40046458) {
        if (param_8 == 0x40086419) {
          lVar35 = (**(code **)(**(long **)(pbVar1 + 0x10) + 0x5a0))();
          if (lVar35 == 0) {
            uVar28 = 0;
            *param_9 = 0;
            goto LAB_fffffff009c09510;
          }
          uVar28 = (**(code **)(**(long **)(pbVar1 + 0x10) + 0x5a8))();
          uVar31 = (**(code **)(**(long **)(pbVar1 + 0x10) + 0x5a0))
                             (**(long **)(pbVar1 + 0x10) + 0x5a0);
          uVar36 = 0;
          if (uVar31 != 0) {
            uVar36 = uVar28 / uVar31;
          }
        }
        else {
          if (param_8 != 0x40086421) goto code_r0xfffffff009c0aa9c;
          *param_9 = 0;
          puVar13 = PTR_DAT_fffffff008064c08;
          plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x130))
                                      (*(long **)(pbVar1 + 0x10),"Protocol Characteristics",
                                       *(undefined8 *)PTR_DAT_fffffff008064c08,3);
          plVar25 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064b78);
          if (plVar25 == (long *)0x0) {
            plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x130))
                                        (*(long **)(pbVar1 + 0x10),"Physical Interconnect Location",
                                         *(undefined8 *)puVar13,3);
          }
          else {
            plVar25 = (long *)(**(code **)(*plVar25 + 0x138))
                                        (plVar25,"Physical Interconnect Location");
          }
          plVar25 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064ba8);
          if ((plVar25 == (long *)0x0) ||
             (iVar16 = (**(code **)(*plVar25 + 0xb8))(plVar25,"External"), iVar16 == 0))
          goto LAB_fffffff009c0b048;
          uVar36 = 1;
        }
        uVar28 = 0;
        *param_9 = uVar36;
        goto LAB_fffffff009c09510;
      }
      plVar25 = *(long **)(pbVar1 + 0x10);
      uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
      pcVar14 = *(code **)(*plVar25 + 0x130);
      pcVar26 = "IOMinimumSaturationByteCount";
LAB_fffffff009c0a768:
      plVar25 = (long *)(*pcVar14)(plVar25,pcVar26,uVar20,3);
LAB_fffffff009c0a774:
      plVar25 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064ba0);
      uVar17 = 0;
      if (plVar25 != (long *)0x0) {
        uVar17 = (**(code **)(*plVar25 + 0xa8))();
      }
    }
LAB_fffffff009c0a7a4:
    uVar28 = 0;
    *(undefined4 *)param_9 = uVar17;
    goto LAB_fffffff009c09510;
  }
  if (0x4020644f < param_8) {
    if (param_8 < 0x8010641f) {
      if (param_8 == 0x40206450) {
        uVar28 = param_9[2];
        puVar38 = (undefined8 *)param_9[3];
        plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x78))
                                    (*(long **)(pbVar1 + 0x10),"Format Error Detail",
                                     *(undefined8 *)PTR_DAT_fffffff008064c08,3);
        if ((plVar25 == (long *)0x0) &&
           (plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x78))
                                        (*(long **)(pbVar1 + 0x10),"Fatal Error Code",
                                         *(undefined8 *)puVar13,3), plVar25 == (long *)0x0)) {
          plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x78))
                                      (*(long **)(pbVar1 + 0x10),"Terminate Reason",
                                       *(undefined8 *)puVar13,3);
        }
        plVar21 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064ba8);
        if (plVar21 == (long *)0x0) {
          uVar28 = 0x16;
        }
        else {
          puVar27 = (undefined8 *)(**(code **)(*plVar21 + 0xa8))();
          thunk_FUN_fffffff00a354958(puVar38,puVar27,uVar28);
          uVar28 = 0;
        }
        if (plVar25 != (long *)0x0) {
          pcVar14 = *(code **)(*plVar25 + 0x28);
LAB_fffffff009c0ade0:
          (*pcVar14)(plVar25);
        }
      }
      else if (param_8 == 0x4080641c) {
        local_f0 = (undefined *)CONCAT44(local_f0._4_4_,0x80);
        iVar16 = (**(code **)(**(long **)(pbVar1 + 0x10) + 0x238))
                           (*(long **)(pbVar1 + 0x10),param_9,&local_f0,
                            *(undefined8 *)PTR_DAT_fffffff008064bf0);
        if ((iVar16 != 0) &&
           (pcVar26 = thunk_FUN_fffffff00a3544f8((char *)param_9,0x3a), pcVar26 != (char *)0x0)) {
          pcVar26 = thunk_FUN_fffffff00a3544f8((char *)param_9,0x3a);
          thunk_FUN_fffffff00a354958(param_9,(undefined8 *)(pcVar26 + 1),(long)(int)local_f0);
          goto LAB_fffffff009c0b048;
        }
LAB_fffffff009c0ada8:
        uVar28 = 0x16;
      }
      else {
        if (param_8 != 0x8010641a) goto code_r0xfffffff009c0aa9c;
        plVar25 = *(long **)(pbVar1 + 8);
        plVar21 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x370))();
        puVar39 = (uint *)thunk_FUN_fffffff00a894f30(plVar21,(long)PTR_DAT_fffffff008060478);
        plVar21 = DAT_fffffff00af47df8;
        lVar35 = 0;
        uVar28 = 0xf000;
        lVar37 = 0x20;
        do {
          if (((uVar28 & 1) != 0) && (*(char *)((long)param_9 + lVar35) != '\0'))
          goto LAB_fffffff009c0ada8;
          lVar35 = lVar35 + 1;
          uVar28 = uVar28 >> 1;
          lVar37 = lVar37 + -1;
        } while (lVar37 != 0);
        if (puVar39 == (uint *)0x0) goto LAB_fffffff009c0adb0;
        thunk_FUN_fffffff00a2262a8(DAT_fffffff00af47e08);
        thunk_FUN_fffffff00a2262a8(DAT_fffffff00af47e10);
        iVar16 = FUN_fffffff009c0b180(plVar21,*(int *)(pbVar1 + 4));
        if (iVar16 == 1) {
          uVar20 = 3;
          iVar16 = (**(code **)(*(long *)puVar39 + 0x540))(puVar39,plVar25,0);
          if (iVar16 != 0) {
            uVar36 = *param_9;
            uVar28 = param_9[1];
            *pbVar1 = *pbVar1 | 4;
            thunk_FUN_fffffff00a226de0(DAT_fffffff00af47e10);
            thunk_FUN_fffffff00a226de0(DAT_fffffff00af47e08);
            lVar35 = **(long **)(pbVar1 + 0x10);
            uVar30 = 0;
            (**(code **)(lVar35 + 0x2c8))(lVar35 + 0x2c8,*(long **)(pbVar1 + 0x10),plVar25);
            (**(code **)(*plVar25 + 0x20))(plVar25);
            uVar22 = (**(code **)(*(long *)puVar39 + 0x5f0))
                               (*(long *)puVar39 + 0x5f0,puVar39,uVar36 * (uint)uVar28);
            uVar28 = (**(code **)(*(long *)puVar39 + 0x478))
                               (*(long *)puVar39 + 0x478,puVar39,uVar22);
            auVar49._8_8_ = extraout_var;
            auVar49._0_8_ = extraout_d0;
            auVar7._4_12_ = auVar46;
            auVar7._0_4_ = uVar17;
            auVar10._4_12_ = auVar48;
            auVar10._0_4_ = uVar47;
            thunk_FUN_fffffff00a9324ec
                      (auVar49,param_2,auVar7,auVar10,param_5,param_6,puVar39,0xffffffffffffffff,
                       uVar30,uVar20,(undefined *)param_10);
            (**(code **)(*(long *)puVar39 + 0x2c8))(*(long *)puVar39 + 0x2c8,puVar39,plVar25,0);
            (**(code **)(*plVar25 + 0x28))(plVar25);
            goto LAB_fffffff009c0b098;
          }
        }
        thunk_FUN_fffffff00a226de0(DAT_fffffff00af47e10);
LAB_fffffff009c0adf8:
        thunk_FUN_fffffff00a226de0(DAT_fffffff00af47e08);
        uVar28 = 0x10;
      }
    }
    else if (param_8 < 0xc010641a) {
      if (param_8 != 0x8010641f) {
        if (param_8 == 0x80186416) {
          if ((*(uint *)PTR_DAT_fffffff008064c20 & 0xfffffff7) != 0) {
            thunk_FUN_fffffff00a6de494
                      (param_1,param_2,uVar17,uVar47,param_5,param_6,0x3060000,(long)(int)uVar15,
                       0x80186416,(ulong)(uint)param_9[2],0);
          }
          lVar35 = 0;
          uVar28 = 0xf00000;
          lVar37 = 0x20;
          do {
            if (((uVar28 & 1) != 0) && (*(char *)((long)param_9 + lVar35) != '\0'))
            goto LAB_fffffff009c0ada8;
            lVar35 = lVar35 + 1;
            uVar28 = uVar28 >> 1;
            lVar37 = lVar37 + -1;
          } while (lVar37 != 0);
          uVar20 = *(undefined8 *)(pbVar1 + 8);
          plVar25 = *(long **)(pbVar1 + 0x10);
          uVar28 = *param_9;
          uVar36 = param_9[1];
          uVar17 = (undefined4)param_9[2];
          pcVar14 = *(code **)(*plVar25 + 0x590);
LAB_fffffff009c09768:
          uVar20 = (*pcVar14)(plVar25,uVar20,uVar28,uVar36,uVar17);
LAB_fffffff009c0a684:
          lVar35 = **(long **)(pbVar1 + 0x10);
          if (*(long *)PTR_DAT_fffffff008064be8 == local_70) {
            if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c0a704. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
              uVar28 = (**(code **)(lVar35 + 0x478))
                                 (*(long **)(pbVar1 + 0x10),uVar20,lVar35 + 0x478);
              return uVar28;
            }
                    /* WARNING: Does not return */
            pcVar14 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c0a6fc);
            (*pcVar14)();
          }
          goto LAB_fffffff009c0b0fc;
        }
        goto code_r0xfffffff009c0aa9c;
      }
      uStack_88 = 0;
      local_90 = 0;
      uStack_78 = 0;
      uStack_80 = 0;
      uStack_a8 = 0;
      local_b0 = 0;
      uStack_98 = 0;
      uStack_a0 = 0;
      uStack_c8 = 0;
      local_d0 = 0;
      uStack_b8 = 0;
      uStack_c0 = 0;
      uStack_e8 = 0;
      local_f0 = (undefined *)0x0;
      uStack_d8 = 0;
      uStack_e0 = 0;
      puVar33 = param_10;
      uVar20 = thunk_FUN_fffffff00a7273c0(param_11);
      if ((int)uVar20 == 0) {
        lVar35 = 0;
        uVar28 = 0xf000;
        lVar37 = 0x20;
        do {
          if (((uVar28 & 1) != 0) && (*(char *)((long)param_9 + lVar35) != '\0'))
          goto LAB_fffffff009c0ada8;
          lVar35 = lVar35 + 1;
          uVar28 = uVar28 >> 1;
          lVar37 = lVar37 + -1;
        } while (lVar37 != 0);
        puVar38 = (undefined8 *)(ulong)(uint)*param_9;
        lVar35 = 8;
        lVar37 = 4;
      }
      else {
        puVar38 = (undefined8 *)*param_9;
        lVar35 = 0xc;
        lVar37 = 8;
      }
      if (puVar38 == (undefined8 *)0x0) goto LAB_fffffff009c0ada8;
      uVar18 = *(uint *)((long)param_9 + lVar37);
      if (uVar18 >> 0x1c == 0) {
        uVar19 = *(uint *)((long)param_9 + lVar35);
        puVar40 = (ulong *)((ulong)uVar18 << 4);
        if (uVar18 < 9) {
          if (uVar18 == 0) goto LAB_fffffff009c0b048;
          local_100 = (ulong *)&DAT_00000080;
          ppuVar23 = &local_f0;
          puVar43 = puVar40;
        }
        else {
          auVar5._8_8_ = extraout_var_00;
          auVar5._0_8_ = extraout_d0_00;
          auVar9._4_12_ = auVar46;
          auVar9._0_4_ = uVar17;
          auVar12._4_12_ = auVar48;
          auVar12._0_4_ = uVar47;
          auVar49 = thunk_FUN_fffffff00a221024
                              (auVar5,param_2,auVar9,auVar12,param_5,param_6,puVar40,1);
          ppuVar23 = auVar49._0_8_;
          uVar18 = (uint)puVar40;
          if (ppuVar23 == (undefined **)0x0) {
            uVar18 = 0x80;
          }
          puVar43 = (ulong *)(ulong)uVar18;
          local_100 = puVar40;
          if (ppuVar23 == (undefined **)0x0) {
            local_100 = (ulong *)&DAT_00000080;
            ppuVar23 = &local_f0;
          }
        }
        puVar13 = PTR_DAT_fffffff008064c20;
        puVar41 = puVar40;
        do {
          if (local_100 < (ulong *)((ulong)puVar43 & 0xffffffff)) goto LAB_fffffff009c0b100;
          ppuVar42 = (undefined **)((ulong)puVar43 & 0xffffffff);
          thunk_FUN_fffffff00aa65cc0(ppuVar23,(ulong)ppuVar42);
          if (param_11 == *(long *)PTR_DAT_fffffff008064c30) {
            auVar45 = thunk_FUN_fffffff00aa65b10(ppuVar23,puVar38,(ulong)ppuVar42);
          }
          else {
            ppuVar32 = ppuVar42;
            uVar28 = thunk_FUN_fffffff00a389b14(puVar38,ppuVar23,(ulong)ppuVar42,param_10);
            auVar45._8_8_ = extraout_var_04;
            auVar45._0_8_ = extraout_d0_04;
            uVar20 = extraout_d0_04;
            uVar22 = extraout_var_04;
            if ((int)uVar28 != 0) goto LAB_fffffff009c0affc;
          }
          param_10 = (ulong *)((ulong)puVar43 >> 4 & 0xfffffff);
          uVar34 = *(uint *)puVar13;
          uVar18 = (uint)puVar43;
          if (uVar34 != 0 && 0xf < uVar18) {
            lVar35 = 0;
            puVar33 = param_10;
            do {
              if ((uVar34 & 0xfffffff7) != 0) {
                uVar28 = 0;
                if (*(ulong *)(pbVar1 + 0x20) != 0) {
                  uVar28 = (ulong)ppuVar23[lVar35 * 2] / *(ulong *)(pbVar1 + 0x20);
                }
                auVar45 = thunk_FUN_fffffff00a6de494
                                    (auVar45,param_2,uVar17,uVar47,param_5,param_6,0x3060004,
                                     (long)(int)uVar15,uVar28,(long)(ppuVar23 + lVar35 * 2)[1],0);
                uVar34 = *(uint *)puVar13;
              }
              lVar35 = lVar35 + 1;
              puVar33 = (ulong *)((long)puVar33 + -1);
            } while (puVar33 != (ulong *)0x0);
          }
          puVar33 = (ulong *)(ulong)uVar19;
          ppuVar32 = ppuVar23;
          uVar20 = (**(code **)(**(long **)(pbVar1 + 0x10) + 0x568))
                             (*(long **)(pbVar1 + 0x10),*(undefined8 *)(pbVar1 + 8));
          lVar35 = **(long **)(pbVar1 + 0x10);
          uVar28 = (**(code **)(lVar35 + 0x478))(lVar35 + 0x478,*(long **)(pbVar1 + 0x10),uVar20);
          uVar20 = extraout_d0_05;
          uVar22 = extraout_var_05;
          if ((int)uVar28 != 0) goto LAB_fffffff009c0affc;
          puVar38 = (undefined8 *)((long)puVar38 + (long)ppuVar42);
          uVar34 = (int)puVar41 - uVar18;
          puVar41 = (ulong *)(ulong)uVar34;
          if (uVar34 <= uVar18) {
            uVar18 = uVar34;
          }
          puVar43 = (ulong *)(ulong)uVar18;
        } while (uVar34 != 0);
        uVar28 = 0;
LAB_fffffff009c0affc:
        if (ppuVar23 != &local_f0) {
          auVar6._8_8_ = uVar22;
          auVar6._0_8_ = uVar20;
          thunk_FUN_fffffff00a22175c
                    (auVar6,param_2,uVar17,uVar47,param_5,param_6,ppuVar23,(undefined *)puVar40,
                     ppuVar32,param_10,(undefined *)puVar33);
        }
      }
      else {
        uVar28 = 0x54;
      }
    }
    else if (param_8 == 0xc010641a) {
      puVar33 = param_10;
      plVar25 = (long *)(**(code **)(**(long **)(pbVar1 + 0x10) + 0x370))();
      plVar25 = thunk_FUN_fffffff00a894f30(plVar25,(long)PTR_DAT_fffffff008060478);
      uVar20 = thunk_FUN_fffffff00a7273c0(param_11);
      lVar35 = 0;
      if ((int)uVar20 == 0) {
        uVar28 = 0xff00;
        lVar37 = 0x20;
        do {
          if (((uVar28 & 1) != 0) && (*(char *)((long)param_9 + lVar35) != '\0'))
          goto LAB_fffffff009c0ada8;
          lVar35 = lVar35 + 1;
          uVar28 = uVar28 >> 1;
          lVar37 = lVar37 + -1;
        } while (lVar37 != 0);
        puVar40 = (ulong *)(ulong)(uint)*param_9;
        lVar35 = 4;
      }
      else {
        uVar28 = 0xf000;
        lVar37 = 0x20;
        do {
          if (((uVar28 & 1) != 0) && (*(char *)((long)param_9 + lVar35) != '\0'))
          goto LAB_fffffff009c0ada8;
          lVar35 = lVar35 + 1;
          uVar28 = uVar28 >> 1;
          lVar37 = lVar37 + -1;
        } while (lVar37 != 0);
        puVar40 = (ulong *)*param_9;
        lVar35 = 8;
      }
      if (plVar25 == (long *)0x0) goto LAB_fffffff009c0adb0;
      uVar15 = *(uint *)((long)param_9 + lVar35);
      uVar18 = (**(code **)(*plVar25 + 0x618))(plVar25,0,0);
      if (uVar15 == 0) {
        uVar28 = 0;
      }
      else {
        if (puVar40 == (ulong *)0x0) goto LAB_fffffff009c0ada8;
        uVar19 = uVar15;
        if (uVar18 <= uVar15) {
          uVar19 = uVar18;
        }
        uVar28 = (ulong)uVar19;
        puVar43 = (ulong *)(uVar28 << 3);
        auVar2._8_8_ = extraout_var_01;
        auVar2._0_8_ = extraout_d0_01;
        auVar8._4_12_ = auVar46;
        auVar8._0_4_ = uVar17;
        auVar11._4_12_ = auVar48;
        auVar11._0_4_ = uVar47;
        thunk_FUN_fffffff00a902580(auVar2,param_2,auVar8,auVar11,param_5,param_6,puVar43);
        if (extraout_x0 == (undefined **)0x0) goto LAB_fffffff009c0adb8;
        thunk_FUN_fffffff00aa65cc0(extraout_x0,(ulong)puVar43);
        uVar31 = uVar28;
        (**(code **)(*plVar25 + 0x618))(plVar25,extraout_x0);
        uVar29 = (**(code **)(**(long **)(pbVar1 + 0x10) + 0x5a0))
                           (**(long **)(pbVar1 + 0x10) + 0x5a0);
        puVar13 = PTR_DAT_fffffff008064c30;
        uVar36 = 0x200;
        if (uVar29 != 0) {
          uVar36 = uVar29;
        }
        if (uVar18 == 0) {
          uVar19 = 0;
          puVar44 = extraout_d0_02;
          uVar29 = extraout_var_02;
        }
        else {
          lVar35 = 0;
          do {
            iVar16 = (int)(lVar35 * 8);
            puVar41 = (ulong *)((long)extraout_x0 + (long)iVar16);
            if (lVar35 * 8 - (long)iVar16 != 0) {
              puVar41 = (ulong *)((ulong)(extraout_x0 + lVar35) & 0xffffffffffff |
                                 0x2bad000000000000);
            }
            puVar44 = (undefined *)0x0;
            if (uVar36 != 0) {
              puVar44 = (undefined *)(*puVar41 / uVar36);
            }
            uStack_e8 = uVar36 & 0xffffffff;
            local_f0 = puVar44;
            if (param_11 == *(long *)puVar13) {
              puVar40[1] = uStack_e8;
              *puVar40 = (ulong)puVar44;
              uVar29 = uStack_e8;
            }
            else {
              uVar31 = 0x10;
              uVar20 = thunk_FUN_fffffff00a38a690(&local_f0,puVar40,0x10,param_10);
              uVar19 = (uint)uVar20;
              puVar44 = extraout_d0_03;
              uVar29 = extraout_var_03;
              if (uVar19 != 0) goto LAB_fffffff009c0b0c8;
            }
            lVar35 = lVar35 + 1;
            puVar40 = puVar40 + 2;
            uVar28 = uVar28 - 1;
          } while (uVar28 != 0);
          uVar19 = 0;
        }
LAB_fffffff009c0b0c8:
        auVar3._8_8_ = uVar29;
        auVar3._0_8_ = puVar44;
        thunk_FUN_fffffff00a9026b0
                  (auVar3,param_2,uVar17,uVar47,param_5,param_6,extraout_x0,(undefined *)puVar43,
                   uVar31,param_10,(undefined *)puVar33);
        uVar34 = 7;
        if (uVar18 <= uVar15) {
          uVar34 = uVar19;
        }
        uVar28 = (ulong)uVar34;
        uVar18 = uVar15;
      }
      uVar20 = thunk_FUN_fffffff00a7273c0(param_11);
      if ((int)uVar20 == 0) {
        *(uint *)((long)param_9 + 4) = uVar18;
      }
      else {
        *(uint *)(param_9 + 1) = uVar18;
      }
    }
    else {
      if (param_8 != 0xc028644f) goto code_r0xfffffff009c0aa9c;
      puVar39 = (uint *)((long)param_9 + 0x1c);
      uVar36 = (ulong)(long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff008064b68 & 0x1f)) / 0x18;
      if (*puVar39 <= uVar36) {
        uVar36 = (ulong)*puVar39;
      }
      uVar15 = (uint)uVar36;
      *puVar39 = uVar15;
      ppuVar23 = (undefined **)
                 thunk_FUN_fffffff00a902580
                           (param_1,param_2,param_3,param_4,param_5,param_6,(ulong *)(uVar36 * 0x18)
                           );
      if (ppuVar23 != (undefined **)0x0) {
        if (uVar36 < *puVar39) {
LAB_fffffff009c0b100:
                    /* WARNING: Does not return */
          pcVar14 = (code *)SoftwareBreakpoint(0xbffe,0xfffffff009c0b104);
          (*pcVar14)();
        }
        thunk_FUN_fffffff00aa65cc0(ppuVar23,(ulong)*puVar39 * 0x18);
        uVar31 = *param_9;
        puVar33 = (ulong *)param_9[1];
        lVar35 = **(long **)(pbVar1 + 0x10);
        uVar20 = (**(code **)(lVar35 + 0x598))
                           (lVar35 + 0x598,*(long **)(pbVar1 + 0x10),*(undefined8 *)(pbVar1 + 8));
        puVar13 = PTR_DAT_fffffff008064c30;
        if ((int)uVar20 == 0) {
          uVar18 = *(uint *)((long)param_9 + 0x1c);
          if (uVar15 <= *(uint *)((long)param_9 + 0x1c)) {
            uVar18 = uVar15;
          }
          *(uint *)((long)param_9 + 0x1c) = uVar18;
          uVar31 = (ulong)uVar18 * 0x18;
          if (param_11 == *(long *)puVar13) {
            thunk_FUN_fffffff00aa65b10((undefined8 *)param_9[4],ppuVar23,uVar31);
          }
          else {
            thunk_FUN_fffffff00a38a690(ppuVar23,(undefined8 *)param_9[4],uVar31,puVar33);
          }
        }
        uVar28 = (**(code **)(**(long **)(pbVar1 + 0x10) + 0x478))(*(long **)(pbVar1 + 0x10),uVar20)
        ;
        auVar4._8_8_ = extraout_var_06;
        auVar4._0_8_ = extraout_d0_06;
        thunk_FUN_fffffff00a9026b0
                  (auVar4,param_2,uVar17,uVar47,param_5,param_6,ppuVar23,
                   (undefined *)(uVar36 * 0x18),uVar31,puVar33,(undefined *)puVar39);
LAB_fffffff009c0b098:
        if (*(long *)PTR_DAT_fffffff008064be8 == local_70) {
          return uVar28;
        }
        goto LAB_fffffff009c0b0fc;
      }
LAB_fffffff009c0adb8:
      uVar28 = 0xc;
    }
    goto LAB_fffffff009c09510;
  }
  if (0x1e < param_8 - 0x40086440U) {
code_r0xfffffff009c0aa9c:
    puVar38 = (undefined8 *)(**(long **)(pbVar1 + 8) + 0x550);
    if (*(long *)PTR_DAT_fffffff008064be8 == local_70) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c0ab1c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar28 = (*(code *)*puVar38)(*(long **)(pbVar1 + 8),param_7,param_8,param_9,param_10,
                                     param_11,puVar38);
        return uVar28;
      }
                    /* WARNING: Does not return */
      pcVar14 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c0ab14);
      (*pcVar14)();
    }
    goto LAB_fffffff009c0b0fc;
  }
  switch(param_8) {
  default:
    plVar25 = *(long **)(pbVar1 + 0x10);
    uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
    pcVar14 = *(code **)(*plVar25 + 0x130);
    pcVar26 = "IOMaximumBlockCountRead";
    break;
  case 0x40086441:
    plVar25 = *(long **)(pbVar1 + 0x10);
    uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
    pcVar14 = *(code **)(*plVar25 + 0x130);
    pcVar26 = "IOMaximumBlockCountWrite";
    break;
  case 0x40086442:
    plVar25 = *(long **)(pbVar1 + 0x10);
    uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
    pcVar14 = *(code **)(*plVar25 + 0x130);
    pcVar26 = "IOMaximumSegmentCountRead";
    break;
  case 0x40086443:
    plVar25 = *(long **)(pbVar1 + 0x10);
    uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
    pcVar14 = *(code **)(*plVar25 + 0x130);
    pcVar26 = "IOMaximumSegmentCountWrite";
    break;
  case 0x40086444:
    plVar25 = *(long **)(pbVar1 + 0x10);
    uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
    pcVar14 = *(code **)(*plVar25 + 0x130);
    pcVar26 = "IOMaximumSegmentByteCountRead";
    break;
  case 0x40086445:
    plVar25 = *(long **)(pbVar1 + 0x10);
    uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
    pcVar14 = *(code **)(*plVar25 + 0x130);
    pcVar26 = "IOMaximumSegmentByteCountWrite";
    break;
  case 0x40086446:
    plVar25 = *(long **)(pbVar1 + 0x10);
    uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
    pcVar14 = *(code **)(*plVar25 + 0x130);
    pcVar26 = "IOMaximumByteCountRead";
    break;
  case 0x40086447:
    plVar25 = *(long **)(pbVar1 + 0x10);
    uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
    pcVar14 = *(code **)(*plVar25 + 0x130);
    pcVar26 = "IOMaximumByteCountWrite";
    break;
  case 0x40086448:
  case 0x4008644c:
  case 0x4008644d:
  case 0x4008644e:
  case 0x4008644f:
  case 0x40086451:
  case 0x40086452:
  case 0x40086453:
  case 0x40086454:
  case 0x40086455:
  case 0x40086456:
  case 0x40086457:
  case 0x40086458:
  case 0x40086459:
  case 0x4008645a:
  case 0x4008645b:
  case 0x4008645c:
  case 0x4008645d:
    goto code_r0xfffffff009c0aa9c;
  case 0x40086449:
    uVar36 = (**(code **)(**(long **)(pbVar1 + 0x10) + 0x5b0))();
    goto LAB_fffffff009c0a148;
  case 0x4008644a:
    plVar25 = *(long **)(pbVar1 + 0x10);
    uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
    pcVar14 = *(code **)(*plVar25 + 0x130);
    pcVar26 = "IOMinimumSegmentAlignmentByteCount";
    break;
  case 0x4008644b:
    plVar25 = *(long **)(pbVar1 + 0x10);
    uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
    pcVar14 = *(code **)(*plVar25 + 0x130);
    pcVar26 = "IOMaximumSegmentAddressableBitCount";
    break;
  case 0x40086450:
    uVar36 = FUN_fffffff009c08894(*(long **)(pbVar1 + 0x10));
    goto LAB_fffffff009c0a148;
  case 0x4008645e:
    plVar25 = *(long **)(pbVar1 + 0x10);
    uVar20 = *(undefined8 *)PTR_DAT_fffffff008064c08;
    pcVar14 = *(code **)(*plVar25 + 0x130);
    pcVar26 = "IOMaximumSwapWrite";
  }
  plVar25 = (long *)(*pcVar14)(plVar25,pcVar26,uVar20,3);
  plVar25 = thunk_FUN_fffffff00a894f30(plVar25,*(long *)PTR_PTR_fffffff008064ba0);
  uVar36 = 0;
  if (plVar25 != (long *)0x0) {
    uVar36 = (**(code **)(*plVar25 + 0xb0))();
  }
LAB_fffffff009c0a148:
  uVar28 = 0;
  *param_9 = uVar36;
LAB_fffffff009c09510:
  if (*(long *)PTR_DAT_fffffff008064be8 == local_70) {
    return uVar28;
  }
LAB_fffffff009c0b0fc:
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

