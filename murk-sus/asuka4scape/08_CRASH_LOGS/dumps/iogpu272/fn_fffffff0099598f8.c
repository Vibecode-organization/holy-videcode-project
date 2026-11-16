// FUN_fffffff0099598f8 @ fffffff0099598f8 size=4

void FUN_fffffff0099598f8(long param_1,int *param_2,long param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  long *plVar6;
  undefined8 uVar7;
  long *plStack_38;
  
  iVar1 = *param_2;
  uVar5 = (param_3 - (long)param_2) - 8;
  if (iVar1 < 2) {
    if (iVar1 == 0) {
      if (0x2f < uVar5) {
        lVar2 = FUN_fffffff009958aec(param_1,1);
        if (lVar2 != 0) {
          *(int *)(lVar2 + 0x30) = param_2[2];
          *(undefined8 *)(lVar2 + 0x38) = *(undefined8 *)(param_2 + 4);
          *(undefined8 *)(lVar2 + 0x40) = *(undefined8 *)(param_2 + 6);
          *(undefined8 *)(lVar2 + 0x48) = *(undefined8 *)(param_2 + 8);
          *(undefined8 *)(lVar2 + 0x50) = *(undefined8 *)(param_2 + 0xc);
          *(undefined8 *)(lVar2 + 0x18) = 0;
          plVar6 = *(long **)(param_1 + 0x48);
          *(long **)(lVar2 + 0x20) = plVar6;
          *plVar6 = lVar2;
          *(undefined8 **)(param_1 + 0x48) = (undefined8 *)(lVar2 + 0x18);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x28);
          return;
        }
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Failed to create IO Command Descriptor (kIOGPUIOCommandDescriptorTypeIO)\n")
        ;
        *(undefined1 *)(param_1 + 0x5c) = 1;
        return;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Insufficient bytes (%llu) for sIOGPUIOKernelArgs (%lu)\n");
      goto LAB_fffffff009959d80;
    }
    if (iVar1 == 1) {
      if (*(int *)(param_1 + 0x28) == 0) {
        return;
      }
      if (uVar5 < 0x10) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Insufficient bytes (%llu) for sIOGPUIOKernelCommandBarrierArgs (%lu)\n");
      }
      else {
        lVar2 = FUN_fffffff009958aec(param_1,2);
        if (lVar2 != 0) {
          *(undefined4 *)(lVar2 + 0x38) = *(undefined4 *)(param_1 + 0x28);
          *(undefined8 *)(lVar2 + 0x30) = *(undefined8 *)(param_2 + 2);
          *(char *)(lVar2 + 0x3c) = (char)param_2[4];
          *(undefined8 *)(lVar2 + 0x18) = 0;
          plVar6 = *(long **)(param_1 + 0x48);
          *(long **)(lVar2 + 0x20) = plVar6;
          *plVar6 = lVar2;
          *(undefined8 **)(param_1 + 0x48) = (undefined8 *)(lVar2 + 0x18);
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          return;
        }
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Failed to create IO Command Descriptor (kIOGPUIOCommandDescriptorTypeBarrier)\n"
                  );
      }
      goto LAB_fffffff009959d80;
    }
LAB_fffffff009959a14:
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Invalid Command (%u) of bytes (%llu)\n");
LAB_fffffff009959d80:
    *(undefined1 *)(param_1 + 0x5c) = 1;
    return;
  }
  if (iVar1 == 2) {
    if (uVar5 < 0x10) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Insufficient bytes (%llu) for sIOGPUIOKernelCommandSignalOrWaitEventArgs (%lu)\n"
                );
      goto LAB_fffffff009959d80;
    }
    uVar7 = *(undefined8 *)(param_2 + 4);
    plStack_38 = (long *)0x0;
    iVar1 = thunk_EXT_FUN_80110000039a3b60
                      (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x50) + 0x78) + 0x50),
                       param_2[2],&plStack_38);
    if ((iVar1 == 0) &&
       (plVar6 = (long *)thunk_EXT_FUN_8011000003890f30
                                   (plStack_38,*(undefined8 *)PTR_DAT_fffffff007ff2790),
       plVar6 != (long *)0x0)) {
      if (*(int *)(param_1 + 0x28) == 0) {
        uVar4 = thunk_EXT_FUN_8011000002c12750(plVar6);
        thunk_EXT_FUN_8011000002c12744(uVar4,uVar7);
        goto LAB_fffffff009959b28;
      }
      lVar2 = FUN_fffffff009958aec(param_1,3);
      if (lVar2 != 0) {
        (**(code **)(*plVar6 + 0x20))(plVar6);
        *(long **)(lVar2 + 0x30) = plVar6;
        *(undefined8 *)(lVar2 + 0x38) = uVar7;
LAB_fffffff009959d2c:
        *(undefined8 *)(lVar2 + 0x18) = 0;
        plVar6 = *(long **)(param_1 + 0x48);
        *(long **)(lVar2 + 0x20) = plVar6;
        *plVar6 = lVar2;
        *(undefined8 **)(param_1 + 0x48) = (undefined8 *)(lVar2 + 0x18);
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
        goto LAB_fffffff009959b28;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Failed to create IO Command Descriptor (kIOGPUIOCommandDescriptorTypeSignalEvent)\n"
                );
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: kIOGPUIOKernelCommandSignalSharedEvent: Invalid event port name: %d obj: %p\n"
                );
    }
  }
  else {
    if (iVar1 != 3) goto LAB_fffffff009959a14;
    if (uVar5 < 0x10) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Insufficient bytes (%llu) for sIOGPUIOKernelCommandSignalOrWaitEventArgs (%lu)\n"
                );
      goto LAB_fffffff009959d80;
    }
    uVar5 = *(ulong *)(param_2 + 4);
    plStack_38 = (long *)0x0;
    iVar1 = thunk_EXT_FUN_80110000039a3b60
                      (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x50) + 0x78) + 0x50),
                       param_2[2],&plStack_38);
    if ((iVar1 == 0) &&
       (plVar6 = (long *)thunk_EXT_FUN_8011000003890f30
                                   (plStack_38,*(undefined8 *)PTR_DAT_fffffff007ff2790),
       plVar6 != (long *)0x0)) {
      thunk_EXT_FUN_8011000002c12750();
      uVar3 = thunk_EXT_FUN_8011000002c13500();
      if (uVar5 <= uVar3) goto LAB_fffffff009959b28;
      lVar2 = FUN_fffffff009958aec(param_1,4);
      if (lVar2 != 0) {
        (**(code **)(*plVar6 + 0x20))(plVar6);
        *(long **)(lVar2 + 0x30) = plVar6;
        *(ulong *)(lVar2 + 0x38) = uVar5;
        *(undefined8 *)(lVar2 + 0x40) = 0;
        goto LAB_fffffff009959d2c;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Failed to create IO Command Descriptor (kIOGPUIOKernelCommandWaitSharedEvent)\n"
                );
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: kIOGPUIOKernelCommandWaitSharedEvent: Invalid event port name: %d obj: %p\n");
    }
  }
  *(undefined1 *)(param_1 + 0x5c) = 1;
LAB_fffffff009959b28:
  if (plStack_38 == (long *)0x0) {
    return;
  }
  (**(code **)(*plStack_38 + 0x28))();
  return;
}

