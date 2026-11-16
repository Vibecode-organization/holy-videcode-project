// FUN_fffffff00932c630 @ fffffff00932c630 size=4 depth=0
// CALLERS:
//   fffffff00afde566 ?
//   fffffff007f19d48 ?
// CALLS:

ulong FUN_fffffff00932c630(long *param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  undefined *in_x4;
  ulong uVar5;
  uint *puVar6;
  undefined1 extraout_q0 [16];
  undefined1 auVar7 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 in_q1 [16];
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  uint uStack_54;
  long *plStack_50;
  long *plStack_48;
  
  uVar5 = 0xe00002bd;
  plVar2 = thunk_FUN_fffffff00a894f30(param_1,(long)PTR_DAT_fffffff007f190d8);
  if (plVar2 == (long *)0x0) {
    return 0xe00002c2;
  }
  plStack_50 = (long *)0x0;
  plStack_48 = (long *)0x0;
  uStack_54 = 0;
  if (*(long **)(param_3 + 0x40) == (long *)0x0) {
    auVar7 = extraout_q0;
    plVar3 = plStack_48;
    if ((*(uint *)(param_3 + 0x38) != 0) &&
       (plVar3 = thunk_FUN_fffffff00a966e00
                           (*(undefined8 *)(param_3 + 0x30),(ulong)*(uint *)(param_3 + 0x38),2,0),
       auVar7 = extraout_q0_00, plVar3 == (long *)0x0)) goto LAB_fffffff00932c718;
  }
  else {
    auVar7 = (**(code **)(**(long **)(param_3 + 0x40) + 0x20))();
    plVar3 = *(long **)(param_3 + 0x40);
  }
  plStack_48 = plVar3;
  if (*(long **)(param_3 + 0x68) == (long *)0x0) {
    puVar6 = (uint *)(param_3 + 0x60);
    if (*puVar6 == 0) goto LAB_fffffff00932c6dc;
    plVar3 = thunk_FUN_fffffff00a966d2c((ulong)*puVar6,1,0);
    if (plVar3 == (long *)0x0) goto LAB_fffffff00932c718;
    plVar4 = (long *)(**(code **)(*plVar3 + 0x148))();
    thunk_FUN_fffffff00aa64ec0(plVar4,(ulong)*puVar6,0,(ulong)*puVar6);
    uStack_54 = *puVar6;
    plStack_50 = plVar3;
    uVar1 = FUN_fffffff00932b5e0
                      (extraout_q0_01,in_q1,in_q2,in_q3,in_s4,in_s5,plVar2,(long *)&plStack_48,
                       (long *)&plStack_50,&uStack_54,in_x4);
    uVar5 = (ulong)uVar1;
    if (*puVar6 != 0) {
      if (*(long *)(param_3 + 0x58) != 0) {
        (**(code **)(*plStack_50 + 200))(plStack_50,0);
      }
      goto LAB_fffffff00932c700;
    }
  }
  else {
    auVar7 = (**(code **)(**(long **)(param_3 + 0x68) + 0x20))();
    plStack_50 = *(long **)(param_3 + 0x68);
    uStack_54 = *(uint *)(param_3 + 0x70);
LAB_fffffff00932c6dc:
    uVar1 = FUN_fffffff00932b5e0
                      (auVar7,in_q1,in_q2,in_q3,in_s4,in_s5,plVar2,(long *)&plStack_48,
                       (long *)&plStack_50,&uStack_54,in_x4);
    uVar5 = (ulong)uVar1;
    if (*(int *)(param_3 + 0x60) != 0) {
LAB_fffffff00932c700:
      *(uint *)(param_3 + 0x60) = uStack_54;
    }
  }
  if (*(int *)(param_3 + 0x70) != 0) {
    *(uint *)(param_3 + 0x70) = uStack_54;
  }
LAB_fffffff00932c718:
  plVar2 = plStack_50;
  plStack_50 = (long *)0x0;
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))();
  }
  plVar2 = plStack_48;
  plStack_48 = (long *)0x0;
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))();
  }
  return uVar5;
}

