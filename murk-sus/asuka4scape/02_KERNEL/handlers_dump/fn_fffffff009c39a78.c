// FUN_fffffff009c39a78 @ fffffff009c39a78 size=4 depth=0
// CALLERS:
//   fffffff00afec088 ?
//   fffffff0080692c0 ?
// CALLS:

undefined8 FUN_fffffff009c39a78(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  long *plVar2;
  ulong *puVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined1 in_q0 [16];
  undefined1 extraout_q0 [16];
  undefined1 in_q1 [16];
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  ulong uStack_58;
  uint uStack_4c;
  long lStack_48;
  
  lStack_48 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar4 = 0xe00002c2;
  pcVar5 = *(char **)(param_3 + 0x30);
  uVar1 = *(uint *)(param_3 + 0x38);
  uStack_4c = 0;
  uStack_58 = 0;
  plVar2 = *(long **)(param_3 + 0x40);
  if (plVar2 == (long *)0x0) {
    plVar2 = (long *)0x0;
  }
  else {
    plVar2 = (long *)(**(code **)(*plVar2 + 0xe8))(plVar2,0x1000);
    if (plVar2 == (long *)0x0) {
      uVar4 = 0xe00002c8;
      goto LAB_fffffff009c39ba4;
    }
    pcVar5 = (char *)(**(code **)(*plVar2 + 0x78))();
    uVar1 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
    in_q0 = extraout_q0;
  }
  if (pcVar5 != (char *)0x0 && uVar1 != 0) {
    uVar4 = FUN_fffffff009c3e384
                      (in_q0,in_q1,in_q2,in_q3,in_s4,in_s5,param_1,&uStack_4c,(long *)&uStack_58,
                       pcVar5,uVar1);
    puVar3 = *(ulong **)(param_3 + 0x48);
    *puVar3 = (ulong)uStack_4c;
    puVar3[1] = uStack_58;
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
LAB_fffffff009c39ba4:
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_48) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

