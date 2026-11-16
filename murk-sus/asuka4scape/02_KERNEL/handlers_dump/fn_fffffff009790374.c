// FUN_fffffff009790374 @ fffffff009790374 size=4 depth=0
// CALLERS:
//   fffffff00afe264e ?
//   fffffff007f94fc8 ?
// CALLS:

undefined8 FUN_fffffff009790374(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  short *psVar2;
  bool bVar3;
  uint uVar4;
  long *plVar5;
  long lVar6;
  long *plVar7;
  long *plVar8;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  
  if (**(long **)(param_3 + 0x20) == 0) {
LAB_fffffff00979056c:
    plVar5 = (long *)0x0;
  }
  else {
    plVar7 = *(long **)(param_1 + 0xf8);
    uVar4 = FUN_fffffff00976b640();
    uVar1 = *(uint *)(plVar7 + 1);
    plVar5 = (long *)(**(code **)(*plVar7 + 0x10))(plVar7);
    bVar3 = FUN_fffffff00976b650
                      (1,uVar1,(ulong)uVar4,plVar5,"_setVirtualEDID",0,0,
                       (byte *)"Passed EDID: size=%d\n");
    if (!bVar3) {
      lVar6 = (**(code **)(*plVar7 + 0x10))(plVar7);
      if (lVar6 == 0) {
LAB_fffffff0097904a8:
        lVar6 = (**(code **)(*plVar7 + 0x10))(plVar7);
        if (lVar6 != 0) {
          plVar5 = (long *)(**(code **)(*plVar7 + 0x10))(plVar7);
          lVar6 = (**(code **)(*plVar5 + 0x38))();
          thunk_FUN_fffffff00a895b28(lVar6);
        }
      }
      else {
        lVar6 = (**(code **)(*plVar7 + 0x10))(plVar7);
        lVar6 = thunk_FUN_fffffff00a912bc0(lVar6);
        if (lVar6 == 0) goto LAB_fffffff0097904a8;
        plVar5 = (long *)(**(code **)(*plVar7 + 0x10))(plVar7);
        (**(code **)(*plVar5 + 0x1e8))(plVar5,0);
      }
      psVar2 = DAT_fffffff00af1e2e8;
      FUN_fffffff00976b640();
      thunk_FUN_fffffff00a8df19c
                (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,psVar2,1,
                 (byte *)"IOAV[%d] %s<0x%llx>::%s: Passed EDID: size=%d\n");
    }
    if ((*(long *)(param_3 + 0x30) == 0) || (*(uint *)(param_3 + 0x38) == 0))
    goto LAB_fffffff00979056c;
    plVar5 = thunk_FUN_fffffff00a89e264(*(long *)(param_3 + 0x30),(ulong)*(uint *)(param_3 + 0x38));
  }
  (**(code **)(**(long **)(param_1 + 0x100) + 0x10))
            (*(long **)(param_1 + 0x100),**(long **)(param_3 + 0x20) != 0,plVar5);
  plVar8 = *(long **)(param_1 + 0xf8);
  uVar4 = FUN_fffffff00976b640();
  uVar1 = *(uint *)(plVar8 + 1);
  plVar7 = (long *)(**(code **)(*plVar8 + 0x10))(plVar8);
  bVar3 = FUN_fffffff00976b650
                    (1,uVar1,(ulong)uVar4,plVar7,"_setVirtualEDID",0,0,
                     (byte *)"%s virtual EDID mode\n");
  if (bVar3) goto LAB_fffffff009790770;
  lVar6 = (**(code **)(*plVar8 + 0x10))(plVar8);
  if (lVar6 == 0) {
LAB_fffffff0097906bc:
    lVar6 = (**(code **)(*plVar8 + 0x10))(plVar8);
    if (lVar6 != 0) {
      plVar7 = (long *)(**(code **)(*plVar8 + 0x10))(plVar8);
      lVar6 = (**(code **)(*plVar7 + 0x38))();
      thunk_FUN_fffffff00a895b28(lVar6);
    }
  }
  else {
    lVar6 = (**(code **)(*plVar8 + 0x10))(plVar8);
    lVar6 = thunk_FUN_fffffff00a912bc0(lVar6);
    if (lVar6 == 0) goto LAB_fffffff0097906bc;
    plVar7 = (long *)(**(code **)(*plVar8 + 0x10))(plVar8);
    (**(code **)(*plVar7 + 0x1e8))(plVar7,0);
  }
  psVar2 = DAT_fffffff00af1e2e8;
  FUN_fffffff00976b640();
  thunk_FUN_fffffff00a8df19c
            (extraout_q0_00,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,psVar2,1,
             (byte *)"IOAV[%d] %s<0x%llx>::%s: %s virtual EDID mode\n");
LAB_fffffff009790770:
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  return 0;
}

