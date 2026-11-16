// FUN_fffffff0081e60cc @ fffffff0081e60cc size=804

long * FUN_fffffff0081e60cc(long param_1)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  ulong uVar8;
  long lVar9;
  long *plVar10;
  undefined8 uVar11;
  ulong uVar12;
  
  uVar1 = **(uint **)(param_1 + 0x1370);
  uVar12 = (ulong)uVar1;
  if (uVar1 != 0x40) {
    lVar9 = uVar12 * 0x40;
    uVar8 = param_1 + 0x160 + (long)(int)lVar9;
    if (lVar9 - (int)lVar9 != 0) {
      uVar8 = param_1 + 0x160 + lVar9 & 0xffffffffffffU | 0x2bad000000000000;
    }
    iVar4 = thunk_EXT_FUN_80110000029479f8(*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x148),uVar8)
    ;
    if (iVar4 != 0) {
      uVar8 = param_1 + 0x1160;
      uVar3 = (param_1 + 0x1360U) - uVar8;
      if ((param_1 + 0x1360U < uVar8) || (uVar3 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                  );
      }
      if (uVar12 * 8 - (long)(int)(uVar12 * 8) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                  );
      }
      if (((uVar12 & 0x1fffffff) >> 0x1c != 0) || (uVar2 = uVar1 * 8, (uint)uVar3 < uVar2 + 8)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                  );
      }
      plVar7 = (long *)(uVar8 + uVar2);
      uVar8 = (ulong)CARRY8(uVar8,(ulong)uVar2);
      uVar12 = -uVar8;
      if ((uVar12 != uVar8) || ((long)uVar12 < 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                  );
      }
      plVar10 = (long *)*plVar7;
      if (plVar10 != (long *)0x0) {
LAB_fffffff0081e62e8:
        uVar11 = **(undefined8 **)(param_1 + 0x1370);
        **(undefined8 **)(param_1 + 0x1370) =
             CONCAT44((int)((ulong)uVar11 >> 0x20) + 1,(int)uVar11 + 1);
        *(undefined1 *)(param_1 + 0x13b0) = 1;
        return plVar10;
      }
      plVar10 = (long *)(**(code **)(DAT_fffffff00ae23240 + 0x68))();
      if (plVar10 == (long *)0x0) {
        return (long *)0x0;
      }
      lVar9 = *(long *)(param_1 + 0x28);
      plVar10[0xe] = param_1;
      plVar10[0xf] = lVar9;
      thunk_EXT_FUN_8011000002946f14(plVar10 + 2);
      *(undefined1 *)(plVar10 + 10) = 0;
      iVar4 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))(plVar10);
      if (iVar4 != 0) {
        lVar9 = *(long *)(param_1 + 0x28);
        uVar11 = *(undefined8 *)(param_1 + 0x38);
        plVar5 = (long *)thunk_EXT_FUN_8011000003962c64
                                   (*(undefined4 *)(lVar9 + 0x18b70),0x4000000,
                                    (long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f)));
        if (plVar5 != (long *)0x0) {
          plVar6 = (long *)thunk_EXT_FUN_801100000297d1cc(lVar9,0,plVar5);
          plVar10[0xc] = (long)plVar6;
          if (plVar6 != (long *)0x0) {
            uVar12 = (ulong)(uVar1 << 0x1a) | 0x1300000000;
            lVar9 = (**(code **)(*plVar6 + 0xa0))(plVar6,uVar11,0x200000007,uVar12,0x4000000);
            plVar10[0xb] = lVar9;
            plVar6 = (long *)plVar10[0xc];
            if (lVar9 != 0) {
              (**(code **)(*plVar6 + 0x28))();
              if ((*(ushort *)(plVar10[0xb] + 0x10) & 1) == 0) {
                plVar7 = (long *)thunk_EXT_FUN_8011000003a49114
                                           (
                                           "AGXk: %s:%d:%s: !!! GPU virtual address not found for mesh shader block\n"
                                           );
                return plVar7;
              }
              plVar10[0xd] = uVar12;
              (**(code **)(*plVar5 + 0x28))(plVar5);
              *(uint *)((long)plVar10 + 0xc) = uVar1;
              *plVar7 = (long)plVar10;
              goto LAB_fffffff0081e62e8;
            }
            if (plVar6 != (long *)0x0) {
              (**(code **)(*plVar6 + 0x28))();
            }
            plVar10[0xc] = 0;
          }
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
      }
      (**(code **)(*plVar10 + 0x28))(plVar10);
    }
  }
  return (long *)0x0;
}

