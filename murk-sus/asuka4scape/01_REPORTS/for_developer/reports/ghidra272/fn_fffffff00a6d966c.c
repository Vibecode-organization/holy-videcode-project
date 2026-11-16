// FUN_fffffff00a6d966c @ fffffff00a6d966c size=800

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff00a6d966c(long param_1,uint *param_2)

{
  bool bVar1;
  int *piVar2;
  long lVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  long lVar9;
  uint uVar10;
  long lVar11;
  long lVar12;
  int in_wzr;
  undefined8 local_38;
  
  lVar3 = tpidr_el1;
  if (*(ulong *)(param_1 + 0x58) == 0) {
    *(ulong *)(param_1 + 0x58) = (ulong)*(uint *)(lVar3 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(param_1 + 0x50,lVar3,0);
  }
  lVar12 = *(long *)(param_1 + 0x638);
  if (lVar12 + 1U < 2) {
    if (*(int *)(param_1 + 0x58) == *(int *)(lVar3 + 0x4e8)) {
      *(int *)(param_1 + 0x58) = in_wzr;
      uVar8 = 0x16;
    }
    else {
      FUN_fffffff00a226e08(param_1 + 0x50,lVar3);
      uVar8 = 0x16;
    }
  }
  else {
    piVar2 = (int *)(lVar12 + 0x38);
    iVar6 = *piVar2;
    *piVar2 = iVar6 + 1;
    if (iVar6 + 0xf0000001U < 0xf0000002) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ed0(piVar2);
    }
    if (*(int *)(param_1 + 0x58) == *(int *)(lVar3 + 0x4e8)) {
      *(int *)(param_1 + 0x58) = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(param_1 + 0x50,lVar3);
    }
    *(int *)(lVar3 + 0x1c0) = *(int *)(lVar3 + 0x1c0) + 1;
    LOAcquire();
    uVar7 = *(uint *)(lVar12 + 0x28);
    *(uint *)(lVar12 + 0x28) = uVar7 + 0x1000000;
    if ((uVar7 >> 0x10 & 0xff) == uVar7 >> 0x18) {
      *(undefined4 *)(lVar12 + 0x2c) = *(undefined4 *)(lVar3 + 0x4e8);
    }
    else {
      FUN_fffffff00a22b5a8(lVar12 + 0x20,uVar7 >> 0x18,lVar3);
    }
    uVar8 = *(undefined8 *)(lVar12 + 0x80);
    uVar7 = (uint)*(undefined8 *)(lVar12 + 0x88);
    uVar7 = (uint)(ushort)((ulong)uVar8 >> 0x30) +
            ((uint)((ulong)uVar8 >> 0x10) & 0xffff) + ((uint)uVar8 & 0xffff) +
            ((uint)((ulong)uVar8 >> 0x20) & 0xffff) + (uVar7 & 0xffff) + (uVar7 >> 0x10) +
            ((uint)((ulong)*(undefined8 *)(lVar12 + 0x88) >> 0x20) & 1);
    *param_2 = (uint)*(ushort *)(lVar12 + 0x5a);
    param_2[1] = uVar7;
    param_2[2] = *(ushort *)(lVar12 + 0x56) - uVar7;
    param_2[3] = 0;
    bVar1 = _DAT_fffffff00ad14c6c <= *(ushort *)(lVar12 + 0x58);
    uVar7 = (uint)bVar1;
    uVar10 = (uint)bVar1;
    param_2[3] = uVar10;
    if (_DAT_fffffff00ad14c68 <= *(ushort *)(lVar12 + 0x5a)) {
      uVar7 = uVar10 | 2;
      param_2[3] = uVar7;
    }
    uVar5 = *(undefined4 *)(lVar12 + 0x132);
    uVar10 = (uint)*(ushort *)(lVar12 + 0x136);
    iVar6 = DAT_fffffff00add3e74;
    if ((*(ushort *)(lVar12 + 0x136) & 8) != 0) {
      iVar6 = 1;
    }
    if (((uint)*(byte *)(lVar12 + 0x131) +
         (uint)(ushort)((ushort)(byte)uVar5 + (ushort)(byte)((uint)uVar5 >> 8) +
                        (ushort)(byte)((uint)uVar5 >> 0x10) + (ushort)(byte)((uint)uVar5 >> 0x18)) +
         (uint)*(byte *)(lVar12 + 0x130) * 2 == iVar6) &&
       ((((*(long *)(lVar12 + 0x188) != 0 || (*(long *)(lVar12 + 0x178) != 0)) ||
         (*(long *)(lVar12 + 0x168) != 0)) ||
        (((*(long *)(lVar12 + 0x158) != 0 || (*(long *)(lVar12 + 0x148) != 0)) ||
         (*(long *)(lVar12 + 0x138) != 0)))))) {
      uVar7 = uVar7 | 8;
      param_2[3] = uVar7;
      uVar10 = (uint)*(ushort *)(lVar12 + 0x136);
    }
    if ((uVar10 >> 4 & 1) != 0) {
      param_2[3] = uVar7 | 0x10;
    }
    FUN_fffffff00a22b850(lVar12 + 0x20);
    iVar6 = *(int *)(lVar12 + 0x38);
    *(int *)(lVar12 + 0x38) = iVar6 + -1;
    if (iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ea0();
    }
    if (iVar6 == 1) {
      local_38 = 0;
      lVar9 = *(long *)(lVar12 + 0x18);
      lVar11 = *(long *)(lVar9 + 0x18);
      if (lVar11 == 0) {
        uVar8 = 0;
        *(undefined8 *)(lVar12 + 0x18) = 0;
      }
      else {
        *(undefined8 *)(lVar9 + 0x18) = *(undefined8 *)(lVar11 + 0x18);
        *(undefined8 *)(lVar11 + 0x18) = 0;
        uVar8 = *(undefined8 *)(lVar12 + 0x18);
        lVar9 = lVar11;
      }
      FUN_fffffff00a28646c(lVar12,lVar3,lVar9,uVar8,&local_38);
      FUN_fffffff00a287c08();
      FUN_fffffff00a285dac(local_38);
      if (*(uint *)(lVar12 + 0x20) >> 0x18 != 0x44) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa51020(lVar12 + 0x20);
      }
      *(uint *)(lVar12 + 0x20) = *(uint *)(lVar12 + 0x20) & 0xffffff;
      *(undefined4 *)(lVar12 + 0x28) = 0;
      lVar3 = *DAT_fffffff007c063a0;
      lVar9 = DAT_fffffff007c063a0[1];
      uVar4 = *(undefined2 *)(lVar3 + 0x34);
      FUN_fffffff00aa65cc0(lVar12,uVar4);
      FUN_fffffff00a29223c(lVar3,lVar9,lVar12,uVar4);
    }
    uVar8 = 0;
  }
  return uVar8;
}

