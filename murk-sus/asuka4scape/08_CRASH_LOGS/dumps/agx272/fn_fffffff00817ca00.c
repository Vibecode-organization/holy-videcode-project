// FUN_fffffff00817ca00 @ fffffff00817ca00 size=392

void FUN_fffffff00817ca00(long param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  long lVar4;
  
  if ((*(byte *)(param_1 + 0x530) & 1) == 0) {
    return;
  }
  iVar1 = thunk_EXT_FUN_8011000002946de4(*(undefined8 *)(param_1 + 0x148));
  if (iVar1 != 0) {
    lVar4 = *(long *)(param_1 + 0x4b0);
    iVar1 = (**(code **)(*(long *)(lVar4 + 0x848) + 0x30))(lVar4 + 0x848);
    iVar2 = (**(code **)(*(long *)(lVar4 + 0x848) + 0x38))(lVar4 + 0x848);
    if ((iVar1 != iVar2) ||
       (iVar1 = (**(code **)(**(long **)(param_1 + 0x4b0) + 0x80))(), iVar1 == 0)) {
      (**(code **)(**(long **)(param_1 + 0x528) + 0xf0))
                (*(long **)(param_1 + 0x528),*(undefined1 *)(param_1 + 0x65c));
      uVar3 = 1;
      goto LAB_fffffff00817cb38;
    }
    if (((*(byte *)(param_1 + 0x531) & 1) != 0) && (*(char *)(param_1 + 0x115c1) == '\x01')) {
      (**(code **)(**(long **)(param_1 + 0x4b0) + 0x298))(*(long **)(param_1 + 0x4b0),2);
      *(char *)(param_1 + 0x115c1) = '\x02';
      if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494(0x85930c14,0,0,0,0,0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
        uVar3 = 0;
        goto LAB_fffffff00817cb38;
      }
    }
  }
  uVar3 = 0;
LAB_fffffff00817cb38:
  *(undefined1 *)(param_1 + 0x530) = uVar3;
  return;
}

