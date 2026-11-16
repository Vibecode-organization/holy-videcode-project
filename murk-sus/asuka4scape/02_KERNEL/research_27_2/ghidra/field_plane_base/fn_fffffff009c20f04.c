// FUN_fffffff009c20f04 @ fffffff009c20f04

/* WARNING: Removing unreachable block (ram,0xfffffff009c21014) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2105c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c20f78) */

undefined8
FUN_fffffff009c20f04
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7,ulong param_8,undefined4 *param_9)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  long local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x50));
  if ((param_8 & 1) == 0) {
    if (*(int *)(param_7 + 0x23c) == 0) {
LAB_fffffff009c21084:
      uVar3 = 0xe00002c2;
      thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x50));
      goto LAB_fffffff009c21094;
    }
    *(int *)(param_7 + 0x23c) = *(int *)(param_7 + 0x23c) + -1;
    *(int *)(*(long *)(param_7 + 0x178) + 0x10) = *(int *)(*(long *)(param_7 + 0x178) + 0x10) + 1;
    iVar2 = *(int *)(param_7 + 0x9c);
    if (((iVar2 == 0x200) || (iVar2 == 0x400)) || (iVar2 == 0x700)) {
      thunk_FUN_fffffff00a394134();
      iVar2 = *(int *)(param_7 + 0x9c);
    }
    uVar1 = iVar2 - 0x100U >> 8;
    if (6 < (uVar1 | iVar2 << 0x18) || (1 << (ulong)(uVar1 & 0x1f) & 0x4bU) == 0) {
      *(uint *)(param_7 + 0x3d0) = *(uint *)(param_7 + 0x3d0) | 0x20;
    }
  }
  else {
    if (*(int *)(param_7 + 0x238) == 0) goto LAB_fffffff009c21084;
    *(int *)(param_7 + 0x238) = *(int *)(param_7 + 0x238) + -1;
  }
  if (param_9 != (undefined4 *)0x0) {
    *param_9 = *(undefined4 *)(*(long *)(param_7 + 0x178) + 0xc);
  }
  local_40 = 0;
  auVar4 = thunk_FUN_fffffff00a2df760(*(ulong *)(param_7 + 0x30),&local_40);
  thunk_FUN_fffffff00a6de494
            (auVar4,param_2,param_3,param_4,param_5,param_6,0x85210014,local_40,
             (ulong)*(uint *)(param_7 + 0x10),param_8 & 0xffffffff,
             (ulong)*(uint *)(*(long *)(param_7 + 0x178) + 0xc));
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x50));
  uVar3 = 0;
LAB_fffffff009c21094:
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar3;
}

