// FUN_fffffff009c3c7fc @ fffffff009c3c7fc size=216

undefined8 FUN_fffffff009c3c7fc(long param_1,long param_2,ulong param_3)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = 0xe00002c2;
  plVar1 = (long *)thunk_EXT_FUN_80110000038d4754
                             (param_2 + 0xc,(param_2 + (param_3 & 0xffffffff)) - (param_2 + 0xc),0);
  if (plVar1 != (long *)0x0) {
    lVar2 = thunk_EXT_FUN_8011000003890f30(plVar1,*(undefined8 *)PTR_DAT_fffffff00806c9f0);
    if (lVar2 != 0) {
      thunk_EXT_FUN_8011000003223a00(*(undefined8 *)(param_1 + 0xe0));
      uVar3 = thunk_EXT_FUN_8011000003896344(lVar2,0);
      if (*(long **)(param_1 + 0x130) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x130) + 0x28))();
      }
      *(undefined8 *)(param_1 + 0x130) = uVar3;
      thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0xe0));
      uVar3 = 0;
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar3;
}

