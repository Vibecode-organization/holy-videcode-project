// FUN_fffffff00a497e90 @ fffffff00a497e90 size=752

byte * FUN_fffffff00a497e90
                 (uint param_1,int param_2,long param_3,byte *param_4,byte *param_5,uint param_6,
                 long param_7)

{
  byte *pbVar1;
  byte *pbVar2;
  long lVar3;
  int iVar4;
  char cVar5;
  ulong uVar6;
  code *pcVar7;
  bool bVar8;
  byte *pbVar9;
  byte bVar10;
  ulong local_58;
  
  if ((param_5 == (byte *)0x0) || (param_6 < 0x80)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa5d948
              ("buf != NULL && buflen >= sizeof(*ss)",
               "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/net/route.c"
               ,0x30f);
  }
  FUN_fffffff00aa65cc0(param_5,param_6);
  if (param_2 < 2) {
    if (param_2 == 0) {
      if (param_4[1] == 0x1e) {
        iVar4 = *(int *)(param_4 + 0x18);
      }
      else {
        if (param_4[1] != 2) {
          return param_4;
        }
        iVar4 = *(int *)(param_4 + 8);
      }
      if (iVar4 == 0) {
        return param_4;
      }
      FUN_fffffff00a497af0(param_4,param_5,0);
      return param_5;
    }
    if (param_2 != 1) {
      return param_4;
    }
    if (param_4[1] != 0x12) {
      return param_4;
    }
    if (param_4[6] == 0) {
      return param_4;
    }
    bVar8 = true;
  }
  else {
    if (param_2 == 2) {
      if (param_3 == 0) {
        return param_4;
      }
      cVar5 = *(char *)(param_3 + 1);
      if ((cVar5 != '\x1e') && (cVar5 != '\x02')) {
        return param_4;
      }
      bVar10 = 4;
      if (cVar5 != '\x02') {
        bVar10 = 8;
      }
      if (*param_4 <= bVar10) {
        return param_4;
      }
      if (0x80 < *param_4) {
        return param_4;
      }
      if ((param_4 <= param_4 + 0xff) && (param_5 <= param_5 + 0x80)) {
        FUN_fffffff00aa65b10(param_5,param_4);
        lVar3 = 8;
        if (*(char *)(param_3 + 1) != '\x02') {
          lVar3 = 0x18;
        }
        pbVar1 = param_5 + lVar3;
        pbVar1[0] = 0;
        pbVar1[1] = 0;
        pbVar1[2] = 0;
        pbVar1[3] = 0;
        FUN_fffffff00a498180(param_5,bVar10);
        if ((param_1 & 0xffffffef) == 4) {
          return param_5;
        }
        if (*(char *)(param_3 + 1) != '\x1e') {
          return param_5;
        }
        *param_5 = 0x1c;
        return param_5;
      }
      goto LAB_fffffff00a4980a0;
    }
    if (param_2 != 4) {
      return param_4;
    }
    bVar8 = param_4[1] == 0x12;
  }
  if (param_7 == 0) {
    return param_4;
  }
  if (!bVar8) {
    return param_4;
  }
  local_58 = 0;
  if (param_6 < *param_4) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa5d948
              ("buflen >= sa->sa_len",
               "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/net/route.c"
               ,0x367);
  }
  if ((param_4 <= param_4 + 0xff) && (pbVar1 = param_5 + 0xff, param_5 <= pbVar1)) {
    FUN_fffffff00aa65b10(param_5,param_4);
    pbVar9 = (byte *)FUN_fffffff00a475d30(param_5,&local_58,param_7);
    uVar6 = local_58;
    if (param_5 < param_5 + 0x14) {
      pbVar2 = param_5 + (ulong)param_5[5] + 8;
      if (pbVar2 != pbVar9) {
        if (param_5[6] < local_58) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa5d948
                    ("size <= sdl->sdl_alen",
                     "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/net/route.c"
                     ,0x374);
        }
        if ((((pbVar1 < pbVar2) || (pbVar2 < param_5)) || (0xf7 - (ulong)param_5[5] < local_58)) ||
           (pbVar9 + local_58 < pbVar9)) goto LAB_fffffff00a4980a0;
        FUN_fffffff00aa65b10(pbVar2,pbVar9,local_58);
        if (uVar6 < param_5[6]) {
          if (((pbVar1 < param_5 + uVar6 + (ulong)param_5[5] + 8) ||
              (param_5 + uVar6 + (ulong)param_5[5] + 8 < param_5)) ||
             (0xf7 - (uVar6 + param_5[5]) < param_5[6] - uVar6)) goto LAB_fffffff00a4980a0;
          FUN_fffffff00aa65cc0();
        }
      }
      return param_5;
    }
  }
LAB_fffffff00a4980a0:
                    /* WARNING: Does not return */
  pcVar7 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a4980a4);
  (*pcVar7)();
}

