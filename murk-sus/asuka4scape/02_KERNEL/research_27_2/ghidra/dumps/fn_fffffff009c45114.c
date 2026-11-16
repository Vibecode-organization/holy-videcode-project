// FUN_fffffff009c45114 @ fffffff009c45114 size=1248
// CALLERS:
//   fffffff00afec1e0 no-fn
//   fffffff009c44e2c FUN_fffffff009c44d30@fffffff009c44d30
// CALLEES:
//   fffffff009c49864 thunk_FUN_fffffff00a8a10d8
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c49a54 thunk_FUN_fffffff00a89a1f4
//   fffffff009c49a64 thunk_FUN_fffffff00a89a3f0
//   fffffff009c49a84 thunk_FUN_fffffff00a8cae24
//   fffffff009c499a4 thunk_FUN_fffffff00a89ca6c
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30
//   fffffff009c42d48 FUN_fffffff009c42d48
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c49894 thunk_FUN_fffffff00a8a140c

int FUN_fffffff009c45114(long param_1,long *param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  long *plVar5;
  long *plVar6;
  undefined8 uVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  long *plVar11;
  long *plVar12;
  ulong uVar13;
  int iVar14;
  long *local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar5 = thunk_FUN_fffffff00a89a1f4(10);
  if (plVar5 == (long *)0x0) {
    iVar14 = 0;
  }
  else {
    thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0x40));
    uVar13 = 0;
    do {
      plVar6 = thunk_FUN_fffffff00a8a10d8(1);
      uVar7 = (**(code **)(**(long **)(param_1 + 0x48 + uVar13 * 8) + 0x90))();
      plVar8 = thunk_FUN_fffffff00a89a1f4(uVar7);
      bVar2 = plVar6 != (long *)0x0;
      bVar3 = plVar8 != (long *)0x0;
      bVar4 = bVar2 && bVar3;
      if (bVar2 && bVar3) {
        local_70 = thunk_FUN_fffffff00a8cae24
                             ((long)((1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f)) <<
                                    (ulong)((uint)uVar13 & 0x1f)),0x20);
        thunk_FUN_fffffff00a8a140c(plVar6,"Bucket buffer size",&local_70);
        if (local_70 != (long *)0x0) {
          (**(code **)(*local_70 + 0x28))();
        }
      }
      plVar9 = thunk_FUN_fffffff00a89ca6c(*(undefined8 *)(param_1 + 0x48 + uVar13 * 8));
      if (plVar9 == (long *)0x0) {
        if (!bVar2 || !bVar3) goto LAB_fffffff009c45444;
LAB_fffffff009c4537c:
        local_70 = plVar8;
        if (plVar8 != (long *)0x0) {
          (**(code **)(*plVar8 + 0x20))(plVar8);
        }
        thunk_FUN_fffffff00a8a140c(plVar6,"Descriptors",&local_70);
        if (local_70 != (long *)0x0) {
          (**(code **)(*local_70 + 0x28))();
        }
        local_70 = plVar6;
        if (plVar6 != (long *)0x0) {
          (**(code **)(*plVar6 + 0x20))(plVar6);
        }
        thunk_FUN_fffffff00a89a3f0(plVar5,&local_70);
        if (local_70 != (long *)0x0) {
          (**(code **)(*local_70 + 0x28))();
        }
        iVar14 = 1;
      }
      else {
        plVar12 = (long *)0x0;
        while( true ) {
          plVar10 = (long *)(**(code **)(*plVar9 + 0x88))(plVar9);
          plVar10 = thunk_FUN_fffffff00a894f30(plVar10,-0xff50b7ba8);
          if (plVar10 != (long *)0x0) {
            (**(code **)(*plVar10 + 0x20))(plVar10);
          }
          if (plVar12 != (long *)0x0) {
            (**(code **)(*plVar12 + 0x28))(plVar12);
          }
          if (plVar10 == (long *)0x0) break;
          plVar11 = thunk_FUN_fffffff00a8a10d8(1);
          bVar4 = plVar11 != (long *)0x0;
          plVar12 = plVar10;
          if (plVar11 != (long *)0x0) {
            FUN_fffffff009c42d48((long)plVar10,plVar11);
            local_70 = plVar11;
            (**(code **)(*plVar11 + 0x20))(plVar11);
            thunk_FUN_fffffff00a89a3f0(plVar8,&local_70);
            if (local_70 != (long *)0x0) {
              (**(code **)(*local_70 + 0x28))();
            }
            (**(code **)(*plVar11 + 0x28))(plVar11);
          }
        }
        (**(code **)(*plVar9 + 0x28))(plVar9);
        if (bVar4) goto LAB_fffffff009c4537c;
LAB_fffffff009c45444:
        iVar14 = 0;
      }
      if (plVar8 != (long *)0x0) {
        (**(code **)(*plVar8 + 0x28))(plVar8);
      }
      if (plVar6 != (long *)0x0) {
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
      bVar4 = uVar13 < 9;
      uVar13 = uVar13 + 1;
      iVar1 = 0;
      if (bVar4) {
        iVar1 = iVar14;
      }
    } while (iVar1 != 0);
    thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0x40));
    if (iVar14 != 0) {
      local_70 = thunk_FUN_fffffff00a8cae24(*(undefined8 *)(param_1 + 0x28),0x40);
      thunk_FUN_fffffff00a8a140c(param_2,"Pool Id",&local_70);
      if (local_70 != (long *)0x0) {
        (**(code **)(*local_70 + 0x28))();
      }
      local_70 = plVar5;
      (**(code **)(*plVar5 + 0x20))();
      thunk_FUN_fffffff00a8a140c(param_2,"Buckets",&local_70);
      if (local_70 != (long *)0x0) {
        (**(code **)(*local_70 + 0x28))();
      }
    }
    (**(code **)(*plVar5 + 0x28))();
  }
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
    return iVar14;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

