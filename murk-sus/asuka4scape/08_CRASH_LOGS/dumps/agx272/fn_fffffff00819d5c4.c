// FUN_fffffff00819d5c4 @ fffffff00819d5c4 size=264

undefined8 FUN_fffffff00819d5c4(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  long *plVar4;
  undefined8 *puVar5;
  undefined8 local_50;
  undefined8 uStack_48;
  
  if ((*(byte *)(param_1 + 0x130) & 1) == 0) {
    uVar2 = thunk_EXT_FUN_8011000002960e38
                      (*(undefined8 *)(param_1 + 0x120),
                       "com.apple.internal.display-params-access-privileged");
    if ((uVar2 & 1) == 0) {
      *(undefined1 *)(param_1 + 0x130) = 0;
      return 0xe00002c1;
    }
    uVar3 = thunk_EXT_FUN_801100000372056c(*(undefined4 *)(param_1 + 0xe0));
    iVar1 = thunk_EXT_FUN_80110000036e83c0();
    thunk_EXT_FUN_8011000003720838(uVar3);
    *(bool *)(param_1 + 0x130) = iVar1 != 0;
    if (iVar1 == 0) {
      return 0xe00002c1;
    }
  }
  if (*(long *)(param_1 + 0xf8) == 0) {
    uVar3 = 0xe00002c9;
  }
  else {
    plVar4 = *(long **)(*(long *)(param_1 + 0xf8) + 0x310);
    puVar5 = (undefined8 *)(*plVar4 + 0xe8);
    local_50 = param_3;
    uStack_48 = param_2;
    uVar3 = (*(code *)*puVar5)(puVar5,plVar4,FUN_fffffff00817dad8,&uStack_48,&local_50,0,0);
  }
  return uVar3;
}

