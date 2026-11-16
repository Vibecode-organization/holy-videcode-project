// FUN_fffffff009c606f4 @ fffffff009c606f4

undefined8 FUN_fffffff009c606f4(long param_1,ulong *param_2)

{
  ushort uVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  uVar4 = 0xe00002bd;
  if (param_2 == (ulong *)0x0) {
    uVar4 = 0xe00002c2;
  }
  else {
    *param_2 = 0xffffffffffffffff;
    thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0xf8));
    if ((*(byte *)(param_1 + 0xbb) & 1) == 0) {
      uVar4 = 0xe00002c9;
    }
    else {
      thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0xe8));
      if ((*(byte *)(param_1 + 0xba) & 1) == 0) {
        uVar4 = 0xe00002be;
      }
      else {
        uVar5 = *(ulong *)(param_1 + 0xb0) | (ulong)*(ushort *)(param_1 + 0xb8);
        plVar2 = thunk_FUN_fffffff00a8cae24(uVar5,0x40);
        if (plVar2 != (long *)0x0) {
          (**(code **)(**(long **)(param_1 + 0x88) + 0xe8))(*(long **)(param_1 + 0x88),plVar2);
          (**(code **)(*plVar2 + 0x28))(plVar2);
          *param_2 = uVar5;
          uVar1 = *(short *)(param_1 + 0xb8) + 1;
          *(ushort *)(param_1 + 0xb8) = uVar1;
          uVar5 = *(ulong *)(param_1 + 0xb0) | (ulong)uVar1;
          uVar4 = FUN_fffffff009c605fc(param_1,uVar5);
          if ((int)uVar4 != 0) {
            do {
              if (uVar5 == *param_2) break;
              uVar1 = *(short *)(param_1 + 0xb8) + 1;
              *(ushort *)(param_1 + 0xb8) = uVar1;
              uVar5 = *(ulong *)(param_1 + 0xb0) | (ulong)uVar1;
              uVar3 = FUN_fffffff009c605fc(param_1,uVar5);
            } while ((uVar3 & 1) != 0);
          }
          if (uVar5 == *param_2) {
            uVar4 = 0;
            *(undefined1 *)(param_1 + 0xba) = 0;
          }
          else {
            uVar4 = 0;
          }
        }
      }
      thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0xe8));
    }
    thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0xf8));
  }
  return uVar4;
}

