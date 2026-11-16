// FUN_fffffff009c41c14 @ fffffff009c41c14 size=312

/* WARNING: Removing unreachable block (ram,0xfffffff009c41ce0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c41c7c) */

undefined8
FUN_fffffff009c41c14(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  long lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
  lVar4 = *(long *)(param_1 + 0x10);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  iVar1 = FUN_fffffff009c41d4c
                    (*(undefined8 *)(*(long *)(param_1 + 0x20) + 0xf8),param_1 + 0x28,param_2,lVar4,
                     0x1001,0xd0,param_3);
  if (iVar1 == 0) {
    pcVar3 = "map_client_shared failed for client_shared_ro";
  }
  else {
    uVar6 = 0x1001;
    if ((*(byte *)(param_1 + 0x40) & 1) != 0) {
      uVar6 = 1;
    }
    lVar4 = *(long *)(param_1 + 0x10);
    if (lVar4 == 0) {
      lVar4 = 0;
    }
    uVar2 = FUN_fffffff009c41d4c
                      (*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x100),param_1 + 0x30,param_2,
                       lVar4,uVar6,0x40,param_4);
    if ((uVar2 & 1) != 0) {
      uVar5 = 1;
      goto LAB_fffffff009c41d2c;
    }
    pcVar3 = "map_client_shared failed for client_shared_rw";
  }
  thunk_EXT_FUN_80110000038fe9a0(pcVar3);
  uVar5 = 0;
LAB_fffffff009c41d2c:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
  return uVar5;
}

