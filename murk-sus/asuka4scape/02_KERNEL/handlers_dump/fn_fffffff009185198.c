// FUN_fffffff009185198 @ fffffff009185198 size=4 depth=0
// CALLERS:
//   fffffff00afdb23f ?
//   fffffff007ecb868 ?
// CALLS:

undefined8 FUN_fffffff009185198(long param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined1 in_q0 [16];
  undefined1 in_q1 [16];
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  uint uStack_24;
  
  uVar3 = 0xe00002c2;
  plVar1 = (long *)FUN_fffffff009195eec
                             (in_q0,in_q1,in_q2,in_q3,in_s4,in_s5,*(long *)(param_1 + 0xd8),15000);
  if (plVar1 == (long *)0x0) {
    uVar3 = 0xe00002ca;
  }
  else {
    puVar2 = *(undefined8 **)(param_3 + 0x20);
    if (0xfffffffffffffbff < puVar2[2] - 0x401) {
      uStack_24 = (uint)puVar2[2];
      if ((uStack_24 <= *(uint *)(param_3 + 0x38)) &&
         (uVar3 = FUN_fffffff0091801b8
                            (plVar1,(int)*puVar2,(int)puVar2[1],&uStack_24,*(long *)(param_3 + 0x30)
                            ), (int)uVar3 == 0)) {
        *(ulong *)(*(long *)(param_3 + 0x48) + 0x10) = (ulong)uStack_24;
      }
    }
  }
  return uVar3;
}

