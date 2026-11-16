// FUN_fffffff00818e21c @ fffffff00818e21c size=2340

undefined8
FUN_fffffff00818e21c(long param_1,undefined8 param_2,ulong param_3,undefined8 param_4,long param_5)

{
  undefined4 uVar1;
  bool bVar2;
  undefined4 uVar3;
  long *plVar4;
  long *plVar5;
  ulong uVar6;
  undefined8 *puVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  long *plVar13;
  long lVar14;
  undefined8 uVar15;
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
  
  plVar4 = (long *)FUN_fffffff0081e2fcc
                             (*(undefined8 *)
                               (*(long *)(*(long *)(param_1 + 0x530) + 0x11d98) + 0x10));
  if (plVar4 == (long *)0x0) {
LAB_fffffff00818e418:
    thunk_EXT_FUN_8011000002c13530(param_2);
    goto LAB_fffffff00818e424;
  }
  uVar11 = *(undefined8 *)(param_1 + 0x530);
  plVar5 = (long *)(**(code **)(DAT_fffffff00ae23078 + 0x68))();
  if (plVar5 == (long *)0x0) {
    bVar2 = false;
  }
  else {
    uVar6 = (**(code **)(PTR_DAT_fffffff007ca6118 + 0x88))(plVar5,uVar11,param_1);
    if ((uVar6 & 1) == 0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
      bVar2 = false;
      plVar5 = (long *)0x0;
    }
    else {
      plVar5[0x1a] = (long)plVar4;
      plVar5[0x1b] = param_3;
      (**(code **)(*plVar4 + 0x20))(plVar4);
      uStack_88 = 0;
      local_90 = 0;
      uStack_78 = 0;
      uStack_80 = 0;
      uStack_a8 = 0;
      local_b0 = 0;
      uStack_98 = 0;
      uStack_a0 = 0;
      thunk_EXT_FUN_8011000002946f14(&local_b0);
      lVar9 = *(long *)(param_1 + 0x530);
      if ((*(byte *)(lVar9 + 0x1ac45) & 1) != 0) {
        FUN_fffffff0081a0304(*(undefined8 *)(lVar9 + 0x148),0x80b,param_1 + 0x4d8,0);
        lVar9 = *(long *)(param_1 + 0x530);
      }
      thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar9 + 0x148),param_1 + 0x4d8,&local_b0);
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498,&local_b0);
      thunk_EXT_FUN_801100000294849c
                (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),&local_b0,plVar5 + 0xe);
      thunk_EXT_FUN_801100000294c614
                (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x158),param_1,plVar5);
      bVar2 = true;
    }
  }
  (**(code **)(*plVar4 + 0x28))(plVar4);
  if (plVar5 == (long *)0x0) {
    if (!bVar2) goto LAB_fffffff00818e418;
  }
  else {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (param_5 == 0) {
    bVar2 = true;
  }
  else {
    bVar2 = *(int *)(param_5 + 0xc4) != 0x200;
  }
  uVar6 = thunk_EXT_FUN_8011000002c13500(param_2);
  if (param_3 <= uVar6) {
    return 1;
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
  thunk_EXT_FUN_8011000002946f14(&local_b0);
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x11164) & 1) == 0) {
    puVar12 = (undefined8 *)0x0;
  }
  else {
    puVar12 = &local_f0;
    thunk_EXT_FUN_8011000002946f14(&local_f0);
  }
  plVar4 = (long *)(**(code **)(DAT_fffffff00ae23d00 + 0x68))();
  if (plVar4 == (long *)0x0) goto LAB_fffffff00818e424;
  (**(code **)(*plVar4 + 0xe8))
            (plVar4,*(undefined8 *)(param_1 + 0x530),param_1,*(undefined8 *)(param_1 + 0x480),
             param_2,param_3,param_4,*(byte *)(param_1 + 0x7f7) & 1);
  if (*(int *)(*(long *)(*(long *)(param_1 + 0x610) + 200) + 0x28) == 0) {
    lVar14 = plVar4[0x20];
    lVar9 = *(long *)(param_1 + 0x530);
    if ((*(byte *)(lVar9 + 0x1ac45) & 1) != 0) {
      FUN_fffffff0081a0304(*(undefined8 *)(lVar9 + 0x148),0x80b,param_1 + 0x4d8,lVar14);
      lVar9 = *(long *)(param_1 + 0x530);
    }
    thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar9 + 0x148),param_1 + 0x4d8,&local_b0);
    puVar7 = puVar12;
    if (puVar12 == (undefined8 *)0x0) {
      if (!bVar2) goto LAB_fffffff00818e5cc;
      uVar11 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
      lVar9 = param_1 + 0x498;
      puVar7 = &local_b0;
LAB_fffffff00818e664:
      thunk_EXT_FUN_80110000029486ac(uVar11,lVar9,puVar7);
    }
    else {
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x4d8,puVar12);
      if (bVar2) {
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498,&local_b0);
        uVar11 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
        lVar9 = param_1 + 0x628;
        goto LAB_fffffff00818e664;
      }
LAB_fffffff00818e5cc:
      FUN_fffffff00818ac24
                (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),*(undefined4 *)(param_5 + 0xb4),
                 *(undefined4 *)(param_5 + 0xb8));
      FUN_fffffff00818add4
                (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),*(undefined4 *)(param_5 + 0xc4),
                 &local_b0,puVar12,lVar14);
      FUN_fffffff00818c0d0(param_1,param_5,0,&local_b0,puVar12,lVar14);
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x5d0,&local_b0);
      if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
        FUN_fffffff0081a0304
                  (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),0x81b,param_1 + 0x5d0,lVar14)
        ;
      }
      if (puVar12 != (undefined8 *)0x0) {
        uVar11 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
        lVar9 = param_1 + 0x5d0;
        goto LAB_fffffff00818e664;
      }
    }
    if (*(int *)(*(long *)(param_1 + 0x610) + 0x98) == 0) {
      lVar9 = FUN_fffffff00818cd38(param_1,&local_b0);
      *(long *)(param_1 + 0x820) = lVar9;
      if (lVar9 != 0) {
        plVar5 = (long *)(param_1 + 0x820);
        puVar7 = (undefined8 *)(lVar9 + 0x218);
        uVar3 = 2;
        lVar9 = 0x810;
        goto LAB_fffffff00818e6cc;
      }
    }
    else {
      lVar9 = FUN_fffffff00818c3bc(param_1,&local_b0,1);
      *(long *)(param_1 + 0x818) = lVar9;
      if (lVar9 != 0) {
        plVar5 = (long *)(param_1 + 0x818);
        puVar7 = (undefined8 *)(lVar9 + 0x220);
        uVar3 = 1;
        lVar9 = 0x808;
LAB_fffffff00818e6cc:
        plVar13 = (long *)*puVar7;
        *(long **)(param_1 + lVar9) = plVar13;
        lVar9 = *plVar5;
        uVar1 = *(undefined4 *)(lVar9 + 0xe8);
        *(undefined4 *)(plVar4 + 0x4f) = uVar3;
        thunk_EXT_FUN_8011000002969708(plVar4,param_2);
        if (*(long *)(param_1 + 0x518) != 0) {
          thunk_EXT_FUN_8011000002969c30(plVar4);
        }
        if ((*(byte *)(param_1 + 0x618) & 1) == 0) {
          plVar5 = *(long **)(*(long *)(param_1 + 0x610) + 0xa8);
          (**(code **)(*plVar5 + 0x98))(plVar5,0,0);
        }
        (**(code **)(*plVar4 + 0xd8))(plVar4,*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8));
        if (puVar12 != (undefined8 *)0x0) {
          thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(plVar13[2] + 0x148),plVar13 + 0x23,puVar12)
          ;
        }
        thunk_EXT_FUN_801100000296a2e0(plVar4,&local_b0);
        if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
          FUN_fffffff0081a0304
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),0x806,&local_b0,lVar14);
        }
        thunk_EXT_FUN_801100000294166c(plVar13,*(undefined8 *)(param_1 + 0x488));
        plVar4[0x3f] = (long)plVar13;
        uVar15 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
        uVar11 = (**(code **)(*plVar4 + 0xf8))(plVar4);
        thunk_EXT_FUN_8011000002947250(uVar15,0,&local_b0,uVar11,0xffffffff);
        (**(code **)(*plVar13 + 0xa0))(plVar13);
        uVar11 = (**(code **)(*plVar4 + 0xf0))(plVar4);
        (**(code **)(*plVar13 + 0xa8))(plVar13,0,uVar11);
        *(int *)(plVar4 + 0x89) = (int)plVar13[3];
        thunk_EXT_FUN_801100000296a27c(plVar4);
        if (bVar2) {
          if (puVar12 != (undefined8 *)0x0) {
            thunk_EXT_FUN_80110000029486ac
                      (*(undefined8 *)(plVar13[2] + 0x148),puVar12,plVar13 + 0x23);
          }
          lVar10 = *(long *)(param_1 + 0x530);
          uVar8 = *(uint *)(lVar10 + 0x1ac44);
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
            (**(code **)(*plVar13 + 0x98))(plVar13,&local_130);
            FUN_fffffff0081a05d0
                      (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x530) + 0x148) + 0x10),0x80f,
                       local_130._4_4_,uVar1,lVar14);
            lVar10 = *(long *)(param_1 + 0x530);
            uVar8 = *(uint *)(lVar10 + 0x1ac44);
          }
          if ((uVar8 >> 3 & 1) == 0) goto LAB_fffffff00818ea08;
          uVar3 = thunk_EXT_FUN_8011000002c13530(param_2);
          uVar11 = 0x338;
        }
        else {
          FUN_fffffff00818af98
                    (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),
                     *(undefined4 *)(param_5 + 0xc4),plVar4 + 0x10,puVar12,lVar14);
          FUN_fffffff00818d240(param_1,param_5,2,plVar4 + 0x10,puVar12);
          if (puVar12 != (undefined8 *)0x0) {
            thunk_EXT_FUN_80110000029486ac
                      (*(undefined8 *)(plVar13[2] + 0x148),puVar12,plVar13 + 0x23);
          }
          lVar10 = *(long *)(param_1 + 0x530);
          uVar8 = *(uint *)(lVar10 + 0x1ac44);
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
            (**(code **)(*plVar13 + 0x98))(plVar13,&local_130);
            FUN_fffffff0081a05d0
                      (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x530) + 0x148) + 0x10),0x81c,
                       local_130._4_4_,uVar1,lVar14);
            lVar10 = *(long *)(param_1 + 0x530);
            uVar8 = *(uint *)(lVar10 + 0x1ac44);
          }
          if ((uVar8 >> 3 & 1) == 0) goto LAB_fffffff00818ea08;
          uVar3 = thunk_EXT_FUN_8011000002c13530(param_2);
          uVar11 = 0x35e;
        }
        FUN_fffffff00817dc48(lVar10,uVar11,0,uVar3,param_3,param_4,lVar14,0);
LAB_fffffff00818ea08:
        plVar5 = *(long **)(*(long *)(param_1 + 0x530) + 0x4b0);
        (**(code **)(*plVar5 + 0x178))(plVar5,1,*(undefined4 *)(param_1 + 0x7ec));
        thunk_EXT_FUN_80110000029595ec(lVar9,plVar4);
        (**(code **)(*plVar4 + 0x28))(plVar4);
        (**(code **)(*plVar13 + 0x98))(plVar13,param_1 + 0x498);
        if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x11164) & 1) != 0) {
          thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(plVar13[2] + 0x148),plVar13 + 0x23,param_1 + 0x628);
        }
        lVar9 = *(long *)(*(long *)(param_1 + 0x610) + 0xa8);
        lVar14 = (ulong)*(uint *)(lVar9 + 0x28) * 0x40;
        uVar6 = lVar9 + 0x4c0 + (long)(int)lVar14;
        if (lVar14 - (int)lVar14 != 0) {
          uVar6 = lVar9 + 0x4c0 + lVar14 & 0xffffffffffffU | 0x2bad000000000000;
        }
        thunk_EXT_FUN_801100000294849c
                  (*(undefined8 *)(*(long *)(lVar9 + 0x18) + 0x148),param_1 + 0x498,uVar6);
        lVar9 = *(long *)(param_1 + 0x530);
        if ((((*(byte *)(*(long *)(lVar9 + 0x111b0) + 0x54) & 1) != 0) &&
            ((*(byte *)(*(long *)(lVar9 + 0x111b0) + 0x2c) >> 4 & 1) != 0)) ||
           ((*(byte *)(lVar9 + 0x5c8) >> 5 & 1) != 0)) {
          thunk_EXT_FUN_8011000002947870(*(undefined8 *)(lVar9 + 0x148),param_1 + 0x498);
        }
        return 1;
      }
    }
  }
  else {
    (**(code **)(*plVar4 + 0x88))(plVar4);
  }
  (**(code **)(*plVar4 + 0x28))(plVar4);
LAB_fffffff00818e424:
  *(undefined4 *)(param_1 + 0x520) = 8;
  return 0;
}

