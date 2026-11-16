// FUN_fffffff0081d8be4 @ fffffff0081d8be4 size=312

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff0081d8be4(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  uVar4 = FUN_fffffff00816edd0();
  DAT_fffffff00ae25928 = *(byte *)(param_1 + 0x10958) & 1;
  *(undefined1 *)(param_1 + 0x11119) = 1;
  uVar5 = *(ulong *)(param_1 + 0x5c8);
  *(undefined4 *)(param_1 + 0x610) = 0x50;
  *(undefined8 *)(param_1 + 0x618) = 0x4000000040;
  *(undefined8 *)(param_1 + 0x660) = DAT_fffffff007113fb8;
  *(undefined4 *)(param_1 + 0x668) = 0xffffffff;
  uVar2 = _DAT_fffffff007113b10;
  *(undefined8 *)(param_1 + 0x10938) = _UNK_fffffff007113b18;
  *(undefined8 *)(param_1 + 0x10930) = uVar2;
  *(undefined2 *)(param_1 + 0x10940) = 0x101;
  *(undefined1 *)(param_1 + 0x10942) = 1;
  *(undefined4 *)(param_1 + 0x10944) = 2;
  *(undefined1 *)(param_1 + 0x10948) = 1;
  uVar2 = _DAT_fffffff007113b20;
  *(undefined8 *)(param_1 + 0x115cc) = _UNK_fffffff007113b28;
  *(undefined8 *)(param_1 + 0x115c4) = uVar2;
  puVar3 = PTR_DAT_fffffff007ca5f88;
  *(char **)(param_1 + 0x1750) = "MCache registers";
  iVar1 = 1 << (ulong)(*(uint *)puVar3 & 0x1f);
  *(uint *)(param_1 + 0x1528) = iVar1 + 0x1407bU & -iVar1;
  *(undefined4 *)(param_1 + 0x1324) = 1;
  *(undefined8 *)(param_1 + 0x1328) = 0x200f04000;
  thunk_EXT_FUN_8011000003a61b10(param_1 + 0x1538,param_1 + 0x1320,0x218);
  *(undefined8 *)(param_1 + 0x109e8) = DAT_fffffff007113fc0;
  *(ulong *)(param_1 + 0x5c8) = uVar5 & 0xfffffffdffffffff | 0x4070800b8440;
  return uVar4;
}

