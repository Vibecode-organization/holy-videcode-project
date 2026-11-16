// FUN_fffffff00819a4c0 @ fffffff00819a4c0 size=4

void FUN_fffffff00819a4c0(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined *puStack_48;
  undefined8 uStack_40;
  code *pcStack_38;
  undefined *puStack_30;
  long lStack_28;
  
  thunk_EXT_FUN_80110000029728f4();
  if (*(long **)(param_1 + 0x610) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x610) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x610) = 0;
  thunk_EXT_FUN_8011000002972900(param_1);
  if (*(long **)(param_1 + 0x918) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x918) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x918) = 0;
  if (*(long **)(param_1 + 0x910) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x910) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x910) = 0;
  lVar1 = -0x8000000000000000;
  if (-1 < *(int *)(param_1 + 0x848)) {
    lVar1 = (long)*(int *)(param_1 + 0x848) << 3;
  }
  uVar2 = *(undefined8 *)(param_1 + 0x8f0);
  *(undefined8 *)(param_1 + 0x8f0) = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca2f78,uVar2,lVar1);
  lVar1 = -0x8000000000000000;
  if (-1 < *(int *)(param_1 + 0x848)) {
    lVar1 = (long)*(int *)(param_1 + 0x848) << 3;
  }
  uVar2 = *(undefined8 *)(param_1 + 0x8f8);
  *(undefined8 *)(param_1 + 0x8f8) = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca2fc8,uVar2,lVar1);
  lVar1 = -0x8000000000000000;
  if (-1 < *(int *)(param_1 + 0x848)) {
    lVar1 = (long)*(int *)(param_1 + 0x848) << 2;
  }
  uVar2 = *(undefined8 *)(param_1 + 0x900);
  *(undefined8 *)(param_1 + 0x900) = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca3018,uVar2,lVar1);
  lVar1 = -0x8000000000000000;
  if (-1 < *(int *)(param_1 + 0x848)) {
    lVar1 = (long)*(int *)(param_1 + 0x848) << 6;
  }
  uVar2 = *(undefined8 *)(param_1 + 0x8e0);
  *(undefined8 *)(param_1 + 0x8e0) = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca3068,uVar2,lVar1);
  if (*(long **)(param_1 + 0x850) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x850) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x850) = 0;
  if (((*(long *)(param_1 + 0x938) != 0) && (*(long *)(param_1 + 0x928) != 0)) &&
     (*(long *)(param_1 + 0x930) != 0)) {
    puStack_48 = PTR_DAT_fffffff007ca5f90;
    uStack_40 = DAT_fffffff007113e50;
    pcStack_38 = FUN_fffffff00819a734;
    puStack_30 = &DAT_fffffff007c93ec8;
    lStack_28 = param_1;
    thunk_EXT_FUN_801100000395c120(&puStack_30,*(long *)(param_1 + 0x938),&puStack_48);
    (**(code **)(**(long **)(param_1 + 0x930) + 0xa8))
              (*(long **)(param_1 + 0x930),*(undefined8 *)(param_1 + 0x938));
    if (*(long **)(param_1 + 0x938) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x938) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x938) = 0;
    if (*(long **)(param_1 + 0x930) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x930) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x930) = 0;
  }
  (**(code **)(PTR_DAT_fffffff007ca6130 + 0x80))(param_1);
  return;
}

