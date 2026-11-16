// FUN_fffffff009959e20 @ fffffff009959e20 size=1272

bool FUN_fffffff009959e20(long param_1,long param_2)

{
  int *piVar1;
  long *plVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined4 uVar7;
  long *plVar8;
  long lVar9;
  long *plVar10;
  undefined8 uVar11;
  long *plVar12;
  ulong uVar13;
  ulong local_68;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
  plVar2 = *(long **)(param_1 + 0x40);
  if ((*(byte *)(param_1 + 0x5d) & 1) == 0) {
joined_r0xfffffff009959e78:
    do {
      if (plVar2 == (long *)0x0) goto LAB_fffffff00995a278;
      plVar10 = plVar2 + 3;
      plVar12 = (long *)*plVar10;
      iVar4 = (int)plVar2[5];
      if (iVar4 < 3) {
        if (iVar4 == 1) {
          if (plVar12 == (long *)0x0) {
            plVar8 = (long *)plVar2[4];
            if ((long *)*plVar8 != plVar2) goto LAB_fffffff00995a2e0;
            *(long **)(param_1 + 0x48) = plVar8;
          }
          else {
            if ((long *)plVar12[4] != plVar10) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995a308);
              (*pcVar3)();
            }
            if (*(long **)plVar2[4] != plVar2) {
LAB_fffffff00995a2e0:
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995a2e8);
              (*pcVar3)();
            }
            plVar12[4] = (long)plVar2[4];
            plVar8 = (long *)plVar2[4];
          }
          *plVar8 = (long)plVar12;
          LOAcquire();
          *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
          LORelease();
          plVar2[3] = 0;
          plVar8 = *(long **)(param_2 + 8);
          plVar2[4] = (long)plVar8;
          *plVar8 = (long)plVar2;
          *(long **)(param_2 + 8) = plVar10;
          plVar2 = plVar12;
          goto joined_r0xfffffff009959e78;
        }
        if (iVar4 == 2) {
          if ((int)plVar2[7] != *(int *)(param_1 + 0x30)) goto LAB_fffffff00995a278;
          if (*(char *)((long)plVar2 + 0x3c) != '\0') {
            if (plVar2[6] != 0) {
              FUN_fffffff00995a318
                        (*(undefined8 *)(param_1 + 0x50),plVar2[6],*(undefined4 *)(param_1 + 0x58));
              plVar2[6] = 0;
            }
            goto LAB_fffffff00995a278;
          }
          lVar9 = *plVar10;
          if (lVar9 == 0) {
            plVar10 = (long *)plVar2[4];
            if ((long *)*plVar10 != plVar2) goto LAB_fffffff00995a2f0;
            *(long **)(param_1 + 0x48) = plVar10;
          }
          else {
            if (*(long **)(lVar9 + 0x20) != plVar10) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995a318);
              (*pcVar3)();
            }
            if (*(long **)plVar2[4] != plVar2) {
LAB_fffffff00995a2f0:
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995a2f8);
              (*pcVar3)();
            }
            *(long **)(lVar9 + 0x20) = (long *)plVar2[4];
            plVar10 = (long *)plVar2[4];
          }
          *plVar10 = lVar9;
          piVar1 = (int *)(param_1 + 0x2c);
          LOAcquire();
          iVar4 = *piVar1;
          *piVar1 = iVar4 + 1;
          LORelease();
          FUN_fffffff00995a390(CONCAT44((int)((ulong)piVar1 >> 0x20),iVar4),param_1,3,plVar2[6],0);
          (**(code **)(*plVar2 + 0x28))(plVar2);
          thunk_EXT_FUN_80110000036da494(0x8509010c,*(undefined8 *)(param_1 + 0x38),0,0,0,0);
          plVar2 = plVar12;
          goto joined_r0xfffffff009959e78;
        }
LAB_fffffff009959f6c:
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid Descriptor Type (%u)\n");
      }
      else {
        if (iVar4 == 3) {
          plVar8 = (long *)plVar2[6];
          uVar5 = thunk_EXT_FUN_8011000002c12750(plVar8);
          lVar9 = plVar2[7];
          thunk_EXT_FUN_8011000002c12744(uVar5,lVar9);
          uVar11 = *(undefined8 *)(param_1 + 0x38);
          uVar5 = thunk_EXT_FUN_8011000002c134f4(uVar5);
          thunk_EXT_FUN_80110000036da494(0x85090110,uVar11,uVar5,lVar9,0,0);
          (**(code **)(*plVar8 + 0x28))(plVar8);
          lVar9 = plVar2[3];
          if (lVar9 == 0) {
            plVar10 = (long *)plVar2[4];
            if ((long *)*plVar10 != plVar2) goto LAB_fffffff00995a2d8;
            *(long **)(param_1 + 0x48) = plVar10;
          }
          else {
            if (*(long **)(lVar9 + 0x20) != plVar10) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995a300);
              (*pcVar3)();
            }
            if (*(long **)plVar2[4] != plVar2) {
LAB_fffffff00995a2d8:
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995a2e0);
              (*pcVar3)();
            }
            *(long **)(lVar9 + 0x20) = (long *)plVar2[4];
            plVar10 = (long *)plVar2[4];
          }
          *plVar10 = lVar9;
          piVar1 = (int *)(param_1 + 0x2c);
          LOAcquire();
          iVar4 = *piVar1;
          *piVar1 = iVar4 + 1;
          uVar5 = CONCAT44((int)((ulong)piVar1 >> 0x20),iVar4);
          LORelease();
          uVar7 = 3;
        }
        else {
          if (iVar4 != 4) goto LAB_fffffff009959f6c;
          plVar8 = (long *)plVar2[6];
          uVar5 = thunk_EXT_FUN_8011000002c12750(plVar8);
          uVar13 = plVar2[7];
          uVar6 = thunk_EXT_FUN_8011000002c13500();
          if (uVar6 < uVar13) {
            if (*(int *)(*(long *)(param_1 + 0x50) + 0x14) == 1) {
              local_68 = 0;
              thunk_EXT_FUN_8011000003204ed8(5,1000000000,&local_68);
              iVar4 = thunk_EXT_FUN_8011000002c132ec(uVar5,uVar13,local_68);
              uVar7 = 2;
              if (iVar4 != 0) {
                uVar7 = 3;
              }
            }
            else {
              if (plVar2[8] == 0) {
                lVar9 = thunk_EXT_FUN_8011000003397c88();
                plVar2[8] = lVar9;
              }
              local_68 = 0;
              lVar9 = thunk_EXT_FUN_8011000003397c88();
              thunk_EXT_FUN_8011000003398228(lVar9 - plVar2[8],&local_68);
              if (local_68 < 5000000000) {
                FUN_fffffff00995a4ac(*(undefined8 *)(param_1 + 0x50));
                goto LAB_fffffff00995a278;
              }
              uVar7 = 2;
            }
          }
          else {
            uVar7 = 3;
          }
          uVar11 = *(undefined8 *)(param_1 + 0x38);
          uVar5 = thunk_EXT_FUN_8011000002c134f4(uVar5);
          thunk_EXT_FUN_80110000036da494(0x85090114,uVar11,uVar5,uVar13,uVar7,0);
          (**(code **)(*plVar8 + 0x28))(plVar8);
          lVar9 = *plVar10;
          if (lVar9 == 0) {
            plVar10 = (long *)plVar2[4];
            if ((long *)*plVar10 != plVar2) goto LAB_fffffff00995a2e8;
            *(long **)(param_1 + 0x48) = plVar10;
          }
          else {
            if (*(long **)(lVar9 + 0x20) != plVar10) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995a310);
              (*pcVar3)();
            }
            if (*(long **)plVar2[4] != plVar2) {
LAB_fffffff00995a2e8:
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995a2f0);
              (*pcVar3)();
            }
            *(long **)(lVar9 + 0x20) = (long *)plVar2[4];
            plVar10 = (long *)plVar2[4];
          }
          *plVar10 = lVar9;
          piVar1 = (int *)(param_1 + 0x2c);
          LOAcquire();
          iVar4 = *piVar1;
          *piVar1 = iVar4 + 1;
          uVar5 = CONCAT44((int)((ulong)piVar1 >> 0x20),iVar4);
          LORelease();
        }
        FUN_fffffff00995a390(uVar5,param_1,uVar7,0,0);
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
      plVar2 = plVar12;
    } while( true );
  }
  if (*(long **)(param_1 + 0x40) != (long *)0x0) {
    FUN_fffffff0099597b4(param_1,1);
  }
LAB_fffffff00995a278:
  lVar9 = *(long *)(param_1 + 0x40);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
  return lVar9 == 0;
}

