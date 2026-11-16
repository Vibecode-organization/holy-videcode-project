// FUN_fffffff0081be5e0 @ fffffff0081be5e0 size=776

long * FUN_fffffff0081be5e0(long param_1)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  long *local_48;
  
  lVar4 = *(long *)(param_1 + 0x280);
  plVar1 = (long *)thunk_EXT_FUN_80110000038961f4(5);
  if (plVar1 == (long *)0x0) {
    return (long *)0x0;
  }
  plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar4 + 0x10f94),0x20);
  if (plVar2 != (long *)0x0) {
    local_48 = plVar2;
    (**(code **)(*plVar2 + 0x20))();
    thunk_EXT_FUN_80110000038963f0(plVar1,&local_48);
    if (local_48 != (long *)0x0) {
      (**(code **)(*local_48 + 0x28))();
    }
    plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar4 + 0x10fa4),0x20);
    (**(code **)(*plVar2 + 0x28))(plVar2);
    if (plVar3 != (long *)0x0) {
      local_48 = plVar3;
      (**(code **)(*plVar3 + 0x20))(plVar3);
      thunk_EXT_FUN_80110000038963f0(plVar1,&local_48);
      if (local_48 != (long *)0x0) {
        (**(code **)(*local_48 + 0x28))();
      }
      plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar4 + 0x10fb4),0x20);
      (**(code **)(*plVar3 + 0x28))(plVar3);
      if (plVar2 != (long *)0x0) {
        local_48 = plVar2;
        (**(code **)(*plVar2 + 0x20))(plVar2);
        thunk_EXT_FUN_80110000038963f0(plVar1,&local_48);
        if (local_48 != (long *)0x0) {
          (**(code **)(*local_48 + 0x28))();
        }
        plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar4 + 0x10fc4),0x20);
        (**(code **)(*plVar2 + 0x28))(plVar2);
        if (plVar3 != (long *)0x0) {
          local_48 = plVar3;
          (**(code **)(*plVar3 + 0x20))(plVar3);
          thunk_EXT_FUN_80110000038963f0(plVar1,&local_48);
          if (local_48 != (long *)0x0) {
            (**(code **)(*local_48 + 0x28))();
          }
          plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar4 + 0x10fd4),0x20);
          (**(code **)(*plVar3 + 0x28))(plVar3);
          if (plVar2 != (long *)0x0) {
            local_48 = plVar2;
            (**(code **)(*plVar2 + 0x20))(plVar2);
            thunk_EXT_FUN_80110000038963f0(plVar1,&local_48);
            plVar3 = plVar1;
            if (local_48 != (long *)0x0) {
              (**(code **)(*local_48 + 0x28))();
            }
            goto LAB_fffffff0081be8a0;
          }
        }
      }
    }
  }
  plVar3 = (long *)0x0;
  plVar2 = plVar1;
LAB_fffffff0081be8a0:
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return plVar3;
}

