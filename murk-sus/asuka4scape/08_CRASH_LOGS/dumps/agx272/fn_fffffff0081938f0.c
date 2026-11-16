// FUN_fffffff0081938f0 @ fffffff0081938f0 size=516

void FUN_fffffff0081938f0(long param_1,long *param_2,long param_3)

{
  ulong uVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000029595ec(param_3);
  *(byte *)(param_1 + 0x7e8) =
       *(byte *)(param_1 + 0x7e8) | (byte)(1 << (ulong)(*(uint *)(param_3 + 0xe8) & 0x1f));
  (**(code **)(**(long **)(param_1 + 0x800) + 0x98))(*(long **)(param_1 + 0x800),param_1 + 0x728);
  plVar5 = *(long **)(param_1 + 0x800);
  (**(code **)(*plVar5 + 0x98))(plVar5,param_1 + 0x498);
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x11164) & 1) != 0) {
    thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(plVar5[2] + 0x148),plVar5 + 0x23,param_1 + 0x628)
    ;
  }
  *(byte *)(param_1 + 0x7e9) =
       *(byte *)(param_1 + 0x7e9) | (byte)(1 << (ulong)(*(uint *)(param_3 + 0xe8) & 0x1f));
  (**(code **)(**(long **)(param_1 + 0x808) + 0x98))(*(long **)(param_1 + 0x808),param_1 + 0x768);
  plVar5 = *(long **)(param_1 + 0x808);
  (**(code **)(*plVar5 + 0x98))(plVar5,param_1 + 0x498);
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x11164) & 1) != 0) {
    thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(plVar5[2] + 0x148),plVar5 + 0x23,param_1 + 0x628)
    ;
  }
  lVar3 = *(long *)(*(long *)(param_1 + 0x610) + 0xa8);
  lVar4 = (ulong)*(uint *)(lVar3 + 0x28) * 0x40;
  uVar1 = lVar3 + 0x4c0 + (long)(int)lVar4;
  if (lVar4 - (int)lVar4 != 0) {
    uVar1 = lVar3 + 0x4c0 + lVar4 & 0xffffffffffffU | 0x2bad000000000000;
  }
  thunk_EXT_FUN_801100000294849c
            (*(undefined8 *)(*(long *)(lVar3 + 0x18) + 0x148),param_1 + 0x498,uVar1);
  (**(code **)(*param_2 + 0x28))(param_2);
  lVar3 = *(long *)(param_1 + 0x530);
  if ((((*(byte *)(*(long *)(lVar3 + 0x111b0) + 0x54) & 1) == 0) ||
      ((*(byte *)(*(long *)(lVar3 + 0x111b0) + 0x2c) >> 4 & 1) == 0)) &&
     ((*(byte *)(lVar3 + 0x5c8) >> 5 & 1) == 0)) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008193af0);
    (*pcVar2)();
  }
  thunk_EXT_FUN_8011000002947870(*(undefined8 *)(lVar3 + 0x148),param_1 + 0x498);
  return;
}

