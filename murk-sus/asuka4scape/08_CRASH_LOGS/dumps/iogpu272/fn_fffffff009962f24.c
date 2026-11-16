// FUN_fffffff009962f24 @ fffffff009962f24 size=104

undefined4 FUN_fffffff009962f24(long param_1,long param_2)

{
  long lVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x58));
  lVar1 = (long)*(int *)(param_2 + 0x424) * 0x18 + 0xc;
  puVar2 = (undefined4 *)(*(long *)(param_1 + 0x48) + (long)(int)lVar1);
  if (lVar1 != (int)lVar1) {
    puVar2 = (undefined4 *)
             (*(long *)(param_1 + 0x48) + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar3 = *puVar2;
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x58));
  return uVar3;
}

