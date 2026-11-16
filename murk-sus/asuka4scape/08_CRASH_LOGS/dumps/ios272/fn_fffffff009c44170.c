// FUN_fffffff009c44170 @ fffffff009c44170 size=624

/* WARNING: Removing unreachable block (ram,0xfffffff009c441e0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff009c44170(long param_1,long param_2)

{
  undefined8 uVar1;
  long *plVar2;
  long lVar3;
  char *pcVar4;
  undefined8 *puVar5;
  long *plVar6;
  char local_70 [8];
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  uStack_68 = ram0xfffffff0078a12d8;
  local_70 = (char  [8])s__unknown__fffffff0078a12d0._0_8_;
  uStack_58 = 0;
  uStack_60 = 0;
  if (param_2 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
               "IOSurfaceMemoryPool: %s (%d) invalid task (%p) can\'t access pool id %llu (wrong entitlements)\n"
              );
    pcVar4 = 
    "====> %s:%d IOSurfaceMemoryPool: %s (%d) invalid task (%p) can\'t access pool id %llu (wrong entitlements)\n"
    ;
LAB_fffffff009c443a4:
    thunk_EXT_FUN_80110000038fe9a0(pcVar4);
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    if ((param_2 == *(long *)(param_1 + 0x30)) || (param_2 == *(long *)PTR_DAT_fffffff00806ca70))
    goto LAB_fffffff009c443ac;
    if (*(long **)(param_1 + 0xa8) == (long *)0x0) {
      puVar5 = *(undefined8 **)PTR_DAT_fffffff00806ca60;
LAB_fffffff009c442dc:
      plVar2 = (long *)thunk_EXT_FUN_80110000039a2b94(param_2,"com.apple.private.iosurfaceinfo");
      plVar6 = (long *)*puVar5;
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x28))(plVar2);
      }
      if (plVar6 != plVar2) {
        lVar3 = thunk_EXT_FUN_80110000032970b4(param_2);
        if (lVar3 != 0) {
          uVar1 = thunk_EXT_FUN_8011000003720f30();
          thunk_EXT_FUN_8011000003722d80(uVar1,local_70,0x20);
        }
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurfaceMemoryPool: %s (%d) can\'t access pool id %llu (wrong entitlements)\n")
        ;
        pcVar4 = 
        "====> %s:%d IOSurfaceMemoryPool: %s (%d) can\'t access pool id %llu (wrong entitlements)\n"
        ;
        goto LAB_fffffff009c443a4;
      }
    }
    else {
      uVar1 = (**(code **)(**(long **)(param_1 + 0xa8) + 0xa8))();
      plVar2 = (long *)thunk_EXT_FUN_80110000039a2b94(param_2,uVar1);
      puVar5 = *(undefined8 **)PTR_DAT_fffffff00806ca60;
      plVar6 = (long *)*puVar5;
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x28))(plVar2);
      }
      if (plVar6 != plVar2) goto LAB_fffffff009c442dc;
    }
    uVar1 = 1;
  }
LAB_fffffff009c443ac:
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_48) {
    thunk_EXT_FUN_8011000003a48590(uVar1);
    return;
  }
  return;
}

