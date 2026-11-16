// FUN_fffffff009c36818 @ fffffff009c36818 size=276

undefined8 FUN_fffffff009c36818(long param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 uVar6;
  undefined1 auStack_3c [4];
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  iVar1 = FUN_fffffff009c3692c
                    (param_1 + 0xf8,param_2,0xd0,*(undefined4 *)(param_1 + 0x1a8),auStack_3c,param_3
                    );
  if (iVar1 == 0) {
    pcVar3 = "IOSurfaceSharedRO alloc failed";
  }
  else {
    puVar4 = (undefined8 *)*param_3;
    puVar4[0x17] = 0;
    puVar4[0x16] = 0;
    puVar4[0x19] = 0;
    puVar4[0x18] = 0;
    puVar4[0x13] = 0;
    puVar4[0x12] = 0;
    puVar4[0x15] = 0;
    puVar4[0x14] = 0;
    puVar4[0xf] = 0;
    puVar4[0xe] = 0;
    puVar4[0x11] = 0;
    puVar4[0x10] = 0;
    puVar4[0xb] = 0;
    puVar4[10] = 0;
    puVar4[0xd] = 0;
    puVar4[0xc] = 0;
    puVar4[7] = 0;
    puVar4[6] = 0;
    puVar4[9] = 0;
    puVar4[8] = 0;
    puVar4[3] = 0;
    puVar4[2] = 0;
    puVar4[5] = 0;
    puVar4[4] = 0;
    puVar4[1] = 0;
    *puVar4 = 0;
    lVar5 = *param_3;
    *(undefined4 *)(lVar5 + 0x28) = 0x1000;
    uVar6 = 1;
    *(undefined4 *)(lVar5 + 0x20) = 1;
    uVar2 = FUN_fffffff009c3692c
                      (param_1 + 0x100,param_2,0x40,*(undefined4 *)(param_1 + 0x1a8),auStack_3c,
                       param_4);
    if ((uVar2 & 1) != 0) goto LAB_fffffff009c368f0;
    pcVar3 = "IOSurfaceSharedRW alloc failed";
  }
  thunk_EXT_FUN_80110000038fe9a0(pcVar3);
  uVar6 = 0;
LAB_fffffff009c368f0:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar6;
  }
  uVar6 = thunk_EXT_FUN_8011000003a48590();
  return uVar6;
}

