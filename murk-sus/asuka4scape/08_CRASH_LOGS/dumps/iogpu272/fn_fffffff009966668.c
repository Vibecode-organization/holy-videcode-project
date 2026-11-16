// FUN_fffffff009966668 @ fffffff009966668 size=888

undefined8 FUN_fffffff009966668(long param_1,int param_2,undefined8 param_3,int *param_4)

{
  byte bVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  long *plVar6;
  undefined8 uVar7;
  int local_54;
  
  if (param_2 == 0) {
    return 0xe00002c2;
  }
  if (param_4 == (int *)0x0) {
    return 0xe00002c2;
  }
  iVar2 = (int)param_3;
  if (5 < iVar2 - 1U) {
    return 0xe00002c2;
  }
  plVar3 = (long *)FUN_fffffff009945040(*(undefined8 *)(param_1 + 0x10));
  if (plVar3 == (long *)0x0) {
    return 0xe00002c2;
  }
  plVar4 = (long *)FUN_fffffff00995598c();
  if (plVar4 == (long *)0x0) {
    uVar7 = 0xe0000001;
    goto LAB_fffffff009966998;
  }
  (**(code **)(*plVar4 + 0x20))();
  if (plVar4 != plVar3) {
    (**(code **)(*plVar4 + 0x20))(plVar4);
    (**(code **)(*plVar3 + 0x28))(plVar3);
    plVar3 = plVar4;
  }
  bVar1 = *(byte *)(plVar3 + 2);
  if (bVar1 < 0x40) {
    if (bVar1 != 0) {
      if ((bVar1 == 3) &&
         (lVar5 = thunk_EXT_FUN_8011000003890f30(plVar3[5],DAT_fffffff007fed428), lVar5 != 0)) {
        if (iVar2 == 5) {
          iVar2 = FUN_fffffff009943644(lVar5);
          if (iVar2 != 0) {
LAB_fffffff0099669d8:
            iVar2 = 4;
            goto LAB_fffffff009966978;
          }
          *(long *)(*(long *)(param_1 + 0x48) + 0x168) =
               *(long *)(*(long *)(param_1 + 0x48) + 0x168) + 1;
          FUN_fffffff0099437a0(lVar5);
          iVar2 = FUN_fffffff00994b7a8(*(undefined8 *)(*(long *)(param_1 + 0x48) + 0x148));
          if (iVar2 != 0) {
            FUN_fffffff009960834(*(undefined8 *)(*(long *)(param_1 + 0x48) + 0x160));
          }
        }
        else if (iVar2 == 1) {
          iVar2 = FUN_fffffff0099437f4(lVar5);
          if (iVar2 == 0) goto LAB_fffffff0099669d8;
        }
        else {
          if (iVar2 != 6) goto LAB_fffffff00996697c;
          iVar2 = FUN_fffffff009942c08(lVar5);
          if (iVar2 != 0) {
            FUN_fffffff00996c464(lVar5);
            goto LAB_fffffff0099669d8;
          }
        }
      }
LAB_fffffff009966974:
      iVar2 = 2;
      goto LAB_fffffff009966978;
    }
LAB_fffffff0099667d0:
    lVar5 = thunk_EXT_FUN_8011000003890f30(plVar3[5],DAT_fffffff007fefaf0);
    if (lVar5 == 0) goto LAB_fffffff009966974;
    if (iVar2 == 5) {
      iVar2 = FUN_fffffff009943644(lVar5);
      if (iVar2 == 0) {
        FUN_fffffff0099437a0(lVar5);
      }
      goto LAB_fffffff009966974;
    }
    if (iVar2 - 1U < 4) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x28));
      local_54 = 0;
      plVar6 = (long *)FUN_fffffff009981d0c(lVar5);
      iVar2 = (**(code **)(*plVar6 + 0x80))(plVar6,param_3,&local_54);
      if (iVar2 != 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Failed to set purgeable state 0x%x\n");
      }
      iVar2 = local_54;
      if (2 < local_54 - 2U) {
        iVar2 = 1;
      }
      *param_4 = iVar2;
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x28));
      (**(code **)(*plVar6 + 0x28))(plVar6);
    }
  }
  else {
    if (bVar1 != 0x40) {
      if (bVar1 == 0x80) goto LAB_fffffff0099667d0;
      goto LAB_fffffff009966974;
    }
    lVar5 = thunk_EXT_FUN_8011000003890f30(plVar3[5],DAT_fffffff007fe8e10);
    if (lVar5 == 0) goto LAB_fffffff009966974;
    if (iVar2 == 5) {
      iVar2 = FUN_fffffff009943644(lVar5);
      if (iVar2 == 0) {
        FUN_fffffff0099437a0(lVar5);
      }
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Unsupported purgeability option (%u)\n");
    }
    iVar2 = 4;
    if (*(long *)(lVar5 + 0x80) != 0) {
      iVar2 = 2;
    }
LAB_fffffff009966978:
    *param_4 = iVar2;
  }
LAB_fffffff00996697c:
  (**(code **)(*plVar4 + 0x28))(plVar4);
  uVar7 = 0;
LAB_fffffff009966998:
  (**(code **)(*plVar3 + 0x28))(plVar3);
  return uVar7;
}

