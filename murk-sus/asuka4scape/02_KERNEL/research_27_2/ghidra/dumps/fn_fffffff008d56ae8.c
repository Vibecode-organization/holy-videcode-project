// FUN_fffffff008d56ae8 @ fffffff008d56ae8 size=376
// CALLERS:
//   fffffff00afb95ec no-fn
//   fffffff008d56d8c FUN_fffffff008d56c68@fffffff008d56c68
// CALLEES:
//   fffffff008cd5954 FUN_fffffff008cd5954
//   fffffff008df4208 FUN_fffffff008df4208

void FUN_fffffff008d56ae8(undefined8 param_1,long param_2,ulong param_3)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = (uint)(param_3 >> 0x20);
  *(byte *)(param_2 + 0xd0a) = (byte)(uVar2 >> 3) & 1;
  uVar5 = (uint)param_3;
  *(uint *)(param_2 + 0x40) = uVar5 & 0x3f;
  bVar1 = (byte)(uVar5 >> 6) & 1;
  *(byte *)(param_2 + 0x39) = bVar1;
  *(byte *)(param_2 + 0x38) = bVar1;
  *(byte *)(param_2 + 0x3c) = (byte)(uVar5 >> 7) & 1;
  *(byte *)(param_2 + 0x3d) = (byte)(param_3 >> 8) & 1;
  if ((uVar5 >> 0xc & 1) != 0) {
    *(undefined1 *)(param_2 + 0xa18) = 1;
  }
  *(uint *)(param_2 + 0xa1c) = uVar5 >> 0xd & 3;
  *(uint *)(param_2 + 0xc30) = uVar5 >> 0xf & 7;
  *(byte *)(param_2 + 0xc34) = (byte)(uVar5 >> 0x12) & 1;
  *(byte *)(param_2 + 0xc3c) = (byte)(uVar2 >> 0x11) & 1;
  bVar1 = (byte)(param_3 >> 0x18);
  *(byte *)(param_2 + 0xc48) = bVar1 >> 4 & 1;
  bVar3 = (byte)(param_3 >> 0x38);
  *(byte *)(param_2 + 0xc49) = bVar3 >> 2 & 1;
  *(uint *)(param_2 + 0xc70) = uVar5 & 0x20000000;
  *(byte *)(param_2 + 0xce8) = bVar1 >> 6 & 1;
  *(uint *)(param_2 + 0xcec) = uVar2 >> 4 & 7;
  *(byte *)(param_2 + 0xcf8) = (byte)(uVar2 >> 1) & 1;
  *(byte *)(param_2 + 0xcf0) = (byte)(param_3 >> 0x20) & 1;
  *(byte *)(param_2 + 0xcfb) = bVar1 >> 7;
  *(byte *)(param_2 + 0xcfd) = (byte)(uVar2 >> 7) & 1;
  bVar1 = (byte)(uVar2 >> 9) & 1;
  *(byte *)(param_2 + 0xcfe) = bVar1;
  *(byte *)(param_2 + 0xd00) = (byte)(uVar2 >> 10) & 1;
  *(byte *)(param_2 + 0xd05) = (byte)(param_3 >> 0x28) & 1;
  *(byte *)(param_2 + 0xcfc) = (byte)(uVar2 >> 0xb) & 1;
  *(byte *)(param_2 + 0xd07) = (byte)(uVar2 >> 0xc) & 1;
  *(byte *)(param_2 + 0xd0b) = (byte)(uVar2 >> 0xd) & 1;
  *(byte *)(param_2 + 0xd0d) = (byte)(uVar2 >> 0xe) & 1;
  *(byte *)(param_2 + 0xd0e) = (byte)(uVar2 >> 0xf) & 1;
  *(byte *)(param_2 + 0x20bc) = (byte)(uVar2 >> 0x12) & 1;
  *(byte *)(param_2 + 0xcff) = bVar1 & ((byte)(uVar2 >> 7) ^ 0xff);
  *(byte *)(param_2 + 0x20bd) = (byte)(uVar2 >> 0x13) & 1;
  *(byte *)(param_2 + 0x20be) = (byte)(uVar2 >> 0x14) & 1;
  *(byte *)(param_2 + 0x20d1) = (byte)(uVar2 >> 0x15) & 1;
  *(byte *)(param_2 + 0x22c2) = bVar3 & 1;
  *(byte *)(param_2 + 0x22c1) = (byte)(param_3 >> 0x36) & 1;
  if (((param_3 >> 0x36 & 1) != 0) && (iVar4 = FUN_fffffff008cd5954(4,10), iVar4 != 0)) {
    FUN_fffffff008df4208();
  }
  *(byte *)(param_2 + 0x20d0) = (byte)(param_3 >> 0x30) & 1;
  *(byte *)(param_2 + 0x22cc) = (byte)(uVar2 >> 0x17) & 1;
  *(byte *)(param_2 + 0x22cd) = bVar3 >> 1 & 1;
  return;
}

