// FUN_fffffff009cfb964 @ fffffff009cfb964

/* WARNING: Removing unreachable block (ram,0xfffffff009cfbb58) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfbcb4) */

void FUN_fffffff009cfb964
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7,ulong param_8,
               undefined8 param_9,long param_10)

{
  undefined1 auVar1 [16];
  bool bVar2;
  long lVar3;
  short *psVar4;
  undefined *local_68;
  undefined8 local_60;
  code *local_58;
  undefined *local_50;
  long *plStack_48;
  
  lVar3 = thunk_FUN_fffffff00a92f600();
  if (((param_8 & 0x20004) == 0) || (param_10 != lVar3)) {
    lVar3 = thunk_FUN_fffffff00a92f600();
    if (((param_8 & 0x20004) == 0) && (param_10 == lVar3)) {
      if ((param_7 != (long *)0x0) && ((*(uint *)((long)param_7 + 500) >> 4 & 1) != 0)) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
           (bVar2 = thunk_FUN_fffffff00a394140(), !bVar2)) {
          psVar4 = *(short **)PTR_DAT_fffffff008089cb8;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar1 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar4,0,
                     (byte *)"%s@%s: %s::%s: system wake\n");
        }
        else {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: system wake\n");
        }
      }
      lVar3 = (**(code **)(*(long *)param_7[0x17] + 0x118))
                        ((long *)param_7[0x17],"usb-device-slp-ddr");
      if ((lVar3 != **(long **)PTR_PTR_fffffff008089d58) &&
         ((**(code **)(*(long *)param_7[0x4d4] + 0xb0))(), (*(byte *)(param_7 + 0x4d2) & 1) != 0)) {
        (**(code **)(*(long *)param_7[0x4d4] + 0xf0))((long *)param_7[0x4d4],0);
      }
    }
  }
  else {
    if ((param_7 != (long *)0x0) && ((*(uint *)((long)param_7 + 500) >> 4 & 1) != 0)) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar2 = thunk_FUN_fffffff00a394140(), !bVar2)) {
        psVar4 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar1 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar4,0,
                   (byte *)"%s@%s: %s::%s: system sleep\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: system sleep\n");
      }
    }
    local_68 = PTR_DAT_fffffff008089c90;
    local_60 = DAT_fffffff0078bdde8;
    local_58 = FUN_fffffff009cfbda8;
    local_50 = &DAT_fffffff008087800;
    plStack_48 = param_7;
    thunk_FUN_fffffff00a960120((long *)param_7[0x8c],&local_68);
    thunk_FUN_fffffff00a92f600();
  }
  (**(code **)(PTR_DAT_fffffff008089d10 + 0x510))(param_7,param_8,param_9,param_10);
  return;
}

