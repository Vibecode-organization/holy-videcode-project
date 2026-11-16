// FUN_fffffff009184e04 @ fffffff009184e04 size=4 depth=0
// CALLERS:
//   fffffff00afdb236 ?
//   fffffff007ecb7d8 ?
// CALLS:

undefined8 FUN_fffffff009184e04(long param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  undefined8 uVar2;
  undefined1 in_q0 [16];
  undefined1 in_q1 [16];
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  long lStack_48;
  uint *puStack_40;
  long *plStack_38;
  
  plVar1 = (long *)FUN_fffffff0091960c0
                             (in_q0,in_q1,in_q2,in_q3,in_s4,in_s5,*(long *)(param_1 + 0xd8),15000);
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c7;
  }
  else {
    lStack_48 = 0;
    puStack_40 = (uint *)0x0;
    plStack_38 = (long *)0x0;
    uVar2 = FUN_fffffff0091ad3b4(param_3,&lStack_48,(long *)0x0);
    if ((int)uVar2 == 0) {
      uVar2 = FUN_fffffff00917e1c4
                        (plVar1,**(undefined4 **)(param_3 + 0x20),lStack_48,(ulong)*puStack_40,
                         puStack_40,0);
      if (plStack_38 != (long *)0x0) {
        (**(code **)(*plStack_38 + 0x28))();
        (**(code **)(**(long **)(param_3 + 0x68) + 0xe0))(*(long **)(param_3 + 0x68),0);
      }
    }
  }
  return uVar2;
}

