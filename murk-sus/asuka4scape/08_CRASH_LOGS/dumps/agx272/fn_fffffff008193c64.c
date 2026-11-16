// FUN_fffffff008193c64 @ fffffff008193c64 size=4616

/* WARNING: Removing unreachable block (ram,0xfffffff0081941ac) */

undefined8
FUN_fffffff008193c64
          (long param_1,long *param_2,long param_3,long param_4,int *param_5,long param_6,
          long param_7,long param_8)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ulong uVar5;
  long *plVar6;
  ulong uVar7;
  long lVar8;
  undefined4 *puVar9;
  code *pcVar10;
  undefined8 *puVar11;
  uint uVar12;
  long lVar13;
  long *plVar14;
  long *plVar15;
  undefined8 uVar16;
  ulong uVar17;
  long lVar18;
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
  long local_158;
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
  ulong local_100;
  long local_f0;
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
  
  lVar18 = param_2[0x20];
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
  thunk_EXT_FUN_8011000002946f14(&local_b0);
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x11164) & 1) == 0) {
    plVar14 = (long *)0x0;
  }
  else {
    plVar14 = &local_f0;
    thunk_EXT_FUN_8011000002946f14(&local_f0);
  }
  FUN_fffffff00818ac24
            (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),*(undefined4 *)(param_4 + 0xb4),
             *(undefined4 *)(param_4 + 0xb8));
  FUN_fffffff00818add4
            (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),*(undefined4 *)(param_4 + 0xc4),
             &local_b0,plVar14,lVar18);
  lVar8 = *(long *)(param_1 + 0x530);
  if ((*(byte *)(lVar8 + 0x1ac45) & 1) != 0) {
    FUN_fffffff0081a0304(*(undefined8 *)(lVar8 + 0x148),0x80b,param_1 + 0x4d8,lVar18);
    lVar8 = *(long *)(param_1 + 0x530);
  }
  thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar8 + 0x148),param_1 + 0x4d8,&local_b0);
  if (plVar14 == (long *)0x0) {
    FUN_fffffff00818c0d0(param_1,param_4,0,&local_b0,0,lVar18);
    plVar15 = (long *)0x0;
  }
  else {
    thunk_EXT_FUN_80110000029486ac
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x4d8,plVar14);
    FUN_fffffff00818c0d0(param_1,param_4,0,&local_b0,plVar14,lVar18);
    plVar15 = plVar14;
  }
  uVar5 = FUN_fffffff008194e6c(param_1,param_3,&local_b0,plVar15,lVar18);
  if ((uVar5 & 1) == 0) {
    (**(code **)(*param_2 + 0x28))(param_2);
    uVar12 = 0x10;
    goto LAB_fffffff008194460;
  }
  thunk_EXT_FUN_80110000029486ac
            (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x5d0,&local_b0);
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
    FUN_fffffff0081a0304
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),0x81b,param_1 + 0x5d0,lVar18);
  }
  if (plVar14 == (long *)0x0) {
    plVar15 = (long *)0x0;
  }
  else {
    thunk_EXT_FUN_80110000029486ac
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x5d0,plVar14);
    plVar15 = plVar14;
  }
  FUN_fffffff0081953d4(param_1,param_5,param_2,&local_b0,plVar15,lVar18);
  if (((*(byte *)(*(long *)(param_6 + 0x18) + 0x259) & 1) != 0) &&
     (thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498,&local_b0),
     plVar14 != (long *)0x0)) {
    thunk_EXT_FUN_80110000029486ac
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x628,plVar14);
  }
  thunk_EXT_FUN_8011000002969c30(param_2,*(undefined8 *)(param_1 + 0x518));
  (**(code **)(*param_2 + 0xd8))(param_2,*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8));
  lVar8 = FUN_fffffff00818cd38(param_1,&local_b0);
  *(long *)(param_1 + 0x820) = lVar8;
  if (lVar8 == 0) {
    pcVar10 = *(code **)(*param_2 + 0x28);
LAB_fffffff00819444c:
    (*pcVar10)(param_2);
LAB_fffffff008194458:
    uVar12 = 8;
LAB_fffffff008194460:
    *(uint *)(param_1 + 0x520) = uVar12;
    return 0;
  }
  plVar15 = *(long **)(lVar8 + 0x218);
  *(long **)(param_1 + 0x810) = plVar15;
  if ((*(byte *)(param_6 + 8) & 1) == 0) goto LAB_fffffff008194d5c;
  local_100 = *(ulong *)(param_6 + 0x90);
  uStack_128 = *(undefined8 *)(param_6 + 0x68);
  local_130 = *(undefined8 *)(param_6 + 0x60);
  uStack_118 = *(undefined8 *)(param_6 + 0x78);
  uStack_120 = *(undefined8 *)(param_6 + 0x70);
  uStack_108 = *(undefined8 *)(param_6 + 0x88);
  local_110 = *(undefined8 *)(param_6 + 0x80);
  lStack_168 = *(long *)(param_6 + 0x28);
  local_170 = *(long *)(param_6 + 0x20);
  local_158 = *(long *)(param_6 + 0x38);
  lStack_160 = *(long *)(param_6 + 0x30);
  uStack_148 = *(undefined8 *)(param_6 + 0x48);
  local_150 = *(undefined8 *)(param_6 + 0x40);
  uStack_138 = *(undefined8 *)(param_6 + 0x58);
  uStack_140 = *(undefined8 *)(param_6 + 0x50);
  if ((local_100 >> 0x28 & 1) == 0) {
    uVar12 = 0;
  }
  else {
    if ((*(byte *)(param_6 + 0xa4) & 1) == 0) {
      uVar12 = (uint)(*(int *)(param_1 + 0x7ec) == 2);
    }
    else {
      uVar12 = 1;
    }
    if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x10a08) & 1) != 0) {
      uVar12 = *(uint *)(*(long *)(param_1 + 0x530) + 0x10a0c) >>
               (ulong)(*(uint *)(param_1 + 0x7ec) & 0x1f);
    }
  }
  local_171 = 0;
  uVar5 = FUN_fffffff0081854b4(plVar15,param_2,&local_170,uVar12 & 1,&local_171);
  if ((uVar5 & 1) == 0) {
    (**(code **)(*param_2 + 0x28))(param_2);
    uVar12 = local_171 & 0xfc | 0x202;
    goto LAB_fffffff008194460;
  }
  lVar8 = plVar15[0x10];
  if (lVar8 != 0) {
    uVar16 = *(undefined8 *)(lVar8 + 0x38);
    lVar8 = *(long *)(lVar8 + 0x50);
    local_1c0 = PTR_DAT_fffffff007ca5f90;
    uStack_1b8 = DAT_fffffff007113e50;
    local_1b0 = FUN_fffffff0081d4434;
    local_1a0 = &local_b0;
    local_1a8 = &DAT_fffffff007c97620;
    thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(lVar8 + 0x10));
    FUN_fffffff0081d40e8(lVar8,&local_1c0,uVar16);
    thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar8 + 0x10));
  }
  if (*(long *)(param_1 + 0x850) != 0) {
    param_2[0x2c] = *(long *)(param_1 + 0x850);
  }
  if (((*(byte *)(param_1 + 0x7f6) & 1) == 0) && (*(int *)(param_3 + 0x8c) != 0)) {
    plVar6 = (long *)thunk_EXT_FUN_8011000002c150fc(*(undefined8 *)(param_1 + 0x530));
    if (*(int *)(param_3 + 0x8c) != 0) {
      uVar5 = 0;
      do {
        puVar11 = (undefined8 *)(*(ulong *)(param_3 + 0x80) + uVar5 * 0x10);
        if (((*(ulong *)(param_3 + 0x80) ^ (ulong)puVar11) & 0xffc0000000000000) != 0) {
          puVar11 = (undefined8 *)((ulong)puVar11 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar7 = thunk_EXT_FUN_8011000002969b54(param_2,*puVar11,*(undefined4 *)(puVar11 + 1),plVar6)
        ;
        if ((uVar7 & 1) == 0) {
          (**(code **)(*param_2 + 0x28))(param_2);
          *(undefined4 *)(param_1 + 0x520) = 0x110;
          if (plVar6 == (long *)0x0) {
            return 0;
          }
          (**(code **)(*plVar6 + 0x28))(plVar6);
          return 0;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_3 + 0x8c));
    }
    if (plVar6 != (long *)0x0) {
      (**(code **)(*plVar6 + 0x28))(plVar6);
    }
  }
  if ((*(byte *)(param_1 + 0x7ea) >> (ulong)(*(uint *)(*(long *)(param_1 + 0x820) + 0xe8) & 0x1f) &
      1) != 0) {
    param_7 = 0;
  }
  param_2[0x43] = param_7;
  param_2[0x44] = param_8;
  if (*(char *)(param_1 + 0x7ea) == '\0') {
    thunk_EXT_FUN_801100000294849c
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x7a8,param_1 + 0x6e8);
    thunk_EXT_FUN_8011000002946f14(param_1 + 0x7a8);
  }
  lVar8 = *(long *)(param_1 + 0x530);
  if (((*(byte *)(lVar8 + 0x11180) & 1) != 0) &&
     ((*(byte *)(param_1 + 0x7ea) >> (ulong)(*(uint *)(*(long *)(param_1 + 0x820) + 0xe8) & 0x1f) &
      1) == 0)) {
    if ((*(byte *)(lVar8 + 0x1ac45) & 1) != 0) {
      FUN_fffffff0081a0304(*(undefined8 *)(lVar8 + 0x148),0x80c,param_1 + 0x6e8,lVar18);
      lVar8 = *(long *)(param_1 + 0x530);
    }
    thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar8 + 0x148),param_1 + 0x6e8,&local_b0);
  }
  if (param_5 != (int *)0x0) {
    iVar2 = *param_5;
    *(int *)(param_2 + 0x2e) = iVar2;
    lVar8 = *(long *)(param_5 + 2);
    param_2[0x39] = *(long *)(param_5 + 4);
    param_2[0x38] = lVar8;
    puVar9 = *(undefined4 **)(param_5 + 6);
    param_2[0x3a] = (long)puVar9;
    if (iVar2 == 0) {
      *puVar9 = 0;
    }
  }
  thunk_EXT_FUN_801100000294166c(*(undefined8 *)(param_1 + 0x810),*(undefined8 *)(param_1 + 0x488));
  uVar4 = (**(code **)(*plVar15 + 0x128))(*plVar15 + 0x128,plVar15);
  *(undefined4 *)(param_2 + 0x6a) = uVar4;
  param_2[0x3f] = (long)plVar15;
  if ((*(byte *)(param_6 + 8) & 1) == 0) goto LAB_fffffff008194d5c;
  if ((*(byte *)(param_6 + 0x10) & 1) != 0) {
    uVar16 = thunk_EXT_FUN_8011000003a49114
                       ("AGXk: %s:%d:%s: !!! Assertion failed: %s: invalid state!\n");
    return uVar16;
  }
  *(undefined1 *)(param_6 + 0x10) = 1;
  plVar6 = *(long **)(param_6 + 0x18);
  param_2[0x95] = *plVar6;
  param_2[0x96] = plVar6[1];
  param_2[0x97] = plVar6[2];
  param_2[0x9a] = plVar6[5];
  param_2[0x9b] = plVar6[6];
  param_2[0x9c] = plVar6[7];
  param_2[0x9d] = plVar6[8];
  param_2[0x9e] = plVar6[9];
  param_2[0x9f] = plVar6[10];
  lVar8 = plVar6[0xb];
  param_2[0xa1] = plVar6[0xc];
  param_2[0xa0] = lVar8;
  param_2[0xa2] = plVar6[0xe];
  param_2[0xa3] = plVar6[0xf];
  param_2[0xa4] = plVar6[0x10];
  param_2[0xa5] = plVar6[0x11];
  lVar8 = plVar6[3];
  param_2[0x99] = plVar6[4];
  param_2[0x98] = lVar8;
  *(byte *)(param_2 + 0xad) = *(byte *)((long)plVar6 + 0x1fc) & 1;
  *(byte *)((long)param_2 + 0x56a) = *(byte *)((long)plVar6 + 0x255) & 1;
  param_2[0xae] = plVar6[0x16];
  *(char *)((long)param_2 + 0x5da) = (char)plVar6[0x1b];
  *(int *)((long)param_2 + 0x534) = (int)plVar6[0x19];
  *(byte *)(param_2 + 0xa6) = *(byte *)((long)plVar6 + 0xcc) & 1;
  param_2[0xa7] = plVar6[0x1a];
  lVar8 = plVar6[0x40];
  param_2[0xb2] = plVar6[0x41];
  param_2[0xb1] = lVar8;
  lVar8 = plVar6[0x42];
  param_2[0xb4] = plVar6[0x43];
  param_2[0xb3] = lVar8;
  lVar8 = plVar6[0x44];
  param_2[0xb6] = plVar6[0x45];
  param_2[0xb5] = lVar8;
  lVar8 = plVar6[0x46];
  param_2[0xb8] = plVar6[0x47];
  param_2[0xb7] = lVar8;
  param_2[0xb9] = plVar6[0x48];
  *(int *)(param_2 + 0xba) = (int)plVar6[0x49];
  *(byte *)((long)param_2 + 0x5db) = *(byte *)((long)plVar6 + 0x251) & 1;
  param_2[0xaf] = plVar6[0x13];
  param_2[0xb0] = plVar6[0x14];
  *(byte *)((long)param_2 + 0x5dc) = *(byte *)((long)plVar6 + 0x252) & 1;
  *(byte *)((long)param_2 + 0x5dd) = *(byte *)((long)plVar6 + 0x253) & 1;
  *(byte *)(param_2 + 0xe2) = *(byte *)((long)plVar6 + 0x254) & 1;
  *(byte *)(param_2 + 0xe7) = *(byte *)((long)plVar6 + 0x256) & 1;
  *(byte *)((long)param_2 + 0x739) = *(byte *)(plVar6 + 0x4b) & 1;
  *(int *)((long)param_2 + 0x714) = (int)plVar6[0x15];
  *(byte *)((long)param_2 + 0x5d9) = *(byte *)((long)plVar6 + 599) & 1;
  *(int *)(param_2 + 0x8c) = (int)plVar6[0x4d];
  *(int *)((long)param_2 + 0x73c) = (int)plVar6[0x17];
  param_2[0xe8] = plVar6[0x18];
  param_2[0xa8] = local_170;
  param_2[0xa9] = local_158;
  *(undefined4 *)(param_2 + 0xaa) = local_150._4_4_;
  param_2[0xac] = lStack_160;
  param_2[0xab] = lStack_168;
  *(byte *)((long)param_2 + 0x569) = (byte)uVar12 & 1;
  param_2[0xea] = 0;
  param_2[0xe9] = 0;
  if ((*(byte *)(param_6 + 8) & 1) == 0) goto LAB_fffffff008194d5c;
  uVar5 = FUN_fffffff0081e8ff0
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x111e8),
                     *(undefined8 *)(param_1 + 0x488),*(undefined8 *)(param_3 + 0x50),param_6 + 0x98
                     ,param_2 + 0xe3,param_2 + 0xe4,param_2);
  if ((uVar5 & 1) == 0) goto LAB_fffffff008194458;
  if ((*(byte *)(param_4 + 8) & 1) == 0) goto LAB_fffffff008194d5c;
  if (*(int *)(param_4 + 0xa4) != 0) {
    if (*(int *)(param_4 + 0x150) != 0 || *(int *)(param_4 + 0x154) != 0) {
      uVar5 = FUN_fffffff008195510
                        (param_1,param_3,param_2,param_2 + 0xe5,*(int *)(param_4 + 0x150),
                         *(int *)(param_4 + 0x154),*(undefined8 *)(param_4 + 0x160));
      if ((uVar5 & 1) == 0) goto LAB_fffffff008194458;
      if ((*(byte *)(param_4 + 8) & 1) == 0) goto LAB_fffffff008194d5c;
    }
  }
  if (*(int *)(*(long *)(*(long *)(param_1 + 0x610) + 200) + 0x28) != 0) {
    (**(code **)(*param_2 + 0x88))(param_2);
    pcVar10 = *(code **)(*param_2 + 0x28);
    goto LAB_fffffff00819444c;
  }
  *(undefined1 *)(param_2 + 0x68) = 0;
  (**(code **)(**(long **)(param_1 + 0x810) + 0xa0))();
  plVar6 = *(long **)(param_1 + 0x810);
  plVar6[5] = *(long *)(param_1 + 0x410);
  uVar16 = (**(code **)(*param_2 + 0xf0))(param_2);
  (**(code **)(*plVar6 + 0xa8))(plVar6,0,uVar16);
  *(undefined4 *)(param_2 + 0xbc) = *(undefined4 *)(*(long *)(param_1 + 0x810) + 0x18);
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
    (**(code **)(**(long **)(param_1 + 0x810) + 0x98))(*(long **)(param_1 + 0x810),&local_1c0);
    lVar8 = *(long *)(*(long *)(*(long *)(param_1 + 0x530) + 0x148) + 0x10);
    if ((*(byte *)(lVar8 + 0x1ac45) & 1) != 0) {
      uVar3 = local_1c0._4_4_;
      uVar4 = *(undefined4 *)(*(long *)(param_1 + 0x820) + 0xe8);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85982028,uVar3,uVar4,lVar18,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x1ac48));
    }
  }
  if ((param_5 != (int *)0x0) && ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0)) {
    uStack_198 = 0;
    local_1a0 = (undefined8 *)0x0;
    uStack_188 = 0;
    uStack_190 = 0;
    uStack_1b8 = 0;
    local_1c0 = (undefined *)0x0;
    local_1a8 = (undefined *)0x0;
    local_1b0 = (code *)0x0;
    thunk_EXT_FUN_8011000002946f14(&local_1c0);
    (**(code **)(**(long **)(param_1 + 0x810) + 0x98))(*(long **)(param_1 + 0x810),&local_1c0);
    lVar8 = *(long *)(*(long *)(*(long *)(param_1 + 0x530) + 0x148) + 0x10);
    if ((*(byte *)(lVar8 + 0x1ac45) & 1) != 0) {
      uVar3 = local_1c0._4_4_;
      uVar4 = *(undefined4 *)(*(long *)(param_1 + 0x820) + 0xe8);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85982048,uVar3,uVar4,lVar18,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x1ac48));
    }
  }
  if ((*(byte *)(param_4 + 8) & 1) == 0) {
LAB_fffffff008194d5c:
    uVar16 = thunk_EXT_FUN_8011000003a49114
                       ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
    return uVar16;
  }
  if (*(int *)(param_4 + 0xa0) != 0) {
    FUN_fffffff008195bb8(param_1,param_4,*(undefined8 *)(param_1 + 0x810),2,param_2 + 0xbd);
  }
  if (plVar14 != (long *)0x0) {
    thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(plVar15[2] + 0x148),plVar15 + 0x23,plVar14);
  }
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x5c9) >> 1 & 1) != 0) {
    (**(code **)(*plVar15 + 0x98))(plVar15,plVar14);
  }
  thunk_EXT_FUN_801100000296a2e0(param_2,&local_b0);
  thunk_EXT_FUN_801100000294849c
            (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),&local_b0,param_2 + 0x60);
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
    FUN_fffffff0081a0304(*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),0x806,&local_b0,lVar18)
    ;
  }
  FUN_fffffff00818af98
            (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),*(undefined4 *)(param_4 + 0xc4),
             param_2 + 0x10,plVar14,lVar18);
  FUN_fffffff00818ac24
            (*(undefined8 *)(*(long *)(param_1 + 0x610) + 0xa8),*(undefined4 *)(param_4 + 0xbc),
             *(undefined4 *)(param_4 + 0xc0));
  FUN_fffffff00818d240(param_1,param_4,2,param_2 + 0x10,plVar14);
  thunk_EXT_FUN_8011000002969708(param_2,*(undefined8 *)(param_3 + 0x70));
  lVar18 = *(long *)(param_3 + 0x18);
  uVar5 = *(ulong *)(lVar18 + 0x20);
  if (uVar5 == 0) {
    uVar5 = *(ulong *)(*(long *)(param_3 + 0x68) + 0x20);
    if (uVar5 != 0) {
      plVar6 = (long *)(*(long *)(param_3 + 0x68) + 0x18);
      if (plVar14 == (long *)0x0) goto LAB_fffffff008194958;
LAB_fffffff00819486c:
      uVar7 = 0;
      uVar17 = 1;
      do {
        lVar8 = *(long *)(*plVar6 + uVar7 * 8);
        thunk_EXT_FUN_8011000002951168(lVar8,0,0);
        thunk_EXT_FUN_8011000002950f84(lVar8,*(undefined8 *)(param_1 + 0x810),1);
        uVar16 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
        lVar18 = thunk_EXT_FUN_801100000295198c(lVar8);
        thunk_EXT_FUN_80110000029486ac(uVar16,plVar14,lVar18 + 0x100);
        uVar16 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
        lVar18 = thunk_EXT_FUN_801100000295198c(lVar8);
        thunk_EXT_FUN_80110000029486ac(uVar16,plVar14,lVar18 + 0x140);
        thunk_EXT_FUN_8011000002969884(param_2,*(undefined8 *)(lVar8 + 0x28));
        bVar1 = uVar17 < uVar5;
        uVar7 = uVar17;
        uVar17 = (ulong)((int)uVar17 + 1);
      } while (bVar1);
    }
  }
  else if (plVar14 == (long *)0x0) {
    uVar7 = 0;
    uVar17 = 1;
    do {
      lVar8 = *(long *)(*(long *)(lVar18 + 0x18) + uVar7 * 8);
      thunk_EXT_FUN_8011000002951168(lVar8,0,0);
      thunk_EXT_FUN_8011000002950f84(lVar8,*(undefined8 *)(param_1 + 0x810),1);
      thunk_EXT_FUN_8011000002969884(param_2,*(undefined8 *)(lVar8 + 0x28));
      bVar1 = uVar17 < uVar5;
      uVar7 = uVar17;
      uVar17 = (ulong)((int)uVar17 + 1);
    } while (bVar1);
    uVar5 = *(ulong *)(*(long *)(param_3 + 0x68) + 0x20);
    if (uVar5 != 0) {
      plVar6 = (long *)(*(long *)(param_3 + 0x68) + 0x18);
LAB_fffffff008194958:
      uVar7 = 0;
      uVar17 = 1;
      do {
        lVar18 = *(long *)(*plVar6 + uVar7 * 8);
        thunk_EXT_FUN_8011000002951168(lVar18,0,0);
        thunk_EXT_FUN_8011000002950f84(lVar18,*(undefined8 *)(param_1 + 0x810),1);
        thunk_EXT_FUN_8011000002969884(param_2,*(undefined8 *)(lVar18 + 0x28));
        bVar1 = uVar17 < uVar5;
        uVar7 = uVar17;
        uVar17 = (ulong)((int)uVar17 + 1);
      } while (bVar1);
    }
  }
  else {
    uVar7 = 0;
    uVar17 = 1;
    do {
      lVar13 = *(long *)(*(long *)(lVar18 + 0x18) + uVar7 * 8);
      thunk_EXT_FUN_8011000002951168(lVar13,0,0);
      thunk_EXT_FUN_8011000002950f84(lVar13,*(undefined8 *)(param_1 + 0x810),1);
      uVar16 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
      lVar8 = thunk_EXT_FUN_801100000295198c(lVar13);
      thunk_EXT_FUN_80110000029486ac(uVar16,plVar14,lVar8 + 0x100);
      uVar16 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
      lVar8 = thunk_EXT_FUN_801100000295198c(lVar13);
      thunk_EXT_FUN_80110000029486ac(uVar16,plVar14,lVar8 + 0x140);
      thunk_EXT_FUN_8011000002969884(param_2,*(undefined8 *)(lVar13 + 0x28));
      bVar1 = uVar17 < uVar5;
      uVar7 = uVar17;
      uVar17 = (ulong)((int)uVar17 + 1);
    } while (bVar1);
    uVar5 = *(ulong *)(*(long *)(param_3 + 0x68) + 0x20);
    if (uVar5 != 0) {
      plVar6 = (long *)(*(long *)(param_3 + 0x68) + 0x18);
      goto LAB_fffffff00819486c;
    }
  }
  lVar18 = *(long *)(param_3 + 0x10);
  uVar5 = *(ulong *)(lVar18 + 0x20);
  if (uVar5 == 0) {
    uVar5 = *(ulong *)(*(long *)(param_3 + 0x60) + 0x20);
    if (uVar5 == 0) goto LAB_fffffff008194b28;
    plVar6 = (long *)(*(long *)(param_3 + 0x60) + 0x18);
    if (plVar14 == (long *)0x0) goto LAB_fffffff008194aec;
  }
  else {
    if (plVar14 == (long *)0x0) {
      uVar7 = 0;
      uVar17 = 1;
      do {
        lVar8 = *(long *)(*(long *)(lVar18 + 0x18) + uVar7 * 8);
        thunk_EXT_FUN_8011000002950f84(lVar8,*(undefined8 *)(param_1 + 0x810),0);
        thunk_EXT_FUN_8011000002969884(param_2,*(undefined8 *)(lVar8 + 0x28));
        bVar1 = uVar17 < uVar5;
        uVar7 = uVar17;
        uVar17 = (ulong)((int)uVar17 + 1);
      } while (bVar1);
      uVar5 = *(ulong *)(*(long *)(param_3 + 0x60) + 0x20);
      if (uVar5 == 0) goto LAB_fffffff008194b28;
      plVar6 = (long *)(*(long *)(param_3 + 0x60) + 0x18);
LAB_fffffff008194aec:
      uVar7 = 0;
      uVar17 = 1;
      do {
        lVar18 = *(long *)(*plVar6 + uVar7 * 8);
        thunk_EXT_FUN_8011000002950f84(lVar18,*(undefined8 *)(param_1 + 0x810),0);
        thunk_EXT_FUN_8011000002969884(param_2,*(undefined8 *)(lVar18 + 0x28));
        bVar1 = uVar17 < uVar5;
        uVar7 = uVar17;
        uVar17 = (ulong)((int)uVar17 + 1);
      } while (bVar1);
      goto LAB_fffffff008194b28;
    }
    uVar7 = 0;
    uVar17 = 1;
    do {
      lVar13 = *(long *)(*(long *)(lVar18 + 0x18) + uVar7 * 8);
      thunk_EXT_FUN_8011000002950f84(lVar13,*(undefined8 *)(param_1 + 0x810),0);
      uVar16 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
      lVar8 = thunk_EXT_FUN_801100000295198c(lVar13);
      thunk_EXT_FUN_80110000029486ac(uVar16,plVar14,lVar8 + 0x100);
      thunk_EXT_FUN_8011000002969884(param_2,*(undefined8 *)(lVar13 + 0x28));
      bVar1 = uVar17 < uVar5;
      uVar7 = uVar17;
      uVar17 = (ulong)((int)uVar17 + 1);
    } while (bVar1);
    uVar5 = *(ulong *)(*(long *)(param_3 + 0x60) + 0x20);
    if (uVar5 == 0) goto LAB_fffffff008194b28;
    plVar6 = (long *)(*(long *)(param_3 + 0x60) + 0x18);
  }
  uVar7 = 0;
  uVar17 = 1;
  do {
    lVar8 = *(long *)(*plVar6 + uVar7 * 8);
    thunk_EXT_FUN_8011000002950f84(lVar8,*(undefined8 *)(param_1 + 0x810),0);
    uVar16 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
    lVar18 = thunk_EXT_FUN_801100000295198c(lVar8);
    thunk_EXT_FUN_80110000029486ac(uVar16,plVar14,lVar18 + 0x100);
    thunk_EXT_FUN_8011000002969884(param_2,*(undefined8 *)(lVar8 + 0x28));
    bVar1 = uVar17 < uVar5;
    uVar7 = uVar17;
    uVar17 = (ulong)((int)uVar17 + 1);
  } while (bVar1);
LAB_fffffff008194b28:
  lVar18 = *(long *)(param_3 + 0x48);
  uVar5 = *(ulong *)(lVar18 + 0x20);
  if (uVar5 != 0) {
    uVar7 = 0;
    uVar17 = 1;
    do {
      thunk_EXT_FUN_8011000002969884
                (param_2,*(undefined8 *)(*(long *)(*(long *)(lVar18 + 0x18) + uVar7 * 8) + 0x28));
      bVar1 = uVar17 < uVar5;
      uVar7 = uVar17;
      uVar17 = (ulong)((int)uVar17 + 1);
    } while (bVar1);
  }
  lVar18 = plVar15[0x10];
  if (lVar18 != 0) {
    lVar8 = thunk_EXT_FUN_8011000003890f30(plVar15,*(undefined8 *)PTR_DAT_fffffff007ca5fb8);
    uVar16 = *(undefined8 *)(lVar18 + 0x38);
    lVar18 = *(long *)(lVar18 + 0x50);
    local_1c0 = PTR_DAT_fffffff007ca5f90;
    uStack_1b8 = DAT_fffffff007113e50;
    local_1b0 = FUN_fffffff0081d446c;
    local_1a8 = &DAT_fffffff007c97640;
    local_1a0 = (undefined8 *)CONCAT44(local_1a0._4_4_,*(undefined4 *)(lVar8 + 0x18));
    thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(lVar18 + 0x10));
    FUN_fffffff0081d40e8(lVar18,&local_1c0,uVar16);
    thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar18 + 0x10));
  }
  if (plVar14 == (long *)0x0) {
    if (param_5 == (int *)0x0) {
      return 1;
    }
    if (3 < *param_5) {
      return 1;
    }
    lVar18 = plVar15[3];
    thunk_EXT_FUN_8011000002946f14(param_1 + 0x858);
    thunk_EXT_FUN_80110000029486ac
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_2 + 0x10,param_1 + 0x858);
    *(int *)(param_1 + 0x8d8) = (int)lVar18;
    if ((*(byte *)(param_5 + 1) & 1) == 0) {
      return 1;
    }
    thunk_EXT_FUN_8011000002946f14(*(long *)(param_1 + 0x850) + 0x60);
    uVar16 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
    plVar14 = param_2 + 0x10;
    lVar18 = *(long *)(param_1 + 0x850) + 0x60;
  }
  else {
    thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(plVar15[2] + 0x148),plVar14,plVar15 + 0x23);
    if (param_5 == (int *)0x0) {
      return 1;
    }
    if (3 < *param_5) {
      return 1;
    }
    lVar18 = plVar15[3];
    thunk_EXT_FUN_8011000002946f14(param_1 + 0x858);
    thunk_EXT_FUN_80110000029486ac
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_2 + 0x10,param_1 + 0x858);
    thunk_EXT_FUN_8011000002946f14(param_1 + 0x898);
    thunk_EXT_FUN_80110000029486ac
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),plVar14,param_1 + 0x898);
    *(int *)(param_1 + 0x8d8) = (int)lVar18;
    if ((*(byte *)(param_5 + 1) & 1) == 0) {
      return 1;
    }
    thunk_EXT_FUN_8011000002946f14(*(long *)(param_1 + 0x850) + 0x60);
    thunk_EXT_FUN_80110000029486ac
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_2 + 0x10,
               *(long *)(param_1 + 0x850) + 0x60);
    thunk_EXT_FUN_8011000002946f14(*(long *)(param_1 + 0x850) + 0xa0);
    uVar16 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
    lVar18 = *(long *)(param_1 + 0x850) + 0xa0;
  }
  thunk_EXT_FUN_80110000029486ac(uVar16,plVar14,lVar18);
  return 1;
}

