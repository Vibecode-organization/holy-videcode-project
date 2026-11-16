// FUN_fffffff008193af4 @ fffffff008193af4 size=368

void FUN_fffffff008193af4(long param_1,long *param_2,long param_3,long *param_4)

{
  ulong uVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000029595ec(param_3);
  (**(code **)(*param_2 + 0x28))(param_2);
  *(byte *)(param_1 + 0x7ea) =
       *(byte *)(param_1 + 0x7ea) | (byte)(1 << (ulong)(*(uint *)(param_3 + 0xe8) & 0x1f));
  (**(code **)(*param_4 + 0x98))(param_4,param_1 + 0x7a8);
  (**(code **)(*param_4 + 0x98))(param_4,param_1 + 0x498);
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x11164) & 1) != 0) {
    thunk_EXT_FUN_80110000029486ac
              (*(undefined8 *)(param_4[2] + 0x148),param_4 + 0x23,param_1 + 0x628);
  }
  lVar3 = *(long *)(*(long *)(param_1 + 0x610) + 0xa8);
  lVar4 = (ulong)*(uint *)(lVar3 + 0x28) * 0x40;
  uVar1 = lVar3 + 0x4c0 + (long)(int)lVar4;
  if (lVar4 - (int)lVar4 != 0) {
    uVar1 = lVar3 + 0x4c0 + lVar4 & 0xffffffffffffU | 0x2bad000000000000;
  }
  thunk_EXT_FUN_801100000294849c
            (*(undefined8 *)(*(long *)(lVar3 + 0x18) + 0x148),param_1 + 0x498,uVar1);
  lVar3 = *(long *)(param_1 + 0x530);
  if ((((*(byte *)(*(long *)(lVar3 + 0x111b0) + 0x54) & 1) == 0) ||
      ((*(byte *)(*(long *)(lVar3 + 0x111b0) + 0x2c) >> 4 & 1) == 0)) &&
     ((*(byte *)(lVar3 + 0x5c8) >> 5 & 1) == 0)) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008193c60);
    (*pcVar2)();
  }
  thunk_EXT_FUN_8011000002947870(*(undefined8 *)(lVar3 + 0x148),param_1 + 0x498);
  return;
}

