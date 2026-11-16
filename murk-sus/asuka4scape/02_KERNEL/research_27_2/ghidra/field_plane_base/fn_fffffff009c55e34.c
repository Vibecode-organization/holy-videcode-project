// FUN_fffffff009c55e34 @ fffffff009c55e34

int FUN_fffffff009c55e34
              (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4
              ,undefined4 param_5,undefined4 param_6,long *param_7,long param_8,long param_9,
              undefined8 param_10)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  undefined1 auVar10 [16];
  
  if (param_8 != 0) {
    param_7[0x33] = param_8;
  }
  if (param_9 != 0) {
    param_7[0x34] = param_9;
  }
  if ((*(byte *)(param_7 + 0x32) & 1) == 0) {
    FUN_fffffff009c560e8(param_1,param_2,param_3,param_4,param_5,param_6,(long)param_7,(long *)0x0);
  }
  thunk_FUN_fffffff00a2262a8(param_7[4]);
  lVar8 = DAT_fffffff0078aede0;
  uVar3 = (int)param_7[0x2d] + 1U & 7;
  uVar9 = (ulong)uVar3;
  (param_7 + uVar9 * 2 + 5)[1] = DAT_fffffff0078aede0;
  param_7[uVar9 * 2 + 5] = lVar8;
  (param_7 + uVar9 * 2 + 0x15)[1] = lVar8;
  param_7[uVar9 * 2 + 0x15] = lVar8;
  puVar1 = (undefined4 *)((long)param_7 + uVar9 * 4 + 0x128);
  iVar6 = (**(code **)(*(long *)param_7[2] + 0x78))((long *)param_7[2],param_8,param_10,puVar1);
  puVar2 = (undefined4 *)((long)param_7 + uVar9 * 4 + 0x148);
  iVar7 = (**(code **)(*(long *)param_7[3] + 0x78))((long *)param_7[3],param_9,param_10,puVar2);
  *(uint *)(param_7 + 0x2d) = uVar3;
  auVar10 = thunk_FUN_fffffff00a226de0(param_7[4]);
  puVar5 = PTR_DAT_fffffff00807b638;
  if (iVar6 != 0) {
    auVar10 = thunk_FUN_fffffff00a8df19c
                        (auVar10,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                         (short *)PTR_DAT_fffffff00807b638,0,
                         (byte *)
                         " IOTimeSyncFamily assertion FailMessage \"%s\" failed in %s at line %d. ")
    ;
    auVar10 = thunk_FUN_fffffff00a8df19c
                        (auVar10,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                         (short *)puVar5,0,(byte *)"Failed to re-initialize A filter\n");
  }
  puVar5 = PTR_DAT_fffffff00807b638;
  if (iVar7 != 0) {
    auVar10 = thunk_FUN_fffffff00a8df19c
                        (auVar10,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                         (short *)PTR_DAT_fffffff00807b638,0,
                         (byte *)
                         " IOTimeSyncFamily assertion FailMessage \"%s\" failed in %s at line %d. ")
    ;
    thunk_FUN_fffffff00a8df19c
              (auVar10,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,(short *)puVar5,0,
               (byte *)"Failed to re-initialize B filter\n");
  }
  if ((((*(byte *)((long)param_7 + 0x179) & 1) != 0) && (iVar7 == 0 && iVar6 == 0)) &&
     ((*(byte *)(param_7 + 0x2f) & 1) != 0)) {
    lVar8 = (**(code **)(*param_7 + 0x38))(param_7);
    thunk_FUN_fffffff00a895b28(lVar8);
    (**(code **)(*(long *)param_7[2] + 0x88))((long *)param_7[2],*puVar1);
    auVar10 = (**(code **)(*(long *)param_7[3] + 0x88))((long *)param_7[3],*puVar2);
    thunk_FUN_fffffff00a8df19c
              (auVar10,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00807b638,0,
               (byte *)"  %s(%s): reinitializeFilter %u, %llu, %llu\n");
  }
  iVar4 = -0x1ffffd44;
  if (iVar7 != 0) {
    iVar4 = iVar7;
  }
  if (iVar6 != 0) {
    iVar4 = iVar6;
  }
  return iVar4;
}

