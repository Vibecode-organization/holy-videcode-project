// FUN_fffffff009962c3c @ fffffff009962c3c size=204

long * FUN_fffffff009962c3c(long param_1,undefined8 param_2)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long *plVar5;
  long *plVar6;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x160));
  plVar6 = *(long **)(param_1 + 0x168);
  if (plVar6 == (long *)0x0) {
    plVar5 = (long *)0x0;
  }
  else {
    plVar5 = (long *)0x0;
    do {
      (**(code **)(*plVar6 + 0x90))(plVar6);
      lVar3 = FUN_fffffff00995da74(plVar6);
      plVar1 = plVar5;
      if ((lVar3 != 0) &&
         (iVar2 = FUN_fffffff00994b4ec(*(undefined8 *)(param_1 + 0x1b0),lVar3 + 0xc0), iVar2 != 0))
      {
        plVar1 = plVar6;
        if (plVar5 != (long *)0x0) {
          plVar1 = plVar5;
        }
        uVar4 = FUN_fffffff00994cc40(*(undefined8 *)(param_1 + 0x1b0),lVar3 + 0x80,param_2);
        plVar5 = plVar6;
        if ((uVar4 & 1) != 0) break;
      }
      plVar5 = plVar1;
      plVar6 = (long *)plVar6[6];
    } while (plVar6 != (long *)0x0);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x160));
  return plVar5;
}

