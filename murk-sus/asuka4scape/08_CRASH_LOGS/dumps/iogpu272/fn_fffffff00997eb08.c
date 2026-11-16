// FUN_fffffff00997eb08 @ fffffff00997eb08 size=116

undefined4 FUN_fffffff00997eb08(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long *plVar3;
  
  uVar2 = thunk_EXT_FUN_801100000325c0a0();
  plVar3 = (long *)thunk_EXT_FUN_80110000039a2b94(uVar2,"com.apple.private.ioaccelmemoryinfo");
  uVar1 = 0xe00002c1;
  if (plVar3 != (long *)0x0) {
    uVar1 = 0;
    if ((long *)**(long **)PTR_DAT_fffffff007ff2820 != plVar3) {
      uVar1 = 0xe00002c1;
    }
    (**(code **)(*plVar3 + 0x28))();
  }
  return uVar1;
}

