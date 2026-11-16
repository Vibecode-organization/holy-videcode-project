// FUN_fffffff009c20920 @ fffffff009c20920

/* WARNING: Removing unreachable block (ram,0xfffffff009c20998) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c20950) */

undefined4 FUN_fffffff009c20920(long param_1,int param_2,int param_3)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = *(long *)(param_1 + 0x178);
  if (param_3 != 0) {
    *(int *)(lVar1 + 0xc) = *(int *)(lVar1 + 0xc) + 1;
  }
  uVar2 = 0x1c;
  if (param_2 == 0) {
    uVar2 = 0xc;
  }
  *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | uVar2;
  return *(undefined4 *)(lVar1 + 0xc);
}

