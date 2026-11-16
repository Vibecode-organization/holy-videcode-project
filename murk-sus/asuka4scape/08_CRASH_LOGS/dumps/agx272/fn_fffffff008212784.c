// FUN_fffffff008212784 @ fffffff008212784 size=168

/* WARNING: Removing unreachable block (ram,0xfffffff0082127f4) */

void FUN_fffffff008212784(long param_1)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  ulong unaff_x30;
  
  (**(code **)(PTR_DAT_fffffff007ca6108 + 0xb8))();
  plVar3 = *(long **)(*(long *)(param_1 + 0xc0) + 0x4b0);
  thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x18),&DAT_fffffff00ae21f50);
  lVar2 = *plVar3;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008212828. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar2 + 0x178))
              (plVar3,0,*(undefined4 *)(*(long *)(param_1 + 0x18) + 0x7ec),lVar2 + 0x178);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008212820);
  (*pcVar1)();
}

