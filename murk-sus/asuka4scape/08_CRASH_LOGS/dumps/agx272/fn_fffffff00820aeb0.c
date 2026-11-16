// FUN_fffffff00820aeb0 @ fffffff00820aeb0 size=240

/* WARNING: Removing unreachable block (ram,0xfffffff00820af00) */

undefined8 FUN_fffffff00820aeb0(long *param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  long *plVar3;
  
  uVar1 = FUN_fffffff008183e1c();
  *(undefined4 *)((long)param_1 + 0x194) = 0;
  lVar2 = (**(code **)(*param_1 + 0x160))(*param_1 + 0x160,param_1,param_1 + 0x32);
  if (lVar2 != 0) {
    plVar3 = (long *)FUN_fffffff0081f9fc0(param_1[2],*(undefined8 *)(param_2 + 0x488),lVar2,3,5);
    param_1[0x31] = (long)plVar3;
    if (plVar3 == (long *)0x0) {
      uVar1 = 0;
    }
    else {
      (**(code **)(*plVar3 + 0x20))();
      (**(code **)(*(long *)param_1[0x31] + 0xb0))
                ((long *)param_1[0x31],*(undefined8 *)(param_2 + 0x488));
    }
  }
  return uVar1;
}

