// FUN_fffffff009c0065c @ fffffff009c0065c

void FUN_fffffff009c0065c(long *param_1,long *param_2)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  ulong unaff_x30;
  
  plVar2 = thunk_FUN_fffffff00a89ca6c(param_1[0x17]);
  if (plVar2 != (long *)0x0) {
    lVar3 = (**(code **)(*plVar2 + 0x88))();
    while (lVar3 != 0) {
      (**(code **)(*param_1 + 0x5a8))(param_1,lVar3);
      lVar3 = (**(code **)(*plVar2 + 0x88))(plVar2);
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c00754);
    (*pcVar1)();
  }
  (*(code *)PTR_FUN_fffffff008063338)(param_1,param_2,&PTR_FUN_fffffff008063338);
  return;
}

