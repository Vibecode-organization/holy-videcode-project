// FUN_fffffff0081c2b60 @ fffffff0081c2b60 size=744

long FUN_fffffff0081c2b60(long param_1,uint param_2,int param_3)

{
  ulong uVar1;
  undefined4 *puVar2;
  ulong uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined8 uVar7;
  long *plVar8;
  long lVar9;
  long lVar10;
  undefined8 *puVar11;
  long lVar12;
  long lVar13;
  long *local_90;
  undefined4 local_88;
  uint uStack_84;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined4 local_44;
  
  lVar13 = *(long *)(param_1 + 0x808);
  uStack_78 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  local_50 = 0;
  uStack_58 = 0;
  local_60 = 0;
  local_88 = 0x1a;
  local_80 = 1;
  local_90 = (long *)CONCAT44(local_90._4_4_,2);
  uStack_84 = param_2;
  uVar7 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
  local_44 = 0;
  plVar8 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
  puVar11 = (undefined8 *)(*plVar8 + 0xe8);
  iVar6 = (*(code *)*puVar11)(puVar11,plVar8,FUN_fffffff00817ea94,&local_88,&local_90,&local_44,0);
  if ((iVar6 == 0) &&
     ((((byte)local_90 >> 1 & 1) == 0 ||
      (iVar6 = FUN_fffffff0081a43cc(param_1,uVar7,local_44), iVar6 == 0)))) {
    lVar12 = thunk_EXT_FUN_80110000038961f4(0xc);
    if (lVar12 != 0) {
      lVar13 = lVar13 + 0x3e5;
      lVar9 = (ulong)param_2 * 0x30;
      iVar6 = (int)lVar9;
      uVar1 = lVar13 + iVar6;
      if (lVar9 - iVar6 != 0) {
        uVar1 = lVar13 + lVar9 & 0xffffffffffffU | 0x2bad000000000000;
      }
      if (param_3 == 0) {
        lVar13 = 0;
        uVar3 = param_1 + 0x17c8 + (long)iVar6;
        if (lVar9 - iVar6 != 0) {
          uVar3 = param_1 + 0x17c8 + lVar9 & 0xffffffffffffU | 0x2bad000000000000;
        }
        lVar9 = 0xc;
        do {
          lVar10 = lVar13 * 4;
          iVar6 = (int)lVar10;
          piVar4 = (int *)(uVar1 + (long)iVar6);
          if (lVar10 - iVar6 != 0) {
            piVar4 = (int *)(uVar1 + lVar10 & 0xffffffffffff | 0x2bad000000000000);
          }
          piVar5 = (int *)(uVar3 + (long)iVar6);
          if (lVar10 - iVar6 != 0) {
            piVar5 = (int *)(uVar3 + lVar10 & 0xffffffffffff | 0x2bad000000000000);
          }
          plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24(*piVar4 - *piVar5,0x20);
          if (plVar8 == (long *)0x0) {
            return lVar12;
          }
          local_90 = plVar8;
          (**(code **)(*plVar8 + 0x20))();
          thunk_EXT_FUN_80110000038963f0(lVar12,&local_90);
          if (local_90 != (long *)0x0) {
            (**(code **)(*local_90 + 0x28))();
          }
          (**(code **)(*plVar8 + 0x28))(plVar8);
          lVar13 = lVar13 + 1;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
      }
      else {
        lVar13 = 0;
        lVar9 = 0xc;
        do {
          lVar10 = lVar13 * 4;
          puVar2 = (undefined4 *)(uVar1 + (long)(int)lVar10);
          if (lVar10 - (int)lVar10 != 0) {
            puVar2 = (undefined4 *)(uVar1 + lVar10 & 0xffffffffffff | 0x2bad000000000000);
          }
          plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24(*puVar2,0x20);
          if (plVar8 == (long *)0x0) {
            return lVar12;
          }
          local_90 = plVar8;
          (**(code **)(*plVar8 + 0x20))();
          thunk_EXT_FUN_80110000038963f0(lVar12,&local_90);
          if (local_90 != (long *)0x0) {
            (**(code **)(*local_90 + 0x28))();
          }
          (**(code **)(*plVar8 + 0x28))(plVar8);
          lVar13 = lVar13 + 1;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
      }
    }
  }
  else {
    lVar12 = 0;
  }
  return lVar12;
}

