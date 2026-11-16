// FUN_fffffff0081debcc @ fffffff0081debcc size=624

/* WARNING: Removing unreachable block (ram,0xfffffff0081ded68) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff0081debcc(long *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  
  uVar4 = FUN_fffffff00816edd0();
  DAT_fffffff00ae25928 = *(byte *)(param_1 + 0x212b) & 1;
  *(undefined1 *)((long)param_1 + 0x11119) = 1;
  uVar6 = param_1[0xb9];
  *(undefined4 *)(param_1 + 0xc2) = 0x50;
  param_1[0xc3] = 0x4000000040;
  param_1[0xcc] = DAT_fffffff007113fb8;
  *(undefined4 *)(param_1 + 0xcd) = 0xffffffff;
  lVar5 = _DAT_fffffff007113b10;
  param_1[0x2127] = _UNK_fffffff007113b18;
  param_1[0x2126] = lVar5;
  *(undefined2 *)(param_1 + 0x2128) = 0x101;
  *(undefined1 *)((long)param_1 + 0x10942) = 1;
  *(undefined4 *)((long)param_1 + 0x10944) = 2;
  *(undefined1 *)(param_1 + 0x2129) = 1;
  uVar2 = _DAT_fffffff007113b20;
  *(undefined8 *)((long)param_1 + 0x115cc) = _UNK_fffffff007113b28;
  *(undefined8 *)((long)param_1 + 0x115c4) = uVar2;
  puVar3 = PTR_DAT_fffffff007ca5f88;
  param_1[0x2ea] = (long)"MCache registers";
  iVar1 = 1 << (ulong)(*(uint *)puVar3 & 0x1f);
  *(uint *)(param_1 + 0x2a5) = iVar1 + 0x1407bU & -iVar1;
  *(undefined4 *)((long)param_1 + 0x1324) = 1;
  param_1[0x265] = 0x200f04000;
  thunk_EXT_FUN_8011000003a61b10(param_1 + 0x2a7,param_1 + 0x264,0x218);
  param_1[0x213d] = DAT_fffffff007113fc0;
  param_1[0xb9] = uVar6 & 0xfffffffdffffffff | 0x4070800b8440;
  param_1[0x1dc] = (long)"AnalogTempSensorController1Regs";
  param_1[0x157] = 0x23b2e8000;
  param_1[0x1889] = (long)"MetrologySensorRegs";
  *(undefined4 *)(param_1 + 0x197) = 0x1000;
  *(undefined4 *)((long)param_1 + 0xab4) = 1;
  *(undefined4 *)(param_1 + 0x1844) = 0x8000;
  *(undefined4 *)((long)param_1 + 0xc01c) = 1;
  lVar5 = (**(code **)(*param_1 + 0x800))(*param_1 + 0x800,param_1,0);
  param_1[0x1804] = lVar5 + 0xd80000;
  param_1[0x614] = (long)"PushTelemetryDashboardRegs";
  *(undefined4 *)(param_1 + 0x5cf) = 0x1000;
  *(undefined4 *)((long)param_1 + 0x2c74) = 1;
  param_1[0x58f] = 0x23b3d0000;
  *(uint *)(param_1 + 0x58e) = *(uint *)(param_1 + 0x58e) | 2;
  param_1[0x69b] = (long)"PushTelemetryDashboardReadRegs";
  *(undefined4 *)(param_1 + 0x656) = 0x1000;
  param_1[0x616] = 0x23b3c0000;
  param_1[0x615] = DAT_fffffff007113ec0;
  param_1[0x7a9] = (long)"ANE0Doorbell";
  *(int *)(param_1 + 0x764) = 1 << (ulong)(*(uint *)puVar3 & 0x1f);
  *(undefined4 *)((long)param_1 + 0x391c) = 1;
  *(uint *)(param_1 + 0x723) = *(uint *)(param_1 + 0x723) | 2;
  param_1[0x724] = 0x26b45c000;
  param_1[0xb9] = param_1[0xb9] | 0x400000000;
  return uVar4;
}

