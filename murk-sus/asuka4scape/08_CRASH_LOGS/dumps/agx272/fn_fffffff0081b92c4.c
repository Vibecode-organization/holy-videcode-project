// FUN_fffffff0081b92c4 @ fffffff0081b92c4 size=364

undefined8 FUN_fffffff0081b92c4(long param_1,long *param_2,undefined8 param_3)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  if (*(float *)(*(long *)(param_1 + 0x918) + 100) == 0.0) {
    if (*(int *)(*(long *)(param_1 + 0x918) + 0x68) == 0) {
      lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"indices");
      if (lVar2 != 0) {
        uVar1 = *(undefined8 *)PTR_DAT_fffffff007ca6098;
        lVar2 = thunk_EXT_FUN_8011000003890f30(lVar2,uVar1);
        if ((((lVar2 != 0) &&
             (lVar3 = (**(code **)(*param_2 + 0x138))(param_2,"pmu_ce"), lVar3 != 0)) &&
            (lVar3 = thunk_EXT_FUN_8011000003890f30(lVar3,uVar1), lVar3 != 0)) &&
           (((lVar4 = (**(code **)(*param_2 + 0x138))(param_2,"pmu_ce_clear_status"), lVar4 != 0 &&
             (lVar4 = thunk_EXT_FUN_8011000003890f30(lVar4,uVar1), lVar4 != 0)) &&
            (uVar1 = FUN_fffffff0081b9430(param_1,lVar2,lVar3,lVar4,param_3), (int)uVar1 == 0)))) {
          return uVar1;
        }
      }
      uVar1 = 0xe00002c2;
    }
    else {
      uVar1 = 0xe00002c7;
    }
  }
  else {
    uVar1 = 0xe00002c7;
  }
  return uVar1;
}

