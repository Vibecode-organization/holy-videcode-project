// FUN_fffffff0081a173c @ fffffff0081a173c size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081a181c) */

void FUN_fffffff0081a173c(long *param_1)

{
  undefined8 *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long *plVar6;
  undefined8 uVar7;
  bool bVar8;
  long lVar9;
  ulong uVar10;
  long *plVar11;
  long *plVar12;
  long *plVar13;
  byte bStack_a1;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  ulong uStack_88;
  ulong uStack_80;
  undefined8 uStack_78;
  long lStack_70;
  
  uVar7 = 0;
  bVar8 = true;
  do {
    lStack_70 = 0;
    uStack_88 = 0;
    uStack_90 = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    uStack_98 = 0;
    uStack_a0 = 0;
    iVar3 = (**(code **)(*param_1 + 0x7b8))(param_1,uVar7,&uStack_a0,1);
    if (iVar3 != 0) {
      iVar3 = (int)uStack_90;
      uVar10 = uStack_90 & 0xffffffff;
      iVar4 = (**(code **)(*param_1 + 0x788))(param_1);
      lVar9 = *param_1;
      if (iVar3 < iVar4) {
        (**(code **)(lVar9 + 0x7c8))(lVar9 + 0x7c8,param_1,uVar10);
      }
      else {
        iVar4 = (**(code **)(lVar9 + 0x778))(lVar9 + 0x778,param_1);
        if (iVar4 <= iVar3) {
          (**(code **)(*param_1 + 0x778))(param_1);
        }
      }
      (**(code **)(*param_1 + 0x7a8))(param_1,uStack_90._4_4_,uStack_88 & 0xffffffff);
      if ((-1 < iVar3) && (iVar3 < (int)param_1[0x23c0])) {
        thunk_EXT_FUN_80110000032222a8(param_1[0x23bf]);
        if (iVar3 < (int)param_1[0x23c0]) {
          lVar9 = uVar10 * 8;
          puVar1 = (undefined8 *)(param_1[0x23c4] + (long)(int)lVar9);
          if (lVar9 - (int)lVar9 != 0) {
            puVar1 = (undefined8 *)(param_1[0x23c4] + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
          }
          plVar11 = (long *)*puVar1;
          if ((plVar11 != (long *)0x0) &&
             (uVar10 = thunk_EXT_FUN_801100000294991c(plVar11), (uVar10 & 1) != 0)) {
            thunk_EXT_FUN_8011000003222de0(param_1[0x23bf]);
            lVar9 = lStack_70;
            uVar7 = uStack_78;
            bStack_a1 = 0;
            (**(code **)(*plVar11 + 200))(plVar11,uStack_78);
            if ((lStack_70 != 0) &&
               (lVar5 = (**(code **)(*plVar11 + 0x100))(plVar11,0), lVar5 != lVar9)) {
              (**(code **)(*plVar11 + 0x100))(plVar11,0);
            }
            (**(code **)(*plVar11 + 0x20))(plVar11);
            plVar12 = (long *)plVar11[0x5f];
            (**(code **)(*plVar11 + 0x28))(plVar11);
            plVar6 = plVar11;
            if (plVar12 != (long *)0x0) {
              (**(code **)(*plVar11 + 0x160))(plVar11);
              plVar6 = plVar12;
            }
            plVar6 = (long *)thunk_EXT_FUN_801100000296cfb8(plVar6,uVar7,&bStack_a1);
            if ((plVar6 != (long *)0x0) && ((bStack_a1 & 1) != 0)) {
              (**(code **)(*plVar6 + 0x98))(plVar6);
            }
            if ((int)plVar11[0x4f] != 0) {
              thunk_EXT_FUN_80110000032970b4(plVar11[5]);
            }
            (**(code **)(*plVar11 + 0x100))(plVar11,0);
            (**(code **)(*plVar11 + 0x160))(plVar11);
            if (plVar6 == (long *)0x0) {
              plVar12 = (long *)0x0;
            }
            else {
              (**(code **)(*plVar6 + 0x98))(plVar6);
              thunk_EXT_FUN_801100000297b70c(plVar6);
              thunk_EXT_FUN_801100000297b724(plVar6);
              (**(code **)(*plVar6 + 200))(plVar6);
              thunk_EXT_FUN_801100000293f804(plVar6[3]);
              plVar13 = (long *)plVar6[3];
              plVar12 = (long *)0x0;
              if (plVar13 != (long *)0x0) {
                thunk_EXT_FUN_8011000003890f30(plVar13,&DAT_fffffff00ae21bd0);
                thunk_EXT_FUN_801100000293ebf8(plVar13);
                thunk_EXT_FUN_801100000293f7e4(plVar13);
                (**(code **)(*plVar13 + 0x88))(plVar13);
                plVar12 = (long *)thunk_EXT_FUN_8011000002970a94(param_1,plVar13);
                if (plVar12 != (long *)0x0) {
                  thunk_EXT_FUN_8011000002951258(plVar12);
                }
              }
            }
            (**(code **)(*plVar11 + 0x118))(plVar11,uVar7,uStack_80 & 0xff);
            if (plVar12 != (long *)0x0) {
              (**(code **)(*plVar12 + 0x28))(plVar12);
            }
            if (plVar6 != (long *)0x0) {
              (**(code **)(*plVar6 + 0x28))(plVar6);
            }
            (**(code **)(*plVar11 + 0x28))(plVar11);
            goto LAB_fffffff0081a1790;
          }
        }
        thunk_EXT_FUN_8011000003222de0(param_1[0x23bf]);
      }
    }
LAB_fffffff0081a1790:
    uVar7 = 1;
    bVar2 = !bVar8;
    bVar8 = false;
    if (bVar2) {
      thunk_EXT_FUN_80110000032222a8(param_1[0x23bf]);
      if (0 < (int)param_1[0x23c0]) {
        lVar9 = 0;
        do {
          plVar11 = *(long **)(param_1[0x23c4] + lVar9 * 8);
          if ((plVar11 != (long *)0x0) &&
             (iVar3 = thunk_EXT_FUN_801100000294991c(plVar11), iVar3 != 0)) {
            (**(code **)(*plVar11 + 0x100))(plVar11,0);
            (**(code **)(*plVar11 + 0x28))(plVar11);
          }
          lVar9 = lVar9 + 1;
        } while (lVar9 < (int)param_1[0x23c0]);
      }
      thunk_EXT_FUN_8011000003222de0(param_1[0x23bf]);
      uStack_a0 = 0;
      uStack_98 = 0;
      uVar10 = (**(code **)(*param_1 + 0x7c0))(param_1,&uStack_a0);
      if ((uVar10 & 1) != 0) {
        iVar3 = (int)uStack_a0;
        iVar4 = (**(code **)(*param_1 + 0x778))(param_1);
        if (iVar4 <= iVar3) {
          (**(code **)(*param_1 + 0x778))(param_1);
        }
      }
      return;
    }
  } while( true );
}

