// FUN_fffffff008194e6c @ fffffff008194e6c size=1384

undefined8
FUN_fffffff008194e6c(long *param_1,long param_2,undefined8 param_3,long param_4,undefined8 param_5)

{
  bool bVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  undefined8 uVar13;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
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
  uStack_108 = 0;
  local_110 = 0;
  uStack_f8 = 0;
  uStack_100 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  uVar7 = *(ulong *)(param_1[0xa6] + 0x5c8);
  uVar3 = param_1[0xa9];
  thunk_EXT_FUN_8011000002946f14(&local_b0);
  if (param_4 != 0) {
    thunk_EXT_FUN_8011000002946f14(&local_f0);
  }
  lVar9 = *(long *)(param_2 + 0x18);
  uVar10 = *(ulong *)(lVar9 + 0x20);
  if (uVar10 == 0) {
    uVar5 = 0;
    uVar6 = 0xffffffffffffffff;
  }
  else {
    uVar5 = 0;
    uVar6 = 0xffffffffffffffff;
    uVar12 = 0;
    uVar8 = 1;
    do {
      lVar11 = *(long *)(*(long *)(lVar9 + 0x18) + uVar12 * 8);
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(param_1[0xa6] + 0x148),*(undefined8 *)(lVar11 + 0x18),&local_b0);
      if (param_4 != 0) {
        uVar13 = *(undefined8 *)(param_1[0xa6] + 0x148);
        lVar2 = thunk_EXT_FUN_801100000295198c(lVar11);
        thunk_EXT_FUN_80110000029486ac(uVar13,lVar2 + 0x100,&local_f0);
      }
      uVar4 = (ulong)*(uint *)(lVar11 + 0x14);
      uVar12 = uVar4;
      if ((*(byte *)(lVar11 + 0xc2) & 1) != 0) {
        uVar12 = 0xffffffffffffffff;
      }
      if ((uVar7 >> 0x32 & 1) != 0) {
        if ((uVar4 & ~uVar3) != 0) {
          FUN_fffffff0081963b0(lVar11,uVar4,uVar3,"CL Read");
        }
        if (((uVar3 & (uVar4 ^ 0xffffffffffffffff)) != 0) && ((*(byte *)(lVar11 + 0xc2) & 1) == 0))
        {
          FUN_fffffff0081963b0(lVar11,uVar4,uVar3,"CL Write");
        }
      }
      uVar5 = uVar5 | uVar4;
      uVar6 = uVar12 & uVar6;
      Hint_Prefetch(*(long *)(lVar11 + 0x18) + 0x40,2,0,1);
      lVar11 = thunk_EXT_FUN_801100000295198c(*(long *)(lVar11 + 0x18),lVar11);
      Hint_Prefetch(lVar11 + 0x140,2,0,1);
      bVar1 = uVar8 < uVar10;
      uVar12 = uVar8;
      uVar8 = (ulong)((int)uVar8 + 1);
    } while (bVar1);
  }
  lVar9 = *(long *)(param_2 + 0x68);
  uVar10 = *(ulong *)(lVar9 + 0x20);
  if (uVar10 != 0) {
    uVar12 = 0;
    uVar8 = 1;
    do {
      lVar11 = *(long *)(*(long *)(lVar9 + 0x18) + uVar12 * 8);
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(param_1[0xa6] + 0x148),*(undefined8 *)(lVar11 + 0x18),&local_b0);
      if (param_4 != 0) {
        uVar13 = *(undefined8 *)(param_1[0xa6] + 0x148);
        lVar2 = thunk_EXT_FUN_801100000295198c(lVar11);
        thunk_EXT_FUN_80110000029486ac(uVar13,lVar2 + 0x100,&local_f0);
      }
      uVar4 = (ulong)*(uint *)(lVar11 + 0x14);
      uVar12 = uVar4;
      if ((*(byte *)(lVar11 + 0xc2) & 1) != 0) {
        uVar12 = 0xffffffffffffffff;
      }
      if ((uVar7 >> 0x32 & 1) != 0) {
        if ((uVar4 & ~uVar3) != 0) {
          FUN_fffffff0081963b0(lVar11,uVar4,uVar3,"CL Read");
        }
        if (((uVar3 & (uVar4 ^ 0xffffffffffffffff)) != 0) && ((*(byte *)(lVar11 + 0xc2) & 1) == 0))
        {
          FUN_fffffff0081963b0(lVar11,uVar4,uVar3,"CL Write");
        }
      }
      uVar5 = uVar5 | uVar4;
      uVar6 = uVar12 & uVar6;
      Hint_Prefetch(*(long *)(lVar11 + 0x18) + 0x40,2,0,1);
      lVar11 = thunk_EXT_FUN_801100000295198c(*(long *)(lVar11 + 0x18),lVar11);
      Hint_Prefetch(lVar11 + 0x140,2,0,1);
      bVar1 = uVar8 < uVar10;
      uVar12 = uVar8;
      uVar8 = (ulong)((int)uVar8 + 1);
    } while (bVar1);
  }
  lVar9 = *(long *)(param_2 + 0x10);
  uVar10 = *(ulong *)(lVar9 + 0x20);
  if (uVar10 != 0) {
    uVar12 = 0;
    uVar8 = 1;
    do {
      lVar2 = *(long *)(*(long *)(lVar9 + 0x18) + uVar12 * 8);
      lVar11 = thunk_EXT_FUN_801100000295198c(lVar2);
      if ((*(char *)(lVar11 + 0x11) < '\0') &&
         (thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(param_1[0xa6] + 0x148),*(long *)(lVar2 + 0x18) + 0x40,&local_b0
                    ), param_4 != 0)) {
        uVar13 = *(undefined8 *)(param_1[0xa6] + 0x148);
        lVar11 = thunk_EXT_FUN_801100000295198c(lVar2);
        thunk_EXT_FUN_80110000029486ac(uVar13,lVar11 + 0x140,&local_f0);
      }
      uVar12 = (ulong)*(uint *)(lVar2 + 0x14);
      if (((uVar7 >> 0x32 & 1) != 0) && ((uVar12 & ~uVar3) != 0)) {
        FUN_fffffff0081963b0(lVar2,uVar12,uVar3,"CL Read");
      }
      uVar5 = uVar5 | uVar12;
      Hint_Prefetch(*(undefined8 *)(lVar2 + 0x18),2,0,1);
      lVar11 = thunk_EXT_FUN_801100000295198c(*(undefined8 *)(lVar2 + 0x18),lVar2);
      Hint_Prefetch(lVar11 + 0x100,2,0,1);
      bVar1 = uVar8 < uVar10;
      uVar12 = uVar8;
      uVar8 = (ulong)((int)uVar8 + 1);
    } while (bVar1);
  }
  lVar9 = *(long *)(param_2 + 0x60);
  uVar10 = *(ulong *)(lVar9 + 0x20);
  if (uVar10 != 0) {
    uVar12 = 0;
    uVar8 = 1;
    do {
      lVar2 = *(long *)(*(long *)(lVar9 + 0x18) + uVar12 * 8);
      lVar11 = thunk_EXT_FUN_801100000295198c(lVar2);
      if ((*(char *)(lVar11 + 0x11) < '\0') &&
         (thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(param_1[0xa6] + 0x148),*(long *)(lVar2 + 0x18) + 0x40,&local_b0
                    ), param_4 != 0)) {
        uVar13 = *(undefined8 *)(param_1[0xa6] + 0x148);
        lVar11 = thunk_EXT_FUN_801100000295198c(lVar2);
        thunk_EXT_FUN_80110000029486ac(uVar13,lVar11 + 0x140,&local_f0);
      }
      uVar12 = (ulong)*(uint *)(lVar2 + 0x14);
      if (((uVar7 >> 0x32 & 1) != 0) && ((uVar12 & ~uVar3) != 0)) {
        FUN_fffffff0081963b0(lVar2,uVar12,uVar3,"CL Read");
      }
      uVar5 = uVar5 | uVar12;
      Hint_Prefetch(*(undefined8 *)(lVar2 + 0x18),2,0,1);
      lVar11 = thunk_EXT_FUN_801100000295198c(*(undefined8 *)(lVar2 + 0x18),lVar2);
      Hint_Prefetch(lVar11 + 0x100,2,0,1);
      bVar1 = uVar8 < uVar10;
      uVar12 = uVar8;
      uVar8 = (ulong)((int)uVar8 + 1);
    } while (bVar1);
  }
  FUN_fffffff00818dc84(param_1,&local_b0,&local_130);
  thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(param_1[0xa6] + 0x148),&local_130,param_3);
  if ((*(byte *)(param_1[0xa6] + 0x1ac45) & 1) != 0) {
    FUN_fffffff0081a0304(*(undefined8 *)(param_1[0xa6] + 0x148),0x801,&local_130,param_5);
  }
  if (param_4 != 0) {
    FUN_fffffff00818dc84(param_1,&local_f0,&local_130);
    thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(param_1[0xa6] + 0x148),&local_130,param_4);
  }
  if (((*(byte *)(param_1 + 0x121) & 1) == 0) &&
     ((uVar5 & (param_1[0xa9] ^ 0xffffffffffffffffU)) != 0 ||
      ((param_1[0xa9] | uVar5) & (uVar6 ^ 0xffffffffffffffff)) != 0)) {
    if ((*(byte *)(param_1[0xa6] + 0x1ff) & 1) != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x11,
                 "protection violation: %016llx -> %016llx -> %016llx");
    }
    (**(code **)(*param_1 + 0xf0))(param_1,0x10);
    uVar13 = 0;
  }
  else {
    uVar13 = 1;
  }
  return uVar13;
}

