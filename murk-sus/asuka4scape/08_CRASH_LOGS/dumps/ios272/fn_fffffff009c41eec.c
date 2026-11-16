// FUN_fffffff009c41eec @ fffffff009c41eec size=180

/* WARNING: Removing unreachable block (ram,0xfffffff009c41f48) */

ulong FUN_fffffff009c41eec(long param_1,undefined8 param_2,undefined8 param_3)

{
  ulong uVar1;
  long lVar2;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
  lVar2 = *(long *)(param_1 + 0x10);
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  uVar1 = FUN_fffffff009c41d4c
                    (*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x130),param_1 + 0x38,param_2,lVar2
                     ,0x1001,8,param_3);
  if ((uVar1 & 1) == 0) {
    thunk_EXT_FUN_80110000038fe9a0("map_client_shared failed for event_shared_ro");
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
  return uVar1;
}

