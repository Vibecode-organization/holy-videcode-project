// FUN_fffffff009186660 @ fffffff009186660 size=4 depth=0
// CALLERS:
//   fffffff00afdb26f ?
//   fffffff007ecbbe0 ?
// CALLS:

/* WARNING: Removing unreachable block (ram,0xfffffff00918677c) */

undefined8 FUN_fffffff009186660(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  long lVar2;
  long *plVar3;
  undefined1 in_q0 [16];
  undefined1 extraout_q0 [16];
  undefined1 in_q1 [16];
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 *puStack_50;
  undefined1 *puStack_48;
  long *plStack_40;
  
  puStack_50 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_48 = &DAT_aaaaaaaaaaaaaaaa;
  plStack_40 = (long *)&DAT_aaaaaaaaaaaaaaaa;
  plVar3 = *(long **)(*(long *)(param_1 + 0xd8) + 0xf0);
  if (plVar3 != (long *)0x0) {
    thunk_FUN_fffffff00aa64ec0((long *)&puStack_50,0x18,0,0x18);
    uVar1 = FUN_fffffff0091ad3b4(param_3,(long *)&puStack_50,(long *)0x0);
    if ((int)uVar1 == 0) {
      uVar1 = FUN_fffffff009175f48(plVar3,puStack_50,puStack_48);
    }
    puStack_50 = (undefined1 *)0x0;
    puStack_48 = (undefined1 *)0x0;
    if (plStack_40 != (long *)0x0) {
      (**(code **)(*plStack_40 + 0x28))();
      (**(code **)(**(long **)(param_3 + 0x68) + 0xe0))(*(long **)(param_3 + 0x68),0);
    }
    return uVar1;
  }
  lVar2 = FUN_fffffff0091ade6c(in_q0,in_q1,in_q2,in_q3,in_s4,in_s5);
  plVar3 = (long *)FUN_fffffff0091960c0
                             (extraout_q0,in_q1,in_q2,in_q3,in_s4,in_s5,*(long *)(lVar2 + 0xd8),
                              15000);
  if (plVar3 == (long *)0x0) {
    return 0xe00002c7;
  }
  uVar1 = FUN_fffffff00917e56c(plVar3,**(undefined4 **)(param_3 + 0x20));
  return uVar1;
}

