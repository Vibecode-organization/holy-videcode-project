// FUN_fffffff0081fe9cc @ fffffff0081fe9cc size=4

void FUN_fffffff0081fe9cc(long *param_1)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  FUN_fffffff00816b2a8(param_1[2]);
  if ((long *)param_1[0x5b] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x5b] + 0x28))();
  }
  param_1[0x5b] = 0;
  if ((long *)param_1[0x5c] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x5c] + 0x28))();
  }
  param_1[0x5c] = 0;
  if ((long *)param_1[0x5d] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x5d] + 0x28))();
  }
  param_1[0x5d] = 0;
  (**(code **)(*param_1 + 400))(param_1);
  plVar1 = (long *)param_1[0x55];
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0xe0))(plVar1,0);
    if ((long *)param_1[0x55] != (long *)0x0) {
      (**(code **)(*(long *)param_1[0x55] + 0x28))();
    }
    param_1[0x55] = 0;
  }
  plVar1 = (long *)param_1[0x57];
  if (plVar1 != (long *)0x0) {
    if (param_1[0x58] != 0) {
      (**(code **)(*plVar1 + 0xe0))(plVar1,0);
      plVar1 = (long *)param_1[0x57];
    }
    (**(code **)(*plVar1 + 0x28))();
    param_1[0x57] = 0;
    param_1[0x58] = 0;
  }
  plVar1 = (long *)param_1[0x5a];
  lVar3 = param_1[2];
  lVar4 = param_1[5];
  lVar5 = *(long *)PTR_DAT_fffffff007ca61d0;
  FUN_fffffff0081e8640(param_1);
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar3 + 0x11a70));
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar3 + 0x11a78));
  if (*(int *)(lVar3 + 0x11a68) != 0) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! AGXSecureGart::free\n");
    return;
  }
  if (plVar1 != (long *)0x0) {
    if ((DAT_fffffff00ae25928 & 1) == 0) {
      FUN_fffffff00820f5dc(plVar1[3]);
    }
    else {
      (**(code **)(*(long *)plVar1[2] + 0x78))();
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar3 + 0x11a78));
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar3 + 0x11a70));
  if (lVar4 == lVar5) {
    if (DAT_fffffff00ae23b38 != 0) {
      lVar3 = DAT_fffffff00ae23b38;
      uVar2 = DAT_fffffff00ae23b40;
      if ((int)DAT_fffffff00ae23b40 < 1) {
        lVar4 = (long)(int)DAT_fffffff00ae23b40;
      }
      else {
        lVar5 = 0;
        do {
          if (*(long *)(lVar3 + lVar5 * 8) != 0) {
            thunk_EXT_FUN_80110000038ff020();
            lVar3 = DAT_fffffff00ae23b38;
            *(undefined8 *)(DAT_fffffff00ae23b38 + lVar5 * 8) = 0;
            uVar2 = DAT_fffffff00ae23b40;
          }
          lVar5 = lVar5 + 1;
          lVar4 = (long)(int)uVar2;
        } while (lVar5 < lVar4);
      }
      lVar4 = lVar4 << 3;
      if (0x7fffffff < uVar2) {
        lVar4 = -0x8000000000000000;
      }
      DAT_fffffff00ae23b38 = 0;
      thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4af8,lVar3,lVar4);
      DAT_fffffff00ae23b38 = 0;
      DAT_fffffff00ae23b40 = 0;
    }
    if (DAT_fffffff00ae23b30 != 0) {
      thunk_EXT_FUN_80110000038ff020();
      DAT_fffffff00ae23b30 = 0;
    }
  }
  return;
}

