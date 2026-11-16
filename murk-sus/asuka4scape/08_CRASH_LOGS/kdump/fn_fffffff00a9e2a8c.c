// FUN_fffffff00a9e2a8c @ fffffff00a9e2a8c size=428
// CALLERS:
//   fffffff00afbfad3 ?
//   fffffff007c66aa8 ?
// CALLS:
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00a9e2c38 FUN_fffffff00a9e2c38

void FUN_fffffff00a9e2a8c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,ulong param_9,ulong param_10,long *param_11)

{
  long lVar1;
  undefined **ppuVar2;
  long lVar3;
  long *plVar4;
  ulong uVar5;
  int iVar6;
  long local_68;
  long lStack_60;
  undefined *local_58;
  undefined8 *puStack_50;
  long local_48;
  undefined4 local_40;
  uint local_3c;
  long local_38;
  
  if (param_9 != 0) {
    if (*(ulong *)(param_7 + 0x20) <= param_9) {
LAB_fffffff00a9e2c1c:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114
                (param_1,param_2,param_3,param_4,param_5,param_6,
                 (byte *)"Invalid work token (%llu): index out of bounds. @%s:%d");
    }
    lVar1 = param_9 * 0x38;
    plVar4 = (long *)(*(ulong *)(param_7 + 0x18) + lVar1);
    if (((*(ulong *)(param_7 + 0x18) ^ (ulong)plVar4) & 0xffc0000000000000) != 0) {
      plVar4 = (long *)((ulong)plVar4 & 0xffffffffffff | 0xc8a2000000000000);
    }
    local_58 = *(undefined **)*plVar4;
    puStack_50 = (undefined8 *)*plVar4 + 0x60;
    local_48 = (long)plVar4 + 0x11;
    local_40 = 0x20;
    local_3c = *(byte *)(plVar4 + 2) & 1;
    local_38 = param_7 + 0x40;
    lVar3 = *(long *)(param_7 + 0x10);
    iVar6 = (int)param_11;
    if (*(ulong *)(lVar3 + 8) < 4) {
      ppuVar2 = &local_58;
      param_1 = (**(code **)(lVar3 + 0x38))
                          (param_8,param_9 | (ulong)*(byte *)(param_7 + 0xd) << 0x18);
    }
    else {
      local_68 = 0;
      lStack_60 = 0;
      ppuVar2 = &local_58;
      param_11 = &local_68;
      param_1 = (**(code **)(lVar3 + 0x58))
                          (param_8,param_9 | (ulong)*(byte *)(param_7 + 0xd) << 0x18);
      if ((*(byte *)(param_7 + 0x60) & 1) != 0) {
        uVar5 = *(ulong *)(param_7 + 0x18) + lVar1;
        if (((*(ulong *)(param_7 + 0x18) ^ uVar5) & 0xffc0000000000000) != 0) {
          uVar5 = uVar5 & 0xffffffffffff | 0xc8a2000000000000;
        }
        lVar3 = *(long *)(uVar5 + 8);
        if ((lVar3 != 0) && (*(int *)(param_7 + 0x58) == 4)) {
          *(long *)(lVar3 + 0x130) = *(long *)(lVar3 + 0x130) + local_68;
          *(long *)(lVar3 + 0x138) = *(long *)(lVar3 + 0x138) + lStack_60;
        }
      }
    }
    if (iVar6 == 0) {
      if (*(ulong *)(param_7 + 0x20) <= param_9) goto LAB_fffffff00a9e2c1c;
      uVar5 = *(ulong *)(param_7 + 0x18) + lVar1;
      if (((*(ulong *)(param_7 + 0x18) ^ uVar5) & 0xffc0000000000000) != 0) {
        uVar5 = uVar5 & 0xffffffffffff | 0xc8a2000000000000;
      }
      *(undefined1 *)(uVar5 + 0x10) = 0;
    }
    else {
      FUN_fffffff00a9e2c38
                (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_9,ppuVar2,param_10,
                 (ulong)param_11);
    }
  }
  return;
}

