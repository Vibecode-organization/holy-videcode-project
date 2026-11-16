// FUN_fffffff009965dc0 @ fffffff009965dc0 size=284

undefined8 FUN_fffffff009965dc0(long param_1,int param_2,int param_3,undefined8 *param_4)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  
  if ((param_2 - 0x2001U < 0xffffe000) || (param_3 - 0x29U < 0xffffffd8)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Invalid arguments : numEntries = %u, entrySize = %u \n");
    uVar3 = 0xe00002c2;
  }
  else {
    plVar2 = (long *)FUN_fffffff009982e58(*(undefined8 *)(param_1 + 0x50));
    if (plVar2 != (long *)0x0) {
      iVar1 = thunk_FUN_fffffff009944798(*(undefined8 *)(param_1 + 0x90),plVar2);
      if (iVar1 != 0) {
        *(int *)(param_4 + 1) = iVar1;
        uVar3 = FUN_fffffff009983188(plVar2);
        *param_4 = uVar3;
        (**(code **)(*plVar2 + 0x28))(plVar2);
        return 0;
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    uVar3 = 0xe00002bd;
    *(undefined4 *)(param_4 + 1) = 0;
    *param_4 = 0;
  }
  return uVar3;
}

