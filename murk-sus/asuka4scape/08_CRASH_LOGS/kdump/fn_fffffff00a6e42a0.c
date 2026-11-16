// FUN_fffffff00a6e42a0 @ fffffff00a6e42a0 size=400
// CALLERS:
//   fffffff00afbc4dd ?
//   fffffff00a6e3c8c FUN_fffffff00a6e3bd0@fffffff00a6e3bd0
//   fffffff00a6e3cf0 FUN_fffffff00a6e3bd0@fffffff00a6e3bd0
//   fffffff00a6e54d4 FUN_fffffff00a6e5270@fffffff00a6e5270
//   fffffff00a6e599c FUN_fffffff00a6e5270@fffffff00a6e5270
//   fffffff00a6e59d0 FUN_fffffff00a6e5270@fffffff00a6e5270
//   fffffff00a6e5b94 FUN_fffffff00a6e5a18@fffffff00a6e5a18
// CALLS:
//   fffffff00a6efc08 FUN_fffffff00a6efc08
//   fffffff00a6efe14 FUN_fffffff00a6efe14
//   fffffff00a6ff548 FUN_fffffff00a6ff548

ulong FUN_fffffff00a6e42a0
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                undefined8 param_8,long param_9,undefined ********param_10,
                undefined ********param_11,undefined2 param_12,long *param_13)

{
  uint uVar1;
  ulong uVar2;
  int *piVar3;
  int *local_a8;
  undefined ********local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  
  local_a8 = (int *)0x0;
  if (((uint)param_11 & 0xffef) != 0xffed) {
    return 0x16;
  }
  uVar1 = *(uint *)(param_9 + 4);
  uStack_60 = 0;
  uStack_78 = 0;
  local_80 = 0;
  local_68 = 0;
  uStack_70 = 0;
  uStack_98 = 0;
  local_a0 = (undefined ********)0x0;
  uStack_88 = 0;
  local_90 = 0;
  if (param_13 == (long *)0x0) {
    uVar2 = FUN_fffffff00a6efc08(param_7,uVar1,5,9,&local_a8);
    piVar3 = local_a8;
    if ((int)uVar2 != 0) goto LAB_fffffff00a6e4380;
    param_13 = *(long **)(*(long *)(local_a8 + 4) + 0x38);
    if (param_13 == (long *)0x0) {
      param_13 = (long *)0x0;
    }
  }
  piVar3 = local_a8;
  uStack_60 = 0;
  uStack_70 = 0;
  uStack_78 = 0;
  local_80 = 0;
  uStack_88 = 0;
  uStack_98 = (ulong)CONCAT22(param_12,(short)param_11);
  local_90 = *(undefined8 *)(param_9 + 8);
  local_a0 = param_10;
  local_68 = param_8;
  uVar2 = FUN_fffffff00a6ff548
                    (ZEXT816(0),param_2,param_3,param_4,param_5,param_6,param_13,(ulong *)&local_a0,
                     (undefined8 *)0x0,param_10,param_11);
  if ((uStack_98._2_2_ >> 0xe & 1) != 0) {
    uVar2 = local_80 & 0xffffffff;
  }
LAB_fffffff00a6e4380:
  if (piVar3 != (int *)0x0) {
    FUN_fffffff00a6efe14(param_7,uVar1,piVar3,0);
  }
  return uVar2;
}

