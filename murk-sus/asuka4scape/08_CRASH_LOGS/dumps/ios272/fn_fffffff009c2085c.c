// FUN_fffffff009c2085c @ fffffff009c2085c size=196

/* WARNING: Removing unreachable block (ram,0xfffffff009c208fc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c208b4) */

undefined4 FUN_fffffff009c2085c(long param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  lVar3 = *(long *)(param_1 + 0x178);
  if (param_3 != 0) {
    *(int *)(lVar3 + 0xc) = *(int *)(lVar3 + 0xc) + 1;
  }
  uVar2 = 0x1c;
  if (param_2 == 0) {
    uVar2 = 0xc;
  }
  *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | uVar2;
  uVar1 = *(undefined4 *)(lVar3 + 0xc);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  return uVar1;
}

