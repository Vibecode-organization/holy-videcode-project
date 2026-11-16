// FUN_fffffff009c9da78 @ fffffff009c9da78

void FUN_fffffff009c9da78(long *param_1,int param_2)

{
  undefined *puVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  long *plVar9;
  undefined8 uVar10;
  long *plVar11;
  ulong uVar12;
  
  iVar3 = (**(code **)(*param_1 + 0x598))();
  if (iVar3 == 0) {
    *(char *)(param_1[0x27] + 0x10) = (char)(int)param_1[0x2b];
    if ((int)param_1[0x1e] == 0) {
      (**(code **)(*(long *)param_1[0x2e] + 0xb8))();
      iVar3 = (**(code **)(*(long *)param_1[0x2d] + 0x90))();
      puVar1 = PTR_DAT_fffffff00807e548;
      if (iVar3 != 0) {
        uVar5 = 0;
        do {
          plVar9 = (long *)(**(code **)(*(long *)param_1[0x2d] + 0x118))
                                     ((long *)param_1[0x2d],uVar5);
          plVar9 = thunk_FUN_fffffff00a894f30(plVar9,(long)puVar1);
          if ((((*(byte *)((long)plVar9 + 0x31) & 1) == 0) &&
              ((*(byte *)((long)plVar9 + 0x32) & 1) == 0)) &&
             (iVar3 = FUN_fffffff009c9a9b8((long)plVar9), iVar3 <= param_2)) {
            (**(code **)(*(long *)param_1[0x2e] + 0xe8))((long *)param_1[0x2e],plVar9);
          }
          uVar5 = uVar5 + 1;
          uVar4 = (**(code **)(*(long *)param_1[0x2d] + 0x90))();
        } while (uVar5 < uVar4);
      }
      *(undefined4 *)((long)param_1 + 0xe4) = 0;
    }
    else {
      plVar9 = (long *)(**(code **)(*(long *)param_1[0x2d] + 0x118))
                                 ((long *)param_1[0x2d],(int)param_1[0x1e] + -1);
      puVar1 = PTR_DAT_fffffff00807e548;
      plVar9 = thunk_FUN_fffffff00a894f30(plVar9,(long)PTR_DAT_fffffff00807e548);
      if ((plVar9 != (long *)0x0) && (iVar3 = FUN_fffffff009c9a9b8((long)plVar9), iVar3 <= param_2))
      {
        uVar5 = (**(code **)(*(long *)param_1[0x2e] + 0x128))((long *)param_1[0x2e],plVar9,0);
        uVar10 = (**(code **)(*(long *)param_1[0x2e] + 0x90))();
        if (uVar5 < (uint)uVar10) {
          *(uint *)((long)param_1 + 0xe4) = uVar5 + 1;
        }
        else {
          uVar5 = FUN_fffffff009ca8370(uVar10,(long *)param_1[0x2d],param_2,3);
          uVar4 = FUN_fffffff009ca8370((ulong)uVar5,(long *)param_1[0x2d],param_2,4);
          uVar7 = FUN_fffffff009ca8370((ulong)uVar4,(long *)param_1[0x2e],param_2,3);
          uVar12 = (ulong)uVar7;
          if (((((*(byte *)((long)plVar9 + 0x31) & 1) != 0) && (*(uint *)(param_1 + 0x1e) == uVar4))
              && (uVar5 != 0)) && ((int)uVar7 < 1)) {
            plVar11 = (long *)(**(code **)(*(long *)param_1[0x2d] + 0x118))
                                        ((long *)param_1[0x2d],uVar5 - 1);
            plVar11 = thunk_FUN_fffffff00a894f30(plVar11,(long)puVar1);
            uVar12 = 0;
            if (plVar11 != (long *)0x0) {
              uVar5 = FUN_fffffff009c9a9b8((long)plVar11);
              uVar12 = (ulong)uVar5;
              if ((int)uVar5 <= param_2) {
                uVar12 = (**(code **)(*(long *)param_1[0x2e] + 0xe8))((long *)param_1[0x2e],plVar11)
                ;
              }
            }
          }
          iVar3 = FUN_fffffff009ca8370(uVar12,(long *)param_1[0x2d],param_2,5);
          if ((int)param_1[0x1e] == iVar3) {
            (**(code **)(*(long *)param_1[0x2e] + 0xb8))();
          }
          (**(code **)(*(long *)param_1[0x2e] + 0xe8))((long *)param_1[0x2e],plVar9);
          uVar8 = (**(code **)(*(long *)param_1[0x2e] + 0x90))();
          *(undefined4 *)((long)param_1 + 0xe4) = uVar8;
        }
      }
    }
  }
  else {
    iVar3 = (**(code **)(*(long *)param_1[0x2e] + 0x90))();
    puVar1 = PTR_DAT_fffffff00807e548;
    if (iVar3 != 0) {
      uVar5 = 0;
LAB_fffffff009c9daf8:
      plVar9 = (long *)(**(code **)(*(long *)param_1[0x2e] + 0x118))((long *)param_1[0x2e],uVar5);
      plVar9 = thunk_FUN_fffffff00a894f30(plVar9,(long)puVar1);
      if (((*(byte *)(plVar9 + 6) & 1) != 0) &&
         (*(uint *)((long)param_1 + 0x15c) == (uint)*(byte *)(param_1[0x27] + 0x10)))
      goto code_r0xfffffff009c9db48;
      if (*(int *)((long)param_1 + 0xd4) == 4) {
        FUN_fffffff009c9be10(param_1);
      }
      (**(code **)(*(long *)param_1[0x2e] + 0xb8))();
      iVar3 = (**(code **)(*(long *)param_1[0x2d] + 0x90))();
      if (iVar3 != 0) {
        uVar5 = 0;
        do {
          plVar9 = (long *)(**(code **)(*(long *)param_1[0x2d] + 0x118))
                                     ((long *)param_1[0x2d],uVar5);
          plVar9 = thunk_FUN_fffffff00a894f30(plVar9,(long)puVar1);
          if (((((*(byte *)(plVar9 + 6) & 1) != 0) && ((*(byte *)((long)plVar9 + 0x31) & 1) == 0))
              && ((*(byte *)((long)plVar9 + 0x32) & 1) == 0)) &&
             (iVar3 = FUN_fffffff009c9a9b8((long)plVar9), iVar3 <= param_2)) {
            (**(code **)(*(long *)param_1[0x2e] + 0xe8))((long *)param_1[0x2e],plVar9);
          }
          uVar5 = uVar5 + 1;
          uVar4 = (**(code **)(*(long *)param_1[0x2d] + 0x90))();
        } while (uVar5 < uVar4);
      }
      *(undefined4 *)((long)param_1 + 0xe4) = 0;
    }
LAB_fffffff009c9de5c:
    *(char *)(param_1[0x27] + 0x10) = (char)*(undefined4 *)((long)param_1 + 0x15c);
  }
  uVar2 = (**(code **)(*(long *)param_1[0x2e] + 0x90))();
  *(undefined1 *)(param_1[0x27] + 0x11) = uVar2;
  uVar10 = FUN_fffffff009ca86f8(param_1,(uint)*(byte *)(param_1 + 0x1c));
  *(int *)(param_1 + 0x1d) = (int)uVar10;
  if (param_2 - 1U < 2) {
    iVar3 = 1;
    if (param_2 == 1) {
      iVar3 = 2;
    }
    (**(code **)(*(long *)param_1[0x2f] + 0xb8))();
    iVar6 = (**(code **)(*(long *)param_1[0x2d] + 0x90))();
    puVar1 = PTR_DAT_fffffff00807e548;
    if (iVar6 != 0) {
      uVar5 = 0;
      do {
        plVar9 = (long *)(**(code **)(*(long *)param_1[0x2d] + 0x118))((long *)param_1[0x2d],uVar5);
        plVar9 = thunk_FUN_fffffff00a894f30(plVar9,(long)puVar1);
        iVar6 = FUN_fffffff009c9a9b8((long)plVar9);
        if (((iVar3 < iVar6) || ((*(byte *)((long)plVar9 + 0x31) & 1) != 0)) ||
           (((*(byte *)((long)plVar9 + 0x32) & 1) != 0 || ((*(byte *)(plVar9 + 6) & 1) != 0)))) {
          iVar6 = FUN_fffffff009c9a9b8((long)plVar9);
          if ((iVar6 <= iVar3) &&
             (((((*(byte *)((long)plVar9 + 0x31) & 1) != 0 ||
                ((*(byte *)((long)plVar9 + 0x32) & 1) != 0)) || ((*(byte *)(plVar9 + 6) & 1) != 0))
              && (iVar6 = (**(code **)(*(long *)param_1[0x2e] + 0x90))(), iVar6 != 0)))) {
            uVar4 = 0;
            do {
              plVar11 = (long *)(**(code **)(*(long *)param_1[0x2e] + 0x118))
                                          ((long *)param_1[0x2e],uVar4);
              plVar11 = thunk_FUN_fffffff00a894f30(plVar11,(long)puVar1);
              if (plVar9 == plVar11) {
                (**(code **)(*(long *)param_1[0x2f] + 0xe8))((long *)param_1[0x2f],plVar9);
              }
              uVar4 = uVar4 + 1;
              uVar7 = (**(code **)(*(long *)param_1[0x2e] + 0x90))();
            } while (uVar4 < uVar7);
          }
        }
        else {
          (**(code **)(*(long *)param_1[0x2f] + 0xe8))((long *)param_1[0x2f],plVar9);
        }
        uVar5 = uVar5 + 1;
        uVar4 = (**(code **)(*(long *)param_1[0x2d] + 0x90))();
      } while (uVar5 < uVar4);
    }
    uVar2 = (**(code **)(*(long *)param_1[0x2f] + 0x90))();
    *(undefined1 *)(param_1[0x28] + 8) = uVar2;
  }
  return;
code_r0xfffffff009c9db48:
  uVar5 = uVar5 + 1;
  uVar4 = (**(code **)(*(long *)param_1[0x2e] + 0x90))();
  if (uVar4 <= uVar5) goto LAB_fffffff009c9de5c;
  goto LAB_fffffff009c9daf8;
}

