// FUN_fffffff00996e374 @ fffffff00996e374 size=268

void FUN_fffffff00996e374(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  ulong unaff_x30;
  
  FUN_fffffff00994b178
            (*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),(int)(char)*(uint *)(param_1 + 0x84)
             ,*(uint *)(param_1 + 0x84) & 0xffffff00);
  if (*(int *)(param_1 + 0x88) != 0xff) {
    FUN_fffffff00994b178
              (*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),
               (int)(char)*(uint *)(param_1 + 0x88),*(uint *)(param_1 + 0x88) & 0xffffff00);
  }
  uVar2 = thunk_EXT_FUN_8011000003397c88();
  *(undefined8 *)(param_1 + 0x70) = uVar2;
  if (*(long *)(param_1 + 0x60) != 0) {
    FUN_fffffff00997a298(*(long *)(param_1 + 0x60),uVar2);
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    if ((*(byte *)(param_1 + 0x4c) & 1) != 0) {
      for (lVar3 = *(long *)(param_1 + 0x38); lVar3 != 0; lVar3 = *(long *)(lVar3 + 0x50)) {
        *(undefined4 *)(lVar3 + 0x60) = 0xe00002eb;
      }
    }
    FUN_fffffff009950418(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x158),param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  if ((DAT_fffffff00af227e8 != 0) && (*(long *)(param_1 + 0x60) != 0)) {
    uVar2 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996e470);
      (*pcVar1)();
    }
    thunk_EXT_FUN_80110000036da494
              (0x850900e2,uVar2,*(undefined4 *)(param_1 + 0x84),*(undefined4 *)(param_1 + 0x88),
               *(undefined8 *)(param_1 + 0x100),0);
    return;
  }
  return;
}

