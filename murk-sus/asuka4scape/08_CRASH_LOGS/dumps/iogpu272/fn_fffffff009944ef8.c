// FUN_fffffff009944ef8 @ fffffff009944ef8 size=132

void FUN_fffffff009944ef8(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  ulong unaff_x30;
  
  uVar3 = (ulong)*(uint *)(param_1 + 0x28);
  if (*(uint *)(param_1 + 0x28) != 0) {
    uVar5 = 0;
    lVar4 = *(long *)(param_1 + 0x10);
    do {
      plVar2 = *(long **)(lVar4 + uVar5 * 8);
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x28))();
        lVar4 = *(long *)(param_1 + 0x10);
        uVar3 = (ulong)*(uint *)(param_1 + 0x28);
      }
      *(undefined8 *)(lVar4 + uVar5 * 8) = 0;
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar3);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009944f78);
    (*pcVar1)();
  }
  FUN_fffffff009944574(param_1);
  return;
}

