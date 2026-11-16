// FUN_fffffff00994eda8 @ fffffff00994eda8 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff00994ee5c) */

undefined8
FUN_fffffff00994eda8
          (long param_1,undefined8 param_2,long *param_3,long *param_4,undefined8 param_5,
          undefined8 param_6)

{
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  
  uVar2 = FUN_fffffff00994ea4c();
  if ((int)uVar2 != 0) {
    *(long **)(param_1 + 0xe8) = param_4;
    (**(code **)(*param_4 + 0x20))(param_4);
    *(undefined8 *)(param_1 + 0xd8) = param_5;
    *(undefined8 *)(param_1 + 0xe0) = param_6;
    lVar3 = thunk_EXT_FUN_80110000038fe5cc(0x1000);
    *(long *)(param_1 + 0xf8) = lVar3;
    uVar2 = 0;
    if (lVar3 != 0) {
      uStack_58 = 0;
      uStack_60 = 0;
      uStack_48 = 0;
      uStack_50 = 0;
      uStack_68 = 0;
      uStack_70 = 0;
      uStack_80 = DAT_fffffff007835cc0;
      uStack_78 = thunk_EXT_FUN_8011000003397c88();
      uVar1 = (**(code **)(*param_3 + 0x100))(*param_3 + 0x100,param_3);
      uStack_48 = CONCAT71(uStack_48._1_7_,uVar1);
      uVar2 = FUN_fffffff0099756cc(*(undefined8 *)(param_1 + 0x10),&uStack_80);
      *(undefined8 *)(param_1 + 0xf0) = uVar2;
      *(undefined1 *)(param_1 + 0x104) = 0;
      *(undefined4 *)(param_1 + 0xcc) = 0;
      *(undefined4 *)(param_1 + 0xd0) = 0;
      uVar2 = 1;
    }
  }
  return uVar2;
}

