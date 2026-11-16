// FUN_fffffff0081fa144 @ fffffff0081fa144 size=308

undefined8 FUN_fffffff0081fa144(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  undefined *puVar2;
  long lVar3;
  long *plVar4;
  undefined8 uVar5;
  
  uVar5 = 0;
  if (*(long *)(param_1 + 0x28) != 0) {
    lVar3 = thunk_EXT_FUN_8011000003890f30(*(long *)(param_1 + 0x28),&DAT_fffffff00ae21bd0);
    uVar5 = 0;
    if (lVar3 != 0) {
      lVar3 = thunk_EXT_FUN_801100000297dd00();
      puVar2 = PTR_DAT_fffffff007ca61d0;
      uVar5 = 0;
      if (lVar3 != 0) {
        uVar1 = param_3 + param_2;
        do {
          while( true ) {
            if (uVar1 - param_2 <= param_3) {
              param_3 = uVar1 - param_2;
            }
            plVar4 = (long *)thunk_EXT_FUN_801100000396cb64
                                       (lVar3,*(undefined8 *)puVar2,0,
                                        *(uint *)(*(long *)(param_1 + 0x50) + 0x18b70) | 1,param_2,
                                        param_3);
            if (plVar4 != (long *)0x0) break;
            if (param_3 < 2) {
              return 0;
            }
            param_3 = param_3 >> (1 < param_3);
            if (uVar1 <= param_2) goto LAB_fffffff0081fa254;
          }
          uVar5 = (**(code **)(*plVar4 + 0x78))();
          thunk_EXT_FUN_8011000003a61cc0(uVar5,param_3);
          param_2 = param_3 + param_2;
          (**(code **)(*plVar4 + 0x28))(plVar4);
        } while (param_2 < uVar1);
LAB_fffffff0081fa254:
        uVar5 = 1;
      }
    }
  }
  return uVar5;
}

