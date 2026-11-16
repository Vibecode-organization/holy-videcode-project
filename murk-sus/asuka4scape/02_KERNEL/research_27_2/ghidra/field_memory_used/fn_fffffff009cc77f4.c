// FUN_fffffff009cc77f4 @ fffffff009cc77f4

/* WARNING: Removing unreachable block (ram,0xfffffff009cc797c) */

void FUN_fffffff009cc77f4
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7)

{
  bool bVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  short *psVar6;
  undefined1 auVar7 [16];
  
  if ((param_7 != (long *)0x0) && ((*(uint *)((long)param_7 + 0x44) >> 2 & 1) != 0)) {
    if (((*(uint *)((long)param_7 + 0x44) >> 0x1e & 1) == 0) ||
       (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
      psVar6 = *(short **)PTR_DAT_fffffff008081388;
      lVar3 = (**(code **)(*param_7 + 0x38))(param_7);
      auVar7 = thunk_FUN_fffffff00a895b28(lVar3);
      thunk_FUN_fffffff00a8df19c
                (auVar7,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar6,0,
                 (byte *)"%s: %s::%s: \n");
    }
    else {
      lVar3 = (**(code **)(*param_7 + 0x38))(param_7);
      thunk_FUN_fffffff00a895b28(lVar3);
      thunk_FUN_fffffff00a9029a0((byte *)"%s: %s::%s: \n");
    }
  }
  (**(code **)(*(long *)param_7[4] + 0x800))
            ((long *)param_7[4],(int)param_7[3] * 0x10 + 0x408,0x80000000);
  DataMemoryBarrier(2,3);
  (**(code **)(*(long *)param_7[2] + 0xb8))();
  lVar3 = (**(code **)(*(long *)param_7[2] + 200))();
  lVar4 = (**(code **)(*(long *)param_7[4] + 0x378))(*(long *)param_7[4] + 0x378);
  if ((lVar3 == lVar4) && (lVar3 = (**(code **)(*(long *)param_7[4] + 0x378))(), lVar3 != 0)) {
    plVar5 = (long *)(**(code **)(*(long *)param_7[4] + 0x378))();
    (**(code **)(*plVar5 + 0xa8))(plVar5,param_7[2]);
  }
  uVar2 = (**(code **)(*(long *)param_7[4] + 0x7f0))
                    ((long *)param_7[4],(int)param_7[3] * 0x10 + 0x40c);
  if ((uVar2 & 0xffff) != 0) {
    (**(code **)(*(long *)param_7[4] + 0x7f8))
              ((long *)param_7[4],(int)param_7[3] * 0x10 + 0x40c,uVar2 & 0xfffc);
    DataMemoryBarrier(2,3);
    *(uint *)(param_7 + 8) = (int)param_7[8] + (uVar2 >> 2) & 0x1ff;
  }
  return;
}

