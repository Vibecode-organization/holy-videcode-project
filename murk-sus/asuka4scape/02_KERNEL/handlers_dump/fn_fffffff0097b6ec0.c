// FUN_fffffff0097b6ec0 @ fffffff0097b6ec0 size=4 depth=0
// CALLERS:
//   fffffff00afe2a86 ?
//   fffffff007f95070 ?
// CALLS:

undefined8
FUN_fffffff0097b6ec0
          (long param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,undefined8 param_7)

{
  uint uVar1;
  short *psVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined ******ppppppuVar6;
  long *plVar7;
  long *plVar8;
  long lVar9;
  long extraout_x16;
  long extraout_x16_00;
  long extraout_x16_01;
  long extraout_x16_02;
  long extraout_x16_03;
  long extraout_x16_04;
  long extraout_x16_05;
  undefined8 uVar10;
  undefined1 extraout_q0 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  
  uVar10 = 0xe00002c2;
  if ((*(char **)(param_3 + 0x30) == (char *)0x0) || (*(uint *)(param_3 + 0x38) == 0)) {
    ppppppuVar6 = (undefined ******)0x0;
  }
  else {
    ppppppuVar6 = thunk_FUN_fffffff00a8d8754
                            (*(char **)(param_3 + 0x30),(ulong)*(uint *)(param_3 + 0x38),
                             (undefined8 *)0x0);
    if (ppppppuVar6 == (undefined ******)0x0) {
      uVar10 = 0xe00002ca;
    }
    else {
      plVar7 = thunk_FUN_fffffff00a894f30((long *)ppppppuVar6,*(long *)PTR_PTR_fffffff007f99798);
      plVar8 = thunk_FUN_fffffff00a894f30((long *)ppppppuVar6,*(long *)PTR_PTR_fffffff007f99818);
      if (plVar7 == (long *)0x0) {
        if (plVar8 != (long *)0x0) {
          FUN_fffffff00973d8cc();
          iVar4 = (**(code **)(extraout_x16 + 0x80))();
          if (iVar4 != 0) goto LAB_fffffff0097b6f5c;
        }
      }
      else {
LAB_fffffff0097b6f5c:
        uVar10 = FUN_fffffff00973d8cc();
        uVar10 = (**(code **)(extraout_x16_00 + 0x88))(uVar10,plVar7);
      }
    }
  }
  plVar8 = *(long **)(param_1 + 0xf8);
  uVar5 = FUN_fffffff00976b640();
  uVar1 = *(uint *)(plVar8 + 1);
  plVar7 = (long *)(**(code **)(*plVar8 + 0x10))(plVar8);
  bVar3 = FUN_fffffff009751ca0
                    (1,uVar1,(ulong)uVar5,plVar7,"_setHDRStaticMetadata",param_6,param_7,
                     (byte *)"ret = 0x%08x\n");
  if (bVar3) goto LAB_fffffff0097b7104;
  FUN_fffffff00975f824();
  lVar9 = (**(code **)(extraout_x16_01 + 0x10))(plVar8);
  if (lVar9 == 0) {
LAB_fffffff0097b7064:
    FUN_fffffff00975f824();
    lVar9 = (**(code **)(extraout_x16_04 + 0x10))(plVar8);
    if (lVar9 != 0) {
      FUN_fffffff00975f824();
      plVar7 = (long *)(**(code **)(extraout_x16_05 + 0x10))(plVar8);
      lVar9 = (**(code **)(*plVar7 + 0x38))();
      thunk_FUN_fffffff00a895b28(lVar9);
    }
  }
  else {
    FUN_fffffff00975f824();
    lVar9 = (**(code **)(extraout_x16_02 + 0x10))(plVar8);
    lVar9 = thunk_FUN_fffffff00a912bc0(lVar9);
    if (lVar9 == 0) goto LAB_fffffff0097b7064;
    FUN_fffffff00975f824();
    plVar7 = (long *)(**(code **)(extraout_x16_03 + 0x10))(plVar8);
    (**(code **)(*plVar7 + 0x1e8))(plVar7,0);
  }
  psVar2 = DAT_fffffff00af1e2e8;
  FUN_fffffff00976b640();
  thunk_FUN_fffffff00a8df19c
            (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,psVar2,1,
             (byte *)"IOAV[%d] %s<0x%llx>::%s: ret = 0x%08x\n");
LAB_fffffff0097b7104:
  if (ppppppuVar6 != (undefined ******)0x0) {
    (*(code *)(*ppppppuVar6)[5])(ppppppuVar6);
  }
  return uVar10;
}

