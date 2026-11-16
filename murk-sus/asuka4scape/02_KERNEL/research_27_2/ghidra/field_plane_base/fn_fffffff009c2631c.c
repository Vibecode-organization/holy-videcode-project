// FUN_fffffff009c2631c @ fffffff009c2631c

/* WARNING: Removing unreachable block (ram,0xfffffff009c26380) */

void FUN_fffffff009c2631c(long param_1,uint param_2)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined4 local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  if ((~param_2 & 0x3fffff) == 0) {
    thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0x50));
    lVar2 = *(long *)(param_1 + 0x178);
    *(undefined4 *)(lVar2 + 0xb4) = 0;
    *(undefined8 *)(lVar2 + 0xac) = 0;
    *(undefined8 *)(lVar2 + 0xa4) = 0;
    *(undefined8 *)(lVar2 + 0x9c) = 0;
    *(undefined8 *)(lVar2 + 0x94) = 0;
    *(undefined8 *)(lVar2 + 0x8c) = 0;
    *(undefined8 *)(lVar2 + 0x84) = 0;
    *(undefined8 *)(lVar2 + 0x7c) = 0;
    *(undefined8 *)(lVar2 + 0x74) = 0;
    *(undefined8 *)(lVar2 + 0x6c) = 0;
    *(undefined8 *)(lVar2 + 100) = 0;
    *(undefined8 *)(lVar2 + 0x5c) = 0;
    *(undefined8 *)(lVar2 + 0x54) = 0;
    *(undefined8 *)(lVar2 + 0x4c) = 0;
    *(undefined8 *)(lVar2 + 0x44) = 0;
    *(undefined8 *)(lVar2 + 0x3c) = 0;
    *(undefined8 *)(lVar2 + 0x34) = 0;
    if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0x50));
        return;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c263e4);
      (*pcVar1)();
    }
  }
  else {
    local_30 = 0;
    uStack_48 = 0;
    local_50 = 0;
    uStack_38 = 0;
    uStack_40 = 0;
    uStack_68 = 0;
    local_70 = 0;
    uStack_58 = 0;
    uStack_60 = 0;
    uStack_88 = 0;
    local_90 = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    uStack_a8 = 0;
    local_b0 = 0;
    uStack_98 = 0;
    uStack_a0 = 0;
    FUN_fffffff009c25e38(param_1,&local_b0,param_2);
    if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

