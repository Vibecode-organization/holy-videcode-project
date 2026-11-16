// FUN_fffffff00997a694 @ fffffff00997a694 size=644

/* WARNING: Removing unreachable block (ram,0xfffffff00997a7e8) */

undefined8
FUN_fffffff00997a694
          (long *param_1,undefined8 param_2,undefined8 param_3,int param_4,undefined8 param_5)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  long *local_58;
  
  uVar6 = 0xe00002bc;
  iVar2 = FUN_fffffff009975b64(param_1[0xa6],param_1);
  if (iVar2 == 0) {
    uVar6 = 0xe00002d7;
  }
  else {
    thunk_EXT_FUN_80110000032222a8(param_1[0xa5]);
    *(undefined1 *)((long)param_1 + 0x526) = 1;
    thunk_EXT_FUN_8011000003222de0(param_1[0xa5]);
    thunk_EXT_FUN_80110000032222a8(param_1[0x8b]);
    if ((param_1[0x85] != 0) && (param_1[0x91] != 0)) {
      FUN_fffffff00997a918(param_1);
      if ((int)param_1[0xa4] == 0) {
        FUN_fffffff0099616bc(*(undefined8 *)(param_1[0xa6] + 0x160),4);
        local_58 = (long *)0x0;
        uVar6 = thunk_EXT_FUN_80110000039a3b60
                          (*(undefined8 *)(param_1[0x90] + 0x28),param_2,&local_58);
        if (((int)uVar6 == 0) &&
           (lVar3 = thunk_EXT_FUN_8011000003890f30(local_58,*(undefined8 *)PTR_DAT_fffffff007ff2790)
           , lVar3 != 0)) {
          uVar4 = thunk_EXT_FUN_8011000002c12750();
          lVar5 = *param_1;
          if (param_4 == 0) {
            (**(code **)(lVar5 + 0x128))(lVar5 + 0x128,param_1,uVar4,param_3,param_5);
            lVar5 = param_1[0xaa];
            thunk_EXT_FUN_8011000002c12750(lVar3);
            uVar4 = thunk_EXT_FUN_8011000002c134f4();
            uVar1 = 0x850900d4;
          }
          else {
            (**(code **)(lVar5 + 0x120))(lVar5 + 0x120,param_1,uVar4,param_3);
            lVar5 = param_1[0xaa];
            thunk_EXT_FUN_8011000002c12750(lVar3);
            uVar4 = thunk_EXT_FUN_8011000002c134f4();
            uVar1 = 0x850900d0;
          }
          thunk_EXT_FUN_80110000036da494(uVar1,lVar5,0,uVar4,param_3,0);
        }
        else {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s: Failed to find shared event reference\n");
          *(undefined4 *)(param_1 + 0xa4) = 10;
        }
        if (local_58 != (long *)0x0) {
          (**(code **)(*local_58 + 0x28))();
        }
        *(int *)(param_1[0xa6] + 0x2e8) = (int)param_1[0x92];
      }
      else {
        uVar6 = 0;
      }
    }
    thunk_EXT_FUN_80110000032222a8(param_1[0xa5]);
    if ((*(byte *)((long)param_1 + 0x525) & 1) != 0) {
      (**(code **)(*param_1 + 0xe0))(param_1);
      *(undefined1 *)((long)param_1 + 0x525) = 0;
    }
    *(undefined1 *)((long)param_1 + 0x526) = 0;
    thunk_EXT_FUN_8011000003222de0(param_1[0xa5]);
    thunk_EXT_FUN_8011000003222de0(param_1[0x8b]);
    FUN_fffffff009975bcc(param_1[0xa6]);
  }
  return uVar6;
}

