// FUN_fffffff00819e14c @ fffffff00819e14c size=4

void FUN_fffffff00819e14c(long param_1,int *param_2,undefined8 *param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  long *plVar8;
  ulong uVar9;
  long lVar10;
  byte bVar11;
  long lVar12;
  char cVar13;
  long *plVar14;
  long *plVar15;
  ulong uVar16;
  undefined8 uStack_a0;
  long lStack_98;
  ulong uStack_90;
  undefined8 uStack_88;
  ulong uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  long lStack_58;
  
  lStack_58 = *(long *)PTR_DAT_fffffff007ca61a0;
  uVar6 = 0xe00002bc;
  if ((param_2 == (int *)0x0) || (0xc < *param_2)) goto LAB_fffffff00819e820;
  plVar14 = *(long **)(param_1 + 0x120);
  plVar15 = (long *)plVar14[9];
  thunk_EXT_FUN_80110000032222a8(plVar15[0x234c]);
  (**(code **)(*plVar15 + 0x710))(plVar15,"",0);
  plVar15 = (long *)plVar14[9];
  iVar3 = (int)plVar14[0xc];
  if ((*(byte *)((long)plVar15 + 0x57a) & 1) == 0) {
    uStack_80 = uStack_80 & 0xffffffff00000000;
    lStack_98 = 0;
    uStack_a0 = 0;
    uStack_88 = 0;
    uStack_90 = 0;
    if (0 < iVar3) {
      thunk_EXT_FUN_8011000003722d80(iVar3,&uStack_a0,0x24);
      uStack_80._0_4_ = (uint)(uint3)uStack_80;
    }
    thunk_EXT_FUN_80110000036da494(0x85090080,iVar3,0,0,0,0);
    if ((*(byte *)((long)plVar15 + 0x5c9) >> 4 & 1) != 0) {
      thunk_EXT_FUN_8011000003a49114
                (
                "AGXk: %s:%d:%s: !!! AGXk: pid=%u name=%s panicking due to submission while the GPU is powered off!\n"
                );
      return;
    }
    do {
      if ((*(byte *)((long)plVar15 + 0x1ac44) >> 3 & 1) != 0) {
        thunk_EXT_FUN_8011000003390230();
        uVar6 = thunk_EXT_FUN_8011000003271024();
        FUN_fffffff00817dc48(plVar15,0x319,0,iVar3,uVar6,0,0,0);
      }
      FUN_fffffff00817f3cc(plVar15,(long)plVar15 + 0x57a);
      if ((*(byte *)((long)plVar15 + 0x1ac44) >> 3 & 1) != 0) {
        thunk_EXT_FUN_8011000003390230();
        uVar6 = thunk_EXT_FUN_8011000003271024();
        FUN_fffffff00817dc48(plVar15,0x31a,0,iVar3,uVar6,0,0,0);
      }
    } while ((*(byte *)((long)plVar15 + 0x57a) & 1) == 0);
    thunk_EXT_FUN_80110000036da494(0x85090084,iVar3,0,0,0,0);
    plVar15 = (long *)plVar14[9];
  }
  (**(code **)(*plVar15 + 0x718))(plVar15,"",0);
  thunk_EXT_FUN_8011000003222de0(plVar15[0x234c]);
  uStack_78 = *(undefined8 *)(param_2 + 10);
  uStack_80 = *(ulong *)(param_2 + 8);
  uStack_68 = *(undefined8 *)(param_2 + 0xe);
  uStack_70 = *(undefined8 *)(param_2 + 0xc);
  uStack_60 = *(undefined8 *)(param_2 + 0x10);
  lStack_98 = *(long *)(param_2 + 2);
  uStack_a0 = *(undefined8 *)param_2;
  uStack_88 = *(undefined8 *)(param_2 + 6);
  uStack_90 = *(ulong *)(param_2 + 4);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(plVar14[9] + 0x111b8));
  uVar7 = uStack_90;
  lVar12 = lStack_98;
  uVar1 = (uint)uStack_a0;
  if ((uint)uStack_a0 == 0xb) {
    if (param_3 != (undefined8 *)0x0) {
      *(undefined4 *)((long)param_3 + 0x44) = 0;
      *(undefined8 *)((long)param_3 + 0x3c) = 0;
      *(undefined8 *)((long)param_3 + 0x34) = 0;
      *(undefined8 *)((long)param_3 + 0x2c) = 0;
      *(undefined8 *)((long)param_3 + 0x24) = 0;
      *(undefined8 *)((long)param_3 + 0x1c) = 0;
      *(undefined8 *)((long)param_3 + 0x14) = 0;
      *(undefined8 *)((long)param_3 + 0xc) = 0;
      *(undefined8 *)((long)param_3 + 4) = 0;
      lVar12 = *(long *)(*(long *)(plVar14[9] + 0x111b0) + 0x20);
      *(bool *)((long)param_3 + 4) = lVar12 != 0;
      cVar13 = '\x02';
      if (*(long **)(*(long *)(plVar14[9] + 0x111b0) + 0x20) != plVar14) {
        cVar13 = '\0';
      }
      *(undefined4 *)param_3 = 0xb;
      if (lVar12 != 0) {
        cVar13 = cVar13 + '\x01';
      }
      *(char *)((long)param_3 + 4) = cVar13;
      iVar3 = thunk_EXT_FUN_8011000002960e38(plVar14,"com.apple.private.agx.performance-spi");
      if ((iVar3 == 0) || (lVar12 = thunk_EXT_FUN_801100000372056c((int)plVar14[0xc]), lVar12 == 0))
      {
        bVar11 = 0;
      }
      else {
        iVar3 = thunk_EXT_FUN_80110000036e83c0();
        thunk_EXT_FUN_8011000003720838(lVar12);
        bVar11 = 0;
        if (iVar3 != 0) {
          bVar11 = 4;
        }
      }
      bVar2 = *(byte *)((long)param_3 + 4);
      *(byte *)((long)param_3 + 4) = bVar2 & 0xfb | bVar11;
      *(byte *)((long)param_3 + 4) =
           (*(byte *)(*(long *)(plVar14[9] + 0x111b0) + 0x54) & 1) << 3 | bVar2 & 0xf3 | bVar11;
      (**(code **)(**(long **)(plVar14[9] + 0x111b0) + 0xf0))
                (*(long **)(plVar14[9] + 0x111b0),param_3);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(plVar14[9] + 0x111b8));
      uVar6 = 0;
      goto LAB_fffffff00819e820;
    }
    goto LAB_fffffff00819e804;
  }
  plVar15 = *(long **)(plVar14[9] + 0x111b0);
  if ((long *)plVar15[4] == plVar14) {
    if ((uint)uStack_a0 < 0xd) {
      if ((1 << (ulong)((uint)uStack_a0 & 0x1f) & 0x7f6U) != 0) {
LAB_fffffff00819e45c:
        uVar7 = (**(code **)(*plVar15 + 0x88))(plVar15,&uStack_a0);
LAB_fffffff00819e480:
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(plVar14[9] + 0x111b8));
        uVar6 = 0xe00002bc;
        if ((uVar7 & 1) == 0) goto LAB_fffffff00819e820;
LAB_fffffff00819e5a8:
        uVar6 = 0;
        if (param_3 != (undefined8 *)0x0) {
          param_3[5] = uStack_78;
          param_3[4] = uStack_80;
          param_3[7] = uStack_68;
          param_3[6] = uStack_70;
          param_3[8] = uStack_60;
          param_3[1] = lStack_98;
          *param_3 = uStack_a0;
          param_3[3] = uStack_88;
          param_3[2] = uStack_90;
        }
        goto LAB_fffffff00819e820;
      }
      if ((uint)uStack_a0 == 3) {
        uVar16 = (ulong)uStack_a0._4_1_;
        if ((uint)uStack_a0._4_1_ < *(uint *)(plVar14 + 0x41)) {
          if (lStack_98 == 0) {
            if (*(long *)(plVar14[0x40] + uVar16 * 8) != 0) {
              uVar7 = (**(code **)(*plVar15 + 0x88))(plVar15,&uStack_a0);
              (**(code **)(*plVar14 + 0xe8))(plVar14,uVar16,0);
              goto LAB_fffffff00819e480;
            }
            goto LAB_fffffff00819e594;
          }
          if ((ulong)(long)(2 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f)) <= uStack_90) {
            uVar9 = FUN_fffffff008200da0(plVar15,uVar16);
            if ((uVar9 & 1) == 0) {
              lVar10 = plVar14[0xb];
              uVar6 = 0x500000007;
            }
            else {
              lVar10 = *(long *)(plVar14[9] + 0x11da0);
              uVar6 = 0x800000007;
            }
            lVar12 = FUN_fffffff008200e48(plVar14,plVar14[10],lVar10,lVar12,uVar7,uVar6);
            if (lVar12 != 0) {
              lStack_98 = lVar12;
              (**(code **)(*plVar14 + 0xe8))(plVar14,uVar16);
              plVar15 = *(long **)(plVar14[9] + 0x111b0);
              goto LAB_fffffff00819e45c;
            }
          }
        }
      }
      else {
        if ((uint)uStack_a0 != 0xc) goto LAB_fffffff00819e544;
        plVar15 = (long *)FUN_fffffff00817fc0c(plVar14[9],1);
        if (plVar15 != (long *)0x0) {
          plVar8 = (long *)thunk_EXT_FUN_80110000038caee0(0x4000);
          if (plVar8 == (long *)0x0) {
            uVar7 = 0;
          }
          else {
            uVar7 = (**(code **)(*plVar15 + 0x30))(plVar15,plVar8);
            if ((uVar7 & 1) == 0) {
              uVar7 = 0;
            }
            else {
              uVar1 = (uint)uStack_90;
              uVar4 = (**(code **)(*plVar8 + 0xb8))(plVar8);
              if (uVar1 < uVar4) {
                uVar7 = 0;
              }
              else {
                uVar5 = (**(code **)(*plVar8 + 0xb8))(plVar8);
                uStack_90 = CONCAT44(uStack_90._4_4_,uVar5);
                uVar6 = (**(code **)(*plVar8 + 0x78))(plVar8);
                thunk_EXT_FUN_8011000003386690(uVar6,lStack_98,uVar5);
                uVar7 = 1;
              }
            }
            (**(code **)(*plVar8 + 0x28))(plVar8);
          }
          (**(code **)(*plVar15 + 0x28))(plVar15);
          goto LAB_fffffff00819e480;
        }
      }
    }
    else {
LAB_fffffff00819e544:
      if ((uint)uStack_a0 == 0) {
LAB_fffffff00819e550:
        cVar13 = uStack_a0._4_1_;
        iVar3 = (**(code **)(*plVar15 + 0x90))(plVar15,uStack_a0._4_1_ != '\0',plVar14);
        if (iVar3 != 0) {
          if (cVar13 != '\0') {
            *(undefined4 *)(plVar14 + 0x3f) = (undefined4)lStack_98;
            if (plVar14[0x40] == 0) {
              uVar1 = *(uint *)(*(long *)(plVar14[9] + 0x111b0) + 0x48);
              if (uVar1 != 0) {
                lVar12 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4b98,(ulong)uVar1 << 3);
                if (lVar12 == 0) {
                  (**(code **)(**(long **)(plVar14[9] + 0x111b0) + 0x90))
                            (*(long **)(plVar14[9] + 0x111b0),1,plVar14);
                  *(undefined4 *)(plVar14 + 0x3f) = 0;
                  goto LAB_fffffff00819e804;
                }
                plVar14[0x40] = lVar12;
                *(uint *)(plVar14 + 0x41) = uVar1;
              }
            }
          }
LAB_fffffff00819e594:
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(plVar14[9] + 0x111b8));
          goto LAB_fffffff00819e5a8;
        }
      }
    }
LAB_fffffff00819e804:
    uVar6 = *(undefined8 *)(plVar14[9] + 0x111b8);
LAB_fffffff00819e814:
    thunk_EXT_FUN_8011000003222de0(uVar6);
    uVar6 = 0xe00002bc;
  }
  else {
    iVar3 = thunk_EXT_FUN_8011000002960e38(plVar14,"com.apple.private.agx.performance-spi");
    if ((iVar3 != 0) && (lVar12 = thunk_EXT_FUN_801100000372056c((int)plVar14[0xc]), lVar12 != 0)) {
      iVar3 = thunk_EXT_FUN_80110000036e83c0();
      thunk_EXT_FUN_8011000003720838(lVar12);
      if (iVar3 != 0) {
        if (uVar1 == 0) {
          plVar15 = *(long **)(plVar14[9] + 0x111b0);
          goto LAB_fffffff00819e550;
        }
        uVar6 = *(undefined8 *)(plVar14[9] + 0x111b8);
        goto LAB_fffffff00819e814;
      }
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(plVar14[9] + 0x111b8));
    uVar6 = 0xe00002c1;
  }
LAB_fffffff00819e820:
  if (*(long *)PTR_DAT_fffffff007ca61a0 != lStack_58) {
    thunk_EXT_FUN_8011000003a48590(uVar6);
    return;
  }
  return;
}

