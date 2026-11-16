// FUN_fffffff0081c426c @ fffffff0081c426c size=2776

long * FUN_fffffff0081c426c(long param_1,ulong param_2)

{
  long lVar1;
  long lVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  long *plVar12;
  long *plVar13;
  ulong uVar14;
  long lVar15;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  
  lVar15 = *(long *)(param_1 + 0x918);
  plVar12 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  if (plVar12 != (long *)0x0) {
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar15 + 0x5c4),0x20);
    if (plVar13 == (long *)0x0) {
      local_6c = 0;
    }
    else {
      local_6c = (**(code **)(*plVar12 + 0x100))(plVar12,"pre_sample_idx",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0xa48),0x20);
    if (plVar13 == (long *)0x0) {
      local_70 = 0;
    }
    else {
      local_70 = (**(code **)(*plVar12 + 0x100))(plVar12,"Power",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0xbd0),0x20);
    if (plVar13 == (long *)0x0) {
      local_74 = 0;
    }
    else {
      local_74 = (**(code **)(*plVar12 + 0x100))(plVar12,"Performance",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2a64),0x20);
    if (plVar13 == (long *)0x0) {
      local_78 = 0;
    }
    else {
      local_78 = (**(code **)(*plVar12 + 0x100))(plVar12,"PowerZone",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    lVar2 = *(long *)(param_1 + 0x2c0) + 0x2270;
    lVar1 = (param_2 & 0xffffffff) * 0x2b8 + 0x18;
    uVar14 = lVar2 + (int)lVar1;
    if (lVar1 != (int)lVar1) {
      uVar14 = lVar2 + lVar1 & 0xffffffffffffU | 0x2bad000000000000;
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar14 + 0x80),0x20);
    if (plVar13 == (long *)0x0) {
      local_7c = 0;
    }
    else {
      local_7c = (**(code **)(*plVar12 + 0x100))(plVar12,"FastDie",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0xb00),0x20);
    if (plVar13 == (long *)0x0) {
      local_80 = 0;
    }
    else {
      local_80 = (**(code **)(*plVar12 + 0x100))(plVar12,"PPM",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2220),0x20);
    if (plVar13 == (long *)0x0) {
      local_84 = 0;
    }
    else {
      local_84 = (**(code **)(*plVar12 + 0x100))(plVar12,"Deadline",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2cb0),0x20);
    if (plVar13 == (long *)0x0) {
      local_88 = 0;
    }
    else {
      local_88 = (**(code **)(*plVar12 + 0x100))(plVar12,"PMU",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    lVar1 = *(long *)(param_1 + 0x2c0) + 0x2878;
    uVar14 = (param_2 & 0xffffffff) * 0x70 | 8;
    puVar3 = (undefined4 *)(lVar1 + (int)uVar14);
    if (uVar14 != (long)(int)uVar14) {
      puVar3 = (undefined4 *)(lVar1 + uVar14 & 0xffffffffffff | 0x2bad000000000000);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24(*puVar3,0x20);
    if (plVar13 == (long *)0x0) {
      local_8c = 0;
    }
    else {
      local_8c = (**(code **)(*plVar12 + 0x100))(plVar12,"UT",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2bf4),0x20);
    if (plVar13 == (long *)0x0) {
      local_90 = 0;
    }
    else {
      local_90 = (**(code **)(*plVar12 + 0x100))(plVar12,"SE",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2b28),0x20);
    if (plVar13 == (long *)0x0) {
      local_94 = 0;
    }
    else {
      local_94 = (**(code **)(*plVar12 + 0x100))(plVar12,"DeadlineAware",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x348) + 0x8c),0x20);
    if (plVar13 == (long *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)(*plVar12 + 0x100))(plVar12,"PPMLimit",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x348) + 0x88),0x20);
    if (plVar13 == (long *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (**(code **)(*plVar12 + 0x100))(plVar12,"CLTMLimit",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x27ae),0x20);
    if (plVar13 == (long *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (**(code **)(*plVar12 + 0x100))(plVar12,"Turbo",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    lVar2 = *(long *)(param_1 + 0x2c0) + 0x2d38;
    lVar1 = (param_2 & 0xffffffff) * 0xf8 + 0xe0;
    uVar14 = lVar2 + (int)lVar1;
    if (lVar1 != (int)lVar1) {
      uVar14 = lVar2 + lVar1 & 0xffffffffffffU | 0x2bad000000000000;
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar14 + 4),0x20);
    if (plVar13 == (long *)0x0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (**(code **)(*plVar12 + 0x100))(plVar12,"CoreEfficiency",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24(0,0x20);
    if (plVar13 == (long *)0x0) {
      uVar8 = 0;
    }
    else {
      uVar8 = (**(code **)(*plVar12 + 0x100))(plVar12,"FABoost",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2ecc),0x20);
    if (plVar13 == (long *)0x0) {
      uVar9 = 0;
    }
    else {
      uVar9 = (**(code **)(*plVar12 + 0x100))(plVar12,"AvgPerfStateLimiter",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x50),0x20);
    if (plVar13 == (long *)0x0) {
      uVar10 = 0;
    }
    else {
      uVar10 = (**(code **)(*plVar12 + 0x100))(plVar12,"Final",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x918) + 0x558),0x20);
    if (plVar13 == (long *)0x0) {
      uVar11 = 0;
    }
    else {
      uVar11 = (**(code **)(*plVar12 + 0x100))(plVar12,"CLPCSplitHint",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    plVar13 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar15 + 0x5c4),0x20);
    if (plVar13 != (long *)0x0) {
      uVar14 = (**(code **)(*plVar12 + 0x100))(plVar12,"post_sample_idx",plVar13);
      (**(code **)(*plVar13 + 0x28))(plVar13);
      if (((local_6c & local_70 & local_74 & local_78 & local_7c & local_80 & local_84 & local_88 &
            local_8c & local_90 & local_94 & uVar4 & uVar5 & uVar6 & uVar7 & uVar8 & uVar9 & uVar10
           & uVar11) == 1) && ((uVar14 & 1) != 0)) {
        return plVar12;
      }
    }
    (**(code **)(*plVar12 + 0x28))(plVar12);
  }
  return (long *)0x0;
}

