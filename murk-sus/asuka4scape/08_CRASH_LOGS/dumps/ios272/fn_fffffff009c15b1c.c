// FUN_fffffff009c15b1c @ fffffff009c15b1c size=296

void FUN_fffffff009c15b1c(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  undefined1 auVar3 [16];
  undefined8 local_40;
  undefined8 uStack_38;
  ulong local_30;
  ulong uStack_28;
  long local_18;
  
  local_18 = *(long *)PTR_DAT_fffffff00806ca40;
  if (*(long *)(param_1 + 0x48) == 0) {
    lVar2 = *(long *)(param_1 + 0x60);
    if (lVar2 != 0) {
      if (*(long *)PTR_DAT_fffffff00806ca40 == local_18) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c15be8);
          (*pcVar1)();
        }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c15be8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(lVar2 + 0x10))
                  (lVar2,*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x10),
                   *(undefined8 *)(param_1 + 0x20));
        return;
      }
      goto LAB_fffffff009c15c40;
    }
    if (*(code **)(param_1 + 0x58) != (code *)0x0) {
      if (*(long *)PTR_DAT_fffffff00806ca40 == local_18) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c15c38);
          (*pcVar1)();
        }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c15c3c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(param_1 + 0x58))
                  (*(undefined8 *)(param_1 + 0x50),*(undefined8 *)(param_1 + 0x38),
                   *(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x20));
        return;
      }
      goto LAB_fffffff009c15c40;
    }
  }
  else {
    local_30 = *(ulong *)(param_1 + 0x10);
    auVar3 = NEON_ext(*(undefined1 (*) [16])(param_1 + 0x18),*(undefined1 (*) [16])(param_1 + 0x18),
                      8,1);
    uStack_38 = auVar3._8_8_;
    local_40 = auVar3._0_8_;
    uStack_28 = local_30 >> 0x20;
    thunk_EXT_FUN_80110000039a40ec(*(long *)(param_1 + 0x48) + 0x50,0,&local_40,4);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_18) {
    return;
  }
LAB_fffffff009c15c40:
  thunk_EXT_FUN_8011000003a48590();
  return;
}

