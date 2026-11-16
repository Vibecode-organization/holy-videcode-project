// FUN_fffffff00996311c @ fffffff00996311c size=136

void FUN_fffffff00996311c(long param_1,long param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x58));
  lVar5 = *(long *)(param_1 + 0x48);
  lVar4 = (long)*(int *)(param_2 + 0x424) * 0x18;
  puVar1 = (undefined8 *)(lVar5 + (int)lVar4);
  if (lVar4 - (int)lVar4 != 0) {
    puVar1 = (undefined8 *)(lVar5 + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
  }
  lVar4 = lVar4 + 8;
  puVar2 = (undefined8 *)(lVar5 + (int)lVar4);
  if (lVar4 != (int)lVar4) {
    puVar2 = (undefined8 *)(lVar5 + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar1 = 0;
  *puVar2 = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099631a0);
    (*pcVar3)();
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x58));
  return;
}

