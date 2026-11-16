// FUN_fffffff0099484d0 @ fffffff0099484d0 size=152
// CALLERS:
// CALLEES:
//   fffffff009984f2c thunk_FUN_fffffff00a275d1c
//   fffffff0099676d4 FUN_fffffff0099676d4

undefined8
FUN_fffffff0099484d0
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8,long param_9)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  uint *puVar6;
  undefined1 extraout_q0 [16];
  uint local_44;
  
  puVar6 = *(uint **)(param_9 + 0x20);
  uVar3 = *puVar6;
  uVar1 = *(ulong *)(puVar6 + 2);
  uVar2 = *(ulong *)(puVar6 + 4);
  local_44 = 0;
  lVar4 = thunk_FUN_fffffff00a275d1c
                    (*(long *)(*(long *)(*(long *)(param_7 + 0x120) + 0x48) + 0x2e0));
  uVar5 = FUN_fffffff0099676d4
                    (extraout_q0,param_2,param_3,param_4,param_5,param_6,*(long *)(param_7 + 0x120),
                     uVar3,uVar1,uVar2,&local_44);
  if ((int)uVar5 == 0) {
    **(ulong **)(param_9 + 0x48) = (ulong)local_44;
  }
  thunk_FUN_fffffff00a275d1c(lVar4);
  return uVar5;
}

