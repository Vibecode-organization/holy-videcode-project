// FUN_fffffff00997a4d8 @ fffffff00997a4d8 size=444

undefined8 FUN_fffffff00997a4d8(long param_1,long param_2,uint param_3)

{
  long *plVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  
  if (0x28 < param_3) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"Invalid resource group count\n");
    return 0xe00002c2;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(*(long *)(param_1 + 0x430) + 0x298));
  FUN_fffffff009976978(param_1);
  if (param_3 != 0) {
    FUN_fffffff009965604(*(undefined8 *)(param_1 + 0x488));
    uVar7 = 0;
    do {
      iVar2 = *(int *)(param_2 + uVar7 * 4);
      if (((iVar2 == 0) ||
          (plVar3 = (long *)FUN_fffffff00996561c(*(undefined8 *)(param_1 + 0x488),iVar2),
          plVar3 == (long *)0x0)) || ((char)plVar3[2] != '\x03')) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"Invalid resource group ID %08x\n");
        FUN_fffffff009965610(*(undefined8 *)(param_1 + 0x488));
        lVar4 = *(long *)(param_1 + 0x430);
        if (uVar7 != 0) {
          lVar5 = 0;
          do {
            (**(code **)(**(long **)(lVar4 + 0x150 + lVar5 * 8) + 0x28))();
            lVar4 = *(long *)(param_1 + 0x430);
            *(undefined8 *)(lVar4 + 0x150 + lVar5 * 8) = 0;
            lVar5 = lVar5 + 1;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        uVar6 = 0xe00002c2;
        *(undefined4 *)(lVar4 + 0x290) = 0;
        goto LAB_fffffff00997a66c;
      }
      lVar4 = *(long *)(param_1 + 0x430);
      lVar5 = (ulong)*(uint *)(lVar4 + 0x290) * 8;
      plVar1 = (long *)(lVar4 + 0x150 + (long)(int)lVar5);
      if (lVar5 - (int)lVar5 != 0) {
        plVar1 = (long *)(lVar4 + 0x150 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *(uint *)(lVar4 + 0x290) = *(uint *)(lVar4 + 0x290) + 1;
      *plVar1 = (long)plVar3;
      (**(code **)(*plVar3 + 0x20))();
      uVar7 = uVar7 + 1;
    } while (param_3 != uVar7);
    FUN_fffffff009965610(*(undefined8 *)(param_1 + 0x488));
  }
  uVar6 = 0;
LAB_fffffff00997a66c:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(*(long *)(param_1 + 0x430) + 0x298));
  return uVar6;
}

