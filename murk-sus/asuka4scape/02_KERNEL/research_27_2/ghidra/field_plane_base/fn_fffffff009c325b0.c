// FUN_fffffff009c325b0 @ fffffff009c325b0

uint FUN_fffffff009c325b0(long *param_1)

{
  uint uVar1;
  uint uVar2;
  long *plVar3;
  long *plVar4;
  uint uVar5;
  undefined8 local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar3 = (long *)(**(code **)(*param_1 + 0x178))(param_1,*(undefined8 *)PTR_DAT_fffffff00806ca50);
  if (plVar3 != (long *)0x0) {
    local_40 = 0;
    thunk_FUN_fffffff00a908630(plVar3,(undefined4 *)((long)&local_40 + 4),(undefined4 *)&local_40);
    if (local_40._4_4_ != 0) {
      plVar4 = (long *)(**(code **)(*param_1 + 0x148))(param_1,&DAT_fffffff00789cb7a);
      plVar3 = thunk_FUN_fffffff00a894f30(plVar4,*(long *)PTR_PTR_fffffff00806c9e8);
      if (plVar3 == (long *)0x0) {
        if (plVar4 == (long *)0x0) goto LAB_fffffff009c326e0;
        uVar5 = 0;
        plVar3 = plVar4;
      }
      else {
        uVar2 = (**(code **)(*plVar3 + 0xa0))();
        uVar1 = ((int)local_40 + local_40._4_4_) * 4;
        uVar5 = 0;
        if (uVar1 != 0) {
          uVar5 = uVar2 / uVar1;
        }
      }
      (**(code **)(*plVar3 + 0x28))(plVar3);
      goto LAB_fffffff009c326e4;
    }
  }
LAB_fffffff009c326e0:
  uVar5 = 0;
LAB_fffffff009c326e4:
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar5;
}

