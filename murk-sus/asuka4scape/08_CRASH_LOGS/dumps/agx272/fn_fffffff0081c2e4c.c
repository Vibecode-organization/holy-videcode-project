// FUN_fffffff0081c2e4c @ fffffff0081c2e4c size=296

long FUN_fffffff0081c2e4c(undefined8 param_1,ulong param_2)

{
  undefined *puVar1;
  undefined4 *puVar2;
  long lVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long *local_48;
  
  lVar3 = thunk_EXT_FUN_80110000038961f4(0xc);
  if (lVar3 != 0) {
    lVar7 = 0;
    lVar5 = (param_2 & 0xffffffff) * 0x30;
    puVar1 = &UNK_fffffff007114088 + (int)lVar5;
    if (lVar5 - (int)lVar5 != 0) {
      puVar1 = (undefined *)
               ((ulong)(&UNK_fffffff007114088 + lVar5) & 0xffffffffffff | 0x2bad000000000000);
    }
    lVar5 = 0xc;
    do {
      lVar6 = lVar7 * 4;
      puVar2 = (undefined4 *)(puVar1 + (int)lVar6);
      if (lVar6 - (int)lVar6 != 0) {
        puVar2 = (undefined4 *)((ulong)(puVar1 + lVar6) & 0xffffffffffff | 0x2bad000000000000);
      }
      plVar4 = (long *)thunk_EXT_FUN_80110000038c6e24(*puVar2,0x20);
      if (plVar4 == (long *)0x0) {
        return lVar3;
      }
      local_48 = plVar4;
      (**(code **)(*plVar4 + 0x20))();
      thunk_EXT_FUN_80110000038963f0(lVar3,&local_48);
      if (local_48 != (long *)0x0) {
        (**(code **)(*local_48 + 0x28))();
      }
      (**(code **)(*plVar4 + 0x28))(plVar4);
      lVar7 = lVar7 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  return lVar3;
}

