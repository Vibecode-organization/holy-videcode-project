// FUN_fffffff0081f8444 @ fffffff0081f8444 size=276

/* WARNING: Removing unreachable block (ram,0xfffffff0081f84dc) */

long * FUN_fffffff0081f8444(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 *puVar2;
  ulong uVar3;
  
  if ((int)param_2 == 0) {
    return (long *)0x0;
  }
  plVar1 = (long *)thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca2448,0x78);
  puVar2 = (undefined8 *)thunk_EXT_FUN_8011000003976500(plVar1,&DAT_fffffff00ae23868);
  *puVar2 = &DAT_fffffff007c9e530;
  puVar2[0xc] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23868);
  uVar3 = (**(code **)(*plVar1 + 0x128))(*plVar1 + 0x128,plVar1,param_1,param_2,param_3);
  if ((uVar3 & 1) == 0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

