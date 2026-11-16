// FUN_fffffff009967f2c @ fffffff009967f2c size=140

undefined8
FUN_fffffff009967f2c(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  undefined8 uVar2;
  
  uVar2 = 0xe00002c2;
  plVar1 = (long *)FUN_fffffff009945040(*(undefined8 *)(param_1 + 0x10));
  if (plVar1 != (long *)0x0) {
    if ((char)plVar1[2] == '\x03') {
      uVar2 = FUN_fffffff0099569fc(plVar1,param_3,param_4);
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

