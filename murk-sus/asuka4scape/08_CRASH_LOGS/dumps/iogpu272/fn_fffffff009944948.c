// FUN_fffffff009944948 @ fffffff009944948 size=188

void FUN_fffffff009944948(long param_1,ulong param_2)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  
  uVar2 = (uint)param_2;
  if ((uVar2 != 0) && (uVar2 < *(uint *)(param_1 + 0x28))) {
    if (uVar2 < *(uint *)(param_1 + 0x2c)) {
      *(uint *)(param_1 + 0x2c) = uVar2;
    }
    lVar3 = (param_2 & 0xffffffff) * 8;
    plVar1 = (long *)(*(long *)(param_1 + 0x10) + (long)(int)lVar3);
    if (lVar3 != (int)lVar3) {
      plVar1 = (long *)(*(long *)(param_1 + 0x10) + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar3 = *plVar1;
    *plVar1 = 0;
    if (lVar3 != 0) {
      uVar4 = param_2 >> 6 & 0x3ffffff;
      *(ulong *)(*(long *)(param_1 + 0x18) + uVar4 * 8) =
           *(ulong *)(*(long *)(param_1 + 0x18) + uVar4 * 8) &
           (1L << (param_2 & 0x3f) ^ 0xffffffffffffffffU);
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
    }
    return;
  }
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
             "trying to remove apparently bogus texture handle %d\n");
  return;
}

