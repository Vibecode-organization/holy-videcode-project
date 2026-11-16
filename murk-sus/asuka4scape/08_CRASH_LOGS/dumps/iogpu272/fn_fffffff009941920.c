// FUN_fffffff009941920 @ fffffff009941920 size=1212

/* WARNING: Removing unreachable block (ram,0xfffffff009941b1c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009941d68) */

undefined8 FUN_fffffff009941920(long *param_1,ulong param_2,long *param_3)

{
  uint uVar1;
  long *plVar2;
  undefined8 *puVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  long *plVar9;
  ulong uVar10;
  
  if (*(uint *)(param_1 + 0x14) <= (uint)param_2) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid Index (%u), Capacity (%u)\n")
    ;
    return 0xe00002c2;
  }
  uVar1 = *(uint *)(param_1 + 6) & (*(uint *)(param_1[2] + 0x1fc) & 0x3fff) >> 0xd;
  uVar10 = param_2 & 0xffffffff;
  lVar7 = (param_2 & 0xffffffff) * 8;
  puVar3 = (undefined8 *)(param_1[0x13] + (long)(int)lVar7);
  if (lVar7 != (int)lVar7) {
    puVar3 = (undefined8 *)(param_1[0x13] + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
  }
  plVar9 = (long *)*puVar3;
  uVar4 = FUN_fffffff0099437e4();
  if (param_3 != (long *)0x0) {
    if ((uVar4 & 1) != 0) {
      if ((*(byte *)(param_1 + 0x1a) & 1) == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = (**(code **)(*param_3 + 0xb0))(param_3);
      }
      lVar7 = param_1[2];
      uVar4 = *(uint *)(lVar7 + 0x1f0);
      if (plVar9 == (long *)0x0) {
        if ((*(byte *)(param_1 + 6) >> 2 & 1) == 0) {
          iVar5 = FUN_fffffff0099758f0(lVar7,uVar6,uVar1);
          if (iVar5 == 0) {
            return 0xe00002be;
          }
        }
        else {
          FUN_fffffff0099758c4(lVar7,uVar6,uVar1);
        }
      }
      uVar8 = (**(code **)(*param_3 + 0xd8))(param_3,uVar4 >> 2 & 0x20);
      if ((int)uVar8 != 0) {
        FUN_fffffff0099758d8(param_1[2],uVar6,uVar1);
        return uVar8;
      }
      uVar6 = (**(code **)(*param_1 + 0x100))(param_1,param_2,plVar9,param_3);
      if ((int)uVar6 != 0) {
        (**(code **)(*param_3 + 0xe0))(param_3,0);
        return uVar6;
      }
      if (plVar9 != (long *)0x0) {
        (**(code **)(*plVar9 + 0xe0))(plVar9,0);
      }
    }
    (**(code **)(*param_3 + 0x20))(param_3);
    if (plVar9 == (long *)0x0) {
      lVar7 = (**(code **)(*param_3 + 0xb0))(param_3);
      param_1[0x10] = param_1[0x10] + lVar7;
      *(int *)((long)param_1 + 0xa4) = *(int *)((long)param_1 + 0xa4) + 1;
    }
    lVar7 = uVar10 * 8;
    plVar2 = (long *)(param_1[0x13] + (long)(int)lVar7);
    if (lVar7 - (int)lVar7 != 0) {
      plVar2 = (long *)(param_1[0x13] + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *plVar2 = (long)param_3;
    uVar10 = uVar10 >> 3 & 0x1ffffff8;
    *(ulong *)(param_1[0x15] + uVar10) = *(ulong *)(param_1[0x15] + uVar10) | 1L << (param_2 & 0x3f)
    ;
    (**(code **)(*param_1 + 0x128))(*param_1 + 0x128,param_1,param_2,0xff);
    if (plVar9 == (long *)0x0) {
      return 0;
    }
    (**(code **)(*plVar9 + 0x28))(plVar9);
    return 0;
  }
  if (uVar4 == 0) {
LAB_fffffff009941a58:
    if (plVar9 == (long *)0x0) goto LAB_fffffff009941d08;
  }
  else {
    uVar6 = (**(code **)(*param_1 + 0x100))(param_1,param_2,plVar9,0);
    if ((int)uVar6 != 0 || plVar9 == (long *)0x0) {
      if ((int)uVar6 != 0) {
        return uVar6;
      }
      goto LAB_fffffff009941a58;
    }
    if ((*(byte *)(param_1 + 0x1a) & 1) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (**(code **)(*plVar9 + 0xb0))(plVar9);
    }
    (**(code **)(*plVar9 + 0xe0))(plVar9,0);
    FUN_fffffff0099758d8(param_1[2],uVar6,uVar1);
  }
  lVar7 = (**(code **)(*plVar9 + 0xb0))(plVar9);
  param_1[0x10] = param_1[0x10] - lVar7;
  *(int *)((long)param_1 + 0xa4) = *(int *)((long)param_1 + 0xa4) + -1;
  (**(code **)(*plVar9 + 0x28))(plVar9);
LAB_fffffff009941d08:
  lVar7 = uVar10 * 8;
  puVar3 = (undefined8 *)(param_1[0x13] + (long)(int)lVar7);
  if (lVar7 - (int)lVar7 != 0) {
    puVar3 = (undefined8 *)(param_1[0x13] + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar3 = 0;
  uVar10 = uVar10 >> 3 & 0x1ffffff8;
  *(ulong *)(param_1[0x15] + uVar10) =
       *(ulong *)(param_1[0x15] + uVar10) & (1L << (param_2 & 0x3f) ^ 0xffffffffffffffffU);
  (**(code **)(*param_1 + 0x128))(*param_1 + 0x128,param_1,param_2,0);
  return 0;
}

