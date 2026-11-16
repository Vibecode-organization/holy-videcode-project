// FUN_fffffff009979888 @ fffffff009979888 size=284

void FUN_fffffff009979888(long *param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  uint uVar2;
  
  while( true ) {
    if ((int)param_1[0xa4] != 0) {
      return;
    }
    if (param_3 < param_2 + 8) break;
    uVar2 = *(uint *)(param_2 + 4);
    uVar1 = param_2 + uVar2;
    if ((CARRY8(param_2,(ulong)uVar2)) || ((uVar2 < 8 || param_3 < uVar1) || (uVar2 & 3) != 0)) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Invalid command_size (%u) min=%lu currentCommand=%p kernelCommandEnd=%p\n");
      goto LAB_fffffff009979984;
    }
    (**(code **)(*param_1 + 0xd0))(param_1,param_2,uVar1);
    param_2 = uVar1;
    if (param_3 <= uVar1) {
      return;
    }
  }
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
             "%s: Insufficient space (%lu) to hold sIOGPUKernelCommand (%lu)\n");
LAB_fffffff009979984:
  *(undefined4 *)(param_1 + 0xa4) = 10;
  return;
}

