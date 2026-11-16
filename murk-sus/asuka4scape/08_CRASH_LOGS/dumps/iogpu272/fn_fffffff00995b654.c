// FUN_fffffff00995b654 @ fffffff00995b654 size=848

undefined8 FUN_fffffff00995b654(long param_1)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  long lVar8;
  long *plVar9;
  long *plVar10;
  long *plVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  long lVar14;
  
  lVar5 = thunk_EXT_FUN_8011000003739e28(1,0,0,0);
  if (lVar5 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to create uio\n");
  }
  else {
    if ((*(byte *)(param_1 + 0x74) & 1) == 0) {
      iVar3 = 0;
      plVar10 = (long *)0x0;
      do {
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x68));
        plVar11 = *(long **)(param_1 + 0x58);
        if (plVar11 == (long *)0x0) {
          do {
            if (plVar10 != (long *)0x0) {
              (**(code **)(*plVar10 + 0x28))(plVar10);
            }
            *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
            iVar3 = thunk_EXT_FUN_80110000038ff064(*(undefined8 *)(param_1 + 0x68),param_1,1);
            *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + -1;
            if (iVar3 == 2) {
              *(undefined1 *)(param_1 + 0x74) = 1;
              if (*(int *)(param_1 + 0x70) != 0) {
                thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x68),param_1,0);
              }
LAB_fffffff00995b934:
              thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x68));
              goto LAB_fffffff00995b93c;
            }
            if ((*(byte *)(param_1 + 0x74) & 1) != 0) goto LAB_fffffff00995b934;
            plVar10 = (long *)0x0;
            plVar11 = *(long **)(param_1 + 0x58);
          } while (plVar11 == (long *)0x0);
          iVar3 = 0;
        }
        lVar8 = plVar11[3];
        if (lVar8 == 0) {
          plVar9 = (long *)plVar11[4];
          if ((long *)*plVar9 != plVar11) goto LAB_fffffff00995b994;
          *(long **)(param_1 + 0x60) = plVar9;
        }
        else {
          if (*(long **)(lVar8 + 0x20) != plVar11 + 3) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995b9a4);
            (*pcVar2)();
          }
          if (*(long **)plVar11[4] != plVar11) {
LAB_fffffff00995b994:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995b99c);
            (*pcVar2)();
          }
          *(long **)(lVar8 + 0x20) = (long *)plVar11[4];
          plVar9 = (long *)plVar11[4];
        }
        *plVar9 = lVar8;
        if ((*(int *)(param_1 + 0x70) != 0) && (*(long *)(param_1 + 0x58) != 0)) {
          thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x68),param_1,1);
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x68));
        lVar8 = plVar11[10];
        uVar12 = *(undefined8 *)(plVar11[2] + 0x38);
        uVar13 = *(undefined8 *)(param_1 + 0x30);
        bVar1 = *(byte *)(plVar11[2] + 0x5d);
        thunk_EXT_FUN_80110000036da494(0x85090109,uVar13,uVar12,plVar11[8],0,0);
        if ((bVar1 & 1) == 0) {
          if (iVar3 != (int)plVar11[6]) {
            iVar3 = (int)plVar11[6];
            if (plVar10 != (long *)0x0) {
              (**(code **)(*plVar10 + 0x28))(plVar10);
              iVar3 = (int)plVar11[6];
            }
            plVar10 = (long *)FUN_fffffff009967ba8(*(undefined8 *)(param_1 + 0x78),iVar3);
          }
          if (plVar10 == (long *)0x0) {
            lVar14 = 0;
            uVar7 = 2;
          }
          else {
            lVar14 = plVar10[4];
            thunk_EXT_FUN_801100000373a074(lVar5,plVar11[7],0,0);
            thunk_EXT_FUN_801100000373a224(lVar5,plVar11[9],plVar11[8]);
            uVar6 = FUN_fffffff009964928(plVar10);
            iVar4 = thunk_EXT_FUN_80110000034138c0(uVar6,lVar5);
            uVar7 = 2;
            if (iVar4 == 0) {
              uVar7 = 3;
            }
          }
        }
        else {
          lVar14 = 0;
          uVar7 = 1;
        }
        thunk_EXT_FUN_80110000036da494(0x8509010a,uVar13,uVar12,lVar14,uVar7,0);
        FUN_fffffff00995a390(plVar11[2],uVar7,lVar8,1);
        (**(code **)(*plVar11 + 0x28))(plVar11);
      } while ((*(byte *)(param_1 + 0x74) & 1) == 0);
      if (plVar10 != (long *)0x0) {
        (**(code **)(*plVar10 + 0x28))(plVar10);
      }
    }
LAB_fffffff00995b93c:
    thunk_EXT_FUN_801100000373a14c(lVar5);
  }
  return 0xe00002eb;
}

