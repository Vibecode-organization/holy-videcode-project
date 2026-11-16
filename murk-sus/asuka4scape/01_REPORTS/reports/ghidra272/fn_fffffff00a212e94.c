// FUN_fffffff00a212e94 @ fffffff00a212e94 size=824

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a212e94(undefined8 param_1,int param_2)

{
  ushort uVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  undefined4 in_wzr;
  undefined8 *local_260;
  undefined8 uStack_258;
  undefined8 uStack_250;
  undefined8 uStack_248;
  undefined8 local_240;
  long lStack_238;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 uStack_220;
  undefined8 uStack_218;
  undefined8 local_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  long local_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 local_f8;
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
  long local_68;
  
  local_68 = DAT_fffffff00ad30000;
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
  uStack_108 = 0;
  local_110 = 0;
  local_f8 = 0;
  uStack_100 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  uStack_148 = 0;
  local_150 = 0;
  uStack_138 = 0;
  uStack_140 = 0;
  uStack_168 = 0;
  local_170 = 0;
  uStack_158 = 0;
  uStack_160 = 0;
  uStack_188 = 0;
  local_190 = 0;
  uStack_178 = 0;
  uStack_180 = 0;
  uStack_1a8 = 0;
  local_1b0 = 0;
  uStack_198 = 0;
  uStack_1a0 = 0;
  uStack_1c8 = 0;
  local_1d0 = 0;
  uStack_1b8 = 0;
  uStack_1c0 = 0;
  uStack_1e8 = 0;
  local_1f0 = 0;
  uStack_1d8 = 0;
  uStack_1e0 = 0;
  uStack_208 = 0;
  local_210 = 0;
  uStack_1f8 = 0;
  uStack_200 = 0;
  uStack_228 = 0;
  local_230 = 0;
  uStack_218 = 0;
  uStack_220 = 0;
  lStack_238 = (long)param_2;
  local_240 = 0xff000001;
  uStack_258 = _UNK_fffffff0070438a8;
  local_260 = _DAT_fffffff0070438a0;
  uStack_248 = _UNK_fffffff0070438b8;
  uStack_250 = _DAT_fffffff0070438b0;
  lVar4 = FUN_fffffff00a297e2c(4,4);
  local_260 = &local_f8;
  FUN_fffffff00a297f64(4,lVar4,0,&local_260,0x20);
  if (lVar4 != 0) {
    FUN_fffffff00aa3c2b0(&DAT_fffffff007c6b298,lVar4);
  }
  FUN_fffffff00aa3c4a8(&local_110,lVar4);
  lVar4 = tpidr_el1;
  uVar3 = (ulong)*(uint *)(lVar4 + 0x4e8);
  if (_DAT_fffffff00ad34848 != 0) {
    FUN_fffffff00a2262d4(&DAT_fffffff00ad34840,lVar4,0);
    uVar3 = _DAT_fffffff00ad34848;
  }
  _DAT_fffffff00ad34848 = uVar3;
  lVar2 = DAT_fffffff00ad34a98;
  if ((((DAT_fffffff00ad34a98 == 0) || (DAT_fffffff00ad34a98 + 1U < 2)) ||
      ((*(byte *)(DAT_fffffff00ad34a98 + 1) & 7) == 0)) ||
     (lVar5 = FUN_fffffff00a29bafc(param_1), uVar6 = local_f8,
     *(long *)(lVar5 + 0x310) == *(long *)(lVar2 + 0x48))) {
    if (DAT_fffffff00ad34848 == *(int *)(lVar4 + 0x4e8)) {
      _DAT_fffffff00ad34848 = CONCAT44(DAT_fffffff00ad34848_4,in_wzr);
    }
    else {
      FUN_fffffff00a226e08(&DAT_fffffff00ad34840,lVar4);
    }
    FUN_fffffff00aa1c310(&local_f8);
    FUN_fffffff00aa3c3b0();
    uVar6 = 5;
  }
  else {
    uStack_100 = _DAT_fffffff00ad34aa8;
    uStack_108 = DAT_fffffff00ad34aa0;
    local_110 = lVar2;
    local_f8 = DAT_fffffff00ad34ab0;
    if (DAT_fffffff007bc7030 == lVar2) {
      local_110 = FUN_fffffff00a1f45e4(lVar2);
    }
    else {
      local_110 = FUN_fffffff00a1f472c();
    }
    if (local_110 == 0) {
      local_110 = 0;
    }
    local_f8 = uVar6;
    uVar6 = FUN_fffffff00aa1c310(&DAT_fffffff00ad34ab0);
    FUN_fffffff00aa3c5d4(&local_110,uVar6);
    if (DAT_fffffff00ad34848 == *(int *)(lVar4 + 0x4e8)) {
      _DAT_fffffff00ad34848 = CONCAT44(DAT_fffffff00ad34848_4,in_wzr);
    }
    else {
      FUN_fffffff00a226e08(&DAT_fffffff00ad34840,lVar4);
    }
    uVar1 = *(ushort *)(lVar4 + 200);
    *(ushort *)(lVar4 + 200) = uVar1 & 0xfffc;
    uVar6 = FUN_fffffff00a211aa8(param_1,9,&local_240,2,&local_230,&DAT_fffffff00ad34840);
    *(ushort *)(lVar4 + 200) = *(ushort *)(lVar4 + 200) & 0xfffc | uVar1 & 3;
    FUN_fffffff00aa1c310(&local_f8);
    FUN_fffffff00aa3c3b0();
    local_f8 = 0;
    lVar4 = local_110;
    if (local_110 == 0) {
      lVar4 = 0;
    }
    FUN_fffffff00a1f4ae8(lVar4);
  }
  if (DAT_fffffff00ad30000 != local_68) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4c590(uVar6);
  }
  return;
}

