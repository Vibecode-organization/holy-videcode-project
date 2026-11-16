// FUN_fffffff009970fb8 @ fffffff009970fb8 size=4

long FUN_fffffff009970fb8(long param_1,undefined8 param_2,undefined1 *param_3)

{
  int iVar1;
  long lVar2;
  undefined1 uVar3;
  long lStack_38;
  
  lStack_38 = 0;
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x18));
  lVar2 = FUN_fffffff009970edc(param_1 + 0x1b8,param_2,&lStack_38);
  if ((lVar2 == 0) || (iVar1 = FUN_fffffff00994d91c(), iVar1 == 0)) {
    lVar2 = lStack_38;
    if (lStack_38 == 0) goto LAB_fffffff009971040;
    iVar1 = FUN_fffffff00994d91c(lStack_38);
    if (iVar1 == 0) {
      lVar2 = 0;
      goto LAB_fffffff009971040;
    }
    if (param_3 == (undefined1 *)0x0) goto LAB_fffffff009971040;
    uVar3 = 1;
  }
  else {
    if (param_3 == (undefined1 *)0x0) goto LAB_fffffff009971040;
    uVar3 = 0;
  }
  *param_3 = uVar3;
LAB_fffffff009971040:
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x18));
  return lVar2;
}

