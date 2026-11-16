// FUN_fffffff00995b0c8 @ fffffff00995b0c8 size=528

void FUN_fffffff00995b0c8(long param_1)

{
  uint uVar1;
  long *plVar2;
  code *pcVar3;
  long lVar4;
  long *plVar5;
  uint uVar6;
  long *plVar7;
  
  if (*(long *)(param_1 + 0x38) != 0) {
    FUN_fffffff00994463c();
    lVar4 = *(long *)(param_1 + 0x38);
    uVar1 = *(uint *)(lVar4 + 0x28);
    if (1 < uVar1) {
      uVar6 = 1;
      do {
        lVar4 = FUN_fffffff009945214(*(undefined8 *)(param_1 + 0x38),uVar6);
        if (lVar4 != 0) {
          FUN_fffffff00994508c(*(undefined8 *)(param_1 + 0x38),uVar6);
          FUN_fffffff009959180();
        }
        uVar6 = uVar6 + 1;
      } while (uVar1 != uVar6);
      lVar4 = *(long *)(param_1 + 0x38);
    }
    FUN_fffffff009944648(lVar4);
  }
  if (*(long *)(param_1 + 0x98) != 0) {
    thunk_EXT_FUN_8011000003277d90();
    thunk_EXT_FUN_801100000327731c(*(undefined8 *)(param_1 + 0x98));
    *(undefined8 *)(param_1 + 0x98) = 0;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x90));
  plVar2 = *(long **)(param_1 + 0x80);
  while (plVar2 != (long *)0x0) {
    plVar5 = plVar2 + 0xc;
    plVar7 = (long *)*plVar5;
    FUN_fffffff00995a580(plVar2);
    lVar4 = *plVar5;
    if (lVar4 == 0) {
      plVar5 = (long *)plVar2[0xd];
      if ((long *)*plVar5 != plVar2) goto LAB_fffffff00995b2b8;
      *(long **)(param_1 + 0x88) = plVar5;
    }
    else {
      if (*(long **)(lVar4 + 0x68) != plVar5) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995b2d0);
        (*pcVar3)();
      }
      if (*(long **)plVar2[0xd] != plVar2) {
LAB_fffffff00995b2b8:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995b2c0);
        (*pcVar3)();
      }
      *(long **)(lVar4 + 0x68) = (long *)plVar2[0xd];
      plVar5 = (long *)plVar2[0xd];
    }
    *plVar5 = lVar4;
    (**(code **)(*plVar2 + 0x28))(plVar2);
    plVar2 = plVar7;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x90));
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x68));
  plVar2 = *(long **)(param_1 + 0x58);
  do {
    if (plVar2 == (long *)0x0) {
      *(undefined1 *)(param_1 + 0x74) = 1;
      thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x68),param_1,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x68));
      *(undefined8 *)(param_1 + 0x78) = 0;
      return;
    }
    plVar5 = plVar2 + 3;
    plVar7 = (long *)*plVar5;
    FUN_fffffff00995a390(plVar2[2],2,plVar2[10],0);
    lVar4 = *plVar5;
    if (lVar4 == 0) {
      plVar5 = (long *)plVar2[4];
      if ((long *)*plVar5 != plVar2) goto LAB_fffffff00995b2c0;
      *(long **)(param_1 + 0x60) = plVar5;
    }
    else {
      if (*(long **)(lVar4 + 0x20) != plVar5) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995b2d8);
        (*pcVar3)();
      }
      if (*(long **)plVar2[4] != plVar2) {
LAB_fffffff00995b2c0:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995b2c8);
        (*pcVar3)();
      }
      *(long **)(lVar4 + 0x20) = (long *)plVar2[4];
      plVar5 = (long *)plVar2[4];
    }
    *plVar5 = lVar4;
    (**(code **)(*plVar2 + 0x28))(plVar2);
    plVar2 = plVar7;
  } while( true );
}

