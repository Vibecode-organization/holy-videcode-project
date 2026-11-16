// FUN_fffffff009c34a0c @ fffffff009c34a0c size=4

void FUN_fffffff009c34a0c(long param_1,undefined8 param_2,code *param_3)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  undefined1 *puStack_160;
  undefined1 *puStack_158;
  undefined1 *puStack_150;
  undefined1 *puStack_148;
  undefined1 *puStack_140;
  undefined1 *puStack_138;
  undefined1 *puStack_130;
  undefined1 *puStack_128;
  undefined1 *puStack_120;
  undefined1 *puStack_118;
  undefined1 *puStack_110;
  undefined1 *puStack_108;
  undefined1 *puStack_100;
  undefined1 *puStack_f8;
  undefined1 *puStack_f0;
  undefined1 *puStack_e8;
  undefined1 *puStack_e0;
  undefined1 *puStack_d8;
  undefined1 *puStack_d0;
  undefined1 *puStack_c8;
  undefined1 *puStack_c0;
  undefined1 *puStack_b8;
  undefined1 *puStack_b0;
  undefined1 *puStack_a8;
  undefined1 *puStack_a0;
  undefined1 *puStack_98;
  undefined1 *puStack_90;
  undefined1 *puStack_88;
  undefined1 *puStack_80;
  undefined1 *puStack_78;
  undefined1 *puStack_70;
  undefined1 *puStack_68;
  long lStack_58;
  
  lStack_58 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  for (lVar3 = *(long *)(param_1 + 0x90); lVar3 != 0; lVar3 = *(long *)(lVar3 + 0x18)) {
    if (*(long *)(lVar3 + 0x30) != 0) {
      puStack_78 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_80 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_68 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_70 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_98 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_a0 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_88 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_90 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_b8 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_c0 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_a8 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_b0 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_d8 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_e0 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_c8 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_d0 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_f8 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_100 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_e8 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_f0 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_118 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_120 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_108 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_110 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_138 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_140 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_128 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_130 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_158 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_160 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_148 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_150 = &DAT_aaaaaaaaaaaaaaaa;
      FUN_fffffff009c2a738(lVar3);
      lVar5 = *(long *)(lVar3 + 0x2f0);
      if (lVar5 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        do {
          if (iVar4 < 0x40) {
            FUN_fffffff009c41bd8(*(undefined8 *)(lVar5 + 0x10));
            lVar2 = thunk_EXT_FUN_80110000032970b4();
            if (lVar2 != 0) {
              uVar1 = thunk_EXT_FUN_8011000003720f30();
              *(undefined4 *)((long)&puStack_160 + (long)iVar4 * 4) = uVar1;
              iVar4 = iVar4 + 1;
            }
          }
          lVar5 = *(long *)(lVar5 + 0x28);
        } while (lVar5 != 0);
      }
      FUN_fffffff009c2a744(lVar3);
      (*param_3)(param_2,*(undefined8 *)(lVar3 + 0x30),*(undefined4 *)(lVar3 + 0x10),&puStack_160,
                 iVar4);
    }
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_58) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

