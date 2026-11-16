// FUN_fffffff00994abdc @ fffffff00994abdc size=520

undefined8 FUN_fffffff00994abdc(long param_1,ulong param_2,int param_3)

{
  long lVar1;
  undefined8 *puVar2;
  int *piVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  int *piVar9;
  undefined8 local_48;
  
  uVar7 = (param_2 & 0xffffffff) << 3;
  uVar8 = -(param_2 >> 0x1f & 1) & 0xfffffff800000000 | uVar7;
  iVar4 = (int)uVar7;
  puVar2 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar4);
  if (uVar8 != (long)iVar4) {
    puVar2 = (undefined8 *)(*(long *)(param_1 + 0x20) + uVar8 & 0xffffffffffff | 0x2bad000000000000)
    ;
  }
  lVar1 = param_1 + 0x40;
  uVar7 = (long)(int)param_2 << 4 | 0xc;
  piVar3 = (int *)(lVar1 + (int)uVar7);
  if (uVar7 != (long)(int)uVar7) {
    piVar3 = (int *)(lVar1 + uVar7 & 0xffffffffffff | 0x2bad000000000000);
  }
  piVar9 = (int *)*puVar2;
  if (0 < param_3 - *piVar3) {
    FUN_fffffff0099616bc(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x160),5);
  }
  FUN_fffffff009975c34(*(undefined8 *)(param_1 + 0x10),0x100000000);
  lVar5 = *(long *)(param_1 + 0x10);
  if ((*(byte *)(lVar5 + 0x1fc) & 1) == 0) {
    iVar4 = *(int *)(lVar5 + 0x2d0);
    while( true ) {
      if (((iVar4 != 0) || (*(char *)(lVar5 + 0x1e0) < '\0')) || (param_3 - *piVar9 < 1))
      goto LAB_fffffff00994ad98;
      local_48 = 0;
      thunk_EXT_FUN_8011000003204ed8(1,1000000000,&local_48);
      iVar4 = thunk_EXT_FUN_8011000003243438(piVar9,0,local_48);
      if (param_3 - *piVar9 < 1) break;
      if (((iVar4 == -1) && (iVar4 = thunk_EXT_FUN_8011000003247bfc(0), iVar4 == 1)) &&
         (iVar4 = thunk_EXT_FUN_8011000003a12d84(0), iVar4 != 0)) {
        uVar7 = (ulong)*(uint *)(param_1 + 0x28);
        if (0 < (int)*(uint *)(param_1 + 0x28)) {
          lVar5 = 0;
          do {
            if (0 < *(int *)(lVar1 + (lVar5 << 4 | 8U)) -
                    **(int **)(*(long *)(param_1 + 0x20) + lVar5 * 8)) goto LAB_fffffff00994ad50;
            lVar5 = lVar5 + 1;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        if (0 < param_3 - *piVar9) {
          uVar6 = thunk_EXT_FUN_8011000003a49114
                            (
                            "\"IOGPUEventMachine::waitForStamp: Stamp test failed, but all submitted stamps are finished.  stamp[%08x]: %08x gpu_stamp: %08x\" @%s:%d"
                            );
          return uVar6;
        }
      }
LAB_fffffff00994ad50:
      lVar5 = *(long *)(param_1 + 0x10);
      iVar4 = *(int *)(lVar5 + 0x2d0);
    }
    thunk_EXT_FUN_8011000003246024(piVar9,0,0);
    lVar5 = *(long *)(param_1 + 0x10);
  }
  else {
    do {
      if ((param_3 - *piVar9 < 1) || (*(int *)(lVar5 + 0x2d0) != 0)) break;
    } while (-1 < *(char *)(lVar5 + 0x1e0));
  }
LAB_fffffff00994ad98:
  FUN_fffffff009975c44(lVar5,0x100000000);
  return 0;
}

