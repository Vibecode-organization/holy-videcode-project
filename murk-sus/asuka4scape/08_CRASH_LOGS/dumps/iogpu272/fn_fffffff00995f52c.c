// FUN_fffffff00995f52c @ fffffff00995f52c size=324

void FUN_fffffff00995f52c(long param_1,int param_2,ulong param_3)

{
  int iVar1;
  code *pcVar2;
  bool bVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  bool bVar7;
  long lVar8;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x150));
  if (*(int *)(param_1 + 0x198) != 0) {
    if ((((*(byte *)(*(long *)(param_1 + 0x1a8) + 0x1ff) >> 5 & 1) == 0) && (param_2 == 2)) &&
       (param_3 != 0)) {
      bVar7 = false;
      iVar1 = *(int *)(*(long *)(param_1 + 0x140) + 0x6c);
      lVar6 = *(long *)(param_1 + 0x140);
      do {
        lVar8 = *(long *)(lVar6 + 0x20);
        if (((iVar1 == *(int *)(lVar6 + 0x6c)) && ((*(byte *)(lVar6 + 0x62) & 1) == 0)) &&
           (((*(byte *)(lVar6 + 0x61) & 1) == 0 && (uVar4 = FUN_fffffff00995d1bc(lVar6), uVar4 != 0)
            ))) {
          bVar3 = param_3 < uVar4;
          param_3 = param_3 - uVar4;
          if (bVar3) break;
          bVar7 = true;
          *(undefined1 *)(lVar6 + 100) = 1;
          thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x150),lVar6,1);
        }
        lVar6 = lVar8;
      } while (lVar8 != 0);
      if (bVar7) goto LAB_fffffff00995f644;
    }
    lVar6 = *(long *)(param_1 + 0x140);
    if (lVar6 != 0) {
      if (DAT_fffffff00af227e8 != 0) {
        uVar5 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
        thunk_EXT_FUN_80110000036da494(0x85180140,uVar5,*(undefined8 *)(lVar6 + 200),0,param_2,0);
      }
      thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x150),lVar6,1);
    }
  }
LAB_fffffff00995f644:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995f66c);
    (*pcVar2)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x150));
  return;
}

