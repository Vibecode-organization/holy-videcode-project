// FUN_fffffff009c1f6a8 @ fffffff009c1f6a8 size=200

void FUN_fffffff009c1f6a8(long *param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  if (param_3 == 1) {
    local_30 = 0;
    thunk_EXT_FUN_80110000032db760(param_1[6],&local_30);
    thunk_EXT_FUN_80110000036da494
              (0x85210038,local_30,(int)param_1[2],*(undefined4 *)((long)param_1 + 0xc),0,0);
    iVar1 = FUN_fffffff009c46ff8((undefined4 *)((long)param_1 + 0xc),3,2);
    if (iVar1 == 0) {
      (**(code **)(*param_1 + 0x78))(param_1);
    }
    if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
      return;
    }
  }
  else {
    FUN_fffffff009c48ff4();
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

