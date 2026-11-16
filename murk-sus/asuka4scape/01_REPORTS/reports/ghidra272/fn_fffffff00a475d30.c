// FUN_fffffff00a475d30 @ fffffff00a475d30 size=252

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_fffffff00a475d30(undefined *param_1,ulong *param_2,undefined8 *param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  
  puVar1 = param_1 + 0xff;
  puVar2 = param_1 + (ulong)(byte)param_1[5] + 8;
  uVar7 = (ulong)(byte)param_1[6];
  if ((_DAT_fffffff00ad19ca8 != 0) &&
     ((param_1[4] == -0x70 || param_1[4] == '\x06') && param_3 != (undefined8 *)0x0)) {
    iVar4 = FUN_fffffff00aa310b8(*param_3,"net.link.addr");
    lVar6 = FUN_fffffff00a29b24c();
    if (*(long *)(lVar6 + 0x18) == 0) {
      iVar5 = FUN_fffffff00a57fd88(DAT_fffffff007c6b250);
    }
    else {
      iVar5 = FUN_fffffff00a57fd88();
    }
    if ((iVar5 == 0) || (iVar4 != 0)) {
      if (7 < uVar7) {
        uVar7 = 8;
      }
      puVar2 = &DAT_fffffff007020a58;
      puVar1 = &DAT_fffffff007020a60;
      param_1 = puVar2;
    }
  }
  if (param_2 != (ulong *)0x0) {
    *param_2 = uVar7;
  }
  if ((puVar2 != (undefined *)0x0) && (puVar1 <= puVar2 || puVar2 < param_1)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a475e2c);
    (*pcVar3)();
  }
  return puVar2;
}

