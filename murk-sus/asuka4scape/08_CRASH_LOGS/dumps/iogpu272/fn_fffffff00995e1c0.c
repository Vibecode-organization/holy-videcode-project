// FUN_fffffff00995e1c0 @ fffffff00995e1c0 size=244

void FUN_fffffff00995e1c0(undefined8 param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long *local_48;
  
  lVar4 = 0;
  lVar5 = 0xf;
  do {
    uVar1 = *(uint *)(param_2 + 4 + lVar4 * 4);
    iVar2 = uVar1 << 0x18;
    if ((iVar2 != -0x1000000) &&
       (plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24
                                   ((ulong)uVar1 & 0xffffff00 | (ulong)(uint)(iVar2 >> 0x18) << 0x20
                                    ,0x40), plVar3 != (long *)0x0)) {
      local_48 = plVar3;
      (**(code **)(*plVar3 + 0x20))();
      thunk_EXT_FUN_80110000038963f0(param_1,&local_48);
      if (local_48 != (long *)0x0) {
        (**(code **)(*local_48 + 0x28))();
      }
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    lVar4 = lVar4 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  return;
}

