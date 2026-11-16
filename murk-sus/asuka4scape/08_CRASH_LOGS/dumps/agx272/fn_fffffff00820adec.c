// FUN_fffffff00820adec @ fffffff00820adec size=196

void FUN_fffffff00820adec(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  if ((*(long *)(param_1 + 0x188) != 0) && ((*(byte *)(param_2 + 0x1250) & 1) != 0)) {
    thunk_EXT_FUN_80110000029699e0(param_2,*(long *)(param_1 + 0x188));
    thunk_EXT_FUN_8011000002950f84(*(undefined8 *)(param_1 + 0x188),param_1,1);
    lVar3 = *(long *)(param_1 + 0x188);
    lVar1 = (**(code **)(**(long **)(lVar3 + 0x20) + 0x98))();
    if ((*(byte *)(lVar3 + 0x10) & 0x7f) == 0) {
      uVar2 = *(ulong *)(lVar3 + 0x48);
    }
    else if (*(byte *)(lVar3 + 0x10) == 0x82) {
      uVar2 = (ulong)*(uint *)(lVar3 + 0x4c);
    }
    else {
      uVar2 = 0;
    }
    *(ulong *)(param_2 + 0x1240) = uVar2 + lVar1;
    *(ulong *)(param_2 + 0x1248) = (ulong)*(uint *)(param_1 + 400);
  }
  return;
}

