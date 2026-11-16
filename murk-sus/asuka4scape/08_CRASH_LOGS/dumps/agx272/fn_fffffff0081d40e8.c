// FUN_fffffff0081d40e8 @ fffffff0081d40e8 size=536

void FUN_fffffff0081d40e8(long param_1,long param_2,ulong param_3)

{
  bool bVar1;
  long *plVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  
  if (param_3 == 0) {
    param_3 = 0xffffffffffffffff;
  }
  uVar5 = *(ulong *)(param_1 + 0x28);
  uVar6 = uVar5 - 1;
  if (0 < (long)uVar5) {
    lVar7 = *(long *)(param_1 + 0x20);
    lVar8 = uVar5 * 0x18 + -8;
    plVar2 = (long *)(lVar7 + (int)lVar8);
    if (lVar8 != (int)lVar8) {
      plVar2 = (long *)(lVar7 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar8 = **(long **)(*plVar2 + 8);
    if (lVar8 == 0) {
      if (uVar6 != 0) {
        lVar10 = 2 - uVar5;
        do {
          lVar8 = uVar6 * 0x18 + -8;
          plVar2 = (long *)(lVar7 + (int)lVar8);
          if (lVar8 != (int)lVar8) {
            plVar2 = (long *)(lVar7 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
          }
          lVar8 = **(long **)(*plVar2 + 8);
          if (lVar8 != 0) {
            uVar6 = -lVar10;
            goto LAB_fffffff0081d415c;
          }
          uVar6 = uVar6 - 1;
          lVar10 = lVar10 + 1;
        } while (lVar10 != 1);
      }
    }
    else {
LAB_fffffff0081d415c:
      lVar10 = **(long **)(*(long *)(lVar8 + 0x28) + 8);
      while (lVar10 == 0) {
        do {
          if (uVar5 <= uVar6) {
            lVar10 = 0;
            goto LAB_fffffff0081d4170;
          }
          uVar9 = uVar6 - 1;
          bVar1 = uVar6 == 0;
          uVar6 = uVar9;
        } while (bVar1);
        lVar10 = uVar9 * 0x18 + 0x10;
        plVar2 = (long *)(lVar7 + (int)lVar10);
        if (lVar10 != (int)lVar10) {
          plVar2 = (long *)(lVar7 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
        }
        lVar10 = **(long **)(*plVar2 + 8);
      }
LAB_fffffff0081d4170:
      uVar5 = 0;
LAB_fffffff0081d4188:
      uVar9 = uVar6;
      lVar7 = lVar10;
      lVar8 = *(long *)(lVar8 + 0x10);
      iVar4 = (**(code **)(param_2 + 0x10))(param_2);
      uVar5 = lVar8 + uVar5;
      if ((iVar4 != 0 && uVar5 < param_3) && lVar7 != 0) {
        lVar10 = **(long **)(*(long *)(lVar7 + 0x28) + 8);
        lVar8 = lVar7;
        uVar6 = uVar9;
        if (lVar10 == 0) {
          uVar3 = uVar9;
          if (-2 < (long)uVar9) {
            uVar3 = 0xffffffffffffffff;
          }
          uVar6 = uVar3;
          if (-1 < (long)uVar9) {
            uVar6 = uVar9;
            do {
              if (*(long *)(param_1 + 0x28) <= (long)uVar9) {
                lVar10 = 0;
                break;
              }
              if (uVar6 == 0) {
                lVar10 = 0;
                uVar6 = uVar3;
                break;
              }
              uVar6 = uVar6 - 1;
              lVar7 = uVar6 * 0x18 + 0x10;
              plVar2 = (long *)(*(long *)(param_1 + 0x20) + (long)(int)lVar7);
              if (lVar7 != (int)lVar7) {
                plVar2 = (long *)(*(long *)(param_1 + 0x20) + lVar7 & 0xffffffffffffU |
                                 0x2bad000000000000);
              }
              lVar10 = **(long **)(*plVar2 + 8);
            } while (**(long **)(*plVar2 + 8) == 0);
          }
        }
        goto LAB_fffffff0081d4188;
      }
    }
  }
  return;
}

