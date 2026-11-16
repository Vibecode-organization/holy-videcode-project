// FUN_fffffff00820f004 @ fffffff00820f004 size=1304

undefined8 FUN_fffffff00820f004(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  undefined8 *puVar7;
  long *plVar8;
  bool bVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  
  uVar4 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
  if ((int)uVar4 == 0) {
    return uVar4;
  }
  *(undefined8 *)(param_1 + 0x28) = param_2;
  *(undefined8 *)(param_1 + 0x10) = param_3;
  *(undefined8 *)(param_1 + 0xb0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x3d8) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0xcc) = 0x100000001;
  lVar5 = thunk_EXT_FUN_80110000038ff010();
  *(long *)(param_1 + 0xb8) = lVar5;
  if (lVar5 == 0) {
    return 0;
  }
  lVar5 = thunk_EXT_FUN_80110000038ff134();
  *(long *)(param_1 + 0xc0) = lVar5;
  if (lVar5 == 0) {
    return 0;
  }
  plVar6 = *(long **)(param_1 + 0x10);
  *(uint *)(param_1 + 0xcc) = *(byte *)((long)plVar6 + 0x10959) & 1;
  if (*(uint *)((long)plVar6 + 0x10954) < 3) {
    *(uint *)(param_1 + 0xd0) = *(uint *)((long)plVar6 + 0x10954);
  }
  plVar8 = (long *)(param_1 + 0x30);
  *(undefined8 *)(param_1 + 0x38) = 0;
  *plVar8 = 0;
  *(undefined8 *)(param_1 + 0x98) = 0;
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(undefined8 *)(param_1 + 0xa8) = 0;
  *(undefined8 *)(param_1 + 0xa0) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  puVar2 = PTR_DAT_fffffff007ca61d0;
  if ((*(int *)((long)plVar6 + 0x10964) == 0) &&
     ((*(long *)(param_1 + 0x28) != *(long *)PTR_DAT_fffffff007ca61d0 ||
      ((*(byte *)(param_1 + 200) & 1) != 0)))) {
    puVar7 = (undefined8 *)(**(code **)(*plVar6 + 0xd18))();
    if (puVar7 == (undefined8 *)0x0) {
      return 0;
    }
    uVar10 = puVar7[1];
    uVar4 = *puVar7;
    uVar12 = puVar7[3];
    uVar11 = puVar7[2];
    uVar13 = puVar7[4];
    uVar15 = puVar7[7];
    uVar14 = puVar7[6];
    *(undefined8 *)(param_1 + 0x98) = puVar7[5];
    *(undefined8 *)(param_1 + 0x90) = uVar13;
    *(undefined8 *)(param_1 + 0xa8) = uVar15;
    *(undefined8 *)(param_1 + 0xa0) = uVar14;
    *(undefined8 *)(param_1 + 0x78) = uVar10;
    *(undefined8 *)(param_1 + 0x70) = uVar4;
    *(undefined8 *)(param_1 + 0x88) = uVar12;
    *(undefined8 *)(param_1 + 0x80) = uVar11;
    plVar6 = *(long **)(param_1 + 0x10);
  }
  uVar4 = (**(code **)(*plVar6 + 0xd30))();
  *(undefined8 *)(param_1 + 0x18) = uVar4;
  puVar1 = PTR_DAT_fffffff007ca5f88;
  if ((*(int *)(*(long *)(param_1 + 0x10) + 0x10964) == 0) &&
     ((*(long *)(param_1 + 0x28) != *(long *)puVar2 || ((*(byte *)(param_1 + 200) & 1) != 0)))) {
    bVar9 = true;
  }
  else {
    bVar9 = false;
  }
  plVar6 = (long *)thunk_EXT_FUN_8011000003962c64
                             (*(uint *)(param_1 + 0xb4) | 3,0x40,
                              (long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f)));
  *(long **)(param_1 + 0x30) = plVar6;
  if ((plVar6 != (long *)0x0) && (iVar3 = (**(code **)(*plVar6 + 0xd8))(plVar6,3), iVar3 == 0)) {
    puVar7 = (undefined8 *)(**(code **)(**(long **)(param_1 + 0x30) + 0x148))();
    *(undefined8 **)(param_1 + 0x38) = puVar7;
    puVar7[1] = 0;
    *puVar7 = 0;
    puVar7[3] = 0;
    puVar7[2] = 0;
    puVar7[5] = 0;
    puVar7[4] = 0;
    puVar7[7] = 0;
    puVar7[6] = 0;
    lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4be8,0x40);
    *(long *)(param_1 + 0x40) = lVar5;
    if (lVar5 != 0) {
      lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4c38,0x40);
      *(long *)(param_1 + 0x48) = lVar5;
      if (lVar5 != 0) {
        lVar5 = thunk_EXT_FUN_80110000038fe5cc(0x20);
        *(long *)(param_1 + 0x50) = lVar5;
        if (lVar5 != 0) {
          lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4c88,0x40);
          *(long *)(param_1 + 0x58) = lVar5;
          if (lVar5 != 0) {
            lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4cd8,0x40);
            *(long *)(param_1 + 0x60) = lVar5;
            if (lVar5 != 0) {
              lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4d28,0x40);
              *(long *)(param_1 + 0x68) = lVar5;
              if (lVar5 != 0) {
                if (bVar9) {
LAB_fffffff00820f3ac:
                  if ((*(long *)(param_1 + 0x28) == *(long *)puVar2) &&
                     ((*(byte *)(param_1 + 200) & 1) == 0)) {
                    (**(code **)(**(long **)(param_1 + 0x10) + 0xd10))
                              (*(long **)(param_1 + 0x10),param_1 + 0x70);
                  }
                  return 1;
                }
                plVar6 = (long *)thunk_EXT_FUN_8011000003962c64
                                           (*(uint *)(param_1 + 0xb4) | 3,0x40,
                                            (long)(1 << (ulong)(*(uint *)puVar1 & 0x1f)));
                plVar8 = (long *)(param_1 + 0x70);
                *plVar8 = (long)plVar6;
                if ((plVar6 != (long *)0x0) &&
                   (iVar3 = (**(code **)(*plVar6 + 0xd8))(plVar6,3), iVar3 == 0)) {
                  puVar7 = (undefined8 *)(**(code **)(**(long **)(param_1 + 0x70) + 0x148))();
                  *(undefined8 **)(param_1 + 0x78) = puVar7;
                  puVar7[1] = 0;
                  *puVar7 = 0;
                  puVar7[3] = 0;
                  puVar7[2] = 0;
                  puVar7[5] = 0;
                  puVar7[4] = 0;
                  puVar7[7] = 0;
                  puVar7[6] = 0;
                  lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4be8,0x40);
                  *(long *)(param_1 + 0x80) = lVar5;
                  if (lVar5 != 0) {
                    lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4c38,0x40);
                    *(long *)(param_1 + 0x88) = lVar5;
                    if (lVar5 != 0) {
                      lVar5 = thunk_EXT_FUN_80110000038fe5cc(0x20);
                      *(long *)(param_1 + 0x90) = lVar5;
                      if (lVar5 != 0) {
                        lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4c88,0x40);
                        *(long *)(param_1 + 0x98) = lVar5;
                        if (lVar5 != 0) {
                          lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4cd8,0x40);
                          *(long *)(param_1 + 0xa0) = lVar5;
                          if (lVar5 != 0) {
                            lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4d28,0x40);
                            *(long *)(param_1 + 0xa8) = lVar5;
                            if (lVar5 != 0) goto LAB_fffffff00820f3ac;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  lVar5 = plVar8[6];
  if (lVar5 != 0) {
    plVar8[6] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4d78,lVar5,0x40);
    plVar8[6] = 0;
  }
  lVar5 = plVar8[5];
  if (lVar5 != 0) {
    plVar8[5] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4dc8,lVar5,0x40);
    plVar8[5] = 0;
  }
  lVar5 = plVar8[7];
  if (lVar5 != 0) {
    plVar8[7] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4e18,lVar5,0x40);
    plVar8[7] = 0;
  }
  lVar5 = plVar8[3];
  if (lVar5 != 0) {
    plVar8[3] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4e68,lVar5,0x40);
    plVar8[3] = 0;
  }
  lVar5 = plVar8[2];
  if (lVar5 != 0) {
    plVar8[2] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4eb8,lVar5,0x40);
    plVar8[2] = 0;
  }
  lVar5 = plVar8[4];
  if (lVar5 != 0) {
    plVar8[4] = 0;
    thunk_EXT_FUN_80110000038fe6b0(lVar5,0x20);
    plVar8[4] = 0;
  }
  plVar6 = (long *)*plVar8;
  if (plVar8[1] != 0) {
    (**(code **)(*plVar6 + 0xe0))(plVar6,0);
    plVar8[1] = 0;
    plVar6 = (long *)*plVar8;
  }
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))();
    *plVar8 = 0;
  }
  return 0;
}

