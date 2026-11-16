// FUN_fffffff009c2a3d0 @ fffffff009c2a3d0 size=188
// CALLERS:
//   fffffff00afebe12 no-fn
//   fffffff007ff2498 no-fn
//   fffffff008022058 no-fn
//   fffffff00802a180 no-fn
//   fffffff009984aa8 thunk_FUN_fffffff009c2a3d0@fffffff009984a9c
//   fffffff009a9a64c thunk_FUN_fffffff009c2a3d0@fffffff009a9a640
//   fffffff009abd838 thunk_FUN_fffffff009c2a3d0@fffffff009abd82c
// CALLEES:
//   fffffff009c49954 thunk_FUN_fffffff00a97baa8
//   fffffff009c49c14 thunk_FUN_fffffff00a6de494
//   fffffff009c21f78 FUN_fffffff009c21f78

void FUN_fffffff009c2a3d0
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7,long *param_8)

{
  uint uVar1;
  code *pcVar2;
  long *plVar3;
  ulong uVar4;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar5 [16];
  
  plVar3 = *(long **)(param_7 + 0x30);
  if ((plVar3 != (long *)0x0) && ((*(uint *)(param_7 + 0x3d0) >> 10 & 1) != 0)) {
    *(uint *)(param_7 + 0x3d0) = *(uint *)(param_7 + 0x3d0) & 0xfffffbff;
    (**(code **)(*plVar3 + 0xe0))(plVar3,0);
  }
  FUN_fffffff009c21f78((long *)(param_7 + 0x30),param_8);
  uVar1 = *(uint *)(param_7 + 0x10);
  if (*(long *)(param_7 + 0x30) == 0) {
    uVar4 = 0;
    auVar5 = extraout_q0;
  }
  else {
    uVar4 = thunk_FUN_fffffff00a97baa8(*(long *)(param_7 + 0x30));
    auVar5 = extraout_q0_00;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2a488);
    (*pcVar2)();
  }
  thunk_FUN_fffffff00a6de494
            (auVar5,param_2,param_3,param_4,param_5,param_6,0x540000c,(ulong)uVar1,uVar4,0,0);
  return;
}

