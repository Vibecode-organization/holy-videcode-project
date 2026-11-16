// FUN_fffffff00997f1c8 @ fffffff00997f1c8 size=156

undefined8 FUN_fffffff00997f1c8(long param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  *(long *)(param_1 + 0x28) = param_2;
  *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) | 0x40;
  lVar2 = (**(code **)(**(long **)(param_1 + 0x20) + 0x88))(*(long **)(param_1 + 0x20),param_1);
  if (lVar2 != 0) {
    *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) | 1;
  }
  if (lVar2 == param_2) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997f250);
      (*pcVar1)();
    }
    uVar3 = FUN_fffffff009942da8(*(undefined8 *)(param_1 + 0x18),param_1);
    return uVar3;
  }
  return 0;
}

