// FUN_fffffff009970edc @ fffffff009970edc size=220

long * FUN_fffffff009970edc(undefined8 *param_1,ulong param_2,undefined8 *param_3)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  ulong uVar7;
  
  plVar4 = (long *)*param_1;
  if (plVar4 == (long *)0x0) {
    plVar6 = (long *)0x0;
  }
  else {
    plVar5 = (long *)0x0;
    uVar7 = 0xffffffffffffffff;
    do {
      uVar2 = (**(code **)(*plVar4 + 0x98))(plVar4);
      lVar3 = (**(code **)(*plVar4 + 200))(plVar4);
      if (uVar2 <= param_2 && param_2 < lVar3 + uVar2) {
        return plVar4;
      }
      uVar1 = param_2 - uVar2;
      if (uVar7 <= param_2 - uVar2) {
        uVar1 = uVar7;
      }
      if (param_2 < uVar2) {
        uVar1 = uVar7;
      }
      plVar6 = plVar4;
      if (uVar7 <= param_2 - uVar2 || param_2 < uVar2) {
        plVar6 = plVar5;
      }
      plVar4 = (long *)plVar4[7];
      plVar5 = plVar6;
      uVar7 = uVar1;
    } while (plVar4 != (long *)0x0);
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = plVar6;
  }
  return (long *)0x0;
}

