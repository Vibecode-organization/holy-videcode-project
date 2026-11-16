// FUN_fffffff00aa0ee74 @ fffffff00aa0ee74 size=232 depth=1
// CALLERS:
//   fffffff00afbfda5 ?
//   fffffff00a9e0550 FUN_fffffff00a9dfff0
//   fffffff00aa0ef10 FUN_fffffff00aa0ee74
// CALLS:
//   fffffff00a94a67c FUN_fffffff00a94a67c
//   fffffff00a9f12d4 FUN_fffffff00a9f12d4

bool FUN_fffffff00aa0ee74
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               undefined8 param_8,undefined8 param_9)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  undefined8 extraout_x1;
  undefined1 extraout_q0 [16];
  
  uVar3 = (**(code **)(*DAT_fffffff00add78a0 + 0x98))();
  if ((uVar3 & 1) == 0) {
    iVar2 = (**(code **)(*DAT_fffffff00add78a0 + 0x100))
                      ((undefined8 *)(*DAT_fffffff00add78a0 + 0x100),DAT_fffffff00add78a0,
                       FUN_fffffff00aa0ee74,param_7,0,0,0,0);
    bVar1 = iVar2 != 0;
  }
  else {
    iVar2 = (int)param_7[0x42];
    if ((iVar2 == 0 || iVar2 == 0x69) && ((*(byte *)((long)param_7 + 0x18c) & 1) != 0)) {
      FUN_fffffff00a94a67c
                (extraout_q0,param_2,param_3,param_4,param_5,param_6,param_7,extraout_x1,param_9);
      bVar1 = true;
    }
    else {
      if (iVar2 == 0x69) {
        FUN_fffffff00a9f12d4();
      }
      bVar1 = false;
    }
  }
  return bVar1;
}

