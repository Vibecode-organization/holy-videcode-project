// FUN_fffffff009c41a54 @ fffffff009c41a54 size=388

/* WARNING: Removing unreachable block (ram,0xfffffff009c41b7c) */

void FUN_fffffff009c41a54(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  long lVar4;
  ulong unaff_x30;
  
  puVar2 = *(undefined8 **)(param_1 + 0x28);
  while (puVar2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*puVar2;
    if ((long *)puVar2[1] != (long *)0x0) {
      (**(code **)(*(long *)puVar2[1] + 0x28))();
    }
    puVar2[1] = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b730,puVar2);
    puVar2 = puVar1;
  }
  puVar2 = *(undefined8 **)(param_1 + 0x30);
  while (puVar2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*puVar2;
    if ((long *)puVar2[1] != (long *)0x0) {
      (**(code **)(*(long *)puVar2[1] + 0x28))();
    }
    puVar2[1] = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b770,puVar2);
    puVar2 = puVar1;
  }
  puVar2 = *(undefined8 **)(param_1 + 0x38);
  while (puVar2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*puVar2;
    if ((long *)puVar2[1] != (long *)0x0) {
      (**(code **)(*(long *)puVar2[1] + 0x28))();
    }
    puVar2[1] = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b7b0,puVar2);
    puVar2 = puVar1;
  }
  lVar4 = *(long *)(param_1 + 0x10);
  if ((lVar4 != 0) && (lVar4 != 0)) {
    thunk_EXT_FUN_801100000326c730(lVar4);
    *(long *)(param_1 + 0x10) = 0;
  }
  if (*(long *)(param_1 + 0x18) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c41bd4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c41bcc);
  (*pcVar3)();
}

