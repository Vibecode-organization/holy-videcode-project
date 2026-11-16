// FUN_fffffff009c2e168 @ fffffff009c2e168 size=180

void FUN_fffffff009c2e168(long param_1)

{
  code *pcVar1;
  undefined8 *puVar2;
  long lVar3;
  ulong unaff_x30;
  
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff00806b0f0);
  *(undefined8 **)(param_1 + 0x10) = puVar2;
  if (puVar2 == (undefined8 *)0x0) {
    return;
  }
  puVar2[0x27] = 0;
  puVar2[0x26] = 0;
  puVar2[0x29] = 0;
  puVar2[0x28] = 0;
  puVar2[0x23] = 0;
  puVar2[0x22] = 0;
  puVar2[0x25] = 0;
  puVar2[0x24] = 0;
  puVar2[0x1f] = 0;
  puVar2[0x1e] = 0;
  puVar2[0x21] = 0;
  puVar2[0x20] = 0;
  puVar2[0x1b] = 0;
  puVar2[0x1a] = 0;
  puVar2[0x1d] = 0;
  puVar2[0x1c] = 0;
  puVar2[0x17] = 0;
  puVar2[0x16] = 0;
  puVar2[0x19] = 0;
  puVar2[0x18] = 0;
  puVar2[0x13] = 0;
  puVar2[0x12] = 0;
  puVar2[0x15] = 0;
  puVar2[0x14] = 0;
  puVar2[0xf] = 0;
  puVar2[0xe] = 0;
  puVar2[0x11] = 0;
  puVar2[0x10] = 0;
  puVar2[0xb] = 0;
  puVar2[10] = 0;
  puVar2[0xd] = 0;
  puVar2[0xc] = 0;
  puVar2[7] = 0;
  puVar2[6] = 0;
  puVar2[9] = 0;
  puVar2[8] = 0;
  puVar2[3] = 0;
  puVar2[2] = 0;
  puVar2[5] = 0;
  puVar2[4] = 0;
  puVar2[1] = 0;
  *puVar2 = 0;
  lVar3 = *(long *)(param_1 + 0x10);
  *(undefined8 *)(lVar3 + 8) = 0x100000001;
  *(undefined8 *)(lVar3 + 0x38) = 0x100000001;
  *(undefined8 *)(lVar3 + 0x98) = 0x100000001;
  *(undefined8 *)(lVar3 + 0xf8) = 0x100000001;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2e204);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c2e20c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))(param_1);
  return;
}

