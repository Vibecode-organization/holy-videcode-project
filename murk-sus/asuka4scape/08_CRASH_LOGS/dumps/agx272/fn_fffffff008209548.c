// FUN_fffffff008209548 @ fffffff008209548 size=6240

void FUN_fffffff008209548(long param_1,int *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  uint *puVar8;
  long *plVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  code *pcVar19;
  int iVar20;
  uint uVar21;
  undefined8 uVar22;
  long lVar23;
  undefined8 uVar24;
  ulong uVar25;
  long lVar26;
  ulong uVar27;
  ulong uVar28;
  long lVar29;
  ulong uVar30;
  ulong uVar31;
  uint uVar32;
  uint uVar33;
  undefined4 uVar34;
  ulong uVar35;
  long lVar36;
  ulong uVar37;
  long lVar38;
  ulong unaff_x30;
  undefined8 local_88;
  undefined4 local_80;
  long local_78;
  
  local_78 = *(long *)PTR_DAT_fffffff007ca61a0;
  if (0x10 < *param_2 - 0x10U) {
code_r0xfffffff00820ad80:
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Non-statistics packet in statistics ring\n")
    ;
    return;
  }
  switch(*param_2) {
  default:
    uVar14 = param_2[6];
    if (0xf < uVar14) goto LAB_fffffff00820a188;
    lVar29 = 0x4e4f5f434c544d00;
    lVar36 = param_1 + 0x1200;
    lVar26 = *(long *)(param_1 + 0x530) * 8;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar26);
    if (lVar26 - (int)lVar26 != 0) {
      puVar10 = (undefined8 *)(lVar36 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar38 = *(long *)(param_2 + 1);
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_1 + 0x60),0x4750555048,*puVar10,
               lVar38 - *(long *)(param_1 + 0x538),0,0);
    lVar26 = (ulong)uVar14 * 8;
    plVar9 = (long *)(lVar36 + (int)lVar26);
    if (lVar26 - (int)lVar26 != 0) {
      plVar9 = (long *)(lVar36 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8(*(undefined8 *)(param_1 + 0x60),0x4750555048,*plVar9,0,1,0);
    *(ulong *)(param_1 + 0x530) = (ulong)uVar14;
    *(long *)(param_1 + 0x538) = lVar38;
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,*(undefined8 *)(param_1 + 0x568),
               lVar38 - *(long *)(param_1 + 0x570),0,0);
    *(long *)(param_1 + 0x570) = lVar38;
    if ((param_2[3] != 0) && ((uint)param_2[5] < (uint)param_2[4])) {
      lVar29 = *plVar9;
    }
    if (*(long *)(param_1 + 0x568) != lVar29) {
      thunk_EXT_FUN_80110000039b74c8
                (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,lVar29,0,1,0);
      *(long *)(param_1 + 0x568) = lVar29;
    }
    break;
  case 0x11:
    uVar22 = *(undefined8 *)(param_1 + 0x90);
    goto LAB_fffffff008209cd8;
  case 0x12:
    uVar22 = *(undefined8 *)(param_1 + 0x88);
LAB_fffffff008209cd8:
    if (*(long *)PTR_DAT_fffffff007ca61a0 == local_78) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar19 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008209d24);
        (*pcVar19)();
      }
      thunk_EXT_FUN_80110000039b8f8c(uVar22,*(undefined8 *)(param_2 + 1));
      return;
    }
    goto LAB_fffffff00820ad78;
  case 0x13:
    *(ulong *)(param_1 + 0x40) =
         CONCAT44((int)((ulong)*(undefined8 *)(param_1 + 0x40) >> 0x20) +
                  (int)((ulong)*(undefined8 *)(param_2 + 3) >> 0x20),
                  (int)*(undefined8 *)(param_1 + 0x40) + (int)*(undefined8 *)(param_2 + 3));
    *(ulong *)(param_1 + 0x4c) =
         CONCAT44((int)((ulong)*(undefined8 *)(param_1 + 0x4c) >> 0x20) + 1,
                  (int)*(undefined8 *)(param_1 + 0x4c) + param_2[6]);
    break;
  case 0x14:
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + param_2[1];
    break;
  case 0x15:
    if (param_2[1] == 0xa746) {
      uVar22 = *(undefined8 *)(param_1 + 0xb0);
      if (*(long *)PTR_DAT_fffffff007ca61a0 != local_78) goto LAB_fffffff00820ad78;
      uVar25 = 0x543432383232;
    }
    else {
      if (param_2[1] != 0x8d7f) break;
      uVar22 = *(undefined8 *)(param_1 + 0xb0);
      if (*(long *)PTR_DAT_fffffff007ca61a0 != local_78) goto LAB_fffffff00820ad78;
      uVar25 = 0x543336323233;
    }
    uVar25 = uVar25 | 0x5253000000000000;
    iVar20 = 1;
LAB_fffffff00820a06c:
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar19 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00820a09c);
      (*pcVar19)();
    }
    thunk_EXT_FUN_80110000039b5664(uVar22,uVar25,iVar20);
    return;
  case 0x16:
    if (param_2[1] == 0xa35b) {
      uVar24 = *(undefined8 *)(param_1 + 0xb0);
      uVar22 = 0x5253543431383139;
    }
    else {
      local_80 = 0;
      local_88 = 0;
      thunk_EXT_FUN_8011000003722d80(param_2[2],&local_88,0xc);
      if ((param_2[1] == 0) &&
         (iVar20 = thunk_EXT_FUN_80110000031cd5d0(&local_88,"mediaserverd",0xc), iVar20 == 0)) {
        uVar22 = 0x4d53455256455244;
      }
      else {
        uVar22 = 0x5245535441525455;
      }
      uVar24 = *(undefined8 *)(param_1 + 0xb0);
    }
    thunk_EXT_FUN_80110000039b5664(uVar24,uVar22,1);
    thunk_EXT_FUN_80110000039b5664(*(undefined8 *)(param_1 + 0xb0),0x5245535441525454,1);
    break;
  case 0x17:
    thunk_EXT_FUN_80110000039b5664(*(undefined8 *)(param_1 + 0xa8),0x5556434f554e54,param_2[1]);
    uVar22 = *(undefined8 *)(param_1 + 0xa8);
    iVar20 = param_2[2];
    if (*(long *)PTR_DAT_fffffff007ca61a0 != local_78) goto LAB_fffffff00820ad78;
    uVar25 = 0x5556414354495645;
    goto LAB_fffffff00820a06c;
  case 0x18:
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4530,param_2[1]);
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4531,param_2[2]);
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4532,param_2[3]);
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4533,param_2[4]);
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4534,param_2[5]);
    uVar22 = *(undefined8 *)(param_1 + 0xb8);
    uVar25 = (ulong)(uint)param_2[6];
    if (*(long *)PTR_DAT_fffffff007ca61a0 == local_78) {
      uVar24 = 0x46494c544552;
LAB_fffffff008209c2c:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar19 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008209c5c);
        (*pcVar19)();
      }
      thunk_EXT_FUN_80110000039b5574(uVar22,uVar24,uVar25);
      return;
    }
    goto LAB_fffffff00820ad78;
  case 0x19:
    uVar14 = param_2[7];
    if (0x12 < uVar14) {
LAB_fffffff00820a188:
      thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Ring entry contains bad data\n");
      return;
    }
    uVar15 = param_2[8];
    uVar25 = (ulong)uVar15;
    if (0xf < uVar15) goto LAB_fffffff00820a188;
    uVar16 = param_2[9];
    if (((0xf < uVar16) || (0x63f < (uint)param_2[0xb])) || (uVar17 = param_2[0xc], 6 < uVar17))
    goto LAB_fffffff00820a188;
    uVar18 = param_2[10];
    if (0x12 < uVar18) goto LAB_fffffff00820a188;
    iVar20 = param_2[0xd];
    uVar13 = param_2[0xe];
    if (iVar20 == 2) {
      if (uVar13 != 0) goto LAB_fffffff00820a188;
    }
    else if (iVar20 == 1) {
      if (1 < uVar13) goto LAB_fffffff00820a188;
    }
    else if ((iVar20 == 0) && (7 < uVar13)) goto LAB_fffffff00820a188;
    lVar26 = *(long *)(param_2 + 1);
    iVar12 = param_2[0xf];
    uVar32 = param_2[0x10];
    lVar36 = *(long *)(param_1 + 0x578);
    if ((lVar36 == 0x504d554c4f4f5000) || (uVar14 != 0xc)) {
      if ((lVar36 == 0x504d554c4f4f5000) && (uVar14 != 0xc)) {
        thunk_EXT_FUN_80110000039b74c8
                  (*(undefined8 *)(param_1 + 0x120),0x504d555f52430000,
                   *(undefined8 *)(param_1 + 0x598),lVar26 - *(long *)(param_1 + 0x5a0),0,0);
        thunk_EXT_FUN_80110000039b74c8
                  (*(undefined8 *)(param_1 + 0x120),0x504d555f52430000,0x4e4f4e4500000000,0,1,0);
        *(undefined8 *)(param_1 + 0x598) = 0x4e4f4e4500000000;
        goto LAB_fffffff00820a440;
      }
      if ((lVar36 == 0x504d554c4f4f5000) && (uVar14 == 0xc)) {
        lVar36 = 0x494e56414c494400;
        if (iVar20 == 2) {
          if (iVar12 == 2) {
            lVar36 = 0x1458;
          }
          else {
            if (iVar12 != 1) goto LAB_fffffff00820ad20;
            lVar36 = 0x1450;
          }
LAB_fffffff00820ad00:
          lVar29 = (ulong)uVar13 * 8;
          plVar9 = (long *)(param_1 + lVar36 + (long)(int)lVar29);
          if (lVar29 != (int)lVar29) {
            plVar9 = (long *)(param_1 + lVar36 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
          }
          lVar36 = *plVar9;
        }
        else {
          if (iVar20 == 1) {
            if (iVar12 == 2) {
              lVar36 = 0x1440;
            }
            else {
              if (iVar12 != 1) goto LAB_fffffff00820ad20;
              lVar36 = 0x1430;
            }
            goto LAB_fffffff00820ad00;
          }
          if (iVar20 == 0) {
            if (iVar12 == 2) {
              lVar36 = 0x13f0;
            }
            else {
              if (iVar12 != 1) goto LAB_fffffff00820ad20;
              lVar36 = 0x13b0;
            }
            goto LAB_fffffff00820ad00;
          }
        }
LAB_fffffff00820ad20:
        lVar29 = *(long *)(param_1 + 0x598);
        if (lVar29 == lVar36) goto LAB_fffffff00820a444;
        uVar22 = *(undefined8 *)(param_1 + 0x120);
        goto LAB_fffffff00820a408;
      }
    }
    else {
      lVar36 = 0x494e56414c494400;
      if (iVar20 == 2) {
        if (iVar12 == 2) {
          lVar36 = 0x1458;
        }
        else {
          if (iVar12 != 1) goto LAB_fffffff00820a400;
          lVar36 = 0x1450;
        }
LAB_fffffff00820a3e0:
        lVar36 = param_1 + lVar36;
LAB_fffffff00820a3e4:
        lVar29 = (ulong)uVar13 * 8;
        plVar9 = (long *)(lVar36 + (int)lVar29);
        if (lVar29 != (int)lVar29) {
          plVar9 = (long *)(lVar36 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
        }
        lVar36 = *plVar9;
      }
      else {
        if (iVar20 == 1) {
          if (iVar12 == 2) {
            lVar36 = 0x1440;
          }
          else {
            if (iVar12 != 1) goto LAB_fffffff00820a400;
            lVar36 = 0x1430;
          }
          goto LAB_fffffff00820a3e0;
        }
        if (iVar20 == 0) {
          if (iVar12 == 2) {
            lVar36 = 0x13f0;
            goto LAB_fffffff00820a3e0;
          }
          if (iVar12 != 1) goto LAB_fffffff00820a400;
          lVar36 = param_1 + 0x13b0;
          goto LAB_fffffff00820a3e4;
        }
      }
LAB_fffffff00820a400:
      uVar22 = *(undefined8 *)(param_1 + 0x120);
      lVar29 = *(long *)(param_1 + 0x598);
LAB_fffffff00820a408:
      thunk_EXT_FUN_80110000039b74c8
                (uVar22,0x504d555f52430000,lVar29,lVar26 - *(long *)(param_1 + 0x5a0),0,0);
      thunk_EXT_FUN_80110000039b74c8
                (*(undefined8 *)(param_1 + 0x120),0x504d555f52430000,lVar36,0,1,0);
      *(long *)(param_1 + 0x598) = lVar36;
LAB_fffffff00820a440:
      *(long *)(param_1 + 0x5a0) = lVar26;
    }
LAB_fffffff00820a444:
    lVar29 = param_1 + 0x1200;
    lVar36 = *(long *)(param_1 + 0x10) + 0x18bb8;
    lVar38 = (ulong)*(uint *)(param_1 + 0x530) * 4;
    puVar8 = (uint *)(lVar36 + (int)lVar38);
    if (lVar38 - (int)lVar38 != 0) {
      puVar8 = (uint *)(lVar36 + lVar38 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar36 = (ulong)*puVar8 * 8;
    puVar10 = (undefined8 *)(lVar29 + (int)lVar36);
    if (lVar36 - (int)lVar36 != 0) {
      puVar10 = (undefined8 *)(lVar29 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_1 + 0x60),0x4750555048,*puVar10,
               ((lVar26 - *(long *)(param_1 + 0x538)) * (ulong)uVar32) / 100,0,0);
    lVar36 = *(long *)(param_1 + 0x10) + 0x18b78;
    lVar38 = (ulong)*(uint *)(param_1 + 0x530) * 4;
    puVar8 = (uint *)(lVar36 + (int)lVar38);
    if (lVar38 - (int)lVar38 != 0) {
      puVar8 = (uint *)(lVar36 + lVar38 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar36 = (ulong)*puVar8 * 8;
    puVar10 = (undefined8 *)(lVar29 + (int)lVar36);
    if (lVar36 - (int)lVar36 != 0) {
      puVar10 = (undefined8 *)(lVar29 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_1 + 0x60),0x4750555048,*puVar10,
               ((lVar26 - *(long *)(param_1 + 0x538)) * (ulong)(100 - uVar32)) / 100,0,0);
    lVar36 = *(long *)(param_1 + 0x10) + 0x18b78;
    lVar38 = uVar25 * 4;
    puVar8 = (uint *)(lVar36 + (int)lVar38);
    if (lVar38 - (int)lVar38 != 0) {
      puVar8 = (uint *)(lVar36 + lVar38 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar36 = (ulong)*puVar8 * 8;
    puVar10 = (undefined8 *)(lVar29 + (int)lVar36);
    if (lVar36 - (int)lVar36 != 0) {
      puVar10 = (undefined8 *)(lVar29 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8(*(undefined8 *)(param_1 + 0x60),0x4750555048,*puVar10,0,1,0);
    if (uVar32 != 0) {
      lVar36 = *(long *)(param_1 + 0x10) + 0x18bb8;
      lVar38 = (ulong)*(uint *)(param_1 + 0x530) * 4;
      puVar8 = (uint *)(lVar36 + (int)lVar38);
      if (lVar38 - (int)lVar38 != 0) {
        puVar8 = (uint *)(lVar36 + lVar38 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar36 = (ulong)*puVar8 * 8;
      puVar10 = (undefined8 *)(lVar29 + (int)lVar36);
      if (lVar36 - (int)lVar36 != 0) {
        puVar10 = (undefined8 *)(lVar29 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      thunk_EXT_FUN_80110000039b74c8(*(undefined8 *)(param_1 + 0x60),0x4750555048,*puVar10,0,1,0);
    }
    lVar36 = param_1 + 0x1280;
    lVar38 = *(long *)(param_1 + 0x540) * 8;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar38);
    if (lVar38 - (int)lVar38 != 0) {
      puVar10 = (undefined8 *)(lVar36 + lVar38 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *(ulong *)(param_1 + 0x530) = uVar25;
    *(long *)(param_1 + 0x538) = lVar26;
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,*puVar10,
               lVar26 - *(long *)(param_1 + 0x548),0,0);
    lVar38 = (ulong)uVar16 * 8;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar38);
    if (lVar38 - (int)lVar38 != 0) {
      puVar10 = (undefined8 *)(lVar36 + lVar38 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,*puVar10,0,1,0);
    *(ulong *)(param_1 + 0x540) = (ulong)uVar16;
    *(long *)(param_1 + 0x548) = lVar26;
    uVar30 = (ulong)*(uint *)(param_1 + 0x5ac);
    if (0xf < *(uint *)(param_1 + 0x5ac)) {
LAB_fffffff00820ad4c:
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Unexpected statistic packet value from fender\n");
      return;
    }
    uVar13 = param_2[0xb];
    uVar37 = *(ulong *)(param_2 + 1);
    uVar28 = *(ulong *)(param_2 + 3);
    iVar20 = param_2[6];
    uVar31 = *(ulong *)(param_1 + 0x5b8);
    if ((*(int *)(param_1 + 0x5b0) == 0) || (iVar20 == 0)) {
      uVar35 = (ulong)uVar13 / 100;
      uVar32 = uVar13 / 100;
      if ((*(int *)(param_1 + 0x5b0) == 0) || (param_2[8] == 0)) {
        uVar33 = *(uint *)(param_1 + 0x5a8) % 100;
        if (uVar33 != 0) {
          uVar30 = *(ulong *)(param_1 + 0x5c0);
          uVar21 = (**(code **)(**(long **)(param_1 + 0x10) + 0xb80))();
          uVar27 = (ulong)((float)uVar30 +
                          ((float)uVar33 / -100.0 + 1.0) * (float)uVar21 * 1000.0 * 24.0);
          uVar30 = (ulong)*(uint *)(param_1 + 0x5ac);
          lVar36 = uVar27 - *(ulong *)(param_1 + 0x5b8);
          if ((*(ulong *)(param_1 + 0x5b8) <= uVar27 && lVar36 != 0) && uVar27 <= uVar37) {
            if (*(uint *)(param_1 + 0x5ac) - 0xf < 0xfffffff0) goto LAB_fffffff00820ad4c;
            lVar38 = uVar30 * 8;
            puVar10 = (undefined8 *)(lVar29 + (int)lVar38);
            if (lVar38 - (int)lVar38 != 0) {
              puVar10 = (undefined8 *)(lVar29 + lVar38 & 0xffffffffffffU | 0x2bad000000000000);
            }
            thunk_EXT_FUN_80110000039b74c8
                      (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,*puVar10,lVar36,0,0);
            lVar36 = (ulong)(*(int *)(param_1 + 0x5ac) + 1) * 8;
            puVar10 = (undefined8 *)(lVar29 + (int)lVar36);
            if (lVar36 != (int)lVar36) {
              puVar10 = (undefined8 *)(lVar29 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
            }
            thunk_EXT_FUN_80110000039b74c8
                      (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,*puVar10,0,1,0);
            iVar12 = *(int *)(param_1 + 0x5ac);
            uVar33 = iVar12 + 1;
            uVar30 = (ulong)uVar33;
            *(uint *)(param_1 + 0x5ac) = uVar33;
            if (uVar28 == *(ulong *)(param_1 + 0x5c0)) {
              uVar32 = iVar12 + 1;
            }
            uVar35 = (ulong)uVar32;
            uVar31 = uVar27;
          }
        }
        uVar34 = (undefined4)uVar35;
        lVar36 = uVar30 * 8;
        puVar10 = (undefined8 *)(lVar29 + (int)lVar36);
        if (lVar36 != (int)lVar36) {
          puVar10 = (undefined8 *)(lVar29 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
        }
        thunk_EXT_FUN_80110000039b74c8
                  (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,*puVar10,uVar37 - uVar31,0,0)
        ;
        if (iVar20 == 0) goto LAB_fffffff00820a924;
      }
      else {
        uVar33 = uVar13 / 100;
        if (uVar13 % 100 != 0) {
          uVar21 = (**(code **)(**(long **)(param_1 + 0x10) + 0xb80))();
          if ((ulong)(long)((float)uVar28 +
                           ((float)(uVar13 % 100) / -100.0 + 1.0) * (float)uVar21 * 1000.0 * 24.0) <
              uVar37) {
            uVar33 = uVar32 + 1;
          }
          uVar35 = (ulong)uVar33;
        }
LAB_fffffff00820a924:
        uVar34 = (undefined4)uVar35;
        thunk_EXT_FUN_80110000039b74c8
                  (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,uVar35,0,1,0);
      }
      *(undefined4 *)(param_1 + 0x5ac) = uVar34;
      *(ulong *)(param_1 + 0x5b8) = uVar37;
      *(uint *)(param_1 + 0x5a8) = uVar13;
      *(ulong *)(param_1 + 0x5c0) = uVar28;
      *(int *)(param_1 + 0x5b0) = iVar20;
    }
    lVar36 = 0x4e4f5f434c544d00;
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,*(undefined8 *)(param_1 + 0x568),
               lVar26 - *(long *)(param_1 + 0x570),0,0);
    *(long *)(param_1 + 0x570) = lVar26;
    if ((param_2[5] != 0) && ((uVar14 == 1 || ((uVar14 == 2 && (uVar17 == 0)))))) {
      lVar36 = uVar25 * 8;
      plVar9 = (long *)(lVar29 + (int)lVar36);
      if (lVar36 - (int)lVar36 != 0) {
        plVar9 = (long *)(lVar29 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar36 = *plVar9;
    }
    if (*(long *)(param_1 + 0x568) != lVar36) {
      thunk_EXT_FUN_80110000039b74c8
                (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,lVar36,0,1,0);
      *(long *)(param_1 + 0x568) = lVar36;
    }
    if (*(int *)(param_1 + 0x5d8) != 0) {
      thunk_EXT_FUN_80110000039b5664
                (*(undefined8 *)(param_1 + 0x100),0x505a454e47414745,
                 lVar26 - *(long *)(param_1 + 0x580));
    }
    *(uint *)(param_1 + 0x5d8) = (uint)((uVar17 != 0 && uVar15 != 0) && uVar14 == 2);
    if ((uVar15 == 0) && (param_2[6] != 0)) {
      uVar25 = 0;
      if (uVar16 != 0) goto LAB_fffffff00820aa94;
LAB_fffffff00820aa7c:
      if (param_2[6] == 0) goto LAB_fffffff00820aa94;
      uVar30 = 0;
      uVar31 = (ulong)(uVar18 + 1);
    }
    else {
      uVar25 = (ulong)(uVar14 + 1);
      if (uVar16 == 0) goto LAB_fffffff00820aa7c;
LAB_fffffff00820aa94:
      uVar30 = (ulong)uVar18 + 1;
      uVar31 = uVar30;
    }
    uVar15 = 0;
    if (uVar14 == 2) {
      uVar15 = uVar17 + 1;
    }
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_1 + 0x108),0x505a5253444e4359,*(undefined8 *)(param_1 + 0x5c8),
               lVar26 - *(long *)(param_1 + 0x5d0),0,0);
    lVar36 = (ulong)uVar15 * 8;
    puVar10 = (undefined8 *)(param_1 + 0x1460 + (long)(int)lVar36);
    if (lVar36 != (int)lVar36) {
      puVar10 = (undefined8 *)(param_1 + 0x1460 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_1 + 0x108),0x505a5253444e4359,*puVar10,0,1,0);
    *(undefined8 *)(param_1 + 0x5c8) = *puVar10;
    *(long *)(param_1 + 0x5d0) = lVar26;
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_1 + 0x110),0x5057524354524c,*(undefined8 *)(param_1 + 0x578),
               lVar26 - *(long *)(param_1 + 0x580),0,0);
    lVar36 = param_1 + 0x1310;
    lVar29 = uVar25 * 8;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar29);
    if (lVar29 != (int)lVar29) {
      puVar10 = (undefined8 *)(lVar36 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8(*(undefined8 *)(param_1 + 0x110),0x5057524354524c,*puVar10,0,1,0)
    ;
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_1 + 0x118),0x4146524354524c,*(undefined8 *)(param_1 + 0x588),
               lVar26 - *(long *)(param_1 + 0x590),0,0);
    uVar28 = (uVar31 & 0xffffffff) << 3;
    uVar31 = -(uVar31 >> 0x1f & 1) & 0xfffffff800000000 | uVar28;
    iVar20 = (int)uVar28;
    puVar11 = (undefined8 *)(lVar36 + iVar20);
    if (uVar31 != (long)iVar20) {
      puVar11 = (undefined8 *)(lVar36 + uVar31 & 0xffffffffffff | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8(*(undefined8 *)(param_1 + 0x118),0x4146524354524c,*puVar11,0,1,0)
    ;
    lVar29 = uVar30 * 8;
    puVar11 = (undefined8 *)(lVar36 + (int)lVar29);
    if (lVar29 - (int)lVar29 != 0) {
      puVar11 = (undefined8 *)(lVar36 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *(undefined8 *)(param_1 + 0x578) = *puVar10;
    *(long *)(param_1 + 0x580) = lVar26;
    *(undefined8 *)(param_1 + 0x588) = *puVar11;
    *(long *)(param_1 + 0x590) = lVar26;
    if ((int)uVar25 == 0) {
      thunk_EXT_FUN_80110000039b74c8
                (*(undefined8 *)(param_1 + 0x120),0x504d555f52430000,
                 *(undefined8 *)(param_1 + 0x598),lVar26 - *(long *)(param_1 + 0x5a0),0,0);
      thunk_EXT_FUN_80110000039b74c8
                (*(undefined8 *)(param_1 + 0x120),0x504d555f52430000,0x4e4f4e4500000000,0,1,0);
      *(undefined8 *)(param_1 + 0x598) = 0x4e4f4e4500000000;
      *(long *)(param_1 + 0x5a0) = lVar26;
    }
    break;
  case 0x1a:
    uVar14 = param_2[3];
    if (1 < uVar14) goto LAB_fffffff00820a188;
    lVar26 = *(long *)(param_2 + 1);
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_1 + 0x70),0x46454e444552,*(undefined8 *)(param_1 + 0x550),
               lVar26 - *(long *)(param_1 + 0x558),0,0);
    lVar36 = (ulong)uVar14 * 8;
    puVar10 = (undefined8 *)(param_1 + 0x1300 + (long)(int)lVar36);
    if (lVar36 - (int)lVar36 != 0) {
      puVar10 = (undefined8 *)(param_1 + 0x1300 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8(*(undefined8 *)(param_1 + 0x70),0x46454e444552,*puVar10,0,1,0);
    lVar36 = 0x98;
    if (uVar14 != 0) {
      lVar36 = 0xa0;
    }
    thunk_EXT_FUN_80110000039b8f8c
              (*(undefined8 *)(param_1 + lVar36),lVar26 - *(long *)(param_1 + 0x560));
    *(undefined8 *)(param_1 + 0x550) = *puVar10;
    *(long *)(param_1 + 0x558) = lVar26;
    *(long *)(param_1 + 0x560) = lVar26;
    break;
  case 0x1b:
    uVar14 = param_2[1];
    if (0xf < uVar14) goto LAB_fffffff00820a188;
    uVar15 = param_2[3];
    if (0xf < uVar15) goto LAB_fffffff00820a188;
    uVar16 = param_2[2];
    uVar30 = (ulong)uVar16;
    if (10000 < uVar16) goto LAB_fffffff00820a188;
    uVar17 = param_2[4];
    uVar25 = (ulong)uVar17;
    if (10000 < uVar17) goto LAB_fffffff00820a188;
    lVar36 = (ulong)uVar14 * 8;
    iVar20 = (int)lVar36;
    if (uVar16 == 0) {
      puVar10 = (undefined8 *)(param_1 + 0x3c0 + (long)iVar20);
      if (lVar36 - iVar20 != 0) {
        puVar10 = (undefined8 *)(param_1 + 0x3c0 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar11 = (undefined8 *)(param_1 + 0x17b8 + (long)iVar20);
      if (lVar36 - iVar20 != 0) {
        puVar11 = (undefined8 *)(param_1 + 0x17b8 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      thunk_EXT_FUN_80110000039b5664(*puVar10,*puVar11,1);
    }
    else {
      thunk_EXT_FUN_80110000039b8f8c(*(undefined8 *)(param_1 + 0x138),uVar30);
      puVar10 = (undefined8 *)(param_1 + 0x140 + (long)iVar20);
      if (lVar36 - iVar20 != 0) {
        puVar10 = (undefined8 *)(param_1 + 0x140 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      thunk_EXT_FUN_80110000039b8f8c(*puVar10,uVar30);
    }
    lVar26 = param_1 + 0x2c0;
    puVar10 = (undefined8 *)(lVar26 + iVar20);
    if (lVar36 - iVar20 != 0) {
      puVar10 = (undefined8 *)(lVar26 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar29 = param_1 + 0x1c0;
    lVar38 = param_1 + 0x15b8;
    lVar3 = param_1 + 0x16b8;
    puVar11 = (undefined8 *)(lVar3 + iVar20);
    if (lVar36 - iVar20 != 0) {
      puVar11 = (undefined8 *)(lVar3 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5664(*puVar10,*puVar11,uVar30);
    lVar1 = param_1 + 0x340;
    puVar10 = (undefined8 *)(lVar1 + iVar20);
    if (lVar36 - iVar20 != 0) {
      puVar10 = (undefined8 *)(lVar1 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar4 = param_1 + 0x1738;
    puVar11 = (undefined8 *)(lVar4 + iVar20);
    if (lVar36 - iVar20 != 0) {
      puVar11 = (undefined8 *)(lVar4 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5664(*puVar10,*puVar11,1);
    puVar10 = (undefined8 *)(lVar29 + iVar20);
    if (lVar36 - iVar20 != 0) {
      puVar10 = (undefined8 *)(lVar29 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    puVar11 = (undefined8 *)(lVar38 + iVar20);
    if (lVar36 - iVar20 != 0) {
      puVar11 = (undefined8 *)(lVar38 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar23 = thunk_EXT_FUN_80110000039b575c(*puVar10,*puVar11);
    lVar2 = param_1 + 0x240;
    puVar6 = (undefined8 *)(lVar2 + iVar20);
    if (lVar36 - iVar20 != 0) {
      puVar6 = (undefined8 *)(lVar2 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar5 = param_1 + 0x1638;
    puVar7 = (undefined8 *)(lVar5 + iVar20);
    if (lVar36 - iVar20 != 0) {
      puVar7 = (undefined8 *)(lVar5 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar36 = thunk_EXT_FUN_80110000039b575c(*puVar6,*puVar7);
    if ((uVar16 != 0) && ((lVar23 == 0 || ((long)uVar30 < lVar23)))) {
      thunk_EXT_FUN_80110000039b5574(*puVar10,*puVar11,uVar30);
    }
    if (lVar36 < (long)uVar30) {
      thunk_EXT_FUN_80110000039b5574(*puVar6,*puVar7,uVar30);
    }
    if (uVar14 != uVar15) {
      lVar36 = (ulong)uVar15 * 8;
      iVar20 = (int)lVar36;
      if (uVar17 == 0) {
        puVar10 = (undefined8 *)(param_1 + 0x3c0 + (long)iVar20);
        if (lVar36 - iVar20 != 0) {
          puVar10 = (undefined8 *)(param_1 + 0x3c0 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
        }
        puVar11 = (undefined8 *)(param_1 + 0x17b8 + (long)iVar20);
        if (lVar36 - iVar20 != 0) {
          puVar11 = (undefined8 *)(param_1 + 0x17b8 + lVar36 & 0xffffffffffffU | 0x2bad000000000000)
          ;
        }
        thunk_EXT_FUN_80110000039b5664(*puVar10,*puVar11,1);
      }
      else {
        thunk_EXT_FUN_80110000039b8f8c(*(undefined8 *)(param_1 + 0x138),uVar25);
        puVar10 = (undefined8 *)(param_1 + 0x140 + (long)iVar20);
        if (lVar36 - iVar20 != 0) {
          puVar10 = (undefined8 *)(param_1 + 0x140 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
        }
        thunk_EXT_FUN_80110000039b8f8c(*puVar10,uVar25);
      }
      puVar10 = (undefined8 *)(lVar26 + iVar20);
      if (lVar36 - iVar20 != 0) {
        puVar10 = (undefined8 *)(lVar26 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar11 = (undefined8 *)(lVar3 + iVar20);
      if (lVar36 - iVar20 != 0) {
        puVar11 = (undefined8 *)(lVar3 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      thunk_EXT_FUN_80110000039b5664(*puVar10,*puVar11,uVar25);
      puVar10 = (undefined8 *)(lVar1 + iVar20);
      if (lVar36 - iVar20 != 0) {
        puVar10 = (undefined8 *)(lVar1 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar11 = (undefined8 *)(lVar4 + iVar20);
      if (lVar36 - iVar20 != 0) {
        puVar11 = (undefined8 *)(lVar4 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      thunk_EXT_FUN_80110000039b5664(*puVar10,*puVar11,1);
      puVar10 = (undefined8 *)(lVar29 + iVar20);
      if (lVar36 - iVar20 != 0) {
        puVar10 = (undefined8 *)(lVar29 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar11 = (undefined8 *)(lVar38 + iVar20);
      if (lVar36 - iVar20 != 0) {
        puVar11 = (undefined8 *)(lVar38 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar26 = thunk_EXT_FUN_80110000039b575c(*puVar10,*puVar11);
      puVar6 = (undefined8 *)(lVar2 + iVar20);
      if (lVar36 - iVar20 != 0) {
        puVar6 = (undefined8 *)(lVar2 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar7 = (undefined8 *)(lVar5 + iVar20);
      if (lVar36 - iVar20 != 0) {
        puVar7 = (undefined8 *)(lVar5 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar36 = thunk_EXT_FUN_80110000039b575c(*puVar6,*puVar7);
      if ((uVar17 != 0) && ((lVar26 == 0 || ((long)uVar25 < lVar26)))) {
        thunk_EXT_FUN_80110000039b5574(*puVar10,*puVar11,uVar25);
      }
      if (lVar36 < (long)uVar25) {
        uVar22 = *puVar6;
        uVar24 = *puVar7;
        if (*(long *)PTR_DAT_fffffff007ca61a0 == local_78) goto LAB_fffffff008209c2c;
        goto LAB_fffffff00820ad78;
      }
    }
    break;
  case 0x1c:
    if (*(long *)(param_1 + 0x440) != 0) {
      uVar14 = param_2[3];
      if (0xf < uVar14) goto LAB_fffffff00820a188;
      lVar36 = param_1 + 0x1838;
      lVar26 = (ulong)*(uint *)(param_1 + 0xfe0) * 8;
      puVar10 = (undefined8 *)(lVar36 + (int)lVar26);
      if (lVar26 - (int)lVar26 != 0) {
        puVar10 = (undefined8 *)(lVar36 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar29 = *(long *)(param_2 + 1);
      thunk_EXT_FUN_80110000039b74c8
                (*(long *)(param_1 + 0x440),0x4750555f53570000,*puVar10,
                 lVar29 - *(long *)(param_1 + 0xfe8),0,0);
      lVar26 = (ulong)uVar14 * 8;
      puVar10 = (undefined8 *)(lVar36 + (int)lVar26);
      if (lVar26 - (int)lVar26 != 0) {
        puVar10 = (undefined8 *)(lVar36 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
      }
      thunk_EXT_FUN_80110000039b74c8
                (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,*puVar10,0,1,0);
      *(uint *)(param_1 + 0xfe0) = uVar14;
      *(long *)(param_1 + 0xfe8) = lVar29;
    }
    break;
  case 0x1d:
  case 0x1f:
    goto code_r0xfffffff00820ad80;
  case 0x1e:
    uVar25 = (ulong)(uint)param_2[0xd];
    if (2 < (uint)param_2[0xd]) goto LAB_fffffff00820a188;
    lVar36 = param_1 + 0xff0;
    lVar26 = uVar25 * 0x60;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar26);
    if (lVar26 - (int)lVar26 != 0) {
      puVar10 = (undefined8 *)(lVar36 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0x450),*puVar10,param_2[1]);
    uVar30 = uVar25 * 0x60 | 8;
    puVar10 = (undefined8 *)(lVar36 + (int)uVar30);
    if (uVar30 != (long)(int)uVar30) {
      puVar10 = (undefined8 *)(lVar36 + uVar30 & 0xffffffffffff | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0x450),*puVar10,param_2[2]);
    uVar30 = uVar25 * 0x60 | 0x10;
    puVar10 = (undefined8 *)(lVar36 + (int)uVar30);
    if (uVar30 != (long)(int)uVar30) {
      puVar10 = (undefined8 *)(lVar36 + uVar30 & 0xffffffffffff | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0x450),*puVar10,param_2[3]);
    uVar25 = uVar25 * 0x60 | 0x18;
    puVar10 = (undefined8 *)(lVar36 + (int)uVar25);
    if (uVar25 != (long)(int)uVar25) {
      puVar10 = (undefined8 *)(lVar36 + uVar25 & 0xffffffffffff | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0x450),*puVar10,param_2[4]);
    lVar29 = lVar26 + 0x20;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar29);
    if (lVar29 != (int)lVar29) {
      puVar10 = (undefined8 *)(lVar36 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0x450),*puVar10,param_2[5]);
    lVar29 = lVar26 + 0x28;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar29);
    if (lVar29 != (int)lVar29) {
      puVar10 = (undefined8 *)(lVar36 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0x450),*puVar10,param_2[6]);
    lVar29 = lVar26 + 0x30;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar29);
    if (lVar29 != (int)lVar29) {
      puVar10 = (undefined8 *)(lVar36 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0x450),*puVar10,param_2[7]);
    lVar29 = lVar26 + 0x38;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar29);
    if (lVar29 != (int)lVar29) {
      puVar10 = (undefined8 *)(lVar36 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0x450),*puVar10,param_2[8]);
    lVar29 = lVar26 + 0x40;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar29);
    if (lVar29 != (int)lVar29) {
      puVar10 = (undefined8 *)(lVar36 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0x450),*puVar10,param_2[9]);
    lVar29 = lVar26 + 0x48;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar29);
    if (lVar29 != (int)lVar29) {
      puVar10 = (undefined8 *)(lVar36 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0x450),*puVar10,param_2[10]);
    lVar29 = lVar26 + 0x50;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar29);
    if (lVar29 != (int)lVar29) {
      puVar10 = (undefined8 *)(lVar36 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0x450),*puVar10,param_2[0xb]);
    lVar26 = lVar26 + 0x58;
    puVar10 = (undefined8 *)(lVar36 + (int)lVar26);
    if (lVar26 != (int)lVar26) {
      puVar10 = (undefined8 *)(lVar36 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar22 = *(undefined8 *)(param_1 + 0x450);
    uVar24 = *puVar10;
    uVar25 = (ulong)(uint)param_2[0xc];
    if (*(long *)PTR_DAT_fffffff007ca61a0 == local_78) goto LAB_fffffff008209c2c;
    goto LAB_fffffff00820ad78;
  case 0x20:
    thunk_EXT_FUN_80110000039b5574
              (*(undefined8 *)(param_1 + 0x458),0x54484d5f41435456,*(undefined8 *)(param_2 + 1));
    uVar22 = *(undefined8 *)(param_1 + 0x458);
    uVar25 = *(ulong *)(param_2 + 3);
    if (*(long *)PTR_DAT_fffffff007ca61a0 == local_78) {
      uVar24 = 0x5346455449455233;
      goto LAB_fffffff008209c2c;
    }
    goto LAB_fffffff00820ad78;
  }
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_78) {
    return;
  }
LAB_fffffff00820ad78:
  thunk_EXT_FUN_8011000003a48590();
  return;
}

