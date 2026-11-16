// FUN_fffffff009c0d250 @ fffffff009c0d250

/* WARNING: Removing unreachable block (ram,0xfffffff009c0d748) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0d8f4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0e2e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0e104) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0e08c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0e014) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0dc78) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0dbfc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0ded4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0e050) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0e0c8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0e140) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0d8b4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0d6d8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0d81c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0d9bc) */

long * FUN_fffffff009c0d250(long *param_1,long *param_2,long *param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  byte *pbVar10;
  ulong uVar11;
  long *plVar12;
  long *plVar13;
  long *plVar14;
  ulong uVar15;
  long *plVar16;
  long *plVar17;
  char *pcVar18;
  char *pcVar19;
  long lVar20;
  long *plVar21;
  long *plVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  long lVar28;
  uint uVar29;
  undefined8 local_78;
  undefined4 local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff008064be8;
  uVar5 = (**(code **)(*param_3 + 0x98))(param_3);
  plVar6 = thunk_FUN_fffffff00a8d0c44(uVar5);
  if (plVar6 == (long *)0x0) goto LAB_fffffff009c0e558;
  uVar5 = (**(code **)(*param_2 + 0x98))(param_2);
  plVar7 = thunk_FUN_fffffff00a8cc688(uVar5,&LAB_fffffff009c0e594,0);
  if (plVar7 == (long *)0x0) {
    plVar9 = (long *)0x0;
LAB_fffffff009c0e4e4:
    (**(code **)(*plVar6 + 0x28))(plVar6);
    if (plVar7 != (long *)0x0) {
      (**(code **)(*plVar7 + 0x28))(plVar7);
    }
    plVar6 = (long *)0x0;
    plVar7 = (long *)0x0;
    if (plVar9 == (long *)0x0) goto LAB_fffffff009c0e558;
  }
  else {
    plVar8 = thunk_FUN_fffffff00a89ca6c(param_2);
    plVar9 = (long *)0x0;
    if (plVar8 == (long *)0x0) goto LAB_fffffff009c0e4e4;
    plVar9 = (long *)(**(code **)(*plVar8 + 0x88))(plVar8);
    if (plVar9 == (long *)0x0) {
      uVar29 = 0;
    }
    else {
      uVar29 = 0;
      do {
        pbVar10 = (byte *)(**(code **)(*plVar9 + 0x218))(plVar9,0);
        uVar11 = thunk_FUN_fffffff00a9beff8(pbVar10,(undefined8 *)0x0,10);
        if (uVar29 <= (uint)uVar11) {
          uVar29 = (uint)uVar11;
        }
        (**(code **)(*plVar7 + 0xd8))(plVar7,plVar9);
        plVar9 = (long *)(**(code **)(*plVar8 + 0x88))(plVar8);
      } while (plVar9 != (long *)0x0);
    }
    (**(code **)(*plVar8 + 0x28))(plVar8);
    uVar5 = (**(code **)(*param_3 + 0x98))(param_3);
    plVar9 = thunk_FUN_fffffff00a8cc688(uVar5,&LAB_fffffff009c0e594,0);
    if ((plVar9 == (long *)0x0) ||
       (plVar8 = thunk_FUN_fffffff00a89ca6c(param_3), plVar8 == (long *)0x0))
    goto LAB_fffffff009c0e4e4;
    plVar12 = (long *)(**(code **)(*plVar8 + 0x88))();
    while (plVar12 != (long *)0x0) {
      pbVar10 = (byte *)(**(code **)(*plVar12 + 0x218))(plVar12,0);
      uVar11 = thunk_FUN_fffffff00a9beff8(pbVar10,(undefined8 *)0x0,10);
      if (uVar29 <= (uint)uVar11) {
        uVar29 = (uint)uVar11;
      }
      (**(code **)(*plVar9 + 0xd8))(plVar9,plVar12);
      plVar12 = (long *)(**(code **)(*plVar8 + 0x88))(plVar8);
    }
    (**(code **)(*plVar8 + 0x28))(plVar8);
    plVar8 = thunk_FUN_fffffff00a89ca6c(plVar7);
    if (plVar8 == (long *)0x0) goto LAB_fffffff009c0e4e4;
    plVar12 = thunk_FUN_fffffff00a89ca6c(plVar9);
    if (plVar12 == (long *)0x0) {
      plVar16 = (long *)0x0;
LAB_fffffff009c0e480:
      (**(code **)(*plVar8 + 0x28))(plVar8);
      if (plVar12 != (long *)0x0) {
        (**(code **)(*plVar12 + 0x28))(plVar12);
      }
      if (plVar16 != (long *)0x0) {
        (**(code **)(*plVar16 + 0x28))(plVar16);
      }
      goto LAB_fffffff009c0e4e4;
    }
    plVar13 = (long *)(**(code **)(*plVar8 + 0x88))(plVar8);
    plVar14 = (long *)(**(code **)(*plVar12 + 0x88))(plVar12);
    if (plVar13 != (long *)0x0 || plVar14 != (long *)0x0) {
      do {
        if (plVar13 == (long *)0x0) {
          uVar11 = 0xffffffffffffffff;
          if (plVar14 == (long *)0x0) goto LAB_fffffff009c0d5e8;
LAB_fffffff009c0d5f8:
          uVar15 = (**(code **)(*plVar14 + 0x5b0))(plVar14);
        }
        else {
          uVar11 = (**(code **)(*plVar13 + 0x5b0))(plVar13);
          if (plVar14 != (long *)0x0) goto LAB_fffffff009c0d5f8;
LAB_fffffff009c0d5e8:
          uVar15 = 0xffffffffffffffff;
        }
        if (uVar15 <= uVar11 && uVar11 != uVar15) {
          (**(code **)(*plVar14 + 0xd8))(plVar14,&DAT_fffffff007899200,1);
          plVar16 = thunk_FUN_fffffff00a89ca6c(plVar7);
          if (plVar16 == (long *)0x0) {
LAB_fffffff009c0e474:
            plVar16 = (long *)0x0;
            goto LAB_fffffff009c0e480;
          }
          do {
            plVar17 = (long *)(**(code **)(*plVar16 + 0x88))(plVar16);
            if (plVar17 == (long *)0x0) goto LAB_fffffff009c0d790;
            pcVar18 = (char *)(**(code **)(*plVar17 + 0x218))(plVar17,0);
            pcVar19 = (char *)(**(code **)(*plVar14 + 0x218))(*plVar14 + 0x218,plVar14,0);
            iVar2 = thunk_FUN_fffffff00aa7451c(pcVar18,pcVar19);
          } while (iVar2 != 0);
          local_70 = 0;
          local_78 = 0;
          thunk_FUN_fffffff00a76d3ec((undefined1 *)&local_78,0xc,&DAT_fffffff0078989ee);
          (**(code **)(*plVar14 + 0x230))(*plVar14 + 0x230,plVar14,&local_78,0);
          (**(code **)(*plVar14 + 0xd8))(plVar14,&DAT_fffffff007899200,0);
LAB_fffffff009c0d790:
          (**(code **)(*plVar16 + 0x28))(plVar16);
          iVar2 = (**(code **)(*plVar14 + 0x360))(plVar14,param_1);
          if (iVar2 != 0) {
            (**(code **)(*param_1 + 0x5a0))(param_1,plVar14);
            (**(code **)(*plVar14 + 0x2a0))(*plVar14 + 0x2a0,plVar14,8);
          }
          (**(code **)(*plVar6 + 0xf0))(plVar6,plVar14);
LAB_fffffff009c0e360:
          plVar14 = (long *)(**(code **)(*plVar12 + 0x88))();
        }
        else {
          if (uVar15 <= uVar11) {
            plVar16 = thunk_FUN_fffffff00a8d0c44(1);
            if (plVar16 == (long *)0x0) goto LAB_fffffff009c0e474;
            uVar5 = thunk_FUN_fffffff00a9123a8((long)plVar14);
            lVar28 = (**(code **)(*plVar13 + 0x5b0))(plVar13);
            lVar20 = (**(code **)(*plVar14 + 0x5b0))(*plVar14 + 0x5b0,plVar14);
            if (lVar28 == lVar20) {
              lVar28 = (**(code **)(*plVar13 + 0x5a8))(plVar13);
              lVar20 = (**(code **)(*plVar14 + 0x5a8))(plVar14);
              if (lVar28 != lVar20) goto LAB_fffffff009c0dbb0;
              lVar28 = (**(code **)(*plVar13 + 0x5a0))(plVar13);
              lVar20 = (**(code **)(*plVar14 + 0x5a0))(plVar14);
              if (lVar28 != lVar20) goto LAB_fffffff009c0dbb0;
              iVar2 = (**(code **)(*plVar13 + 0x5f0))(plVar13);
              iVar3 = (**(code **)(*plVar14 + 0x5f0))(plVar14);
              if (iVar2 != iVar3) goto LAB_fffffff009c0dbb0;
              iVar2 = (**(code **)(*plVar13 + 0x5c8))(plVar13);
              iVar3 = (**(code **)(*plVar14 + 0x5c8))(plVar14);
              if (iVar2 != iVar3) goto LAB_fffffff009c0dbb0;
              iVar2 = (**(code **)(*plVar13 + 0x5d0))(plVar13);
              iVar3 = (**(code **)(*plVar14 + 0x5d0))(plVar14);
              if (iVar2 != iVar3) goto LAB_fffffff009c0dbb0;
              pcVar18 = (char *)(**(code **)(*plVar13 + 0x5e0))(plVar13);
              pcVar19 = (char *)(**(code **)(*plVar14 + 0x5e0))(plVar14);
              iVar2 = thunk_FUN_fffffff00aa7451c(pcVar18,pcVar19);
              if (iVar2 != 0) goto LAB_fffffff009c0dbb0;
              bVar1 = false;
            }
            else {
LAB_fffffff009c0dbb0:
              bVar1 = true;
            }
            pcVar18 = (char *)(**(code **)(*plVar13 + 0x1e8))(plVar13,0);
            pcVar19 = (char *)(**(code **)(*plVar14 + 0x1e8))(*plVar14 + 0x1e8,plVar14,0);
            iVar2 = thunk_FUN_fffffff00aa7451c(pcVar18,pcVar19);
            if (iVar2 == 0) {
              pcVar18 = (char *)(**(code **)(*plVar13 + 0x218))(plVar13,0);
              pcVar19 = (char *)(**(code **)(*plVar14 + 0x218))(*plVar14 + 0x218,plVar14,0);
              iVar2 = thunk_FUN_fffffff00aa7451c(pcVar18,pcVar19);
              if (iVar2 != 0) goto LAB_fffffff009c0dca8;
              uVar4 = 1;
            }
            else {
LAB_fffffff009c0dca8:
              uVar4 = 0;
            }
            plVar17 = thunk_FUN_fffffff00a89ca6c(uVar5);
            if (plVar17 != (long *)0x0) {
              plVar21 = (long *)(**(code **)(*plVar17 + 0x88))();
              while (plVar21 != (long *)0x0) {
                uVar11 = (**(code **)(*plVar21 + 0xb8))(plVar21,"Content Hint");
                if ((((((((uVar11 & 1) == 0) &&
                        (uVar11 = (**(code **)(*plVar21 + 0xb8))(plVar21,"Ejectable"),
                        (uVar11 & 1) == 0)) &&
                       (uVar11 = (**(code **)(*plVar21 + 0xb8))(plVar21,"Preferred Block Size"),
                       (uVar11 & 1) == 0)) &&
                      ((uVar11 = (**(code **)(*plVar21 + 0xb8))(plVar21,"Removable"),
                       (uVar11 & 1) == 0 &&
                       (uVar11 = (**(code **)(*plVar21 + 0xb8))(plVar21,&DAT_fffffff00789929a),
                       (uVar11 & 1) == 0)))) &&
                     ((uVar11 = (**(code **)(*plVar21 + 0xb8))(plVar21,"Whole"), (uVar11 & 1) == 0
                      && ((uVar11 = (**(code **)(*plVar21 + 0xb8))(plVar21,"Writable"),
                          (uVar11 & 1) == 0 &&
                          (uVar11 = (**(code **)(*plVar21 + 0xb8))(plVar21,"Content"),
                          (uVar11 & 1) == 0)))))) &&
                    (uVar11 = (**(code **)(*plVar21 + 0xb8))(plVar21,&DAT_fffffff007899271),
                    (uVar11 & 1) == 0)) &&
                   ((uVar11 = (**(code **)(*plVar21 + 0xb8))(plVar21,&DAT_fffffff007899200),
                    (uVar11 & 1) == 0 &&
                    (uVar11 = (**(code **)(*plVar21 + 0xb8))(plVar21,&DAT_fffffff007899276),
                    (uVar11 & 1) == 0)))) {
                  plVar22 = (long *)(**(code **)(*plVar13 + 0x108))(plVar13,plVar21);
                  uVar5 = (**(code **)(*plVar14 + 0x108))(*plVar14 + 0x108,plVar14,plVar21);
                  if ((plVar22 == (long *)0x0) ||
                     (uVar11 = (**(code **)(*plVar22 + 0x40))(plVar22,uVar5), (uVar11 & 1) == 0)) {
                    (**(code **)(*plVar16 + 0xf0))(plVar16,plVar21);
                  }
                }
                plVar21 = (long *)(**(code **)(*plVar17 + 0x88))(plVar17);
              }
              (**(code **)(*plVar17 + 0x28))(plVar17);
              (**(code **)(*plVar13 + 0xd8))(plVar13,&DAT_fffffff007899200,uVar4);
              if (bVar1) {
                uVar5 = (**(code **)(*plVar14 + 0x5b0))(plVar14);
                uVar23 = (**(code **)(*plVar14 + 0x5a8))(plVar14);
                uVar24 = (**(code **)(*plVar14 + 0x5a0))(*plVar14 + 0x5a0,plVar14);
                uVar4 = (**(code **)(*plVar14 + 0x5f0))(*plVar14 + 0x5f0,plVar14);
                uVar25 = (**(code **)(*plVar14 + 0x5c8))(*plVar14 + 0x5c8,plVar14);
                uVar26 = (**(code **)(*plVar14 + 0x5d0))(*plVar14 + 0x5d0,plVar14);
                uVar27 = (**(code **)(*plVar14 + 0x5e0))(*plVar14 + 0x5e0,plVar14);
                (**(code **)(*plVar13 + 0x5e8))
                          (*plVar13 + 0x5e8,plVar13,uVar5,uVar23,uVar24,uVar4,uVar25,uVar26,uVar27,0
                          );
              }
              iVar2 = (**(code **)(*plVar16 + 0x90))(plVar16);
              if (iVar2 != 0) {
                plVar17 = thunk_FUN_fffffff00a89ca6c(plVar16);
                if (plVar17 == (long *)0x0) goto LAB_fffffff009c0e480;
                lVar28 = (**(code **)(*plVar17 + 0x88))();
                while (lVar28 != 0) {
                  uVar5 = (**(code **)(*plVar14 + 0x108))(plVar14,lVar28);
                  (**(code **)(*plVar13 + 0xb8))(plVar13,lVar28,uVar5);
                  lVar28 = (**(code **)(*plVar17 + 0x88))(plVar17);
                }
                (**(code **)(*plVar17 + 0x28))(plVar17);
              }
              if ((bVar1) || (iVar2 = (**(code **)(*plVar16 + 0x90))(plVar16), iVar2 != 0)) {
                (**(code **)(*plVar13 + 0x430))(plVar13,0xe0000130,0,0);
                (**(code **)(*plVar13 + 0x2a0))(*plVar13 + 0x2a0,plVar13,8);
              }
              (**(code **)(*plVar16 + 0x28))(plVar16);
              (**(code **)(*plVar6 + 0xf0))(plVar6,plVar13);
              plVar13 = (long *)(**(code **)(*plVar8 + 0x88))();
              goto LAB_fffffff009c0e360;
            }
            goto LAB_fffffff009c0e480;
          }
          (**(code **)(*plVar13 + 0xd8))(plVar13,&DAT_fffffff007899200,0);
          uVar11 = (**(code **)(*param_1 + 0x2e8))(*param_1 + 0x2e8,param_1,plVar13);
          lVar28 = *plVar13;
          if ((uVar11 & 1) == 0) {
            (**(code **)(lVar28 + 0x2f0))(lVar28 + 0x2f0,plVar13,0);
            (**(code **)(*param_1 + 0x5a8))(param_1,plVar13);
          }
          else {
            (**(code **)(lVar28 + 0x100))(lVar28 + 0x100,plVar13,"Partition ID");
            (**(code **)(*plVar6 + 0xf0))(plVar6,plVar13);
          }
          plVar13 = (long *)(**(code **)(*plVar8 + 0x88))();
        }
      } while (plVar13 != (long *)0x0 || plVar14 != (long *)0x0);
    }
    (**(code **)(*plVar8 + 0x28))();
    (**(code **)(*plVar12 + 0x28))();
    (**(code **)(*plVar7 + 0x28))(plVar7);
    plVar7 = plVar6;
  }
  plVar6 = plVar7;
  (**(code **)(*plVar9 + 0x28))(plVar9);
LAB_fffffff009c0e558:
  if (*(long *)PTR_DAT_fffffff008064be8 != local_68) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return plVar6;
}

