// FUN_fffffff0081cb094 @ fffffff0081cb094 size=508

/* WARNING: Removing unreachable block (ram,0xfffffff0081cb200) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cb16c) */

undefined8 FUN_fffffff0081cb094(long param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 local_38;
  
  *(undefined1 *)(param_1 + 0x1488) = 0;
  *(undefined1 *)(param_1 + 0x14e9) = 0;
  iVar3 = (**(code **)(**(long **)(param_1 + 0x1460) + 0x548))
                    (*(long **)(param_1 + 0x1460),*(undefined8 *)(param_1 + 0x1480));
  if (iVar3 == 0) {
LAB_fffffff0081cb248:
    uVar6 = 0;
  }
  else {
    if ((*(byte *)(param_1 + 0x14e9) & 1) == 0) {
      uVar7 = 0;
      iVar1 = *(int *)(*(long *)(param_1 + 0x280) + 0x10950);
      iVar3 = *(int *)(*(long *)(param_1 + 0x280) + 0x23c);
      if (iVar1 != 0) {
        iVar3 = iVar1;
      }
      uVar2 = iVar3 * 1000;
      if (uVar2 < 0x32) {
        uVar2 = 0x32;
      }
      do {
        local_38 = 0;
        thunk_EXT_FUN_8011000003204ed8(0x32,1000000,&local_38);
        plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
        lVar5 = *plVar4;
        iVar3 = (**(code **)(lVar5 + 0x110))(lVar5 + 0x110,plVar4,param_1 + 0x14e9,local_38,0);
        if ((*(byte *)(param_1 + 0x14e9) & 1) != 0) break;
        if (iVar3 != 1) goto LAB_fffffff0081cb248;
        uVar7 = uVar7 + 0x32;
        if (uVar2 <= uVar7) {
          iVar3 = *(int *)(*(long *)(param_1 + 0x280) + 0x10950);
          thunk_EXT_FUN_8011000003397c88();
          if (iVar3 != 0) {
            thunk_EXT_FUN_8011000003397c88();
            uVar6 = thunk_EXT_FUN_8011000003a49114
                              (
                              "AGXk: %s:%d:%s: !!! Timeout while waiting for the GPU firmware to come up (%us) at timestamp %llu\n"
                              );
            return uVar6;
          }
          goto LAB_fffffff0081cb248;
        }
      } while ((*(byte *)(param_1 + 0x14e9) & 1) == 0);
    }
    uVar6 = 1;
    *(undefined1 *)(param_1 + 0x290) = 1;
    (**(code **)(**(long **)(param_1 + 0x280) + 0x38))();
    thunk_EXT_FUN_8011000003891b28();
    (**(code **)(**(long **)(param_1 + 0x280) + 0x720))(**(long **)(param_1 + 0x280) + 0x720);
  }
  return uVar6;
}

