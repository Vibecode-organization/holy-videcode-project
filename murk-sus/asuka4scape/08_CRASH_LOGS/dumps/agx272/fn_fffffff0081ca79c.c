// FUN_fffffff0081ca79c @ fffffff0081ca79c size=4

void FUN_fffffff0081ca79c(long param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  long *plVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  
  lVar8 = 0;
  lVar9 = 0x110;
  do {
    puVar1 = (uint *)(param_2 + lVar8 * 8);
    uVar2 = *puVar1;
    if (((uVar2 ^ 0xffffffff) & 9) == 0) {
      uVar3 = uVar2 >> 4 & 0x7f;
      uVar2 = puVar1[1];
      plVar4 = (long *)FUN_fffffff00817f2e0
                                 (*(undefined8 *)(*(long *)(param_1 + 0x280) + 0x160),uVar3);
      if (plVar4 != (long *)0x0) {
        uVar5 = thunk_EXT_FUN_8011000002959acc(plVar4,uVar3,uVar2);
        lVar6 = thunk_EXT_FUN_8011000003890f30(uVar5,&DAT_fffffff00ae256a0);
        if ((((lVar6 != 0) &&
             (uVar7 = thunk_EXT_FUN_80110000029474ec
                                (*(undefined8 *)(*(long *)(param_1 + 0x280) + 0x148),lVar6 + 0xc40),
             (uVar7 & 1) == 0)) && (*(long *)(lVar6 + 0xc98) != 0)) &&
           (uVar7 = FUN_fffffff0081fa144
                              (*(long *)(lVar6 + 0xc98),*(undefined8 *)(lVar6 + 0xca0),
                               *(undefined8 *)(lVar6 + 0xf68)), (uVar7 & 1) == 0)) {
          thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Failed to clear gpu tail pointers\n");
          return;
        }
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
    }
    lVar8 = lVar8 + 1;
    lVar9 = lVar9 + -1;
    if (lVar9 == 0) {
      return;
    }
  } while( true );
}

