// FUN_fffffff009c40a4c @ fffffff009c40a4c size=244

/* WARNING: Removing unreachable block (ram,0xfffffff009c40ac0) */

undefined8
FUN_fffffff009c40a4c
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  
  plVar1 = (long *)FUN_fffffff009c3f1d0();
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    lVar3 = *(long *)(param_1 + 0xf8);
    if (lVar3 == 0) {
      lVar3 = 0;
    }
    FUN_fffffff009c2ab44(plVar1,lVar3,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    (**(code **)(*plVar1 + 0x28))(plVar1);
    uVar2 = 0;
  }
  return uVar2;
}

