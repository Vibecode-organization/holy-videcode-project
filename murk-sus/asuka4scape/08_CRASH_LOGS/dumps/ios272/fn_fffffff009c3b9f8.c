// FUN_fffffff009c3b9f8 @ fffffff009c3b9f8 size=188

/* WARNING: Removing unreachable block (ram,0xfffffff009c3ba50) */

undefined8
FUN_fffffff009c3b9f8(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
    uVar2 = FUN_fffffff009c33ad4(*(undefined8 *)(param_1 + 0xe8),lVar3,plVar1,param_3,param_4);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

