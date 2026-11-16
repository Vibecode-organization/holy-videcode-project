// FUN_fffffff009c47b38 @ fffffff009c47b38 size=184

/* WARNING: Removing unreachable block (ram,0xfffffff009c47bd0) */

byte FUN_fffffff009c47b38(long param_1)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  
  iVar1 = FUN_fffffff009c4755c();
  if (iVar1 != 0) {
    lVar2 = FUN_fffffff009c22264(*(undefined8 *)(param_1 + 0x18));
    if (lVar2 == 0) {
      *(undefined1 *)(param_1 + 0x21) = 1;
    }
    else {
      plVar3 = (long *)FUN_fffffff009c22264(*(undefined8 *)(param_1 + 0x18));
      iVar1 = (**(code **)(*plVar3 + 0xd8))(plVar3,0);
      *(bool *)(param_1 + 0x21) = iVar1 == 0;
      if (iVar1 != 0) goto LAB_fffffff009c47bdc;
    }
    thunk_EXT_FUN_80110000038905fc(*(long *)(*(long *)(param_1 + 0x18) + 0x178) + 0x24);
  }
LAB_fffffff009c47bdc:
  return *(byte *)(param_1 + 0x21) & 1;
}

