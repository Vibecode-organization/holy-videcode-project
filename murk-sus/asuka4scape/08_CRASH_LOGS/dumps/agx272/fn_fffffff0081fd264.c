// FUN_fffffff0081fd264 @ fffffff0081fd264 size=412

undefined8 FUN_fffffff0081fd264(long *param_1)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  
  uVar3 = 1;
  if (param_1[0x57] == 0) {
    lVar4 = thunk_EXT_FUN_8011000003962c64
                      (*(undefined4 *)(param_1[2] + 0x18b70),0x100000000,
                       (long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f)));
    param_1[0x57] = lVar4;
    uVar3 = 0;
    if (lVar4 != 0) {
      plVar1 = param_1 + 0x57;
      iVar2 = (**(code **)(*param_1 + 0x98))(param_1,2,0x1300000000,0x100000000);
      if ((iVar2 != 0) &&
         (iVar2 = (**(code **)(*(long *)*plVar1 + 0xd8))((long *)*plVar1,0), iVar2 == 0)) {
        lVar4 = (**(code **)(*(long *)param_1[0x57] + 0x148))();
        param_1[0x58] = lVar4;
        thunk_EXT_FUN_8011000003a61cc0(lVar4,0x100000000);
        uVar5 = (**(code **)(*param_1 + 0xd0))(param_1,param_1[0x57],0x1300000000,0x100000000,0,0);
        if ((uVar5 & 1) != 0) {
          return 1;
        }
      }
      plVar6 = (long *)*plVar1;
      uVar3 = 0;
      if (plVar6 != (long *)0x0) {
        if (param_1[0x58] != 0) {
          (**(code **)(*plVar6 + 0xe0))(plVar6,0);
          plVar6 = (long *)*plVar1;
        }
        (**(code **)(*plVar6 + 0x28))();
        uVar3 = 0;
        *plVar1 = 0;
        param_1[0x58] = 0;
      }
    }
  }
  return uVar3;
}

