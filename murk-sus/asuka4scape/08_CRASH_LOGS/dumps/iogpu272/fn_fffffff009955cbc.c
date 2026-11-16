// FUN_fffffff009955cbc @ fffffff009955cbc size=328

undefined8 FUN_fffffff009955cbc(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  ulong unaff_x30;
  
  plVar5 = *(long **)(param_1 + 0x98);
  if (plVar5 != (long *)0x0) {
LAB_fffffff009955cdc:
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009955d1c);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff009955d24. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(*plVar5 + 0x80))(plVar5,(undefined8 *)(*plVar5 + 0x80));
    return uVar3;
  }
  lVar4 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x28),DAT_fffffff007fefaf0);
  if ((lVar4 != 0) &&
     (plVar5 = (long *)(**(code **)(*DAT_fffffff007fec1a8 + 0x68))(), plVar5 != (long *)0x0)) {
    uVar6 = *(undefined8 *)(param_1 + 0x50);
    uVar3 = FUN_fffffff009981d00(lVar4);
    iVar2 = FUN_fffffff0099516c8(plVar5,uVar6,uVar3);
    if (iVar2 != 0) {
      *(long **)(param_1 + 0x98) = plVar5;
      goto LAB_fffffff009955cdc;
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Failed to create fKernelMap for data buffer\n");
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  return 0;
}

