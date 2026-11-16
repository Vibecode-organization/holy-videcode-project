// FUN_fffffff009944a54 @ fffffff009944a54 size=260

long * FUN_fffffff009944a54(long param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  long *plVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x20));
  if (*(int *)(param_1 + 0x30) == 0) {
    plVar4 = (long *)0x0;
  }
  else {
    plVar4 = (long *)thunk_EXT_FUN_80110000038961f4();
    if (plVar4 != (long *)0x0) {
      uVar1 = *(uint *)(param_1 + 0x28);
      uVar2 = *(uint *)(param_1 + 0x30);
      if (1 < uVar1 && uVar2 != 0) {
        uVar6 = 0;
        lVar7 = 1;
        uVar8 = 2;
        do {
          plVar5 = *(long **)(*(long *)(param_1 + 0x10) + lVar7 * 8);
          if ((plVar5 != (long *)0x0) && (iVar3 = FUN_fffffff00994d91c(plVar5), iVar3 != 0)) {
            (**(code **)(*plVar4 + 0xe8))(plVar4,plVar5);
            (**(code **)(*plVar5 + 0x28))(plVar5);
            uVar6 = uVar6 + 1;
          }
          if (uVar1 <= uVar8) break;
          lVar7 = lVar7 + 1;
          uVar8 = uVar8 + 1;
        } while (uVar6 < uVar2);
      }
    }
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x20));
  return plVar4;
}

