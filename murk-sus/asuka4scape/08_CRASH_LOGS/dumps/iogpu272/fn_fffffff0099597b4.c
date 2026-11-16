// FUN_fffffff0099597b4 @ fffffff0099597b4 size=324

void FUN_fffffff0099597b4(long param_1,undefined8 param_2)

{
  int iVar1;
  long *plVar2;
  code *pcVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  
  plVar2 = *(long **)(param_1 + 0x40);
  do {
    if (plVar2 == (long *)0x0) {
      return;
    }
    plVar6 = plVar2 + 3;
    plVar7 = (long *)*plVar6;
    iVar1 = (int)plVar2[5];
    plVar5 = plVar7;
    if (iVar1 - 3U < 2) {
      if ((long *)plVar2[6] != (long *)0x0) {
        (**(code **)(*(long *)plVar2[6] + 0x28))();
        plVar5 = (long *)*plVar6;
      }
      lVar4 = 0;
      plVar2[6] = 0;
      if (plVar5 == (long *)0x0) goto LAB_fffffff009959848;
LAB_fffffff009959874:
      if ((long *)plVar5[4] != plVar6) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0099598f8);
        (*pcVar3)();
      }
      if (*(long **)plVar2[4] != plVar2) {
LAB_fffffff0099598e8:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0099598f0);
        (*pcVar3)();
      }
      plVar5[4] = (long)plVar2[4];
      plVar6 = (long *)plVar2[4];
    }
    else {
      if (iVar1 == 2) {
        lVar4 = plVar2[6];
      }
      else if (iVar1 == 1) {
        lVar4 = plVar2[10];
      }
      else {
        lVar4 = 0;
      }
      if (plVar7 != (long *)0x0) goto LAB_fffffff009959874;
LAB_fffffff009959848:
      plVar6 = (long *)plVar2[4];
      if ((long *)*plVar6 != plVar2) goto LAB_fffffff0099598e8;
      *(long **)(param_1 + 0x48) = plVar6;
    }
    *plVar6 = (long)plVar5;
    FUN_fffffff00995a390(param_1,param_2,lVar4,0);
    (**(code **)(*plVar2 + 0x28))(plVar2);
    plVar2 = plVar7;
  } while( true );
}

