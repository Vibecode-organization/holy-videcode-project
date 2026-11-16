// FUN_fffffff009cadb40 @ fffffff009cadb40

/* WARNING: Removing unreachable block (ram,0xfffffff009cadbdc) */

undefined8
FUN_fffffff009cadb40
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,long param_8,
          undefined8 param_9)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  ulong local_38;
  
  if (((param_8 != 0) && (param_8 != 3)) &&
     (uVar2 = (**(code **)(*(long *)param_7[0x17] + 0x2d0))((long *)param_7[0x17],param_7),
     param_1 = extraout_q0, (uVar2 & 1) == 0)) {
    local_38 = 0;
    thunk_FUN_fffffff00a208ed8(10,1000000000,(long *)&local_38);
    lVar3 = *(long *)param_7[0x17];
    uVar2 = (**(code **)(lVar3 + 0x2c0))(lVar3 + 0x2c0,(long *)param_7[0x17],param_7,0,0);
    if ((uVar2 & 1) == 0) {
      do {
        uVar2 = thunk_FUN_fffffff00a39bc88();
        if (local_38 <= uVar2) break;
        thunk_FUN_fffffff00a902978(extraout_q0_00,param_2,param_3,param_4,param_5,param_6,100,100);
        iVar1 = (**(code **)(*(long *)param_7[0x17] + 0x2c0))((long *)param_7[0x17],param_7,0,0);
      } while (iVar1 == 0);
    }
    iVar1 = (**(code **)(*(long *)param_7[0x17] + 0x2d0))((long *)param_7[0x17],param_7);
    param_1 = extraout_q0_01;
    if (iVar1 == 0) {
      (**(code **)(*param_7 + 0x6c8))(param_7,0x1000000,&DAT_fffffff0078bd710);
      return 0;
    }
  }
  (**(code **)(PTR_DAT_fffffff0080813a8 + 0x4e8))(param_1,param_7,param_8,param_9);
  if ((param_8 == 0) &&
     (iVar1 = (**(code **)(*(long *)param_7[0x17] + 0x2d0))((long *)param_7[0x17],param_7),
     iVar1 != 0)) {
    (**(code **)(*(long *)param_7[0x17] + 0x2c8))((long *)param_7[0x17],param_7,0);
  }
  return 0;
}

