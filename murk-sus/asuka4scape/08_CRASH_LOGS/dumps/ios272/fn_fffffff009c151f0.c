// FUN_fffffff009c151f0 @ fffffff009c151f0 size=112

undefined8 FUN_fffffff009c151f0(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff00806ad70,0x50);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(uVar1,&DAT_fffffff00af48120);
  *puVar2 = &DAT_fffffff008066698;
  puVar2[6] = 0;
  puVar2[7] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00af48120);
  return uVar1;
}

