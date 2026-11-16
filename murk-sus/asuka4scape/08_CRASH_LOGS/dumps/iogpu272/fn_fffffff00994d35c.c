// FUN_fffffff00994d35c @ fffffff00994d35c size=96

void FUN_fffffff00994d35c(long param_1,ulong param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  ulong unaff_x30;
  
  uVar2 = (param_2 & 0xffffffff) << 3;
  uVar5 = -(param_2 >> 0x1f & 1) & 0xfffffff800000000 | uVar2;
  iVar4 = (int)uVar2;
  puVar1 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar4);
  if (uVar5 != (long)iVar4) {
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x20) + uVar5 & 0xffffffffffff | 0x2bad000000000000)
    ;
  }
  *(undefined4 *)*puVar1 = param_3;
  FUN_fffffff00994ae48();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994d3b8);
    (*pcVar3)();
  }
  FUN_fffffff009974f9c(*(undefined8 *)(param_1 + 0x10));
  return;
}

