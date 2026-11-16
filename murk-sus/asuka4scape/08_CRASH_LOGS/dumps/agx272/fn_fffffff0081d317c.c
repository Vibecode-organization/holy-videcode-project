// FUN_fffffff0081d317c @ fffffff0081d317c size=464

/* WARNING: Removing unreachable block (ram,0xfffffff0081d3200) */

undefined8
FUN_fffffff0081d317c(long param_1,undefined8 param_2,undefined8 param_3,long param_4,long param_5)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  long *plVar4;
  long *plVar5;
  
  FUN_fffffff0081d30b8();
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xe8));
  plVar5 = *(long **)(param_1 + 0xf0);
  while( true ) {
    if (plVar5 == (long *)0x0) {
      uVar3 = thunk_EXT_FUN_8011000003a49114
                        (
                        "AGXk: %s:%d:%s: !!! AGXArmFirmwareMapper::iovmUnmapMemory: unmapping address that was never mapped!\n"
                        );
      return uVar3;
    }
    lVar2 = (**(code **)(*(long *)*plVar5 + 0x98))();
    plVar4 = *(long **)(*(long *)(param_1 + 0xe0) + 0x4b0);
    lVar2 = (**(code **)(*plVar4 + 0x208))(plVar4,plVar5[1] + lVar2,0);
    if (param_4 == lVar2) break;
    plVar5 = (long *)plVar5[3];
  }
  if (param_5 != plVar5[2]) {
    uVar3 = thunk_EXT_FUN_8011000003a49114
                      (
                      "AGXk: %s:%d:%s: !!! AGXArmFirmwareMapper::iovmUnmapMemory: unmapping different length than was mapped!\n"
                      );
    return uVar3;
  }
  lVar2 = plVar5[3];
  if (lVar2 == 0) {
    plVar4 = (long *)plVar5[4];
    if ((long *)*plVar4 != plVar5) goto LAB_fffffff0081d3314;
    *(long **)(param_1 + 0xf8) = plVar4;
  }
  else {
    if (*(long **)(lVar2 + 0x20) != plVar5 + 3) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0081d3324);
      (*pcVar1)();
    }
    if (*(long **)plVar5[4] != plVar5) {
LAB_fffffff0081d3314:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0081d331c);
      (*pcVar1)();
    }
    *(undefined8 **)(lVar2 + 0x20) = (undefined8 *)plVar5[4];
    plVar4 = (long *)plVar5[4];
  }
  *plVar4 = lVar2;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xe8));
  thunk_EXT_FUN_801100000297b408(*plVar5);
  if ((long *)*plVar5 != (long *)0x0) {
    (**(code **)(*(long *)*plVar5 + 0x28))();
  }
  *plVar5 = 0;
  thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ca1888,plVar5);
  return 0;
}

