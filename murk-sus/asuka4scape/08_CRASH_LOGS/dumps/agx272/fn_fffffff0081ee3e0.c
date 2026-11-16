// FUN_fffffff0081ee3e0 @ fffffff0081ee3e0 size=240

undefined8 FUN_fffffff0081ee3e0(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  
  iVar1 = thunk_EXT_FUN_80110000029718f0
                    (*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x98),0);
  if (iVar1 == 0) {
    uVar2 = 0xe00002be;
  }
  else {
    if (*(long *)(param_1 + 0x90) != 0) {
      uVar5 = 0;
      do {
        uVar2 = thunk_EXT_FUN_801100000293f644
                          (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x80) + uVar5 * 8) + 0x18))
        ;
        if ((int)uVar2 != 0) {
          if ((int)uVar5 != 0) {
            lVar3 = 0;
            lVar4 = 0;
            do {
              thunk_EXT_FUN_801100000293f7a0
                        (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x80) + lVar4 * 8) + 0x18));
              lVar4 = lVar4 + 1;
              lVar3 = lVar3 + 8;
            } while (uVar5 << 3 != lVar3);
          }
          thunk_EXT_FUN_80110000029718d8
                    (*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x98),0);
          return uVar2;
        }
        uVar5 = (ulong)((int)uVar5 + 1);
      } while (uVar5 < *(ulong *)(param_1 + 0x90));
    }
    thunk_EXT_FUN_8011000002979900(*(long *)(*(long *)(param_1 + 0x10) + 0x160) + 0x1b8,param_1);
    uVar2 = 0;
  }
  return uVar2;
}

