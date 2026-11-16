// FUN_fffffff008213b20 @ fffffff008213b20 size=524

void FUN_fffffff008213b20(long param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  undefined8 *puVar3;
  undefined *local_70;
  undefined8 local_68;
  code *local_60;
  undefined *local_58;
  long lStack_50;
  undefined8 local_48;
  long lStack_40;
  undefined1 local_38;
  
  lVar1 = thunk_EXT_FUN_8011000003890f30(param_2,&DAT_fffffff00ae23d00);
  lStack_50 = param_1;
  if (lVar1 == 0) {
    lVar1 = thunk_EXT_FUN_8011000003890f30(param_2,&DAT_fffffff00ae23760);
    plVar2 = *(long **)(param_1 + 0x218);
    if (lVar1 == 0) {
      (**(code **)(*plVar2 + 0x88))(plVar2,param_2);
      local_48 = *(undefined8 *)(param_1 + 0x218);
      local_70 = PTR_DAT_fffffff007ca5f90;
      local_68 = DAT_fffffff007113e50;
      local_60 = FUN_fffffff008213278;
      local_58 = &DAT_fffffff007ca0530;
      local_38 = 0;
      lStack_40 = param_2;
      thunk_EXT_FUN_801100000395c120(*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x310),&local_70);
      if (*(long *)(param_2 + 0x140) == 0) {
        return;
      }
      plVar2 = *(long **)(*(long *)(param_1 + 0xc0) + 0x310);
      puVar3 = (undefined8 *)(*plVar2 + 0xe8);
      (*(code *)*puVar3)(puVar3,plVar2,FUN_fffffff00817e544,*(long *)(param_2 + 0x140),0,0,0);
      *(undefined8 *)(param_2 + 0x140) = 0;
      return;
    }
    FUN_fffffff00818717c(plVar2,lVar1,2);
  }
  else {
    (**(code **)(**(long **)(param_1 + 0x218) + 0x108))(*(long **)(param_1 + 0x218),lVar1,2);
  }
  local_48 = *(undefined8 *)(param_1 + 0x218);
  local_70 = PTR_DAT_fffffff007ca5f90;
  local_68 = DAT_fffffff007113e50;
  local_60 = FUN_fffffff008213278;
  local_58 = &DAT_fffffff007ca0530;
  local_38 = 0;
  lStack_40 = lVar1;
  thunk_EXT_FUN_801100000395c120(*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x310),&local_70);
  return;
}

