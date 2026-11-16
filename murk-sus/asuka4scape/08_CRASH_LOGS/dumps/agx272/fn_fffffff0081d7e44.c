// FUN_fffffff0081d7e44 @ fffffff0081d7e44 size=56

undefined8 FUN_fffffff0081d7e44(undefined8 param_1,uint param_2)

{
  undefined8 *puVar1;
  int iVar2;
  ulong uVar3;
  
  if (6 < (int)param_2) {
    param_2 = 7;
  }
  uVar3 = -(ulong)(param_2 >> 0x1f) & 0xfffffff800000000 | (ulong)param_2 << 3;
  iVar2 = (int)((ulong)param_2 << 3);
  puVar1 = (undefined8 *)(&UNK_fffffff007c97990 + iVar2);
  if (uVar3 != (long)iVar2) {
    puVar1 = (undefined8 *)
             ((ulong)(&UNK_fffffff007c97990 + uVar3) & 0xffffffffffff | 0x2bad000000000000);
  }
  return *puVar1;
}

