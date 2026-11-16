// FUN_fffffff008196468 @ fffffff008196468 size=3264

/* WARNING: Removing unreachable block (ram,0xfffffff008196b34) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081968a0) */

undefined8
FUN_fffffff008196468
          (long param_1,long *param_2,long param_3,long param_4,long param_5,long param_6,
          long param_7)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ulong uVar4;
  long *plVar5;
  ulong uVar6;
  uint uVar7;
  long lVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  long *plVar15;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  code *local_1b0;
  undefined *local_1a8;
  undefined8 *local_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  byte local_171;
  long local_170;
  long lStack_168;
  long lStack_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
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
  local_f0 = 0;
  uStack_d8 = 0;
  uStack_e0 = 0;
  lVar14 = param_2[0x20];
  thunk_EXT_FUN_8011000002946f14(&local_b0);
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x11164) & 1) == 0) {
    puVar10 = (undefined8 *)0x0;
  }
  else {
    puVar10 = &local_f0;
    thunk_EXT_FUN_8011000002946f14(&local_f0);
  }
  FUN_fffffff00818ac24
            (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),*(undefined4 *)(param_5 + 0xb4),
             *(undefined4 *)(param_5 + 0xb8));
  FUN_fffffff00818add4
            (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),*(undefined4 *)(param_5 + 200),
             &local_b0,puVar10,lVar14);
  lVar8 = *(long *)(param_1 + 0x530);
  if ((*(byte *)(lVar8 + 0x1ac45) & 1) != 0) {
    FUN_fffffff0081a0304(*(undefined8 *)(lVar8 + 0x148),0x80b,param_1 + 0x4d8,lVar14);
    lVar8 = *(long *)(param_1 + 0x530);
  }
  thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar8 + 0x148),param_1 + 0x4d8,&local_b0);
  if (puVar10 == (undefined8 *)0x0) {
    FUN_fffffff00818c0d0(param_1,param_5,1,&local_b0,0,lVar14);
    puVar9 = (undefined8 *)0x0;
  }
  else {
    thunk_EXT_FUN_80110000029486ac
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x4d8,puVar10);
    FUN_fffffff00818c0d0(param_1,param_5,1,&local_b0,puVar10,lVar14);
    puVar9 = puVar10;
  }
  uVar4 = FUN_fffffff008197128(param_1,param_7,&local_b0,puVar9,lVar14);
  if ((uVar4 & 1) == 0) {
    (**(code **)(*param_2 + 0x28))(param_2);
    uVar7 = 0x10;
    goto LAB_fffffff008196ab8;
  }
  thunk_EXT_FUN_80110000029486ac
            (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x5d0,&local_b0);
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
    FUN_fffffff0081a0304
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),0x81b,param_1 + 0x5d0,lVar14);
  }
  if (puVar10 != (undefined8 *)0x0) {
    thunk_EXT_FUN_80110000029486ac
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x5d0,puVar10);
  }
  thunk_EXT_FUN_8011000002969c30(param_2,*(undefined8 *)(param_1 + 0x518));
  (**(code **)(*param_2 + 0xd8))(param_2,*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8));
  lVar8 = FUN_fffffff00818c3bc(param_1,&local_b0,1);
  *(long *)(param_1 + 0x818) = lVar8;
  if (lVar8 == 0) {
LAB_fffffff008196a6c:
    (**(code **)(*param_2 + 0x28))(param_2);
LAB_fffffff008196a84:
    uVar7 = 8;
LAB_fffffff008196ab8:
    *(uint *)(param_1 + 0x520) = uVar7;
    return 0;
  }
  *(undefined8 *)(param_1 + 0x800) = 0;
  plVar15 = *(long **)(lVar8 + 0x220);
  *(long **)(param_1 + 0x808) = plVar15;
  if ((*(byte *)(param_6 + 8) & 1) == 0) goto LAB_fffffff008197050;
  uStack_128 = *(undefined8 *)(param_6 + 0x68);
  local_130 = *(undefined8 *)(param_6 + 0x60);
  uStack_118 = *(undefined8 *)(param_6 + 0x78);
  uStack_120 = *(undefined8 *)(param_6 + 0x70);
  uStack_108 = *(undefined8 *)(param_6 + 0x88);
  local_110 = *(undefined8 *)(param_6 + 0x80);
  local_100 = *(undefined8 *)(param_6 + 0x90);
  lStack_168 = *(long *)(param_6 + 0x28);
  local_170 = *(long *)(param_6 + 0x20);
  local_158 = *(undefined8 *)(param_6 + 0x38);
  lStack_160 = *(long *)(param_6 + 0x30);
  uStack_148 = *(undefined8 *)(param_6 + 0x48);
  local_150 = *(undefined8 *)(param_6 + 0x40);
  uStack_138 = *(undefined8 *)(param_6 + 0x58);
  uStack_140 = *(undefined8 *)(param_6 + 0x50);
  local_171 = 0;
  uVar4 = FUN_fffffff0081854b4(plVar15,param_2,&local_170,0,&local_171);
  if ((uVar4 & 1) == 0) {
    (**(code **)(*param_2 + 0x28))(param_2);
    uVar7 = local_171 | 0x203;
    goto LAB_fffffff008196ab8;
  }
  lVar8 = plVar15[0x10];
  if (lVar8 != 0) {
    uVar11 = *(undefined8 *)(lVar8 + 0x38);
    lVar8 = *(long *)(lVar8 + 0x50);
    local_1c0 = PTR_DAT_fffffff007ca5f90;
    uStack_1b8 = DAT_fffffff007113e50;
    local_1b0 = FUN_fffffff0081d4434;
    local_1a0 = &local_b0;
    local_1a8 = &DAT_fffffff007c97620;
    thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(lVar8 + 0x10));
    FUN_fffffff0081d40e8(lVar8,&local_1c0,uVar11);
    thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar8 + 0x10));
  }
  if (((*(byte *)(param_1 + 0x7f6) & 1) == 0) && (*(int *)(param_7 + 0x8c) != 0)) {
    plVar5 = (long *)thunk_EXT_FUN_8011000002c150fc(*(undefined8 *)(param_1 + 0x530));
    if (*(int *)(param_7 + 0x8c) != 0) {
      uVar4 = 0;
      do {
        puVar9 = (undefined8 *)(*(ulong *)(param_7 + 0x80) + uVar4 * 0x10);
        if (((*(ulong *)(param_7 + 0x80) ^ (ulong)puVar9) & 0xffc0000000000000) != 0) {
          puVar9 = (undefined8 *)((ulong)puVar9 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar6 = thunk_EXT_FUN_8011000002969b54(param_2,*puVar9,*(undefined4 *)(puVar9 + 1),plVar5);
        if ((uVar6 & 1) == 0) {
          (**(code **)(*param_2 + 0x28))(param_2);
          *(undefined4 *)(param_1 + 0x520) = 0x110;
          if (plVar5 != (long *)0x0) {
            (**(code **)(*plVar5 + 0x28))(plVar5);
            return 0;
          }
          return 0;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(param_7 + 0x8c));
    }
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  if ((*(byte *)(param_1 + 0x7e9) >> (ulong)(*(uint *)(*(long *)(param_1 + 0x818) + 0xe8) & 0x1f) &
      1) != 0) {
    param_3 = 0;
  }
  param_2[0x104] = param_3;
  param_2[0x105] = param_4;
  if (*(char *)(param_1 + 0x7e9) == '\0') {
    thunk_EXT_FUN_801100000294849c
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x768,param_1 + 0x6a8);
    thunk_EXT_FUN_8011000002946f14(param_1 + 0x768);
  }
  lVar8 = *(long *)(param_1 + 0x530);
  if (((*(byte *)(lVar8 + 0x11180) & 1) != 0) &&
     ((*(byte *)(param_1 + 0x7e9) >> (ulong)(*(uint *)(*(long *)(param_1 + 0x818) + 0xe8) & 0x1f) &
      1) == 0)) {
    if ((*(byte *)(lVar8 + 0x1ac45) & 1) != 0) {
      FUN_fffffff0081a0304(*(undefined8 *)(lVar8 + 0x148),0x80c,param_1 + 0x6a8,lVar14);
      lVar8 = *(long *)(param_1 + 0x530);
    }
    thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar8 + 0x148),param_1 + 0x6a8,&local_b0);
  }
  thunk_EXT_FUN_801100000294166c(*(undefined8 *)(param_1 + 0x808),*(undefined8 *)(param_1 + 0x488));
  uVar3 = (**(code **)(*plVar15 + 0x128))(*plVar15 + 0x128,plVar15);
  *(undefined4 *)((long)param_2 + 0x34c) = uVar3;
  param_2[0x3f] = (long)plVar15;
  if ((*(byte *)(param_6 + 8) & 1) == 0) goto LAB_fffffff008197050;
  if ((*(byte *)(param_6 + 0x10) & 1) != 0) {
    uVar11 = thunk_EXT_FUN_8011000003a49114
                       ("AGXk: %s:%d:%s: !!! Assertion failed: %s: invalid state!\n");
    return uVar11;
  }
  *(undefined1 *)(param_6 + 0x10) = 1;
  lVar8 = *(long *)(param_6 + 0x18);
  *(undefined4 *)((long)param_2 + 0x814) = *(undefined4 *)(lVar8 + 0x3f0);
  *(byte *)(param_2 + 0x102) = *(byte *)(lVar8 + 0x3f4) & 1;
  param_2[0x103] = *(long *)(lVar8 + 0x3f8);
  *(byte *)((long)param_2 + 0x835) = *(byte *)(lVar8 + 0x400) & 1;
  *(undefined1 *)((long)param_2 + 0x8f1) = *(undefined1 *)(lVar8 + 0x402);
  param_2[0x11c] = *(long *)(lVar8 + 0x410);
  param_2[0x11d] = *(long *)(lVar8 + 0x418);
  FUN_fffffff0081dfb54(param_2);
  *(undefined1 *)(param_2 + 0xff) = 1;
  lVar8 = *(long *)(param_6 + 0x18);
  param_2[0x100] = *(long *)(lVar8 + 1000);
  *(byte *)(param_2 + 0x101) = *(byte *)(lVar8 + 0x484) & 1;
  if ((*(byte *)(param_6 + 8) & 1) == 0) goto LAB_fffffff008197050;
  param_2[0x93] = *(long *)(param_6 + 0xfc);
  *(undefined4 *)(param_2 + 0x94) = *(undefined4 *)(param_6 + 0x104);
  param_2[0xf7] = local_170;
  *(undefined8 *)((long)param_2 + 0x7c4) = local_158;
  *(undefined4 *)((long)param_2 + 0x7cc) = local_150._4_4_;
  param_2[0xfb] = lStack_160;
  param_2[0xfa] = lStack_168;
  *(byte *)((long)param_2 + 0x83b) = *(byte *)(param_6 + 0x108) & 1;
  *(byte *)((long)param_2 + 0xac9) = *(byte *)(param_2[2] + 0x109b1) & 1;
  (**(code **)(*param_2 + 0xf0))(param_2,*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa0));
  if ((*(byte *)(param_6 + 8) & 1) == 0) goto LAB_fffffff008197050;
  uVar4 = FUN_fffffff0081e8ff0
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x111e8),
                     *(undefined8 *)(param_1 + 0x488),*(undefined8 *)(param_7 + 0x50),param_6 + 0x98
                     ,param_2 + 0x146,param_2 + 0x147,param_2);
  if ((uVar4 & 1) == 0) goto LAB_fffffff008196a84;
  if ((*(byte *)(param_5 + 8) & 1) == 0) goto LAB_fffffff008197050;
  if (*(int *)(param_5 + 0xa4) != 0) {
    if (*(int *)(param_5 + 0x158) != 0 || *(int *)(param_5 + 0x15c) != 0) {
      uVar4 = FUN_fffffff008195510
                        (param_1,param_7,param_2,param_2 + 0x148,*(int *)(param_5 + 0x158),
                         *(int *)(param_5 + 0x15c),*(undefined8 *)(param_5 + 0x168));
      if ((uVar4 & 1) == 0) goto LAB_fffffff008196a84;
      if ((*(byte *)(param_5 + 8) & 1) == 0) goto LAB_fffffff008197050;
    }
  }
  if (*(int *)(*(long *)(*(long *)(param_1 + 0x610) + 200) + 0x28) != 0) {
    (**(code **)(*param_2 + 0x88))(param_2);
    goto LAB_fffffff008196a6c;
  }
  *(byte *)(param_2 + 0x69) = (byte)(*(uint *)(*(long *)(param_1 + 0x530) + 0x5c8) >> 0xf) & 1;
  (**(code **)(**(long **)(param_1 + 0x808) + 0xa0))();
  plVar5 = *(long **)(param_1 + 0x808);
  plVar5[5] = *(long *)(param_1 + 0x410);
  uVar11 = (**(code **)(*param_2 + 0x108))(*param_2 + 0x108,param_2);
  (**(code **)(*plVar5 + 0xa8))(plVar5,0,uVar11);
  *(undefined4 *)((long)param_2 + 0x8f4) = *(undefined4 *)(*(long *)(param_1 + 0x808) + 0x18);
  thunk_EXT_FUN_801100000296a27c(param_2);
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
    uStack_198 = 0;
    local_1a0 = (undefined8 *)0x0;
    uStack_188 = 0;
    uStack_190 = 0;
    uStack_1b8 = 0;
    local_1c0 = (undefined *)0x0;
    local_1a8 = (undefined *)0x0;
    local_1b0 = (code *)0x0;
    thunk_EXT_FUN_8011000002946f14(&local_1c0);
    (**(code **)(**(long **)(param_1 + 0x808) + 0x98))(*(long **)(param_1 + 0x808),&local_1c0);
    lVar8 = *(long *)(*(long *)(*(long *)(param_1 + 0x530) + 0x148) + 0x10);
    if ((*(byte *)(lVar8 + 0x1ac45) & 1) != 0) {
      uVar2 = local_1c0._4_4_;
      uVar3 = *(undefined4 *)(*(long *)(param_1 + 0x818) + 0xe8);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85982024,uVar2,uVar3,lVar14,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x1ac48));
    }
  }
  if ((*(byte *)(param_5 + 8) & 1) == 0) {
LAB_fffffff008197050:
    uVar11 = thunk_EXT_FUN_8011000003a49114
                       ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
    return uVar11;
  }
  if (*(int *)(param_5 + 0xa0) != 0) {
    FUN_fffffff008195bb8(param_1,param_5,*(undefined8 *)(param_1 + 0x808),8,param_2 + 0x120);
  }
  if (puVar10 != (undefined8 *)0x0) {
    thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(plVar15[2] + 0x148),plVar15 + 0x23,puVar10);
  }
  thunk_EXT_FUN_801100000296a2e0(param_2,&local_b0);
  thunk_EXT_FUN_801100000294849c
            (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),&local_b0,param_2 + 0x49);
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
    FUN_fffffff0081a0304(*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),0x806,&local_b0,lVar14)
    ;
  }
  FUN_fffffff00818af98
            (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),*(undefined4 *)(param_5 + 200),
             param_2 + 0x10,puVar10,lVar14);
  FUN_fffffff00818ac24
            (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),*(undefined4 *)(param_5 + 0xbc),
             *(undefined4 *)(param_5 + 0xc0));
  FUN_fffffff00818d240(param_1,param_5,3,param_2 + 0x10,puVar10);
  thunk_EXT_FUN_8011000002969708(param_2,*(undefined8 *)(param_7 + 0x70));
  lVar14 = *(long *)(param_7 + 0x28);
  uVar4 = *(ulong *)(lVar14 + 0x20);
  if (uVar4 == 0) {
    uVar4 = *(ulong *)(*(long *)(param_7 + 0x20) + 0x20);
    if (uVar4 == 0) goto LAB_fffffff008196f1c;
    plVar5 = (long *)(*(long *)(param_7 + 0x20) + 0x18);
    if (puVar10 == (undefined8 *)0x0) goto LAB_fffffff008196ee0;
  }
  else {
    if (puVar10 == (undefined8 *)0x0) {
      uVar6 = 0;
      uVar13 = 1;
      do {
        lVar8 = *(long *)(*(long *)(lVar14 + 0x18) + uVar6 * 8);
        thunk_EXT_FUN_8011000002951168(lVar8,0,0);
        thunk_EXT_FUN_8011000002950f84(lVar8,*(undefined8 *)(param_1 + 0x808),1);
        thunk_EXT_FUN_8011000002969884(param_2,*(undefined8 *)(lVar8 + 0x28));
        bVar1 = uVar13 < uVar4;
        uVar6 = uVar13;
        uVar13 = (ulong)((int)uVar13 + 1);
      } while (bVar1);
      uVar4 = *(ulong *)(*(long *)(param_7 + 0x20) + 0x20);
      if (uVar4 == 0) goto LAB_fffffff008196f1c;
      plVar5 = (long *)(*(long *)(param_7 + 0x20) + 0x18);
LAB_fffffff008196ee0:
      uVar6 = 0;
      uVar13 = 1;
      do {
        lVar14 = *(long *)(*plVar5 + uVar6 * 8);
        thunk_EXT_FUN_8011000002950f84(lVar14,*(undefined8 *)(param_1 + 0x808),0);
        thunk_EXT_FUN_8011000002969884(param_2,*(undefined8 *)(lVar14 + 0x28));
        bVar1 = uVar13 < uVar4;
        uVar6 = uVar13;
        uVar13 = (ulong)((int)uVar13 + 1);
      } while (bVar1);
      goto LAB_fffffff008196f1c;
    }
    uVar6 = 0;
    uVar13 = 1;
    do {
      lVar12 = *(long *)(*(long *)(lVar14 + 0x18) + uVar6 * 8);
      thunk_EXT_FUN_8011000002951168(lVar12,0,0);
      thunk_EXT_FUN_8011000002950f84(lVar12,*(undefined8 *)(param_1 + 0x808),1);
      uVar11 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
      lVar8 = thunk_EXT_FUN_801100000295198c(lVar12);
      thunk_EXT_FUN_80110000029486ac(uVar11,puVar10,lVar8 + 0x100);
      uVar11 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
      lVar8 = thunk_EXT_FUN_801100000295198c(lVar12);
      thunk_EXT_FUN_80110000029486ac(uVar11,puVar10,lVar8 + 0x140);
      thunk_EXT_FUN_8011000002969884(param_2,*(undefined8 *)(lVar12 + 0x28));
      bVar1 = uVar13 < uVar4;
      uVar6 = uVar13;
      uVar13 = (ulong)((int)uVar13 + 1);
    } while (bVar1);
    uVar4 = *(ulong *)(*(long *)(param_7 + 0x20) + 0x20);
    if (uVar4 == 0) goto LAB_fffffff008196f1c;
    plVar5 = (long *)(*(long *)(param_7 + 0x20) + 0x18);
  }
  uVar6 = 0;
  uVar13 = 1;
  do {
    lVar8 = *(long *)(*plVar5 + uVar6 * 8);
    thunk_EXT_FUN_8011000002950f84(lVar8,*(undefined8 *)(param_1 + 0x808),0);
    uVar11 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
    lVar14 = thunk_EXT_FUN_801100000295198c(lVar8);
    thunk_EXT_FUN_80110000029486ac(uVar11,puVar10,lVar14 + 0x100);
    thunk_EXT_FUN_8011000002969884(param_2,*(undefined8 *)(lVar8 + 0x28));
    bVar1 = uVar13 < uVar4;
    uVar6 = uVar13;
    uVar13 = (ulong)((int)uVar13 + 1);
  } while (bVar1);
LAB_fffffff008196f1c:
  lVar14 = *(long *)(param_7 + 0x48);
  uVar4 = *(ulong *)(lVar14 + 0x20);
  if (uVar4 != 0) {
    uVar6 = 0;
    uVar13 = 1;
    do {
      thunk_EXT_FUN_8011000002969884
                (param_2,*(undefined8 *)(*(long *)(*(long *)(lVar14 + 0x18) + uVar6 * 8) + 0x28));
      bVar1 = uVar13 < uVar4;
      uVar6 = uVar13;
      uVar13 = (ulong)((int)uVar13 + 1);
    } while (bVar1);
  }
  lVar14 = plVar15[0x10];
  if (lVar14 != 0) {
    lVar8 = thunk_EXT_FUN_8011000003890f30(plVar15,*(undefined8 *)PTR_DAT_fffffff007ca5fb8);
    uVar11 = *(undefined8 *)(lVar14 + 0x38);
    lVar14 = *(long *)(lVar14 + 0x50);
    local_1c0 = PTR_DAT_fffffff007ca5f90;
    uStack_1b8 = DAT_fffffff007113e50;
    local_1b0 = FUN_fffffff0081d446c;
    local_1a8 = &DAT_fffffff007c97640;
    local_1a0 = (undefined8 *)CONCAT44(local_1a0._4_4_,*(undefined4 *)(lVar8 + 0x18));
    thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(lVar14 + 0x10));
    FUN_fffffff0081d40e8(lVar14,&local_1c0,uVar11);
    thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar14 + 0x10));
  }
  if (puVar10 != (undefined8 *)0x0) {
    thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(plVar15[2] + 0x148),puVar10,plVar15 + 0x23);
  }
  return 1;
}

