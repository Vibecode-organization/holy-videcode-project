// FUN_fffffff00aa3cb40 @ fffffff00aa3cb40 size=748

int FUN_fffffff00aa3cb40
              (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined4 param_5,
              undefined8 *param_6)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  code *pcVar7;
  int iVar8;
  ulong uVar9;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  
  lVar4 = FUN_fffffff00a29b0b4();
  if (lVar4 == 0) {
    lVar4 = 0;
    lVar2 = *(long *)(param_1 + 0x3f0);
  }
  else {
    lVar4 = FUN_fffffff00aa3ca04();
    lVar2 = lVar4;
  }
  if (lVar2 == 0) {
    iVar8 = 1;
  }
  else {
    if (DAT_fffffff007c6b264 == 0) {
      uVar9 = 0;
      iVar8 = 0;
    }
    else {
      uVar9 = 0;
      iVar8 = 0;
      do {
        lVar6 = *(long *)(DAT_fffffff007c6b270 + uVar9 * 8);
        if (lVar6 != 0) {
          lVar6 = *(long *)(lVar6 + 0x20);
          pcVar7 = *(code **)(lVar6 + 0x180);
          if (pcVar7 == (code *)0x0) {
            pcVar7 = *(code **)(lVar6 + 0x400);
            if (pcVar7 == (code *)0x0) goto LAB_fffffff00aa3cbb8;
            uVar5 = FUN_fffffff00aa1c310(param_2 + 0x18);
            iVar3 = (*pcVar7)(lVar2,param_2,uVar5);
          }
          else {
            uVar5 = FUN_fffffff00aa1c310(param_2 + 0x18);
            uStack_78 = param_6[1];
            local_80 = *param_6;
            uStack_68 = param_6[3];
            uStack_70 = param_6[2];
            iVar3 = (*pcVar7)(lVar2,param_2,uVar5,param_3,param_4,param_5,&local_80);
          }
          if (iVar3 == 0xb || iVar8 == 0xb) {
            iVar8 = 0xb;
          }
          else if (iVar3 == 0x16 || iVar8 == 0x16) {
            iVar8 = 0x16;
          }
          else if (iVar3 == 3 || iVar8 == 3) {
            iVar8 = 3;
          }
          else if (iVar3 == 2 || iVar8 == 2) {
            iVar8 = 2;
          }
          else if (iVar3 == 0xd || iVar8 == 0xd) {
            iVar8 = 0xd;
          }
          else if (iVar3 == 1 || iVar8 == 1) {
            iVar8 = 1;
          }
          else if (iVar3 != 0) {
            iVar8 = iVar3;
          }
        }
LAB_fffffff00aa3cbb8:
        uVar9 = uVar9 + 1;
      } while (uVar9 < DAT_fffffff007c6b264);
    }
    iVar3 = FUN_fffffff00aa187f0();
    if (iVar3 != 0) {
      if ((uint)uVar9 <= DAT_fffffff007c6b260) {
        do {
          lVar6 = *(long *)(DAT_fffffff007c6b270 + (uVar9 & 0xffffffff) * 8);
          if (lVar6 != 0) {
            lVar6 = *(long *)(lVar6 + 0x20);
            pcVar7 = *(code **)(lVar6 + 0x180);
            if (pcVar7 == (code *)0x0) {
              pcVar7 = *(code **)(lVar6 + 0x400);
              if (pcVar7 == (code *)0x0) goto LAB_fffffff00aa3cd2c;
              uVar5 = FUN_fffffff00aa1c310(param_2 + 0x18);
              iVar3 = (*pcVar7)(lVar2,param_2,uVar5);
            }
            else {
              uVar5 = FUN_fffffff00aa1c310(param_2 + 0x18);
              uStack_78 = param_6[1];
              local_80 = *param_6;
              uStack_68 = param_6[3];
              uStack_70 = param_6[2];
              iVar3 = (*pcVar7)(lVar2,param_2,uVar5,param_3,param_4,param_5,&local_80);
            }
            if (iVar3 == 0xb || iVar8 == 0xb) {
              iVar8 = 0xb;
            }
            else if (iVar3 == 0x16 || iVar8 == 0x16) {
              iVar8 = 0x16;
            }
            else if (iVar3 == 3 || iVar8 == 3) {
              iVar8 = 3;
            }
            else if (iVar3 == 2 || iVar8 == 2) {
              iVar8 = 2;
            }
            else if (iVar3 == 0xd || iVar8 == 0xd) {
              iVar8 = 0xd;
            }
            else if (iVar3 == 1 || iVar8 == 1) {
              iVar8 = 1;
            }
            else if (iVar3 != 0) {
              iVar8 = iVar3;
            }
          }
LAB_fffffff00aa3cd2c:
          uVar1 = (int)uVar9 + 1;
          uVar9 = (ulong)uVar1;
        } while (uVar1 <= DAT_fffffff007c6b260);
      }
      FUN_fffffff00aa188cc();
    }
    if (lVar4 != 0) {
      FUN_fffffff00aa3c3b0();
    }
  }
  return iVar8;
}

