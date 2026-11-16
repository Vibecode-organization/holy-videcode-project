// FUN_fffffff009957f50 @ fffffff009957f50 size=832

ulong FUN_fffffff009957f50(long param_1,long *param_2,ulong param_3,ulong param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  undefined8 local_68;
  
  if (DAT_fffffff00af227e8 != 0) {
    uVar1 = (**(code **)(**(long **)(param_1 + 0x28) + 0xe0))();
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar1,&local_68);
    uVar1 = local_68;
    uVar2 = (**(code **)(*(long *)param_2[5] + 0xe0))();
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar2,&local_68);
    uVar2 = local_68;
    uVar3 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x50));
    thunk_EXT_FUN_80110000036da494(0x851801ad,uVar1,uVar2,param_4 & 0xffffffff,uVar3,0);
  }
  uVar1 = DAT_fffffff007fe8e10;
  lVar4 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x28),DAT_fffffff007fe8e10);
  if (lVar4 == 0) {
    param_4 = 0xe00002c7;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: memory is not a virtual memory\n");
  }
  else {
    lVar5 = thunk_EXT_FUN_8011000003890f30(param_2[5],uVar1);
    if (lVar5 == 0) {
      param_4 = 0xe00002c7;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: destination resoource memory is not a virtual memory\n");
    }
    else {
      if (*(int *)(lVar4 + 0x90) == *(int *)(lVar5 + 0x90)) {
        if (*(int *)((long)param_2 + 0x14) == *(int *)(param_1 + 0x14)) {
          if ((int)param_4 != 0) {
            lVar7 = 0;
            uVar8 = param_4 & 0xffffffff;
            do {
              uVar6 = param_3 + lVar7 * 0x10;
              if (((param_3 ^ uVar6) & 0xffc0000000000000) != 0) {
                uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
              }
              param_4 = FUN_fffffff009941ddc
                                  (lVar4,lVar5,*(undefined4 *)(uVar6 + 0xc),
                                   *(undefined4 *)(uVar6 + 4),*(undefined4 *)(uVar6 + 8));
              if ((int)param_4 != 0) goto LAB_fffffff0099581a8;
              lVar7 = lVar7 + 1;
              uVar8 = uVar8 - 1;
            } while (uVar8 != 0);
            param_4 = 0;
          }
          goto LAB_fffffff0099581a8;
        }
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Protection violation\n");
      }
      else {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Incompatible virtual page sizes source(%u), destination(%u)\n");
      }
      param_4 = 0xe00002e2;
    }
  }
LAB_fffffff0099581a8:
  if (DAT_fffffff00af227e8 == 0) {
    if (param_2 == (long *)0x0) {
      return param_4;
    }
  }
  else {
    uVar1 = (**(code **)(**(long **)(param_1 + 0x28) + 0xe0))();
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar1,&local_68);
    uVar1 = local_68;
    uVar2 = (**(code **)(*(long *)param_2[5] + 0xe0))();
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar2,&local_68);
    uVar2 = local_68;
    uVar3 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x50));
    thunk_EXT_FUN_80110000036da494(0x851801ae,uVar1,uVar2,(int)param_4 == 0,uVar3,0);
  }
  (**(code **)(*param_2 + 0x28))(param_2);
  return param_4;
}

