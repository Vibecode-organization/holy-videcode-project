// FUN_fffffff0081feeec @ fffffff0081feeec size=484

undefined8 FUN_fffffff0081feeec(long param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  
  plVar1 = (long *)(**(code **)(**(long **)(param_1 + 0x10) + 0x5e8))
                             (*(long **)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x28));
  if (plVar1 != (long *)0x0) {
    plVar2 = (long *)(**(code **)(**(long **)(param_1 + 0x10) + 0x5e8))
                               (*(long **)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x28));
    if (plVar2 != (long *)0x0) {
      lVar3 = (**(code **)(**(long **)(param_1 + 0x10) + 0x5e8))
                        (*(long **)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x28));
      if (lVar3 != 0) {
        thunk_EXT_FUN_80110000038fe9a0("Created AGX Protected Contexts for %p\n");
        *(long **)(param_1 + 0x2d8) = plVar1;
        *(undefined4 *)((long)plVar1 + 0x274) = 1;
        plVar1[0x5f] = param_1;
        thunk_EXT_FUN_801100000296ca14
                  (*(undefined8 *)(param_1 + 0x2d8),*(undefined8 *)(param_1 + 0x30));
        lVar4 = *(long *)(*(long *)(param_1 + 0x2d8) + 0x1e0);
        if (lVar4 != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 0x38));
          *(long *)(lVar4 + 0x18) = param_1;
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 0x38));
        }
        *(long **)(param_1 + 0x2e0) = plVar2;
        *(undefined4 *)((long)plVar2 + 0x274) = 3;
        plVar2[0x5f] = param_1;
        thunk_EXT_FUN_801100000296ca14
                  (*(undefined8 *)(param_1 + 0x2e0),*(undefined8 *)(param_1 + 0x30));
        lVar4 = *(long *)(*(long *)(param_1 + 0x2e0) + 0x1e0);
        if (lVar4 != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 0x38));
          *(long *)(lVar4 + 0x18) = param_1;
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 0x38));
        }
        *(long *)(param_1 + 0x2e8) = lVar3;
        *(undefined4 *)(lVar3 + 0x274) = 7;
        *(long *)(lVar3 + 0x2f8) = param_1;
        thunk_EXT_FUN_801100000296ca14
                  (*(undefined8 *)(param_1 + 0x2e8),*(undefined8 *)(param_1 + 0x30));
        lVar3 = *(long *)(*(long *)(param_1 + 0x2e8) + 0x1e0);
        if (lVar3 != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x38));
          *(long *)(lVar3 + 0x18) = param_1;
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x38));
        }
        *(undefined1 *)(param_1 + 0x2f0) = 1;
        return 1;
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return 0;
}

