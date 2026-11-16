// FUN_fffffff00995c524 @ fffffff00995c524 size=448

/* WARNING: Removing unreachable block (ram,0xfffffff00995c688) */
/* WARNING: Removing unreachable block (ram,0xfffffff00995c608) */

void FUN_fffffff00995c524(long param_1)

{
  long *plVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  code *pcVar5;
  byte bVar6;
  long lVar7;
  char local_60 [8];
  char acStack_58 [8];
  char acStack_50 [8];
  char acStack_48 [5];
  char local_43 [3];
  char acStack_40 [5];
  char acStack_3b [19];
  long local_28;
  
  lVar4 = 0;
  local_28 = *(long *)PTR_DAT_fffffff007ff2800;
  acStack_58 = (char  [8])s_4_>_2AA_6_AC_G2E6_x__FC7246_AC_E_fffffff00782d5e5._8_8_;
  local_60 = (char  [8])s_4_>_2AA_6_AC_G2E6_x__FC7246_AC_E_fffffff00782d5e5._0_8_;
  acStack_48 = (char  [5])s_4_>_2AA_6_AC_G2E6_x__FC7246_AC_E_fffffff00782d5e5._24_5_;
  acStack_50 = (char  [8])s_4_>_2AA_6_AC_G2E6_x__FC7246_AC_E_fffffff00782d5e5._16_8_;
  acStack_3b._0_8_ = s_4_>_2AA_6_AC_G2E6_x__FC7246_AC_E_fffffff00782d5e5._37_8_;
  local_43 = (char  [3])s_4_>_2AA_6_AC_G2E6_x__FC7246_AC_E_fffffff00782d5e5._29_3_;
  acStack_40 = (char  [5])s_4_>_2AA_6_AC_G2E6_x__FC7246_AC_E_fffffff00782d5e5._32_5_;
  lVar7 = 0x2c;
  do {
    iVar3 = local_60[lVar4] + 0xe;
    uVar2 = iVar3 + ((uint)(iVar3 * -0x51b3) >> 0x10);
    local_60[lVar4] =
         (char)iVar3 + ((char)(uVar2 >> 6) + (char)((uVar2 & 0x8000) >> 0xf)) * -0x5e + '!';
    lVar4 = lVar4 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  lVar4 = (long)DAT_fffffff00af21d48 >> 1;
  plVar1 = (long *)(param_1 + (int)lVar4);
  if (lVar4 != (int)lVar4) {
    plVar1 = (long *)(param_1 + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
  }
  pcVar5 = DAT_fffffff00af21d40;
  if ((DAT_fffffff00af21d48 & 1) != 0) {
    pcVar5 = *(code **)(*plVar1 + ((ulong)DAT_fffffff00af21d40 & 0xffffffff));
  }
  uVar2 = (*pcVar5)(plVar1,local_60);
  bVar6 = 2;
  if (uVar2 == 0) {
    bVar6 = 0;
  }
  *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) & 0xfd | bVar6;
  if ((uVar2 & 1) == 0) {
    lVar4 = (long)DAT_fffffff00af21d48 >> 1;
    plVar1 = (long *)(param_1 + (int)lVar4);
    if (lVar4 != (int)lVar4) {
      plVar1 = (long *)(param_1 + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
    }
    pcVar5 = DAT_fffffff00af21d40;
    if ((DAT_fffffff00af21d48 & 1) != 0) {
      pcVar5 = *(code **)(*plVar1 + ((ulong)DAT_fffffff00af21d40 & 0xffffffff));
    }
    iVar3 = (*pcVar5)(plVar1,"com.apple.private.ggdsw.GPUProcessProtectedContent");
    bVar6 = 2;
    if (iVar3 == 0) {
      bVar6 = 0;
    }
    *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) & 0xfd | bVar6;
  }
  if (*(long *)PTR_DAT_fffffff007ff2800 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

