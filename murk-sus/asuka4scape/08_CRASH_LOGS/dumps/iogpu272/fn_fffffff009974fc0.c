// FUN_fffffff009974fc0 @ fffffff009974fc0 size=232

undefined8 FUN_fffffff009974fc0(long param_1,long *param_2)

{
  bool bVar1;
  int iVar2;
  code *pcVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  int iVar10;
  ulong unaff_x30;
  
  uVar4 = (**(code **)(*param_2 + 0x98))(param_2);
  do {
    lVar9 = *(long *)(param_1 + 0x198);
    if (lVar9 == 0) {
LAB_fffffff009975048:
      bVar1 = true;
    }
    else {
      iVar10 = *(int *)(param_1 + 0x1a8);
      lVar5 = 0;
      do {
        lVar6 = lVar5;
        iVar2 = iVar10;
        if ((*(int *)(lVar9 + 0x38) == 0) &&
           (lVar6 = lVar9, iVar2 = *(int *)(lVar9 + 0x3c), iVar10 - *(int *)(lVar9 + 0x3c) < 1)) {
          lVar6 = lVar5;
          iVar2 = iVar10;
        }
        iVar10 = iVar2;
        lVar9 = *(long *)(lVar9 + 0x10);
        lVar5 = lVar6;
      } while (lVar9 != 0);
      if (lVar6 == 0) goto LAB_fffffff009975048;
      FUN_fffffff009951a44();
      bVar1 = false;
    }
    if ((uVar4 <= (uint)(*(int *)(param_1 + 0x1b4) - *(int *)(param_1 + 0x1b0))) &&
       (uVar7 = FUN_fffffff00995193c(param_2), (uVar7 & 1) != 0)) {
      return 1;
    }
    if (bVar1) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009975090);
        (*pcVar3)();
      }
      uVar8 = FUN_fffffff00995193c(param_2);
      return uVar8;
    }
  } while( true );
}

