// FUN_fffffff00a498250 @ fffffff00a498250 size=200

undefined8 FUN_fffffff00a498250(ulong param_1,undefined2 *param_2,ulong param_3)

{
  undefined2 *puVar1;
  ulong uVar2;
  byte bVar3;
  code *pcVar4;
  
  if (param_3 < 0x14) {
    return 0x16;
  }
  if (param_2 <= (undefined2 *)((long)param_2 + 0xff)) {
    bVar3 = *(byte *)(param_1 + 6);
    *(undefined8 *)(param_2 + 5) = 0;
    *(undefined8 *)(param_2 + 1) = 0;
    param_2[9] = 0;
    *param_2 = 0x1214;
    param_2[1] = *(undefined2 *)(param_1 + 2);
    *(undefined1 *)(param_2 + 2) = *(undefined1 *)(param_1 + 4);
    if (0xc < bVar3) {
      return 0x37;
    }
    *(byte *)(param_2 + 3) = bVar3;
    puVar1 = param_2 + 4;
    if ((puVar1 <= (undefined2 *)((long)param_2 + 0xff)) && (param_2 <= puVar1)) {
      uVar2 = param_1 + *(byte *)(param_1 + 5) + 8;
      if ((uVar2 <= param_1 + 0xff) &&
         ((param_1 <= uVar2 && ((ulong)bVar3 <= 0xf7 - (ulong)*(byte *)(param_1 + 5))))) {
        FUN_fffffff00aa65b10(puVar1);
        return 0;
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a498274);
  (*pcVar4)();
}

