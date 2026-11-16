// FUN_fffffff0099431c4 @ fffffff0099431c4 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff009943314) */

long * FUN_fffffff0099431c4
                 (long param_1,long param_2,undefined8 param_3,long param_4,long param_5,
                 undefined4 param_6)

{
  int iVar1;
  ulong uVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  
  if (((uint)param_3 >> 7 & 1) == 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x48));
    if (*(int *)(param_1 + 0x50) == 2) {
      lVar4 = param_1 + 0x60;
    }
    else {
      lVar4 = *(long *)(param_1 + 0x58);
    }
    if (0 < *(int *)(param_1 + 0x54)) {
      lVar5 = 0;
      do {
        plVar3 = *(long **)(lVar4 + lVar5 * 8);
        if ((plVar3[4] == param_2) &&
           (((((uint)param_3 >> 3 & 1) == 0 ||
             (iVar1 = (**(code **)(*plVar3 + 0x90))(plVar3,param_3), iVar1 != 0)) &&
            (uVar2 = FUN_fffffff00994d91c(plVar3), (uVar2 & 1) != 0)))) {
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x48));
          return plVar3;
        }
        lVar5 = lVar5 + 1;
      } while (lVar5 < *(int *)(param_1 + 0x54));
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x48));
  }
  if (param_4 != 0 && param_5 != 0) {
    param_6 = 1;
  }
  plVar3 = (long *)(**(code **)(**(long **)(param_1 + 0x10) + 0x5a8))
                             (*(long **)(param_1 + 0x10),param_2,param_1,param_3,param_6);
  if (plVar3 != (long *)0x0) {
    if (param_4 == 0 || param_5 == 0) {
      uVar2 = (**(code **)(*plVar3 + 0xb0))(plVar3);
      if ((uVar2 & 1) != 0) {
        return plVar3;
      }
    }
    else {
      uVar2 = (**(code **)(*plVar3 + 0xb8))(plVar3,param_4,param_5);
      if ((uVar2 & 1) != 0) {
        return plVar3;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: failed to reserve the GPUVM address 0x%llx length 0x%llx\n");
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return (long *)0x0;
}

