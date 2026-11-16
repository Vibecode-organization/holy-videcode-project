// FUN_fffffff009c04ac0 @ fffffff009c04ac0

/* WARNING: Removing unreachable block (ram,0xfffffff009c04d14) */

void FUN_fffffff009c04ac0(long *param_1,long *param_2,undefined8 param_3)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  ulong uVar6;
  long *plVar7;
  long *plVar8;
  ulong *puVar9;
  long lVar10;
  ulong unaff_x30;
  
  plVar5 = (long *)(**(code **)(*(long *)param_1[0x17] + 0x128))();
  if (plVar5 == (long *)0x0) {
    bVar2 = true;
  }
  else {
    uVar6 = (**(code **)(*plVar5 + 0xa8))();
    bVar2 = (uVar6 & 2) == 0;
  }
  plVar5 = thunk_FUN_fffffff00a8d42e4((byte *)"IOStorage");
  if (plVar5 != (long *)0x0) {
    plVar7 = (long *)(**(code **)(*param_1 + 0x280))(param_1,plVar5);
    (**(code **)(*plVar5 + 0x28))(plVar5);
    plVar5 = thunk_FUN_fffffff00a89ca6c(param_1[0x17]);
    if (plVar5 != (long *)0x0) {
      plVar8 = (long *)(**(code **)(*plVar5 + 0x88))();
      if (plVar8 == (long *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = 0;
        do {
          if ((plVar8 != param_2) &&
             (plVar8 = (long *)(**(code **)(*(long *)param_1[0x17] + 0x128))(),
             plVar8 != (long *)0x0)) {
            iVar3 = (**(code **)(*plVar8 + 0xa8))();
            uVar4 = ((byte)(&UNK_fffffff007899608)
                           [(ulong)(uVar4 - 1 >> 1 & 7) + (ulong)(iVar3 - 1U >> 1 & 7) * 8] & 0x7f)
                    << 1 | 1;
          }
          plVar8 = (long *)(**(code **)(*plVar5 + 0x88))(plVar5);
        } while (plVar8 != (long *)0x0);
        uVar4 = uVar4 & 3;
      }
      (**(code **)(*plVar5 + 0x28))(plVar5);
      if (*(uint *)(param_1 + 0x16) != uVar4) {
        plVar5 = (long *)(**(code **)(*param_1 + 0x370))(param_1);
        plVar5 = thunk_FUN_fffffff00a894f30(plVar5,(long)PTR_DAT_fffffff0080636c8);
        if (plVar5 != (long *)0x0) {
          lVar10 = *plVar5;
          if (uVar4 == 0) {
            (**(code **)(lVar10 + 0x2c8))(lVar10 + 0x2c8,plVar5,param_1,param_3);
            (**(code **)(*param_1 + 0xd8))(param_1,&DAT_fffffff007899276,0);
          }
          else {
            (**(code **)(lVar10 + 0x540))(lVar10 + 0x540,plVar5,param_1,0,uVar4);
          }
        }
      }
      (**(code **)(*(long *)param_1[0x17] + 0x108))((long *)param_1[0x17],param_2);
      *(uint *)(param_1 + 0x16) = uVar4;
      if ((!bVar2) && (uVar4 = thunk_FUN_fffffff00a92d93c(param_1), (uVar4 & 1) == 0)) {
        if (plVar7 == (long *)0x0) {
          thunk_FUN_fffffff00a2262a8(*(ulong *)param_1[0x12]);
          puVar9 = (ulong *)param_1[0x12];
          *(undefined1 *)(puVar9 + 2) = 1;
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
            thunk_FUN_fffffff00a226de0(*puVar9);
            return;
          }
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c04e94);
          (*pcVar1)();
        }
        if (plVar7 != param_2) {
          FUN_fffffff009c04e98((long)param_1,plVar7);
        }
        goto LAB_fffffff009c04dc4;
      }
    }
    if (plVar7 != (long *)0x0) {
LAB_fffffff009c04dc4:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c04e14. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*plVar7 + 0x28))(plVar7,(undefined8 *)(*plVar7 + 0x28));
        return;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c04e0c);
      (*pcVar1)();
    }
  }
  return;
}

