// FUN_fffffff0099553c0 @ fffffff0099553c0 size=216

void FUN_fffffff0099553c0(long param_1,undefined8 param_2)

{
  int iVar1;
  long *plVar2;
  uint uVar3;
  int iVar4;
  int local_24;
  
  plVar2 = *(long **)(param_1 + 0x28);
  if (plVar2 != (long *)0x0) {
    local_24 = 0;
    iVar1 = (**(code **)(*plVar2 + 0xa8))(plVar2,param_2,&local_24);
    iVar4 = (int)param_2;
    if (iVar1 == 0) {
      if ((iVar4 == 4) || (local_24 == 4)) {
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfff7ffff;
      }
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Failed to set purgeable state 0x%x\n");
    }
    if (iVar4 - 3U < 2) {
      uVar3 = *(uint *)(param_1 + 0x10) | 0x800;
    }
    else {
      if (iVar4 != 2) {
        return;
      }
      uVar3 = *(uint *)(param_1 + 0x10) & 0xfffff7ff;
    }
    *(uint *)(param_1 + 0x10) = uVar3;
  }
  return;
}

