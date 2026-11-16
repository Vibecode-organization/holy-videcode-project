// FUN_fffffff00a1dd018 @ fffffff00a1dd018 size=812

undefined8 FUN_fffffff00a1dd018(long param_1,long *param_2,long param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  char *pcVar9;
  long lVar10;
  undefined8 *puVar11;
  ulong *puVar12;
  
  lVar7 = *(long *)(param_1 + 0x310);
  if (lVar7 == 0) {
    lVar7 = 0;
  }
  lVar1 = tpidr_el1;
  *(int *)(lVar1 + 0x1c0) = *(int *)(lVar1 + 0x1c0) + 1;
  LOAcquire();
  uVar2 = *(uint *)(lVar7 + 8);
  *(uint *)(lVar7 + 8) = uVar2 + 0x1000000;
  if ((uVar2 >> 0x10 & 0xff) == uVar2 >> 0x18) {
    *(undefined4 *)(lVar7 + 0xc) = *(undefined4 *)(lVar1 + 0x4e8);
  }
  else {
    FUN_fffffff00a1ef300(lVar7,uVar2 >> 0x18,lVar1);
  }
  puVar12 = (ulong *)(lVar7 + 0x48);
  if ((*puVar12 == 0) || (*puVar12 == 0)) goto LAB_fffffff00a1dd2e0;
  uVar8 = *puVar12;
  if (uVar8 == 0) {
    uVar8 = 0;
LAB_fffffff00a1dd0e8:
    lVar4 = 0;
    uVar6 = 0;
  }
  else if ((uVar8 >> 0x26 & 1) == 0) {
    if (uVar8 == 0) goto LAB_fffffff00a1dd0e8;
    lVar4 = (uVar8 & 0x3fff) << 0xe;
    uVar6 = uVar8 & 0xffffffbfffffc000 | 0x4000000000;
  }
  else {
    lVar4 = (uVar8 & 0x10 | 0x20) << (uVar8 & 0xf);
    uVar6 = uVar8 & 0xffffffffffffffe0;
  }
  lVar10 = 0;
  puVar11 = (undefined8 *)0x0;
  if (uVar6 + 0x30 <= uVar6 + lVar4) {
    puVar11 = (undefined8 *)(uVar6 + 0x18);
  }
  uVar2 = 1;
  while( true ) {
    uVar6 = 0;
    if (uVar8 != 0) {
      uVar6 = uVar8 & 0xffffffbfffffc000 | 0x4000000000;
    }
    lVar4 = (uVar8 & 0x3fff) << 0xe;
    if ((uVar8 & 0x4000000000) != 0) {
      uVar6 = uVar8 & 0xffffffffffffffe0;
      lVar4 = (uVar8 & 0x10 | 0x20) << (uVar8 & 0xf);
    }
    do {
      if ((*(uint *)(puVar11 + 1) >> 0x10 & 1) != 0) {
        pcVar9 = (char *)*puVar11;
        if (pcVar9 == (char *)0x0) {
          pcVar9 = (char *)0x0;
        }
        if (((((char *)0x1 < pcVar9 + 1) && ((pcVar9[1] & 7U) != 0)) && (*pcVar9 == '\x1f')) &&
           (*(long *)(pcVar9 + 0x50) != 0)) {
          if (param_3 != 0) {
            uVar3 = (**(code **)(param_3 + 0x10))
                              (param_3,lVar10,
                               (uint)(CONCAT44(uVar2,*(uint *)(puVar11 + 1)) >> 0x18) | 3,
                               *(long *)(pcVar9 + 0x50));
            if (uVar3 == 0) {
              param_3 = 0;
            }
            if (((uVar3 & 1) == 0) && (param_2 == (long *)0x0)) {
              FUN_fffffff00a1ef5a8(lVar7);
              return 0;
            }
          }
          lVar10 = lVar10 + 1;
        }
      }
      if ((puVar11 + 3 == (undefined8 *)0x0) || ((undefined8 *)(uVar6 + lVar4) < puVar11 + 6)) {
        FUN_fffffff00a1ef5a8(lVar7);
        if (param_2 == (long *)0x0) {
          return 0;
        }
        *param_2 = lVar10;
        return 0;
      }
      uVar2 = uVar2 + 1;
      puVar11 = puVar11 + 3;
    } while ((uVar2 & 0xfff) != 0);
    FUN_fffffff00a1ef5a8(lVar7);
    *(int *)(lVar1 + 0x1c0) = *(int *)(lVar1 + 0x1c0) + 1;
    LOAcquire();
    uVar3 = *(uint *)(lVar7 + 8);
    *(uint *)(lVar7 + 8) = uVar3 + 0x1000000;
    if ((uVar3 >> 0x10 & 0xff) == uVar3 >> 0x18) {
      *(undefined4 *)(lVar7 + 0xc) = *(undefined4 *)(lVar1 + 0x4e8);
    }
    else {
      FUN_fffffff00a1ef300(lVar7,uVar3 >> 0x18,lVar1);
    }
    if ((*puVar12 == 0) || (*puVar12 == 0)) break;
    uVar6 = *puVar12;
    if (uVar6 == 0) {
      uVar8 = 0;
      uVar5 = 0;
    }
    else {
      uVar8 = 0;
      if (uVar6 != 0) {
        uVar8 = uVar6;
      }
      uVar5 = 0;
      if (uVar6 != 0) {
        uVar5 = uVar6 & 0xffffffbfffffc000 | 0x4000000000;
      }
      if ((uVar6 & 0x4000000000) != 0) {
        uVar8 = uVar6;
        uVar5 = uVar6 & 0xffffffffffffffe0;
      }
    }
    puVar11 = (undefined8 *)(uVar5 + (ulong)uVar2 * 0x18);
    if (((uVar5 ^ (ulong)puVar11) & 0xffc0000000000000) != 0) {
      puVar11 = (undefined8 *)((ulong)puVar11 & 0xffffffffffff | 0xc8a2000000000000);
    }
  }
LAB_fffffff00a1dd2e0:
  FUN_fffffff00a1ef5a8(lVar7);
  return 0x10;
}

