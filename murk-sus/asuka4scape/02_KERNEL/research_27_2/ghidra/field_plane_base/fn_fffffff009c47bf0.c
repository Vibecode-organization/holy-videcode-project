// FUN_fffffff009c47bf0 @ fffffff009c47bf0

/* WARNING: Removing unreachable block (ram,0xfffffff009c47c38) */

void FUN_fffffff009c47bf0
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,ulong param_9,undefined8 param_10,undefined8 param_11,
               undefined8 param_12,ulong param_13)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  
  if ((*(long *)(param_7 + 0x18) != 0) && ((*(byte *)(param_7 + 0x21) & 1) != 0)) {
    thunk_FUN_fffffff00a89460c((int *)(*(long *)(*(long *)(param_7 + 0x18) + 0x178) + 0x24));
    lVar2 = FUN_fffffff009c22264(*(long *)(param_7 + 0x18));
    param_8 = extraout_x1;
    param_1 = extraout_q0;
    if (lVar2 != 0) {
      plVar3 = (long *)FUN_fffffff009c22264(*(long *)(param_7 + 0x18));
      param_1 = (**(code **)(*plVar3 + 0xe0))(plVar3,0);
      param_8 = extraout_x1_00;
    }
    *(undefined1 *)(param_7 + 0x21) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    FUN_fffffff009c47644
              (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c47c98);
  (*pcVar1)();
}

