// FUN_fffffff009c4f014 @ fffffff009c4f014

undefined8
FUN_fffffff009c4f014
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long *param_8,
          undefined1 param_9)

{
  undefined *puVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 auVar5 [16];
  
  *(undefined8 *)(param_7 + 0x108) = 2000000000;
  *(undefined8 *)(param_7 + 0x110) = 2000000000;
  *(undefined2 *)(param_7 + 0x118) = 0;
  *(undefined1 *)(param_7 + 0x11a) = 0;
  *(undefined8 *)(param_7 + 0x128) = 0;
  *(undefined1 *)(param_7 + 0x130) = 0;
  lVar3 = (**(code **)(*(long *)PTR_DAT_fffffff008071c88 + 0x68))();
  *(long *)(param_7 + 0x128) = lVar3;
  puVar1 = PTR_DAT_fffffff00807b638;
  if (lVar3 == 0) {
    auVar5 = thunk_FUN_fffffff00a8df19c
                       (extraout_q0,param_2,param_3._0_4_,param_4._0_4_,param_5,param_6,&MACH_HEADER
                        ,(short *)PTR_DAT_fffffff00807b638,0,
                        (byte *)
                        " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                       );
    thunk_FUN_fffffff00a8df19c
              (auVar5,param_2,param_3._0_4_,param_4._0_4_,param_5,param_6,&MACH_HEADER,
               (short *)puVar1,0,(byte *)"Failed to allocate time line filter\n");
    return 0;
  }
  FUN_fffffff009c554a0(lVar3,param_9);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c4f0c4);
    (*pcVar2)();
  }
  uVar4 = (*(code *)PTR_FUN_fffffff0080780e8)(param_7,param_8);
  return uVar4;
}

