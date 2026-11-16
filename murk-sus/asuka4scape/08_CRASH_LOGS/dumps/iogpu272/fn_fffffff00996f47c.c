// FUN_fffffff00996f47c @ fffffff00996f47c size=644

void FUN_fffffff00996f47c(long *param_1)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  long *plVar6;
  long *plVar7;
  long lVar8;
  long lVar9;
  long *plVar10;
  long *plVar11;
  ulong unaff_x30;
  
  if (DAT_fffffff00af227e8 != 0) {
    lVar8 = param_1[0x20];
    lVar9 = param_1[0x2e];
    uVar5 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
    thunk_EXT_FUN_80110000036da494(0x851801b1,lVar8,(int)lVar9,uVar5,0,0);
  }
  lVar9 = *(long *)(param_1[2] + 0x160);
  if ((param_1[0xc] == 0) ||
     (lVar8 = param_1[0xf], iVar3 = FUN_fffffff009962f24(lVar9), (int)lVar8 == iVar3)) {
    iVar3 = (**(code **)(*param_1 + 0x90))(param_1,*(undefined4 *)(lVar9 + 0x158));
    if (iVar3 == 0) {
      if ((long *)param_1[0x2c] != (long *)0x0) {
        plVar1 = param_1 + 0x2c;
        plVar10 = (long *)param_1[0x2c];
        do {
          plVar11 = (long *)plVar10[3];
          FUN_fffffff00996ed24(plVar10);
          plVar7 = (long *)*plVar1;
          if (plVar7 == plVar10) {
            lVar9 = plVar7[3];
            *plVar1 = lVar9;
            plVar6 = plVar1;
          }
          else {
            do {
              plVar6 = plVar7;
              plVar7 = (long *)plVar6[3];
            } while (plVar7 != plVar10);
            lVar9 = plVar7[3];
            plVar6 = plVar6 + 3;
            *plVar6 = lVar9;
          }
          if (lVar9 == 0) {
            param_1[0x2d] = (long)plVar6;
          }
          (**(code **)(*plVar10 + 0x28))(plVar10);
          *(int *)(param_1 + 0x2e) = (int)param_1[0x2e] + -1;
          plVar10 = plVar11;
        } while (plVar11 != (long *)0x0);
      }
      (**(code **)(*param_1 + 0x98))(param_1);
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s mapping descriptor prepare failed (0x%X)\n\n");
    }
  }
  else {
    if (param_1[0xd] != 0) {
      uVar4 = FUN_fffffff009962ebc(lVar9,param_1[0xc]);
      *(undefined4 *)(param_1[0xd] + 200) = uVar4;
    }
    (**(code **)(*param_1 + 0x88))(param_1);
  }
  (**(code **)(*(long *)param_1[2] + 0x6c0))();
  thunk_EXT_FUN_8011000002c12744(param_1[0x2a],param_1[0x2b]);
  if (DAT_fffffff00af227e8 != 0) {
    lVar8 = param_1[0x20];
    lVar9 = param_1[0x2e];
    uVar5 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996f6e0);
      (*pcVar2)();
    }
    thunk_EXT_FUN_80110000036da494(0x851801b2,lVar8,(int)lVar9,uVar5,0,0);
    return;
  }
  return;
}

