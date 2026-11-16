// FUN_fffffff009c0441c @ fffffff009c0441c

void FUN_fffffff009c0441c(long *param_1,long *param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  
  plVar3 = (long *)(**(code **)(*param_2 + 0x108))(param_2,*(undefined8 *)PTR_DAT_fffffff008064c00);
  plVar3 = thunk_FUN_fffffff00a894f30(plVar3,*(long *)PTR_PTR_fffffff008064ba8);
  if ((plVar3 != (long *)0x0) &&
     (iVar2 = (**(code **)(*plVar3 + 0xb8))(plVar3,"IOStorage"), iVar2 != 0)) {
    uVar4 = (**(code **)(*param_1 + 0x5e0))(param_1);
    (**(code **)(*param_1 + 0xd0))(param_1,"Content",uVar4);
    (**(code **)(*param_1 + 0xd8))(param_1,&DAT_fffffff007899271,1);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c04568);
    (*pcVar1)();
  }
  (*(code *)PTR_FUN_fffffff0080638b8)(param_1,param_2,param_3,&PTR_FUN_fffffff0080638b8);
  return;
}

