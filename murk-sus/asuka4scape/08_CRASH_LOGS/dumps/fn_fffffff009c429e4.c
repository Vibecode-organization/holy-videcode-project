// FUN_fffffff009c429e4 @ fffffff009c429e4 size=868
// CALLERS:
//   fffffff00afec1a1 no-fn
//   fffffff009c44afc FUN_fffffff009c44a5c@fffffff009c44a5c
//   fffffff009c44f34 FUN_fffffff009c44d30@fffffff009c44d30
//   fffffff009c45664 FUN_fffffff009c455f4@fffffff009c455f4
// CALLEES:
//   fffffff009c49864 thunk_FUN_fffffff00a8a10d8
//   fffffff009c49e74 thunk_FUN_fffffff00a2df760
//   fffffff009c49a54 thunk_FUN_fffffff00a89a1f4
//   fffffff009c49a64 thunk_FUN_fffffff00a89a3f0
//   fffffff009c49a84 thunk_FUN_fffffff00a8cae24
//   fffffff009c499a4 thunk_FUN_fffffff00a89ca6c
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30
//   fffffff009c42d48 FUN_fffffff009c42d48
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c49894 thunk_FUN_fffffff00a8a140c

undefined8 FUN_fffffff009c429e4(long param_1,long *param_2)

{
  bool bVar1;
  undefined8 uVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar2 = (**(code **)(**(long **)(param_1 + 0x28) + 0x90))();
  plVar3 = thunk_FUN_fffffff00a89a1f4(uVar2);
  bVar1 = plVar3 != (long *)0x0;
  if (plVar3 != (long *)0x0) {
    local_70 = (long *)0x0;
    thunk_FUN_fffffff00a2df760(*(ulong *)(param_1 + 0x20),(long *)&local_70);
    local_70 = thunk_FUN_fffffff00a8cae24(local_70,0x40);
    thunk_FUN_fffffff00a8a140c(param_2,"Descriptor address",&local_70);
    if (local_70 != (long *)0x0) {
      (**(code **)(*local_70 + 0x28))();
    }
    local_70 = thunk_FUN_fffffff00a8cae24(*(undefined8 *)(param_1 + 0x10),0x40);
    thunk_FUN_fffffff00a8a140c(param_2,"Pool Id",&local_70);
    if (local_70 != (long *)0x0) {
      (**(code **)(*local_70 + 0x28))();
    }
  }
  plVar4 = thunk_FUN_fffffff00a89ca6c(*(undefined8 *)(param_1 + 0x28));
  if (plVar4 == (long *)0x0) {
    if (plVar3 != (long *)0x0) goto LAB_fffffff009c42c5c;
  }
  else {
    plVar7 = (long *)0x0;
    while( true ) {
      plVar5 = (long *)(**(code **)(*plVar4 + 0x88))(plVar4);
      plVar5 = thunk_FUN_fffffff00a894f30(plVar5,-0xff50b7ba8);
      if (plVar5 != (long *)0x0) {
        (**(code **)(*plVar5 + 0x20))(plVar5);
      }
      if (plVar7 != (long *)0x0) {
        (**(code **)(*plVar7 + 0x28))(plVar7);
      }
      if (plVar5 == (long *)0x0) break;
      plVar6 = thunk_FUN_fffffff00a8a10d8(1);
      bVar1 = plVar6 != (long *)0x0;
      plVar7 = plVar5;
      if (plVar6 != (long *)0x0) {
        FUN_fffffff009c42d48((long)plVar5,plVar6);
        local_70 = plVar6;
        (**(code **)(*plVar6 + 0x20))(plVar6);
        thunk_FUN_fffffff00a89a3f0(plVar3,&local_70);
        if (local_70 != (long *)0x0) {
          (**(code **)(*local_70 + 0x28))();
        }
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
    }
    (**(code **)(*plVar4 + 0x28))(plVar4);
    if (bVar1) {
LAB_fffffff009c42c5c:
      local_70 = plVar3;
      if (plVar3 != (long *)0x0) {
        (**(code **)(*plVar3 + 0x20))(plVar3);
      }
      thunk_FUN_fffffff00a8a140c(param_2,"Components",&local_70);
      if (local_70 != (long *)0x0) {
        (**(code **)(*local_70 + 0x28))();
      }
      uVar2 = 1;
      goto joined_r0xfffffff009c42c50;
    }
  }
  uVar2 = 0;
joined_r0xfffffff009c42c50:
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

