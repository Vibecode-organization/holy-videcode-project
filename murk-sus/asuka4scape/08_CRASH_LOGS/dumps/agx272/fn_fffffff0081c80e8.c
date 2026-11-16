// FUN_fffffff0081c80e8 @ fffffff0081c80e8 size=1508

long * FUN_fffffff0081c80e8(long param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  undefined8 *puVar10;
  long *plVar11;
  ulong uVar12;
  long lVar13;
  int iVar14;
  ulong uVar15;
  long *plVar16;
  uint uVar17;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  long *local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007ca61a0;
  uStack_a8 = 0;
  local_b0 = 0;
  uStack_98 = 0;
  uStack_a0 = 0;
  uStack_c8 = 0;
  uStack_b8 = 0;
  uStack_c0 = 0;
  local_d0 = 0x32;
  local_88 = (long *)CONCAT44(local_88._4_4_,2);
  uVar3 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
  local_d8 = (long *)((ulong)local_d8._4_4_ << 0x20);
  plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
  puVar10 = (undefined8 *)(*plVar4 + 0xe8);
  iVar2 = (*(code *)*puVar10)(puVar10,plVar4,FUN_fffffff00817ea94,&local_d0,&local_88,&local_d8,0);
  if ((iVar2 == 0) &&
     ((((byte)local_88 >> 1 & 1) == 0 ||
      (iVar2 = FUN_fffffff0081a43cc(param_1,uVar3,(ulong)local_d8 & 0xffffffff), iVar2 == 0)))) {
    lVar13 = *(long *)(param_1 + 0x910);
    uVar17 = *(uint *)(lVar13 + 0x6c44);
    uVar15 = (ulong)uVar17;
    iVar2 = *(int *)(lVar13 + 0x6c30);
    if (iVar2 != 0) {
      plVar4 = (long *)thunk_EXT_FUN_801100000389d0d8(3);
      plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(iVar2,0x20);
      plVar6 = (long *)thunk_EXT_FUN_80110000038961f4(uVar15);
      plVar11 = (long *)thunk_EXT_FUN_801100000389d0d8(uVar15);
      if (plVar4 == (long *)0x0) {
        plVar16 = (long *)0x0;
LAB_fffffff0081c8608:
        if (plVar11 == (long *)0x0) {
          plVar11 = (long *)0x0;
          plVar4 = plVar16;
        }
        else {
          plVar4 = (long *)0x0;
LAB_fffffff0081c8618:
          (**(code **)(*plVar11 + 0x28))();
          plVar11 = plVar4;
          plVar4 = plVar16;
        }
        if (plVar6 != (long *)0x0) goto LAB_fffffff0081c8634;
      }
      else {
        plVar16 = plVar4;
        if (plVar5 == (long *)0x0 || plVar6 == (long *)0x0) goto LAB_fffffff0081c8608;
        if (plVar11 != (long *)0x0) {
          if (uVar17 != 0) {
            uVar12 = 0;
            uVar17 = 0;
            do {
              plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24
                                         (*(undefined4 *)(lVar13 + 0x6c34 + uVar12 * 4),0x20);
              plVar8 = (long *)thunk_EXT_FUN_80110000038961f4(iVar2);
              if (plVar7 == (long *)0x0) {
                if (plVar8 == (long *)0x0) goto LAB_fffffff0081c8608;
LAB_fffffff0081c84b4:
                bVar1 = false;
LAB_fffffff0081c8468:
                (**(code **)(*plVar8 + 0x28))(plVar8);
                if (plVar7 != (long *)0x0) goto LAB_fffffff0081c8484;
              }
              else {
                iVar14 = iVar2;
                if (plVar8 != (long *)0x0) {
                  do {
                    plVar9 = (long *)thunk_EXT_FUN_80110000038c6e24
                                               (*(undefined8 *)(lVar13 + 0x6c48 + (ulong)uVar17 * 8)
                                                ,0x40);
                    if (plVar9 == (long *)0x0) {
                      uVar17 = uVar17 + 1;
                      goto LAB_fffffff0081c84b4;
                    }
                    local_88 = plVar9;
                    (**(code **)(*plVar9 + 0x20))();
                    thunk_EXT_FUN_80110000038963f0(plVar8,&local_88);
                    if (local_88 != (long *)0x0) {
                      (**(code **)(*local_88 + 0x28))();
                    }
                    (**(code **)(*plVar9 + 0x28))(plVar9);
                    uVar17 = uVar17 + 1;
                    iVar14 = iVar14 + -1;
                  } while (iVar14 != 0);
                  local_88 = (long *)0x0;
                  uStack_80 = 0;
                  local_78 = 0;
                  thunk_EXT_FUN_80110000037693ec(&local_88,0x14,"Counter_%u");
                  local_d8 = plVar8;
                  (**(code **)(*plVar8 + 0x20))(plVar8);
                  thunk_EXT_FUN_801100000389d40c(plVar11,&local_88,&local_d8);
                  if (local_d8 != (long *)0x0) {
                    (**(code **)(*local_d8 + 0x28))();
                  }
                  local_d8 = plVar7;
                  (**(code **)(*plVar7 + 0x20))(plVar7);
                  thunk_EXT_FUN_80110000038963f0(plVar6,&local_d8);
                  if (local_d8 != (long *)0x0) {
                    (**(code **)(*local_d8 + 0x28))();
                  }
                  bVar1 = true;
                  goto LAB_fffffff0081c8468;
                }
                bVar1 = false;
LAB_fffffff0081c8484:
                (**(code **)(*plVar7 + 0x28))(plVar7);
              }
              if (!bVar1) goto LAB_fffffff0081c8608;
              uVar12 = uVar12 + 1;
            } while (uVar12 != uVar15);
          }
          local_88 = plVar5;
          (**(code **)(*plVar5 + 0x20))(plVar5);
          thunk_EXT_FUN_801100000389d40c(plVar4,"NumFSTPs",&local_88);
          if (local_88 != (long *)0x0) {
            (**(code **)(*local_88 + 0x28))();
          }
          local_88 = plVar6;
          (**(code **)(*plVar6 + 0x20))(plVar6);
          thunk_EXT_FUN_801100000389d40c(plVar4,"CounterList",&local_88);
          if (local_88 != (long *)0x0) {
            (**(code **)(*local_88 + 0x28))();
          }
          local_88 = plVar11;
          (**(code **)(*plVar11 + 0x20))();
          thunk_EXT_FUN_801100000389d40c(plVar4,"CounterValues",&local_88);
          if (local_88 != (long *)0x0) {
            (**(code **)(*local_88 + 0x28))();
          }
          plVar16 = (long *)0x0;
          goto LAB_fffffff0081c8618;
        }
        plVar11 = (long *)0x0;
LAB_fffffff0081c8634:
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
      if (plVar5 != (long *)0x0) {
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
      if (plVar4 != (long *)0x0) {
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
      goto LAB_fffffff0081c81bc;
    }
  }
  plVar11 = (long *)0x0;
LAB_fffffff0081c81bc:
  if (*(long *)PTR_DAT_fffffff007ca61a0 != local_70) {
    plVar4 = (long *)thunk_EXT_FUN_8011000003a48590();
    return plVar4;
  }
  return plVar11;
}

