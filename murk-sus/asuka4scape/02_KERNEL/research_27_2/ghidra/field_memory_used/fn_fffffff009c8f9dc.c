// FUN_fffffff009c8f9dc @ fffffff009c8f9dc

/* WARNING: Removing unreachable block (ram,0xfffffff009c8fb8c) */

undefined8
FUN_fffffff009c8f9dc
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7,long *param_8,long *param_9)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  short *psVar8;
  undefined1 auVar9 [16];
  
  if (param_8 != (long *)0x0) {
    iVar2 = (**(code **)(*param_8 + 0xb8))(param_8,"SetDebugFlag");
    if (iVar2 == 0) {
      uVar7 = 0xe0000001;
    }
    else {
      plVar5 = thunk_FUN_fffffff00a894f30(param_9,*(long *)PTR_PTR_fffffff00807fa98);
      if (plVar5 == (long *)0x0) {
        uVar7 = 0xe00002c2;
      }
      else {
        uVar3 = (**(code **)(*plVar5 + 0xa8))();
        if ((param_7 != (long *)0x0) && ((*(uint *)((long)param_7 + 500) & 1) != 0)) {
          if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
             (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
            psVar8 = *(short **)PTR_DAT_fffffff00807fa80;
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            auVar9 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
            thunk_FUN_fffffff00a8df19c
                      (auVar9,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar8,0,
                       (byte *)"%s@%s: %s::%s: SetDebugFlag - 0x%08x\n");
          }
          else {
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            (**(code **)(*param_7 + 0x218))(param_7,0);
            thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: SetDebugFlag - 0x%08x\n");
          }
        }
        lVar6 = (**(code **)(*param_7 + 0x38))(param_7);
        uVar4 = thunk_FUN_fffffff00944ede4(lVar6,*(long *)PTR_PTR_fffffff00807fac0,0);
        uVar7 = 0;
        *(uint *)((long)param_7 + 500) = uVar4 | uVar3;
      }
    }
    return uVar7;
  }
  return 0xe0000001;
}

