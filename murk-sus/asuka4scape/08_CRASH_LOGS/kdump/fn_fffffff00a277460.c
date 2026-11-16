// FUN_fffffff00a277460 @ fffffff00a277460 size=216
// CALLERS:
//   fffffff00afb8cfc ?
//   fffffff00a717454 FUN_fffffff00a7166ec@fffffff00a7166ec
//   fffffff00a2b54ac FUN_fffffff00a2b5440@fffffff00a2b5440
// CALLS:
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a273d34 FUN_fffffff00a273d34

undefined4
FUN_fffffff00a277460
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,int param_8,
          undefined **param_9,uint *param_10,ulong param_11)

{
  uint uVar1;
  long lVar2;
  undefined4 uVar3;
  uint in_wzr;
  
  if (param_7 == (long *)0x0) {
    return 4;
  }
  lVar2 = tpidr_el1;
  if (param_7[0x87] == 0) {
    param_7[0x87] = (ulong)*(uint *)(lVar2 + 0x4e8);
  }
  else {
    param_1 = FUN_fffffff00a2262d4((ulong)(param_7 + 0x86),lVar2,(undefined **)0x0);
  }
  if ((*(byte *)((long)param_7 + 0x42b) & 0x11) == 0) {
    uVar3 = 0x25;
  }
  else {
    uVar3 = FUN_fffffff00a273d34
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11);
  }
  uVar1 = *(uint *)(param_7 + 0x87);
  if (uVar1 == *(uint *)(lVar2 + 0x4e8)) {
    *(uint *)(param_7 + 0x87) = in_wzr;
  }
  else {
    FUN_fffffff00a226e08((ulong)(param_7 + 0x86),lVar2,uVar1);
  }
  return uVar3;
}

