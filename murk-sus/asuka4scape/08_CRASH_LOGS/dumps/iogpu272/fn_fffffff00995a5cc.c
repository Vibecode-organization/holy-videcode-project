// FUN_fffffff00995a5cc @ fffffff00995a5cc size=288

undefined8 FUN_fffffff00995a5cc(long param_1,undefined8 param_2)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  undefined8 uVar7;
  
  uVar7 = 0xe00002bc;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
  plVar6 = *(long **)(param_1 + 0x40);
  if ((plVar6 != (long *)0x0) && ((int)plVar6[5] == 2)) {
    lVar4 = plVar6[3];
    if (lVar4 == 0) {
      plVar5 = (long *)plVar6[4];
      if ((long *)*plVar5 != plVar6) goto LAB_fffffff00995a6dc;
      *(long **)(param_1 + 0x48) = plVar5;
    }
    else {
      if (*(long **)(lVar4 + 0x20) != plVar6 + 3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995a6ec);
        (*pcVar2)();
      }
      if (*(long **)plVar6[4] != plVar6) {
LAB_fffffff00995a6dc:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995a6e4);
        (*pcVar2)();
      }
      *(long **)(lVar4 + 0x20) = (long *)plVar6[4];
      plVar5 = (long *)plVar6[4];
    }
    *plVar5 = lVar4;
    piVar1 = (int *)(param_1 + 0x2c);
    LOAcquire();
    iVar3 = *piVar1;
    *piVar1 = iVar3 + 1;
    LORelease();
    FUN_fffffff00995a390(CONCAT44((int)((ulong)piVar1 >> 0x20),iVar3),param_1,param_2,0,0);
    (**(code **)(*plVar6 + 0x28))(plVar6);
    thunk_EXT_FUN_80110000036da494(0x8509010c,*(undefined8 *)(param_1 + 0x38),0,0,0,0);
    uVar7 = 0;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
  return uVar7;
}

