// FUN_fffffff00a47d620 @ fffffff00a47d620 size=1048

void FUN_fffffff00a47d620(long param_1,uint param_2,undefined8 *param_3,uint param_4)

{
  long lVar1;
  ulong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  ushort uVar8;
  ushort uVar9;
  long lVar10;
  undefined8 *puVar11;
  undefined2 local_d4;
  ushort local_d2;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined2 local_b8;
  undefined2 uStack_b6;
  char cStack_b4;
  char cStack_b3;
  undefined2 uStack_b2;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  char cStack_a4;
  char cStack_a3;
  undefined2 uStack_a2;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  uint uStack_94;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined6 uStack_70;
  undefined2 uStack_6a;
  undefined6 local_68;
  undefined2 uStack_62;
  undefined6 uStack_60;
  undefined2 uStack_5a;
  undefined6 local_58;
  undefined2 uStack_52;
  undefined6 uStack_50;
  ushort uStack_4a;
  long local_48;
  
  local_48 = DAT_fffffff00acf0000;
  uStack_50 = 0;
  uStack_4a = 0;
  local_58 = 0;
  uStack_52 = 0;
  uStack_60 = 0;
  uStack_5a = 0;
  local_68 = 0;
  uStack_62 = 0;
  uStack_70 = 0;
  uStack_6a = 0;
  local_78 = 0;
  uStack_80 = 0;
  local_88 = 0;
  uStack_90 = 0;
  local_98 = 0;
  uStack_94 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  local_a8 = 0;
  cStack_a4 = '\0';
  cStack_a3 = '\0';
  uStack_a2 = 0;
  uStack_b0 = 0;
  uStack_ac = 0;
  local_b8 = 0;
  uStack_b6 = 0;
  cStack_b4 = '\0';
  cStack_b3 = '\0';
  uStack_b2 = 0;
  if (param_2 < 0x10000) {
    local_d4 = (undefined2)param_2;
    local_d0 = (undefined4)DAT_fffffff00ad3ccc0;
    uStack_cc = DAT_fffffff00ad3ccc8;
    if (((param_4 & 0x220) != 0) || (uVar8 = 0x40, (param_4 & 7) == 0)) {
      uVar9 = 0x40;
      if ((param_4 & 0x20) != 0) {
        uVar9 = 0x240;
      }
      uVar9 = uVar9 | (ushort)((param_4 >> 9 & 1) << 0xd);
      uVar8 = uVar9 | 0x80;
      if ((param_4 & 7) != 0) {
        uVar8 = uVar9;
      }
    }
    uStack_c0 = param_3[1];
    local_c8 = *param_3;
    if (*(char *)(param_3 + 10) == '\x06') {
      uVar9 = 4;
    }
    else {
      if (*(char *)(param_3 + 10) != '\x11') {
        FUN_fffffff00a89f3b0
                  (&MACH_HEADER,DAT_fffffff00ad55348,0,"%s: unexpected protocol %u for nfi %p");
        uVar6 = 0;
        goto LAB_fffffff00a47d9e0;
      }
      uVar9 = 8;
    }
    if (*(char *)((long)param_3 + 0x19) == '\x02') {
      local_d2 = uVar8 | uVar9 | 1;
      local_b8 = *(undefined2 *)((long)param_3 + 0x1a);
      uStack_b6 = *(undefined2 *)((long)param_3 + 0x36);
      uVar3 = *(undefined4 *)((long)param_3 + 0x1c);
      uVar4 = *(undefined4 *)(param_3 + 7);
      cStack_b4 = (char)uVar3;
      cStack_b3 = (char)((uint)uVar3 >> 8);
      uStack_b2 = (undefined2)((uint)uVar3 >> 0x10);
      cStack_a4 = (char)uVar4;
      cStack_a3 = (char)((uint)uVar4 >> 8);
      uStack_a2 = (undefined2)((uint)uVar4 >> 0x10);
    }
    else {
      local_d2 = uVar8 | uVar9 | 2;
      local_b8 = *(undefined2 *)((long)param_3 + 0x1a);
      uStack_b6 = *(undefined2 *)((long)param_3 + 0x36);
      uVar6 = param_3[4];
      uStack_ac = (undefined4)param_3[5];
      local_a8 = (undefined4)((ulong)param_3[5] >> 0x20);
      cStack_b4 = (char)uVar6;
      cStack_b3 = (char)((ulong)uVar6 >> 8);
      uStack_b2 = (undefined2)((ulong)uVar6 >> 0x10);
      uStack_b0 = (undefined4)((ulong)uVar6 >> 0x20);
      uVar6 = *(undefined8 *)((long)param_3 + 0x3c);
      uStack_9c = (undefined4)*(undefined8 *)((long)param_3 + 0x44);
      local_98 = (undefined4)((ulong)*(undefined8 *)((long)param_3 + 0x44) >> 0x20);
      cStack_a4 = (char)uVar6;
      cStack_a3 = (char)((ulong)uVar6 >> 8);
      uStack_a2 = (undefined2)((ulong)uVar6 >> 0x10);
      uStack_a0 = (undefined4)((ulong)uVar6 >> 0x20);
      if ((cStack_b4 == -2) && (cStack_b3 < -0x40)) {
        uStack_b2 = 0;
      }
      if ((cStack_a4 == -2) && (cStack_a3 < -0x40)) {
        uStack_a2 = 0;
      }
    }
    uStack_94 = *(uint *)((long)param_3 + 0x54);
    lVar1 = (long)&uStack_90 + 4;
    uVar7 = FUN_fffffff00a1954a0((long)param_3 + 0x5c,0x11);
    uVar2 = uVar7;
    if (0x10 < uVar7) {
      uVar2 = 0x11;
    }
    if (0xf < uVar7) {
      uVar7 = 0x10;
    }
    FUN_fffffff00aa24d30(lVar1,(long)param_3 + 0x5c,uVar2);
    *(undefined1 *)(lVar1 + uVar7) = 0;
    FUN_fffffff00a1ebed8(&DAT_fffffff00ad8b5d8);
    puVar11 = (undefined8 *)&uStack_6a;
    if (uStack_94 != 0) {
      for (lVar10 = *(long *)(DAT_fffffff00ad8b5f8 + (ulong)(uStack_94 % 0x1f) * 0x10); lVar10 != 0;
          lVar10 = *(long *)(lVar10 + 0x18)) {
        if (*(uint *)(lVar10 + 0x6c) == uStack_94) {
          if ((*(ushort *)(lVar10 + 0xb6) & 1) != 0) {
            uStack_4a = uStack_4a | 1;
          }
          uStack_62 = (undefined2)*(undefined8 *)(lVar10 + 0x9e);
          uStack_60 = (undefined6)((ulong)*(undefined8 *)(lVar10 + 0x9e) >> 0x10);
          uStack_6a = (undefined2)*(undefined8 *)(lVar10 + 0x96);
          local_68 = (undefined6)((ulong)*(undefined8 *)(lVar10 + 0x96) >> 0x10);
          iVar5 = FUN_fffffff00a1eca88(&DAT_fffffff00ad8b5d8);
          if (iVar5 != 1) goto LAB_fffffff00a47da14;
          goto LAB_fffffff00a47d93c;
        }
      }
    }
    iVar5 = FUN_fffffff00a1eca88(&DAT_fffffff00ad8b5d8);
    if (iVar5 != 1) {
LAB_fffffff00a47da14:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa0c4f8("lck_rw_unlock_shared(): lock %p held in mode: %d @%s:%d");
    }
    lVar10 = FUN_fffffff00a6e4f94(uStack_94);
    if (lVar10 != 0) {
      uStack_62 = (undefined2)*(undefined8 *)(lVar10 + 0x5a0);
      uStack_60 = (undefined6)((ulong)*(undefined8 *)(lVar10 + 0x5a0) >> 0x10);
      uStack_6a = (undefined2)*(undefined8 *)(lVar10 + 0x598);
      local_68 = (undefined6)((ulong)*(undefined8 *)(lVar10 + 0x598) >> 0x10);
      iVar5 = FUN_fffffff00a6acd88();
      if (iVar5 != 0) {
        uStack_4a = uStack_4a | 1;
      }
      FUN_fffffff00a6e5260(lVar10);
    }
LAB_fffffff00a47d93c:
    if (*(int *)(param_3 + 0xb) == -1) {
      uStack_90 = CONCAT44(uStack_90._4_4_,uStack_94);
      uVar7 = FUN_fffffff00a1954a0(lVar1,0x11);
      uVar2 = uVar7;
      if (0x10 < uVar7) {
        uVar2 = 0x11;
      }
      if (0xf < uVar7) {
        uVar7 = 0x10;
      }
      FUN_fffffff00aa24d30((long)&uStack_80 + 5,lVar1,uVar2);
      *(undefined1 *)((long)&uStack_80 + 5 + uVar7) = 0;
    }
    else {
      uStack_90 = CONCAT44(uStack_90._4_4_,*(int *)(param_3 + 0xb));
      uVar7 = FUN_fffffff00a1954a0((long)param_3 + 0x6d,0x11);
      uVar2 = uVar7;
      if (0x10 < uVar7) {
        uVar2 = 0x11;
      }
      if (0xf < uVar7) {
        uVar7 = 0x10;
      }
      FUN_fffffff00aa24d30((long)&uStack_80 + 5,(long)param_3 + 0x6d,uVar2);
      *(undefined1 *)((long)&uStack_80 + 5 + uVar7) = 0;
      puVar11 = (undefined8 *)(param_1 + 0x100);
    }
    uStack_52 = (undefined2)puVar11[1];
    uStack_50 = (undefined6)((ulong)puVar11[1] >> 0x10);
    uStack_5a = (undefined2)*puVar11;
    local_58 = (undefined6)((ulong)*puVar11 >> 0x10);
    uVar6 = FUN_fffffff00a47cef0(&local_d4);
  }
  else {
    FUN_fffffff00a89f3b0(&MACH_HEADER,DAT_fffffff00ad55348,0,"%s: ifindex %u too big");
    uVar6 = 0;
  }
LAB_fffffff00a47d9e0:
  if (DAT_fffffff00acf0000 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa0b974(uVar6);
}

