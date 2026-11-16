// FUN_fffffff009c86064 @ fffffff009c86064

/* WARNING: Removing unreachable block (ram,0xfffffff009c86108) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c860b8) */

void FUN_fffffff009c86064(long *param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  long *plVar2;
  undefined4 local_28;
  undefined4 uStack_24;
  
  plVar2 = (long *)param_1[0xd];
  lVar1 = *(long *)(*param_1 + 0xb8);
  local_28 = param_3;
  uStack_24 = param_2;
  if ((lVar1 == 0) && (lVar1 = thunk_FUN_fffffff00a894f04(param_1,-0xff6379ea0), lVar1 == 0)) {
    lVar1 = 0;
  }
  (**(code **)(*plVar2 + 0xe8))(plVar2,lVar1,&uStack_24,&local_28,0,0);
  return;
}

