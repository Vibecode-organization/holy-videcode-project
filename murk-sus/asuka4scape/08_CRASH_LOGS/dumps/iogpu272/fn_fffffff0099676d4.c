// FUN_fffffff0099676d4 @ fffffff0099676d4 size=1236

undefined8
FUN_fffffff0099676d4(long param_1,undefined8 param_2,ulong param_3,ulong param_4,undefined8 param_5)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  ulong uVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  long *plVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  long *local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007ff2800;
  uVar13 = 0xe00002c2;
  plVar1 = (long *)FUN_fffffff009945040(*(undefined8 *)(param_1 + 0x10));
  uVar12 = uVar13;
  if (plVar1 == (long *)0x0) goto LAB_fffffff009967b60;
  if ((*(byte *)(plVar1 + 2) & 0x7f) == 0) {
    lVar2 = thunk_EXT_FUN_8011000003890f30(plVar1[5],DAT_fffffff007fefaf0);
    lVar3 = FUN_fffffff009956134(plVar1);
    if (lVar2 != 0) {
      plVar4 = (long *)FUN_fffffff009981d0c(lVar2);
      if (CARRY8(param_3,param_4)) {
        if (plVar4 == (long *)0x0) goto LAB_fffffff009967b40;
      }
      else {
        uVar5 = (**(code **)(*plVar4 + 0xb0))(plVar4);
        if (((param_4 | param_3) >> 0x20 == 0) && (param_3 + param_4 <= uVar5)) {
          plVar6 = (long *)thunk_EXT_FUN_801100000389d0d8(8);
          uVar12 = 0xe00002bd;
          if (plVar6 != (long *)0x0) {
            uStack_88 = 0;
            local_90 = 0;
            uStack_78 = 0;
            uStack_80 = 0;
            uStack_a8 = 0;
            local_b0 = 0;
            uStack_98 = 0;
            uStack_a0 = 0;
            uStack_c8 = 0;
            local_d0 = 0;
            uStack_b8 = 0;
            uStack_c0 = 0;
            uStack_e8 = 0;
            local_f0 = 0;
            uStack_d8 = 0;
            uStack_e0 = 0;
            thunk_EXT_FUN_80110000037693ec(&local_f0,0x80,"ANE Buffer id 0x%x");
            plVar7 = (long *)thunk_EXT_FUN_80110000038ce200(&local_f0);
            uVar12 = FUN_fffffff009953a34(plVar1);
            plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar12,0x40);
            if (plVar7 == (long *)0x0) {
              if (plVar8 != (long *)0x0) {
                uVar13 = 0xe00002bd;
                goto LAB_fffffff009967ad0;
              }
              uVar13 = 0xe00002bd;
            }
            else {
              if (plVar8 == (long *)0x0) {
                uVar13 = 0xe00002bd;
              }
              else {
                uVar12 = *(undefined8 *)PTR_DAT_fffffff007ff2810;
                local_f8 = plVar7;
                (**(code **)(*plVar7 + 0x20))(plVar7);
                thunk_EXT_FUN_801100000389d40c(plVar6,uVar12,&local_f8);
                if (local_f8 != (long *)0x0) {
                  (**(code **)(*local_f8 + 0x28))();
                }
                uVar12 = *(undefined8 *)PTR_DAT_fffffff007ff2818;
                local_f8 = plVar8;
                (**(code **)(*plVar8 + 0x20))();
                thunk_EXT_FUN_801100000389d40c(plVar6,uVar12,&local_f8);
                if (local_f8 != (long *)0x0) {
                  (**(code **)(*local_f8 + 0x28))();
                }
                uVar12 = *(undefined8 *)(param_1 + 0x50);
                uVar14 = *(undefined8 *)(*(long *)(param_1 + 0x48) + 0xf8);
                (**(code **)(*plVar6 + 0x20))(plVar6);
                plVar9 = (long *)thunk_EXT_FUN_8011000002c2fb68(uVar14,uVar12,plVar6,0);
                if (plVar9 != (long *)0x0) {
                  plVar10 = (long *)thunk_EXT_FUN_8011000002c2a0d0();
                  thunk_EXT_FUN_8011000002c2a314(plVar10,param_3);
                  uVar12 = (**(code **)(*plVar4 + 0xb0))(plVar4);
                  thunk_EXT_FUN_8011000002c2a2d4(plVar10,uVar12);
                  thunk_EXT_FUN_8011000002c2a294(plVar10,param_4);
                  thunk_EXT_FUN_8011000002c2a324(plVar10,param_4);
                  thunk_EXT_FUN_8011000002c2a334(plVar10,1);
                  thunk_EXT_FUN_8011000002c2a2a4(plVar10,1);
                  thunk_EXT_FUN_8011000002c2a2f4(plVar10,lVar3 == 0);
                  thunk_EXT_FUN_8011000002c25ee4(plVar9,plVar10);
                  thunk_EXT_FUN_8011000002c263d0(plVar9,plVar4);
                  thunk_EXT_FUN_8011000002c2665c(plVar9,1);
                  plVar11 = (long *)thunk_EXT_FUN_8011000002c43468
                                              (*(undefined8 *)(*(long *)(param_1 + 0x48) + 0xf8),
                                               plVar9);
                  if (plVar11 != (long *)0x0) {
                    uVar13 = thunk_EXT_FUN_80110000039a3b30
                                       (*(undefined8 *)(param_1 + 0x50),plVar11,param_5);
                    (**(code **)(*plVar11 + 0x28))(plVar11);
                  }
                  if (plVar10 != (long *)0x0) {
                    (**(code **)(*plVar10 + 0x28))(plVar10);
                  }
                  (**(code **)(*plVar9 + 0x28))(plVar9);
                }
LAB_fffffff009967ad0:
                (**(code **)(*plVar8 + 0x28))();
                if (plVar7 == (long *)0x0) goto LAB_fffffff009967b08;
              }
              (**(code **)(*plVar7 + 0x28))(plVar7);
            }
LAB_fffffff009967b08:
            (**(code **)(*plVar6 + 0x28))(plVar6);
            uVar12 = uVar13;
          }
        }
      }
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
  }
LAB_fffffff009967b40:
  (**(code **)(*plVar1 + 0x28))(plVar1);
LAB_fffffff009967b60:
  if (*(long *)PTR_DAT_fffffff007ff2800 != local_70) {
    uVar12 = thunk_EXT_FUN_8011000003a48590();
    return uVar12;
  }
  return uVar12;
}

