// FUN_fffffff009c55bfc @ fffffff009c55bfc

undefined8
FUN_fffffff009c55bfc
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7)

{
  undefined8 *puVar1;
  byte bVar2;
  undefined1 auVar3 [16];
  undefined8 uVar4;
  undefined *puVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  undefined8 extraout_d0;
  undefined8 extraout_var;
  uint local_34;
  
  local_34 = 0;
  *(undefined **)(param_7 + 0x180) = &DAT_fffffff0078a321e;
  lVar7 = thunk_FUN_fffffff00a903010();
  *(long *)(param_7 + 0x20) = lVar7;
  puVar5 = PTR_DAT_fffffff00807b638;
  if (lVar7 == 0) {
    auVar3._8_8_ = extraout_var;
    auVar3._0_8_ = extraout_d0;
    auVar3 = thunk_FUN_fffffff00a8df19c
                       (auVar3,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                        (short *)PTR_DAT_fffffff00807b638,0,
                        (byte *)
                        " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                       );
    thunk_FUN_fffffff00a8df19c
              (auVar3,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,(short *)puVar5,0,
               (byte *)"failed to allocate lock\n");
  }
  else {
    iVar6 = thunk_FUN_fffffff00aa14b0c((byte *)"timesync_log",&local_34,4);
    lVar7 = 0;
    bVar2 = 0;
    if (iVar6 != 0) {
      bVar2 = (byte)(local_34 >> 0xb) & 1;
    }
    *(byte *)(param_7 + 0x179) = bVar2;
    *(undefined1 *)(param_7 + 0x178) = 1;
    uVar4 = DAT_fffffff0078aede0;
    lVar9 = 8;
    do {
      puVar1 = (undefined8 *)(param_7 + 0x28 + lVar7 * 0x10);
      puVar1[1] = uVar4;
      *puVar1 = uVar4;
      puVar1[3] = uVar4;
      puVar1[2] = uVar4;
      puVar1 = (undefined8 *)(param_7 + 0xa8 + lVar7 * 0x10);
      puVar1[1] = uVar4;
      *puVar1 = uVar4;
      puVar1[3] = uVar4;
      puVar1[2] = uVar4;
      lVar7 = lVar7 + 2;
      lVar9 = lVar9 + -2;
    } while (lVar9 != 0);
    uVar8 = (**(code **)(PTR_DAT_fffffff00807b620 + 0x78))(param_7);
    if ((uVar8 & 1) != 0) {
      return 1;
    }
  }
  if (*(undefined8 **)(param_7 + 0x20) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x20));
    *(undefined8 *)(param_7 + 0x20) = 0;
  }
  return 0;
}

