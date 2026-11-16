// FUN_fffffff009aa10b4 @ fffffff009aa10b4 size=108
// CALLERS:
//   fffffff00afb8170 no-fn
// CALLEES:
//   fffffff009abd22c thunk_EXT_FUN_80110000038943cc
//   fffffff009abd8ac thunk_EXT_FUN_80110000038922a0
//   fffffff009abd41c thunk_EXT_FUN_80110000039a385c

undefined8 FUN_fffffff009aa10b4(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff0080299e0,0x958);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000039a385c(uVar1,&DAT_fffffff00af28438);
  *puVar2 = &DAT_fffffff0080233d8;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00af28438);
  return uVar1;
}

