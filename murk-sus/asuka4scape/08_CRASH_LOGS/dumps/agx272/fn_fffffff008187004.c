// FUN_fffffff008187004 @ fffffff008187004 size=200

void FUN_fffffff008187004(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *local_30;
  undefined4 local_28;
  
  lVar3 = *(long *)(param_1 + 0x80);
  if (lVar3 != 0) {
    lVar1 = thunk_EXT_FUN_8011000003890f30(param_1,*(undefined8 *)PTR_DAT_fffffff007ca5fb8);
    uVar2 = *(undefined8 *)(lVar3 + 0x38);
    lVar3 = *(long *)(lVar3 + 0x50);
    local_28 = *(undefined4 *)(lVar1 + 0x18);
    local_48 = PTR_DAT_fffffff007ca5f90;
    local_40 = DAT_fffffff007113e50;
    local_38 = FUN_fffffff0081d446c;
    local_30 = &DAT_fffffff007c97640;
    thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(lVar3 + 0x10));
    FUN_fffffff0081d40e8(lVar3,&local_48,uVar2);
    thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar3 + 0x10));
  }
  return;
}

