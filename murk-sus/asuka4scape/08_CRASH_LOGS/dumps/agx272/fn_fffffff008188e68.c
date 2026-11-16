// FUN_fffffff008188e68 @ fffffff008188e68 size=444

void FUN_fffffff008188e68(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined *local_68;
  undefined8 local_60;
  code *local_58;
  undefined *local_50;
  long lStack_48;
  
  if (*(long *)(param_1 + 0x140) != 0) {
    FUN_fffffff0081e1178();
  }
  plVar3 = *(long **)(param_1 + 0x230);
  local_68 = PTR_DAT_fffffff007ca5f90;
  local_60 = DAT_fffffff007113e50;
  local_58 = FUN_fffffff008189024;
  local_50 = &DAT_fffffff007c93a48;
  lStack_48 = param_1;
  if (plVar3 != (long *)0x0) {
    thunk_EXT_FUN_801100000294e120(&local_50,plVar3);
    lVar1 = (**(code **)(*plVar3 + 0x80))(plVar3);
    uVar2 = (**(code **)(*plVar3 + 0x98))(plVar3);
    if (lVar1 != 0) {
      (*local_58)(&local_68,lVar1,uVar2);
      (**(code **)(*plVar3 + 0x88))(plVar3);
    }
    thunk_EXT_FUN_801100000294e12c(plVar3);
  }
  if ((*(int *)(param_1 + 0x170) - 1U < 2) &&
     (*(undefined4 **)(param_1 + 0x1d0) != (undefined4 *)0x0)) {
    **(undefined4 **)(param_1 + 0x1d0) = 1;
  }
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,
             "AGX: NOP Command: proc %{public}s [%d] command type %d traceID 0x%016llx");
  (**(code **)(PTR_DAT_fffffff007ca6160 + 0x98))(param_1);
  return;
}

