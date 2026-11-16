// FUN_fffffff00817b9d8 @ fffffff00817b9d8 size=4

void FUN_fffffff00817b9d8(long param_1)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  ulong uVar10;
  undefined8 uStack_88;
  long lStack_80;
  long lStack_78;
  long lStack_70;
  long lStack_68;
  long lStack_60;
  long alStack_58 [2];
  long lStack_48;
  
  lStack_48 = *(long *)PTR_DAT_fffffff007ca61a0;
  lStack_68 = 0;
  lStack_70 = 0;
  alStack_58[0] = 0;
  lStack_60 = 0;
  lStack_78 = 0;
  lStack_80 = 0;
  uStack_88 = 8;
  iVar3 = thunk_EXT_FUN_8011000003742368
                    ("kern.sptm.event_counters.RETYPES",&lStack_80,&uStack_88,0,0);
  iVar4 = thunk_EXT_FUN_8011000003742368
                    ("kern.sptm.event_counters.SWWA_TLBI_ASID",(ulong)&lStack_80 | 8,&uStack_88,0,0)
  ;
  iVar5 = thunk_EXT_FUN_8011000003742368
                    ("kern.sptm.event_counters.SWWA_TLBI_ALL",&lStack_70,&uStack_88,0,0);
  iVar6 = thunk_EXT_FUN_8011000003742368
                    ("kern.sptm.event_counters.UAT_UNMAP_PROCESSED",&lStack_68,&uStack_88,0,0);
  iVar7 = thunk_EXT_FUN_8011000003742368
                    ("kern.sptm.event_counters.UAT_UNMAP_MARKED",&lStack_60,&uStack_88,0,0);
  iVar8 = thunk_EXT_FUN_8011000003742368
                    ("kern.sptm.event_counters.UAT_UNMAP_UNMARKED",alStack_58,&uStack_88,0,0);
  if (((iVar4 == 0 && iVar3 == 0) && (iVar5 == 0 && iVar6 == 0)) && (iVar7 == 0 && iVar8 == 0)) {
    uVar10 = lStack_80 - *(long *)(param_1 + 0x17fd0);
    if (uVar10 < 1000000) {
      if (uVar10 < 500000) {
        if (uVar10 < 100000) {
          if (uVar10 >> 4 < 0x271) {
            if (uVar10 < 1000) {
              if (uVar10 < 100) {
                if (uVar10 < 10) {
                  if (lStack_80 == *(long *)(param_1 + 0x17fd0)) {
                    *(long *)(param_1 + 0x18000) = *(long *)(param_1 + 0x18000) + 1;
                  }
                  else {
                    *(long *)(param_1 + 0x18008) = *(long *)(param_1 + 0x18008) + 1;
                  }
                }
                else {
                  *(long *)(param_1 + 0x18010) = *(long *)(param_1 + 0x18010) + 1;
                }
              }
              else {
                *(long *)(param_1 + 0x18018) = *(long *)(param_1 + 0x18018) + 1;
              }
            }
            else {
              *(long *)(param_1 + 0x18020) = *(long *)(param_1 + 0x18020) + 1;
            }
          }
          else {
            *(long *)(param_1 + 0x18028) = *(long *)(param_1 + 0x18028) + 1;
          }
        }
        else {
          *(long *)(param_1 + 0x18030) = *(long *)(param_1 + 0x18030) + 1;
        }
      }
      else {
        *(long *)(param_1 + 0x18038) = *(long *)(param_1 + 0x18038) + 1;
      }
    }
    else {
      *(long *)(param_1 + 0x18040) = *(long *)(param_1 + 0x18040) + 1;
    }
    *(long *)(param_1 + 0x17fd0) = lStack_80;
    uVar10 = lStack_78 - *(long *)(param_1 + 0x17fd8);
    if (uVar10 < 1000000) {
      if (uVar10 < 500000) {
        if (uVar10 < 100000) {
          if (uVar10 >> 4 < 0x271) {
            if (uVar10 < 1000) {
              if (uVar10 < 100) {
                if (uVar10 < 10) {
                  lVar9 = 0x18048;
                  if (lStack_78 != *(long *)(param_1 + 0x17fd8)) {
                    lVar9 = 0x18050;
                  }
                }
                else {
                  lVar9 = 0x18058;
                }
              }
              else {
                lVar9 = 0x18060;
              }
            }
            else {
              lVar9 = 0x18068;
            }
          }
          else {
            lVar9 = 0x18070;
          }
        }
        else {
          lVar9 = 0x18078;
        }
      }
      else {
        lVar9 = 0x18080;
      }
    }
    else {
      lVar9 = 0x18088;
    }
    *(long *)(param_1 + lVar9) = *(long *)(param_1 + lVar9) + 1;
    *(long *)(param_1 + 0x17fd8) = lStack_78;
    uVar10 = lStack_70 - *(long *)(param_1 + 0x17fe0);
    lVar9 = 0x18090;
    if (lStack_70 != *(long *)(param_1 + 0x17fe0)) {
      lVar9 = 0x18098;
    }
    lVar1 = 0x180a0;
    if (uVar10 < 10) {
      lVar1 = lVar9;
    }
    lVar9 = 0x180a8;
    if (uVar10 < 100) {
      lVar9 = lVar1;
    }
    lVar1 = 0x180b0;
    if (uVar10 < 1000) {
      lVar1 = lVar9;
    }
    lVar9 = 0x180b8;
    if (uVar10 >> 4 < 0x271) {
      lVar9 = lVar1;
    }
    lVar1 = 0x180c0;
    if (uVar10 < 100000) {
      lVar1 = lVar9;
    }
    lVar9 = 0x180c8;
    if (uVar10 < 500000) {
      lVar9 = lVar1;
    }
    lVar1 = 0x180d0;
    if (uVar10 < 1000000) {
      lVar1 = lVar9;
    }
    *(long *)(param_1 + lVar1) = *(long *)(param_1 + lVar1) + 1;
    *(long *)(param_1 + 0x17fe0) = lStack_70;
    uVar10 = lStack_68 - *(long *)(param_1 + 0x17fe8);
    lVar9 = 0x180d8;
    if (lStack_68 != *(long *)(param_1 + 0x17fe8)) {
      lVar9 = 0x180e0;
    }
    lVar1 = 0x180e8;
    if (uVar10 < 10) {
      lVar1 = lVar9;
    }
    lVar9 = 0x180f0;
    if (uVar10 < 100) {
      lVar9 = lVar1;
    }
    lVar1 = 0x180f8;
    if (uVar10 < 1000) {
      lVar1 = lVar9;
    }
    lVar9 = 0x18100;
    if (uVar10 >> 4 < 0x271) {
      lVar9 = lVar1;
    }
    lVar1 = 0x18108;
    if (uVar10 < 100000) {
      lVar1 = lVar9;
    }
    lVar9 = 0x18110;
    if (uVar10 < 500000) {
      lVar9 = lVar1;
    }
    lVar1 = 0x18118;
    if (uVar10 < 1000000) {
      lVar1 = lVar9;
    }
    *(long *)(param_1 + lVar1) = *(long *)(param_1 + lVar1) + 1;
    *(long *)(param_1 + 0x17fe8) = lStack_68;
    uVar10 = lStack_60 - *(long *)(param_1 + 0x17ff0);
    lVar9 = 0x18120;
    if (lStack_60 != *(long *)(param_1 + 0x17ff0)) {
      lVar9 = 0x18128;
    }
    lVar1 = 0x18130;
    if (uVar10 < 10) {
      lVar1 = lVar9;
    }
    lVar9 = 0x18138;
    if (uVar10 < 100) {
      lVar9 = lVar1;
    }
    lVar1 = 0x18140;
    if (uVar10 < 1000) {
      lVar1 = lVar9;
    }
    lVar9 = 0x18148;
    if (uVar10 >> 4 < 0x271) {
      lVar9 = lVar1;
    }
    lVar1 = 0x18150;
    if (uVar10 < 100000) {
      lVar1 = lVar9;
    }
    lVar9 = 0x18158;
    if (uVar10 < 500000) {
      lVar9 = lVar1;
    }
    lVar1 = 0x18160;
    if (uVar10 < 1000000) {
      lVar1 = lVar9;
    }
    *(long *)(param_1 + lVar1) = *(long *)(param_1 + lVar1) + 1;
    *(long *)(param_1 + 0x17ff0) = lStack_60;
    uVar10 = alStack_58[0] - *(long *)(param_1 + 0x17ff8);
    lVar9 = 0x18168;
    if (alStack_58[0] != *(long *)(param_1 + 0x17ff8)) {
      lVar9 = 0x18170;
    }
    lVar1 = 0x18178;
    if (uVar10 < 10) {
      lVar1 = lVar9;
    }
    lVar9 = 0x18180;
    if (uVar10 < 100) {
      lVar9 = lVar1;
    }
    lVar1 = 0x18188;
    if (uVar10 < 1000) {
      lVar1 = lVar9;
    }
    lVar9 = 0x18190;
    if (uVar10 >> 4 < 0x271) {
      lVar9 = lVar1;
    }
    lVar1 = 0x18198;
    if (uVar10 < 100000) {
      lVar1 = lVar9;
    }
    lVar9 = 0x181a0;
    if (uVar10 < 500000) {
      lVar9 = lVar1;
    }
    lVar1 = 0x181a8;
    if (uVar10 < 1000000) {
      lVar1 = lVar9;
    }
    *(long *)(param_1 + lVar1) = *(long *)(param_1 + lVar1) + 1;
    *(long *)(param_1 + 0x17ff8) = alStack_58[0];
  }
  uVar10 = *(long *)(param_1 + 0x181b0) + 1;
  *(ulong *)(param_1 + 0x181b0) = uVar10;
  uVar2 = 0;
  if (*(ulong *)(param_1 + 0x17fc8) != 0) {
    uVar2 = 86400000 / *(ulong *)(param_1 + 0x17fc8);
  }
  if (uVar2 <= uVar10) {
    *(undefined8 *)(param_1 + 0x181b0) = 0;
    *(undefined8 *)(param_1 + 0x18198) = 0;
    *(undefined8 *)(param_1 + 0x18190) = 0;
    *(undefined8 *)(param_1 + 0x181a8) = 0;
    *(undefined8 *)(param_1 + 0x181a0) = 0;
    *(undefined8 *)(param_1 + 0x18178) = 0;
    *(undefined8 *)(param_1 + 0x18170) = 0;
    *(undefined8 *)(param_1 + 0x18188) = 0;
    *(undefined8 *)(param_1 + 0x18180) = 0;
    *(undefined8 *)(param_1 + 0x18158) = 0;
    *(undefined8 *)(param_1 + 0x18150) = 0;
    *(undefined8 *)(param_1 + 0x18168) = 0;
    *(undefined8 *)(param_1 + 0x18160) = 0;
    *(undefined8 *)(param_1 + 0x18138) = 0;
    *(undefined8 *)(param_1 + 0x18130) = 0;
    *(undefined8 *)(param_1 + 0x18148) = 0;
    *(undefined8 *)(param_1 + 0x18140) = 0;
    *(undefined8 *)(param_1 + 0x18118) = 0;
    *(undefined8 *)(param_1 + 0x18110) = 0;
    *(undefined8 *)(param_1 + 0x18128) = 0;
    *(undefined8 *)(param_1 + 0x18120) = 0;
    *(undefined8 *)(param_1 + 0x180f8) = 0;
    *(undefined8 *)(param_1 + 0x180f0) = 0;
    *(undefined8 *)(param_1 + 0x18108) = 0;
    *(undefined8 *)(param_1 + 0x18100) = 0;
    *(undefined8 *)(param_1 + 0x180d8) = 0;
    *(undefined8 *)(param_1 + 0x180d0) = 0;
    *(undefined8 *)(param_1 + 0x180e8) = 0;
    *(undefined8 *)(param_1 + 0x180e0) = 0;
    *(undefined8 *)(param_1 + 0x180b8) = 0;
    *(undefined8 *)(param_1 + 0x180b0) = 0;
    *(undefined8 *)(param_1 + 0x180c8) = 0;
    *(undefined8 *)(param_1 + 0x180c0) = 0;
    *(undefined8 *)(param_1 + 0x18098) = 0;
    *(undefined8 *)(param_1 + 0x18090) = 0;
    *(undefined8 *)(param_1 + 0x180a8) = 0;
    *(undefined8 *)(param_1 + 0x180a0) = 0;
    *(undefined8 *)(param_1 + 0x18078) = 0;
    *(undefined8 *)(param_1 + 0x18070) = 0;
    *(undefined8 *)(param_1 + 0x18088) = 0;
    *(undefined8 *)(param_1 + 0x18080) = 0;
    *(undefined8 *)(param_1 + 0x18058) = 0;
    *(undefined8 *)(param_1 + 0x18050) = 0;
    *(undefined8 *)(param_1 + 0x18068) = 0;
    *(undefined8 *)(param_1 + 0x18060) = 0;
    *(undefined8 *)(param_1 + 0x18038) = 0;
    *(undefined8 *)(param_1 + 0x18030) = 0;
    *(undefined8 *)(param_1 + 0x18048) = 0;
    *(undefined8 *)(param_1 + 0x18040) = 0;
    *(undefined8 *)(param_1 + 0x18018) = 0;
    *(undefined8 *)(param_1 + 0x18010) = 0;
    *(undefined8 *)(param_1 + 0x18028) = 0;
    *(undefined8 *)(param_1 + 0x18020) = 0;
    *(undefined8 *)(param_1 + 0x18008) = 0;
    *(undefined8 *)(param_1 + 0x18000) = 0;
  }
  (**(code **)(**(long **)(param_1 + 0x17fc0) + 0xf0))();
  if (*(long *)PTR_DAT_fffffff007ca61a0 != lStack_48) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

