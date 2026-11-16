// FUN_fffffff0081bdfc4 @ fffffff0081bdfc4 size=4

long * FUN_fffffff0081bdfc4(long param_1)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  long *plStack_48;
  
  lVar4 = *(long *)(param_1 + 0x280);
  plVar1 = (long *)thunk_EXT_FUN_80110000038961f4(5);
  if (plVar1 == (long *)0x0) {
    return (long *)0x0;
  }
  plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar4 + 0x10f9c),0x20);
  if (plVar2 != (long *)0x0) {
    plStack_48 = plVar2;
    (**(code **)(*plVar2 + 0x20))();
    thunk_EXT_FUN_80110000038963f0(plVar1,&plStack_48);
    if (plStack_48 != (long *)0x0) {
      (**(code **)(*plStack_48 + 0x28))();
    }
    plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar4 + 0x10fac),0x20);
    (**(code **)(*plVar2 + 0x28))(plVar2);
    if (plVar3 != (long *)0x0) {
      plStack_48 = plVar3;
      (**(code **)(*plVar3 + 0x20))(plVar3);
      thunk_EXT_FUN_80110000038963f0(plVar1,&plStack_48);
      if (plStack_48 != (long *)0x0) {
        (**(code **)(*plStack_48 + 0x28))();
      }
      plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar4 + 0x10fbc),0x20);
      (**(code **)(*plVar3 + 0x28))(plVar3);
      if (plVar2 != (long *)0x0) {
        plStack_48 = plVar2;
        (**(code **)(*plVar2 + 0x20))(plVar2);
        thunk_EXT_FUN_80110000038963f0(plVar1,&plStack_48);
        if (plStack_48 != (long *)0x0) {
          (**(code **)(*plStack_48 + 0x28))();
        }
        plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar4 + 0x10fcc),0x20);
        (**(code **)(*plVar2 + 0x28))(plVar2);
        if (plVar3 != (long *)0x0) {
          plStack_48 = plVar3;
          (**(code **)(*plVar3 + 0x20))(plVar3);
          thunk_EXT_FUN_80110000038963f0(plVar1,&plStack_48);
          if (plStack_48 != (long *)0x0) {
            (**(code **)(*plStack_48 + 0x28))();
          }
          plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar4 + 0x10fdc),0x20);
          (**(code **)(*plVar3 + 0x28))(plVar3);
          if (plVar2 != (long *)0x0) {
            plStack_48 = plVar2;
            (**(code **)(*plVar2 + 0x20))(plVar2);
            thunk_EXT_FUN_80110000038963f0(plVar1,&plStack_48);
            plVar3 = plVar1;
            if (plStack_48 != (long *)0x0) {
              (**(code **)(*plStack_48 + 0x28))();
            }
            goto LAB_fffffff0081be288;
          }
        }
      }
    }
  }
  plVar3 = (long *)0x0;
  plVar2 = plVar1;
LAB_fffffff0081be288:
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return plVar3;
}

