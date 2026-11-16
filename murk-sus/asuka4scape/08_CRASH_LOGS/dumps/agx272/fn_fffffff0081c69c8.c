// FUN_fffffff0081c69c8 @ fffffff0081c69c8 size=4

long * FUN_fffffff0081c69c8(long param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  long *plVar20;
  long *plVar21;
  long lVar22;
  long lVar23;
  ulong uVar24;
  undefined4 *puVar25;
  ulong uVar26;
  ulong uVar27;
  ulong uVar28;
  long lVar29;
  undefined4 *puStack_88;
  undefined4 *puStack_80;
  uint uStack_78;
  long *plStack_70;
  uint uStack_64;
  
  if (0x11 < param_2) {
    return (long *)0x0;
  }
  lVar29 = *(long *)(param_1 + 0x918);
  switch(param_2) {
  default:
    uVar28 = 0;
    puStack_88 = (undefined4 *)0x0;
    puStack_80 = (undefined4 *)0x0;
    puVar25 = (undefined4 *)0x0;
    uVar24 = *(long *)(param_1 + 0x2c0) + 0xb50;
    break;
  case 1:
    uVar28 = 0;
    puStack_88 = (undefined4 *)0x0;
    puStack_80 = (undefined4 *)0x0;
    puVar25 = (undefined4 *)0x0;
    uVar24 = *(long *)(param_1 + 0x2c0) + 0x9c8;
    break;
  case 2:
    puStack_88 = (undefined4 *)0x0;
    puStack_80 = (undefined4 *)0x0;
    uVar28 = *(long *)(param_1 + 0x2c0) + 0x291c;
    puVar25 = (undefined4 *)0x0;
    uVar24 = *(long *)(param_1 + 0x2c0) + 0x29e4;
    break;
  case 3:
    uVar28 = 0;
    puVar25 = (undefined4 *)0x0;
    puStack_88 = (undefined4 *)0x0;
    puStack_80 = (undefined4 *)0x0;
    lVar23 = *(long *)(param_1 + 0x2c0) + 0x2270;
    lVar22 = (ulong)param_3 * 0x2b8 + 0x18;
    uVar24 = lVar23 + (int)lVar22;
    if (lVar22 != (int)lVar22) {
      uVar24 = lVar23 + lVar22 & 0xffffffffffffU | 0x2bad000000000000;
    }
    break;
  case 4:
    uVar28 = 0;
    puStack_88 = (undefined4 *)0x0;
    puStack_80 = (undefined4 *)0x0;
    lVar22 = *(long *)(param_1 + 0x2c0) + 0x2878;
    uVar26 = (ulong)param_3 * 0x70 | 8;
    puVar25 = (undefined4 *)(lVar22 + (int)uVar26);
    uVar24 = 0;
    if (uVar26 != (long)(int)uVar26) {
      puVar25 = (undefined4 *)(lVar22 + uVar26 & 0xffffffffffff | 0x2bad000000000000);
    }
    break;
  case 5:
  case 6:
  case 7:
  case 10:
  case 0xb:
  case 0xd:
  case 0xf:
    return (long *)0x0;
  case 8:
    uVar28 = 0;
    puStack_88 = (undefined4 *)0x0;
    puStack_80 = (undefined4 *)0x0;
    puVar25 = (undefined4 *)0x0;
    uVar24 = *(long *)(param_1 + 0x2c0) + 0xa80;
    break;
  case 9:
    uVar28 = 0;
    puStack_80 = (undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2218);
    puStack_88 = (undefined4 *)(param_1 + 0x1900);
    puVar25 = (undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2220);
    uVar24 = 0;
    break;
  case 0xc:
    uVar28 = 0;
    puStack_80 = (undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2ca8);
    puStack_88 = (undefined4 *)(lVar29 + 100);
    puVar25 = (undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2cb0);
    uVar24 = 0;
    break;
  case 0xe:
    lVar22 = *(long *)(param_1 + 0x2c0);
    lVar23 = 0x2b74;
    goto LAB_fffffff0081c6bdc;
  case 0x10:
    lVar22 = *(long *)(param_1 + 0x2c0);
    lVar23 = 0x272e;
    goto LAB_fffffff0081c6bdc;
  case 0x11:
    lVar22 = *(long *)(param_1 + 0x2c0);
    lVar23 = 0x2e4c;
LAB_fffffff0081c6bdc:
    puStack_80 = (undefined4 *)0x0;
    puStack_88 = (undefined4 *)0x0;
    uVar28 = 0;
    puVar25 = (undefined4 *)0x0;
    uVar24 = lVar22 + lVar23;
  }
  plVar20 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  if (plVar20 == (long *)0x0) {
    return (long *)0x0;
  }
  plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar29 + 0x5c4),0x20);
  if (plVar21 == (long *)0x0) {
    uStack_78 = 0;
    if (uVar28 != 0) goto LAB_fffffff0081c6ce4;
LAB_fffffff0081c6c64:
    if (uVar24 != 0) goto LAB_fffffff0081c6c68;
LAB_fffffff0081c6e7c:
    if ((int)param_2 < 0xb) {
      if (param_2 == 4) {
        plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*puVar25,0x20);
        if (plVar21 == (long *)0x0) {
          uVar1 = 0;
        }
        else {
          uVar1 = (**(code **)(*plVar20 + 0x100))(plVar20,"TransferOutput",plVar21);
          (**(code **)(*plVar21 + 0x28))(plVar21);
        }
        lVar22 = *(long *)(param_1 + 0x2c0) + 0x2878;
        uVar24 = (ulong)param_3 * 0x70;
        uVar28 = uVar24 | 0xc;
        puVar25 = (undefined4 *)(lVar22 + (int)uVar28);
        if (uVar28 != (long)(int)uVar28) {
          puVar25 = (undefined4 *)(lVar22 + uVar28 & 0xffffffffffff | 0x2bad000000000000);
        }
        plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*puVar25,0x20);
        if (plVar21 == (long *)0x0) {
          uVar2 = 0;
        }
        else {
          uVar2 = (**(code **)(*plVar20 + 0x100))(plVar20,"EffectiveFrequency",plVar21);
          (**(code **)(*plVar21 + 0x28))(plVar21);
        }
        lVar23 = *(long *)(param_1 + 0x2c0) + 0x2878;
        lVar22 = uVar24 + 0x10;
        puVar25 = (undefined4 *)(lVar23 + (int)lVar22);
        if (lVar22 != (int)lVar22) {
          puVar25 = (undefined4 *)(lVar23 + lVar22 & 0xffffffffffffU | 0x2bad000000000000);
        }
        plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*puVar25,0x20);
        if (plVar21 == (long *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = (**(code **)(*plVar20 + 0x100))(plVar20,"ThresholdPStateFreq",plVar21);
          (**(code **)(*plVar21 + 0x28))(plVar21);
        }
        lVar23 = *(long *)(param_1 + 0x2c0) + 0x2878;
        lVar22 = uVar24 + 0x18;
        puVar25 = (undefined4 *)(lVar23 + (int)lVar22);
        if (lVar22 != (int)lVar22) {
          puVar25 = (undefined4 *)(lVar23 + lVar22 & 0xffffffffffffU | 0x2bad000000000000);
        }
        plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*puVar25,0x20);
        if (plVar21 == (long *)0x0) {
          uVar4 = 0;
        }
        else {
          uVar4 = (**(code **)(*plVar20 + 0x100))(plVar20,"PrimeResidencyPercent",plVar21);
          (**(code **)(*plVar21 + 0x28))(plVar21);
        }
        uStack_78 = uStack_78 & uVar4 & uVar1 & uVar2 & uVar3;
        goto LAB_fffffff0081c7f30;
      }
      if (param_2 != 9) goto LAB_fffffff0081c7f30;
LAB_fffffff0081c77ac:
      plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*puVar25,0x20);
      if (plVar21 == (long *)0x0) {
        uVar1 = 0;
      }
      else {
        uVar1 = (**(code **)(*plVar20 + 0x100))(plVar20,"TransferOutput",plVar21);
        (**(code **)(*plVar21 + 0x28))(plVar21);
      }
      plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*puStack_80,0x20);
      if (plVar21 == (long *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (**(code **)(*plVar20 + 0x100))(plVar20,"ControlEffort",plVar21);
        (**(code **)(*plVar21 + 0x28))(plVar21);
      }
      plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*puStack_88,0x20);
      if (plVar21 == (long *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (**(code **)(*plVar20 + 0x100))(plVar20,"OutputOverride",plVar21);
        (**(code **)(*plVar21 + 0x28))(plVar21);
      }
      uStack_78 = uStack_78 & uVar3 & uVar1 & uVar2;
      goto LAB_fffffff0081c7f30;
    }
    if (param_2 != 0xb) {
      if (param_2 != 0xc) goto LAB_fffffff0081c7f30;
      goto LAB_fffffff0081c77ac;
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*puVar25,0x20);
    if (plVar21 == (long *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)(*plVar20 + 0x100))(plVar20,"TransferOutput",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*puStack_80,0x20);
    if (plVar21 == (long *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(*plVar20 + 0x100))(plVar20,"ControlEffort",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    uVar1 = uVar1 & uVar2;
  }
  else {
    uStack_78 = (**(code **)(*plVar20 + 0x100))(plVar20,"pre_sample_idx",plVar21);
    (**(code **)(*plVar21 + 0x28))(plVar21);
    if (uVar28 == 0) goto LAB_fffffff0081c6c64;
LAB_fffffff0081c6ce4:
    uStack_64 = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x28ec);
    plVar21 = (long *)thunk_EXT_FUN_801100000389a1c8(0x68);
    (**(code **)(*plVar21 + 200))(plVar21,&uStack_64,4);
    if (uStack_64 != 0) {
      uVar26 = 0;
      do {
        uVar27 = uVar28 + uVar26 * 0x28;
        if (((uVar28 ^ uVar27) & 0xffc0000000000000) != 0) {
          uVar27 = uVar27 & 0xffffffffffff | 0xc8a2000000000000;
        }
        (**(code **)(*plVar21 + 200))(plVar21,uVar27 + 8,4);
        (**(code **)(*plVar21 + 200))(plVar21,uVar27 + 4,4);
        (**(code **)(*plVar21 + 200))(plVar21,uVar27,4);
        (**(code **)(*plVar21 + 200))(plVar21,uVar27 + 0x1c,4);
        (**(code **)(*plVar21 + 200))(plVar21,uVar27 + 0x20,4);
        uVar26 = uVar26 + 1;
      } while (uVar26 < uStack_64);
    }
    plStack_70 = plVar21;
    (**(code **)(*plVar21 + 0x20))(plVar21);
    thunk_EXT_FUN_801100000389d40c(plVar20,"PwrZones",&plStack_70);
    if (plStack_70 != (long *)0x0) {
      (**(code **)(*plStack_70 + 0x28))();
    }
    (**(code **)(*plVar21 + 0x28))(plVar21);
    if (uVar24 == 0) goto LAB_fffffff0081c6e7c;
LAB_fffffff0081c6c68:
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x4c),0x20);
    if (plVar21 == (long *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)(*plVar20 + 0x100))(plVar20,"Target",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x50),0x20);
    if (plVar21 == (long *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(*plVar20 + 0x100))(plVar20,"PlantOutput",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x80),0x20);
    if (plVar21 == (long *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (**(code **)(*plVar20 + 0x100))(plVar20,"TransferOutput",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x48),0x20);
    if (plVar21 == (long *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)(*plVar20 + 0x100))(plVar20,"FilterOutput",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x70),0x20);
    if (plVar21 == (long *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (**(code **)(*plVar20 + 0x100))(plVar20,"Error",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x74),0x20);
    if (plVar21 == (long *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (**(code **)(*plVar20 + 0x100))(plVar20,"ErrorIntegral",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x88),0x20);
    if (plVar21 == (long *)0x0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (**(code **)(*plVar20 + 0x100))(plVar20,"PlantFilterFn",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x8c),0x20);
    if (plVar21 == (long *)0x0) {
      uVar8 = 0;
    }
    else {
      uVar8 = (**(code **)(*plVar20 + 0x100))(plVar20,"PlantFilterFi",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x90),0x20);
    if (plVar21 == (long *)0x0) {
      uVar9 = 0;
    }
    else {
      uVar9 = (**(code **)(*plVar20 + 0x100))(plVar20,"IntegralGain",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x94),0x20);
    if (plVar21 == (long *)0x0) {
      uVar10 = 0;
    }
    else {
      uVar10 = (**(code **)(*plVar20 + 0x100))(plVar20,"ProportionalGain",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x78),0x20);
    if (plVar21 == (long *)0x0) {
      uVar11 = 0;
    }
    else {
      uVar11 = (**(code **)(*plVar20 + 0x100))(plVar20,"ControlEffort",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x7c),0x20);
    if (plVar21 == (long *)0x0) {
      uVar12 = 0;
    }
    else {
      uVar12 = (**(code **)(*plVar20 + 0x100))(plVar20,"OutputOverride",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x24),0x20);
    if (plVar21 == (long *)0x0) {
      uVar13 = 0;
    }
    else {
      uVar13 = (**(code **)(*plVar20 + 0x100))(plVar20,"ConfigIntegralMinClamp",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x28),0x20);
    if (plVar21 == (long *)0x0) {
      uVar14 = 0;
    }
    else {
      uVar14 = (**(code **)(*plVar20 + 0x100))(plVar20,"ConfigIntegralMaxClamp",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x34),0x20);
    if (plVar21 == (long *)0x0) {
      uVar15 = 0;
    }
    else {
      uVar15 = (**(code **)(*plVar20 + 0x100))(plVar20,"ConfigTransferGain",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x38),0x20);
    if (plVar21 == (long *)0x0) {
      uVar16 = 0;
    }
    else {
      uVar16 = (**(code **)(*plVar20 + 0x100))(plVar20,"ConfigTransferMinClamp",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x3c),0x20);
    if (plVar21 == (long *)0x0) {
      uVar17 = 0;
    }
    else {
      uVar17 = (**(code **)(*plVar20 + 0x100))(plVar20,"ConfigTransferMaxClamp",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x44),0x20);
    if (plVar21 == (long *)0x0) {
      uVar18 = 0;
    }
    else {
      uVar18 = (**(code **)(*plVar20 + 0x100))(plVar20,"ConfigKpTargetDelta",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0x54),0x20);
    if (plVar21 == (long *)0x0) {
      uVar19 = 0;
    }
    else {
      uVar19 = (**(code **)(*plVar20 + 0x100))(plVar20,"Deadzone",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    uStack_78 = uStack_78 & uVar19 &
                uVar1 & uVar2 & uVar3 & uVar4 & uVar5 & uVar6 & uVar7 & uVar8 & uVar9 & uVar10 &
                uVar11 & uVar12 & uVar13 & uVar14 & uVar15 & uVar16 & uVar17 & uVar18;
    if (param_2 != 0xe) goto LAB_fffffff0081c7f30;
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2c18),0x20);
    if (plVar21 == (long *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(*plVar20 + 0x100))(plVar20,"InactiveEngagementThreshold",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2c14),0x20);
    if (plVar21 == (long *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (**(code **)(*plVar20 + 0x100))(plVar20,"DownsampleCount",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2b6c),0x20);
    if (plVar21 == (long *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)(*plVar20 + 0x100))(plVar20,"SECounter",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2c1c),0x20);
    if (plVar21 == (long *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (**(code **)(*plVar20 + 0x100))(plVar20,"SECriteria",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2c20),0x20);
    if (plVar21 == (long *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (**(code **)(*plVar20 + 0x100))(plVar20,"SEEngageTolerance",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2c24),0x20);
    if (plVar21 == (long *)0x0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (**(code **)(*plVar20 + 0x100))(plVar20,"SEResetTolerance",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2b70),0x20);
    if (plVar21 == (long *)0x0) {
      uVar8 = 0;
    }
    else {
      uVar8 = (**(code **)(*plVar20 + 0x100))(plVar20,"SEResetDelayCounter",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x2c28),0x20);
    if (plVar21 == (long *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)(*plVar20 + 0x100))(plVar20,"SEResetCriteria",plVar21);
      (**(code **)(*plVar21 + 0x28))(plVar21);
      uVar1 = uVar2 & uVar3 & uVar4 & uVar5 & uVar6 & uVar7 & uVar8 & uVar1;
    }
  }
  uStack_78 = uStack_78 & uVar1;
LAB_fffffff0081c7f30:
  plVar21 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar29 + 0x5c4),0x20);
  if (plVar21 != (long *)0x0) {
    uVar1 = (**(code **)(*plVar20 + 0x100))(plVar20,"post_sample_idx",plVar21);
    (**(code **)(*plVar21 + 0x28))(plVar21);
    if ((uStack_78 & uVar1 & 1) != 0) {
      return plVar20;
    }
  }
  (**(code **)(*plVar20 + 0x28))(plVar20);
  return (long *)0x0;
}

