// FUN_fffffff0081ee0f4 @ fffffff0081ee0f4 size=180

/* WARNING: Removing unreachable block (ram,0xfffffff0081ee16c) */

bool FUN_fffffff0081ee0f4(long param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  
  if ((param_2 & 1) == 0) {
    iVar1 = thunk_EXT_FUN_801100000297b3fc();
  }
  else {
    (**(code **)(**(long **)(param_1 + 0x18) + 0x128))(*(long **)(param_1 + 0x18),1);
    iVar1 = thunk_EXT_FUN_801100000297b3fc(*(undefined8 *)(param_1 + 0x18));
    lVar2 = **(long **)(param_1 + 0x18);
    (**(code **)(lVar2 + 0x128))(lVar2 + 0x128,*(long **)(param_1 + 0x18),0);
  }
  return iVar1 == 0;
}

