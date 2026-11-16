// FUN_fffffff009c3eb68 @ fffffff009c3eb68 size=680

/* WARNING: Removing unreachable block (ram,0xfffffff009c3ecec) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3ebd8) */

ulong FUN_fffffff009c3eb68(long param_1,undefined8 param_2,long *param_3)

{
  uint uVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  long lVar6;
  long *local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar2 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  local_50 = (long *)0x0;
  lVar6 = *(long *)(param_1 + 0xf8);
  if (lVar6 == 0) {
    lVar6 = 0;
  }
  uVar3 = thunk_EXT_FUN_80110000039a3bc0(lVar6,param_2,&local_50);
  if ((int)uVar3 == 0) {
    if (plVar2 == (long *)0x0) {
      uVar3 = 0xe00002bd;
    }
    else {
      plVar4 = (long *)FUN_fffffff009c4078c(&local_50);
      if (plVar4 == (long *)0x0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "%s error - invalid memory pool port\n");
        uVar3 = 0xe00002c2;
      }
      else {
        lVar6 = thunk_EXT_FUN_801100000325c0a0();
        if (lVar6 == plVar4[6]) {
          (**(code **)(*param_3 + 0x80))(param_3);
          plVar5 = (long *)FUN_fffffff009c372dc(*(undefined8 *)(param_1 + 0xe8));
          (**(code **)(*plVar2 + 0x20))(plVar2);
          FUN_fffffff009c44d30(plVar5,plVar2,plVar4[5]);
          if (plVar5 != (long *)0x0) {
            (**(code **)(*plVar5 + 0x28))(plVar5);
          }
          uVar3 = (**(code **)(*plVar2 + 0x30))(plVar2,param_3);
          uVar1 = 0;
          if ((uVar3 & 1) == 0) {
            uVar1 = 0xe00002bc;
          }
        }
        else {
          uVar1 = 0xe00002e2;
        }
        uVar3 = (ulong)uVar1;
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
    }
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
               "%s error - copyObjectForPortNameInTask failed\n");
  }
  if (local_50 != (long *)0x0) {
    (**(code **)(*local_50 + 0x28))();
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_48) {
    uVar3 = thunk_EXT_FUN_8011000003a48590();
    return uVar3;
  }
  return uVar3;
}

