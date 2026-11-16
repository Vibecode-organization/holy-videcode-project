// FUN_fffffff009185030 @ fffffff009185030 size=104 depth=0
// CALLERS:
//   fffffff00afdb23b ?
//   fffffff007ecb820 ?
// CALLS:
//   fffffff009195eec FUN_fffffff009195eec

undefined8
FUN_fffffff009185030
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8,long param_9)

{
  code *pcVar1;
  undefined8 uVar2;
  long *plVar3;
  ulong unaff_x30;
  uint auStack_30 [2];
  long lStack_28;
  
  plVar3 = (long *)FUN_fffffff009195eec
                             (param_1,param_2,param_3,param_4,param_5,param_6,
                              *(long *)(param_7 + 0xd8),15000);
  if (plVar3 == (long *)0x0) {
    return 0xe00002ca;
  }
  auStack_30[0] = *(uint *)(param_9 + 0x38);
  lStack_28 = *(long *)(param_9 + 0x30);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009185080);
    (*pcVar1)();
  }
  if (lStack_28 != 0) {
    auStack_30[1] = 0;
    uVar2 = FUN_fffffff00917fb00(plVar3,&stack0xffffffffffffffe8,auStack_30);
    return uVar2;
  }
  return 0xe00002c2;
}

