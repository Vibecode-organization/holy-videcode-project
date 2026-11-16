/* ==== FUN_183bd8754 @ 183bd8754 size=4744 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_183bd8754(long param_1)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined8 *puVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  char *pcVar11;
  ulong uVar12;
  long lVar13;
  undefined8 uVar14;
  ulong uVar15;
  undefined8 uVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  ulong uVar20;
  ulong unaff_x30;
  undefined8 local_110;
  ulong local_108;
  ulong local_100 [9];
  ulong local_b8 [3];
  long local_a0 [3];
  long local_88 [3];
  long local_70;
  
  local_70 = *_DAT_1e0186220;
  if (param_1 == 0) {
LAB_183bd88d0:
    lVar6 = 0;
  }
  else {
    if (*(int *)(param_1 + 8) != 7) {
      if (*(int *)(param_1 + 8) == 5) {
        uVar16 = *(undefined8 *)(param_1 + 0x20);
        lVar6 = _create_device_space(uVar16);
        if (lVar6 != 0) goto LAB_183bd88d4;
        iVar5 = func_0x0001881386b0(uVar16,"Pattern");
        if (iVar5 == 0) {
          if (*_DAT_1e0186220 == local_70) {
            if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
              lVar6 = FUN_183be6414(0);
              return lVar6;
            }
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0xc471,0x183bd8810);
            (*pcVar4)();
          }
          goto LAB_183bd9660;
        }
      }
      goto LAB_183bd88d0;
    }
    lVar17 = *(long *)(param_1 + 0x20);
    lVar6 = _CGPDFObjectCopyAssociation(param_1,"ColorSpace");
    if (lVar6 == 0) {
      if ((lVar17 == 0) || (*(long *)(lVar17 + 0x18) == *(long *)(lVar17 + 0x10))) {
        pcVar11 = "invalid color space: no entries in color space array.";
      }
      else {
        local_110 = 0;
        uVar7 = FUN_183be0724(lVar17,0,&local_110);
        if ((uVar7 & 1) != 0) {
          if (DAT_1edf34740 != -1) {
            func_0x00018813aad0(&DAT_1edf34740,&DAT_1e223f728);
          }
          lVar8 = func_0x000188143c60(DAT_1edf35100);
          if (lVar8 == 0) {
            lVar8 = func_0x0001881404d0(*_DAT_1e00fe6a8,100,0);
          }
          else {
            lVar6 = func_0x0001881404e0();
            if (0 < lVar6) {
              lVar18 = 0;
              do {
                lVar9 = func_0x000188140510(lVar8,lVar18);
                if (lVar17 == lVar9) {
                  pcVar11 = "invalid color space: color space cannot have a circular reference.";
                  goto LAB_183bd88cc;
                }
                lVar18 = lVar18 + 1;
              } while (lVar6 != lVar18);
            }
          }
          func_0x0001881404a0(lVar8,lVar17);
          func_0x000188143d30(DAT_1edf35100,lVar8);
          uVar16 = local_110;
          lVar6 = _create_device_space(local_110);
          if (lVar6 == 0) {
            iVar5 = func_0x0001881386b0(uVar16,"CalGray");
            if (iVar5 == 0) {
              if (*(long *)(lVar17 + 0x18) - *(long *)(lVar17 + 0x10) == 0x10) {
                local_a0[0] = 0;
                local_b8[0] = 0;
                uVar10 = FUN_183bd5ee4(lVar17,1,local_b8);
                uVar7 = local_b8[0];
                if ((uVar10 & 1) == 0) {
                  pcVar11 = 
                  "invalid `CalGray\' color space: second color space array entry is not a dictionary."
                  ;
                }
                else {
                  uVar10 = _get_array(local_b8[0],"WhitePoint",local_100,3,0);
                  if ((uVar10 & 1) == 0) {
                    pcVar11 = 
                    "invalid `CalGray\' color space: `WhitePoint\' value is not an array of 3 numbers."
                    ;
                  }
                  else {
                    uVar10 = _get_array(uVar7,"BlackPoint",local_88,3,_default_black_point_16318);
                    if ((uVar10 & 1) != 0) {
                      iVar5 = FUN_183be0248(uVar7,"Gamma",local_a0);
                      lVar6 = local_a0[0];
                      if (iVar5 == 0) {
                        lVar6 = 0x3ff0000000000000;
                      }
                      lVar6 = FUN_183f3af80(lVar6,local_100,local_88);
joined_r0x000183bd8abc:
                      if (lVar6 == 0) goto LAB_183bd9214;
                      goto LAB_183bd95e8;
                    }
                    pcVar11 = 
                    "invalid `CalGray\' color space: `BlackPoint\' value is not an array of 3 numbers."
                    ;
                  }
                }
              }
              else {
                pcVar11 = 
                "invalid `CalGray\' color space: incorrect number of entriesin color space array.";
              }
LAB_183bd95dc:
              _pdf_error(pcVar11);
            }
            else {
              iVar5 = func_0x0001881386b0(uVar16,"CalRGB");
              if (iVar5 == 0) {
                if (*(long *)(lVar17 + 0x18) - *(long *)(lVar17 + 0x10) == 0x10) {
                  local_108 = 0;
                  uVar10 = FUN_183bd5ee4(lVar17,1,&local_108);
                  uVar7 = local_108;
                  if ((uVar10 & 1) == 0) {
                    pcVar11 = 
                    "invalid `CalRGB\' color space: second color space array entry is not a dictionary."
                    ;
                  }
                  else {
                    uVar10 = _get_array(local_108,"WhitePoint",local_88,3,0);
                    if ((uVar10 & 1) == 0) {
                      pcVar11 = 
                      "invalid `CalRGB\' color space: `WhitePoint\' value is not an array of 3 numbers."
                      ;
                    }
                    else {
                      uVar10 = _get_array(uVar7,"BlackPoint",local_a0,3,_default_black_point_16318);
                      if ((uVar10 & 1) == 0) {
                        pcVar11 = 
                        "invalid `CalRGB\' color space: `BlackPoint\' value is not an array of 3 numbers."
                        ;
                      }
                      else {
                        uVar10 = _get_array(uVar7,"Gamma",local_b8,3,&DAT_1842673d0);
                        if ((uVar10 & 1) == 0) {
                          pcVar11 = 
                          "invalid `CalRGB\' color space: `Gamma\' value is not an array of 3 numbers."
                          ;
                        }
                        else {
                          uVar7 = _get_array(uVar7,"Matrix",local_100,9,
                                             _color_space_state_create_calibrated_rgb_default_matrix
                                            );
                          if ((uVar7 & 1) != 0) {
                            lVar6 = FUN_183c2392c(local_88,local_a0,local_b8,local_100);
                            goto joined_r0x000183bd8abc;
                          }
                          pcVar11 = 
                          "invalid `CalRGB\' color space: `Matrix\' value is not an array of 9 numbers."
                          ;
                        }
                      }
                    }
                  }
                }
                else {
                  pcVar11 = 
                  "invalid `CalRGB\' color space: incorrect number of entries in color space array."
                  ;
                }
                goto LAB_183bd95dc;
              }
              iVar5 = func_0x0001881386b0(uVar16,"Lab");
              if (iVar5 == 0) {
                if (*(long *)(lVar17 + 0x18) - *(long *)(lVar17 + 0x10) == 0x10) {
                  local_b8[0] = 0;
                  uVar10 = FUN_183bd5ee4(lVar17,1,local_b8);
                  uVar7 = local_b8[0];
                  if ((uVar10 & 1) == 0) {
                    pcVar11 = 
                    "invalid `Lab\' color space: second color space array entry is not a dictionary."
                    ;
                  }
                  else {
                    uVar10 = _get_array(local_b8[0],"WhitePoint",local_88,3,0);
                    if ((uVar10 & 1) == 0) {
                      pcVar11 = 
                      "invalid `Lab\' color space: `WhitePoint\' value is not an array of 3 numbers."
                      ;
                    }
                    else {
                      uVar10 = _get_array(uVar7,"BlackPoint",local_a0,3,_default_black_point_16318);
                      if ((uVar10 & 1) == 0) {
                        pcVar11 = 
                        "invalid `Lab\' color space: `BlackPoint\' value is not an array of 3 numbers."
                        ;
                      }
                      else {
                        uVar7 = _get_array(uVar7,"Range",local_100,4,&DAT_1842673e8);
                        if ((uVar7 & 1) != 0) {
                          lVar6 = FUN_183c5bd98(local_88,local_a0,local_100);
                          goto joined_r0x000183bd8abc;
                        }
                        pcVar11 = 
                        "invalid `Lab\' color space: `Range\' value is not an array of 4 numbers.";
                      }
                    }
                  }
                }
                else {
                  pcVar11 = 
                  "invalid `Lab\' color space: incorrect number of entries in color space array.";
                }
                goto LAB_183bd95dc;
              }
              iVar5 = func_0x0001881386b0(uVar16,"ICCBased");
              if (iVar5 == 0) {
                local_100[0] = 0;
                local_88[0] = 0;
                local_a0[0] = 0;
                if (*(long *)(lVar17 + 0x18) - *(long *)(lVar17 + 0x10) == 0x10) {
                  uVar7 = FUN_183bd6e08(lVar17,1,local_a0);
                  lVar6 = local_a0[0];
                  if ((uVar7 & 1) == 0) {
                    pcVar11 = "invalid `ICCBased\' color space: 2nd element is not a stream.";
                  }
                  else {
                    if (local_a0[0] == 0) {
                      uVar16 = 0;
                    }
                    else {
                      uVar16 = *(undefined8 *)(local_a0[0] + 0x30);
                    }
                    iVar5 = FUN_183bd6c4c(uVar16,"N",local_100);
                    uVar7 = local_100[0];
                    if ((iVar5 == 0) || ((long)local_100[0] < 1)) {
                      pcVar11 = "invalid `ICCBased\' color space: missing or invalid `N\' entry.";
                    }
                    else {
                      if ((local_100[0] == 4) || ((local_100[0] & 0x7ffffffffffffffd) == 1)) {
                        iVar5 = FUN_183bcf4b0(uVar16,"Alternate",local_88);
                        if ((iVar5 == 0) || (lVar18 = FUN_183bd8754(local_88[0]), lVar18 == 0)) {
                          if (uVar7 == 4) {
                            lVar18 = FUN_183b3953c();
                          }
                          else if (uVar7 == 3) {
                            lVar18 = FUN_183b2c4f0();
                          }
                          else if (uVar7 == 1) {
                            lVar18 = FUN_183b2cf50();
                          }
                          else {
                            lVar18 = 0;
                          }
                        }
                        lVar9 = func_0x000188138470(uVar7 << 4,0x100004000313f17);
                        if (lVar9 == 0) {
                          if (lVar18 != 0) {
                            lVar6 = func_0x000188140d60(lVar18);
                            if (DAT_1edf367a0 != -1) {
                              func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                            }
                            if (lVar6 == DAT_1edf36a20) goto LAB_183bd978c;
                          }
                          goto LAB_183bd9214;
                        }
                        uVar10 = _get_array(uVar16,"Range",lVar9,uVar7 << 1,0);
                        if ((uVar10 & 1) == 0) {
                          lVar13 = 0;
                          uVar10 = uVar7;
                          do {
                            puVar3 = (undefined8 *)(lVar9 + lVar13 * 0x10);
                            puVar3[1] = 0x3ff0000000000000;
                            *puVar3 = 0;
                            lVar13 = lVar13 + 1;
                            uVar10 = uVar10 - 1;
                          } while (uVar10 != 0);
                        }
                        local_b8[0] = local_b8[0] & 0xffffffff00000000;
                        lVar6 = FUN_183ca244c(lVar6,0,0,local_b8);
                        if (lVar6 != 0) {
                          if ((int)local_b8[0] == 0) {
                            lVar13 = FUN_183b538e4(lVar6);
                            func_0x000188141240(lVar6);
                            if (lVar13 != 0) {
                              lVar6 = FUN_183bd603c(uVar7,lVar9,lVar13,lVar18);
                              if (lVar18 != 0) {
                                lVar19 = func_0x000188140d60(lVar18);
                                if (DAT_1edf367a0 != -1) {
                                  func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                                }
                                if (lVar19 == DAT_1edf36a20) {
                                  func_0x000188141240(lVar18);
                                }
                              }
                              lVar18 = func_0x000188140d60(lVar13);
                              if (DAT_1edf367f0 != -1) {
                                func_0x00018813aad0(&DAT_1edf367f0,&DAT_1e223ea08);
                              }
                              if (lVar18 == DAT_1edf36990) {
                                func_0x000188141240(lVar13);
                              }
                              func_0x000188138390(lVar9);
                              goto joined_r0x000183bd94c4;
                            }
                          }
                          else {
                            func_0x000188141240(lVar6);
                          }
                        }
                        if (lVar18 != 0) {
                          lVar6 = func_0x000188140d60(lVar18);
                          if (DAT_1edf367a0 != -1) {
                            func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                          }
                          if (lVar6 == DAT_1edf36a20) {
                            func_0x000188141240(lVar18);
                          }
                        }
                        goto LAB_183bd94dc;
                      }
                      pcVar11 = "invalid `ICCBased\' color space: invalid `N\' entry.";
                    }
                  }
                }
                else {
                  pcVar11 = 
                  "invalid `ICCBased\' color space: incorrect number of entries in color space array."
                  ;
                }
                goto LAB_183bd95dc;
              }
              iVar5 = func_0x0001881386b0(uVar16,"Separation");
              if (iVar5 == 0) {
                if (*(long *)(lVar17 + 0x18) - *(long *)(lVar17 + 0x10) != 0x20) {
                  pcVar11 = 
                  "invalid `Separation\' color space: incorrect number of entries in color space array."
                  ;
LAB_183bd8df4:
                  _pdf_error(pcVar11);
                  goto LAB_183bd9214;
                }
                local_a0[0] = 0;
                uVar7 = FUN_183be0724(lVar17,1,local_a0);
                if ((uVar7 & 1) == 0) {
                  pcVar11 = "invalid `Separation\' color space: name entry is not a name.";
                }
                else {
                  local_100[0] = 0;
                  local_88[0] = 0;
                  iVar5 = FUN_183bcfb04(lVar17,2,local_88);
                  lVar6 = local_88[0];
                  if (iVar5 == 0) {
                    pcVar11 = 
                    "invalid `Separation\' color space: alternate color space entry is not an object."
                    ;
                  }
                  else if (local_88[0] == 0) {
LAB_183bd91d8:
                    pcVar11 = 
                    "invalid `Separation\' alternate color space: alternate color space must be a name or an array."
                    ;
                  }
                  else if (*(int *)(local_88[0] + 8) == 7) {
                    lVar18 = *(long *)(local_88[0] + 0x20);
                    if ((lVar18 == 0) || (*(long *)(lVar18 + 0x18) == *(long *)(lVar18 + 0x10))) {
                      pcVar11 = 
                      "invalid `Separation\' alternate color space: empty color space array.";
                    }
                    else {
                      iVar5 = FUN_183be0724(lVar18,0,local_100);
                      uVar7 = local_100[0];
                      if (iVar5 == 0) {
                        pcVar11 = 
                        "invalid `Separation\' alternate color space: first entry must be a color space name."
                        ;
                      }
                      else {
                        iVar5 = func_0x0001881386b0(local_100[0],"Separation");
                        if ((((iVar5 != 0) &&
                             (iVar5 = func_0x0001881386b0(uVar7,"DeviceN"), iVar5 != 0)) &&
                            (iVar5 = func_0x0001881386b0(uVar7,"Indexed"), iVar5 != 0)) &&
                           (iVar5 = func_0x0001881386b0(uVar7,"Pattern"), iVar5 != 0))
                        goto LAB_183bd8d30;
                        pcVar11 = 
                        "invalid `Separation\' alternate color space: alternate color space may not be a special color space."
                        ;
                      }
                    }
                  }
                  else {
                    if (*(int *)(local_88[0] + 8) != 5) goto LAB_183bd91d8;
                    iVar5 = func_0x0001881386b0(*(undefined8 *)(local_88[0] + 0x20),"Pattern");
                    if (iVar5 == 0) {
                      pcVar11 = 
                      "invalid `Separation\' color space: alternate color space may not be a special color space."
                      ;
                    }
                    else {
LAB_183bd8d30:
                      lVar18 = FUN_183bd8754(lVar6);
                      if (lVar18 != 0) {
                        local_100[0] = 0;
                        uVar7 = FUN_183bcfb04(lVar17,3,local_100);
                        if ((uVar7 & 1) == 0) {
                          _pdf_error(
                                    "invalid `Separation\' color space: tint transform entry is not an object."
                                    );
                          lVar6 = 0;
                        }
                        else {
                          lVar9 = FUN_183ca31ac(local_100[0]);
                          lVar6 = FUN_183ed2a3c(1,local_a0,lVar18,lVar9,0);
                          if (lVar9 != 0) {
                            func_0x000188141240(lVar9);
                          }
                        }
                        lVar9 = func_0x000188140d60(lVar18);
                        if (DAT_1edf367a0 != -1) {
                          func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                        }
                        if (lVar9 == DAT_1edf36a20) {
                          func_0x000188141240(lVar18);
                        }
                        goto joined_r0x000183bd8abc;
                      }
                      pcVar11 = "invalid `Separation\' color space: invalid alternate color space.";
                    }
                  }
                }
                goto LAB_183bd95dc;
              }
              iVar5 = func_0x0001881386b0(uVar16,"DeviceN");
              if (iVar5 == 0) {
                local_100[0] = 0;
                local_88[0] = 0;
                lVar6 = *(long *)(lVar17 + 0x18) - *(long *)(lVar17 + 0x10);
                if ((lVar6 >> 3) - 6U < 0xfffffffffffffffe) {
                  pcVar11 = "invalid `DeviceN\' color space: incorrect number of entries.";
                }
                else {
                  uVar7 = FUN_183d52960(lVar17,1,local_88);
                  lVar18 = local_88[0];
                  if ((((uVar7 & 1) != 0) && (local_88[0] != 0)) &&
                     (lVar13 = *(long *)(local_88[0] + 0x18) - *(long *)(local_88[0] + 0x10),
                     lVar13 != 0)) {
                    lVar9 = func_0x000188138470(lVar13,0x50040ee9192b6);
                    if (lVar9 == 0) goto LAB_183bd9214;
                    lVar19 = 0;
                    lVar13 = lVar13 >> 3;
                    do {
                      uVar7 = FUN_183be0724(lVar18,lVar19,lVar9 + lVar19 * 8);
                      if ((uVar7 & 1) == 0) {
                        pcVar11 = "invalid `DeviceN\' color space: invalid names entry.";
                        goto LAB_183bd94d4;
                      }
                      lVar19 = lVar19 + 1;
                    } while (lVar13 != lVar19);
                    uVar7 = FUN_183bcfb04(lVar17,2,local_100);
                    if (((uVar7 & 1) == 0) || (lVar18 = FUN_183bd8754(local_100[0]), lVar18 == 0)) {
                      pcVar11 = "invalid `DeviceN\' color space: invalid alternate color space.";
LAB_183bd94d4:
                      _pdf_error(pcVar11);
                      goto LAB_183bd94dc;
                    }
                    uVar7 = FUN_183bcfb04(lVar17,3,local_100);
                    if ((uVar7 & 1) == 0) {
                      _pdf_error("invalid `DeviceN\' color space: invalid tint transform.");
                      lVar6 = func_0x000188140d60(lVar18);
joined_r0x000183bd97c0:
                      if (DAT_1edf367a0 != -1) {
                        func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                      }
                      lVar19 = lVar18;
                      if (lVar6 != DAT_1edf36a20) goto LAB_183bd94dc;
                    }
                    else {
                      lVar19 = FUN_183ca31ac(local_100[0]);
                      if (lVar19 != 0) {
                        if (*(long *)(lVar19 + 0x20) == lVar13) {
                          if (*(long *)(*(long *)(lVar18 + 0x18) + 0x30) == *(long *)(lVar19 + 0x30)
                             ) goto LAB_183bd8fa4;
                          _pdf_error("invalid `DeviceN\' color space: invalid tint transform.");
                          func_0x000188141240(lVar19);
                          lVar6 = func_0x000188140d60(lVar18);
                        }
                        else {
                          _pdf_error("invalid `DeviceN\' color space: invalid tint transform.");
                          func_0x000188141240(lVar19);
                          lVar6 = func_0x000188140d60(lVar18);
                        }
                        goto joined_r0x000183bd97c0;
                      }
LAB_183bd8fa4:
                      local_a0[0] = 0;
                      if ((lVar6 != 0x28) ||
                         (uVar7 = FUN_183bd5ee4(lVar17,4,local_a0), (uVar7 & 1) != 0)) {
                        lVar6 = FUN_183ed2a3c(lVar13,lVar9,lVar18,lVar19,0);
                        lVar13 = func_0x000188140d60(lVar18);
                        if (DAT_1edf367a0 != -1) {
                          func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                        }
                        if (lVar13 == DAT_1edf36a20) {
                          func_0x000188141240(lVar18);
                        }
                        if (lVar19 != 0) {
                          func_0x000188141240(lVar19);
                        }
                        func_0x000188138390(lVar9);
                        goto joined_r0x000183bd8abc;
                      }
                      _pdf_error("invalid `DeviceN\' color space: invalid attributes.");
                      lVar6 = func_0x000188140d60(lVar18);
                      if (DAT_1edf367a0 != -1) {
                        func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                      }
                      if (lVar6 == DAT_1edf36a20) {
                        func_0x000188141240(lVar18);
                      }
                      if (lVar19 == 0) goto LAB_183bd94dc;
                    }
                    func_0x000188141240(lVar19);
LAB_183bd94dc:
                    func_0x000188138390(lVar9);
                    goto LAB_183bd9214;
                  }
                  pcVar11 = "invalid `DeviceN\' color space: invalid names entry.";
                }
                goto LAB_183bd95dc;
              }
              iVar5 = func_0x0001881386b0(uVar16,"Indexed");
              if (iVar5 == 0) {
                local_100[0] = 0;
                local_88[0] = 0;
                local_a0[0] = 0;
                local_b8[0] = 0;
                if (*(long *)(lVar17 + 0x18) - *(long *)(lVar17 + 0x10) == 0x20) {
                  uVar7 = FUN_183bcfb04(lVar17,1,local_100);
                  if ((uVar7 & 1) == 0) {
                    pcVar11 = 
                    "invalid `Indexed\' color space: second color space array entry is not an object."
                    ;
                  }
                  else {
                    lVar18 = FUN_183bd8754(local_100[0]);
                    if (lVar18 != 0) {
                      uVar10 = FUN_183d52894(lVar17,2,local_b8);
                      uVar7 = local_b8[0];
                      if ((uVar10 & 1) == 0) {
                        _pdf_error(
                                  "invalid `Indexed\' color space: high value entry is not an integer."
                                  );
                        lVar6 = func_0x000188140d60(lVar18);
                      }
                      else {
                        if (-1 < (long)local_b8[0]) {
                          iVar5 = FUN_183bd6e08(lVar17,3,local_88);
                          if (iVar5 == 0) {
                            iVar5 = FUN_183d528fc(lVar17,3,local_a0);
                            lVar6 = local_a0[0];
                            if (iVar5 == 0) {
                              _pdf_error(
                                        "invalid `Indexed\' color space: lookup entry is not a stream or a string."
                                        );
                              lVar6 = func_0x000188140d60(lVar18);
                              goto joined_r0x000183bd9240;
                            }
                            lVar9 = *(long *)(*(long *)(lVar18 + 0x18) + 0x30);
                            uVar10 = lVar9 + lVar9 * uVar7;
                            if (local_a0[0] == 0) {
                              if (uVar10 != 0) goto LAB_183bd9750;
                              lVar6 = 0;
                            }
                            else {
                              if (*(long *)(local_a0[0] + 0x18) != 0) {
                                _decrypt_string(local_a0[0]);
                              }
                              if (*(ulong *)(lVar6 + 0x48) < uVar10) {
LAB_183bd9750:
                                _pdf_error("invalid `Indexed\' color space: invalid lookup entry.");
                                lVar6 = func_0x000188140d60(lVar18);
                                goto joined_r0x000183bd9240;
                              }
                              if (*(long *)(lVar6 + 0x18) != 0) {
                                _decrypt_string(lVar6);
                              }
                              lVar6 = lVar6 + 0x50;
                            }
                            lVar6 = FUN_183dc4ea0(lVar18,uVar7,lVar6);
                          }
                          else {
                            local_108 = local_108 & 0xffffffff00000000;
                            lVar9 = FUN_183ca244c(local_88[0],0,0,&local_108);
                            if (lVar9 == 0) {
LAB_183bd9744:
                              lVar6 = 0;
                            }
                            else {
                              if ((int)local_108 == 0) {
                                uVar20 = *(ulong *)(*(long *)(lVar18 + 0x18) + 0x30);
                                uVar10 = uVar7 + 1;
                                uVar15 = uVar20 * uVar10;
                                uVar12 = func_0x000188140ab0(lVar9);
                                if (((uVar20 | uVar10) >> 0x20 == 0) ||
                                   ((lVar6 = 0, auVar1._8_8_ = 0, auVar1._0_8_ = uVar10,
                                    auVar2._8_8_ = 0, auVar2._0_8_ = uVar20,
                                    SUB168(auVar1 * auVar2,8) == 0 && (uVar10 * uVar20 <= uVar15))))
                                {
                                  if (uVar12 < uVar15) {
                                    lVar13 = func_0x000188138460(1,uVar15,0x8d32ad0b);
                                    if (lVar13 == 0) goto LAB_183bd9744;
                                    uVar16 = func_0x000188140aa0(lVar9);
                                    uVar14 = func_0x000188140ab0(lVar9);
                                    func_0x0001881384e0(lVar13,uVar16,uVar14);
                                    lVar6 = FUN_183dc4ea0(lVar18,uVar7,lVar13);
                                    func_0x000188138390(lVar13);
                                  }
                                  else {
                                    uVar16 = func_0x000188140aa0(lVar9);
                                    lVar6 = FUN_183dc4ea0(lVar18,uVar7,uVar16);
                                  }
                                }
                              }
                              else {
                                lVar6 = 0;
                              }
                              func_0x000188141240(lVar9);
                            }
                          }
                          lVar9 = func_0x000188140d60(lVar18);
                          if (DAT_1edf367a0 != -1) {
                            func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                          }
                          if (lVar9 == DAT_1edf36a20) {
                            func_0x000188141240(lVar18);
                          }
                          goto joined_r0x000183bd8abc;
                        }
                        _pdf_error("invalid `Indexed\' color space: high value entry is negative.");
                        lVar6 = func_0x000188140d60(lVar18);
                      }
joined_r0x000183bd9240:
                      if (DAT_1edf367a0 != -1) {
                        func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                      }
                      if (lVar6 == DAT_1edf36a20) {
LAB_183bd978c:
                        func_0x000188141240(lVar18);
                      }
                      goto LAB_183bd9214;
                    }
                    pcVar11 = "invalid `Indexed\' color space: invalid base color space.";
                  }
                }
                else {
                  pcVar11 = 
                  "invalid `Indexed\' color space: incorrect number of entries in color space array."
                  ;
                }
                goto LAB_183bd95dc;
              }
              iVar5 = func_0x0001881386b0(uVar16,"Pattern");
              if (iVar5 != 0) {
                pcVar11 = "unrecognized color space `%s\'.";
                goto LAB_183bd8df4;
              }
              local_100[0] = 0;
              lVar6 = *(long *)(lVar17 + 0x18) - *(long *)(lVar17 + 0x10) >> 3;
              if (lVar6 == 2) {
                FUN_183bcfb04(lVar17,1,local_100);
                lVar18 = FUN_183bd8754(local_100[0]);
                if (lVar18 == 0) {
                  pcVar11 = "invalid `Pattern\' color space: invalid base color space.";
                  goto LAB_183bd9204;
                }
                lVar6 = FUN_183be6414();
                lVar9 = func_0x000188140d60(lVar18);
                if (DAT_1edf367a0 != -1) {
                  func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                }
                if (lVar9 == DAT_1edf36a20) {
                  func_0x000188141240(lVar18);
                }
              }
              else if (lVar6 == 1) {
                lVar6 = FUN_183be6414(0);
              }
              else {
                pcVar11 = 
                "invalid `Pattern\' color space: incorrect number of entries in color space array.";
LAB_183bd9204:
                _pdf_error(pcVar11);
                lVar6 = 0;
              }
joined_r0x000183bd94c4:
              if (lVar6 != 0) goto LAB_183bd95e8;
            }
LAB_183bd9214:
            lVar6 = 0;
          }
          else {
LAB_183bd95e8:
            lVar6 = _CGPDFObjectSetAssociation(param_1,lVar6,"ColorSpace");
          }
          uVar16 = func_0x0001881404e0(lVar8);
          uVar16 = func_0x0001881404f0(lVar8,0,uVar16,lVar17);
          func_0x000188140540(lVar8,uVar16);
          func_0x000188143d30(DAT_1edf35100,lVar8);
          goto LAB_183bd88d4;
        }
        pcVar11 = "invalid color space: first color space array entry must be a name.";
      }
LAB_183bd88cc:
      _pdf_error(pcVar11);
      goto LAB_183bd88d0;
    }
  }
LAB_183bd88d4:
  if (*_DAT_1e0186220 == local_70) {
    return lVar6;
  }
LAB_183bd9660:
  lVar6 = func_0x000188138130();
  return lVar6;
}



/* ==== _CreateColorSpaceFromObject @ 183fe3b4c size=2568 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _CreateColorSpaceFromObject(long param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  long lVar12;
  undefined1 auVar13 [16];
  undefined8 local_118;
  long local_110;
  long local_108;
  long local_100 [10];
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  long local_98 [7];
  
  local_98[6] = *_DAT_1e0186220;
  *param_2 = 0;
  if (param_1 == 0) goto LAB_183fe4290;
  if (*(int *)(param_1 + 8) != 7) {
    if (*(int *)(param_1 + 8) == 5) {
      uVar11 = *(undefined8 *)(param_1 + 0x20);
      iVar3 = func_0x0001881386b0(uVar11,"DeviceCMYK");
      if (iVar3 == 0) {
        uVar11 = FUN_183b3953c();
      }
      else {
        iVar3 = func_0x0001881386b0(uVar11,"DeviceGray");
        if (iVar3 == 0) {
          uVar11 = FUN_183b2cf50();
        }
        else {
          iVar3 = func_0x0001881386b0(uVar11,"DeviceRGB");
          if (iVar3 == 0) {
            uVar11 = FUN_183b2c4f0();
          }
          else {
            iVar3 = func_0x0001881386b0(uVar11,"Pattern");
            if (iVar3 != 0) goto LAB_183fe4290;
            uVar11 = FUN_183be6414(0);
          }
        }
      }
      *param_2 = uVar11;
    }
    goto LAB_183fe4290;
  }
  local_118 = 0;
  local_110 = 0;
  iVar3 = _GetNamedArrayCommandFromObject(param_1,&local_110,&local_118);
  if (iVar3 == 0) goto LAB_183fe4290;
  if (DAT_1eb0584e8 != -1) {
    func_0x00018813aad0(&DAT_1eb0584e8,&DAT_1e2240650);
  }
  lVar4 = func_0x000188143c60(DAT_1eb0584f0);
  if (lVar4 == 0) {
    lVar4 = func_0x0001881404d0(*_DAT_1e00fe6a8,100,0);
    lVar9 = local_110;
  }
  else {
    lVar5 = func_0x0001881404e0();
    lVar9 = local_110;
    if (0 < lVar5) {
      lVar12 = 0;
      do {
        lVar6 = func_0x000188140510(lVar4,lVar12);
        if (lVar9 == lVar6) {
          func_0x00018813adf0("invalid color space: color space cannot have a circular reference.\n"
                              ,0x43,1,*_DAT_1e0186228);
          goto LAB_183fe4290;
        }
        lVar12 = lVar12 + 1;
      } while (lVar5 != lVar12);
    }
  }
  func_0x0001881404a0(lVar4,lVar9);
  func_0x000188143d30(DAT_1eb0584f0,lVar4);
  uVar11 = local_118;
  iVar3 = func_0x0001881386b0(local_118,"CalGray");
  if (iVar3 == 0) {
    local_98[0] = 0;
    *param_2 = 0;
    iVar3 = FUN_183bd5ee4(lVar9,1,local_98);
    lVar9 = local_98[0];
    if (iVar3 != 0) {
      local_98[3] = 0;
      local_98[4] = 0;
      local_98[5] = 0;
      local_b0 = 0;
      iVar3 = _GetArrayValues(local_98[0],"WhitePoint",local_100,3);
      if (iVar3 != 0) {
        _GetArrayValues(lVar9,"BlackPoint",local_98 + 3,3);
        FUN_183be0248(lVar9,"Gamma",&local_b0);
        uVar11 = FUN_183f3af80(local_b0,local_100,local_98 + 3);
LAB_183fe4258:
        *param_2 = uVar11;
      }
    }
  }
  else {
    iVar3 = func_0x0001881386b0(uVar11,"CalRGB");
    if (iVar3 == 0) {
      local_108 = 0;
      *param_2 = 0;
      iVar3 = FUN_183bd5ee4(lVar9,1,&local_108);
      lVar9 = local_108;
      if (iVar3 != 0) {
        local_98[0] = 0;
        local_98[1] = 0;
        local_98[2] = 0;
        uStack_a8 = 0x3ff0000000000000;
        local_b0 = 0x3ff0000000000000;
        local_a0 = 0x3ff0000000000000;
        local_100[3] = 0;
        local_100[6] = 0;
        local_100[5] = 0;
        local_100[2] = 0;
        local_100[1] = 0;
        local_100[0] = 0x3ff0000000000000;
        local_100[4] = 0x3ff0000000000000;
        local_100[7] = 0;
        local_100[8] = 0x3ff0000000000000;
        iVar3 = _GetArrayValues(local_108,"WhitePoint",local_98 + 3,3);
        if (iVar3 != 0) {
          _GetArrayValues(lVar9,"BlackPoint",local_98,3);
          _GetArrayValues(lVar9,"Gamma",&local_b0,3);
          _GetArrayValues(lVar9,"Matrix",local_100,9);
          uVar11 = FUN_183c2392c(local_98 + 3,local_98,&local_b0,local_100);
          goto LAB_183fe4258;
        }
      }
    }
    else {
      iVar3 = func_0x0001881386b0(uVar11,"Lab");
      if (iVar3 == 0) {
        local_b0 = 0;
        *param_2 = 0;
        iVar3 = FUN_183bd5ee4(lVar9,1,&local_b0);
        lVar9 = local_b0;
        if (iVar3 != 0) {
          local_98[0] = 0;
          local_98[1] = 0;
          local_98[2] = 0;
          local_100[1] = 0x4059000000000000;
          local_100[0] = -0x3fa7000000000000;
          local_100[3] = 0x4059000000000000;
          local_100[2] = 0xc059000000000000;
          iVar3 = _GetArrayValues(local_b0,"WhitePoint",local_98 + 3,3);
          if (iVar3 != 0) {
            _GetArrayValues(lVar9,"BlackPoint",local_98,3);
            _GetArrayValues(lVar9,"Range",local_100,4);
            uVar11 = FUN_183c5bd98(local_98 + 3,local_98,local_100);
            goto LAB_183fe4258;
          }
        }
      }
      else {
        iVar3 = func_0x0001881386b0(uVar11,"ICCBased");
        if (iVar3 == 0) {
          *param_2 = 0;
          local_100[0] = 0;
          iVar3 = FUN_183bd6e08(lVar9,1,local_100);
          lVar9 = local_100[0];
          if (((((iVar3 != 0) && (local_98[3] = 0, local_100[0] != 0)) &&
               (lVar5 = *(long *)(local_100[0] + 0x30), lVar5 != 0)) &&
              ((iVar3 = FUN_183bd6c4c(lVar5,"N",local_98 + 3), lVar12 = local_98[3], iVar3 != 0 &&
               (local_98[3] < 5)))) && ((local_98[3] & 0xfffffffffffffffdU) != 0)) {
            local_98[0] = 0;
            iVar3 = FUN_183bcf4b0(lVar5,"Alternate",local_98);
            if (iVar3 == 0) {
              if (lVar12 == 3) {
LAB_183fe4384:
                lVar6 = FUN_183b2c4f0();
              }
              else {
                if (lVar12 != 1) goto LAB_183fe4338;
LAB_183fe42d8:
                lVar6 = FUN_183b2cf50();
              }
LAB_183fe4388:
              uVar1 = (uint)lVar12 * 2;
              uVar7 = (ulong)uVar1;
              lVar8 = func_0x000188138470(-(ulong)(((uint)lVar12 & 0x7fffffff) >> 0x1e) &
                                          0xfffffff800000000 | uVar7 << 3,0x100004000313f17);
              if (0 < (int)uVar1) {
                lVar10 = 0;
                auVar13 = NEON_fmov(0x3ff0000000000000,8);
                do {
                  puVar2 = (undefined8 *)(lVar8 + lVar10 * 8);
                  puVar2[1] = auVar13._8_8_;
                  *puVar2 = 0;
                  lVar10 = lVar10 + 2;
                  uVar7 = uVar7 - 2;
                } while (uVar7 != 0);
              }
              _GetArrayValues(lVar5,"Range",lVar8);
              local_b0 = (ulong)local_b0._4_4_ << 0x20;
              lVar9 = FUN_183ca244c(lVar9,0,0,&local_b0);
              if (lVar9 != 0) {
                lVar5 = FUN_183b538e4();
                if (lVar5 != 0) {
                  uVar11 = FUN_183bd603c(lVar12,lVar8,lVar5,lVar6);
                  *param_2 = uVar11;
                  lVar12 = func_0x000188140d60(lVar5);
                  if (DAT_1edf367f0 != -1) {
                    func_0x00018813aad0(&DAT_1edf367f0,&DAT_1e223ea08);
                  }
                  if (lVar12 == DAT_1edf36990) {
                    func_0x000188141240(lVar5);
                  }
                }
                func_0x000188141240(lVar9);
              }
              if (lVar6 != 0) {
                lVar9 = func_0x000188140d60(lVar6);
                if (DAT_1edf367a0 != -1) {
                  func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                }
                if (lVar9 == DAT_1edf36a20) {
                  func_0x000188141240(lVar6);
                }
              }
LAB_183fe44d0:
              func_0x000188138390(lVar8);
            }
            else if ((local_98[0] != 0) && (*(int *)(local_98[0] + 8) == 5)) {
              uVar11 = *(undefined8 *)(local_98[0] + 0x20);
              iVar3 = func_0x0001881386b0(uVar11,"DeviceCMYK");
              if (iVar3 == 0) {
LAB_183fe4338:
                lVar6 = FUN_183b3953c();
                goto LAB_183fe4388;
              }
              iVar3 = func_0x0001881386b0(uVar11,"DeviceGray");
              if (iVar3 == 0) goto LAB_183fe42d8;
              iVar3 = func_0x0001881386b0(uVar11,"DeviceRGB");
              if (iVar3 == 0) goto LAB_183fe4384;
            }
          }
        }
        else {
          iVar3 = func_0x0001881386b0(uVar11,"Indexed");
          if (iVar3 == 0) {
            _CreateIndexedColorSpace(lVar9,param_2);
          }
          else {
            iVar3 = func_0x0001881386b0(uVar11,"DeviceN");
            if (iVar3 == 0) {
              local_100[0] = 0;
              *param_2 = 0;
              iVar3 = FUN_183d52960(lVar9,1,local_100);
              if (iVar3 != 0) {
                local_98[3] = 0;
                iVar3 = FUN_183bcfb04(lVar9,2,local_98 + 3);
                if (iVar3 != 0) {
                  local_98[0] = 0;
                  iVar3 = FUN_183bcfb04(lVar9,3,local_98);
                  if (iVar3 != 0) {
                    _CreateColorSpaceFromObject(local_98[3],&local_b0);
                    lVar9 = local_100[0];
                    if (local_100[0] == 0) {
                      lVar8 = func_0x000188138470(0,0x10040436913f5);
LAB_183fe42fc:
                      lVar9 = FUN_183ca31ac(local_98[0]);
                      lVar12 = 0;
                    }
                    else {
                      lVar5 = *(long *)(local_100[0] + 0x10);
                      lVar12 = *(long *)(local_100[0] + 0x18);
                      lVar8 = func_0x000188138470(lVar12 - lVar5,0x10040436913f5);
                      lVar12 = lVar12 - lVar5;
                      if (lVar12 == 0) goto LAB_183fe42fc;
                      lVar5 = 0;
                      lVar12 = lVar12 >> 3;
                      do {
                        uVar7 = FUN_183be0724(lVar9,lVar5,lVar8 + lVar5 * 8);
                        lVar6 = local_b0;
                        if ((uVar7 & 1) == 0) goto LAB_183fe4344;
                        lVar5 = lVar5 + 1;
                      } while (lVar12 != lVar5);
                      lVar9 = FUN_183ca31ac(local_98[0]);
                    }
                    lVar6 = local_b0;
                    uVar11 = FUN_183ed2a3c(lVar12,lVar8,local_b0,lVar9,0);
                    *param_2 = uVar11;
                    if (lVar9 != 0) {
                      func_0x000188141240(lVar9);
                    }
LAB_183fe4344:
                    if (lVar6 != 0) {
                      lVar9 = func_0x000188140d60(lVar6);
                      if (DAT_1edf367a0 != -1) {
                        func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                      }
                      if (lVar9 == DAT_1edf36a20) {
                        func_0x000188141240(lVar6);
                      }
                    }
                    goto LAB_183fe44d0;
                  }
                }
              }
            }
            else {
              iVar3 = func_0x0001881386b0(uVar11,"Pattern");
              if (iVar3 == 0) {
                if ((lVar9 == 0) || ((ulong)(*(long *)(lVar9 + 0x18) - *(long *)(lVar9 + 0x10)) < 9)
                   ) {
                  uVar11 = FUN_183be6414(0);
                  goto LAB_183fe4258;
                }
                local_100[0] = 0;
                FUN_183bcfb04(lVar9,1,local_100);
                _CreateColorSpaceFromObject(local_100[0],local_98 + 3);
                uVar7 = local_98[3];
                if (local_98[3] != 0) {
                  uVar11 = FUN_183be6414(local_98[3]);
                  *param_2 = uVar11;
LAB_183fe4244:
                  func_0x000188141240(uVar7);
                }
              }
              else {
                iVar3 = func_0x0001881386b0(uVar11,"Separation");
                if (iVar3 == 0) {
                  *param_2 = 0;
                  local_100[0] = 0;
                  iVar3 = FUN_183be0724(lVar9,1,local_100);
                  if (iVar3 != 0) {
                    local_98[3] = 0;
                    iVar3 = FUN_183bcfb04(lVar9,2,local_98 + 3);
                    if (iVar3 != 0) {
                      local_98[0] = 0;
                      iVar3 = FUN_183bcfb04(lVar9,3,local_98);
                      if (iVar3 != 0) {
                        local_b0 = local_100[0];
                        _CreateColorSpaceFromObject(local_98[3],&local_108);
                        uVar7 = FUN_183ca31ac(local_98[0]);
                        lVar9 = local_108;
                        uVar11 = FUN_183ed2a3c(1,&local_b0,local_108,uVar7,0);
                        *param_2 = uVar11;
                        if (lVar9 != 0) {
                          lVar5 = func_0x000188140d60(lVar9);
                          if (DAT_1edf367a0 != -1) {
                            func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
                          }
                          if (lVar5 == DAT_1edf36a20) {
                            func_0x000188141240(lVar9);
                          }
                        }
                        if (uVar7 != 0) goto LAB_183fe4244;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar11 = func_0x0001881404e0(lVar4);
  uVar11 = func_0x0001881404f0(lVar4,0,uVar11,local_110);
  func_0x000188140540(lVar4,uVar11);
  func_0x000188143d30(DAT_1eb0584f0,lVar4);
LAB_183fe4290:
  if (*_DAT_1e0186220 != local_98[6]) {
    func_0x000188138130();
    return;
  }
  return;
}



