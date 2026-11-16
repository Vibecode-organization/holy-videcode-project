// FUN_fffffff00a4b9d84 @ fffffff00a4b9d84 size=1148

void FUN_fffffff00a4b9d84(ulong param_1,long param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  ushort uVar7;
  undefined4 uVar8;
  ushort uVar9;
  long lVar10;
  undefined8 uVar11;
  ulong uVar12;
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
  
  local_38 = DAT_fffffff00ad30000;
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
    FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad95428,0,"%s: ifindex %u too big");
    uVar4 = 0;
    goto LAB_fffffff00a4ba1ac;
  }
  lVar10 = *(long *)(param_2 + 0x40);
  if ((uint)param_1 == 0) {
    if (*(long *)(param_2 + 0xb8) != 0) {
      param_1 = (ulong)*(ushort *)(*(long *)(param_2 + 0xb8) + 0xcc);
      goto LAB_fffffff00a4b9e14;
    }
  }
  else {
LAB_fffffff00a4b9e14:
    local_d0 = param_1 & 0xffff;
  }
  uVar12 = local_d0;
  uVar8 = (undefined4)DAT_fffffff00ad7cd80;
  local_d0 = CONCAT44(uVar8,(undefined4)local_d0);
  uStack_c8 = DAT_fffffff00ad7cd88;
  uVar7 = 0x20;
  if ((*(byte *)(lVar10 + 0x12) & 1) != 0) {
    uVar7 = 0x220;
  }
  if (*(short *)(lVar10 + 6) == 0x11) {
    uVar9 = 8;
  }
  else {
    if (*(short *)(lVar10 + 6) != 6) {
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad95428,0,"%s: unexpected protocol %u for inp %p");
      uVar4 = 0;
      goto LAB_fffffff00a4ba1ac;
    }
    uVar9 = 4;
    if ((*(long *)(param_2 + 0x30) != 0) &&
       (uVar9 = 0x84, *(int *)(*(long *)(param_2 + 0x30) + 0xc) != 1)) {
      uVar9 = 4;
    }
  }
  uVar9 = uVar7 | (ushort)(*(uint *)(param_2 + 0x94) >> 10) & 0x2000 | uVar9;
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
      local_d0 = CONCAT44(uVar8,CONCAT22(uVar9,(undefined2)local_d0)) | 0x20000;
      uStack_a8 = *(undefined8 *)(param_2 + 0xdc);
      uVar6 = *(ulong *)(param_2 + 0xd4);
      uStack_98 = *(undefined8 *)(param_2 + 0xcc);
      uVar12 = *(ulong *)(param_2 + 0xc4);
      local_b0._0_1_ = (char)uVar6;
      local_b0._1_1_ = (byte)(uVar6 >> 8);
      if ((char)local_b0 == -1) {
        if (((local_b0._1_1_ & 0xf) == 1) ||
           ((local_b0._1_1_ & 0xf0) != 0x30 && (local_b0._1_1_ & 0xf) == 2))
        goto LAB_fffffff00a4b9f88;
      }
      else if (((char)local_b0 == -2) && ((char)local_b0._1_1_ < -0x40)) {
LAB_fffffff00a4b9f88:
        local_b0._4_4_ = (undefined4)(uVar6 >> 0x20);
        local_b0._0_4_ = (uint)(ushort)uVar6;
        uVar6 = local_b0;
      }
      local_b0 = uVar6;
      local_a0._0_1_ = (char)uVar12;
      local_a0._1_1_ = (byte)(uVar12 >> 8);
      if ((char)local_a0 == -1) {
        if (((local_a0._1_1_ & 0xf) == 1) ||
           ((local_a0._1_1_ & 0xf0) != 0x30 && (local_a0._1_1_ & 0xf) == 2))
        goto LAB_fffffff00a4b9fd4;
      }
      else if (((char)local_a0 == -2) && ((char)local_a0._1_1_ < -0x40)) {
LAB_fffffff00a4b9fd4:
        local_a0._4_4_ = (undefined4)(uVar12 >> 0x20);
        local_a0._0_4_ = (uint)(ushort)uVar12;
        uVar12 = local_a0;
      }
    }
    else {
      local_d0 = CONCAT44(uVar8,CONCAT22(uVar9,(undefined2)local_d0)) | 0x10000;
      local_b0 = (ulong)*(uint *)(param_2 + 0xe0);
      local_a0 = (ulong)*(uint *)(param_2 + 0xd0);
      uVar12 = local_a0;
    }
  }
  else {
    local_d0 = CONCAT44(uVar8,CONCAT22(uVar9,(undefined2)local_d0)) | 0x30000;
    uStack_a8 = *(undefined8 *)(param_2 + 0xdc);
    local_b0 = *(ulong *)(param_2 + 0xd4);
    uVar12 = local_a0;
  }
  local_a0 = uVar12;
  local_90 = (ulong)*(uint *)(lVar10 + 0x21c);
  if (*(uint *)(lVar10 + 0x21c) != 0) {
    uStack_88 = 0;
    uStack_80 = 0;
    local_78 = 0;
    lVar5 = FUN_fffffff00a72456c();
    if (lVar5 != 0) {
      FUN_fffffff00a354958(&uStack_88,lVar5 + 0x55c,0x11);
      FUN_fffffff00a724838(lVar5);
    }
    uStack_5e = (undefined6)*(undefined8 *)(lVar10 + 0x35c);
    uStack_58 = (undefined2)((ulong)*(undefined8 *)(lVar10 + 0x35c) >> 0x30);
    uStack_66 = (undefined6)*(undefined8 *)(lVar10 + 0x354);
    uStack_60 = (undefined2)((ulong)*(undefined8 *)(lVar10 + 0x354) >> 0x30);
    FUN_fffffff00a228180(&DAT_fffffff00adcb5d8);
    uVar1 = *(uint *)(lVar10 + 0x21c);
    if (uVar1 != 0) {
      for (lVar5 = *(long *)(DAT_fffffff00adcb5f8 + (ulong)(uVar1 % 0x1f) * 0x10); lVar5 != 0;
          lVar5 = *(long *)(lVar5 + 0x18)) {
        if (*(uint *)(lVar5 + 0x6c) == uVar1) {
          if ((*(ushort *)(lVar5 + 0xb6) & 1) != 0) {
            uStack_46 = uStack_46 | 1;
          }
          iVar3 = FUN_fffffff00a228d30(&DAT_fffffff00adcb5d8);
          if (iVar3 == 1) goto LAB_fffffff00a4ba0f4;
          goto LAB_fffffff00a4ba1dc;
        }
      }
    }
    iVar3 = FUN_fffffff00a228d30(&DAT_fffffff00adcb5d8);
    if (iVar3 != 1) {
LAB_fffffff00a4ba1dc:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114("lck_rw_unlock_shared(): lock %p held in mode: %d @%s:%d");
    }
    lVar5 = FUN_fffffff00a72456c(*(undefined4 *)(lVar10 + 0x21c));
    if (lVar5 != 0) {
      iVar3 = FUN_fffffff00a6ec3c0();
      if (iVar3 != 0) {
        uStack_46 = uStack_46 | 1;
      }
      FUN_fffffff00a724838(lVar5);
    }
  }
LAB_fffffff00a4ba0f4:
  if ((*(byte *)(lVar10 + 0x233) >> 4 & 1) == 0) {
    local_90 = CONCAT44(*(int *)(lVar10 + 0x21c),(undefined4)local_90);
    if (*(int *)(lVar10 + 0x21c) != 0) {
      uVar6 = FUN_fffffff00a1d14a0(&uStack_88,0x11);
      uVar12 = uVar6;
      if (0x10 < uVar6) {
        uVar12 = 0x11;
      }
      if (0xf < uVar6) {
        uVar6 = 0x10;
      }
      FUN_fffffff00aa65b10(&local_77,&uStack_88,uVar12);
      *(undefined1 *)((long)&local_77 + uVar6) = 0;
    }
    lVar5 = 0x354;
  }
  else {
    local_d0 = local_d0 | 0x100000;
    local_90 = CONCAT44(*(int *)(lVar10 + 0x344),(undefined4)local_90);
    if (*(int *)(lVar10 + 0x344) != 0) {
      uStack_6f = 0;
      uStack_68 = 0;
      local_77 = 0;
      uStack_70 = 0;
      uStack_67 = 0;
      lVar5 = FUN_fffffff00a72456c();
      if (lVar5 != 0) {
        FUN_fffffff00a354958(&local_77,lVar5 + 0x55c,0x11);
        FUN_fffffff00a724838(lVar5);
      }
    }
    lVar5 = 0x364;
  }
  uVar11 = ((undefined8 *)(lVar10 + lVar5))[1];
  uVar4 = *(undefined8 *)(lVar10 + lVar5);
  uStack_4e = (undefined2)uVar11;
  uStack_4c = (undefined6)((ulong)uVar11 >> 0x10);
  uStack_56 = (undefined2)uVar4;
  local_54 = (undefined4)((ulong)uVar4 >> 0x10);
  uStack_50 = (undefined2)((ulong)uVar4 >> 0x30);
  uVar4 = FUN_fffffff00a4ba200(&local_d0);
LAB_fffffff00a4ba1ac:
  if (DAT_fffffff00ad30000 != local_38) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4c590(uVar4);
  }
  return;
}

