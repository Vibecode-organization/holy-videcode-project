// FUN_fffffff00994d3bc @ fffffff00994d3bc size=92

bool FUN_fffffff00994d3bc(undefined8 param_1,uint *param_2,int param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  
  uVar2 = *param_2 | 0x8000;
  do {
    uVar3 = (uVar2 & 0xaaaaaaaa) >> 1 | (uVar2 & 0x55555555) << 1;
    uVar3 = (uVar3 & 0xcccccccc) >> 2 | (uVar3 & 0x33333333) << 2;
    uVar3 = (uVar3 & 0xf0f0f0f0) >> 4 | (uVar3 & 0xf0f0f0f) << 4;
    uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
    lVar4 = LZCOUNT(uVar3 >> 0x10 | uVar3 << 0x10);
    uVar3 = (uint)lVar4;
    if (0xe < uVar3) goto LAB_fffffff00994d40c;
    uVar2 = 1 << (ulong)(uVar3 & 0x1f) ^ uVar2;
    uVar1 = param_2[lVar4 + 1];
  } while ((uVar1 & 0xff) == 0xff || (char)uVar1 != param_3);
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar1 & 0xffffff00;
  }
LAB_fffffff00994d40c:
  return uVar3 < 0xf;
}

