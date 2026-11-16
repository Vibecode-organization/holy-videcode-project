// FUN_fffffff008d15230 @ fffffff008d15230 size=160
// CALLERS:
//   fffffff00afb8d56 no-fn
// CALLEES:
//   fffffff008de69c8 FUN_fffffff008de69c8
//   fffffff008cd5954 FUN_fffffff008cd5954
//   fffffff008de6984 FUN_fffffff008de6984

undefined8 FUN_fffffff008d15230(long param_1,uint *param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (param_3 == 0x18) {
    if (*param_2 < 4) {
      uVar2 = 0;
      *(uint *)(param_1 + 0x168) = *param_2;
      uVar3 = *(undefined8 *)(param_2 + 2);
      *(undefined8 *)(param_1 + 0x178) = *(undefined8 *)(param_2 + 4);
      *(undefined8 *)(param_1 + 0x170) = uVar3;
    }
    else {
      uVar2 = 0xe00002c2;
      iVar1 = FUN_fffffff008cd5954(1,4);
      if (iVar1 != 0) {
        FUN_fffffff008de69c8(param_2);
      }
    }
  }
  else {
    uVar2 = 0xe00002c2;
    iVar1 = FUN_fffffff008cd5954(1,4);
    if (iVar1 != 0) {
      FUN_fffffff008de6984(param_3);
    }
  }
  return uVar2;
}

