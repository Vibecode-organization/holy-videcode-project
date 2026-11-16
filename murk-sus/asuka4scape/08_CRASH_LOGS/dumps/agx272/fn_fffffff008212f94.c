// FUN_fffffff008212f94 @ fffffff008212f94 size=4

void FUN_fffffff008212f94(long param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined *puStack_70;
  undefined8 uStack_68;
  code *pcStack_60;
  undefined *puStack_58;
  long lStack_50;
  undefined8 uStack_48;
  long lStack_40;
  undefined1 uStack_38;
  
  lVar1 = thunk_EXT_FUN_8011000003890f30(param_2,&DAT_fffffff00ae23d00);
  if (lVar1 == 0) {
    lVar1 = thunk_EXT_FUN_8011000003890f30(param_2,&DAT_fffffff00ae23760);
    if (lVar1 == 0) {
      lVar1 = thunk_EXT_FUN_8011000003890f30(param_2,&DAT_fffffff00ae256a0);
      if (param_2 != 0) {
        (**(code **)(**(long **)(param_1 + 0x220) + 0x88))(*(long **)(param_1 + 0x220),param_2);
        uStack_48 = *(undefined8 *)(param_1 + 0x220);
        puStack_70 = PTR_DAT_fffffff007ca5f90;
        uStack_68 = DAT_fffffff007113e50;
        pcStack_60 = FUN_fffffff008213278;
        puStack_58 = &DAT_fffffff007ca0530;
        lStack_50 = param_1;
        lStack_40 = param_2;
        uStack_38 = lVar1 != 0;
        thunk_EXT_FUN_801100000395c120
                  (*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x310),&puStack_70);
      }
      if (lVar1 != 0) {
        lVar3 = *(long *)(param_1 + 0x220);
        *(undefined4 *)(lVar1 + 0x11e0) = *(undefined4 *)(lVar3 + 0x18);
        *(undefined4 *)(lVar1 + 0x11e4) = *(undefined4 *)(lVar3 + 0x188);
        (**(code **)(**(long **)(param_1 + 0x218) + 0x88))(*(long **)(param_1 + 0x218),lVar1);
        uStack_48 = *(undefined8 *)(param_1 + 0x218);
        puStack_70 = PTR_DAT_fffffff007ca5f90;
        uStack_68 = DAT_fffffff007113e50;
        pcStack_60 = FUN_fffffff008213278;
        puStack_58 = &DAT_fffffff007ca0530;
        uStack_38 = 0;
        lStack_50 = param_1;
        lStack_40 = lVar1;
        thunk_EXT_FUN_801100000395c120
                  (*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x310),&puStack_70);
      }
      if (*(long *)(param_2 + 0x140) == 0) {
        return;
      }
      plVar2 = *(long **)(*(long *)(param_1 + 0xc0) + 0x310);
      puVar4 = (undefined8 *)(*plVar2 + 0xe8);
      (*(code *)*puVar4)(puVar4,plVar2,FUN_fffffff00817e544,*(long *)(param_2 + 0x140),0,0,0);
      *(undefined8 *)(param_2 + 0x140) = 0;
      return;
    }
    FUN_fffffff00818717c(*(undefined8 *)(param_1 + 0x220),lVar1,1);
  }
  else {
    (**(code **)(**(long **)(param_1 + 0x220) + 0x108))(*(long **)(param_1 + 0x220),lVar1,1);
  }
  uStack_48 = *(undefined8 *)(param_1 + 0x220);
  puStack_70 = PTR_DAT_fffffff007ca5f90;
  uStack_68 = DAT_fffffff007113e50;
  pcStack_60 = FUN_fffffff008213278;
  puStack_58 = &DAT_fffffff007ca0530;
  uStack_38 = 0;
  lStack_50 = param_1;
  lStack_40 = lVar1;
  thunk_EXT_FUN_801100000395c120(*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x310),&puStack_70);
  return;
}

