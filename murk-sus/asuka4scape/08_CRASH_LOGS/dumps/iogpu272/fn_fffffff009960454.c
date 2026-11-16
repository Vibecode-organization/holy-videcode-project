// FUN_fffffff009960454 @ fffffff009960454 size=92

undefined8 FUN_fffffff009960454(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x20);
  iVar2 = thunk_EXT_FUN_80110000038905fc(lVar4 + 0x15c);
  if (iVar2 == 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 0x248));
    uVar3 = thunk_EXT_FUN_8011000003397c88();
    *(undefined8 *)(lVar4 + 0x230) = uVar3;
    *(undefined8 *)(lVar4 + 0x238) = 0;
    LOAcquire();
    lVar1 = *(long *)(lVar4 + 0x240);
    *(long *)(lVar4 + 0x240) = lVar1 + 1;
    LORelease();
    thunk_EXT_FUN_8011000003222de0(lVar1,*(undefined8 *)(lVar4 + 0x248));
  }
  return 0;
}

