// FUN_fffffff0081a1d0c @ fffffff0081a1d0c size=344

undefined8 FUN_fffffff0081a1d0c(long param_1,long param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int *piVar5;
  long lVar6;
  undefined8 uVar7;
  ulong unaff_x30;
  long lVar8;
  undefined8 auStack_70 [4];
  undefined8 local_50;
  
  if (param_2 != DAT_fffffff00ae22330) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a1e60);
      (*pcVar2)();
    }
    uVar3 = FUN_fffffff00817234c(param_1);
    return uVar3;
  }
  uVar3 = 0xe00002bc;
  if (param_4 != 0) {
    lVar8 = *(long *)(param_4 + 8);
    auStack_70[1] = *(undefined8 *)(param_4 + 0x18);
    auStack_70[0] = *(undefined8 *)(param_4 + 0x10);
    auStack_70[3] = *(undefined8 *)(param_4 + 0x28);
    auStack_70[2] = *(undefined8 *)(param_4 + 0x20);
    local_50 = *(undefined8 *)(param_4 + 0x30);
    if (lVar8 == 0) {
      uVar3 = 0;
    }
    else {
      lVar6 = 0;
      uVar7 = 0;
      do {
        piVar5 = (int *)((long)auStack_70 + lVar6 * 0xc);
        if ((((ulong)auStack_70 ^ (ulong)piVar5) & 0xffc0000000000000) != 0) {
          piVar5 = (int *)((ulong)piVar5 & 0xffffffffffff | 0xc8a2000000000000);
        }
        iVar1 = *piVar5;
        if (iVar1 == 1) {
          uVar4 = 0;
LAB_fffffff0081a1dc4:
          uVar3 = 0xe00002bc;
          if (*(long *)(param_1 + 0x4b0) != 0) {
            FUN_fffffff0081a8898(*(long *)(param_1 + 0x4b0),uVar4,piVar5[1],piVar5[2]);
            uVar3 = uVar7;
          }
        }
        else {
          uVar3 = 0xe00002bc;
          if ((*(long *)(param_1 + 0x1acf0) != 0) &&
             ((*(byte *)(*(long *)(param_1 + 0x1acf0) + 0x18) & 1) != 0)) {
            if (iVar1 == 2) {
              uVar4 = 3;
            }
            else {
              if (iVar1 != 3) goto LAB_fffffff0081a1d88;
              uVar4 = 2;
            }
            goto LAB_fffffff0081a1dc4;
          }
        }
LAB_fffffff0081a1d88:
        lVar6 = lVar6 + 1;
        lVar8 = lVar8 + -1;
        uVar7 = uVar3;
      } while (lVar8 != 0);
    }
  }
  return uVar3;
}

