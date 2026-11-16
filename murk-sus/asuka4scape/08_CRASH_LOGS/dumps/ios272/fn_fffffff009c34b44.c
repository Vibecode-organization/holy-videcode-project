// FUN_fffffff009c34b44 @ fffffff009c34b44 size=508

void FUN_fffffff009c34b44(long param_1,undefined8 param_2,code *param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  int iVar9;
  undefined4 local_184;
  undefined1 *local_180;
  undefined1 *puStack_178;
  undefined1 *puStack_170;
  undefined1 *puStack_168;
  undefined1 *local_160;
  undefined1 *puStack_158;
  undefined1 *puStack_150;
  undefined1 *puStack_148;
  undefined1 *local_140;
  undefined1 *puStack_138;
  undefined1 *puStack_130;
  undefined1 *puStack_128;
  undefined1 *local_120;
  undefined1 *puStack_118;
  undefined1 *puStack_110;
  undefined1 *puStack_108;
  undefined1 *local_100;
  undefined1 *puStack_f8;
  undefined1 *puStack_f0;
  undefined1 *puStack_e8;
  undefined1 *local_e0;
  undefined1 *puStack_d8;
  undefined1 *puStack_d0;
  undefined1 *puStack_c8;
  undefined1 *local_c0;
  undefined1 *puStack_b8;
  undefined1 *puStack_b0;
  undefined1 *puStack_a8;
  undefined1 *local_a0;
  undefined1 *puStack_98;
  undefined1 *puStack_90;
  undefined1 *puStack_88;
  long local_78;
  
  local_78 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  uVar1 = DAT_fffffff008066f90;
  lVar7 = *(long *)(param_1 + 0x90);
  if (lVar7 != 0) {
    uVar8 = *(undefined8 *)PTR_DAT_fffffff00806ca10;
    do {
      if (*(long *)(lVar7 + 0x30) != 0) {
        puStack_98 = &DAT_aaaaaaaaaaaaaaaa;
        local_a0 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_88 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_90 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_b8 = &DAT_aaaaaaaaaaaaaaaa;
        local_c0 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_a8 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_b0 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_d8 = &DAT_aaaaaaaaaaaaaaaa;
        local_e0 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_c8 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_d0 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_f8 = &DAT_aaaaaaaaaaaaaaaa;
        local_100 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_e8 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_f0 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_118 = &DAT_aaaaaaaaaaaaaaaa;
        local_120 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_108 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_110 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_138 = &DAT_aaaaaaaaaaaaaaaa;
        local_140 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_128 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_130 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_158 = &DAT_aaaaaaaaaaaaaaaa;
        local_160 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_148 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_150 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_178 = &DAT_aaaaaaaaaaaaaaaa;
        local_180 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_168 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_170 = &DAT_aaaaaaaaaaaaaaaa;
        local_184 = 0;
        plVar3 = (long *)FUN_fffffff009c28424(lVar7,uVar1,&local_184);
        if (plVar3 == (long *)0x0) {
          plVar4 = (long *)0x0;
        }
        else {
          plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(plVar3,uVar8);
          if (plVar4 != (long *)0x0) {
            (**(code **)(*plVar4 + 0x20))(plVar4);
          }
        }
        FUN_fffffff009c2a738(lVar7);
        lVar6 = *(long *)(lVar7 + 0x2f0);
        if (lVar6 == 0) {
          iVar9 = 0;
        }
        else {
          iVar9 = 0;
          do {
            if (iVar9 < 0x40) {
              FUN_fffffff009c41bd8(*(undefined8 *)(lVar6 + 0x10));
              lVar5 = thunk_EXT_FUN_80110000032970b4();
              if (lVar5 != 0) {
                uVar2 = thunk_EXT_FUN_8011000003720f30();
                *(undefined4 *)((long)&local_180 + (long)iVar9 * 4) = uVar2;
                iVar9 = iVar9 + 1;
              }
            }
            lVar6 = *(long *)(lVar6 + 0x28);
          } while (lVar6 != 0);
        }
        FUN_fffffff009c2a744(lVar7);
        (*param_3)(param_2,*(undefined8 *)(lVar7 + 0x30),plVar4,*(undefined4 *)(lVar7 + 0x10),
                   &local_180,iVar9);
        if (plVar4 != (long *)0x0) {
          (**(code **)(*plVar4 + 0x28))(plVar4);
        }
        if (plVar3 != (long *)0x0) {
          (**(code **)(*plVar3 + 0x28))(plVar3);
        }
      }
      lVar7 = *(long *)(lVar7 + 0x18);
    } while (lVar7 != 0);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_78) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

