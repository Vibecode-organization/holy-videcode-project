// FUN_fffffff00819cb78 @ fffffff00819cb78 size=908

/* WARNING: Removing unreachable block (ram,0xfffffff00819ccc0) */
/* WARNING: Removing unreachable block (ram,0xfffffff00819ce84) */

ulong FUN_fffffff00819cb78(long param_1,long *param_2,ulong param_3,undefined8 *param_4)

{
  uint *puVar1;
  ulong *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined8 *puVar5;
  long *plVar6;
  undefined8 uVar7;
  ulong uVar8;
  int iVar9;
  int iVar10;
  ulong uVar11;
  long lVar12;
  uint uVar13;
  ulong uVar14;
  long lVar15;
  long lVar16;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 8));
  uVar13 = *(uint *)(param_2 + 0x3d);
  uVar14 = (ulong)uVar13;
  if (uVar13 == 0xffffffff) {
    uVar13 = *(uint *)(param_1 + 0x48);
    if ((int)uVar13 < 0) {
      iVar10 = *(int *)(param_1 + 0x14);
      uVar14 = (ulong)iVar10;
      if (iVar10 < *(int *)(param_1 + 0x10)) {
        iVar10 = *(int *)(param_1 + 0x10) - iVar10;
        do {
          lVar12 = uVar14 * 4;
          piVar4 = (int *)(*(long *)(param_1 + 0x38) + (long)(int)lVar12);
          if (lVar12 - (int)lVar12 != 0) {
            piVar4 = (int *)(*(long *)(param_1 + 0x38) + lVar12 & 0xffffffffffffU |
                            0x2bad000000000000);
          }
          if (*piVar4 == 0) {
            if (uVar14 != 0xffffffffffffffff) {
              uVar13 = (uint)uVar14;
              uVar8 = (uVar14 & 0xffffffff) << 3;
              uVar11 = -(uVar14 >> 0x1f & 1) & 0xfffffff800000000 | uVar8;
              iVar10 = (int)uVar8;
              plVar6 = (long *)(*(long *)(param_1 + 0x30) + (long)iVar10);
              if (uVar11 != (long)iVar10) {
                plVar6 = (long *)(*(long *)(param_1 + 0x30) + uVar11 & 0xffffffffffff |
                                 0x2bad000000000000);
              }
              thunk_EXT_FUN_8011000003223a00(*(undefined8 *)(*plVar6 + 0x1d0));
              puVar5 = (undefined8 *)(*(long *)(param_1 + 0x30) + (long)iVar10);
              if (uVar11 != (long)iVar10) {
                puVar5 = (undefined8 *)
                         (*(long *)(param_1 + 0x30) + uVar11 & 0xffffffffffff | 0x2bad000000000000);
              }
              lVar12 = *(long *)*puVar5;
              (**(code **)(lVar12 + 0x128))(lVar12 + 0x128,(long *)*puVar5,0xffffffff);
              plVar6 = (long *)(*(long *)(param_1 + 0x30) + (long)iVar10);
              if (uVar11 != (long)iVar10) {
                plVar6 = (long *)(*(long *)(param_1 + 0x30) + uVar11 & 0xffffffffffff |
                                 0x2bad000000000000);
              }
              thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(*plVar6 + 0x1d0));
              goto LAB_fffffff00819cc70;
            }
            break;
          }
          uVar14 = uVar14 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
    }
    else {
      *(uint *)(param_1 + 0x48) = uVar13 - 1;
      lVar12 = (ulong)uVar13 * 4;
      puVar1 = (uint *)(*(long *)(param_1 + 0x40) + (long)(int)lVar12);
      if (lVar12 - (int)lVar12 != 0) {
        puVar1 = (uint *)(*(long *)(param_1 + 0x40) + lVar12 & 0xffffffffffffU | 0x2bad000000000000)
        ;
      }
      uVar13 = *puVar1;
      uVar14 = (ulong)uVar13;
      if (uVar13 != 0xffffffff) {
LAB_fffffff00819cc70:
        lVar15 = (long)(int)uVar13;
        thunk_EXT_FUN_8011000003223a00(param_2[0x3a]);
        lVar12 = lVar15 * 4;
        piVar4 = (int *)(*(long *)(param_1 + 0x38) + (long)(int)lVar12);
        if (lVar12 - (int)lVar12 != 0) {
          piVar4 = (int *)(*(long *)(param_1 + 0x38) + lVar12 & 0xffffffffffffU | 0x2bad000000000000
                          );
        }
        *piVar4 = *piVar4 + 1;
        (**(code **)(*param_2 + 0x128))(*param_2 + 0x128,param_2,uVar14);
        if ((*(int *)(param_1 + 0x10) < 2) ||
           (iVar10 = 1 << (ulong)(-(int)LZCOUNT(*(int *)(param_1 + 0x10) + -1) & 0x1f), iVar10 < 2))
        {
          uVar8 = 0xffffffffffffffff;
          uVar11 = 0;
        }
        else {
          iVar10 = (int)LZCOUNT(iVar10 + -1);
          uVar11 = (ulong)(iVar10 + 0x20);
          uVar8 = 0xffffffffffffffff;
          if (iVar10 != 0x20) {
            uVar8 = ~(-1L << (uVar11 & 0x3f));
          }
        }
        lVar16 = lVar15 * 8;
        lVar12 = *(long *)(param_1 + 0x30);
        iVar10 = (int)lVar16;
        puVar2 = (ulong *)(*(long *)(param_1 + 0x28) + (long)iVar10);
        if (lVar16 - iVar10 != 0) {
          puVar2 = (ulong *)(*(long *)(param_1 + 0x28) + lVar16 & 0xffffffffffffU |
                            0x2bad000000000000);
        }
        *puVar2 = (*puVar2 & uVar8) + 1 & uVar8 | lVar15 << (uVar11 & 0x3f);
        plVar6 = (long *)(lVar12 + iVar10);
        if (lVar16 - iVar10 != 0) {
          plVar6 = (long *)(lVar12 + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *plVar6 = (long)param_2;
        if ((int)param_3 != 0x80) {
          uVar8 = (param_3 & 0xffffffff) << 2;
          uVar11 = -(param_3 >> 0x1f & 1) & 0xfffffffc00000000 | uVar8;
          iVar9 = (int)uVar8;
          puVar3 = (undefined4 *)(*(long *)(param_1 + 0x20) + (long)iVar9);
          if (uVar11 != (long)iVar9) {
            puVar3 = (undefined4 *)
                     (*(long *)(param_1 + 0x20) + uVar11 & 0xffffffffffff | 0x2bad000000000000);
          }
          *puVar3 = (int)uVar14;
        }
        thunk_EXT_FUN_8011000003224d30(param_2[0x3a]);
        *(undefined1 *)(param_1 + 0x1c) = 0;
        puVar5 = (undefined8 *)(*(long *)(param_1 + 0x28) + (long)iVar10);
        if (lVar16 - iVar10 != 0) {
          puVar5 = (undefined8 *)
                   (*(long *)(param_1 + 0x28) + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar7 = *puVar5;
        goto LAB_fffffff00819cdc4;
      }
    }
    *(undefined1 *)(param_1 + 0x1c) = 1;
    uVar14 = 0xffffffff;
  }
  else {
    if ((int)param_3 != 0x80) {
      uVar8 = (param_3 & 0xffffffff) << 2;
      uVar11 = -(param_3 >> 0x1f & 1) & 0xfffffffc00000000 | uVar8;
      iVar10 = (int)uVar8;
      puVar1 = (uint *)(*(long *)(param_1 + 0x20) + (long)iVar10);
      if (uVar11 != (long)iVar10) {
        puVar1 = (uint *)(*(long *)(param_1 + 0x20) + uVar11 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar1 = uVar13;
    }
    lVar12 = (long)(int)uVar13 * 4;
    piVar4 = (int *)(*(long *)(param_1 + 0x38) + (long)(int)lVar12);
    if (lVar12 - (int)lVar12 != 0) {
      piVar4 = (int *)(*(long *)(param_1 + 0x38) + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *piVar4 = *piVar4 + 1;
    lVar12 = (long)(int)uVar13 * 8;
    puVar5 = (undefined8 *)(*(long *)(param_1 + 0x28) + (long)(int)lVar12);
    if (lVar12 - (int)lVar12 != 0) {
      puVar5 = (undefined8 *)
               (*(long *)(param_1 + 0x28) + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar7 = *puVar5;
LAB_fffffff00819cdc4:
    *param_4 = uVar7;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 8));
  return uVar14;
}

