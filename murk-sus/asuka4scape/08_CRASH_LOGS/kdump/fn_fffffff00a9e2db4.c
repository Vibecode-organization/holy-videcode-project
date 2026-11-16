// FUN_fffffff00a9e2db4 @ fffffff00a9e2db4 size=260
// CALLERS:
//   fffffff00afbfad6 ?
//   fffffff007c66aa0 ?
// CALLS:
//   fffffff00aa4d114 FUN_fffffff00aa4d114

void FUN_fffffff00a9e2db4
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,ulong param_9)

{
  long *plVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 *puStack_50;
  long local_48;
  undefined8 local_40;
  long local_38;
  
  if (param_9 == 0) {
    return;
  }
  if (param_9 < *(ulong *)(param_7 + 0x20)) {
    plVar1 = (long *)(*(ulong *)(param_7 + 0x18) + param_9 * 0x38);
    if (((*(ulong *)(param_7 + 0x18) ^ (ulong)plVar1) & 0xffc0000000000000) != 0) {
      plVar1 = (long *)((ulong)plVar1 & 0xffffffffffff | 0xc8a2000000000000);
    }
    local_48 = (long)plVar1 + 0x11;
    local_58 = *(undefined8 *)*plVar1;
    puStack_50 = (undefined8 *)*plVar1 + 0x60;
    local_40 = DAT_fffffff00700dcf0;
    local_38 = param_7 + 0x40;
    param_1 = (**(code **)(*(long *)(param_7 + 0x10) + 0x30))
                        (param_8,param_9 | (ulong)*(byte *)(param_7 + 0xd) << 0x18,&local_58);
    if (param_9 < *(ulong *)(param_7 + 0x20)) {
      uVar2 = *(ulong *)(param_7 + 0x18) + param_9 * 0x38;
      if (((*(ulong *)(param_7 + 0x18) ^ uVar2) & 0xffc0000000000000) != 0) {
        uVar2 = uVar2 & 0xffffffffffff | 0xc8a2000000000000;
      }
      *(undefined1 *)(uVar2 + 0x10) = 1;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4d114
            (param_1,param_2,param_3,param_4,param_5,param_6,
             (byte *)"Invalid work token (%llu): index out of bounds. @%s:%d");
}

