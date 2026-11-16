// FUN_fffffff009962de0 @ fffffff009962de0 size=220

void FUN_fffffff009962de0(long param_1,undefined8 param_2)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  long *plVar5;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x160));
  for (plVar5 = *(long **)(param_1 + 0x168); plVar5 != (long *)0x0; plVar5 = (long *)plVar5[6]) {
    (**(code **)(*plVar5 + 0x90))(plVar5);
    FUN_fffffff00995db74(plVar5,param_2);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x160));
  uVar1 = (ulong)*(uint *)(param_1 + 0x50);
  if (0 < (int)*(uint *)(param_1 + 0x50)) {
    lVar2 = 0;
    uVar3 = *(ulong *)(param_1 + 0x48);
    do {
      plVar5 = (long *)(uVar3 + lVar2 * 0x18);
      if (((uVar3 ^ (ulong)plVar5) & 0xffc0000000000000) != 0) {
        plVar5 = (long *)((ulong)plVar5 & 0xffffffffffff | 0xc8a2000000000000);
      }
      if (*plVar5 != 0) {
        *(int *)(plVar5 + 1) = (int)param_2;
        uVar4 = uVar3 + lVar2 * 0x18;
        if (((uVar3 ^ uVar4) & 0xffc0000000000000) != 0) {
          uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
        }
        *(undefined1 *)(uVar4 + 0x10) = 1;
      }
      lVar2 = lVar2 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return;
}

