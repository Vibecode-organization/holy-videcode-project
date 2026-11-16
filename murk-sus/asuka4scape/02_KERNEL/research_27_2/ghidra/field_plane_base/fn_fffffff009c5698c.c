// FUN_fffffff009c5698c @ fffffff009c5698c

void FUN_fffffff009c5698c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7,
               undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined8 param_11)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  undefined1 auVar6 [16];
  
  thunk_FUN_fffffff00a2262a8(param_7[4]);
  uVar3 = (int)param_7[0x2d] + 1U & 7;
  uVar5 = (ulong)uVar3;
  puVar1 = (undefined4 *)((long)param_7 + uVar5 * 4 + 0x128);
  auVar6 = (**(code **)(*(long *)param_7[2] + 0x80))((long *)param_7[2],param_8,param_9,puVar1);
  *(undefined1 (*) [16])(param_7 + uVar5 * 2 + 5) = auVar6;
  puVar2 = (undefined4 *)((long)param_7 + uVar5 * 4 + 0x148);
  auVar6 = (**(code **)(*(long *)param_7[3] + 0x80))((long *)param_7[3],param_10,param_11,puVar2);
  *(undefined1 (*) [16])(param_7 + uVar5 * 2 + 0x15) = auVar6;
  *(uint *)(param_7 + 0x2d) = uVar3;
  thunk_FUN_fffffff00a226de0(param_7[4]);
  if (((*(byte *)((long)param_7 + 0x179) & 1) != 0) && ((*(byte *)(param_7 + 0x2f) & 1) != 0)) {
    lVar4 = (**(code **)(*param_7 + 0x38))(param_7);
    thunk_FUN_fffffff00a895b28(lVar4);
    (**(code **)(*(long *)param_7[2] + 0x88))((long *)param_7[2],*puVar1);
    auVar6 = (**(code **)(*(long *)param_7[3] + 0x88))((long *)param_7[3],*puVar2);
    thunk_FUN_fffffff00a8df19c
              (auVar6,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00807b638,0,
               (byte *)
               "  %s(%s): addTimestamps %u, 0x%llx.%016llx, 0x%llx.%016llx, 0x%llx.%016llx, 0x%llx.%016llx, %llu, %llu\n"
              );
  }
  return;
}

