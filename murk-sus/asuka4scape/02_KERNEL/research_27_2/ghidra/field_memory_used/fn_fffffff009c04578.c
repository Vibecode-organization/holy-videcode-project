// FUN_fffffff009c04578 @ fffffff009c04578

undefined8 FUN_fffffff009c04578(long *param_1,long *param_2,undefined4 param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long lVar10;
  uint uVar11;
  ulong uVar12;
  undefined8 uVar13;
  
  plVar7 = (long *)(**(code **)(*(long *)param_1[0x17] + 0x128))();
  if (plVar7 == (long *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (**(code **)(*plVar7 + 0xa8))();
  }
  plVar7 = thunk_FUN_fffffff00a8d42e4((byte *)"IOStorage");
  if (plVar7 == (long *)0x0) {
    return 0;
  }
  plVar8 = (long *)(**(code **)(*param_1 + 0x280))(param_1,plVar7);
  (**(code **)(*plVar7 + 0x28))(plVar7);
  plVar7 = thunk_FUN_fffffff00a89ca6c(param_1[0x17]);
  if (plVar7 == (long *)0x0) {
LAB_fffffff009c04810:
    uVar13 = 0;
  }
  else {
    plVar9 = (long *)(**(code **)(*plVar7 + 0x88))();
    if (plVar9 == (long *)0x0) {
      uVar12 = 7;
    }
    else {
      uVar11 = 0;
      do {
        if ((plVar9 != param_2) &&
           (plVar9 = (long *)(**(code **)(*(long *)param_1[0x17] + 0x128))(), plVar9 != (long *)0x0)
           ) {
          iVar5 = (**(code **)(*plVar9 + 0xa8))();
          uVar11 = ((byte)(&UNK_fffffff007899608)
                          [(ulong)(uVar11 - 1 >> 1 & 7) + (ulong)(iVar5 - 1U >> 1 & 7) * 8] & 0x7f)
                   << 1 | 1;
        }
        plVar9 = (long *)(**(code **)(*plVar7 + 0x88))(plVar7);
      } while (plVar9 != (long *)0x0);
      uVar12 = (ulong)(uVar11 - 1 >> 1 & 7);
    }
    (**(code **)(*plVar7 + 0x28))(plVar7);
    bVar1 = (&UNK_fffffff007899608)[uVar12 + ((ulong)(param_4 - 1 >> 1) & 7) * 8];
    if ((bVar1 & 7) == 6) goto LAB_fffffff009c04810;
    if ((param_4 >> 1 & 1) == 0) {
      bVar3 = false;
      uVar11 = uVar4 >> 1 & 1;
    }
    else {
      if ((*(byte *)((long)param_1 + 0x9d) & 1) == 0) goto LAB_fffffff009c04810;
      uVar11 = 0;
      bVar3 = (plVar8 != (long *)0x0 && plVar8 != param_2) && (param_4 & 4) == 0;
    }
    uVar2 = param_4 >> 1 & 1;
    uVar6 = thunk_FUN_fffffff00a92d93c(param_1);
    if (uVar4 == 0) {
      uVar2 = 1;
    }
    if ((uVar6 != 0) && (uVar2 != 0)) goto LAB_fffffff009c04810;
    if (bVar3) {
      lVar10 = (**(code **)(*(long *)param_1[0x17] + 0x128))((long *)param_1[0x17],plVar8);
      if (lVar10 != 0) goto LAB_fffffff009c04810;
      iVar5 = (**(code **)(*plVar8 + 0x2f0))(plVar8,0);
      uVar13 = 0;
      if (iVar5 == 0) goto LAB_fffffff009c04818;
    }
    uVar4 = (bVar1 & 1) << 1 | 1;
    if (*(uint *)(param_1 + 0x16) != uVar4) {
      plVar7 = (long *)(**(code **)(*param_1 + 0x370))(param_1);
      plVar7 = thunk_FUN_fffffff00a894f30(plVar7,(long)PTR_DAT_fffffff0080636c8);
      if (plVar7 != (long *)0x0) {
        uVar12 = (**(code **)(*plVar7 + 0x540))(plVar7,param_1,param_3,uVar4);
        if ((uVar12 & 1) == 0) {
          if (bVar3) {
            (**(code **)(*param_1 + 0x2a0))(param_1,8);
          }
          goto LAB_fffffff009c04810;
        }
        (**(code **)(*param_1 + 0xd8))(param_1,&DAT_fffffff007899276,1);
      }
    }
    plVar7 = thunk_FUN_fffffff00a8cae24((ulong)param_4,0x20);
    (**(code **)(*(long *)param_1[0x17] + 0xf0))((long *)param_1[0x17],param_2,plVar7);
    *(uint *)(param_1 + 0x16) = uVar4;
    (**(code **)(*plVar7 + 0x28))(plVar7);
    if ((uVar11 != 0) && (uVar4 = thunk_FUN_fffffff00a92d93c(param_1), (uVar4 & 1) == 0)) {
      if (plVar8 == (long *)0x0) {
        (**(code **)(*param_1 + 0x2a0))(param_1,8);
        return 1;
      }
      if (plVar8 != param_2) {
        (**(code **)(*plVar8 + 0x418))(plVar8,0);
      }
      uVar13 = 1;
      goto LAB_fffffff009c04818;
    }
    uVar13 = 1;
  }
  if (plVar8 == (long *)0x0) {
    return uVar13;
  }
LAB_fffffff009c04818:
  (**(code **)(*plVar8 + 0x28))(plVar8);
  return uVar13;
}

