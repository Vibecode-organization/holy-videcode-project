// FUN_fffffff009ccda38 @ fffffff009ccda38

/* WARNING: Removing unreachable block (ram,0xfffffff009ccdc70) */

void FUN_fffffff009ccda38
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  long *plVar4;
  int *piVar5;
  undefined8 *puVar6;
  short *psVar7;
  ulong unaff_x30;
  undefined1 auVar8 [16];
  
  plVar4 = (long *)(**(code **)(*(long *)param_7[0x17] + 0x118))
                             ((long *)param_7[0x17],"usb-repeater");
  plVar4 = thunk_FUN_fffffff00a894f30(plVar4,*(long *)PTR_PTR_fffffff008089cf0);
  if ((((plVar4 == (long *)0x0) || (iVar3 = (**(code **)(*plVar4 + 0xa0))(), iVar3 != 8)) ||
      (piVar5 = (int *)(**(code **)(*plVar4 + 0xd8))(plVar4), *piVar5 != 0x6d636177)) ||
     ((piVar5[1] != 2 ||
      (iVar3 = (**(code **)(*(long *)param_7[0x17] + 0x2d0))((long *)param_7[0x17],param_7),
      iVar3 == 0)))) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      (*(code *)PTR_FUN_fffffff0080876e8)(param_7);
      return;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ccdc08);
    (*pcVar1)();
  }
  if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar2 = thunk_FUN_fffffff00a394140(), !bVar2)) {
      psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      thunk_FUN_fffffff00a8df19c
                (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                 (byte *)"%s@%s: %s::%s: \n");
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: \n");
    }
  }
  (**(code **)(*(long *)param_7[0x4d0] + 0xa0))((long *)param_7[0x4d0],0);
  puVar6 = (undefined8 *)(*(long *)param_7[0x4d0] + 0xa0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009ccdd34. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*puVar6)((long *)param_7[0x4d0],2,puVar6);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ccdd2c);
  (*pcVar1)();
}

