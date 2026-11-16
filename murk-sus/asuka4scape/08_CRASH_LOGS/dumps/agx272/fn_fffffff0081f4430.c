// FUN_fffffff0081f4430 @ fffffff0081f4430 size=5244

void FUN_fffffff0081f4430(long *param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  int *piVar2;
  ulong uVar3;
  uint *puVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  ulong uVar11;
  uint uVar12;
  
  puVar4 = (uint *)(**(code **)(*param_1 + 0xcd0))();
  lVar5 = (**(code **)(*param_1 + 0xcd8))(param_1);
  uVar10 = (uint)param_2;
  if (DAT_fffffff00ae21808 != 0x3d) {
    uVar11 = (ulong)DAT_fffffff00ae236a0;
    iVar6 = (int)(uVar11 * 0x20);
    uVar3 = (long)puVar4 + (long)iVar6;
    if (uVar11 * 0x20 - (long)iVar6 != 0) {
      uVar3 = (ulong)(puVar4 + uVar11 * 8) & 0xffffffffffff | 0x2bad000000000000;
    }
    uVar12 = *(uint *)(uVar3 + 0x10);
    uVar9 = uVar12;
    if (uVar12 == 0xdadadada) {
      uVar9 = *(uint *)(uVar3 + 4);
    }
    if (uVar9 <= uVar10) {
      lVar1 = 8;
      if (uVar12 != 0xdadadada) {
        lVar1 = 0x14;
      }
      piVar2 = (int *)(uVar3 + (long)(int)lVar1);
      if (lVar1 != (int)lVar1) {
        piVar2 = (int *)(uVar3 + lVar1 & 0xffffffffffff | 0x2bad000000000000);
      }
      uVar12 = DAT_fffffff00ae21808;
      if (uVar10 < uVar9 + *piVar2) goto LAB_fffffff0081f5810;
    }
  }
  if (lVar5 != 0) {
    uVar12 = puVar4[4];
    uVar9 = uVar12;
    if (uVar12 == 0xdadadada) {
      uVar9 = puVar4[1];
    }
    if (uVar9 <= uVar10) {
      lVar1 = 8;
      if (uVar12 != 0xdadadada) {
        lVar1 = 0x14;
      }
      if (uVar9 + *(int *)((long)puVar4 + lVar1) <= uVar10) goto LAB_fffffff0081f458c;
      uVar11 = 0;
      puVar8 = puVar4;
LAB_fffffff0081f57e8:
      uVar12 = *puVar8;
      if (DAT_fffffff00ae21808 != 0x33) {
        DAT_fffffff00ae236a0 = (uint)uVar11;
        DAT_fffffff00ae21808 = uVar12;
      }
      goto LAB_fffffff0081f5810;
    }
LAB_fffffff0081f458c:
    if (lVar5 != 1) {
      uVar12 = puVar4[0xc];
      uVar9 = uVar12;
      if (uVar12 == 0xdadadada) {
        uVar9 = puVar4[9];
      }
      if (uVar9 <= uVar10) {
        puVar8 = puVar4 + 8;
        lVar1 = 8;
        if (uVar12 != 0xdadadada) {
          lVar1 = 0x14;
        }
        if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
          uVar11 = 1;
          goto LAB_fffffff0081f57e8;
        }
      }
      if (lVar5 != 2) {
        uVar12 = puVar4[0x14];
        uVar9 = uVar12;
        if (uVar12 == 0xdadadada) {
          uVar9 = puVar4[0x11];
        }
        if (uVar9 <= uVar10) {
          puVar8 = puVar4 + 0x10;
          lVar1 = 8;
          if (uVar12 != 0xdadadada) {
            lVar1 = 0x14;
          }
          if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
            uVar11 = 2;
            goto LAB_fffffff0081f57e8;
          }
        }
        if (lVar5 != 3) {
          uVar12 = puVar4[0x1c];
          uVar9 = uVar12;
          if (uVar12 == 0xdadadada) {
            uVar9 = puVar4[0x19];
          }
          if (uVar9 <= uVar10) {
            puVar8 = puVar4 + 0x18;
            lVar1 = 8;
            if (uVar12 != 0xdadadada) {
              lVar1 = 0x14;
            }
            if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
              uVar11 = 3;
              goto LAB_fffffff0081f57e8;
            }
          }
          if (lVar5 != 4) {
            uVar12 = puVar4[0x24];
            uVar9 = uVar12;
            if (uVar12 == 0xdadadada) {
              uVar9 = puVar4[0x21];
            }
            if (uVar9 <= uVar10) {
              puVar8 = puVar4 + 0x20;
              lVar1 = 8;
              if (uVar12 != 0xdadadada) {
                lVar1 = 0x14;
              }
              if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                uVar11 = 4;
                goto LAB_fffffff0081f57e8;
              }
            }
            if (lVar5 != 5) {
              uVar12 = puVar4[0x2c];
              uVar9 = uVar12;
              if (uVar12 == 0xdadadada) {
                uVar9 = puVar4[0x29];
              }
              if (uVar9 <= uVar10) {
                puVar8 = puVar4 + 0x28;
                lVar1 = 8;
                if (uVar12 != 0xdadadada) {
                  lVar1 = 0x14;
                }
                if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                  uVar11 = 5;
                  goto LAB_fffffff0081f57e8;
                }
              }
              if (lVar5 != 6) {
                uVar12 = puVar4[0x34];
                uVar9 = uVar12;
                if (uVar12 == 0xdadadada) {
                  uVar9 = puVar4[0x31];
                }
                if (uVar9 <= uVar10) {
                  puVar8 = puVar4 + 0x30;
                  lVar1 = 8;
                  if (uVar12 != 0xdadadada) {
                    lVar1 = 0x14;
                  }
                  if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                    uVar11 = 6;
                    goto LAB_fffffff0081f57e8;
                  }
                }
                if (lVar5 != 7) {
                  uVar12 = puVar4[0x3c];
                  uVar9 = uVar12;
                  if (uVar12 == 0xdadadada) {
                    uVar9 = puVar4[0x39];
                  }
                  if (uVar9 <= uVar10) {
                    puVar8 = puVar4 + 0x38;
                    lVar1 = 8;
                    if (uVar12 != 0xdadadada) {
                      lVar1 = 0x14;
                    }
                    if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                      uVar11 = 7;
                      goto LAB_fffffff0081f57e8;
                    }
                  }
                  if (lVar5 != 8) {
                    uVar12 = puVar4[0x44];
                    uVar9 = uVar12;
                    if (uVar12 == 0xdadadada) {
                      uVar9 = puVar4[0x41];
                    }
                    if (uVar9 <= uVar10) {
                      puVar8 = puVar4 + 0x40;
                      uVar11 = 8;
                      lVar1 = 8;
                      if (uVar12 != 0xdadadada) {
                        lVar1 = 0x14;
                      }
                      if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1))
                      goto LAB_fffffff0081f57e8;
                    }
                    if (lVar5 != 9) {
                      uVar12 = puVar4[0x4c];
                      uVar9 = uVar12;
                      if (uVar12 == 0xdadadada) {
                        uVar9 = puVar4[0x49];
                      }
                      if (uVar9 <= uVar10) {
                        puVar8 = puVar4 + 0x48;
                        lVar1 = 8;
                        if (uVar12 != 0xdadadada) {
                          lVar1 = 0x14;
                        }
                        if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                          uVar11 = 9;
                          goto LAB_fffffff0081f57e8;
                        }
                      }
                      if (lVar5 != 10) {
                        uVar12 = puVar4[0x54];
                        uVar9 = uVar12;
                        if (uVar12 == 0xdadadada) {
                          uVar9 = puVar4[0x51];
                        }
                        if (uVar9 <= uVar10) {
                          puVar8 = puVar4 + 0x50;
                          lVar1 = 8;
                          if (uVar12 != 0xdadadada) {
                            lVar1 = 0x14;
                          }
                          if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                            uVar11 = 10;
                            goto LAB_fffffff0081f57e8;
                          }
                        }
                        if (lVar5 != 0xb) {
                          uVar12 = puVar4[0x5c];
                          uVar9 = uVar12;
                          if (uVar12 == 0xdadadada) {
                            uVar9 = puVar4[0x59];
                          }
                          if (uVar9 <= uVar10) {
                            puVar8 = puVar4 + 0x58;
                            lVar1 = 8;
                            if (uVar12 != 0xdadadada) {
                              lVar1 = 0x14;
                            }
                            if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                              uVar11 = 0xb;
                              goto LAB_fffffff0081f57e8;
                            }
                          }
                          if (lVar5 != 0xc) {
                            uVar12 = puVar4[100];
                            uVar9 = uVar12;
                            if (uVar12 == 0xdadadada) {
                              uVar9 = puVar4[0x61];
                            }
                            if (uVar9 <= uVar10) {
                              puVar8 = puVar4 + 0x60;
                              lVar1 = 8;
                              if (uVar12 != 0xdadadada) {
                                lVar1 = 0x14;
                              }
                              if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                                uVar11 = 0xc;
                                goto LAB_fffffff0081f57e8;
                              }
                            }
                            if (lVar5 != 0xd) {
                              uVar12 = puVar4[0x6c];
                              uVar9 = uVar12;
                              if (uVar12 == 0xdadadada) {
                                uVar9 = puVar4[0x69];
                              }
                              if (uVar9 <= uVar10) {
                                puVar8 = puVar4 + 0x68;
                                lVar1 = 8;
                                if (uVar12 != 0xdadadada) {
                                  lVar1 = 0x14;
                                }
                                if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                                  uVar11 = 0xd;
                                  goto LAB_fffffff0081f57e8;
                                }
                              }
                              if (lVar5 != 0xe) {
                                uVar12 = puVar4[0x74];
                                uVar9 = uVar12;
                                if (uVar12 == 0xdadadada) {
                                  uVar9 = puVar4[0x71];
                                }
                                if (uVar9 <= uVar10) {
                                  puVar8 = puVar4 + 0x70;
                                  lVar1 = 8;
                                  if (uVar12 != 0xdadadada) {
                                    lVar1 = 0x14;
                                  }
                                  if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                                    uVar11 = 0xe;
                                    goto LAB_fffffff0081f57e8;
                                  }
                                }
                                if (lVar5 != 0xf) {
                                  uVar12 = puVar4[0x7c];
                                  uVar9 = uVar12;
                                  if (uVar12 == 0xdadadada) {
                                    uVar9 = puVar4[0x79];
                                  }
                                  if (uVar9 <= uVar10) {
                                    puVar8 = puVar4 + 0x78;
                                    lVar1 = 8;
                                    if (uVar12 != 0xdadadada) {
                                      lVar1 = 0x14;
                                    }
                                    if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                                      uVar11 = 0xf;
                                      goto LAB_fffffff0081f57e8;
                                    }
                                  }
                                  if (lVar5 != 0x10) {
                                    uVar12 = puVar4[0x84];
                                    uVar9 = uVar12;
                                    if (uVar12 == 0xdadadada) {
                                      uVar9 = puVar4[0x81];
                                    }
                                    if (uVar9 <= uVar10) {
                                      puVar8 = puVar4 + 0x80;
                                      lVar1 = 8;
                                      if (uVar12 != 0xdadadada) {
                                        lVar1 = 0x14;
                                      }
                                      if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                                        uVar11 = 0x10;
                                        goto LAB_fffffff0081f57e8;
                                      }
                                    }
                                    if (lVar5 != 0x11) {
                                      uVar12 = puVar4[0x8c];
                                      uVar9 = uVar12;
                                      if (uVar12 == 0xdadadada) {
                                        uVar9 = puVar4[0x89];
                                      }
                                      if (uVar9 <= uVar10) {
                                        puVar8 = puVar4 + 0x88;
                                        lVar1 = 8;
                                        if (uVar12 != 0xdadadada) {
                                          lVar1 = 0x14;
                                        }
                                        if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                                          uVar11 = 0x11;
                                          goto LAB_fffffff0081f57e8;
                                        }
                                      }
                                      if (lVar5 != 0x12) {
                                        uVar12 = puVar4[0x94];
                                        uVar9 = uVar12;
                                        if (uVar12 == 0xdadadada) {
                                          uVar9 = puVar4[0x91];
                                        }
                                        if (uVar9 <= uVar10) {
                                          puVar8 = puVar4 + 0x90;
                                          lVar1 = 8;
                                          if (uVar12 != 0xdadadada) {
                                            lVar1 = 0x14;
                                          }
                                          if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                                            uVar11 = 0x12;
                                            goto LAB_fffffff0081f57e8;
                                          }
                                        }
                                        if (lVar5 != 0x13) {
                                          uVar12 = puVar4[0x9c];
                                          uVar9 = uVar12;
                                          if (uVar12 == 0xdadadada) {
                                            uVar9 = puVar4[0x99];
                                          }
                                          if (uVar9 <= uVar10) {
                                            puVar8 = puVar4 + 0x98;
                                            lVar1 = 8;
                                            if (uVar12 != 0xdadadada) {
                                              lVar1 = 0x14;
                                            }
                                            if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1)) {
                                              uVar11 = 0x13;
                                              goto LAB_fffffff0081f57e8;
                                            }
                                          }
                                          if (lVar5 != 0x14) {
                                            uVar12 = puVar4[0xa4];
                                            uVar9 = uVar12;
                                            if (uVar12 == 0xdadadada) {
                                              uVar9 = puVar4[0xa1];
                                            }
                                            if (uVar9 <= uVar10) {
                                              puVar8 = puVar4 + 0xa0;
                                              uVar11 = 0x14;
                                              lVar1 = 8;
                                              if (uVar12 != 0xdadadada) {
                                                lVar1 = 0x14;
                                              }
                                              if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1))
                                              goto LAB_fffffff0081f57e8;
                                            }
                                            if (lVar5 != 0x15) {
                                              uVar12 = puVar4[0xac];
                                              uVar9 = uVar12;
                                              if (uVar12 == 0xdadadada) {
                                                uVar9 = puVar4[0xa9];
                                              }
                                              if (uVar9 <= uVar10) {
                                                puVar8 = puVar4 + 0xa8;
                                                lVar1 = 8;
                                                if (uVar12 != 0xdadadada) {
                                                  lVar1 = 0x14;
                                                }
                                                if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1))
                                                {
                                                  uVar11 = 0x15;
                                                  goto LAB_fffffff0081f57e8;
                                                }
                                              }
                                              if (lVar5 != 0x16) {
                                                uVar12 = puVar4[0xb4];
                                                uVar9 = uVar12;
                                                if (uVar12 == 0xdadadada) {
                                                  uVar9 = puVar4[0xb1];
                                                }
                                                if (uVar9 <= uVar10) {
                                                  puVar8 = puVar4 + 0xb0;
                                                  lVar1 = 8;
                                                  if (uVar12 != 0xdadadada) {
                                                    lVar1 = 0x14;
                                                  }
                                                  if (uVar10 < uVar9 + *(int *)((long)puVar8 + lVar1
                                                                               )) {
                                                    uVar11 = 0x16;
                                                    goto LAB_fffffff0081f57e8;
                                                  }
                                                }
                                                if (lVar5 != 0x17) {
                                                  uVar12 = puVar4[0xbc];
                                                  uVar9 = uVar12;
                                                  if (uVar12 == 0xdadadada) {
                                                    uVar9 = puVar4[0xb9];
                                                  }
                                                  if (uVar9 <= uVar10) {
                                                    puVar8 = puVar4 + 0xb8;
                                                    lVar1 = 8;
                                                    if (uVar12 != 0xdadadada) {
                                                      lVar1 = 0x14;
                                                    }
                                                    if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                 lVar1)) {
                                                      uVar11 = 0x17;
                                                      goto LAB_fffffff0081f57e8;
                                                    }
                                                  }
                                                  if (lVar5 != 0x18) {
                                                    uVar12 = puVar4[0xc4];
                                                    uVar9 = uVar12;
                                                    if (uVar12 == 0xdadadada) {
                                                      uVar9 = puVar4[0xc1];
                                                    }
                                                    if (uVar9 <= uVar10) {
                                                      puVar8 = puVar4 + 0xc0;
                                                      lVar1 = 8;
                                                      if (uVar12 != 0xdadadada) {
                                                        lVar1 = 0x14;
                                                      }
                                                      if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                   lVar1)) {
                                                        uVar11 = 0x18;
                                                        goto LAB_fffffff0081f57e8;
                                                      }
                                                    }
                                                    if (lVar5 != 0x19) {
                                                      uVar12 = puVar4[0xcc];
                                                      uVar9 = uVar12;
                                                      if (uVar12 == 0xdadadada) {
                                                        uVar9 = puVar4[0xc9];
                                                      }
                                                      if (uVar9 <= uVar10) {
                                                        puVar8 = puVar4 + 200;
                                                        lVar1 = 8;
                                                        if (uVar12 != 0xdadadada) {
                                                          lVar1 = 0x14;
                                                        }
                                                        if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                     lVar1)) {
                                                          uVar11 = 0x19;
                                                          goto LAB_fffffff0081f57e8;
                                                        }
                                                      }
                                                      if (lVar5 != 0x1a) {
                                                        uVar12 = puVar4[0xd4];
                                                        uVar9 = uVar12;
                                                        if (uVar12 == 0xdadadada) {
                                                          uVar9 = puVar4[0xd1];
                                                        }
                                                        if (uVar9 <= uVar10) {
                                                          puVar8 = puVar4 + 0xd0;
                                                          lVar1 = 8;
                                                          if (uVar12 != 0xdadadada) {
                                                            lVar1 = 0x14;
                                                          }
                                                          if (uVar10 < uVar9 + *(int *)((long)puVar8
                                                                                       + lVar1)) {
                                                            uVar11 = 0x1a;
                                                            goto LAB_fffffff0081f57e8;
                                                          }
                                                        }
                                                        if (lVar5 != 0x1b) {
                                                          uVar12 = puVar4[0xdc];
                                                          uVar9 = uVar12;
                                                          if (uVar12 == 0xdadadada) {
                                                            uVar9 = puVar4[0xd9];
                                                          }
                                                          if (uVar9 <= uVar10) {
                                                            puVar8 = puVar4 + 0xd8;
                                                            lVar1 = 8;
                                                            if (uVar12 != 0xdadadada) {
                                                              lVar1 = 0x14;
                                                            }
                                                            if (uVar10 < uVar9 + *(int *)((long)
                                                  puVar8 + lVar1)) {
                                                    uVar11 = 0x1b;
                                                    goto LAB_fffffff0081f57e8;
                                                  }
                                                  }
                                                  if (lVar5 != 0x1c) {
                                                    uVar12 = puVar4[0xe4];
                                                    uVar9 = uVar12;
                                                    if (uVar12 == 0xdadadada) {
                                                      uVar9 = puVar4[0xe1];
                                                    }
                                                    if (uVar9 <= uVar10) {
                                                      puVar8 = puVar4 + 0xe0;
                                                      lVar1 = 8;
                                                      if (uVar12 != 0xdadadada) {
                                                        lVar1 = 0x14;
                                                      }
                                                      if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                   lVar1)) {
                                                        uVar11 = 0x1c;
                                                        goto LAB_fffffff0081f57e8;
                                                      }
                                                    }
                                                    if (lVar5 != 0x1d) {
                                                      uVar12 = puVar4[0xec];
                                                      uVar9 = uVar12;
                                                      if (uVar12 == 0xdadadada) {
                                                        uVar9 = puVar4[0xe9];
                                                      }
                                                      if (uVar9 <= uVar10) {
                                                        puVar8 = puVar4 + 0xe8;
                                                        lVar1 = 8;
                                                        if (uVar12 != 0xdadadada) {
                                                          lVar1 = 0x14;
                                                        }
                                                        if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                     lVar1)) {
                                                          uVar11 = 0x1d;
                                                          goto LAB_fffffff0081f57e8;
                                                        }
                                                      }
                                                      if (lVar5 != 0x1e) {
                                                        uVar12 = puVar4[0xf4];
                                                        uVar9 = uVar12;
                                                        if (uVar12 == 0xdadadada) {
                                                          uVar9 = puVar4[0xf1];
                                                        }
                                                        if (uVar9 <= uVar10) {
                                                          puVar8 = puVar4 + 0xf0;
                                                          lVar1 = 8;
                                                          if (uVar12 != 0xdadadada) {
                                                            lVar1 = 0x14;
                                                          }
                                                          if (uVar10 < uVar9 + *(int *)((long)puVar8
                                                                                       + lVar1)) {
                                                            uVar11 = 0x1e;
                                                            goto LAB_fffffff0081f57e8;
                                                          }
                                                        }
                                                        if (lVar5 != 0x1f) {
                                                          uVar12 = puVar4[0xfc];
                                                          uVar9 = uVar12;
                                                          if (uVar12 == 0xdadadada) {
                                                            uVar9 = puVar4[0xf9];
                                                          }
                                                          if (uVar9 <= uVar10) {
                                                            puVar8 = puVar4 + 0xf8;
                                                            lVar1 = 8;
                                                            if (uVar12 != 0xdadadada) {
                                                              lVar1 = 0x14;
                                                            }
                                                            if (uVar10 < uVar9 + *(int *)((long)
                                                  puVar8 + lVar1)) {
                                                    uVar11 = 0x1f;
                                                    goto LAB_fffffff0081f57e8;
                                                  }
                                                  }
                                                  if (lVar5 != 0x20) {
                                                    uVar12 = puVar4[0x104];
                                                    uVar9 = uVar12;
                                                    if (uVar12 == 0xdadadada) {
                                                      uVar9 = puVar4[0x101];
                                                    }
                                                    if (uVar9 <= uVar10) {
                                                      puVar8 = puVar4 + 0x100;
                                                      lVar1 = 8;
                                                      if (uVar12 != 0xdadadada) {
                                                        lVar1 = 0x14;
                                                      }
                                                      if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                   lVar1)) {
                                                        uVar11 = 0x20;
                                                        goto LAB_fffffff0081f57e8;
                                                      }
                                                    }
                                                    if (lVar5 != 0x21) {
                                                      uVar12 = puVar4[0x10c];
                                                      uVar9 = uVar12;
                                                      if (uVar12 == 0xdadadada) {
                                                        uVar9 = puVar4[0x109];
                                                      }
                                                      if (uVar9 <= uVar10) {
                                                        puVar8 = puVar4 + 0x108;
                                                        lVar1 = 8;
                                                        if (uVar12 != 0xdadadada) {
                                                          lVar1 = 0x14;
                                                        }
                                                        if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                     lVar1)) {
                                                          uVar11 = 0x21;
                                                          goto LAB_fffffff0081f57e8;
                                                        }
                                                      }
                                                      if (lVar5 != 0x22) {
                                                        uVar12 = puVar4[0x114];
                                                        uVar9 = uVar12;
                                                        if (uVar12 == 0xdadadada) {
                                                          uVar9 = puVar4[0x111];
                                                        }
                                                        if (uVar9 <= uVar10) {
                                                          puVar8 = puVar4 + 0x110;
                                                          lVar1 = 8;
                                                          if (uVar12 != 0xdadadada) {
                                                            lVar1 = 0x14;
                                                          }
                                                          if (uVar10 < uVar9 + *(int *)((long)puVar8
                                                                                       + lVar1)) {
                                                            uVar11 = 0x22;
                                                            goto LAB_fffffff0081f57e8;
                                                          }
                                                        }
                                                        if (lVar5 != 0x23) {
                                                          uVar12 = puVar4[0x11c];
                                                          uVar9 = uVar12;
                                                          if (uVar12 == 0xdadadada) {
                                                            uVar9 = puVar4[0x119];
                                                          }
                                                          if (uVar9 <= uVar10) {
                                                            puVar8 = puVar4 + 0x118;
                                                            lVar1 = 8;
                                                            if (uVar12 != 0xdadadada) {
                                                              lVar1 = 0x14;
                                                            }
                                                            if (uVar10 < uVar9 + *(int *)((long)
                                                  puVar8 + lVar1)) {
                                                    uVar11 = 0x23;
                                                    goto LAB_fffffff0081f57e8;
                                                  }
                                                  }
                                                  if (lVar5 != 0x24) {
                                                    uVar12 = puVar4[0x124];
                                                    uVar9 = uVar12;
                                                    if (uVar12 == 0xdadadada) {
                                                      uVar9 = puVar4[0x121];
                                                    }
                                                    if (uVar9 <= uVar10) {
                                                      puVar8 = puVar4 + 0x120;
                                                      lVar1 = 8;
                                                      if (uVar12 != 0xdadadada) {
                                                        lVar1 = 0x14;
                                                      }
                                                      if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                   lVar1)) {
                                                        uVar11 = 0x24;
                                                        goto LAB_fffffff0081f57e8;
                                                      }
                                                    }
                                                    if (lVar5 != 0x25) {
                                                      uVar12 = puVar4[300];
                                                      uVar9 = uVar12;
                                                      if (uVar12 == 0xdadadada) {
                                                        uVar9 = puVar4[0x129];
                                                      }
                                                      if (uVar9 <= uVar10) {
                                                        puVar8 = puVar4 + 0x128;
                                                        lVar1 = 8;
                                                        if (uVar12 != 0xdadadada) {
                                                          lVar1 = 0x14;
                                                        }
                                                        if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                     lVar1)) {
                                                          uVar11 = 0x25;
                                                          goto LAB_fffffff0081f57e8;
                                                        }
                                                      }
                                                      if (lVar5 != 0x26) {
                                                        uVar12 = puVar4[0x134];
                                                        uVar9 = uVar12;
                                                        if (uVar12 == 0xdadadada) {
                                                          uVar9 = puVar4[0x131];
                                                        }
                                                        if (uVar9 <= uVar10) {
                                                          puVar8 = puVar4 + 0x130;
                                                          lVar1 = 8;
                                                          if (uVar12 != 0xdadadada) {
                                                            lVar1 = 0x14;
                                                          }
                                                          if (uVar10 < uVar9 + *(int *)((long)puVar8
                                                                                       + lVar1)) {
                                                            uVar11 = 0x26;
                                                            goto LAB_fffffff0081f57e8;
                                                          }
                                                        }
                                                        if (lVar5 != 0x27) {
                                                          uVar12 = puVar4[0x13c];
                                                          uVar9 = uVar12;
                                                          if (uVar12 == 0xdadadada) {
                                                            uVar9 = puVar4[0x139];
                                                          }
                                                          if (uVar9 <= uVar10) {
                                                            puVar8 = puVar4 + 0x138;
                                                            lVar1 = 8;
                                                            if (uVar12 != 0xdadadada) {
                                                              lVar1 = 0x14;
                                                            }
                                                            if (uVar10 < uVar9 + *(int *)((long)
                                                  puVar8 + lVar1)) {
                                                    uVar11 = 0x27;
                                                    goto LAB_fffffff0081f57e8;
                                                  }
                                                  }
                                                  if (lVar5 != 0x28) {
                                                    uVar12 = puVar4[0x144];
                                                    uVar9 = uVar12;
                                                    if (uVar12 == 0xdadadada) {
                                                      uVar9 = puVar4[0x141];
                                                    }
                                                    if (uVar9 <= uVar10) {
                                                      puVar8 = puVar4 + 0x140;
                                                      lVar1 = 8;
                                                      if (uVar12 != 0xdadadada) {
                                                        lVar1 = 0x14;
                                                      }
                                                      if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                   lVar1)) {
                                                        uVar11 = 0x28;
                                                        goto LAB_fffffff0081f57e8;
                                                      }
                                                    }
                                                    if (lVar5 != 0x29) {
                                                      uVar12 = puVar4[0x14c];
                                                      uVar9 = uVar12;
                                                      if (uVar12 == 0xdadadada) {
                                                        uVar9 = puVar4[0x149];
                                                      }
                                                      if (uVar9 <= uVar10) {
                                                        puVar8 = puVar4 + 0x148;
                                                        lVar1 = 8;
                                                        if (uVar12 != 0xdadadada) {
                                                          lVar1 = 0x14;
                                                        }
                                                        if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                     lVar1)) {
                                                          uVar11 = 0x29;
                                                          goto LAB_fffffff0081f57e8;
                                                        }
                                                      }
                                                      if (lVar5 != 0x2a) {
                                                        uVar12 = puVar4[0x154];
                                                        uVar9 = uVar12;
                                                        if (uVar12 == 0xdadadada) {
                                                          uVar9 = puVar4[0x151];
                                                        }
                                                        if (uVar9 <= uVar10) {
                                                          puVar8 = puVar4 + 0x150;
                                                          lVar1 = 8;
                                                          if (uVar12 != 0xdadadada) {
                                                            lVar1 = 0x14;
                                                          }
                                                          if (uVar10 < uVar9 + *(int *)((long)puVar8
                                                                                       + lVar1)) {
                                                            uVar11 = 0x2a;
                                                            goto LAB_fffffff0081f57e8;
                                                          }
                                                        }
                                                        if (lVar5 != 0x2b) {
                                                          uVar12 = puVar4[0x15c];
                                                          uVar9 = uVar12;
                                                          if (uVar12 == 0xdadadada) {
                                                            uVar9 = puVar4[0x159];
                                                          }
                                                          if (uVar9 <= uVar10) {
                                                            puVar8 = puVar4 + 0x158;
                                                            lVar1 = 8;
                                                            if (uVar12 != 0xdadadada) {
                                                              lVar1 = 0x14;
                                                            }
                                                            if (uVar10 < uVar9 + *(int *)((long)
                                                  puVar8 + lVar1)) {
                                                    uVar11 = 0x2b;
                                                    goto LAB_fffffff0081f57e8;
                                                  }
                                                  }
                                                  if (lVar5 != 0x2c) {
                                                    uVar12 = puVar4[0x164];
                                                    uVar9 = uVar12;
                                                    if (uVar12 == 0xdadadada) {
                                                      uVar9 = puVar4[0x161];
                                                    }
                                                    if (uVar9 <= uVar10) {
                                                      puVar8 = puVar4 + 0x160;
                                                      lVar1 = 8;
                                                      if (uVar12 != 0xdadadada) {
                                                        lVar1 = 0x14;
                                                      }
                                                      if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                   lVar1)) {
                                                        uVar11 = 0x2c;
                                                        goto LAB_fffffff0081f57e8;
                                                      }
                                                    }
                                                    if (lVar5 != 0x2d) {
                                                      uVar12 = puVar4[0x16c];
                                                      uVar9 = uVar12;
                                                      if (uVar12 == 0xdadadada) {
                                                        uVar9 = puVar4[0x169];
                                                      }
                                                      if (uVar9 <= uVar10) {
                                                        puVar8 = puVar4 + 0x168;
                                                        lVar1 = 8;
                                                        if (uVar12 != 0xdadadada) {
                                                          lVar1 = 0x14;
                                                        }
                                                        if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                     lVar1)) {
                                                          uVar11 = 0x2d;
                                                          goto LAB_fffffff0081f57e8;
                                                        }
                                                      }
                                                      if (lVar5 != 0x2e) {
                                                        uVar12 = puVar4[0x174];
                                                        uVar9 = uVar12;
                                                        if (uVar12 == 0xdadadada) {
                                                          uVar9 = puVar4[0x171];
                                                        }
                                                        if (uVar9 <= uVar10) {
                                                          puVar8 = puVar4 + 0x170;
                                                          lVar1 = 8;
                                                          if (uVar12 != 0xdadadada) {
                                                            lVar1 = 0x14;
                                                          }
                                                          if (uVar10 < uVar9 + *(int *)((long)puVar8
                                                                                       + lVar1)) {
                                                            uVar11 = 0x2e;
                                                            goto LAB_fffffff0081f57e8;
                                                          }
                                                        }
                                                        if (lVar5 != 0x2f) {
                                                          uVar12 = puVar4[0x17c];
                                                          uVar9 = uVar12;
                                                          if (uVar12 == 0xdadadada) {
                                                            uVar9 = puVar4[0x179];
                                                          }
                                                          if (uVar9 <= uVar10) {
                                                            puVar8 = puVar4 + 0x178;
                                                            lVar1 = 8;
                                                            if (uVar12 != 0xdadadada) {
                                                              lVar1 = 0x14;
                                                            }
                                                            if (uVar10 < uVar9 + *(int *)((long)
                                                  puVar8 + lVar1)) {
                                                    uVar11 = 0x2f;
                                                    goto LAB_fffffff0081f57e8;
                                                  }
                                                  }
                                                  if (lVar5 != 0x30) {
                                                    uVar12 = puVar4[0x184];
                                                    uVar9 = uVar12;
                                                    if (uVar12 == 0xdadadada) {
                                                      uVar9 = puVar4[0x181];
                                                    }
                                                    if (uVar9 <= uVar10) {
                                                      puVar8 = puVar4 + 0x180;
                                                      lVar1 = 8;
                                                      if (uVar12 != 0xdadadada) {
                                                        lVar1 = 0x14;
                                                      }
                                                      if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                   lVar1)) {
                                                        uVar11 = 0x30;
                                                        goto LAB_fffffff0081f57e8;
                                                      }
                                                    }
                                                    if (lVar5 != 0x31) {
                                                      uVar12 = puVar4[0x18c];
                                                      uVar9 = uVar12;
                                                      if (uVar12 == 0xdadadada) {
                                                        uVar9 = puVar4[0x189];
                                                      }
                                                      if (uVar9 <= uVar10) {
                                                        puVar8 = puVar4 + 0x188;
                                                        lVar1 = 8;
                                                        if (uVar12 != 0xdadadada) {
                                                          lVar1 = 0x14;
                                                        }
                                                        if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                     lVar1)) {
                                                          uVar11 = 0x31;
                                                          goto LAB_fffffff0081f57e8;
                                                        }
                                                      }
                                                      if (lVar5 != 0x32) {
                                                        uVar12 = puVar4[0x194];
                                                        uVar9 = uVar12;
                                                        if (uVar12 == 0xdadadada) {
                                                          uVar9 = puVar4[0x191];
                                                        }
                                                        if (uVar9 <= uVar10) {
                                                          puVar8 = puVar4 + 400;
                                                          lVar1 = 8;
                                                          if (uVar12 != 0xdadadada) {
                                                            lVar1 = 0x14;
                                                          }
                                                          if (uVar10 < uVar9 + *(int *)((long)puVar8
                                                                                       + lVar1)) {
                                                            uVar11 = 0x32;
                                                            goto LAB_fffffff0081f57e8;
                                                          }
                                                        }
                                                        if (lVar5 != 0x33) {
                                                          uVar12 = puVar4[0x19c];
                                                          uVar9 = uVar12;
                                                          if (uVar12 == 0xdadadada) {
                                                            uVar9 = puVar4[0x199];
                                                          }
                                                          if (uVar9 <= uVar10) {
                                                            puVar8 = puVar4 + 0x198;
                                                            lVar1 = 8;
                                                            if (uVar12 != 0xdadadada) {
                                                              lVar1 = 0x14;
                                                            }
                                                            if (uVar10 < uVar9 + *(int *)((long)
                                                  puVar8 + lVar1)) {
                                                    uVar11 = 0x33;
                                                    goto LAB_fffffff0081f57e8;
                                                  }
                                                  }
                                                  if (lVar5 != 0x34) {
                                                    uVar12 = puVar4[0x1a4];
                                                    uVar9 = uVar12;
                                                    if (uVar12 == 0xdadadada) {
                                                      uVar9 = puVar4[0x1a1];
                                                    }
                                                    if (uVar9 <= uVar10) {
                                                      puVar8 = puVar4 + 0x1a0;
                                                      lVar1 = 8;
                                                      if (uVar12 != 0xdadadada) {
                                                        lVar1 = 0x14;
                                                      }
                                                      if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                   lVar1)) {
                                                        uVar11 = 0x34;
                                                        goto LAB_fffffff0081f57e8;
                                                      }
                                                    }
                                                    if (lVar5 != 0x35) {
                                                      uVar12 = puVar4[0x1ac];
                                                      uVar9 = uVar12;
                                                      if (uVar12 == 0xdadadada) {
                                                        uVar9 = puVar4[0x1a9];
                                                      }
                                                      if (uVar9 <= uVar10) {
                                                        puVar8 = puVar4 + 0x1a8;
                                                        lVar1 = 8;
                                                        if (uVar12 != 0xdadadada) {
                                                          lVar1 = 0x14;
                                                        }
                                                        if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                     lVar1)) {
                                                          uVar11 = 0x35;
                                                          goto LAB_fffffff0081f57e8;
                                                        }
                                                      }
                                                      if (lVar5 != 0x36) {
                                                        uVar12 = puVar4[0x1b4];
                                                        uVar9 = uVar12;
                                                        if (uVar12 == 0xdadadada) {
                                                          uVar9 = puVar4[0x1b1];
                                                        }
                                                        if (uVar9 <= uVar10) {
                                                          puVar8 = puVar4 + 0x1b0;
                                                          lVar1 = 8;
                                                          if (uVar12 != 0xdadadada) {
                                                            lVar1 = 0x14;
                                                          }
                                                          if (uVar10 < uVar9 + *(int *)((long)puVar8
                                                                                       + lVar1)) {
                                                            uVar11 = 0x36;
                                                            goto LAB_fffffff0081f57e8;
                                                          }
                                                        }
                                                        if (lVar5 != 0x37) {
                                                          uVar12 = puVar4[0x1bc];
                                                          uVar9 = uVar12;
                                                          if (uVar12 == 0xdadadada) {
                                                            uVar9 = puVar4[0x1b9];
                                                          }
                                                          if (uVar9 <= uVar10) {
                                                            puVar8 = puVar4 + 0x1b8;
                                                            lVar1 = 8;
                                                            if (uVar12 != 0xdadadada) {
                                                              lVar1 = 0x14;
                                                            }
                                                            if (uVar10 < uVar9 + *(int *)((long)
                                                  puVar8 + lVar1)) {
                                                    uVar11 = 0x37;
                                                    goto LAB_fffffff0081f57e8;
                                                  }
                                                  }
                                                  if (lVar5 != 0x38) {
                                                    uVar12 = puVar4[0x1c4];
                                                    uVar9 = uVar12;
                                                    if (uVar12 == 0xdadadada) {
                                                      uVar9 = puVar4[0x1c1];
                                                    }
                                                    if (uVar9 <= uVar10) {
                                                      puVar8 = puVar4 + 0x1c0;
                                                      lVar1 = 8;
                                                      if (uVar12 != 0xdadadada) {
                                                        lVar1 = 0x14;
                                                      }
                                                      if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                   lVar1)) {
                                                        uVar11 = 0x38;
                                                        goto LAB_fffffff0081f57e8;
                                                      }
                                                    }
                                                    if (lVar5 != 0x39) {
                                                      uVar12 = puVar4[0x1cc];
                                                      uVar9 = uVar12;
                                                      if (uVar12 == 0xdadadada) {
                                                        uVar9 = puVar4[0x1c9];
                                                      }
                                                      if (uVar9 <= uVar10) {
                                                        puVar8 = puVar4 + 0x1c8;
                                                        lVar1 = 8;
                                                        if (uVar12 != 0xdadadada) {
                                                          lVar1 = 0x14;
                                                        }
                                                        if (uVar10 < uVar9 + *(int *)((long)puVar8 +
                                                                                     lVar1)) {
                                                          uVar11 = 0x39;
                                                          goto LAB_fffffff0081f57e8;
                                                        }
                                                      }
                                                      if (lVar5 != 0x3a) {
                                                        uVar12 = puVar4[0x1d4];
                                                        uVar9 = uVar12;
                                                        if (uVar12 == 0xdadadada) {
                                                          uVar9 = puVar4[0x1d1];
                                                        }
                                                        if (uVar9 <= uVar10) {
                                                          puVar8 = puVar4 + 0x1d0;
                                                          lVar1 = 8;
                                                          if (uVar12 != 0xdadadada) {
                                                            lVar1 = 0x14;
                                                          }
                                                          if (uVar10 < uVar9 + *(int *)((long)puVar8
                                                                                       + lVar1)) {
                                                            uVar11 = 0x3a;
                                                            goto LAB_fffffff0081f57e8;
                                                          }
                                                        }
                                                        if (lVar5 != 0x3b) {
                                                          uVar12 = puVar4[0x1dc];
                                                          uVar9 = uVar12;
                                                          if (uVar12 == 0xdadadada) {
                                                            uVar9 = puVar4[0x1d9];
                                                          }
                                                          if (uVar9 <= uVar10) {
                                                            puVar8 = puVar4 + 0x1d8;
                                                            lVar5 = 8;
                                                            if (uVar12 != 0xdadadada) {
                                                              lVar5 = 0x14;
                                                            }
                                                            if (uVar10 < uVar9 + *(int *)((long)
                                                  puVar8 + lVar5)) {
                                                    uVar11 = 0x3b;
                                                    goto LAB_fffffff0081f57e8;
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
              }
            }
          }
        }
      }
    }
  }
  uVar11 = 0;
  uVar12 = 0x3d;
LAB_fffffff0081f5810:
  lVar5 = (**(code **)(*param_1 + 0xcd0))(param_1);
  (**(code **)(*param_1 + 0xcd8))(param_1);
  uVar7 = -(uVar11 >> 0x1f) & 0xffffffe000000000 | uVar11 << 5;
  iVar6 = (int)(uVar11 << 5);
  uVar3 = lVar5 + iVar6;
  if (uVar7 != (long)iVar6) {
    uVar3 = lVar5 + uVar7 & 0xffffffffffff | 0x2bad000000000000;
  }
  uVar10 = *(uint *)(uVar3 + 0x10);
  if (uVar10 == 0xdadadada) {
    uVar10 = *(uint *)(uVar3 + 4);
  }
  *(undefined4 *)((param_2 - (ulong)uVar10) + param_1[(ulong)uVar12 + 0x227a]) = param_3;
  return;
}

