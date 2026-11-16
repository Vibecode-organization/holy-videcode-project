// FUN_fffffff00a69a200 @ fffffff00a69a200 size=340

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff00a69a200(long param_1,uint *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_1 + 0x638);
  if (lVar7 + 1U < 2) {
    uVar4 = 0x16;
  }
  else {
    iVar3 = FUN_fffffff00a1ef400(lVar7 + 0x20);
    if (iVar3 == 0) {
      uVar4 = 0x10;
    }
    else {
      uVar4 = *(undefined8 *)(lVar7 + 0x80);
      uVar5 = (uint)*(undefined8 *)(lVar7 + 0x88);
      uVar5 = (uint)(ushort)((ulong)uVar4 >> 0x30) +
              ((uint)((ulong)uVar4 >> 0x10) & 0xffff) + ((uint)uVar4 & 0xffff) +
              ((uint)((ulong)uVar4 >> 0x20) & 0xffff) + (uVar5 & 0xffff) + (uVar5 >> 0x10) +
              ((uint)((ulong)*(undefined8 *)(lVar7 + 0x88) >> 0x20) & 1);
      *param_2 = (uint)*(ushort *)(lVar7 + 0x5a);
      param_2[1] = uVar5;
      param_2[2] = *(ushort *)(lVar7 + 0x56) - uVar5;
      param_2[3] = 0;
      bVar1 = _DAT_fffffff00acd4c6c <= *(ushort *)(lVar7 + 0x58);
      uVar5 = (uint)bVar1;
      uVar6 = (uint)bVar1;
      param_2[3] = uVar6;
      if (_DAT_fffffff00acd4c68 <= *(ushort *)(lVar7 + 0x5a)) {
        uVar5 = uVar6 | 2;
        param_2[3] = uVar5;
      }
      uVar2 = *(undefined4 *)(lVar7 + 0x132);
      uVar6 = (uint)*(ushort *)(lVar7 + 0x136);
      iVar3 = DAT_fffffff00ad93d94;
      if ((*(ushort *)(lVar7 + 0x136) & 8) != 0) {
        iVar3 = 1;
      }
      if (((uint)*(byte *)(lVar7 + 0x131) +
           (uint)(ushort)((ushort)(byte)uVar2 + (ushort)(byte)((uint)uVar2 >> 8) +
                          (ushort)(byte)((uint)uVar2 >> 0x10) + (ushort)(byte)((uint)uVar2 >> 0x18))
           + (uint)*(byte *)(lVar7 + 0x130) * 2 == iVar3) &&
         ((((*(long *)(lVar7 + 0x188) != 0 || (*(long *)(lVar7 + 0x178) != 0)) ||
           (*(long *)(lVar7 + 0x168) != 0)) ||
          (((*(long *)(lVar7 + 0x158) != 0 || (*(long *)(lVar7 + 0x148) != 0)) ||
           (*(long *)(lVar7 + 0x138) != 0)))))) {
        uVar5 = uVar5 | 8;
        param_2[3] = uVar5;
        uVar6 = (uint)*(ushort *)(lVar7 + 0x136);
      }
      if ((uVar6 >> 4 & 1) != 0) {
        param_2[3] = uVar5 | 0x10;
      }
      FUN_fffffff00a1ef5a8(lVar7 + 0x20);
      uVar4 = 0;
    }
  }
  return uVar4;
}

