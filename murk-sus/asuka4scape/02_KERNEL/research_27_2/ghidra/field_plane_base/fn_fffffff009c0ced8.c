// FUN_fffffff009c0ced8 @ fffffff009c0ced8

/* WARNING: Removing unreachable block (ram,0xfffffff009c0d138) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0cfd4) */

undefined8 FUN_fffffff009c0ced8(long *param_1,long *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  code *pcVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  long *plVar7;
  long lVar8;
  undefined8 uVar9;
  char *pcVar10;
  ulong uVar11;
  char local_70 [40];
  long local_48;
  
  puVar2 = PTR_DAT_fffffff008064c08;
  puVar1 = PTR_DAT_fffffff008064bf0;
  local_48 = *(long *)PTR_DAT_fffffff008064be8;
  do {
    param_1 = (long *)(**(code **)(*param_1 + 0x178))(param_1,*(undefined8 *)puVar2);
    uVar9 = 0;
    if (param_1 == (long *)0x0) goto LAB_fffffff009c0d164;
    iVar4 = (**(code **)(*param_1 + 0x1a8))(param_1,*(undefined8 *)puVar1);
  } while (iVar4 == 0);
  local_70[8] = '\0';
  local_70[9] = '\0';
  local_70[10] = '\0';
  local_70[0xb] = '\0';
  local_70[0xc] = '\0';
  local_70[0xd] = '\0';
  local_70[0xe] = '\0';
  local_70[0xf] = '\0';
  local_70[0] = '\0';
  local_70[1] = '\0';
  local_70[2] = '\0';
  local_70[3] = '\0';
  local_70[4] = '\0';
  local_70[5] = '\0';
  local_70[6] = '\0';
  local_70[7] = '\0';
  local_70[0x18] = '\0';
  local_70[0x19] = '\0';
  local_70[0x1a] = '\0';
  local_70[0x1b] = '\0';
  local_70[0x1c] = '\0';
  local_70[0x1d] = '\0';
  local_70[0x1e] = '\0';
  local_70[0x1f] = '\0';
  local_70[0x10] = '\0';
  local_70[0x11] = '\0';
  local_70[0x12] = '\0';
  local_70[0x13] = '\0';
  local_70[0x14] = '\0';
  local_70[0x15] = '\0';
  local_70[0x16] = '\0';
  local_70[0x17] = '\0';
  puVar5 = (undefined8 *)(**(code **)(*param_1 + 0x218))(param_1,*(undefined8 *)puVar1);
  uVar6 = (**(code **)(*param_1 + 0x1e8))(*param_1 + 0x1e8,param_1,*(undefined8 *)puVar1);
  if (puVar5 == (undefined8 *)0x0) {
    uVar9 = 0;
  }
  else {
    plVar7 = thunk_FUN_fffffff00a894f30(param_1,(long)PTR_DAT_fffffff008062398);
    uVar9 = 0;
    if (((plVar7 != (long *)0x0) &&
        (lVar8 = (**(code **)(*param_1 + 0x178))(param_1,*(undefined8 *)puVar1), uVar9 = 0,
        lVar8 != 0)) &&
       (uVar9 = (**(code **)(*param_2 + 0x1b8))(param_2,lVar8,*(undefined8 *)puVar1),
       (int)uVar9 != 0)) {
      thunk_FUN_fffffff00a354958((undefined8 *)local_70,puVar5,0x20);
      pcVar10 = thunk_FUN_fffffff00a3544f8(local_70,0x3a);
      if (pcVar10 != (char *)0x0) {
        pcVar10 = thunk_FUN_fffffff00a3544f8(local_70,0x3a);
        pcVar10[1] = '\0';
      }
      pcVar10 = (char *)(**(code **)(*param_2 + 0x218))(param_2,0);
      uVar11 = thunk_FUN_fffffff00a1d1550((ulong)local_70);
      if (0x20 < uVar11) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xbffe,0xfffffff009c0d19c);
        (*pcVar3)();
      }
      thunk_FUN_fffffff00a354780(local_70,pcVar10,0x20 - uVar11);
      (**(code **)(*param_2 + 0x230))(param_2,local_70,*(undefined8 *)puVar1);
      (**(code **)(*param_2 + 0x210))(*param_2 + 0x210,param_2,uVar6,*(undefined8 *)puVar1);
      uVar9 = 1;
    }
  }
LAB_fffffff009c0d164:
  if (*(long *)PTR_DAT_fffffff008064be8 != local_48) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar9;
}

