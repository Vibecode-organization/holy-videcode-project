// FUN_fffffff00a47cad4 @ fffffff00a47cad4 size=1052

void FUN_fffffff00a47cad4(ulong param_1,long param_2)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  ushort uVar8;
  undefined4 uVar9;
  ushort uVar10;
  long lVar11;
  ulong uVar12;
  undefined8 uVar13;
  undefined8 local_d0;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  uint local_b4;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined1 local_78;
  undefined7 local_77;
  undefined1 uStack_70;
  undefined7 uStack_6f;
  undefined1 uStack_68;
  undefined1 uStack_67;
  undefined6 uStack_66;
  undefined2 uStack_60;
  undefined6 uStack_5e;
  undefined2 uStack_58;
  undefined2 uStack_56;
  undefined4 local_54;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  undefined6 uStack_4c;
  ushort uStack_46;
  long local_38;
  
  local_38 = DAT_fffffff00acf0000;
  uStack_4c = 0;
  uStack_46 = 0;
  uStack_50 = 0;
  uStack_4e = 0;
  uStack_68 = 0;
  uStack_67 = 0;
  uStack_66 = 0;
  uStack_70 = 0;
  uStack_6f = 0;
  uStack_58 = 0;
  uStack_56 = 0;
  local_54 = 0;
  uStack_60 = 0;
  uStack_5e = 0;
  uStack_88 = 0;
  local_90 = 0;
  local_78 = 0;
  local_77 = 0;
  uStack_80 = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_c8 = 0;
  uStack_c4 = 0;
  local_d0 = 0;
  uStack_b8 = 0;
  local_b4 = 0;
  uStack_c0 = 0;
  uStack_bc = 0;
  if (0xffff < (uint)param_1) {
    FUN_fffffff00a89f3b0(&MACH_HEADER,DAT_fffffff00ad55348,0,"%s: ifindex %u too big");
    uVar5 = 0;
    goto LAB_fffffff00a47ce9c;
  }
  lVar11 = *(long *)(param_2 + 0x40);
  if ((uint)param_1 == 0) {
    if (*(long *)(param_2 + 0xb8) != 0) {
      param_1 = (ulong)*(ushort *)(*(long *)(param_2 + 0xb8) + 0xcc);
      goto LAB_fffffff00a47cb64;
    }
  }
  else {
LAB_fffffff00a47cb64:
    local_d0 = param_1 & 0xffff;
  }
  uVar12 = local_d0;
  uVar9 = (undefined4)DAT_fffffff00ad3ccc0;
  local_d0 = CONCAT44(uVar9,(undefined4)local_d0);
  uStack_c8 = DAT_fffffff00ad3ccc8;
  uVar8 = 0x20;
  if ((*(byte *)(lVar11 + 0x12) & 1) != 0) {
    uVar8 = 0x220;
  }
  if (*(short *)(lVar11 + 6) == 0x11) {
    uVar10 = 8;
  }
  else {
    if (*(short *)(lVar11 + 6) != 6) {
      FUN_fffffff00a89f3b0
                (&MACH_HEADER,DAT_fffffff00ad55348,0,"%s: unexpected protocol %u for inp %p");
      uVar5 = 0;
      goto LAB_fffffff00a47ce9c;
    }
    uVar10 = 4;
    if ((*(long *)(param_2 + 0x30) != 0) &&
       (uVar10 = 0x84, *(int *)(*(long *)(param_2 + 0x30) + 0xc) != 1)) {
      uVar10 = 4;
    }
  }
  uVar10 = uVar8 | (ushort)(*(uint *)(param_2 + 0x94) >> 10) & 0x2000 | uVar10;
  uStack_bc = (undefined4)*(undefined8 *)(param_2 + 0x1d8);
  uStack_b8 = (undefined4)((ulong)*(undefined8 *)(param_2 + 0x1d8) >> 0x20);
  uStack_c4 = (undefined4)*(undefined8 *)(param_2 + 0x1d0);
  uStack_c0 = (undefined4)((ulong)*(undefined8 *)(param_2 + 0x1d0) >> 0x20);
  local_b4 = *(uint *)(param_2 + 0x8c) >> 0x10 | *(uint *)(param_2 + 0x8c) << 0x10;
  bVar2 = *(byte *)(param_2 + 0xad);
  local_d0._0_2_ = (undefined2)uVar12;
  if ((((bVar2 >> 1 & 1) == 0) || (((bVar2 ^ 0xff) & 3) != 0)) ||
     ((*(uint *)(param_2 + 0x90) >> 0xf & 1) != 0)) {
    if ((bVar2 & 1) == 0) {
      local_d0 = CONCAT44(uVar9,CONCAT22(uVar10,(undefined2)local_d0)) | 0x20000;
      uStack_a8 = *(undefined8 *)(param_2 + 0xdc);
      uVar12 = *(ulong *)(param_2 + 0xd4);
      uStack_98 = *(undefined8 *)(param_2 + 0xcc);
      uVar7 = *(ulong *)(param_2 + 0xc4);
      local_b0._0_1_ = (char)uVar12;
      bVar3 = (char)local_b0 == -2;
      local_b0 = uVar12;
      if ((bVar3) && (local_b0._1_1_ = (char)(uVar12 >> 8), bVar3 = local_b0._1_1_ < -0x40, bVar3))
      {
        local_b0._4_4_ = (undefined4)(uVar12 >> 0x20);
        local_b0._0_4_ = (uint)(ushort)uVar12;
      }
      local_a0._0_1_ = (char)uVar7;
      bVar3 = (char)local_a0 == -2;
      local_a0 = uVar7;
      if ((bVar3) && (local_a0._1_1_ = (char)(uVar7 >> 8), bVar3 = local_a0._1_1_ < -0x40, bVar3)) {
        local_a0._4_4_ = (undefined4)(uVar7 >> 0x20);
        local_a0._0_4_ = (uint)(ushort)uVar7;
      }
    }
    else {
      local_d0 = CONCAT44(uVar9,CONCAT22(uVar10,(undefined2)local_d0)) | 0x10000;
      local_b0 = (ulong)*(uint *)(param_2 + 0xe0);
      local_a0 = (ulong)*(uint *)(param_2 + 0xd0);
    }
  }
  else {
    local_d0 = CONCAT44(uVar9,CONCAT22(uVar10,(undefined2)local_d0)) | 0x30000;
    uStack_a8 = *(undefined8 *)(param_2 + 0xdc);
    local_b0 = *(ulong *)(param_2 + 0xd4);
  }
  local_90 = (ulong)*(uint *)(lVar11 + 0x21c);
  if (*(uint *)(lVar11 + 0x21c) != 0) {
    uStack_88 = 0;
    uStack_80 = 0;
    local_78 = 0;
    lVar6 = FUN_fffffff00a6e4f94();
    if (lVar6 != 0) {
      FUN_fffffff00a317dd0(&uStack_88,lVar6 + 0x55c,0x11);
      FUN_fffffff00a6e5260(lVar6);
    }
    uStack_5e = (undefined6)*(undefined8 *)(lVar11 + 0x35c);
    uStack_58 = (undefined2)((ulong)*(undefined8 *)(lVar11 + 0x35c) >> 0x30);
    uStack_66 = (undefined6)*(undefined8 *)(lVar11 + 0x354);
    uStack_60 = (undefined2)((ulong)*(undefined8 *)(lVar11 + 0x354) >> 0x30);
    FUN_fffffff00a1ebed8(&DAT_fffffff00ad8b5d8);
    uVar1 = *(uint *)(lVar11 + 0x21c);
    if (uVar1 != 0) {
      for (lVar6 = *(long *)(DAT_fffffff00ad8b5f8 + (ulong)(uVar1 % 0x1f) * 0x10); lVar6 != 0;
          lVar6 = *(long *)(lVar6 + 0x18)) {
        if (*(uint *)(lVar6 + 0x6c) == uVar1) {
          if ((*(ushort *)(lVar6 + 0xb6) & 1) != 0) {
            uStack_46 = uStack_46 | 1;
          }
          iVar4 = FUN_fffffff00a1eca88(&DAT_fffffff00ad8b5d8);
          if (iVar4 != 1) goto LAB_fffffff00a47cecc;
          goto LAB_fffffff00a47cde4;
        }
      }
    }
    iVar4 = FUN_fffffff00a1eca88(&DAT_fffffff00ad8b5d8);
    if (iVar4 != 1) {
LAB_fffffff00a47cecc:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa0c4f8("lck_rw_unlock_shared(): lock %p held in mode: %d @%s:%d");
    }
    lVar6 = FUN_fffffff00a6e4f94(*(undefined4 *)(lVar11 + 0x21c));
    if (lVar6 != 0) {
      iVar4 = FUN_fffffff00a6acd88();
      if (iVar4 != 0) {
        uStack_46 = uStack_46 | 1;
      }
      FUN_fffffff00a6e5260(lVar6);
    }
  }
LAB_fffffff00a47cde4:
  if ((*(byte *)(lVar11 + 0x233) >> 4 & 1) == 0) {
    local_90 = CONCAT44(*(int *)(lVar11 + 0x21c),(undefined4)local_90);
    if (*(int *)(lVar11 + 0x21c) != 0) {
      uVar7 = FUN_fffffff00a1954a0(&uStack_88,0x11);
      uVar12 = uVar7;
      if (0x10 < uVar7) {
        uVar12 = 0x11;
      }
      if (0xf < uVar7) {
        uVar7 = 0x10;
      }
      FUN_fffffff00aa24d30(&local_77,&uStack_88,uVar12);
      *(undefined1 *)((long)&local_77 + uVar7) = 0;
    }
    lVar6 = 0x354;
  }
  else {
    local_d0 = local_d0 | 0x100000;
    local_90 = CONCAT44(*(int *)(lVar11 + 0x344),(undefined4)local_90);
    if (*(int *)(lVar11 + 0x344) != 0) {
      uStack_6f = 0;
      uStack_68 = 0;
      local_77 = 0;
      uStack_70 = 0;
      uStack_67 = 0;
      lVar6 = FUN_fffffff00a6e4f94();
      if (lVar6 != 0) {
        FUN_fffffff00a317dd0(&local_77,lVar6 + 0x55c,0x11);
        FUN_fffffff00a6e5260(lVar6);
      }
    }
    lVar6 = 0x364;
  }
  uVar13 = ((undefined8 *)(lVar11 + lVar6))[1];
  uVar5 = *(undefined8 *)(lVar11 + lVar6);
  uStack_4e = (undefined2)uVar13;
  uStack_4c = (undefined6)((ulong)uVar13 >> 0x10);
  uStack_56 = (undefined2)uVar5;
  local_54 = (undefined4)((ulong)uVar5 >> 0x10);
  uStack_50 = (undefined2)((ulong)uVar5 >> 0x30);
  uVar5 = FUN_fffffff00a47cef0(&local_d0);
LAB_fffffff00a47ce9c:
  if (DAT_fffffff00acf0000 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa0b974(uVar5);
}

