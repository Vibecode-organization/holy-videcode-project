// FUN_fffffff00818b3a0 @ fffffff00818b3a0 size=2920

undefined8
FUN_fffffff00818b3a0
          (long param_1,long *param_2,ulong param_3,undefined4 param_4,long param_5,uint param_6)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  ulong uVar4;
  long *plVar5;
  undefined8 uVar6;
  long *plVar7;
  uint uVar8;
  long lVar9;
  long *plVar10;
  long *plVar11;
  uint uVar12;
  long lVar13;
  undefined8 uVar14;
  long lVar15;
  undefined8 *puVar16;
  long lVar17;
  long *local_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
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
  
  lVar13 = param_2[5];
  if (param_5 == 0) {
    bVar2 = true;
  }
  else {
    bVar2 = *(int *)(param_5 + 0xc4) != 0x200;
  }
  thunk_EXT_FUN_80110000032222a8(param_2[2]);
  if (lVar13 == 0) {
    uVar4 = (**(code **)(*param_2 + 0x80))(param_2);
    lVar17 = *(long *)(param_1 + 0x530);
    if ((*(byte *)(lVar17 + 0x1ac44) >> 3 & 1) != 0) {
      uVar3 = 0;
      goto LAB_fffffff00818b488;
    }
  }
  else {
    uVar4 = thunk_EXT_FUN_8011000002c13500(lVar13);
    lVar17 = *(long *)(param_1 + 0x530);
    if ((*(byte *)(lVar17 + 0x1ac44) >> 3 & 1) != 0) {
      uVar3 = thunk_EXT_FUN_8011000002c13530(lVar13);
LAB_fffffff00818b488:
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar17 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930cc8,uVar3,param_3,uVar4,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar17 + 0x1ac48));
    }
  }
  local_138 = (long *)(param_1 + 0x530);
  if (uVar4 < param_3) {
    iVar1 = *(int *)(param_1 + 0x7ec);
    lVar17 = param_2[3];
    plVar5 = (long *)(**(code **)(DAT_fffffff00ae230a0 + 0x68))();
    if (plVar5 == (long *)0x0) {
      thunk_EXT_FUN_8011000003222de0(param_2[2]);
      *(undefined4 *)(param_1 + 0x520) = 8;
      return 0;
    }
    (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
    plVar5[0x18] = lVar17;
    plVar5[0xf] = param_3;
    plVar5[0x10] = 0;
    thunk_EXT_FUN_8011000002946f14(plVar5 + 3);
    *(undefined2 *)(plVar5 + 0x17) = 0;
    uVar12 = *(int *)(plVar5[0x18] + 0x23c) * 1000 - 1000;
    if (3999 < uVar12) {
      uVar12 = 4000;
    }
    *(uint *)(plVar5 + 0x11) = uVar12;
    plVar5[0x12] = 0;
    plVar5[0x13] = 0;
    plVar5[2] = (long)param_2;
    (**(code **)(*param_2 + 0x20))(param_2);
    *(undefined4 *)(plVar5 + 0x11) = param_4;
    thunk_EXT_FUN_80110000032222a8(param_2[9]);
    if (iVar1 == 5) {
      *(int *)(param_2 + 0xe) = (int)param_2[0xe] + 1;
      *(undefined1 *)((long)plVar5 + 0xb9) = 1;
    }
    *(int *)((long)param_2 + 0x34) = *(int *)((long)param_2 + 0x34) + 1;
    plVar5[0x15] = 0;
    plVar10 = (long *)param_2[8];
    plVar5[0x16] = (long)plVar10;
    *plVar10 = (long)plVar5;
    param_2[8] = (long)(plVar5 + 0x15);
    *(undefined1 *)(plVar5 + 0x17) = 1;
    thunk_EXT_FUN_8011000003222de0(param_2[9]);
    lVar17 = param_2[3];
    if ((*(byte *)(lVar17 + 0x1ac44) >> 3 & 1) != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar17 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930d00,param_2,plVar5,param_3,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar17 + 0x1ac48));
    }
    uStack_88 = 0;
    local_90 = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    uStack_a8 = 0;
    local_b0 = 0;
    uStack_98 = 0;
    uStack_a0 = 0;
    uStack_e8 = 0;
    local_f0 = 0;
    uStack_d8 = 0;
    uStack_e0 = 0;
    uStack_c8 = 0;
    local_d0 = 0;
    uStack_b8 = 0;
    uStack_c0 = 0;
    thunk_EXT_FUN_8011000003222de0(param_2[2]);
    thunk_EXT_FUN_8011000002946f14(&local_b0);
    if ((*(byte *)(*local_138 + 0x11164) & 1) == 0) {
      puVar16 = (undefined8 *)0x0;
    }
    else {
      puVar16 = &local_f0;
      thunk_EXT_FUN_8011000002946f14(&local_f0);
    }
    plVar10 = (long *)(**(code **)(DAT_fffffff00ae23760 + 0x68))();
    if (plVar10 == (long *)0x0) {
      *(undefined4 *)(param_1 + 0x520) = 8;
    }
    else {
      (**(code **)(*plVar10 + 0xe8))
                (plVar10,*(undefined8 *)(param_1 + 0x530),param_1,*(undefined8 *)(param_1 + 0x480),
                 plVar5);
      if (*(int *)(*(long *)(*(long *)(param_1 + 0x610) + 200) + 0x28) == 0) {
        lVar17 = plVar10[0x20];
        lVar9 = *local_138;
        if ((*(byte *)(lVar9 + 0x1ac45) & 1) != 0) {
          FUN_fffffff0081a0304(*(undefined8 *)(lVar9 + 0x148),0x80b,param_1 + 0x4d8);
          lVar9 = *(long *)(param_1 + 0x530);
        }
        thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar9 + 0x148),param_1 + 0x4d8,&local_b0);
        if (puVar16 != (undefined8 *)0x0) {
          thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(*local_138 + 0x148),param_1 + 0x4d8,puVar16);
        }
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x5d0,&local_b0);
        if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
          FUN_fffffff0081a0304
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),0x81b,param_1 + 0x5d0,
                     lVar17);
        }
        if (puVar16 != (undefined8 *)0x0) {
          thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(*local_138 + 0x148),param_1 + 0x5d0,puVar16);
        }
        if (bVar2) {
          if (param_6 != 0) {
            FUN_fffffff00818add4
                      (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),0x100,&local_b0,puVar16,
                       lVar17);
          }
        }
        else {
          FUN_fffffff00818add4
                    (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),
                     *(undefined4 *)(param_5 + 0xc4),&local_b0,puVar16,lVar17);
          FUN_fffffff00818c0d0(param_1,param_5,0,&local_b0,puVar16,lVar17);
        }
        if (*(int *)(*(long *)(param_1 + 0x610) + 0x98) == 0) {
          lVar9 = FUN_fffffff00818cd38(param_1,&local_b0);
          *(long *)(param_1 + 0x820) = lVar9;
          if (lVar9 != 0) {
            plVar7 = (long *)(param_1 + 0x820);
            plVar11 = (long *)(lVar9 + 0x218);
            uVar12 = 2;
            lVar9 = 0x810;
            goto LAB_fffffff00818b904;
          }
        }
        else {
          lVar9 = FUN_fffffff00818c3bc(param_1,&local_b0,1);
          *(long *)(param_1 + 0x818) = lVar9;
          if (lVar9 != 0) {
            plVar7 = (long *)(param_1 + 0x818);
            plVar11 = (long *)(lVar9 + 0x220);
            uVar12 = 1;
            lVar9 = 0x808;
LAB_fffffff00818b904:
            plVar11 = (long *)*plVar11;
            *(long **)(param_1 + lVar9) = plVar11;
            lVar9 = *plVar7;
            uVar3 = *(undefined4 *)(lVar9 + 0xe8);
            *(uint *)(plVar10 + 0x6c) = uVar12;
            if (*(long *)(param_1 + 0x518) != 0) {
              thunk_EXT_FUN_8011000002969c30(plVar10);
            }
            if ((*(byte *)(param_1 + 0x618) & 1) == 0) {
              plVar7 = *(long **)(*(long *)(param_1 + 0x610) + 0xa8);
              (**(code **)(*plVar7 + 0x98))(plVar7,0,0);
            }
            (**(code **)(*plVar10 + 0xd8))
                      (plVar10,*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8));
            if (puVar16 != (undefined8 *)0x0) {
              thunk_EXT_FUN_80110000029486ac
                        (*(undefined8 *)(plVar11[2] + 0x148),plVar11 + 0x23,puVar16);
            }
            thunk_EXT_FUN_801100000296a2e0(plVar10,&local_b0);
            if ((*(byte *)(*local_138 + 0x1ac45) & 1) != 0) {
              FUN_fffffff0081a0304(*(undefined8 *)(*local_138 + 0x148),0x806,&local_b0,lVar17);
            }
            thunk_EXT_FUN_801100000294166c(plVar11,*(undefined8 *)(param_1 + 0x488));
            plVar10[0x3f] = (long)plVar11;
            uVar14 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
            uVar6 = (**(code **)(*plVar10 + 0xf8))(plVar10);
            thunk_EXT_FUN_8011000002947250(uVar14,0,&local_b0,uVar6,0xffffffff);
            (**(code **)(*plVar11 + 0xa0))(plVar11);
            uVar6 = (**(code **)(*plVar10 + 0xf0))(plVar10);
            (**(code **)(*plVar11 + 0xa8))(plVar11,0,uVar6);
            lVar15 = plVar11[3];
            *(int *)(plVar10[0x48] + 0x84) = (int)lVar15;
            *(int *)((long)plVar10 + 0x424) = (int)lVar15;
            thunk_EXT_FUN_801100000296a27c(plVar10);
            thunk_EXT_FUN_8011000002969708(plVar10,param_2);
            plVar7 = (long *)(**(code **)(*plVar10 + 0xf0))(plVar10);
            plVar5[0x10] = *plVar7;
            thunk_EXT_FUN_80110000029481a8
                      (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),(int)plVar11[3],
                       plVar5 + 3);
            if (bVar2) {
              if ((param_6 & 1) == 0) {
                thunk_EXT_FUN_80110000029486ac
                          (*(undefined8 *)(*local_138 + 0x148),plVar10 + 0x10,param_1 + 0x5d0);
                thunk_EXT_FUN_80110000029486ac
                          (*(undefined8 *)(plVar11[2] + 0x148),plVar10 + 0x10,plVar11 + 0x23);
                lVar15 = *local_138;
                uVar8 = *(uint *)(lVar15 + 0x1ac44);
                if ((uVar8 >> 8 & 1) != 0) {
                  uStack_108 = 0;
                  local_110 = 0;
                  uStack_f8 = 0;
                  uStack_100 = 0;
                  uStack_128 = 0;
                  local_130 = 0;
                  uStack_118 = 0;
                  uStack_120 = 0;
                  thunk_EXT_FUN_8011000002946f14(&local_130);
                  (**(code **)(*plVar11 + 0x98))(plVar11,&local_130);
                  FUN_fffffff0081a05d0
                            (*(undefined8 *)(*(long *)(*local_138 + 0x148) + 0x10),0x813,
                             local_130._4_4_,uVar3,lVar17);
                  lVar15 = *local_138;
                  uVar8 = *(uint *)(lVar15 + 0x1ac44);
                }
                if ((uVar8 >> 3 & 1) != 0) {
                  if (lVar13 == 0) {
                    uVar3 = 0;
                  }
                  else {
                    uVar3 = thunk_EXT_FUN_8011000002c13530(lVar13);
                  }
                  uVar4 = (ulong)uVar12 | plVar11[6] << 2;
                  uVar6 = 0x346;
                  goto LAB_fffffff00818bdb4;
                }
              }
              else {
                FUN_fffffff00818af98
                          (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),0x100,plVar10 + 0x10,
                           plVar10 + 0x10,lVar17);
                thunk_EXT_FUN_80110000029486ac
                          (*(undefined8 *)(plVar11[2] + 0x148),plVar10 + 0x10,plVar11 + 0x23);
                if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
                  uStack_108 = 0;
                  local_110 = 0;
                  uStack_f8 = 0;
                  uStack_100 = 0;
                  uStack_128 = 0;
                  local_130 = 0;
                  uStack_118 = 0;
                  uStack_120 = 0;
                  thunk_EXT_FUN_8011000002946f14(&local_130);
                  (**(code **)(*plVar11 + 0x98))(plVar11,&local_130);
                  FUN_fffffff0081a05d0
                            (*(undefined8 *)(*(long *)(*local_138 + 0x148) + 0x10),0x813,
                             local_130._4_4_,uVar3,lVar17);
                }
              }
            }
            else {
              FUN_fffffff00818af98
                        (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),
                         *(undefined4 *)(param_5 + 0xc4),plVar10 + 0x10,plVar10 + 0x10,lVar17);
              FUN_fffffff00818ac24
                        (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),
                         *(undefined4 *)(param_5 + 0xbc),*(undefined4 *)(param_5 + 0xc0));
              FUN_fffffff00818d240(param_1,param_5,2,plVar10 + 0x10,plVar10 + 0x10);
              thunk_EXT_FUN_80110000029486ac
                        (*(undefined8 *)(plVar11[2] + 0x148),plVar10 + 0x10,plVar11 + 0x23);
              lVar15 = *(long *)(param_1 + 0x530);
              uVar8 = *(uint *)(lVar15 + 0x1ac44);
              if ((uVar8 >> 8 & 1) != 0) {
                uStack_108 = 0;
                local_110 = 0;
                uStack_f8 = 0;
                uStack_100 = 0;
                uStack_128 = 0;
                local_130 = 0;
                uStack_118 = 0;
                uStack_120 = 0;
                thunk_EXT_FUN_8011000002946f14(&local_130);
                (**(code **)(*plVar11 + 0x98))(plVar11,&local_130);
                FUN_fffffff0081a05d0
                          (*(undefined8 *)(*(long *)(*local_138 + 0x148) + 0x10),0x81d,
                           local_130._4_4_,uVar3,lVar17);
                lVar15 = *local_138;
                uVar8 = *(uint *)(lVar15 + 0x1ac44);
              }
              if ((uVar8 >> 3 & 1) != 0) {
                if (lVar13 == 0) {
                  uVar3 = 0;
                }
                else {
                  uVar3 = thunk_EXT_FUN_8011000002c13530(lVar13);
                }
                uVar4 = (ulong)uVar12 | plVar11[6] << 2;
                uVar6 = 0x35d;
LAB_fffffff00818bdb4:
                FUN_fffffff00817dc48(lVar15,uVar6,0,uVar3,param_3,lVar17,uVar4,0);
              }
            }
            plVar7 = *(long **)(*(long *)(param_1 + 0x530) + 0x4b0);
            (**(code **)(*plVar7 + 0x178))(plVar7,1,*(undefined4 *)(param_1 + 0x7ec));
            thunk_EXT_FUN_80110000029595ec(lVar9,plVar10);
            (**(code **)(*plVar10 + 0x28))(plVar10);
            (**(code **)(*plVar11 + 0x98))(plVar11,param_1 + 0x498);
            if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x11164) & 1) != 0) {
              thunk_EXT_FUN_80110000029486ac
                        (*(undefined8 *)(plVar11[2] + 0x148),plVar11 + 0x23,param_1 + 0x628);
            }
            lVar13 = *(long *)(*(long *)(param_1 + 0x610) + 0xa8);
            lVar17 = (ulong)*(uint *)(lVar13 + 0x28) * 0x40;
            uVar4 = lVar13 + 0x4c0 + (long)(int)lVar17;
            if (lVar17 - (int)lVar17 != 0) {
              uVar4 = lVar13 + 0x4c0 + lVar17 & 0xffffffffffffU | 0x2bad000000000000;
            }
            thunk_EXT_FUN_801100000294849c
                      (*(undefined8 *)(*(long *)(lVar13 + 0x18) + 0x148),param_1 + 0x498,uVar4);
            lVar13 = *(long *)(param_1 + 0x530);
            if ((((*(byte *)(*(long *)(lVar13 + 0x111b0) + 0x54) & 1) != 0) &&
                ((*(byte *)(*(long *)(lVar13 + 0x111b0) + 0x2c) >> 4 & 1) != 0)) ||
               ((*(byte *)(lVar13 + 0x5c8) >> 5 & 1) != 0)) {
              thunk_EXT_FUN_8011000002947870(*(undefined8 *)(lVar13 + 0x148),param_1 + 0x498);
            }
            (**(code **)(*plVar5 + 0x28))(plVar5);
            goto LAB_fffffff00818b710;
          }
        }
      }
      else {
        (**(code **)(*plVar10 + 0x88))(plVar10);
      }
      *(undefined4 *)(param_1 + 0x520) = 8;
      (**(code **)(*plVar10 + 0x28))(plVar10);
    }
    (**(code **)(*plVar5 + 0x28))(plVar5);
    uVar6 = 0;
  }
  else {
    thunk_EXT_FUN_8011000003222de0(param_2[2]);
LAB_fffffff00818b710:
    uVar6 = 1;
  }
  return uVar6;
}

