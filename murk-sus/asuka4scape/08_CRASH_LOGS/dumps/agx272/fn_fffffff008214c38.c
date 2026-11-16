// FUN_fffffff008214c38 @ fffffff008214c38 size=112

void FUN_fffffff008214c38(long *param_1,ulong *param_2,undefined8 param_3)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  
  uVar3 = thunk_EXT_FUN_8011000003769480(*param_1,*param_2,param_3,&stack0x00000000);
  if (-1 < (int)uVar3) {
    uVar4 = (ulong)uVar3;
    uVar5 = *param_2;
    uVar1 = uVar5;
    if (uVar4 <= uVar5) {
      uVar1 = uVar4;
    }
    uVar2 = 0;
    if (uVar4 <= uVar5) {
      uVar2 = uVar5 - uVar4;
    }
    *param_1 = *param_1 + uVar1;
    *param_2 = uVar2;
  }
  return;
}

