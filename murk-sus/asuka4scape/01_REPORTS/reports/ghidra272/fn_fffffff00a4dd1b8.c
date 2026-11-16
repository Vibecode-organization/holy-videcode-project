// FUN_fffffff00a4dd1b8 @ fffffff00a4dd1b8 size=1160

uint FUN_fffffff00a4dd1b8(ulong *param_1)

{
  char cVar1;
  bool bVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  ulong uVar6;
  ulong *puVar7;
  long lVar8;
  uint uVar9;
  uint uVar10;
  undefined8 *puVar11;
  ulong *puVar12;
  ulong uVar13;
  ulong uVar14;
  
  if (DAT_fffffff00adcdcd0 != (ulong *)0x0) {
    puVar7 = param_1 + 4;
    puVar12 = DAT_fffffff00adcdcd0;
    do {
      if ((((((((((char)*param_1 != '\0') && (*(char *)((long)param_1 + 1) != '\0')) &&
               (*(char *)((long)param_1 + 2) != '\0')) &&
              ((*(char *)((long)param_1 + 3) != '\0' && (*(char *)((long)param_1 + 4) != '\0')))) &&
             ((*(char *)((long)param_1 + 5) != '\0' &&
              ((*(char *)((long)param_1 + 6) != '\0' && (*(char *)((long)param_1 + 7) != '\0'))))))
            && (((char)param_1[1] != '\0' &&
                ((((*(char *)((long)param_1 + 9) != '\0' && (*(char *)((long)param_1 + 10) != '\0'))
                  && (*(char *)((long)param_1 + 0xb) != '\0')) &&
                 (((*(char *)((long)param_1 + 0xc) != '\0' &&
                   (*(char *)((long)param_1 + 0xd) != '\0')) &&
                  ((*(char *)((long)param_1 + 0xe) != '\0' &&
                   ((*(char *)((long)param_1 + 0xf) != '\0' && ((char)param_1[2] != '\0'))))))))))))
           && (*(char *)((long)param_1 + 0x11) != '\0')) &&
          (((*(char *)((long)param_1 + 0x12) != '\0' && (*(char *)((long)param_1 + 0x13) != '\0'))
           && (*(char *)((long)param_1 + 0x14) != '\0')))) &&
         (((*(char *)((long)param_1 + 0x15) != '\0' && (*(char *)((long)param_1 + 0x16) != '\0')) &&
          ((((*(char *)((long)param_1 + 0x17) != '\0' &&
             (((char)param_1[3] != '\0' && (*(char *)((long)param_1 + 0x19) != '\0')))) &&
            (*(char *)((long)param_1 + 0x1a) != '\0')) &&
           ((((*(char *)((long)param_1 + 0x1b) != '\0' && (*(char *)((long)param_1 + 0x1c) != '\0'))
             && (*(char *)((long)param_1 + 0x1d) != '\0')) &&
            ((*(char *)((long)param_1 + 0x1e) != '\0' && (*(char *)((long)param_1 + 0x1f) != '\0')))
            ))))))) goto LAB_fffffff00a4dd63c;
      uVar6 = FUN_fffffff00a1d1550(param_1);
      uVar13 = uVar6;
      if (0x1f < uVar6) {
        uVar13 = 0x20;
      }
      if (uVar6 != 0) {
        lVar8 = 0;
        uVar14 = uVar13;
        do {
          cVar1 = *(char *)((long)puVar12 + lVar8 + 0x10);
          if (cVar1 != *(char *)((long)param_1 + lVar8)) goto LAB_fffffff00a4dd36c;
          if (cVar1 == '\0') goto LAB_fffffff00a4dd378;
          lVar8 = lVar8 + 1;
          uVar14 = uVar14 - 1;
        } while (uVar14 != 0);
        if (uVar6 < 0x21) {
          if (uVar6 != 0x20) goto LAB_fffffff00a4dd364;
        }
        else if (*(char *)((long)param_1 + uVar13) != '\0') goto LAB_fffffff00a4dd36c;
LAB_fffffff00a4dd378:
        if ((((((char)*puVar7 != '\0') && (*(char *)((long)param_1 + 0x21) != '\0')) &&
             ((*(char *)((long)param_1 + 0x22) != '\0' &&
              (((*(char *)((long)param_1 + 0x23) != '\0' &&
                (*(char *)((long)param_1 + 0x24) != '\0')) &&
               (*(char *)((long)param_1 + 0x25) != '\0')))))) &&
            (((*(char *)((long)param_1 + 0x26) != '\0' && (*(char *)((long)param_1 + 0x27) != '\0'))
             && ((((char)param_1[5] != '\0' &&
                  (((*(char *)((long)param_1 + 0x29) != '\0' &&
                    (*(char *)((long)param_1 + 0x2a) != '\0')) &&
                   ((*(char *)((long)param_1 + 0x2b) != '\0' &&
                    (((*(char *)((long)param_1 + 0x2c) != '\0' &&
                      (*(char *)((long)param_1 + 0x2d) != '\0')) &&
                     (*(char *)((long)param_1 + 0x2e) != '\0')))))))) &&
                 (((*(char *)((long)param_1 + 0x2f) != '\0' && ((char)param_1[6] != '\0')) &&
                  (*(char *)((long)param_1 + 0x31) != '\0')))))))) &&
           (((((*(char *)((long)param_1 + 0x32) != '\0' && (*(char *)((long)param_1 + 0x33) != '\0')
               ) && ((*(char *)((long)param_1 + 0x34) != '\0' &&
                     (((((*(char *)((long)param_1 + 0x35) != '\0' &&
                         (*(char *)((long)param_1 + 0x36) != '\0')) &&
                        (*(char *)((long)param_1 + 0x37) != '\0')) &&
                       (((char)param_1[7] != '\0' && (*(char *)((long)param_1 + 0x39) != '\0')))) &&
                      (*(char *)((long)param_1 + 0x3a) != '\0')))))) &&
             ((*(char *)((long)param_1 + 0x3b) != '\0' && (*(char *)((long)param_1 + 0x3c) != '\0'))
             )) && ((*(char *)((long)param_1 + 0x3d) != '\0' &&
                    ((*(char *)((long)param_1 + 0x3e) != '\0' &&
                     (*(char *)((long)param_1 + 0x3f) != '\0')))))))) goto LAB_fffffff00a4dd63c;
        uVar6 = FUN_fffffff00a1d1550(puVar7);
        uVar13 = uVar6;
        if (0x1f < uVar6) {
          uVar13 = 0x20;
        }
        if (uVar6 == 0) {
LAB_fffffff00a4dd1f8:
          cVar1 = *(char *)((long)puVar12 + uVar13 + 0x30);
joined_r0xfffffff00a4dd1fc:
          if (cVar1 != '\0') goto LAB_fffffff00a4dd36c;
        }
        else {
          lVar8 = 0;
          uVar14 = uVar13;
          do {
            cVar1 = *(char *)((long)puVar12 + lVar8 + 0x30);
            if (cVar1 != *(char *)((long)puVar7 + lVar8)) goto LAB_fffffff00a4dd36c;
            if (cVar1 == '\0') goto LAB_fffffff00a4dd4cc;
            lVar8 = lVar8 + 1;
            uVar14 = uVar14 - 1;
          } while (uVar14 != 0);
          if (0x20 < uVar6) {
            cVar1 = *(char *)((long)puVar7 + uVar13);
            goto joined_r0xfffffff00a4dd1fc;
          }
          if (uVar6 != 0x20) goto LAB_fffffff00a4dd1f8;
        }
LAB_fffffff00a4dd4cc:
        if (puVar12 < puVar12 + 0xb) {
          iVar5 = *(int *)((long)puVar12 + 0x54U);
          *(int *)((long)puVar12 + 0x54U) = iVar5 + 1;
          if (0xf0000001 < iVar5 + 0xf0000001U) {
            return *(uint *)(puVar12 + 10);
          }
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa61ed0();
        }
LAB_fffffff00a4dd63c:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a4dd640);
        (*pcVar3)();
      }
LAB_fffffff00a4dd364:
      if (*(char *)((long)puVar12 + uVar13 + 0x10) == '\0') goto LAB_fffffff00a4dd378;
LAB_fffffff00a4dd36c:
      puVar12 = (ulong *)*puVar12;
    } while (puVar12 != (ulong *)0x0);
  }
  puVar7 = (ulong *)FUN_fffffff00a2216c4(&DAT_fffffff007c72c90,0x8004);
  *(char *)((long)param_1 + 0x1f) = '\0';
  *(char *)((long)param_1 + 0x3f) = '\0';
  uVar14 = *param_1;
  uVar6 = param_1[3];
  uVar13 = param_1[2];
  puVar7[3] = param_1[1];
  puVar7[2] = uVar14;
  puVar7[5] = uVar6;
  puVar7[4] = uVar13;
  uVar13 = param_1[4];
  uVar14 = param_1[7];
  uVar6 = param_1[6];
  puVar7[7] = param_1[5];
  puVar7[6] = uVar13;
  puVar7[9] = uVar14;
  puVar7[8] = uVar6;
  uVar9 = 0xffff;
  bVar4 = DAT_fffffff00adcdccc + 1 < 0xffff;
  if (0xffff < DAT_fffffff00adcdccc + 1) {
    uVar9 = DAT_fffffff00adcdccc + 1;
  }
  puVar11 = &DAT_fffffff00adcdcd0;
  do {
    do {
      puVar11 = (undefined8 *)*puVar11;
      DAT_fffffff00adcdccc = uVar9;
      if (puVar11 == (undefined8 *)0x0) goto LAB_fffffff00a4dd5d8;
    } while (*(uint *)(puVar11 + 10) != uVar9);
    DAT_fffffff00adcdccc = uVar9 + 1;
    uVar10 = 0xffff;
    bVar2 = (bool)(DAT_fffffff00adcdccc < 0xffff & bVar4);
    if (0xffff < DAT_fffffff00adcdccc) {
      uVar10 = uVar9 + 1;
    }
    bVar4 = (bool)(DAT_fffffff00adcdccc < 0xffff | bVar4);
    puVar11 = &DAT_fffffff00adcdcd0;
    uVar9 = uVar10;
  } while (!bVar2);
  FUN_fffffff00a8df19c(&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,"%s: %s\n");
  uVar9 = 1;
LAB_fffffff00a4dd5d8:
  *(uint *)(puVar7 + 10) = uVar9;
  *(undefined4 *)((long)puVar7 + 0x54) = 1;
  if (DAT_fffffff00adcdcd0 == (ulong *)0x0) {
    *puVar7 = 0;
  }
  else {
    if ((ulong **)*(undefined8 **)((long)DAT_fffffff00adcdcd0 + 8) != &DAT_fffffff00adcdcd0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a4dd63c);
      (*pcVar3)();
    }
    *puVar7 = (ulong)DAT_fffffff00adcdcd0;
    *(ulong **)((long)DAT_fffffff00adcdcd0 + 8) = puVar7;
    uVar9 = (uint)puVar7[10];
  }
  DAT_fffffff00adcdcd0 = puVar7;
  puVar7[1] = (ulong)&DAT_fffffff00adcdcd0;
  return uVar9;
}

