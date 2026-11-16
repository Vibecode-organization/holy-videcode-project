// FUN_fffffff009c21f08 @ fffffff009c21f08 size=112
// CALLERS:
//   fffffff00afebd14 no-fn
//   fffffff009c1ec08 FUN_fffffff009c1e624@fffffff009c1e624
//   fffffff009c1eedc FUN_fffffff009c1e624@fffffff009c1e624
//   fffffff009c1efa8 FUN_fffffff009c1e624@fffffff009c1e624
//   fffffff009c1f044 FUN_fffffff009c1e624@fffffff009c1e624
//   fffffff009c1f114 FUN_fffffff009c1e624@fffffff009c1e624
// CALLEES:
//   fffffff009c49c14 thunk_FUN_fffffff00a6de494
//   fffffff009c49954 thunk_FUN_fffffff00a97baa8
//   fffffff009c21f78 FUN_fffffff009c21f78

void FUN_fffffff009c21f08
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7,long *param_8)

{
  uint uVar1;
  code *pcVar2;
  ulong uVar3;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar4 [16];
  
  FUN_fffffff009c21f78((long *)(param_7 + 0x30),param_8);
  uVar1 = *(uint *)(param_7 + 0x10);
  if (*(long *)(param_7 + 0x30) == 0) {
    uVar3 = 0;
    auVar4 = extraout_q0;
  }
  else {
    uVar3 = thunk_FUN_fffffff00a97baa8(*(long *)(param_7 + 0x30));
    auVar4 = extraout_q0_00;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c21f74);
    (*pcVar2)();
  }
  thunk_FUN_fffffff00a6de494
            (auVar4,param_2,param_3,param_4,param_5,param_6,0x540000c,(ulong)uVar1,uVar3,0,0);
  return;
}

