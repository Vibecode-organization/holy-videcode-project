// FUN_fffffff009c407ec @ fffffff009c407ec size=512

/* WARNING: Removing unreachable block (ram,0xfffffff009c40868) */

undefined8
FUN_fffffff009c407ec
          (long param_1,undefined8 param_2,undefined8 param_3,ulong param_4,undefined8 param_5)

{
  long *plVar1;
  ulong uVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  long *local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar5 = 0xe00002c2;
  plVar1 = (long *)FUN_fffffff009c3f1d0();
  if (plVar1 == (long *)0x0) goto LAB_fffffff009c4097c;
  local_50 = (long *)0x0;
  lVar4 = *(long *)(param_1 + 0xf8);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  uVar5 = thunk_EXT_FUN_80110000039a3bc0(lVar4,param_3,&local_50);
  if ((int)uVar5 == 0) {
    if (local_50 != (long *)0x0) {
      lVar4 = thunk_EXT_FUN_8011000003890f30(local_50,DAT_fffffff0080668c8);
      if (lVar4 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "%s error - invalid shared event port\n");
        uVar5 = 0xe00002c2;
      }
      else {
        FUN_fffffff009c16750();
        uVar2 = FUN_fffffff009c17500();
        if (uVar2 < param_4) {
          plVar3 = (long *)FUN_fffffff009c48a74(lVar4,param_4,param_5);
          uVar5 = 0xe00002c2;
          if (plVar3 == (long *)0x0) goto LAB_fffffff009c4088c;
          (**(code **)(*plVar3 + 0x20))();
          FUN_fffffff009c2aa08(plVar1,plVar3);
          (**(code **)(*plVar3 + 0x28))(plVar3);
        }
        uVar5 = 0;
      }
      goto LAB_fffffff009c4088c;
    }
    uVar5 = 0xe00002c2;
  }
  else {
LAB_fffffff009c4088c:
    if (local_50 != (long *)0x0) {
      (**(code **)(*local_50 + 0x28))();
    }
  }
  (**(code **)(*plVar1 + 0x28))(plVar1);
LAB_fffffff009c4097c:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return uVar5;
  }
  uVar5 = thunk_EXT_FUN_8011000003a48590();
  return uVar5;
}

