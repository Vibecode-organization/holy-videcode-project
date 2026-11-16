// FUN_fffffff009967e24 @ fffffff009967e24 size=264

undefined8 FUN_fffffff009967e24(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = 0xe00002c2;
  plVar1 = (long *)FUN_fffffff009945040(*(undefined8 *)(param_1 + 0x10));
  if (plVar1 != (long *)0x0) {
    if ((param_4 < 0x80001) && ((char)plVar1[2] == '\x03')) {
      lVar2 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff16d8,param_4 << 3);
      if (lVar2 == 0) {
        uVar3 = 0xe00002bd;
      }
      else {
        (**(code **)(*plVar1 + 0x20))(plVar1);
        uVar3 = FUN_fffffff009967bc0(param_1,plVar1,lVar2,param_3,param_4);
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1728,lVar2,param_4 << 3);
      }
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar3;
}

