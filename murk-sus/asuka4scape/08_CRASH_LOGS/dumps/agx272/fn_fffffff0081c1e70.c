// FUN_fffffff0081c1e70 @ fffffff0081c1e70 size=1116

/* WARNING: Type propagation algorithm not settling */

undefined8
FUN_fffffff0081c1e70
          (long param_1,uint param_2,int *param_3,uint param_4,int param_5,int param_6,int param_7)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  
  if (param_7 == 0) {
    uVar3 = param_4;
    if (param_4 == 0xffffffff) {
      uVar3 = *(uint *)(param_1 + 0x1898);
    }
    uVar3 = uVar3 & ((int)uVar3 >> 0x1f ^ 0xffffffffU);
    piVar1 = (int *)(param_1 + 0x1858);
    if ((param_2 & 1) != 0) {
      piVar1 = param_3;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x185c);
    if ((param_2 & 2) != 0) {
      piVar1 = param_3 + 1;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x1860);
    if ((param_2 & 4) != 0) {
      piVar1 = param_3 + 2;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x1864);
    if ((param_2 & 8) != 0) {
      piVar1 = param_3 + 3;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x1868);
    if ((param_2 & 0x10) != 0) {
      piVar1 = param_3 + 4;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x186c);
    if ((param_2 & 0x20) != 0) {
      piVar1 = param_3 + 5;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x1870);
    if ((param_2 & 0x40) != 0) {
      piVar1 = param_3 + 6;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x1874);
    if ((param_2 & 0x80) != 0) {
      piVar1 = param_3 + 7;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x1878);
    if ((param_2 & 0x100) != 0) {
      piVar1 = param_3 + 8;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x187c);
    if ((param_2 & 0x200) != 0) {
      piVar1 = param_3 + 9;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x1880);
    if ((param_2 & 0x400) != 0) {
      piVar1 = param_3 + 10;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x1884);
    if ((param_2 & 0x800) != 0) {
      piVar1 = param_3 + 0xb;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x1888);
    if ((param_2 & 0x1000) != 0) {
      piVar1 = param_3 + 0xc;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x188c);
    if ((param_2 & 0x2000) != 0) {
      piVar1 = param_3 + 0xd;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x1890);
    if ((param_2 & 0x4000) != 0) {
      piVar1 = param_3 + 0xe;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    piVar1 = (int *)(param_1 + 0x1894);
    if ((param_2 & 0x8000) != 0) {
      piVar1 = param_3 + 0xf;
    }
    if (*piVar1 <= (int)uVar3) {
      return 0xe00002c2;
    }
    if ((param_2 & 1) != 0) {
      iVar2 = *param_3;
      *(int *)(param_1 + 0x1858) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x4fc) = iVar2;
    }
    if ((param_2 >> 1 & 1) != 0) {
      iVar2 = param_3[1];
      *(int *)(param_1 + 0x185c) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x500) = iVar2;
    }
    if ((param_2 >> 2 & 1) != 0) {
      iVar2 = param_3[2];
      *(int *)(param_1 + 0x1860) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x504) = iVar2;
    }
    if ((param_2 >> 3 & 1) != 0) {
      iVar2 = param_3[3];
      *(int *)(param_1 + 0x1864) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x508) = iVar2;
    }
    if ((param_2 >> 4 & 1) != 0) {
      iVar2 = param_3[4];
      *(int *)(param_1 + 0x1868) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x50c) = iVar2;
    }
    if ((param_2 >> 5 & 1) != 0) {
      iVar2 = param_3[5];
      *(int *)(param_1 + 0x186c) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x510) = iVar2;
    }
    if ((param_2 >> 6 & 1) != 0) {
      iVar2 = param_3[6];
      *(int *)(param_1 + 0x1870) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x514) = iVar2;
    }
    if ((param_2 >> 7 & 1) != 0) {
      iVar2 = param_3[7];
      *(int *)(param_1 + 0x1874) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x518) = iVar2;
    }
    if ((param_2 >> 8 & 1) != 0) {
      iVar2 = param_3[8];
      *(int *)(param_1 + 0x1878) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x51c) = iVar2;
    }
    if ((param_2 >> 9 & 1) != 0) {
      iVar2 = param_3[9];
      *(int *)(param_1 + 0x187c) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x520) = iVar2;
    }
    if ((param_2 >> 10 & 1) != 0) {
      iVar2 = param_3[10];
      *(int *)(param_1 + 0x1880) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x524) = iVar2;
    }
    if ((param_2 >> 0xb & 1) != 0) {
      iVar2 = param_3[0xb];
      *(int *)(param_1 + 0x1884) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x528) = iVar2;
    }
    if ((param_2 >> 0xc & 1) != 0) {
      iVar2 = param_3[0xc];
      *(int *)(param_1 + 0x1888) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x52c) = iVar2;
    }
    if ((param_2 >> 0xd & 1) != 0) {
      iVar2 = param_3[0xd];
      *(int *)(param_1 + 0x188c) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x530) = iVar2;
    }
    if ((param_2 >> 0xe & 1) != 0) {
      iVar2 = param_3[0xe];
      *(int *)(param_1 + 0x1890) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x534) = iVar2;
    }
    if ((param_2 >> 0xf & 1) != 0) {
      iVar2 = param_3[0xf];
      *(int *)(param_1 + 0x1894) = iVar2;
      *(int *)(*(long *)(param_1 + 0x918) + 0x538) = iVar2;
    }
    if (param_4 != 0xffffffff) {
      *(uint *)(param_1 + 0x1898) = param_4;
    }
    if (param_5 != -1) {
      *(int *)(param_1 + 0x189c) = param_5;
    }
    if (param_6 != -1) {
      *(int *)(param_1 + 0x18a0) = param_6;
    }
  }
  else {
    (**(code **)(**(long **)(param_1 + 0x280) + 0x9c8))
              (*(long **)(param_1 + 0x280),param_1 + 0x1858);
  }
  lVar4 = *(long *)(param_1 + 0x918);
  *(undefined4 *)(lVar4 + 0x4f4) = *(undefined4 *)(param_1 + 0x1898);
  *(undefined4 *)(lVar4 + 0x4f8) = *(undefined4 *)(param_1 + 0x189c);
  *(undefined4 *)(lVar4 + 0x53c) = *(undefined4 *)(param_1 + 0x18a0);
  *(undefined4 *)(lVar4 + 0x4ec) = 1;
  return 0;
}

