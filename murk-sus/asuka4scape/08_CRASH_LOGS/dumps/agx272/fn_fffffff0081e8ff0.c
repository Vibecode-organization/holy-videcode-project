// FUN_fffffff0081e8ff0 @ fffffff0081e8ff0 size=724

/* WARNING: Removing unreachable block (ram,0xfffffff0081e925c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081e91b4) */

undefined8
FUN_fffffff0081e8ff0
          (long param_1,long param_2,long param_3,int *param_4,undefined8 *param_5,
          undefined8 *param_6,undefined8 param_7)

{
  uint uVar1;
  byte bVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  long *plVar10;
  long lVar11;
  
  uVar4 = 0;
  if ((param_2 != 0) && (param_3 != 0)) {
    if (*param_4 != -1) {
      if ((param_4[1] == -1 && param_4[2] == -1) || (*(ulong *)(param_3 + 0x20) == 0)) {
        return 0;
      }
      uVar5 = 1;
      uVar7 = 0;
      while( true ) {
        uVar6 = uVar5;
        lVar11 = *(long *)(*(long *)(param_3 + 0x18) + uVar7 * 8);
        if (lVar11 == 0) {
          return 0;
        }
        if (*(int *)(lVar11 + 0x88) == *param_4) break;
        uVar5 = (ulong)((int)uVar6 + 1);
        uVar7 = uVar6;
        if (*(ulong *)(param_3 + 0x20) <= uVar6) {
          return 0;
        }
      }
      plVar9 = *(long **)(lVar11 + 0xb8);
      if (plVar9 == (long *)0x0) {
        plVar9 = *(long **)(*(long *)(lVar11 + 0x50) + 0x4b0);
        plVar9 = (long *)(**(code **)(*plVar9 + 0x170))(plVar9,*(undefined8 *)(lVar11 + 0x28),0xb,0)
        ;
        if (plVar9 == (long *)0x0) {
          return 0;
        }
        *(long **)(lVar11 + 0xb8) = plVar9;
        bVar2 = *(byte *)(lVar11 + 0xb1);
      }
      else {
        bVar2 = *(byte *)(lVar11 + 0xb1);
      }
      if ((bVar2 & 1) != 0) {
        uVar5 = *(ulong *)(lVar11 + 0x78);
        if (0x8000 < uVar5 ||
            (uVar5 & (uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f))) != 0) {
          return 0;
        }
        uVar1 = param_4[1];
        if (uVar1 != 0xffffffff) {
          if (uVar5 >> 3 <= (ulong)uVar1) {
            return 0;
          }
          plVar10 = *(long **)(*(long *)(param_1 + 0x10) + 0x4b0);
          lVar3 = (**(code **)(*plVar9 + 0x98))(plVar9);
          lVar8 = *plVar10;
          uVar4 = (**(code **)(lVar8 + 0x208))(lVar8 + 0x208,plVar10,lVar3 + (ulong)(uVar1 << 3),0);
          *param_5 = uVar4;
        }
        uVar1 = param_4[2];
        if (uVar1 != 0xffffffff) {
          if (*(ulong *)(lVar11 + 0x78) >> 3 <= (ulong)uVar1) {
            return 0;
          }
          plVar10 = *(long **)(*(long *)(param_1 + 0x10) + 0x4b0);
          lVar11 = (**(code **)(*plVar9 + 0x98))(plVar9);
          lVar3 = *plVar10;
          uVar4 = (**(code **)(lVar3 + 0x208))(lVar3 + 0x208,plVar10,lVar11 + (ulong)(uVar1 << 3),0)
          ;
          *param_6 = uVar4;
        }
        thunk_EXT_FUN_8011000002969a34(param_7,plVar9);
        return 1;
      }
      return 0;
    }
    uVar4 = 1;
  }
  return uVar4;
}

