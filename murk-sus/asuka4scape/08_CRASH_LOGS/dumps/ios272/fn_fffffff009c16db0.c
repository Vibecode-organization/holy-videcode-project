// FUN_fffffff009c16db0 @ fffffff009c16db0 size=328

/* WARNING: Removing unreachable block (ram,0xfffffff009c16e04) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c16e38) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c16e70) */

void FUN_fffffff009c16db0(long param_1,ulong param_2,undefined8 param_3)

{
  bool bVar1;
  undefined8 *puVar2;
  code *pcVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  puVar2 = (undefined8 *)(param_1 + 0x20);
  if ((*(byte *)(param_1 + 0x50) & 1) == 0) {
    do {
      uVar4 = *(ulong *)*puVar2;
      bVar1 = param_2 > uVar4;
      if (param_2 <= uVar4) goto LAB_fffffff009c16e7c;
    } while (*(ulong *)*puVar2 != uVar4);
    *(ulong *)*puVar2 = param_2;
  }
  else {
    *(ulong *)*puVar2 = param_2;
    bVar1 = true;
  }
LAB_fffffff009c16e7c:
  if (param_2 != 0xffffffffffffffff) {
    thunk_EXT_FUN_80110000036da494(0x85210028,*(undefined8 *)(param_1 + 0x28),param_2,0,0,0);
  }
  FUN_fffffff009c16f04(param_1,param_2);
  if (!bVar1) {
    return;
  }
  FUN_fffffff009c37bb0(*(undefined8 *)(param_1 + 0x10),param_3);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    FUN_fffffff009c16fa0(param_1,param_3);
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c16ee4);
  (*pcVar3)();
}

