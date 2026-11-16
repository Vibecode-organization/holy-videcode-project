// FUN_fffffff009c3c7fc @ fffffff009c3c7fc size=216
// CALLERS:
//   fffffff00afec0cf no-fn
//   fffffff009c3a020 FUN_fffffff009c39f5c@fffffff009c39f5c
// CALLEES:
//   fffffff009c49674 thunk_FUN_fffffff00a228d30
//   fffffff009c49a74 thunk_FUN_fffffff00a89a344
//   fffffff009c49684 thunk_FUN_fffffff00a227a00
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30
//   fffffff009c49764 thunk_FUN_fffffff00a8d8754

undefined8 FUN_fffffff009c3c7fc(long param_1,long param_2,ulong param_3)

{
  undefined ******ppppppuVar1;
  long *plVar2;
  undefined8 uVar3;
  
  uVar3 = 0xe00002c2;
  ppppppuVar1 = thunk_FUN_fffffff00a8d8754
                          ((char *)(param_2 + 0xc),
                           (param_2 + (param_3 & 0xffffffff)) - (param_2 + 0xc),(undefined8 *)0x0);
  if (ppppppuVar1 != (undefined ******)0x0) {
    plVar2 = thunk_FUN_fffffff00a894f30((long *)ppppppuVar1,*(long *)PTR_PTR_fffffff00806c9f0);
    if (plVar2 != (long *)0x0) {
      thunk_FUN_fffffff00a227a00(*(ulong *)(param_1 + 0xe0));
      plVar2 = thunk_FUN_fffffff00a89a344(plVar2,0);
      if (*(long **)(param_1 + 0x130) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x130) + 0x28))();
      }
      *(long **)(param_1 + 0x130) = plVar2;
      thunk_FUN_fffffff00a228d30(*(long *)(param_1 + 0xe0));
      uVar3 = 0;
    }
    (*(code *)(*ppppppuVar1)[5])(ppppppuVar1);
  }
  return uVar3;
}

