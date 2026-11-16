// FUN_fffffff008171bdc @ fffffff008171bdc size=404

undefined8
FUN_fffffff008171bdc
          (long param_1,undefined8 param_2,undefined8 param_3,long param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 local_48;
  
  if (*(uint *)(param_1 + 0x11168) < 2) {
    local_48 = 0;
    if (*(long *)(param_4 + 0x140) == 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x11e48));
      if (*(int *)(param_1 + 0x11ed0) == 0) {
        uVar5 = FUN_fffffff0081e14c4(param_1 + 0x11e40);
      }
      else {
        lVar2 = (ulong)(*(int *)(param_1 + 0x11ed0) - 1) * 8;
        puVar1 = (undefined8 *)(param_1 + 0x11e50 + (long)(int)lVar2);
        if (lVar2 != (int)lVar2) {
          puVar1 = (undefined8 *)(param_1 + 0x11e50 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar5 = *puVar1;
      }
      iVar3 = FUN_fffffff0081e12c4(uVar5,&local_48,param_2,param_3,param_5);
      if (iVar3 == 0) {
        if (*(int *)(param_1 + 0x11ed0) == 0) {
          *(undefined4 *)(param_1 + 0x11ed0) = 1;
          *(undefined8 *)(param_1 + 0x11e50) = uVar5;
        }
      }
      else {
        *(undefined8 *)(param_4 + 0x140) = uVar5;
        if (*(int *)(param_1 + 0x11ed0) != 0) {
          *(int *)(param_1 + 0x11ed0) = *(int *)(param_1 + 0x11ed0) + -1;
        }
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x11e48));
    }
    else {
      FUN_fffffff0081e12c4(*(long *)(param_4 + 0x140),&local_48,param_2,param_3);
    }
  }
  else {
    local_48 = 0;
    uVar4 = thunk_EXT_FUN_8011000002c2308c
                      (param_2,&local_48,param_3,*(undefined4 *)(param_1 + 0x100),0,0,0,0);
    if ((uVar4 & 1) == 0) {
      if ((*(byte *)(param_1 + 0x10a10) & 1) != 0) {
        uVar5 = thunk_EXT_FUN_8011000003a49114
                          (
                          "AGXk: %s:%d:%s: !!! Failed to create ioFence (0x%llx) on ioSurface (0x%llx, id: %d) in sync mode.\n\n"
                          );
        return uVar5;
      }
      local_48 = 0;
    }
  }
  return local_48;
}

