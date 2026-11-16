// FUN_fffffff00819233c @ fffffff00819233c size=4176

/* WARNING: Removing unreachable block (ram,0xfffffff0081928c4) */

void FUN_fffffff00819233c
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,long param_5,
               undefined8 param_6,undefined8 param_7)

{
  undefined4 *puVar1;
  ulong *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  long lVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  ulong uVar14;
  undefined8 uVar15;
  long lVar16;
  ulong uVar17;
  bool bVar18;
  long lVar19;
  undefined8 uVar20;
  ulong unaff_x30;
  undefined8 *local_350 [2];
  long local_340;
  long local_338;
  undefined8 local_330;
  undefined8 uStack_328;
  undefined8 uStack_320;
  undefined8 uStack_318;
  undefined8 local_310;
  undefined8 uStack_308;
  undefined8 uStack_300;
  undefined4 *local_2f8;
  undefined8 *local_2f0;
  undefined8 *puStack_2e8;
  long local_2e0;
  long local_2d8;
  undefined8 local_2d0;
  undefined8 uStack_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  undefined8 local_2b0;
  undefined8 uStack_2a8;
  undefined8 uStack_2a0;
  undefined4 *local_298;
  undefined8 *local_290;
  undefined8 *puStack_288;
  long local_280;
  long local_278;
  undefined8 local_270;
  undefined8 uStack_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined4 *local_238;
  undefined1 *local_230;
  undefined8 *local_228;
  long lStack_220;
  long local_218;
  undefined8 local_210;
  undefined8 local_208;
  undefined8 local_200;
  undefined8 uStack_1f8;
  undefined1 auStack_1e8 [172];
  undefined8 local_13c;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007ca61a0;
  thunk_EXT_FUN_80110000029615ec(*(undefined8 *)(param_1 + 0x488));
  if (*(long *)(param_1 + 0x850) == 0) {
    lVar16 = *(long *)(param_1 + 0x488);
    plVar8 = *(long **)(lVar16 + 0x1f0);
    if (plVar8 == (long *)0x0) {
      plVar8 = (long *)(**(code **)(DAT_fffffff00ae23218 + 0x68))();
      *(long **)(lVar16 + 0x1f0) = plVar8;
      if ((plVar8 == (long *)0x0) ||
         (uVar17 = (**(code **)(*plVar8 + 0x78))(plVar8,*(undefined8 *)(lVar16 + 0x48),lVar16),
         (uVar17 & 1) == 0)) {
        *(undefined8 *)(param_1 + 0x850) = 0;
      }
      else {
        plVar8 = *(long **)(lVar16 + 0x1f0);
        *(long **)(param_1 + 0x850) = plVar8;
        if (plVar8 != (long *)0x0) goto LAB_fffffff0081923b0;
      }
      if (*(long *)PTR_DAT_fffffff007ca61a0 == local_70) {
        return;
      }
      goto LAB_fffffff008193388;
    }
    *(long **)(param_1 + 0x850) = plVar8;
LAB_fffffff0081923b0:
    (**(code **)(*plVar8 + 0x20))();
    lVar19 = *(long *)(param_1 + 0x530);
    plVar8 = *(long **)(param_1 + 0x850);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar19 + 0x338));
    lVar16 = plVar8[4];
    *(int *)(plVar8 + 4) = (int)lVar16 + 1;
    if ((int)lVar16 == 0) {
      (**(code **)(*plVar8 + 0x20))(plVar8);
      plVar8[2] = 0;
      puVar13 = *(undefined8 **)(lVar19 + 0x348);
      plVar8[3] = (long)puVar13;
      *puVar13 = plVar8;
      *(long **)(lVar19 + 0x348) = plVar8 + 2;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar19 + 0x338));
    thunk_EXT_FUN_8011000002947870
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498);
    lVar16 = *(long *)(param_1 + 0x610);
    if (lVar16 == 0) goto LAB_fffffff008192504;
    if (*(int *)(lVar16 + 0x98) != 0) {
      uVar17 = 0;
      do {
        plVar8 = *(long **)(lVar16 + 0x28 + uVar17 * 8);
        (**(code **)(*plVar8 + 0xf8))(plVar8,param_1);
        uVar17 = uVar17 + 1;
        lVar16 = *(long *)(param_1 + 0x610);
      } while (uVar17 < *(uint *)(lVar16 + 0x98));
    }
    if (*(int *)(lVar16 + 0x9c) != 0) {
      uVar17 = 0;
      do {
        plVar8 = *(long **)(lVar16 + 0x48 + uVar17 * 8);
        (**(code **)(*plVar8 + 0xf8))(plVar8,param_1);
        uVar17 = uVar17 + 1;
        lVar16 = *(long *)(param_1 + 0x610);
      } while (uVar17 < *(uint *)(lVar16 + 0x9c));
    }
    plVar8 = *(long **)(lVar16 + 0x68);
    if (plVar8 == (long *)0x0) {
      plVar8 = *(long **)(lVar16 + 0x80);
      if (plVar8 == (long *)0x0) goto LAB_fffffff0081924e4;
LAB_fffffff008193284:
      (**(code **)(*plVar8 + 0xf8))(plVar8,param_1);
      lVar16 = *(long *)(param_1 + 0x610);
      plVar8 = *(long **)(lVar16 + 0x70);
      if (plVar8 != (long *)0x0) goto LAB_fffffff0081932b0;
LAB_fffffff0081924ec:
      plVar8 = *(long **)(lVar16 + 0x88);
      if (plVar8 == (long *)0x0) goto LAB_fffffff0081924f4;
LAB_fffffff0081932dc:
      (**(code **)(*plVar8 + 0xf8))(plVar8,param_1);
      lVar16 = *(long *)(param_1 + 0x610);
      plVar8 = *(long **)(lVar16 + 0x78);
      if (plVar8 != (long *)0x0) goto LAB_fffffff008193308;
LAB_fffffff0081924fc:
      plVar8 = *(long **)(lVar16 + 0x90);
    }
    else {
      (**(code **)(*plVar8 + 0xf8))(plVar8,param_1);
      lVar16 = *(long *)(param_1 + 0x610);
      plVar8 = *(long **)(lVar16 + 0x80);
      if (plVar8 != (long *)0x0) goto LAB_fffffff008193284;
LAB_fffffff0081924e4:
      plVar8 = *(long **)(lVar16 + 0x70);
      if (plVar8 == (long *)0x0) goto LAB_fffffff0081924ec;
LAB_fffffff0081932b0:
      (**(code **)(*plVar8 + 0xf8))(plVar8,param_1);
      lVar16 = *(long *)(param_1 + 0x610);
      plVar8 = *(long **)(lVar16 + 0x88);
      if (plVar8 != (long *)0x0) goto LAB_fffffff0081932dc;
LAB_fffffff0081924f4:
      plVar8 = *(long **)(lVar16 + 0x78);
      if (plVar8 == (long *)0x0) goto LAB_fffffff0081924fc;
LAB_fffffff008193308:
      (**(code **)(*plVar8 + 0xf8))(plVar8,param_1);
      plVar8 = *(long **)(*(long *)(param_1 + 0x610) + 0x90);
    }
    if (plVar8 != (long *)0x0) {
      (**(code **)(*plVar8 + 0xf8))(plVar8,param_1);
    }
  }
LAB_fffffff008192504:
  thunk_EXT_FUN_80110000029615f8(*(undefined8 *)(param_1 + 0x488));
  lVar16 = (ulong)*(uint *)(param_1 + 0x8e8) * 0x40;
  uVar17 = *(long *)(param_1 + 0x8e0) + (long)(int)lVar16;
  if (lVar16 - (int)lVar16 != 0) {
    uVar17 = *(long *)(param_1 + 0x8e0) + lVar16 & 0xffffffffffffU | 0x2bad000000000000;
  }
  thunk_EXT_FUN_8011000002947870(*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),uVar17);
  uVar3 = *(uint *)(param_1 + 0x8e8);
  uVar4 = *(uint *)(param_1 + 0x848);
  uVar5 = 0;
  if (uVar4 != 0) {
    uVar5 = (uVar3 + 1) / uVar4;
  }
  *(uint *)(param_1 + 0x8e8) = (uVar3 + 1) - uVar5 * uVar4;
  lVar16 = (ulong)uVar3 * 8;
  iVar7 = (int)lVar16;
  puVar13 = (undefined8 *)(*(long *)(param_1 + 0x8f0) + (long)iVar7);
  if (lVar16 - iVar7 != 0) {
    puVar13 = (undefined8 *)
              (*(long *)(param_1 + 0x8f0) + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar15 = *puVar13;
  puVar13 = (undefined8 *)(*(long *)(param_1 + 0x8f8) + (long)iVar7);
  if (lVar16 - iVar7 != 0) {
    puVar13 = (undefined8 *)
              (*(long *)(param_1 + 0x8f8) + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar20 = *puVar13;
  lVar16 = *(long *)(param_1 + 0x900);
  puVar13 = (undefined8 *)thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca31f8,0x848);
  *(undefined1 *)(puVar13 + 1) = 0;
  *(undefined4 *)((long)puVar13 + 0xc) = 0;
  *puVar13 = &DAT_fffffff007c95588;
  *(undefined1 *)(puVar13 + 3) = 0;
  *(undefined4 *)((long)puVar13 + 0x1c) = 0;
  puVar13[2] = &DAT_fffffff007c9e328;
  *(undefined1 *)(puVar13 + 4) = 0;
  puVar13[5] = 0;
  *(undefined4 *)((long)puVar13 + 0x13c) = 0;
  *(undefined1 *)(puVar13 + 0x28) = 0;
  *(undefined1 *)(puVar13 + 0x2b) = 0;
  puVar13[9] = 0;
  puVar13[8] = 0;
  puVar13[0xb] = 0;
  puVar13[10] = 0;
  puVar13[0xd] = 0;
  puVar13[0xc] = 0;
  puVar13[0xf] = 0;
  puVar13[0xe] = 0;
  puVar13[0x11] = 0;
  puVar13[0x10] = 0;
  puVar13[0x13] = 0;
  puVar13[0x12] = 0;
  puVar13[0x15] = 0;
  puVar13[0x14] = 0;
  puVar13[0x17] = 0;
  puVar13[0x16] = 0;
  puVar13[0x19] = 0;
  puVar13[0x18] = 0;
  puVar13[0x1b] = 0;
  puVar13[0x1a] = 0;
  puVar13[0x1d] = 0;
  puVar13[0x1c] = 0;
  puVar13[0x1f] = 0;
  puVar13[0x1e] = 0;
  puVar13[0x21] = 0;
  puVar13[0x20] = 0;
  puVar13[0x23] = 0;
  puVar13[0x22] = 0;
  puVar13[0x25] = 0;
  puVar13[0x24] = 0;
  puVar13[7] = 0;
  puVar13[6] = 0;
  *(undefined8 *)((long)puVar13 + 0x132) = 0;
  *(undefined8 *)((long)puVar13 + 0x12a) = 0;
  *(undefined4 *)(puVar13 + 0x3a) = 0;
  puVar13[0x37] = 0;
  puVar13[0x36] = 0;
  puVar13[0x39] = 0;
  puVar13[0x38] = 0;
  puVar13[0x33] = 0;
  puVar13[0x32] = 0;
  puVar13[0x35] = 0;
  puVar13[0x34] = 0;
  puVar13[0x2f] = 0;
  puVar13[0x2e] = 0;
  puVar13[0x31] = 0;
  puVar13[0x30] = 0;
  puVar13[0x2d] = 0;
  puVar13[0x2c] = 0;
  *(undefined4 *)(puVar13 + 0x3b) = 0;
  *(undefined1 *)(puVar13 + 0x3e) = 0;
  *(undefined4 *)((long)puVar13 + 500) = 0;
  puVar13[0x3c] = 0;
  puVar13[0x3d] = &DAT_fffffff007c9c208;
  *(undefined1 *)(puVar13 + 0x6d) = 0;
  *(undefined4 *)((long)puVar13 + 0x36c) = 0;
  puVar13[0x40] = 0;
  puVar13[0x3f] = 0;
  puVar13[0x42] = 0;
  puVar13[0x41] = 0;
  puVar13[0x44] = 0;
  puVar13[0x43] = 0;
  puVar13[0x46] = 0;
  puVar13[0x45] = 0;
  puVar13[0x48] = 0;
  puVar13[0x47] = 0;
  puVar13[0x4a] = 0;
  puVar13[0x49] = 0;
  puVar13[0x4c] = 0;
  puVar13[0x4b] = 0;
  puVar13[0x4e] = 0;
  puVar13[0x4d] = 0;
  puVar13[0x50] = 0;
  puVar13[0x4f] = 0;
  puVar13[0x52] = 0;
  puVar13[0x51] = 0;
  puVar13[0x54] = 0;
  puVar13[0x53] = 0;
  puVar13[0x56] = 0;
  puVar13[0x55] = 0;
  puVar13[0x58] = 0;
  puVar13[0x57] = 0;
  puVar13[0x5a] = 0;
  puVar13[0x59] = 0;
  *(undefined1 *)(puVar13 + 0x5b) = 0;
  *(undefined8 *)((long)puVar13 + 0x352) = 0;
  *(undefined8 *)((long)puVar13 + 0x34a) = 0;
  puVar13[0x67] = 0;
  puVar13[0x66] = 0;
  puVar13[0x69] = 0;
  puVar13[0x68] = 0;
  puVar13[99] = 0;
  puVar13[0x62] = 0;
  puVar13[0x65] = 0;
  puVar13[100] = 0;
  puVar13[0x5f] = 0;
  puVar13[0x5e] = 0;
  puVar13[0x61] = 0;
  puVar13[0x60] = 0;
  puVar13[0x5d] = 0;
  puVar13[0x5c] = 0;
  puVar13[0x6c] = &DAT_fffffff007c94020;
  *(undefined1 *)(puVar13 + 0x6e) = 0;
  puVar13[0x6f] = 0;
  puVar13[0x71] = 0;
  puVar13[0x70] = 0;
  puVar13[0x73] = 0;
  puVar13[0x72] = 0;
  puVar13[0x75] = 0;
  puVar13[0x74] = 0;
  puVar13[0x77] = 0;
  puVar13[0x76] = 0;
  puVar13[0x79] = 0;
  puVar13[0x78] = 0;
  puVar13[0x7b] = 0;
  puVar13[0x7a] = 0;
  puVar13[0x7d] = 0;
  puVar13[0x7c] = 0;
  puVar13[0x7f] = 0;
  puVar13[0x7e] = 0;
  *(undefined8 *)((long)puVar13 + 0x3fd) = 0;
  *(undefined1 *)(puVar13 + 0x82) = 0;
  *(undefined4 *)((long)puVar13 + 0x414) = 0;
  puVar13[0x81] = &DAT_fffffff007c9c208;
  *(undefined1 *)(puVar13 + 0xb1) = 0;
  *(undefined4 *)((long)puVar13 + 0x58c) = 0;
  *(undefined1 *)(puVar13 + 0x9f) = 0;
  puVar13[0x84] = 0;
  puVar13[0x83] = 0;
  puVar13[0x86] = 0;
  puVar13[0x85] = 0;
  puVar13[0x88] = 0;
  puVar13[0x87] = 0;
  puVar13[0x8a] = 0;
  puVar13[0x89] = 0;
  puVar13[0x8c] = 0;
  puVar13[0x8b] = 0;
  puVar13[0x8e] = 0;
  puVar13[0x8d] = 0;
  puVar13[0x90] = 0;
  puVar13[0x8f] = 0;
  puVar13[0x92] = 0;
  puVar13[0x91] = 0;
  puVar13[0x94] = 0;
  puVar13[0x93] = 0;
  puVar13[0x96] = 0;
  puVar13[0x95] = 0;
  puVar13[0x98] = 0;
  puVar13[0x97] = 0;
  puVar13[0x9a] = 0;
  puVar13[0x99] = 0;
  puVar13[0x9c] = 0;
  puVar13[0x9b] = 0;
  puVar13[0x9e] = 0;
  puVar13[0x9d] = 0;
  *(undefined8 *)((long)puVar13 + 0x572) = 0;
  *(undefined8 *)((long)puVar13 + 0x56a) = 0;
  puVar13[0xad] = 0;
  puVar13[0xac] = 0;
  puVar13[0xab] = 0;
  puVar13[0xaa] = 0;
  puVar13[0xa9] = 0;
  puVar13[0xa8] = 0;
  puVar13[0xa7] = 0;
  puVar13[0xa6] = 0;
  puVar13[0xa5] = 0;
  puVar13[0xa4] = 0;
  puVar13[0xa3] = 0;
  puVar13[0xa2] = 0;
  puVar13[0xa1] = 0;
  puVar13[0xa0] = 0;
  puVar13[0xb0] = &DAT_fffffff007c94020;
  *(undefined1 *)(puVar13 + 0xb2) = 0;
  puVar13[0xb3] = 0;
  *(undefined8 *)((long)puVar13 + 0x61d) = 0;
  puVar13[0xc3] = 0;
  puVar13[0xc2] = 0;
  puVar13[0xc1] = 0;
  puVar13[0xc0] = 0;
  puVar13[0xbf] = 0;
  puVar13[0xbe] = 0;
  puVar13[0xbd] = 0;
  puVar13[0xbc] = 0;
  puVar13[0xbb] = 0;
  puVar13[0xba] = 0;
  puVar13[0xb9] = 0;
  puVar13[0xb8] = 0;
  puVar13[0xb7] = 0;
  puVar13[0xb6] = 0;
  puVar13[0xb5] = 0;
  puVar13[0xb4] = 0;
  *(undefined1 *)(puVar13 + 0xc6) = 0;
  *(undefined4 *)((long)puVar13 + 0x634) = 0;
  puVar13[0xc5] = &DAT_fffffff007c9c208;
  *(undefined1 *)(puVar13 + 0xf5) = 0;
  *(undefined4 *)((long)puVar13 + 0x7ac) = 0;
  *(undefined1 *)(puVar13 + 0xe3) = 0;
  puVar13[0xe0] = 0;
  puVar13[0xdf] = 0;
  puVar13[0xe2] = 0;
  puVar13[0xe1] = 0;
  puVar13[0xdc] = 0;
  puVar13[0xdb] = 0;
  puVar13[0xde] = 0;
  puVar13[0xdd] = 0;
  puVar13[0xd8] = 0;
  puVar13[0xd7] = 0;
  puVar13[0xda] = 0;
  puVar13[0xd9] = 0;
  puVar13[0xd4] = 0;
  puVar13[0xd3] = 0;
  puVar13[0xd6] = 0;
  puVar13[0xd5] = 0;
  puVar13[0xd0] = 0;
  puVar13[0xcf] = 0;
  puVar13[0xd2] = 0;
  puVar13[0xd1] = 0;
  puVar13[0xcc] = 0;
  puVar13[0xcb] = 0;
  puVar13[0xce] = 0;
  puVar13[0xcd] = 0;
  puVar13[200] = 0;
  puVar13[199] = 0;
  puVar13[0xca] = 0;
  puVar13[0xc9] = 0;
  *(undefined8 *)((long)puVar13 + 0x792) = 0;
  *(undefined8 *)((long)puVar13 + 0x78a) = 0;
  puVar13[0xf1] = 0;
  puVar13[0xf0] = 0;
  puVar13[0xef] = 0;
  puVar13[0xee] = 0;
  puVar13[0xed] = 0;
  puVar13[0xec] = 0;
  puVar13[0xeb] = 0;
  puVar13[0xea] = 0;
  puVar13[0xe9] = 0;
  puVar13[0xe8] = 0;
  puVar13[0xe7] = 0;
  puVar13[0xe6] = 0;
  puVar13[0xe5] = 0;
  puVar13[0xe4] = 0;
  puVar13[0xf4] = &DAT_fffffff007c94020;
  *(undefined1 *)(puVar13 + 0xf6) = 0;
  puVar13[0xf7] = 0;
  *(undefined8 *)((long)puVar13 + 0x83d) = 0;
  puVar13[0x107] = 0;
  puVar13[0x106] = 0;
  puVar13[0x105] = 0;
  puVar13[0x104] = 0;
  puVar13[0x103] = 0;
  puVar13[0x102] = 0;
  puVar13[0x101] = 0;
  puVar13[0x100] = 0;
  puVar13[0xff] = 0;
  puVar13[0xfe] = 0;
  puVar13[0xfd] = 0;
  puVar13[0xfc] = 0;
  puVar13[0xfb] = 0;
  puVar13[0xfa] = 0;
  puVar13[0xf9] = 0;
  puVar13[0xf8] = 0;
  uVar17 = (**(code **)*puVar13)(puVar13,param_2,param_3);
  if ((uVar17 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x520) = *(undefined4 *)((long)puVar13 + 0xc);
  }
  else {
    lVar19 = (ulong)uVar3 * 4;
    puVar1 = (undefined4 *)(lVar16 + (int)lVar19);
    if (lVar19 - (int)lVar19 != 0) {
      puVar1 = (undefined4 *)(lVar16 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_8011000003a61b10(auStack_1e8,param_4,0x178);
    local_13c = DAT_fffffff007113ed0;
    uStack_268 = 0;
    local_270 = 0;
    uStack_260 = 0;
    puStack_288 = (undefined8 *)0x0;
    local_290 = (undefined8 *)0x0;
    local_280 = 0;
    uStack_2a8 = 0;
    uStack_2a0 = 0;
    uStack_2c8 = 0;
    local_2d0 = 0;
    uStack_2c0 = 0;
    puStack_2e8 = (undefined8 *)0x0;
    local_2f0 = (undefined8 *)0x0;
    local_2e0 = 0;
    uStack_308 = 0;
    uStack_300 = 0;
    uStack_328 = 0;
    local_330 = 0;
    uStack_318 = 0;
    uStack_320 = 0;
    local_350[1] = (undefined8 *)0x0;
    local_350[0] = (undefined8 *)0x0;
    local_338 = 0;
    local_340 = 0;
    local_310 = 5;
    local_2f8 = (undefined4 *)0x0;
    local_2d8 = 0;
    local_2b8 = 0;
    local_2b0 = 5;
    local_298 = (undefined4 *)0x0;
    local_278 = 0;
    local_258 = 0;
    local_250 = 5;
    uStack_240 = 0;
    local_248 = 0;
    local_230 = (undefined1 *)0x0;
    local_238 = (undefined4 *)0x0;
    lStack_220 = 0;
    local_228 = (undefined8 *)0x0;
    local_210 = 0;
    local_218 = 0;
    local_208 = 0;
    uStack_1f8 = 0;
    local_200 = 0;
    if ((*(byte *)(puVar13 + 1) & 1) == 0) goto LAB_fffffff008193214;
    local_310 = 0x100000001;
    local_2b0 = 0x100000002;
    local_250 = 3;
    local_230 = auStack_1e8;
    local_350[0] = puVar13 + 0x3d;
    local_350[1] = puVar13 + 0x6c;
    uStack_308 = uVar15;
    uStack_300 = uVar20;
    local_2f8 = puVar1;
    local_2f0 = puVar13 + 0x81;
    puStack_2e8 = puVar13 + 0xb0;
    uStack_2a8 = uVar15;
    uStack_2a0 = uVar20;
    local_298 = puVar1;
    local_290 = puVar13 + 0xc5;
    puStack_288 = puVar13 + 0xf4;
    local_248 = uVar15;
    uStack_240 = uVar20;
    local_238 = puVar1;
    local_228 = puVar13 + 2;
    thunk_EXT_FUN_8011000002946f14(param_1 + 0x858);
    thunk_EXT_FUN_8011000002946f14(param_1 + 0x898);
    *(undefined4 *)(param_1 + 0x8d8) = 0xffffffff;
    thunk_EXT_FUN_80110000029615ec(*(undefined8 *)(param_1 + 0x488));
    lVar16 = 0;
    do {
      puVar12 = local_350[lVar16 * 0xc];
      if ((*(byte *)(puVar12 + 1) & 1) == 0) goto LAB_fffffff008193214;
      if (*(int *)(puVar12 + 0x16) == 3) {
        uVar17 = FUN_fffffff0081920f4
                           (param_1,puVar12,local_350[lVar16 * 0xc + 1],*(undefined1 *)(param_5 + 8)
                            ,*(undefined8 *)(param_5 + 0x18),param_6,param_7);
joined_r0xfffffff008192acc:
        if ((uVar17 & 1) == 0) {
          thunk_EXT_FUN_80110000029615f8(*(undefined8 *)(param_1 + 0x488));
          if (lVar16 == 0) goto LAB_fffffff008192fb8;
          if ((*(byte *)(local_350[0] + 1) & 1) == 0) goto LAB_fffffff008193214;
          if (*(int *)(local_350[0] + 0x16) == 3) {
            *(undefined1 *)(local_338 + 0x34c) = 1;
          }
          goto LAB_fffffff008192fb8;
        }
      }
      else {
        if (*(int *)(puVar12 + 0x16) == 1) {
          uVar17 = FUN_fffffff00819164c
                             (param_1,puVar12,local_350[lVar16 * 0xc + 1],
                              *(undefined1 *)(param_5 + 8),*(undefined8 *)(param_5 + 0x18),param_6,
                              param_7);
          goto joined_r0xfffffff008192acc;
        }
        *(undefined4 *)(param_1 + 0x520) = 0x106;
      }
      plVar8 = *(long **)(*(long *)(param_1 + 0x530) + 0x4b0);
      (**(code **)(*plVar8 + 0x178))(plVar8,1,*(undefined4 *)(param_1 + 0x7ec));
      lVar16 = lVar16 + 1;
    } while (lVar16 != 4);
    thunk_EXT_FUN_80110000029615f8(*(undefined8 *)(param_1 + 0x488));
    if ((*(byte *)(puVar13 + 1) & 1) == 0) goto LAB_fffffff008193214;
    if ((((local_338 == 0) || (local_2d8 == 0)) || (local_278 == 0)) || (local_218 == 0)) {
LAB_fffffff008192fc4:
      *(undefined4 *)(param_1 + 0x520) = 8;
LAB_fffffff008192fcc:
      *puVar1 = 1;
    }
    else {
      lVar16 = *(long *)(param_1 + 0x850);
      uVar17 = puVar13[0x3c];
      plVar8 = (long *)thunk_EXT_FUN_8011000002961628
                                 (*(undefined8 *)(lVar16 + 0x30),*(undefined4 *)(puVar13 + 0x3b));
      if (plVar8 == (long *)0x0) goto LAB_fffffff008192fc4;
      if (((0xffffffffffffffdf < uVar17) || ((ulong)plVar8[0xf] < uVar17 + 0x20)) ||
         (lVar19 = thunk_EXT_FUN_8011000002951cb8(plVar8), lVar19 == 0)) {
        (**(code **)(*plVar8 + 0x28))(plVar8);
        goto LAB_fffffff008192fc4;
      }
      (**(code **)(*plVar8 + 0x20))(plVar8);
      (**(code **)(*plVar8 + 0x20))(plVar8);
      (**(code **)(*plVar8 + 0x28))(plVar8);
      plVar9 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))();
      if (plVar9 == (long *)0x0) {
        bVar18 = false;
      }
      else {
        lVar11 = *(long *)(lVar16 + 0x28);
        uVar3 = *(uint *)(lVar11 + 0x18b70);
        plVar9[2] = *(long *)(*(long *)(lVar16 + 0x30) + 0x50);
        iVar7 = FUN_fffffff0081e07cc(plVar9,lVar11,6,uVar3 | 0x23);
        if (iVar7 == 0) {
LAB_fffffff008193250:
          bVar18 = false;
        }
        else {
          lVar16 = *(long *)(lVar16 + 0x38);
          plVar10 = (long *)plVar9[0xb];
          if (plVar10 == (long *)0x0) {
            plVar10 = (long *)(**(code **)(*(long *)plVar9[9] + 0x90))
                                        ((long *)plVar9[9],lVar16,0x500000087);
            if (plVar10 == (long *)0x0) goto LAB_fffffff008193250;
            (**(code **)(*plVar10 + 0x20))();
            (**(code **)(*plVar10 + 0x28))(plVar10);
            plVar9[0xb] = (long)plVar10;
          }
          if (plVar10[4] != lVar16) {
            thunk_EXT_FUN_8011000003a49114
                      ("AGXk: %s:%d:%s: !!! Attempting to map into multiple GPU Contexts!\n");
            return;
          }
          lVar16 = (**(code **)(*plVar10 + 0x98))();
          if (lVar16 == 0) goto LAB_fffffff008193250;
          plVar10 = (long *)plVar9[10];
          if (plVar10 == (long *)0x0) {
            plVar10 = (long *)(**(code **)(*(long *)plVar9[9] + 0x90))
                                        ((long *)plVar9[9],plVar9[3],0x800000084);
            if (plVar10 == (long *)0x0) goto LAB_fffffff008193250;
            (**(code **)(*plVar10 + 0x20))();
            (**(code **)(*plVar10 + 0x28))(plVar10);
            plVar9[10] = (long)plVar10;
          }
          lVar16 = (**(code **)(*plVar10 + 0x98))();
          if (lVar16 == 0) goto LAB_fffffff008193250;
          puVar2 = (ulong *)(lVar19 + (int)uVar17);
          if (uVar17 != (long)(int)uVar17) {
            puVar2 = (ulong *)(lVar19 + uVar17 & 0xffffffffffff | 0x2bad000000000000);
          }
          lVar19 = (**(code **)(*(long *)plVar9[0xb] + 0x98))();
          lVar11 = (**(code **)(*(long *)plVar9[10] + 0x98))();
          lVar16 = local_338;
          uVar17 = lVar19 + 0x3fU & 0xffffffffffffffc0;
          uVar14 = lVar11 + 0x3fU & 0xffffffffffffffc0;
          *(ulong *)(local_2d8 + 0x150) = uVar14;
          *(ulong *)(local_278 + 0x150) = uVar14 + 0x80;
          *(ulong *)(local_278 + 0x158) = uVar14 + 0x100;
          *(ulong *)(local_218 + 0x158) = uVar14 + 0x140;
          *puVar2 = uVar17;
          puVar2[1] = uVar17 + 0x80;
          puVar2[2] = uVar17 + 0x100;
          puVar2[3] = uVar17 + 0x140;
          if (plVar9[10] != 0) {
            thunk_EXT_FUN_8011000002969a34(local_338);
          }
          if (plVar9[0xb] != 0) {
            thunk_EXT_FUN_8011000002969a34(lVar16);
          }
          lVar16 = local_2d8;
          if (plVar9[10] != 0) {
            thunk_EXT_FUN_8011000002969a34(local_2d8);
          }
          if (plVar9[0xb] != 0) {
            thunk_EXT_FUN_8011000002969a34(lVar16);
          }
          lVar16 = local_278;
          if (plVar9[10] != 0) {
            thunk_EXT_FUN_8011000002969a34(local_278);
          }
          if (plVar9[0xb] != 0) {
            thunk_EXT_FUN_8011000002969a34(lVar16);
          }
          lVar16 = local_218;
          if (plVar9[10] != 0) {
            thunk_EXT_FUN_8011000002969a34(local_218);
          }
          if (plVar9[0xb] != 0) {
            thunk_EXT_FUN_8011000002969a34(lVar16);
          }
          bVar18 = true;
        }
        (**(code **)(*plVar9 + 0x28))(plVar9);
      }
      thunk_EXT_FUN_8011000002951e04(plVar8);
      (**(code **)(*plVar8 + 0x28))(plVar8);
      (**(code **)(*plVar8 + 0x28))(plVar8);
      if (!bVar18) goto LAB_fffffff008192fc4;
LAB_fffffff008192fb8:
      if (*(int *)(param_1 + 0x520) != 0) goto LAB_fffffff008192fcc;
    }
    local_340 = local_2d8;
    local_2e0 = local_2d8;
    local_280 = local_2d8;
    lStack_220 = local_2d8;
    if ((local_2d8 != 0) && (local_278 != 0)) {
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),local_278 + 0x80,
                 local_2d8 + 0x180);
    }
    if (((local_2d8 != 0) && (local_278 != 0)) && (local_218 != 0)) {
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),local_218 + 0xc40,
                 lStack_220 + 0x180);
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),local_218 + 0x80,
                 lStack_220 + 0x180);
    }
    if ((*(byte *)(local_350[0] + 1) & 1) == 0) {
LAB_fffffff008193214:
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
      return;
    }
    if (*(int *)(local_350[0] + 0x16) == 3) {
      if (local_338 != 0) {
        FUN_fffffff008193af4(param_1,local_338,local_330,uStack_328);
      }
    }
    else if ((*(int *)(local_350[0] + 0x16) == 1) && (local_338 != 0)) {
      FUN_fffffff0081938f0(param_1,local_338,local_330);
    }
    if ((*(byte *)(local_2f0 + 1) & 1) == 0) goto LAB_fffffff008193214;
    if (*(int *)(local_2f0 + 0x16) == 1) {
      if (local_2d8 != 0) {
        FUN_fffffff0081938f0(param_1,local_2d8,local_2d0);
      }
    }
    else if ((*(int *)(local_2f0 + 0x16) == 3) && (local_2d8 != 0)) {
      FUN_fffffff008193af4(param_1,local_2d8,local_2d0,uStack_2c8);
    }
    if ((*(byte *)(local_290 + 1) & 1) == 0) goto LAB_fffffff008193214;
    if (*(int *)(local_290 + 0x16) == 1) {
      if (local_278 != 0) {
        FUN_fffffff0081938f0(param_1,local_278,local_270);
      }
    }
    else if ((*(int *)(local_290 + 0x16) == 3) && (local_278 != 0)) {
      FUN_fffffff008193af4(param_1,local_278,local_270,uStack_268);
    }
    if ((local_230[8] & 1) == 0) goto LAB_fffffff008193214;
    if (*(int *)(local_230 + 0xb0) == 1) {
      if (local_218 != 0) {
        FUN_fffffff0081938f0(param_1,local_218,local_210);
      }
    }
    else if ((*(int *)(local_230 + 0xb0) == 3) && (local_218 != 0)) {
      FUN_fffffff008193af4(param_1,local_218,local_210,local_208);
    }
  }
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_70) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081931d4);
      (*pcVar6)();
    }
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca31f8,puVar13,0x848);
    return;
  }
LAB_fffffff008193388:
  thunk_EXT_FUN_8011000003a48590();
  return;
}

