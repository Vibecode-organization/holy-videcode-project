// FUN_fffffff009c2a48c @ fffffff009c2a48c size=280
// CALLERS:
//   fffffff00afebe13 no-fn
//   fffffff008022018 no-fn
//   fffffff00802a138 no-fn
//   fffffff009a9a5cc thunk_FUN_fffffff009c2a48c@fffffff009a9a5c0
//   fffffff009abd7a8 thunk_FUN_fffffff009c2a48c@fffffff009abd79c
// CALLEES:
//   fffffff009c49564 thunk_FUN_fffffff00a9026b0
//   fffffff009c49c14 thunk_FUN_fffffff00a6de494

void FUN_fffffff009c2a48c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puVar5;
  ulong unaff_x30;
  undefined1 auVar6 [16];
  
  plVar2 = *(long **)(param_7 + 0x30);
  if (plVar2 != (long *)0x0) {
    param_1 = (**(code **)(*plVar2 + 0x50))(plVar2,*(undefined8 *)PTR_PTR_fffffff00806c9c0);
  }
  *(undefined8 *)(param_7 + 0x30) = 0;
  uVar3 = 0;
  uVar4 = 0;
  puVar5 = (undefined *)0x0;
  auVar6 = thunk_FUN_fffffff00a6de494
                     (param_1,param_2,param_3,param_4,param_5,param_6,0x540000c,
                      (ulong)*(uint *)(param_7 + 0x10),0,0,0);
  if (*(undefined ***)(param_7 + 0x308) != (undefined **)0x0) {
    auVar6 = thunk_FUN_fffffff00a9026b0
                       (auVar6,param_2,param_3,param_4,param_5,param_6,
                        *(undefined ***)(param_7 + 0x308),
                        (undefined *)((ulong)*(uint *)(param_7 + 0x98) * 0x3c),uVar3,uVar4,puVar5);
    *(undefined8 *)(param_7 + 0x308) = 0;
    *(undefined4 *)(param_7 + 0x310) = 0;
    *(undefined4 *)(param_7 + 0x3b8) = 0;
  }
  *(undefined8 *)(param_7 + 0x180) = 0;
  *(undefined4 *)(param_7 + 0x188) = 0;
  *(undefined4 *)(param_7 + 0x98) = 0;
  *(undefined8 *)(param_7 + 0x58) = 0;
  *(undefined8 *)(param_7 + 0x60) = 0;
  *(undefined8 *)(param_7 + 0x68) = 0;
  *(undefined8 *)(param_7 + 0x90) = 0;
  auVar6 = thunk_FUN_fffffff00a6de494
                     (auVar6,param_2,param_3,param_4,param_5,param_6,0x5400010,
                      (ulong)*(uint *)(param_7 + 0x10),(ulong)*(uint *)(param_7 + 0x80),0,
                      (ulong)(*(uint *)(param_7 + 0x3d0) >> 9) & 1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2a5a0);
    (*pcVar1)();
  }
  thunk_FUN_fffffff00a6de494
            (auVar6,param_2,param_3,param_4,param_5,param_6,0x5400014,
             (ulong)*(uint *)(param_7 + 0x10),*(ulong *)(param_7 + 0x58),*(long *)(param_7 + 0x60),
             (long)(int)((uint)*(byte *)(param_7 + 0x72) << 0x18) |
             (ulong)*(byte *)(param_7 + 0x73) << 0x10 | (ulong)*(ushort *)(param_7 + 0x70));
  return;
}

