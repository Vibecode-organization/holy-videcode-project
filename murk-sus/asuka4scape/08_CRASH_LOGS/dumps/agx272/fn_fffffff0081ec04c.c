// FUN_fffffff0081ec04c @ fffffff0081ec04c size=1540

/* WARNING: Removing unreachable block (ram,0xfffffff0081ec1c8) */

undefined8 FUN_fffffff0081ec04c(long param_1)

{
  uint uVar1;
  undefined *puVar2;
  bool bVar3;
  int iVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long lVar8;
  undefined4 uVar9;
  long lVar10;
  undefined8 uVar11;
  
  plVar5 = (long *)(**(code **)(DAT_fffffff00ae23390 + 0x68))();
  if (plVar5 == (long *)0x0) {
    return 0;
  }
  lVar10 = *(long *)(param_1 + 0x10);
  plVar5[0x13] = param_1;
  plVar5[3] = lVar10;
  plVar5[0xd] = -1;
  iVar4 = (**(code **)(PTR_DAT_fffffff007ca60e0 + 0x78))();
  if (iVar4 != 0) {
    *(undefined4 *)(plVar5 + 2) = 0xffffffff;
    bVar3 = (*(ulong *)(plVar5[3] + 0x5c8) & 0x200000000000) != 0;
    uVar11 = 0x4000000003;
    if (bVar3) {
      uVar11 = 0x5000000003;
    }
    uVar9 = 5;
    if (bVar3) {
      uVar9 = 1;
    }
    plVar6 = (long *)FUN_fffffff0081f9fc0
                               (plVar5[3],*(undefined8 *)(param_1 + 0x18),
                                (ulong)*(uint *)(param_1 + 0x138) * *(long *)(param_1 + 0x1c8) * 4,
                                uVar11,uVar9);
    plVar5[4] = (long)plVar6;
    if (plVar6 != (long *)0x0) {
      (**(code **)(*plVar6 + 0x20))();
      (**(code **)(*(long *)plVar5[4] + 0xb0))((long *)plVar5[4],*(undefined8 *)(param_1 + 0x18));
      lVar10 = *(long *)(plVar5[4] + 0x28);
      if (*(uint *)(lVar10 + 0x78) < *(uint *)(plVar5[0x13] + 0x108)) {
        thunk_EXT_FUN_801100000293ff9c();
        lVar10 = *(long *)(plVar5[4] + 0x28);
      }
      plVar5[0xe] = 0;
      plVar6 = *(long **)(plVar5[3] + 0x4b0);
      uVar11 = thunk_EXT_FUN_8011000003890f30(lVar10,&DAT_fffffff00ae21bd0);
      lVar10 = *plVar6;
      lVar10 = (**(code **)(lVar10 + 0x170))(lVar10 + 0x170,plVar6,uVar11,9,0);
      plVar5[5] = lVar10;
      if (lVar10 != 0) {
        *(undefined4 *)(plVar5 + 0x10) = 0;
        plVar6 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))(&DAT_fffffff00ae22f20);
        puVar2 = PTR_DAT_fffffff007ca61d0;
        if (plVar6 != (long *)0x0) {
          lVar10 = plVar5[3];
          uVar1 = *(uint *)(lVar10 + 0x18b70);
          plVar6[2] = *(long *)PTR_DAT_fffffff007ca61d0;
          iVar4 = FUN_fffffff0081e07cc(plVar6,lVar10,0xc0,uVar1 | 99);
          if (iVar4 != 0) {
            plVar7 = (long *)plVar6[10];
            if (plVar7 == (long *)0x0) {
              plVar7 = (long *)(**(code **)(*(long *)plVar6[9] + 0x90))
                                         ((long *)plVar6[9],plVar6[3],0x20900000084);
              if (plVar7 == (long *)0x0) goto LAB_fffffff0081ec5ec;
              (**(code **)(*plVar7 + 0x20))();
              (**(code **)(*plVar7 + 0x28))(plVar7);
              plVar6[10] = (long)plVar7;
            }
            lVar10 = (**(code **)(*plVar7 + 0x98))();
            if (lVar10 != 0) {
              plVar7 = (long *)plVar6[0xc];
              if (plVar7 == (long *)0x0) {
                lVar10 = thunk_EXT_FUN_801100000297ea14(plVar6[9],0);
                plVar6[0xc] = lVar10;
                if (lVar10 == 0) goto LAB_fffffff0081ec5ec;
                LOAcquire();
                DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar6[6];
                LORelease();
                plVar7 = (long *)plVar6[0xc];
              }
              lVar10 = (**(code **)(*plVar7 + 0x78))();
              if (lVar10 != 0) {
                plVar5[0x11] = (long)plVar6;
                lVar10 = (**(code **)(*(long *)plVar6[10] + 0x98))();
                lVar8 = (**(code **)(**(long **)(plVar5[0x11] + 0x60) + 0x78))();
                plVar5[9] = lVar8;
                plVar5[0xb] = lVar10;
                plVar6 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))(&DAT_fffffff00ae22f20);
                if (plVar6 == (long *)0x0) goto LAB_fffffff0081ec60c;
                lVar10 = plVar5[3];
                uVar1 = *(uint *)(lVar10 + 0x18b70);
                plVar6[2] = *(long *)puVar2;
                iVar4 = FUN_fffffff0081e07cc(plVar6,lVar10,4,uVar1 | 99);
                if (iVar4 != 0) {
                  plVar7 = (long *)plVar6[10];
                  if (plVar7 == (long *)0x0) {
                    plVar7 = (long *)(**(code **)(*(long *)plVar6[9] + 0x90))
                                               ((long *)plVar6[9],plVar6[3],0x800000084);
                    if (plVar7 == (long *)0x0) goto LAB_fffffff0081ec5ec;
                    (**(code **)(*plVar7 + 0x20))();
                    (**(code **)(*plVar7 + 0x28))(plVar7);
                    plVar6[10] = (long)plVar7;
                  }
                  lVar10 = (**(code **)(*plVar7 + 0x98))();
                  if (lVar10 != 0) {
                    plVar7 = (long *)plVar6[0xc];
                    if (plVar7 == (long *)0x0) {
                      lVar10 = thunk_EXT_FUN_801100000297ea14(plVar6[9],0);
                      plVar6[0xc] = lVar10;
                      if (lVar10 == 0) goto LAB_fffffff0081ec5ec;
                      LOAcquire();
                      DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar6[6];
                      LORelease();
                      plVar7 = (long *)plVar6[0xc];
                    }
                    lVar10 = (**(code **)(*plVar7 + 0x78))();
                    if (lVar10 != 0) {
                      plVar5[0x12] = (long)plVar6;
                      lVar10 = (**(code **)(*(long *)plVar6[10] + 0x98))();
                      lVar8 = (**(code **)(**(long **)(plVar5[0x12] + 0x60) + 0x78))();
                      plVar5[10] = lVar8;
                      plVar5[0xc] = lVar10;
                      if (((*(byte *)(*(long *)(param_1 + 0x10) + 0x3a8) & 1) != 0) &&
                         ((*(byte *)(param_1 + 0x218) & 1) != 0)) {
                        uVar11 = thunk_EXT_FUN_8011000003a49114
                                           (
                                           "AGXk: %s:%d:%s: !!! Assertion failed: %s: GPU HW Buffer replace failed\n"
                                           );
                        return uVar11;
                      }
                      *(long *)(param_1 + 0x210) = *(long *)(param_1 + 0x210) + 1;
                      plVar6 = *(long **)(param_1 + 0x20);
                      *(long **)(param_1 + 0x20) = plVar5;
                      (**(code **)(*plVar5 + 0x20))(plVar5);
                      if (plVar6 != (long *)0x0) {
                        (**(code **)(*plVar6 + 0x28))(plVar6);
                      }
                      FUN_fffffff0081ea690(*(undefined8 *)(param_1 + 0x20));
                      uVar11 = 1;
                      goto LAB_fffffff0081ec5b4;
                    }
                  }
                }
              }
            }
          }
LAB_fffffff0081ec5ec:
          (**(code **)(*plVar6 + 0x28))(plVar6);
        }
      }
    }
  }
LAB_fffffff0081ec60c:
  uVar11 = 0;
LAB_fffffff0081ec5b4:
  (**(code **)(*plVar5 + 0x28))(plVar5);
  return uVar11;
}

