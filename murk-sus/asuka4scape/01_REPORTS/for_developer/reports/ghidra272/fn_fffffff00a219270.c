// FUN_fffffff00a219270 @ fffffff00a219270 size=872

undefined8 FUN_fffffff00a219270(long param_1,long *param_2,long param_3)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  char *pcVar10;
  long lVar11;
  undefined8 *puVar12;
  ulong *puVar13;
  
  lVar8 = *(long *)(param_1 + 0x310);
  if (lVar8 == 0) {
    lVar8 = 0;
  }
  lVar1 = tpidr_el1;
  *(int *)(lVar1 + 0x1c0) = *(int *)(lVar1 + 0x1c0) + 1;
  LOAcquire();
  uVar4 = *(uint *)(lVar8 + 8);
  *(uint *)(lVar8 + 8) = uVar4 + 0x1000000;
  if ((uVar4 >> 0x10 & 0xff) == uVar4 >> 0x18) {
    *(undefined4 *)(lVar8 + 0xc) = *(undefined4 *)(lVar1 + 0x4e8);
  }
  else {
    FUN_fffffff00a22b5a8(lVar8,uVar4 >> 0x18,lVar1);
  }
  puVar13 = (ulong *)(lVar8 + 0x48);
  if ((*puVar13 == 0) || (*puVar13 == 0)) goto LAB_fffffff00a219558;
  uVar9 = *puVar13;
  if (uVar9 == 0) {
    uVar9 = 0;
LAB_fffffff00a219340:
    lVar11 = 0;
    uVar7 = 0;
  }
  else if ((uVar9 >> 0x26 & 1) == 0) {
    if (uVar9 == 0) goto LAB_fffffff00a219340;
    lVar11 = (uVar9 & 0x3fff) << 0xe;
    uVar7 = uVar9 & 0xffffffbfffffc000 | 0x4000000000;
  }
  else {
    lVar11 = (uVar9 & 0x10 | 0x20) << (uVar9 & 0xf);
    uVar7 = uVar9 & 0xffffffffffffffe0;
  }
  if (uVar7 + lVar11 < uVar7 + 0x30) {
    puVar12 = (undefined8 *)0x0;
  }
  else {
    puVar12 = (undefined8 *)(uVar7 + 0x18);
  }
  if (puVar12 == (undefined8 *)0x0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2195d8);
    (*pcVar3)();
  }
  uVar4 = 1;
  lVar11 = 0;
  while( true ) {
    uVar7 = 0;
    if (uVar9 != 0) {
      uVar7 = uVar9 & 0xffffffbfffffc000 | 0x4000000000;
    }
    lVar2 = (uVar9 & 0x3fff) << 0xe;
    if ((uVar9 & 0x4000000000) != 0) {
      uVar7 = uVar9 & 0xffffffffffffffe0;
      lVar2 = (uVar9 & 0x10 | 0x20) << (uVar9 & 0xf);
    }
    do {
      if ((*(uint *)(puVar12 + 1) >> 0x10 & 1) != 0) {
        pcVar10 = (char *)*puVar12;
        if (pcVar10 == (char *)0x0) {
          pcVar10 = (char *)0x0;
        }
        if (((((char *)0x1 < pcVar10 + 1) && ((pcVar10[1] & 7U) != 0)) && (*pcVar10 == '\x1f')) &&
           (*(long *)(pcVar10 + 0x50) != 0)) {
          if (param_3 != 0) {
            uVar5 = (**(code **)(param_3 + 0x10))
                              (param_3,lVar11,
                               (uint)(CONCAT44(uVar4,*(uint *)(puVar12 + 1)) >> 0x18) | 3,
                               *(long *)(pcVar10 + 0x50));
            if (uVar5 == 0) {
              param_3 = 0;
            }
            if (((uVar5 & 1) == 0) && (param_2 == (long *)0x0)) {
              FUN_fffffff00a22b850(lVar8);
              return 0;
            }
          }
          lVar11 = lVar11 + 1;
        }
      }
      if (((undefined8 *)(uVar7 + lVar2) < puVar12 + 6) ||
         (puVar12 = puVar12 + 3, puVar12 == (undefined8 *)0x0)) {
        FUN_fffffff00a22b850(lVar8);
        if (param_2 == (long *)0x0) {
          return 0;
        }
        *param_2 = lVar11;
        return 0;
      }
      uVar4 = uVar4 + 1;
    } while ((uVar4 & 0xfff) != 0);
    FUN_fffffff00a22b850(lVar8);
    *(int *)(lVar1 + 0x1c0) = *(int *)(lVar1 + 0x1c0) + 1;
    LOAcquire();
    uVar5 = *(uint *)(lVar8 + 8);
    *(uint *)(lVar8 + 8) = uVar5 + 0x1000000;
    if ((uVar5 >> 0x10 & 0xff) == uVar5 >> 0x18) {
      *(undefined4 *)(lVar8 + 0xc) = *(undefined4 *)(lVar1 + 0x4e8);
    }
    else {
      FUN_fffffff00a22b5a8(lVar8,uVar5 >> 0x18,lVar1);
    }
    if ((*puVar13 == 0) || (*puVar13 == 0)) break;
    uVar7 = *puVar13;
    if (uVar7 == 0) {
      uVar9 = 0;
      uVar6 = 0;
    }
    else {
      uVar9 = 0;
      if (uVar7 != 0) {
        uVar9 = uVar7;
      }
      uVar6 = 0;
      if (uVar7 != 0) {
        uVar6 = uVar7 & 0xffffffbfffffc000 | 0x4000000000;
      }
      if ((uVar7 & 0x4000000000) != 0) {
        uVar9 = uVar7;
        uVar6 = uVar7 & 0xffffffffffffffe0;
      }
    }
    puVar12 = (undefined8 *)(uVar6 + (ulong)uVar4 * 0x18);
    if (((uVar6 ^ (ulong)puVar12) & 0xffc0000000000000) != 0) {
      puVar12 = (undefined8 *)((ulong)puVar12 & 0xffffffffffff | 0xc8a2000000000000);
    }
  }
LAB_fffffff00a219558:
  FUN_fffffff00a22b850(lVar8);
  return 0x10;
}

