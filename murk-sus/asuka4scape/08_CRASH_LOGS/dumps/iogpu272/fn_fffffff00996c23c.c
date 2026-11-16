// FUN_fffffff00996c23c @ fffffff00996c23c size=552

/* WARNING: Removing unreachable block (ram,0xfffffff00996c514) */

undefined8 FUN_fffffff00996c23c(long *param_1,ulong param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  uint uVar13;
  ulong uVar14;
  undefined8 local_68;
  
  if ((int)param_1[0x22] != 0) {
LAB_fffffff00996c460:
    lVar11 = FUN_fffffff009983f44();
    FUN_fffffff009942d70();
    if ((*(byte *)(lVar11 + 0xd0) & 1) != 0) {
      uVar14 = 0;
      do {
        uVar12 = *(ulong *)(*(long *)(lVar11 + 0x98) + uVar14 * 8);
        if (uVar12 != 0) {
          do {
            uVar10 = (uVar12 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar12 & 0x5555555555555555) << 1;
            uVar10 = (uVar10 & 0xcccccccccccccccc) >> 2 | (uVar10 & 0x3333333333333333) << 2;
            uVar10 = (uVar10 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar10 = (uVar10 & 0xff00ff00ff00ff00) >> 8 | (uVar10 & 0xff00ff00ff00ff) << 8;
            uVar10 = (uVar10 & 0xffff0000ffff0000) >> 0x10 | (uVar10 & 0xffff0000ffff) << 0x10;
            uVar10 = LZCOUNT(uVar10 >> 0x20 | uVar10 << 0x20);
            uVar12 = uVar12 & (1L << (uVar10 & 0x3f) ^ 0xffffffffffffffffU);
            lVar9 = (uVar10 | (uint)((int)uVar14 << 6)) * 8;
            puVar2 = (undefined8 *)(*(long *)(lVar11 + 0x80) + (long)(int)lVar9);
            if (lVar9 - (int)lVar9 != 0) {
              puVar2 = (undefined8 *)
                       (*(long *)(lVar11 + 0x80) + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
            }
            FUN_fffffff009942c08(*puVar2);
          } while (uVar12 != 0);
        }
        uVar8 = (int)uVar14 + 1;
        uVar14 = (ulong)uVar8;
      } while (uVar8 <= *(uint *)(lVar11 + 0xb0));
    }
    uVar4 = FUN_fffffff009942d7c(lVar11);
    return uVar4;
  }
  if (DAT_fffffff00af227e8 != 0) {
    uVar4 = (**(code **)(*param_1 + 0xe0))(param_1);
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar4,&local_68);
    uVar4 = local_68;
    lVar11 = param_1[5];
    uVar5 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
    thunk_EXT_FUN_80110000036da494(0x851801c9,uVar4,lVar11,param_2,uVar5,0);
  }
  if (((*(byte *)((long)param_1 + 0x24) >> 1 & 1) == 0) || ((param_1[5] & param_2) != 0)) {
    uVar4 = 0;
  }
  else if ((*(byte *)(param_1 + 0x1a) & 1) == 0) {
    uVar4 = 0xe00002bc;
  }
  else {
    uVar13 = 0;
    uVar8 = 0;
    uVar14 = 0;
    uVar3 = *(uint *)(param_1 + 0x17);
    do {
      uVar12 = *(ulong *)(param_1[0x13] + uVar14 * 8);
      if (uVar12 != 0) {
        do {
          uVar10 = (uVar12 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar12 & 0x5555555555555555) << 1;
          uVar10 = (uVar10 & 0xcccccccccccccccc) >> 2 | (uVar10 & 0x3333333333333333) << 2;
          uVar10 = (uVar10 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar10 = (uVar10 & 0xff00ff00ff00ff00) >> 8 | (uVar10 & 0xff00ff00ff00ff) << 8;
          uVar10 = (uVar10 & 0xffff0000ffff0000) >> 0x10 | (uVar10 & 0xffff0000ffff) << 0x10;
          uVar10 = LZCOUNT(uVar10 >> 0x20 | uVar10 << 0x20);
          if (uVar8 < uVar3) {
            lVar11 = (uVar10 | (uint)((int)uVar14 << 6)) * 8;
            puVar2 = (undefined8 *)(param_1[0x10] + (long)(int)lVar11);
            if (lVar11 - (int)lVar11 != 0) {
              puVar2 = (undefined8 *)(param_1[0x10] + lVar11 & 0xffffffffffffU | 0x2bad000000000000)
              ;
            }
            uVar5 = *puVar2;
            uVar7 = FUN_fffffff0099437e4(uVar5);
            if ((uVar7 & 1) == 0) {
              FUN_fffffff009983f74();
              goto LAB_fffffff00996c460;
            }
            uVar4 = FUN_fffffff0099436e4(uVar5,param_2);
            if ((int)uVar4 != 0) goto LAB_fffffff00996c300;
            FUN_fffffff0099437a0(uVar5);
            uVar8 = uVar13 + 1;
            uVar13 = uVar8;
          }
          uVar12 = uVar12 & (1L << (uVar10 & 0x3f) ^ 0xffffffffffffffffU);
        } while (uVar12 != 0);
      }
      uVar1 = (int)uVar14 + 1;
      uVar14 = (ulong)uVar1;
    } while (uVar1 <= *(uint *)(param_1 + 0x16));
    uVar4 = 0;
  }
LAB_fffffff00996c300:
  if (DAT_fffffff00af227e8 != 0) {
    uVar5 = (**(code **)(*param_1 + 0xe0))(param_1);
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar5,&local_68);
    uVar5 = local_68;
    uVar6 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
    thunk_EXT_FUN_80110000036da494(0x851801ca,uVar5,(int)uVar4 == 0,param_2,uVar6,0);
  }
  return uVar4;
}

