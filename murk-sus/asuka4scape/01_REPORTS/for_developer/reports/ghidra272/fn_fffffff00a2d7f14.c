// FUN_fffffff00a2d7f14 @ fffffff00a2d7f14 size=296

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a2d7f14(long param_1)

{
  long *plVar1;
  ushort uVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = *(ushort *)(param_1 + 0x6c);
  uVar5 = uVar2 - 1;
  *(short *)(param_1 + 0x6c) = (short)uVar5;
  if (0xffff < uVar5) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("vm_object_paging_end(%p): underflow\n @%s:%d");
  }
  uVar5 = uVar5 & 0xffff;
  uVar4 = *(uint *)(param_1 + 0x74);
  if (((uVar4 >> 0xc & 1) == 0) &&
     (((*(byte *)(param_1 + 0xa9) & (uint)uVar2 == (uint)DAT_fffffff007bccab0) != 0 ||
      (DAT_fffffff007bccab2 == uVar2)))) {
    if ((uVar4 >> 6 & 1) != 0) {
      lVar3 = tpidr_el1;
      plVar1 = (long *)(_DAT_fffffff00ad0e458 + (ulong)*(ushort *)(lVar3 + 0x1b0) * 0x4000);
      lVar3 = *plVar1;
      *plVar1 = lVar3 + 1;
      FUN_fffffff00a24a024(lVar3,param_1 + 6,0,0);
      uVar4 = *(uint *)(param_1 + 0x74);
      uVar5 = (uint)*(ushort *)(param_1 + 0x6c);
    }
    uVar4 = uVar4 & 0xffffffbf;
    *(uint *)(param_1 + 0x74) = uVar4;
  }
  if (uVar5 == 0) {
    if ((uVar4 >> 5 & 1) != 0) {
      FUN_fffffff00a24a024(param_1 + 5,0,0);
      uVar4 = *(uint *)(param_1 + 0x74);
    }
    uVar5 = uVar4 & 0xffffffdf;
    *(uint *)(param_1 + 0x74) = uVar5;
    if (*(int *)(param_1 + 0x70) == 0) {
      if ((uVar4 >> 2 & 1) != 0) {
        FUN_fffffff00a24a024(param_1 + 2,0,0);
        uVar5 = *(uint *)(param_1 + 0x74);
      }
      *(uint *)(param_1 + 0x74) = uVar5 & 0xfffffffb;
    }
  }
  return;
}

