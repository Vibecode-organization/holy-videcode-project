// FUN_fffffff0099681d8 @ fffffff0099681d8 size=196

undefined8 FUN_fffffff0099681d8(long param_1,long param_2,undefined8 param_3,ulong *param_4)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  uint local_34;
  
  uVar3 = 0xe00002e2;
  if ((param_2 == 1) &&
     (iVar1 = FUN_fffffff009964e38(param_1,"com.apple.private.iogpu.disable_wired_collector"),
     iVar1 != 0)) {
    plVar2 = (long *)FUN_fffffff00995c0f8(*(undefined8 *)(param_1 + 0x48),1,param_3);
    if (plVar2 == (long *)0x0) {
      uVar3 = 0;
    }
    else {
      local_34 = 0;
      uVar3 = thunk_EXT_FUN_80110000039a3b30(*(undefined8 *)(param_1 + 0x50),plVar2,&local_34);
      if ((int)uVar3 == 0) {
        *param_4 = (ulong)local_34;
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  return uVar3;
}

