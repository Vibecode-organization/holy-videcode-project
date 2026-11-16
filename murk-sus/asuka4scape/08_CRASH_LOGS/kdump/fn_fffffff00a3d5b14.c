// FUN_fffffff00a3d5b14 @ fffffff00a3d5b14 size=532
// CALLERS:
//   fffffff00afba14a ?
//   fffffff00a3d507c FUN_fffffff00a3d4f98@fffffff00a3d4f98
//   fffffff00a3d50c4 FUN_fffffff00a3d4f98@fffffff00a3d4f98
//   fffffff00a3d61bc FUN_fffffff00a3d5d28@fffffff00a3d5d28
//   fffffff00a3d66b8 FUN_fffffff00a3d6418@fffffff00a3d6418
//   fffffff00a3d9cec FUN_fffffff00a3d9c1c@fffffff00a3d9c1c
//   fffffff00a3d9d14 FUN_fffffff00a3d9c1c@fffffff00a3d9c1c
//   fffffff00a3db410 FUN_fffffff00a3db070@fffffff00a3db070
//   fffffff00a3dc870 FUN_fffffff00a3dc38c@fffffff00a3dc38c
// CALLS:
//   fffffff00a31b1b8 FUN_fffffff00a31b1b8
//   fffffff00a73e538 FUN_fffffff00a73e538

undefined4
FUN_fffffff00a3d5b14(long param_1,long *param_2,undefined4 *param_3,int *param_4,ulong param_5)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  int local_54;
  undefined *puStack_50;
  ulong local_48;
  
  FUN_fffffff00a73e538(param_2,0);
  if ((param_2 != (long *)0x0) && (0 < *(int *)((long)param_2 + 0x14))) {
    uVar6 = param_2[5];
    if (*(ulong *)(*param_2 + 8) < uVar6) {
      uVar6 = *(ulong *)(*param_2 + 8);
    }
    if (uVar6 != 0) {
      uVar4 = uVar6;
      if (0x1fffffff < uVar6) {
        uVar4 = 0x20000000;
      }
      local_54 = (int)uVar4;
      if ((1 << (ulong)(*(uint *)(param_2 + 4) & 0x1f) & 0x121U) == 0) {
        uVar4 = DAT_fffffff007c678d8;
        if (DAT_fffffff007c678d8 == 0) goto LAB_fffffff00a3d5ca8;
LAB_fffffff00a3d5c1c:
        local_48 = 0x80;
        uVar4 = FUN_fffffff00a31b1b8
                          (uVar4,(undefined8 *)
                                 (*(ulong *)*param_2 &
                                 ((ulong)(uint)(-1 << (ulong)(*(byte *)(uVar4 + 0x2c) & 0x1f)) |
                                 0xffffffff00000000)),(undefined **)&local_54,&puStack_50,
                           (uint *)0x0,(uint *)0x0,&local_48,0x14);
        uVar3 = 0;
        if ((int)uVar4 != 0) {
          uVar3 = 0xe;
        }
        bVar1 = (local_48 & 3) != 0;
      }
      else {
        lVar5 = tpidr_el1;
        uVar4 = *(ulong *)(lVar5 + 0x418);
        if ((uVar4 != 0) && (uVar4 != 0)) goto LAB_fffffff00a3d5c1c;
LAB_fffffff00a3d5ca8:
        bVar1 = false;
        uVar3 = 0xe;
      }
      uVar2 = 0xe;
      if (local_54 != 0) {
        uVar2 = uVar3;
      }
      *param_4 = local_54;
      uVar3 = 3;
      if (((*(uint *)(*(long *)(param_1 + 0xd8) + 0x91c) < 0x4001) && (!bVar1)) &&
         ((param_5 & 0xffffffff) <= uVar6)) {
        *param_3 = 1;
        lVar5 = tpidr_el1;
        lVar5 = *(long *)(lVar5 + 0x418);
        if (lVar5 == 0) {
          return uVar2;
        }
        if (lVar5 == 0) {
          return uVar2;
        }
        if (0xd < *(byte *)(lVar5 + 0x2c)) {
          return uVar2;
        }
        uVar3 = 3;
      }
      goto LAB_fffffff00a3d5c80;
    }
  }
  uVar3 = 0;
  uVar2 = 0;
  *param_4 = 0;
LAB_fffffff00a3d5c80:
  *param_3 = uVar3;
  return uVar2;
}

