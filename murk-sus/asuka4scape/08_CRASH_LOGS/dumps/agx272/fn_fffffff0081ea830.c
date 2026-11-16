// FUN_fffffff0081ea830 @ fffffff0081ea830 size=832

ulong FUN_fffffff0081ea830(long *param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  long *plVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  int iVar13;
  long lVar14;
  
  uVar3 = *(uint *)(param_1 + 0x27);
  uVar4 = *(uint *)(param_1 + 0x23);
  uVar5 = uVar4 + 10;
  if (uVar3 <= uVar4 + 10) {
    uVar5 = uVar3;
  }
  if (param_1[0x22] == 0) {
    lVar11 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4828,(ulong)uVar3 << 3);
    param_1[0x22] = lVar11;
    if (lVar11 == 0) {
      return 0;
    }
    uVar4 = *(uint *)(param_1 + 0x23);
  }
  uVar10 = (ulong)uVar4;
  if (uVar4 < uVar5) {
    lVar11 = uVar10 << 3;
    lVar12 = uVar5 - uVar10;
    do {
      if ((param_1[0x25] == (ulong)*(uint *)((long)param_1 + 0x14c) * 0x20000) ||
         (*(uint *)(param_1 + 0x23) == *(uint *)(param_1 + 0x27))) goto LAB_fffffff0081eab14;
      uVar5 = ((uint *)param_1[0x11])[1];
      uVar3 = *(uint *)param_1[0x11];
      if (uVar5 == uVar3) {
        plVar8 = (long *)(**(code **)(*param_1 + 0xd8))(param_1);
        if (plVar8 == (long *)0x0) goto LAB_fffffff0081eab14;
      }
      else {
        if (*(uint *)(param_1 + 0x27) <= uVar5) {
          uVar10 = thunk_EXT_FUN_8011000003a49114
                             (
                             "AGXk: %s:%d:%s: !!! Assertion failed: %s: OOB access in GPU Driver Resource\n"
                             );
          return uVar10;
        }
        lVar14 = (ulong)uVar5 * 8;
        puVar2 = (undefined8 *)(param_1[0x32] + (long)(int)lVar14);
        if (lVar14 - (int)lVar14 != 0) {
          puVar2 = (undefined8 *)(param_1[0x32] + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
        }
        plVar8 = (long *)*puVar2;
      }
      lVar14 = uVar10 * 8;
      iVar13 = (int)lVar14;
      puVar2 = (undefined8 *)(param_1[0x22] + (long)iVar13);
      if (lVar14 - iVar13 != 0) {
        puVar2 = (undefined8 *)(param_1[0x22] + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar2 = plVar8;
      uVar9 = (**(code **)(*plVar8 + 0x88))(plVar8,1);
      if ((uVar9 & 1) == 0) {
        if (uVar5 == uVar3) {
          (**(code **)(*param_1 + 0x110))(param_1,*(undefined8 *)(param_1[0x22] + lVar11));
          iVar13 = *(int *)param_1[0x11];
          if (iVar13 == 0) {
            iVar13 = (int)param_1[0x27];
          }
          *(int *)param_1[0x11] = iVar13 + -1;
          (**(code **)(**(long **)(param_1[0x22] + lVar11) + 0x28))();
        }
        *(undefined8 *)(param_1[0x22] + lVar11) = 0;
        goto LAB_fffffff0081eab14;
      }
      puVar2 = (undefined8 *)(param_1[0x22] + (long)iVar13);
      if (lVar14 - iVar13 != 0) {
        puVar2 = (undefined8 *)(param_1[0x22] + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *(int *)(param_1 + 0x23) = (int)param_1[0x23] + 1;
      (**(code **)(*param_1 + 0xe8))(param_1,*puVar2);
      DataMemoryBarrier(2,3);
      uVar1 = *(int *)(param_1[0x11] + 4) + 1;
      uVar6 = *(uint *)(param_1 + 0x27);
      uVar7 = 0;
      if (uVar6 != 0) {
        uVar7 = uVar1 / uVar6;
      }
      *(uint *)(param_1[0x11] + 4) = uVar1 - uVar7 * uVar6;
      if (uVar5 == uVar3) {
        lVar14 = (ulong)*(uint *)((long)plVar8 + 0xc) * 8;
        puVar2 = (undefined8 *)(param_1[0x32] + (long)(int)lVar14);
        if (lVar14 - (int)lVar14 != 0) {
          puVar2 = (undefined8 *)(param_1[0x32] + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar2 = plVar8;
        param_1[0x25] = param_1[0x25] + 0x20000;
      }
      uVar10 = uVar10 + 1;
      lVar11 = lVar11 + 8;
      lVar12 = lVar12 + -1;
    } while (lVar12 != 0);
  }
  lVar11 = param_1[2];
  if ((*(byte *)(lVar11 + 0x1ac44) >> 3 & 1) != 0) {
    lVar12 = param_1[0x25];
    iVar13 = *(int *)(param_1[3] + 0x60);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar11 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930da4,lVar12,2,(long)iVar13,param_1,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar11 + 0x1ac48));
  }
LAB_fffffff0081eab14:
  return (ulong)(uVar4 != *(uint *)(param_1 + 0x23));
}

