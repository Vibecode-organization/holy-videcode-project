// FUN_fffffff009c2631c @ fffffff009c2631c size=284

/* WARNING: Removing unreachable block (ram,0xfffffff009c26380) */

void FUN_fffffff009c2631c(long param_1,uint param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
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
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
    lVar3 = *(long *)(param_1 + 0x178);
    *(undefined4 *)(lVar3 + 0xb4) = 0;
    *(undefined8 *)(lVar3 + 0xac) = 0;
    *(undefined8 *)(lVar3 + 0xa4) = 0;
    *(undefined8 *)(lVar3 + 0x9c) = 0;
    *(undefined8 *)(lVar3 + 0x94) = 0;
    *(undefined8 *)(lVar3 + 0x8c) = 0;
    *(undefined8 *)(lVar3 + 0x84) = 0;
    *(undefined8 *)(lVar3 + 0x7c) = 0;
    *(undefined8 *)(lVar3 + 0x74) = 0;
    *(undefined8 *)(lVar3 + 0x6c) = 0;
    *(undefined8 *)(lVar3 + 100) = 0;
    *(undefined8 *)(lVar3 + 0x5c) = 0;
    *(undefined8 *)(lVar3 + 0x54) = 0;
    *(undefined8 *)(lVar3 + 0x4c) = 0;
    *(undefined8 *)(lVar3 + 0x44) = 0;
    *(undefined8 *)(lVar3 + 0x3c) = 0;
    *(undefined8 *)(lVar3 + 0x34) = 0;
    uVar2 = *(undefined8 *)(param_1 + 0x50);
    if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        thunk_EXT_FUN_8011000003222de0();
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
    uVar2 = FUN_fffffff009c25e38(param_1,&local_b0);
    if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
      return;
    }
  }
  thunk_EXT_FUN_8011000003a48590(uVar2);
  return;
}

