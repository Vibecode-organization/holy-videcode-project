// FUN_fffffff00997762c @ fffffff00997762c size=356

void FUN_fffffff00997762c
               (long *param_1,undefined8 param_2,ulong param_3,ulong param_4,undefined8 param_5,
               undefined8 param_6,undefined8 param_7)

{
  ulong uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  while( true ) {
    if ((int)param_1[0xa4] != 0) {
      return;
    }
    if ((*(byte *)(param_1 + 0xb9) & 1) != 0) {
      uVar3 = 0x13;
      goto LAB_fffffff00997776c;
    }
    if (param_4 < param_3 + 8) break;
    uVar2 = *(uint *)(param_3 + 4);
    uVar1 = param_3 + uVar2;
    if ((((CARRY8(param_3,(ulong)uVar2)) || (uVar2 < 8)) || (param_4 < uVar1)) || ((uVar2 & 3) != 0)
       ) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Invalid command_size (%u) min=%lu currentCommand=%p kernelCommandEnd=%p\n");
      goto LAB_fffffff009977768;
    }
    (**(code **)(*param_1 + 0xa0))(param_1,param_2,param_3,uVar1,param_5,param_6,param_7);
    param_3 = uVar1;
    if (param_4 <= uVar1) {
      return;
    }
  }
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
             "%s: Insufficient space (%lu) to hold sIOGPUKernelCommand (%lu)\n");
LAB_fffffff009977768:
  uVar3 = 10;
LAB_fffffff00997776c:
  *(undefined4 *)(param_1 + 0xa4) = uVar3;
  return;
}

