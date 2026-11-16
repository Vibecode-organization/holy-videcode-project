// FUN_fffffff009c3e570 @ fffffff009c3e570 size=764

/* WARNING: Removing unreachable block (ram,0xfffffff009c3e6e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3e5f8) */

undefined8
FUN_fffffff009c3e570(long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  long *plVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  long *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar1 = (long *)thunk_EXT_FUN_80110000038d4754(param_3,param_4,0);
  plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(plVar1,*(undefined8 *)PTR_DAT_fffffff00806c9c8);
  if (plVar2 == (long *)0x0) {
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar1 + 0x28))(plVar1);
    }
    uVar3 = 0xe00002c2;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - invalid args\n");
  }
  else {
    local_40 = (long *)0x0;
    lVar5 = *(long *)(param_1 + 0xf8);
    if (lVar5 == 0) {
      lVar5 = 0;
    }
    uVar3 = thunk_EXT_FUN_80110000039a3bc0(lVar5,param_2,&local_40);
    if ((int)uVar3 == 0) {
      plVar1 = (long *)FUN_fffffff009c4078c(&local_40);
      if (plVar1 == (long *)0x0) {
        uVar3 = 0xe00002c2;
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "%s error - invalid memory pool port\n");
      }
      else {
        lVar5 = thunk_EXT_FUN_801100000325c0a0();
        if (lVar5 == plVar1[6]) {
          (**(code **)(*plVar2 + 0x20))(plVar2);
          uVar4 = FUN_fffffff009c45b34(plVar1,plVar2);
          if ((uVar4 & 1) == 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - ensureMemory failed\n"
                      );
            uVar3 = 0xe00002bc;
          }
          else {
            uVar3 = 0;
          }
        }
        else {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                     "%s error - task does not own memory pool\n");
          uVar3 = 0xe00002e2;
        }
        (**(code **)(*plVar1 + 0x28))(plVar1);
      }
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "%s error - copyObjectForPortNameInTask failed\n");
    }
    if (local_40 != (long *)0x0) {
      (**(code **)(*local_40 + 0x28))();
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
    uVar3 = thunk_EXT_FUN_8011000003a48590();
    return uVar3;
  }
  return uVar3;
}

