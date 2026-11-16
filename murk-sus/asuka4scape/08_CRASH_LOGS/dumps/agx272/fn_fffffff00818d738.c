// FUN_fffffff00818d738 @ fffffff00818d738 size=1356

/* WARNING: Removing unreachable block (ram,0xfffffff00818d854) */
/* WARNING: Removing unreachable block (ram,0xfffffff00818d96c) */

long * FUN_fffffff00818d738(long param_1,ulong param_2,ulong param_3)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  long *plVar7;
  ulong uVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  long *plVar15;
  
  plVar7 = (long *)(**(code **)(DAT_fffffff00ae25b38 + 0x68))();
  if (plVar7 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to create work queue\n");
    return (long *)0x0;
  }
  uVar8 = (**(code **)(*plVar7 + 0xd8))
                    (plVar7,*(undefined8 *)(param_1 + 0x530),param_1,
                     *(undefined4 *)(param_1 + 0x848),
                     *(undefined4 *)(*(long *)(param_1 + 0x610) + 0x98),param_3 & 0xffffffff);
  if ((uVar8 & 1) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to init work queue\n");
    goto LAB_fffffff00818dae4;
  }
  lVar10 = *(long *)(param_1 + 0x610);
  if ((param_2 & 1) == 0) {
    iVar6 = FUN_fffffff008214518(plVar7,*(undefined8 *)(*(long *)(lVar10 + 0xb0) + 0x28));
    if (iVar6 == 0) goto LAB_fffffff00818dae4;
    lVar11 = *(long *)(*(long *)(param_1 + 0x530) + 0x1ac50);
    lVar10 = lVar11 + 0x1188;
    lVar12 = (ulong)*(uint *)(*(long *)(param_1 + 0x610) + 0x98) * 8;
    puVar1 = (undefined8 *)(lVar10 + (int)lVar12);
    if (lVar12 - (int)lVar12 != 0) {
      puVar1 = (undefined8 *)(lVar10 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5664(*(undefined8 *)(lVar11 + 200),*puVar1,1);
    uVar14 = *(undefined8 *)(param_1 + 0x488);
    plVar15 = (long *)plVar7[0x18];
    lVar10 = plVar7[0x20];
    plVar9 = (long *)(**(code **)(*plVar15 + 0x878))(*plVar15 + 0x878,plVar15);
    if (plVar9 != (long *)0x0) {
      uVar8 = (**(code **)(*plVar9 + 0x78))(plVar9,plVar15,uVar14,lVar10);
      if ((uVar8 & 1) != 0) {
        plVar7[0x46] = (long)plVar9;
        if (((*(byte *)(*(long *)(param_1 + 0x918) + 0x24) & 1) == 0) &&
           (*(int *)(*(long *)(param_1 + 0x610) + 0x98) != 0)) {
          iVar6 = FUN_fffffff008214808
                            (plVar7,*(undefined8 *)
                                     (*(long *)(*(long *)(param_1 + 0x610) + 0x28) + 0x228));
          if (iVar6 == 0) goto LAB_fffffff00818dae4;
          lVar10 = *(long *)(param_1 + 0x610);
        }
        else {
          *(ulong *)(*(long *)(param_1 + 0x918) + 0x28) = param_3 & 0xffffffff;
          iVar6 = FUN_fffffff00821465c(plVar7,*(undefined8 *)(param_1 + 0x488));
          if (iVar6 == 0) {
            *(undefined8 *)(*(long *)(param_1 + 0x918) + 0x28) = 0;
            goto LAB_fffffff00818dae4;
          }
          lVar12 = plVar7[0x45];
          lVar10 = *(long *)(param_1 + 0x610);
          lVar11 = *(long *)(param_1 + 0x918);
          if ((*(byte *)(*(long *)(lVar12 + 0x10) + 0x11181) & 1) == 0) {
            uVar3 = *(int *)(lVar11 + 0x20) + *(int *)(lVar10 + 0x98);
            uVar4 = *(uint *)(*(long *)(param_1 + 0x530) + 0x418);
            uVar5 = 0;
            if (uVar4 != 0) {
              uVar5 = uVar3 / uVar4;
            }
            iVar6 = uVar3 - uVar5 * uVar4;
          }
          else {
            iVar6 = *(int *)(*(long *)(lVar12 + 0x10) + 0x11184);
          }
          *(int *)(lVar12 + 0x1c4) = iVar6;
          *(int *)(*(long *)(*(long *)(lVar12 + 0x20) + 0x48) + 0xc) = iVar6;
          *(undefined8 *)(lVar11 + 0x28) = 0;
        }
        goto LAB_fffffff00818d7dc;
      }
      (**(code **)(*plVar9 + 0x28))(plVar9);
    }
    plVar7[0x46] = 0;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to create Render Target Memory\n")
    ;
  }
  else {
LAB_fffffff00818d7dc:
    uVar14 = *(undefined8 *)(*(long *)(lVar10 + 0xb0) + 0x28);
    plVar9 = (long *)(**(code **)(*(long *)plVar7[0x18] + 0x840))();
    plVar7[0x44] = (long)plVar9;
    if (plVar9 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to create FRG channel\n");
    }
    else {
      thunk_EXT_FUN_8011000003890f30(plVar7[3],&DAT_fffffff00ae21f50);
      uVar8 = (**(code **)(*plVar9 + 0x178))
                        (*plVar9 + 0x178,plVar9,plVar7[3],plVar7,(int)plVar7[0x1d],
                         *(undefined4 *)((long)plVar7 + 0x54),uVar14);
      if ((uVar8 & 1) != 0) {
        lVar11 = *(long *)(*(long *)(param_1 + 0x530) + 0x1ac50);
        lVar10 = lVar11 + 0x11b0;
        lVar12 = (ulong)*(uint *)(*(long *)(param_1 + 0x610) + 0x98) * 8;
        puVar1 = (undefined8 *)(lVar10 + (int)lVar12);
        if (lVar12 - (int)lVar12 != 0) {
          puVar1 = (undefined8 *)(lVar10 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
        }
        thunk_EXT_FUN_80110000039b5664(*(undefined8 *)(lVar11 + 0xd0),*puVar1,1);
        uVar3 = *(uint *)(param_1 + 0x7ec);
        uVar8 = (ulong)uVar3;
        if (*(int *)(param_1 + 0x44c) == 1) {
          uVar13 = *(undefined4 *)(param_1 + 0x450);
          plVar9 = (long *)plVar7[0x43];
        }
        else {
          uVar13 = 2;
          plVar9 = (long *)plVar7[0x43];
        }
        if (plVar9 != (long *)0x0) {
          (**(code **)(*plVar9 + 0x110))(plVar9,uVar8,uVar13);
        }
        (**(code **)(*(long *)plVar7[0x44] + 0x110))((long *)plVar7[0x44],uVar8,uVar13);
        if ((uVar3 < 6) && ((0x37U >> (ulong)(uVar3 & 0x1f) & 1) != 0)) {
          lVar10 = uVar8 * 4;
          puVar2 = (undefined4 *)(&DAT_fffffff007115cc0 + (int)lVar10);
          if (lVar10 - (int)lVar10 != 0) {
            puVar2 = (undefined4 *)
                     ((ulong)(&DAT_fffffff007115cc0 + lVar10) & 0xffffffffffff | 0x2bad000000000000)
            ;
          }
          thunk_EXT_FUN_8011000002958c50(plVar7,*puVar2);
          return plVar7;
        }
        plVar7 = (long *)thunk_EXT_FUN_8011000003a49114
                                   (
                                   "AGXk: %s:%d:%s: !!! Invalid priority %d used for work queue 0x%p\n"
                                   );
        return plVar7;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to init FRG channel\n");
      if ((long *)plVar7[0x44] != (long *)0x0) {
        (**(code **)(*(long *)plVar7[0x44] + 0x28))();
      }
      plVar7[0x44] = 0;
    }
  }
LAB_fffffff00818dae4:
  (**(code **)(*plVar7 + 0x28))(plVar7);
  return (long *)0x0;
}

