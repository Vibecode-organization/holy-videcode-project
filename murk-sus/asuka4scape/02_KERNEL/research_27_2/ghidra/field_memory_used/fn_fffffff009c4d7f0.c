// FUN_fffffff009c4d7f0 @ fffffff009c4d7f0

ulong FUN_fffffff009c4d7f0
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
                undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7)

{
  undefined *puVar1;
  ulong uVar2;
  long *plVar3;
  long lVar4;
  undefined1 extraout_q0 [16];
  undefined1 auVar5 [16];
  undefined1 extraout_q0_00 [16];
  
  uVar2 = (**(code **)(PTR_DAT_fffffff00807b628 + 0xb8))();
  if (*(long **)(param_7 + 0x88) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0x88) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0x88) = 0;
  *(undefined8 *)(param_7 + 0x90) = 0;
  plVar3 = thunk_FUN_fffffff00a8d0c44(1);
  auVar5 = extraout_q0;
  if (*(long **)(param_7 + 0x88) != (long *)0x0) {
    auVar5 = (**(code **)(**(long **)(param_7 + 0x88) + 0x28))();
  }
  *(long **)(param_7 + 0x88) = plVar3;
  puVar1 = PTR_DAT_fffffff00807b638;
  if (plVar3 == (long *)0x0) {
    auVar5 = thunk_FUN_fffffff00a8df19c
                       (auVar5,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                        (short *)PTR_DAT_fffffff00807b638,0,
                        (byte *)
                        " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                       );
    thunk_FUN_fffffff00a8df19c
              (auVar5,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,(short *)puVar1,0,
               (byte *)"Failed to allocate daemon clients array\n");
  }
  else {
    lVar4 = thunk_FUN_fffffff00a903010();
    *(long *)(param_7 + 0x90) = lVar4;
    puVar1 = PTR_DAT_fffffff00807b638;
    if (lVar4 == 0) {
      auVar5 = thunk_FUN_fffffff00a8df19c
                         (extraout_q0_00,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                          (short *)PTR_DAT_fffffff00807b638,0,
                          (byte *)
                          " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                         );
      thunk_FUN_fffffff00a8df19c
                (auVar5,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,(short *)puVar1,0,
                 (byte *)"Failed to allocate daemon clients lock\n");
    }
  }
  if ((uVar2 & 1) == 0) {
    if (*(long **)(param_7 + 0x88) != (long *)0x0) {
      (**(code **)(**(long **)(param_7 + 0x88) + 0x28))();
    }
    *(undefined8 *)(param_7 + 0x88) = 0;
    if (*(undefined8 **)(param_7 + 0x90) != (undefined8 *)0x0) {
      thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x90));
      *(undefined8 *)(param_7 + 0x90) = 0;
    }
  }
  return uVar2;
}

