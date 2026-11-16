// FUN_fffffff009c04a54 @ fffffff009c04a54

/* WARNING: Removing unreachable block (ram,0xfffffff009c04a80) */

bool FUN_fffffff009c04a54(long param_1,long param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = **(long **)(param_1 + 0xb8);
  if (param_2 == 0) {
    iVar2 = (**(code **)(lVar3 + 0x90))();
    bVar1 = iVar2 == 0;
  }
  else {
    lVar3 = (**(code **)(lVar3 + 0x128))(lVar3 + 0x128);
    bVar1 = lVar3 == 0;
  }
  return !bVar1;
}

