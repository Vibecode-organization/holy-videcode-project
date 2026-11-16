// FUN_fffffff009ca71fc @ fffffff009ca71fc

undefined8 FUN_fffffff009ca71fc(long param_1,undefined8 param_2,int param_3)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar3 = (**(code **)(PTR_DAT_fffffff00807fad0 + 0xb8))();
  if (((((int)uVar3 == 0) && (*(long **)(param_1 + 0x80) != (long *)0x0)) && (param_3 != 0)) &&
     ((*(long *)(param_1 + 0x88) != 0 &&
      ((iVar2 = (**(code **)(**(long **)(param_1 + 0x80) + 0xa8))(), iVar2 == 0 ||
       (uVar4 = (**(code **)(**(long **)(param_1 + 0x80) + 0xa8))(), (uVar4 & 1) != 0)))))) {
    plVar1 = *(long **)(param_1 + 0x80);
    uVar5 = (**(code **)(**(long **)(param_1 + 0x88) + 0x148))();
    uVar6 = (**(code **)(**(long **)(param_1 + 0x80) + 0xb0))();
    (**(code **)(*plVar1 + 0xd0))(plVar1,0,uVar5,uVar6);
  }
  return uVar3;
}

