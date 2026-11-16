// FUN_fffffff00818ed5c @ fffffff00818ed5c size=4

void FUN_fffffff00818ed5c(long param_1,undefined8 param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  long *plVar10;
  ulong uVar11;
  long lVar12;
  ulong unaff_x30;
  undefined1 auVar13 [16];
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  long lStack_48;
  
  auVar13._8_8_ = param_2;
  auVar13._0_8_ = param_1;
  lStack_48 = *(long *)PTR_DAT_fffffff007ca61a0;
  lVar6 = *(long *)(param_1 + 0x610);
  if (lVar6 != 0) {
    lVar7 = *(long *)(param_1 + 0x918);
    uVar8 = *(uint *)(lVar6 + 0x98);
    uVar9 = uVar8;
    if ((*(byte *)(lVar7 + 0x24) & 1) == 0) {
      uVar9 = (uint)(uVar8 != 0);
    }
    if (uVar9 != 0) {
      uVar11 = 0;
      do {
        plVar10 = *(long **)(*(long *)(lVar6 + 0x28 + uVar11 * 8) + 0x228);
        if (plVar10 != (long *)0x0) {
          uVar2 = *(undefined4 *)(param_1 + 0x490);
          thunk_EXT_FUN_80110000032222a8(plVar10[0x24]);
          (**(code **)(*plVar10 + 0x100))(plVar10,param_2,uVar2);
          auVar13 = thunk_EXT_FUN_8011000003222de0(plVar10[0x24]);
          lVar7 = *(long *)(param_1 + 0x918);
          lVar6 = *(long *)(param_1 + 0x610);
        }
        uVar11 = uVar11 + 1;
        uVar8 = *(uint *)(lVar6 + 0x98);
        uVar9 = uVar8;
        if ((*(byte *)(lVar7 + 0x24) & 1) == 0) {
          uVar9 = (uint)(uVar8 != 0);
        }
      } while (uVar11 < uVar9);
    }
    if (uVar8 != 0) {
      uVar11 = 0;
      do {
        lVar7 = *(long *)(lVar6 + 0x28 + uVar11 * 8);
        lVar12 = *(long *)(lVar7 + 0x230);
        if (lVar12 != 0) {
          uStack_68 = 0;
          uStack_70 = 0;
          uStack_58 = 0;
          uStack_60 = 0;
          uStack_88 = 0;
          uStack_90 = 0;
          uStack_78 = 0;
          uStack_80 = 0;
          uStack_a8 = 0;
          uStack_b0 = 0;
          uStack_98 = 0;
          uStack_a0 = 0;
          uStack_c8 = 0;
          uStack_d0 = 0;
          uStack_b8 = 0;
          uStack_c0 = 0;
          if (*(long *)(lVar12 + 0x1c0) != 0) {
            thunk_EXT_FUN_80110000037693ec(&uStack_d0,0x80,"GTP Only RT Buffers: %d x %d x %d");
            auVar13 = thunk_EXT_FUN_8011000002951bac
                                (*(undefined8 *)(lVar12 + 0x1c0),param_2,&uStack_d0);
          }
          if (*(long *)(lVar12 + 0x130) != 0) {
            thunk_EXT_FUN_80110000037693ec
                      (&uStack_d0,0x80,"Shared Render Target Buffer: %d x %d x %d");
            auVar13 = thunk_EXT_FUN_8011000002951bac
                                (*(undefined8 *)(lVar12 + 0x130),param_2,&uStack_d0);
          }
          lVar6 = *(long *)(param_1 + 0x610);
          lVar7 = *(long *)(lVar6 + 0x28 + uVar11 * 8);
        }
        if (*(long *)(lVar7 + 0x218) != 0) {
          auVar13 = FUN_fffffff008187554
                              (*(undefined8 *)(*(long *)(lVar7 + 0x218) + 0x80),param_2,
                               *(undefined4 *)(param_1 + 0x490));
          lVar6 = *(long *)(param_1 + 0x610);
          lVar7 = *(long *)(lVar6 + 0x28 + uVar11 * 8);
        }
        if (*(long *)(lVar7 + 0x220) != 0) {
          auVar13 = FUN_fffffff008187554
                              (*(undefined8 *)(*(long *)(lVar7 + 0x220) + 0x80),param_2,
                               *(undefined4 *)(param_1 + 0x490));
          lVar6 = *(long *)(param_1 + 0x610);
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)(lVar6 + 0x98));
    }
    if (*(int *)(lVar6 + 0x9c) != 0) {
      uVar11 = 0;
      do {
        lVar7 = *(long *)(*(long *)(lVar6 + 0x48 + uVar11 * 8) + 0x218);
        if (lVar7 != 0) {
          auVar13 = FUN_fffffff008187554
                              (*(undefined8 *)(lVar7 + 0x80),param_2,
                               *(undefined4 *)(param_1 + 0x490));
          lVar6 = *(long *)(param_1 + 0x610);
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)(lVar6 + 0x9c));
    }
    lVar6 = *(long *)(lVar6 + 0xa8);
    if (lVar6 != 0) {
      lVar7 = *(long *)(lVar6 + 0x30);
      if (lVar7 != 0) {
        pcVar1 = "AGXCommandBuffer Submitted Kicks";
        if (*(char **)(lVar7 + 0x20) != (char *)0x0) {
          pcVar1 = *(char **)(lVar7 + 0x20);
        }
        thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(lVar7 + 0x48),pcVar1);
        auVar13 = thunk_EXT_FUN_8011000002977950
                            (param_2,*(undefined8 *)(*(long *)(lVar6 + 0x30) + 0x48),
                             *(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x60));
      }
      lVar7 = *(long *)(lVar6 + 0x278);
      if (lVar7 != 0) {
        pcVar1 = "AGXCommandBuffer";
        if (*(char **)(lVar7 + 0x20) != (char *)0x0) {
          pcVar1 = *(char **)(lVar7 + 0x20);
        }
        uVar4 = thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(lVar7 + 0x48),pcVar1);
        uVar5 = *(undefined8 *)(*(long *)(lVar6 + 0x278) + 0x48);
        auVar13._8_8_ = uVar5;
        auVar13._0_8_ = uVar4;
        if (*(long *)PTR_DAT_fffffff007ca61a0 == lStack_48) {
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818f060);
            (*pcVar3)();
          }
          thunk_EXT_FUN_8011000002977950
                    (param_2,uVar5,*(undefined4 *)(*(long *)(lVar6 + 0x10) + 0x60));
          return;
        }
        goto LAB_fffffff00818f094;
      }
    }
  }
  if (*(long *)PTR_DAT_fffffff007ca61a0 == lStack_48) {
    return;
  }
LAB_fffffff00818f094:
  thunk_EXT_FUN_8011000003a48590(auVar13._0_8_,auVar13._8_8_);
  return;
}

