// FUN_fffffff008169f24 @ fffffff008169f24 size=188

void FUN_fffffff008169f24(long param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  long *plVar4;
  uint uVar5;
  long *plVar6;
  ulong unaff_x30;
  
  uVar3 = thunk_EXT_FUN_8011000003397c88();
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 800));
  if (*(long **)(param_1 + 0x328) != (long *)0x0) {
    uVar5 = 0;
    plVar4 = *(long **)(param_1 + 0x328);
    do {
      plVar6 = (long *)plVar4[0x3f];
      uVar2 = (**(code **)(*plVar4 + 0xb0))(plVar4,uVar3);
      uVar5 = uVar5 | uVar2;
      plVar4 = plVar6;
    } while (plVar6 != (long *)0x0);
    if ((uVar5 & 1) != 0) {
      (**(code **)(**(long **)(param_1 + 0x548) + 0xf0))(*(long **)(param_1 + 0x548),1000);
      goto LAB_fffffff008169fbc;
    }
  }
  *(undefined1 *)(param_1 + 0x550) = 0;
LAB_fffffff008169fbc:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008169fdc);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 800));
  return;
}

