// FUN_fffffff008190bb0 @ fffffff008190bb0 size=268

long * FUN_fffffff008190bb0(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  ulong uVar2;
  long *plVar3;
  
  if ((*(uint *)(param_1 + 0x544) < 2) &&
     (plVar3 = *(long **)(param_1 + 0x910), plVar3 != (long *)0x0)) {
    *(undefined8 *)(param_1 + 0x910) = 0;
  }
  else {
    plVar3 = (long *)thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca0b88,0x98);
    puVar1 = (undefined8 *)thunk_EXT_FUN_801100000296c2ac(plVar3,&DAT_fffffff00ae21bf8);
    *puVar1 = &DAT_fffffff007c93250;
    thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae21bf8);
  }
  uVar2 = (**(code **)(*plVar3 + 0x80))
                    (plVar3,*(byte *)(param_1 + 0x527) & 1,param_2,param_3,param_4);
  if ((uVar2 & 1) == 0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
    plVar3 = (long *)0x0;
  }
  return plVar3;
}

