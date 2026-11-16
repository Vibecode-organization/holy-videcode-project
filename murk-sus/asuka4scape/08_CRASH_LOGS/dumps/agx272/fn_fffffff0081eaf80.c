// FUN_fffffff0081eaf80 @ fffffff0081eaf80 size=1124

void FUN_fffffff0081eaf80
               (long *param_1,long *param_2,int param_3,int param_4,ulong param_5,long param_6)

{
  bool bVar1;
  long *plVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  uint *puVar6;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  int iVar12;
  uint uVar13;
  long lVar14;
  long lVar15;
  long local_68;
  
  uVar13 = *(uint *)(param_1 + 0x2a);
  uVar4 = thunk_EXT_FUN_8011000003397c88();
  local_68 = 0;
  thunk_EXT_FUN_8011000003398228(uVar4,&local_68);
  puVar6 = (uint *)param_1[0xe];
  if (puVar6[8] == 1) {
    bVar1 = false;
  }
  else {
    bVar1 = 4000000 < (ulong)(local_68 - param_1[0x30]);
  }
  if ((uVar13 & 3) == 0 && !bVar1) {
    return;
  }
  if ((int)param_1[0x2a] == 0) {
    param_5 = 0;
  }
  else {
    uVar9 = (ulong)(uint)(param_4 * param_3) + 0xfffff & 0x1fff00000;
    if (uVar9 <= param_5) {
      uVar9 = param_5;
    }
    uVar7 = param_5;
    if ((uVar13 & 1) != 0) {
      uVar7 = uVar9;
    }
    if (uVar7 < (ulong)param_1[0x2b]) {
      uVar13 = *(int *)((long)param_1 + 0x154) + 1;
      *(uint *)((long)param_1 + 0x154) = uVar13;
      if (0x80 < uVar13) {
        *(undefined4 *)((long)param_1 + 0x154) = 0;
LAB_fffffff0081eb3a8:
        lVar5 = 0x144;
        if (param_1[0x22] != 0) {
          lVar5 = 0x148;
        }
        uVar8 = (uint)(uVar7 + 0x1ffff >> 0x11);
        uVar13 = *(uint *)((long)param_1 + lVar5);
        if (uVar8 <= *(uint *)((long)param_1 + lVar5)) {
          uVar13 = uVar8;
        }
        *(uint *)(param_1 + 0x28) = uVar13;
        param_1[0x2b] = (ulong)uVar13 << 0x11;
      }
    }
    else {
      *(undefined4 *)((long)param_1 + 0x154) = 0;
      if (uVar7 != param_1[0x2b]) goto LAB_fffffff0081eb3a8;
    }
  }
  uVar13 = *(uint *)((long)param_1 + 0x13c);
  if (*(uint *)((long)param_1 + 0x13c) <= *(uint *)(param_1 + 0x28)) {
    uVar13 = *(uint *)(param_1 + 0x28);
  }
  if (bVar1) {
    uVar8 = *puVar6;
    uVar3 = puVar6[1];
    uVar9 = (ulong)puVar6[3];
    puVar6[8] = 1;
    param_1[0x30] = local_68;
    lVar14 = *(long *)(param_1[2] + 0x1ac50);
    lVar15 = (ulong)uVar8 * 0x8000;
    thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(lVar14 + 0x18));
    lVar5 = *(long *)(lVar14 + 0x38);
    if (*(long *)(lVar14 + 0x38) <= lVar15) {
      lVar5 = lVar15;
    }
    *(long *)(lVar14 + 0x38) = lVar5;
    thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar14 + 0x18));
    uVar7 = param_1[0x39];
    lVar5 = param_1[2];
    lVar14 = 3;
    if (*(long *)(lVar5 + 0x11610) != 0) {
      lVar14 = *(long *)(lVar5 + 0x11610);
    }
    uVar10 = lVar14 * (ulong)uVar8;
    uVar11 = uVar7 + uVar3;
    if (uVar7 + uVar3 <= uVar10) {
      uVar11 = uVar10;
    }
    uVar8 = 0;
    if (uVar7 != 0) {
      uVar8 = (uint)(((uVar7 + (uVar11 & 0xffffffff)) - 1 & -uVar7) / uVar7);
    }
    if (uVar13 <= uVar8) {
      uVar13 = uVar8;
    }
  }
  else {
    uVar9 = 0;
    lVar5 = param_1[2];
  }
  iVar12 = (int)uVar9;
  if (*(long *)(lVar5 + 0x11618) == 0) {
    uVar7 = param_1[0x39];
  }
  else {
    uVar7 = param_1[0x39];
    uVar8 = 0;
    if (uVar7 != 0) {
      uVar8 = (uint)(((uVar7 + (uint)(*(int *)(param_1[0xe] + 4) +
                                     (int)uVar7 * (int)*(long *)(lVar5 + 0x11618))) - 1 & -uVar7) /
                    uVar7);
    }
    if (uVar13 <= uVar8) {
      uVar13 = uVar8;
    }
  }
  uVar11 = param_1[0x25];
  uVar8 = 0;
  if (uVar7 != 0) {
    uVar8 = (uint)((uVar11 >> 0xf & 0xffffffff) / uVar7);
  }
  uVar7 = (ulong)(uVar13 - uVar8);
  if (uVar13 < uVar8 || uVar13 - uVar8 == 0) {
    if (iVar12 == 0) goto LAB_fffffff0081eb310;
    uVar7 = *(ulong *)(lVar5 + 0x11608);
    uVar10 = 8;
    if (uVar7 != 0) {
      uVar10 = uVar7;
    }
    if (uVar10 <= uVar9) {
      if (uVar7 != 0) goto LAB_fffffff0081eb16c;
      iVar12 = 8;
    }
  }
  else {
LAB_fffffff0081eb16c:
    iVar12 = (int)uVar7;
    if (iVar12 == 0) {
LAB_fffffff0081eb310:
      uVar4 = 1;
      goto LAB_fffffff0081eb314;
    }
  }
  lVar5 = 0x144;
  if (param_1[0x22] != 0) {
    lVar5 = 0x148;
  }
  uVar9 = (ulong)*(uint *)((long)param_1 + lVar5) << 0x11;
  if ((uVar11 < uVar9) && (lVar5 = (**(code **)(*param_1 + 0xd0))(param_1), lVar5 != 0)) {
    if ((*(byte *)(param_1 + 5) | 2) != 3) {
      *(undefined1 *)(param_1 + 5) = 2;
    }
    lVar14 = (ulong)*(uint *)(lVar5 + 0xc) * 8;
    plVar2 = (long *)(param_1[0x32] + (long)(int)lVar14);
    if (lVar14 - (int)lVar14 != 0) {
      plVar2 = (long *)(param_1[0x32] + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *plVar2 = lVar5;
    uVar7 = param_1[0x25] + 0x20000;
    param_1[0x25] = uVar7;
    while (((iVar12 = iVar12 + -1, iVar12 != 0 && (uVar7 < uVar9)) &&
           (lVar5 = (**(code **)(*param_1 + 0xd0))(param_1), lVar5 != 0))) {
      lVar14 = (ulong)*(uint *)(lVar5 + 0xc) * 8;
      plVar2 = (long *)(param_1[0x32] + (long)(int)lVar14);
      if (lVar14 - (int)lVar14 != 0) {
        plVar2 = (long *)(param_1[0x32] + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *plVar2 = lVar5;
      uVar7 = param_1[0x25] + 0x20000;
      param_1[0x25] = uVar7;
    }
  }
  uVar11 = param_1[0x25];
  if (uVar11 < (ulong)*(uint *)(param_1 + 0x28) << 0x11) {
    *(int *)(param_1 + 0x28) = (int)(uVar11 + 0x1ffff >> 0x11);
    param_1[0x2b] = uVar11 + 0x1ffff & 0x1fffffffe0000;
    if (uVar11 < param_5) {
      (**(code **)(*param_2 + 0xa0))(param_2,0,0);
      uVar4 = 0;
      *(undefined1 *)(param_6 + 0x1194) = 0;
      uVar11 = param_1[0x25];
      goto LAB_fffffff0081eb314;
    }
  }
  uVar4 = 0;
LAB_fffffff0081eb314:
  lVar5 = param_1[2];
  if ((*(byte *)(lVar5 + 0x1ac44) >> 3 & 1) != 0) {
    iVar12 = *(int *)(param_1[3] + 0x60);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930da4,uVar11,uVar4,(long)iVar12,param_1,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x1ac48));
    uVar11 = param_1[0x25];
  }
  if (uVar11 <= (ulong)param_1[0x2e]) {
    uVar11 = param_1[0x2e];
  }
  param_1[0x2e] = uVar11;
  return;
}

