// FUN_fffffff00a7e0f00 @ fffffff00a7e0f00 size=280
// CALLERS:
//   fffffff00afbd59e ?
//   fffffff00a2ca758 FUN_fffffff00a2ca68c@fffffff00a2ca68c
//   fffffff00a2c6d7c FUN_fffffff00a2c6950@fffffff00a2c6950
//   fffffff00a2c7c40 FUN_fffffff00a2c7710@fffffff00a2c7710
// CALLS:
//   fffffff00a7d9438 FUN_fffffff00a7d9438
//   fffffff00a31b1b8 FUN_fffffff00a31b1b8
//   fffffff00a7d9d38 FUN_fffffff00a7d9d38
//   fffffff00aa4d114 FUN_fffffff00aa4d114

int FUN_fffffff00a7e0f00
              (undefined8 *param_1,undefined4 *****param_2,undefined8 *param_3,int param_4,
              ulong param_5,undefined4 ****param_6)

{
  uint uVar1;
  ulong uVar2;
  undefined1 extraout_q0 [16];
  undefined1 in_q1 [16];
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  uint local_64;
  ulong local_60;
  uint local_54;
  undefined4 *****local_50;
  int local_44;
  
  local_44 = 0;
  uVar1 = param_4 * 0x4000;
  local_50 = (undefined4 *****)0x0;
  local_54 = 0;
  local_60 = 0x440;
  if ((param_5 & 1) == 0) {
    local_60 = 0x441;
  }
  local_64 = uVar1;
  uVar2 = FUN_fffffff00a31b1b8
                    (DAT_fffffff007c678d8,param_3,(undefined **)&local_64,(undefined **)&local_50,
                     (uint *)0x0,&local_54,&local_60,1);
  if ((int)uVar2 == 0 && local_64 == uVar1) {
    if ((param_5 & 1) == 0) {
      local_50[10] = param_6;
      FUN_fffffff00a7d9438
                (param_1,local_50,(undefined4 *****)0x0,param_2,(undefined4 *****)(ulong)uVar1,
                 (uint)(param_6 == (undefined4 ****)0x0),&local_44);
    }
    else {
      FUN_fffffff00a7d9d38
                (param_1,(undefined4 *)local_50,(undefined4 **)0x0,(undefined4 **)param_2,
                 (undefined4 **)(ulong)uVar1,(ulong)(param_6 == (undefined4 ****)0x0 | 0x200),
                 &local_44);
    }
    return local_44;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4d114
            (extraout_q0,in_q1,in_q2,in_q3,in_s4,in_s5,
             (byte *)"vm_map_create_upl failed with %d @%s:%d");
}

