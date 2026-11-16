// FUN_fffffff009c720e8 @ fffffff009c720e8

void FUN_fffffff009c720e8
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,undefined8 param_9,char *param_10,undefined *param_11)

{
  undefined *puVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  code *pcVar4;
  long *plVar5;
  undefined **ppuVar6;
  undefined *puVar7;
  ulong uVar8;
  ulong unaff_x30;
  
  if (*(long *)(param_7 + 0xb8) != 0) {
    param_10 = "Packet pool being freed but has %llu outstanding packets";
    param_1 = thunk_FUN_fffffff00a8df19c
                        (param_1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                         (short *)PTR_DAT_fffffff00807b638,0x10,
                         (byte *)"Packet pool being freed but has %llu outstanding packets");
  }
  if (*(char *)(param_7 + 0x40) != '\0') {
    uVar8 = 0;
    do {
      plVar5 = *(long **)(param_7 + 0x90 + uVar8 * 8);
      if (plVar5 != (long *)0x0) {
        param_1 = (**(code **)(*plVar5 + 0x28))();
      }
      *(undefined8 *)(param_7 + 0x90 + uVar8 * 8) = 0;
      plVar5 = *(long **)(param_7 + 0x68 + uVar8 * 8);
      if (plVar5 != (long *)0x0) {
        param_1 = (**(code **)(*plVar5 + 0x28))();
      }
      *(undefined8 *)(param_7 + 0x68 + uVar8 * 8) = 0;
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(byte *)(param_7 + 0x40));
  }
  if (*(long **)(param_7 + 0xb0) != (long *)0x0) {
    param_1 = (**(code **)(**(long **)(param_7 + 0xb0) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0xb0) = 0;
  if (*(long **)(param_7 + 0x88) != (long *)0x0) {
    param_1 = (**(code **)(**(long **)(param_7 + 0x88) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0x88) = 0;
  ppuVar6 = *(undefined ***)(param_7 + 0x10);
  if (ppuVar6 != (undefined **)0x0) {
    auVar2._8_8_ = 0;
    auVar2._0_8_ = *(ulong *)(param_7 + 0x30);
    puVar7 = (undefined *)(*(ulong *)(param_7 + 0x30) * 0x18);
    puVar1 = (undefined *)0x8000000000000000;
    if (SUB168(auVar2 * ZEXT816(0x18),8) == 0 && -1 < (long)puVar7) {
      puVar1 = puVar7;
    }
    *(undefined8 *)(param_7 + 0x10) = 0;
    param_1 = thunk_FUN_fffffff00a902768
                        (param_1,param_2,param_3,param_4,param_5,param_6,0xfffffff00807b100,ppuVar6,
                         puVar1,param_10,param_11);
    *(undefined8 *)(param_7 + 0x10) = 0;
  }
  ppuVar6 = *(undefined ***)(param_7 + 0x38);
  if (ppuVar6 != (undefined **)0x0) {
    auVar3._8_8_ = 0;
    auVar3._0_8_ = *(ulong *)(param_7 + 0x30);
    puVar7 = (undefined *)(*(ulong *)(param_7 + 0x30) * 0x30);
    puVar1 = (undefined *)0x8000000000000000;
    if (SUB168(auVar3 * ZEXT816(0x30),8) == 0 && -1 < (long)puVar7) {
      puVar1 = puVar7;
    }
    *(undefined8 *)(param_7 + 0x38) = 0;
    thunk_FUN_fffffff00a902768
              (param_1,param_2,param_3,param_4,param_5,param_6,0xfffffff00807b150,ppuVar6,puVar1,
               param_10,param_11);
    *(undefined8 *)(param_7 + 0x38) = 0;
  }
  if (*(undefined8 **)(param_7 + 0x28) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x28));
    *(undefined8 *)(param_7 + 0x28) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c722c4);
    (*pcVar4)();
  }
  (**(code **)(PTR_DAT_fffffff00807b620 + 0x80))(param_7);
  return;
}

