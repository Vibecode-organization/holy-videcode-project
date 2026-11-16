// FUN_fffffff00817e15c @ fffffff00817e15c size=1000

undefined8 FUN_fffffff00817e15c(long param_1,long *param_2,undefined8 param_3,long param_4)

{
  uint uVar1;
  byte bVar2;
  code *pcVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  undefined8 uVar8;
  long *plVar9;
  int iVar10;
  long *plVar11;
  
  thunk_EXT_FUN_80110000032222a8(param_2[3]);
  if (param_2[6] == param_4) {
    iVar10 = (int)param_2[5] + -1;
    *(int *)(param_2 + 5) = iVar10;
    lVar5 = param_2[2];
    if ((*(byte *)(lVar5 + 0x1ac44) >> 3 & 1) != 0) {
      lVar6 = param_2[4];
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930c70,param_2,(int)lVar6,iVar10,param_4,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x1ac48));
      iVar10 = (int)param_2[5];
    }
    if (((iVar10 == 0) && ((int)param_2[4] != 0)) &&
       (plVar7 = (long *)param_2[0xe], plVar7 != (long *)0x0)) {
      plVar11 = (long *)plVar7[0x1b];
      if (param_2 != plVar11) {
        lVar5 = **(long **)(param_2[0x10] + 8);
        if ((*(byte *)(param_2 + 9) & 1) == 0) {
          if ((*(byte *)((long)param_2 + 0x49) & 1) == 0) goto LAB_fffffff00817e284;
LAB_fffffff00817e464:
          lVar6 = param_2[0xb];
          *(int *)(lVar5 + 0x60) = (int)param_2[0xc];
          *(long *)(lVar5 + 0x58) = lVar6;
          bVar2 = *(byte *)((long)param_2 + 0x4a);
        }
        else {
          uVar8 = *(undefined8 *)((long)param_2 + 0x4c);
          *(undefined4 *)(lVar5 + 0x54) = *(undefined4 *)((long)param_2 + 0x54);
          *(undefined8 *)(lVar5 + 0x4c) = uVar8;
          if ((*(byte *)((long)param_2 + 0x49) & 1) != 0) goto LAB_fffffff00817e464;
LAB_fffffff00817e284:
          bVar2 = *(byte *)((long)param_2 + 0x4a);
        }
        if ((bVar2 & 1) != 0) {
          uVar8 = *(undefined8 *)((long)param_2 + 100);
          *(undefined4 *)(lVar5 + 0x6c) = *(undefined4 *)((long)param_2 + 0x6c);
          *(undefined8 *)(lVar5 + 100) = uVar8;
        }
      }
      lVar5 = param_2[0xf];
      if (lVar5 == 0) {
        plVar9 = (long *)param_2[0x10];
        if ((long *)*plVar9 != param_2) goto LAB_fffffff00817e52c;
        plVar7[0x1c] = (long)plVar9;
      }
      else {
        if (*(long **)(lVar5 + 0x80) != param_2 + 0xf) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817e544);
          (*pcVar3)();
        }
        if (*(long **)param_2[0x10] != param_2) {
LAB_fffffff00817e52c:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817e534);
          (*pcVar3)();
        }
        *(long **)(lVar5 + 0x80) = (long *)param_2[0x10];
        plVar9 = (long *)param_2[0x10];
      }
      *plVar9 = lVar5;
      lVar5 = plVar7[0x18];
      if ((*(byte *)(lVar5 + 0x1ac44) >> 3 & 1) != 0) {
        lVar6 = plVar7[0x1b];
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494
                  (0x85930c78,param_2,lVar6 == 0,0xffffffff,param_2 == plVar11,0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x1ac48));
      }
      lVar5 = thunk_EXT_FUN_8011000003397c88();
      plVar7[0x1f] = lVar5;
      if (param_2 == plVar11) {
        lVar5 = plVar7[0x18];
        if (((*(byte *)(lVar5 + 0x10a73) & 1) != 0) && ((*(byte *)(lVar5 + 0x5b8) & 1) != 0)) {
          uVar4 = thunk_EXT_FUN_801100000294780c(*(undefined8 *)(lVar5 + 0x148));
          if ((uVar4 & 1) == 0) {
            (**(code **)(**(long **)(lVar5 + 0x4b0) + 0x3b8))();
            thunk_EXT_FUN_8011000003204ed8(*(undefined4 *)(lVar5 + 0x23c),1000000000,lVar5 + 0x5c0);
            thunk_EXT_FUN_801100000295f33c
                      (*(undefined8 *)(lVar5 + 0x160),*(undefined8 *)(lVar5 + 0x5c0));
          }
          else {
            thunk_EXT_FUN_801100000295f3b0(*(undefined8 *)(lVar5 + 0x160));
            *(undefined1 *)(lVar5 + 0x5b8) = 0;
          }
        }
        (**(code **)(*plVar7 + 0xf0))(plVar7,param_2);
      }
    }
  }
  else if ((*(byte *)(param_2[2] + 0x1ac44) >> 3 & 1) != 0) {
    FUN_fffffff00817dc48(param_2[2],0x321,0,param_2,param_4,param_2[6],0,0);
  }
  thunk_EXT_FUN_8011000003222de0(param_2[3]);
  if ((int)param_2[5] == 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x11e48));
    if ((*(byte *)((long)param_2 + 0xc) & 1) != 0) {
      lVar5 = param_2[7];
      if (lVar5 == 0) {
        plVar7 = (long *)param_2[8];
        if ((long *)*plVar7 != param_2) goto LAB_fffffff00817e524;
        *(long **)(param_1 + 0x11ee0) = plVar7;
      }
      else {
        if (*(long **)(lVar5 + 0x40) != param_2 + 7) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817e53c);
          (*pcVar3)();
        }
        if (*(long **)param_2[8] != param_2) {
LAB_fffffff00817e524:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817e52c);
          (*pcVar3)();
        }
        *(long **)(lVar5 + 0x40) = (long *)param_2[8];
        plVar7 = (long *)param_2[8];
      }
      *plVar7 = lVar5;
      *(undefined1 *)((long)param_2 + 0xc) = 0;
      FUN_fffffff0081e1178(param_2);
      uVar1 = *(uint *)(param_1 + 0x11ed0);
      if (uVar1 < 0x10) {
        *(uint *)(param_1 + 0x11ed0) = uVar1 + 1;
        lVar5 = (ulong)uVar1 * 8;
        plVar7 = (long *)(param_1 + 0x11e50 + (long)(int)lVar5);
        if (lVar5 - (int)lVar5 != 0) {
          plVar7 = (long *)(param_1 + 0x11e50 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *plVar7 = (long)param_2;
      }
      else {
        (**(code **)(*param_2 + 0x28))(param_2);
      }
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x11e48));
  }
  (**(code **)(*param_2 + 0x28))(param_2);
  return 0;
}

