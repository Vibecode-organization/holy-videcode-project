// FUN_fffffff009c209b8 @ fffffff009c209b8 size=416
// CALLERS:
//   fffffff00afebd02 ?
//   fffffff007dde5b0 ?
//   fffffff007df1298 ?
//   fffffff009c3b4ec FUN_fffffff009c3b3ac@fffffff009c3b3ac
//   fffffff009c3cec0 FUN_fffffff009c3cd9c@fffffff009c3cd9c
//   fffffff008a81ce0 thunk_FUN_fffffff009c209b8@fffffff008a81cd4
//   fffffff008aefa10 thunk_FUN_fffffff009c209b8@fffffff008aefa04
// CALLS:
//   fffffff009c49d44 thunk_FUN_fffffff00a726ec0
//   fffffff009c49e74 thunk_FUN_fffffff00a2df760
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c206fc FUN_fffffff009c206fc
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c49c14 thunk_FUN_fffffff00a6de494
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8
//   fffffff009c20b58 FUN_fffffff009c20b58

/* WARNING: Removing unreachable block (ram,0xfffffff009c20ac0) */

undefined8
FUN_fffffff009c209b8
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8,
          uint *param_9,undefined8 param_10,undefined *param_11)

{
  uint uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined8 uVar4;
  int iVar5;
  long lVar6;
  undefined1 auVar7 [16];
  undefined1 extraout_q0 [16];
  undefined4 uVar8;
  undefined1 auVar9 [12];
  undefined4 uVar10;
  undefined1 auVar11 [12];
  long local_40;
  long local_38;
  
  uVar10 = param_4._0_4_;
  auVar11 = param_4._4_12_;
  uVar8 = param_3._0_4_;
  auVar9 = param_3._4_12_;
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  auVar7 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x50));
  if (((param_8 >> 1 & 1) == 0) || (*(long *)(param_7 + 0x38) == 0)) {
    if ((param_8 & 1) == 0) {
      iVar5 = *(int *)(param_7 + 0x23c);
      if (iVar5 == 0) {
        auVar7 = thunk_FUN_fffffff00a726ec0((undefined8 *)(param_7 + 0x2b0),0x40);
        iVar5 = *(int *)(param_7 + 0x23c);
      }
      *(int *)(param_7 + 0x23c) = iVar5 + 1;
    }
    else {
      iVar5 = *(int *)(param_7 + 0x238);
      if (iVar5 == 0) {
        auVar7 = thunk_FUN_fffffff00a726ec0((undefined8 *)(param_7 + 0x270),0x40);
        iVar5 = *(int *)(param_7 + 0x238);
      }
      *(int *)(param_7 + 0x238) = iVar5 + 1;
    }
    auVar2._4_12_ = auVar9;
    auVar2._0_4_ = uVar8;
    auVar3._4_12_ = auVar11;
    auVar3._0_4_ = uVar10;
    FUN_fffffff009c20b58
              (auVar7,param_2,auVar2,auVar3,param_5,param_6,param_7,0,0,(ulong)((param_8 & 1) == 0),
               param_11);
    if ((*(byte *)(param_7 + 0x3d0) >> 4 & 1) != 0) {
      FUN_fffffff009c206fc(extraout_q0,param_2,uVar8,uVar10,param_5,param_6,param_7);
      uVar1 = *(uint *)(param_7 + 0x3d0);
      *(uint *)(param_7 + 0x3d0) = uVar1 & 0xffffffef;
      if ((uVar1 >> 5 & 1) != 0) {
        *(uint *)(param_7 + 0x3d0) = uVar1 & 0xffffffcf;
      }
    }
    lVar6 = *(long *)(param_7 + 0x178);
    if ((param_8 & 1) == 0) {
      *(int *)(lVar6 + 0xc) = *(int *)(lVar6 + 0xc) + 1;
      *(uint *)(param_7 + 0x3d0) = *(uint *)(param_7 + 0x3d0) | 0xc;
    }
    uVar1 = *(uint *)(lVar6 + 0xc);
    if (param_9 != (uint *)0x0) {
      *param_9 = uVar1;
    }
    local_40 = 0;
    auVar7 = thunk_FUN_fffffff00a2df760(*(ulong *)(param_7 + 0x30),&local_40);
    thunk_FUN_fffffff00a6de494
              (auVar7,param_2,uVar8,uVar10,param_5,param_6,0x85210010,local_40,
               (ulong)*(uint *)(param_7 + 0x10),(ulong)param_8,(ulong)uVar1);
    thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x50));
    uVar4 = 0;
  }
  else {
    thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x50));
    uVar4 = 0xe00002cc;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar4;
}

