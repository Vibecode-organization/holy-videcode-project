// FUN_fffffff0099796a4 @ fffffff0099796a4 size=472

undefined8 FUN_fffffff0099796a4(long param_1,uint param_2,long param_3)

{
  long *plVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  
  lVar5 = *(long *)(param_1 + 0x430);
  if ((*(int *)(lVar5 + 0x148) != 0) || ((*(byte *)(lVar5 + 0x2a0) & 1) != 0)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "Duplicate command buffer resource group tokens\n");
    return 0;
  }
  if (0x28 < param_2) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"Invalid resource group count\n");
    return 0;
  }
  if (param_2 != 0) {
    FUN_fffffff009965604(*(undefined8 *)(param_1 + 0x488));
    uVar7 = 0;
    do {
      iVar2 = *(int *)(param_3 + uVar7 * 4);
      if (((iVar2 == 0) ||
          (plVar3 = (long *)FUN_fffffff00996561c(*(undefined8 *)(param_1 + 0x488),iVar2),
          plVar3 == (long *)0x0)) || ((char)plVar3[2] != '\x03')) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"Invalid resource group ID %08x\n");
        FUN_fffffff009965610(*(undefined8 *)(param_1 + 0x488));
        lVar5 = *(long *)(param_1 + 0x430);
        if (uVar7 != 0) {
          lVar6 = 0;
          do {
            (**(code **)(**(long **)(lVar5 + 8 + lVar6 * 8) + 0x28))();
            lVar5 = *(long *)(param_1 + 0x430);
            *(undefined8 *)(lVar5 + 8 + lVar6 * 8) = 0;
            lVar6 = lVar6 + 1;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        uVar4 = 0;
        *(undefined4 *)(lVar5 + 0x148) = 0;
        goto LAB_fffffff009979874;
      }
      lVar5 = *(long *)(param_1 + 0x430);
      lVar6 = (ulong)*(uint *)(lVar5 + 0x148) * 8;
      plVar1 = (long *)(lVar5 + 8 + (long)(int)lVar6);
      if (lVar6 - (int)lVar6 != 0) {
        plVar1 = (long *)(lVar5 + 8 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *(uint *)(lVar5 + 0x148) = *(uint *)(lVar5 + 0x148) + 1;
      *plVar1 = (long)plVar3;
      (**(code **)(*plVar3 + 0x20))();
      uVar7 = uVar7 + 1;
    } while (param_2 != uVar7);
    FUN_fffffff009965610(*(undefined8 *)(param_1 + 0x488));
    lVar5 = *(long *)(param_1 + 0x430);
  }
  uVar4 = 1;
LAB_fffffff009979874:
  *(undefined1 *)(lVar5 + 0x2a0) = 1;
  return uVar4;
}

