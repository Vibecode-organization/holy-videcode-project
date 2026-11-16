// FUN_fffffff00996c464 @ fffffff00996c464 size=184

void FUN_fffffff00996c464(long param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  code *pcVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong unaff_x30;
  
  FUN_fffffff009942d70();
  if ((*(byte *)(param_1 + 0xd0) & 1) != 0) {
    uVar6 = 0;
    do {
      uVar7 = *(ulong *)(*(long *)(param_1 + 0x98) + uVar6 * 8);
      if (uVar7 != 0) {
        do {
          uVar4 = (uVar7 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar7 & 0x5555555555555555) << 1;
          uVar4 = (uVar4 & 0xcccccccccccccccc) >> 2 | (uVar4 & 0x3333333333333333) << 2;
          uVar4 = (uVar4 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar4 = (uVar4 & 0xff00ff00ff00ff00) >> 8 | (uVar4 & 0xff00ff00ff00ff) << 8;
          uVar4 = (uVar4 & 0xffff0000ffff0000) >> 0x10 | (uVar4 & 0xffff0000ffff) << 0x10;
          uVar4 = LZCOUNT(uVar4 >> 0x20 | uVar4 << 0x20);
          uVar7 = uVar7 & (1L << (uVar4 & 0x3f) ^ 0xffffffffffffffffU);
          lVar5 = (uVar4 | (uint)((int)uVar6 << 6)) * 8;
          puVar2 = (undefined8 *)(*(long *)(param_1 + 0x80) + (long)(int)lVar5);
          if (lVar5 - (int)lVar5 != 0) {
            puVar2 = (undefined8 *)
                     (*(long *)(param_1 + 0x80) + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
          }
          FUN_fffffff009942c08(*puVar2);
        } while (uVar7 != 0);
      }
      uVar1 = (int)uVar6 + 1;
      uVar6 = (ulong)uVar1;
    } while (uVar1 <= *(uint *)(param_1 + 0xb0));
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996c518);
    (*pcVar3)();
  }
  FUN_fffffff009942d7c(param_1);
  return;
}

