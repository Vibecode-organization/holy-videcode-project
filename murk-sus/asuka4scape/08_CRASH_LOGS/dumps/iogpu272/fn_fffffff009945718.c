// FUN_fffffff009945718 @ fffffff009945718 size=228

long FUN_fffffff009945718(long param_1)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x20);
  if (lVar4 == 0) {
    lVar2 = thunk_EXT_FUN_80110000038fe580(0x400);
    *(long *)(param_1 + 0x20) = lVar2;
    lVar4 = 0;
    if (lVar2 != 0) {
      plVar3 = *(long **)(*(long *)(param_1 + 0x10) + 0x140);
      if (plVar3 != (long *)0x0) {
        (**(code **)(*plVar3 + 0xa8))();
      }
      iVar1 = thunk_EXT_FUN_80110000037693ec(lVar2,0x400,"%s idx%d");
      if (iVar1 < 0x3ff) {
        lVar4 = thunk_EXT_FUN_80110000038fe580((long)(iVar1 + 1));
        thunk_EXT_FUN_8011000003350958(lVar4,*(undefined8 *)(param_1 + 0x20),(long)(iVar1 + 1));
        thunk_EXT_FUN_80110000038fe6b0(*(undefined8 *)(param_1 + 0x20),0x400);
        *(long *)(param_1 + 0x20) = lVar4;
      }
      else {
        lVar4 = *(long *)(param_1 + 0x20);
      }
    }
  }
  return lVar4;
}

