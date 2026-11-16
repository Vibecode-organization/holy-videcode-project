// FUN_fffffff008199dec @ fffffff008199dec size=196

void FUN_fffffff008199dec(undefined8 param_1,long param_2,long param_3)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  
  uVar6 = *(ulong *)(param_2 + 0x20);
  if (uVar6 != 0) {
    if (param_3 == 0) {
      uVar5 = 0;
      uVar4 = 1;
      do {
        thunk_EXT_FUN_8011000002969884
                  (param_1,*(undefined8 *)(*(long *)(*(long *)(param_2 + 0x18) + uVar5 * 8) + 0x28))
        ;
        bVar1 = uVar4 < uVar6;
        uVar5 = uVar4;
        uVar4 = (ulong)((int)uVar4 + 1);
      } while (bVar1);
    }
    else {
      uVar5 = 0;
      do {
        lVar2 = *(long *)(param_3 + 0x20);
        if (lVar2 != 0) {
          lVar3 = 0;
          do {
            if (*(long *)(*(long *)(param_3 + 0x18) + lVar3 * 8) ==
                *(long *)(*(long *)(param_2 + 0x18) + uVar5 * 8)) goto LAB_fffffff008199e2c;
            lVar3 = lVar3 + 1;
            lVar2 = lVar2 + -1;
          } while (lVar2 != 0);
        }
        thunk_EXT_FUN_801100000296bdb4(param_3);
LAB_fffffff008199e2c:
        uVar5 = (ulong)((int)uVar5 + 1);
      } while (uVar5 < uVar6);
    }
  }
  return;
}

