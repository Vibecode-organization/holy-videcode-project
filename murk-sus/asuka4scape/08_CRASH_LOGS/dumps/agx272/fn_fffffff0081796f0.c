// FUN_fffffff0081796f0 @ fffffff0081796f0 size=608

void FUN_fffffff0081796f0(long *param_1,undefined8 param_2)

{
  undefined4 uVar1;
  byte bVar2;
  uint uVar3;
  undefined *local_58;
  undefined8 local_50;
  code *local_48;
  undefined *local_40;
  long *plStack_38;
  
  thunk_EXT_FUN_8011000003397c88();
  uVar3 = (uint)param_2;
  if ((*(byte *)((long)param_1 + 0x1ac44) >> 3 & 1) != 0) {
    bVar2 = *(byte *)((long)param_1 + 0x57a);
    thunk_EXT_FUN_80110000032222a8(param_1[0x3589]);
    uVar1 = 0x85930c5c;
    if (uVar3 == 0) {
      uVar1 = 0x85930c60;
    }
    thunk_EXT_FUN_80110000036da494(uVar1,bVar2 & 1,0,0,0,0);
    thunk_EXT_FUN_8011000003222de0(param_1[0x3589]);
  }
  (**(code **)(*param_1 + 0xd8))(param_1,"CommandSubmissionEnabled",param_2);
  if (uVar3 != (*(byte *)((long)param_1 + 0x57a) & 1)) {
    if (uVar3 == 0) {
      thunk_EXT_FUN_801100000295c3cc(param_1[0x2c]);
      if ((long *)param_1[0x3592] != (long *)0x0) {
        *(byte *)((long)param_1 + 0x1aca9) = *(byte *)(param_1 + 0x3595) & 1;
        *(undefined1 *)(param_1 + 0x3595) = 0;
        (**(code **)(*(long *)param_1[0x3592] + 0x138))();
        local_58 = PTR_DAT_fffffff007ca5f90;
        local_50 = DAT_fffffff007113e50;
        local_48 = FUN_fffffff00817cedc;
        local_40 = &DAT_fffffff007c92f88;
        plStack_38 = param_1;
        thunk_EXT_FUN_801100000395c120(&local_40,param_1[0x3590],&local_58);
      }
    }
    else {
      thunk_EXT_FUN_801100000295c4b0();
      if ((param_1[0x3592] != 0) && ((*(byte *)((long)param_1 + 0x1aca9) & 1) != 0)) {
        *(undefined1 *)(param_1 + 0x3595) = 1;
        *(undefined1 *)((long)param_1 + 0x1aca9) = 0;
        local_58 = PTR_DAT_fffffff007ca5f90;
        local_50 = DAT_fffffff007113e50;
        local_48 = FUN_fffffff00817cd7c;
        local_40 = &DAT_fffffff007c92fa8;
        plStack_38 = param_1;
        thunk_EXT_FUN_801100000395c120(&local_40,param_1[0x3590],&local_58);
      }
      thunk_EXT_FUN_801100000389061c(0,*(long *)(param_1[0x96] + 0x918) + 0x690);
    }
    *(char *)((long)param_1 + 0x57a) = (char)param_2;
    (**(code **)(*(long *)param_1[0x96] + 0x1a0))((long *)param_1[0x96],param_2);
    if ((*(byte *)((long)param_1 + 0x57a) & 1) != 0) {
      thunk_EXT_FUN_80110000038ff08c(param_1[0x234c],(long)param_1 + 0x57a,0);
    }
  }
  return;
}

