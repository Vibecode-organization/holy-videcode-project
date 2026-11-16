// FUN_fffffff0085287f4 @ fffffff0085287f4 size=2288
// CALLERS:
//   fffffff00afb8e02 no-fn
//   fffffff00841364c FUN_fffffff008413408@fffffff008413408
//   fffffff008417008 FUN_fffffff008416ce8@fffffff008416ce8
//   fffffff0084173fc FUN_fffffff008416ce8@fffffff008416ce8
//   fffffff0084181cc FUN_fffffff008416ce8@fffffff008416ce8
//   fffffff008418afc FUN_fffffff008416ce8@fffffff008416ce8
//   fffffff008419140 FUN_fffffff008416ce8@fffffff008416ce8
//   fffffff0084191c4 FUN_fffffff008416ce8@fffffff008416ce8
//   fffffff008419170 FUN_fffffff008416ce8@fffffff008416ce8
//   fffffff008419254 FUN_fffffff008416ce8@fffffff008416ce8
// CALLEES:
//   fffffff00859af78 thunk_EXT_FUN_801100000322ffdc
//   fffffff00859ae08 thunk_EXT_FUN_8011000002c25028
//   fffffff00859adc8 thunk_EXT_FUN_8011000002c24f68
//   fffffff00859ae18 thunk_EXT_FUN_8011000002c25628
//   fffffff00859add8 thunk_EXT_FUN_8011000002c24d28
//   fffffff00859ae38 thunk_EXT_FUN_8011000002c250e8
//   fffffff0084d7b70 FUN_fffffff0084d7b70
//   fffffff0084f5250 FUN_fffffff0084f5250
//   fffffff00856bac8 FUN_fffffff00856bac8
//   fffffff00859ae28 thunk_EXT_FUN_8011000002c25268
//   fffffff00859ae58 thunk_EXT_FUN_8011000002c253e8
//   fffffff00859ad38 thunk_EXT_FUN_8011000002c1e4e8
//   fffffff00859ad18 thunk_EXT_FUN_8011000002c1e350
//   fffffff00859ace8 thunk_EXT_FUN_8011000002c1e3bc
//   fffffff0083d8120 FUN_fffffff0083d8120
//   fffffff00859ad28 thunk_EXT_FUN_8011000002c1e74c
//   fffffff00859ada8 thunk_EXT_FUN_8011000002c24c68
//   fffffff0083d80cc FUN_fffffff0083d80cc
//   fffffff00859acc8 thunk_EXT_FUN_8011000002c1e5b4
//   fffffff00850277c FUN_fffffff00850277c
//   fffffff0084f5208 FUN_fffffff0084f5208
//   fffffff00859ad68 thunk_EXT_FUN_8011000002c24ba8
//   fffffff0084f5288 FUN_fffffff0084f5288
//   fffffff00859ae98 thunk_EXT_FUN_80110000038db19c
//   fffffff0084d7be4 FUN_fffffff0084d7be4
//   fffffff00859ade8 thunk_EXT_FUN_8011000002c24de8
//   fffffff00859ae68 thunk_EXT_FUN_8011000002c25328
//   fffffff008523448 FUN_fffffff008523448
//   fffffff00859adf8 thunk_EXT_FUN_8011000002c251a8
//   fffffff00859acf8 thunk_EXT_FUN_8011000002c1e680
//   fffffff00859ae48 thunk_EXT_FUN_8011000002c256e8
//   fffffff00859adb8 thunk_EXT_FUN_8011000002c24ea8

undefined8 FUN_fffffff0085287f4(long param_1,uint param_2,ulong param_3,long *param_4)

{
  long *plVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ulong uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  long lVar15;
  long lVar16;
  bool bVar17;
  long lVar18;
  
  if (((param_2 < 4) && ((uint)param_3 < 2)) && (param_4 != (long *)0x0)) {
    if ((*(ulong *)(param_1 + 0x120) >> ((ulong)((uint)param_3 | param_2 << 1) & 0x3f) & 1) == 0) {
      iVar8 = FUN_fffffff0084f5208(0x4c,4);
      if (iVar8 != 0) {
        iVar8 = FUN_fffffff0084f5250(0x4c);
        FUN_fffffff00856bac8();
        FUN_fffffff0084f5288(4);
        if (iVar8 == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007d07808,0,
                     "%lld %d AVE %s: %s::%s:%d %s | wrong calling sequence %p %lld %s 0x%llx");
        }
        else {
          thunk_EXT_FUN_801100000322ffdc
                    ("%lld %d AVE %s: %s::%s:%d %s | wrong calling sequence %p %lld %s 0x%llx\n");
        }
      }
      uVar10 = 0xfffffc0d;
    }
    else {
      param_4[0xd] = 0;
      param_4[0xc] = 0;
      param_4[0xf] = 0;
      param_4[0xe] = 0;
      param_4[9] = 0;
      param_4[8] = 0;
      param_4[0xb] = 0;
      param_4[10] = 0;
      param_4[5] = 0;
      param_4[4] = 0;
      param_4[7] = 0;
      param_4[6] = 0;
      param_4[1] = 0;
      *param_4 = 0;
      param_4[3] = 0;
      param_4[2] = 0;
      uVar10 = thunk_EXT_FUN_8011000002c1e3bc(*(undefined8 *)(param_1 + 0x68));
      lVar15 = 0;
      lVar18 = 0;
      lVar16 = (ulong)param_2 * 0x10;
      uVar12 = param_1 + 0xc0 + (long)(int)lVar16;
      if (lVar16 != (int)lVar16) {
        uVar12 = param_1 + 0xc0 + lVar16 & 0xffffffffffffU | 0x2bad000000000000;
      }
      bVar2 = true;
      do {
        bVar17 = bVar2;
        lVar15 = lVar15 * 8;
        plVar1 = (long *)(uVar12 + (long)(int)lVar15);
        if (lVar15 - (int)lVar15 != 0) {
          plVar1 = (long *)(uVar12 + lVar15 & 0xffffffffffff | 0x2bad000000000000);
        }
        lVar16 = *plVar1;
        if ((lVar16 != 0) && ((*(ulong *)(lVar16 + 0x20) & 1L << (param_3 & 0x3f)) != 0)) {
          lVar18 = *(long *)(lVar16 + 0x28);
        }
        lVar15 = 1;
        bVar2 = false;
      } while (bVar17);
      uVar11 = thunk_EXT_FUN_8011000002c1e350(*(undefined8 *)(param_1 + 0x68));
      lVar16 = FUN_fffffff00850277c();
      if (lVar16 == 0) {
        iVar8 = FUN_fffffff008523448(uVar11);
        if (iVar8 != 0) {
          uVar12 = thunk_EXT_FUN_8011000002c251a8(*(undefined8 *)(param_1 + 0x68),0);
          *param_4 = lVar18 + (uVar12 & 0xffffffff);
          uVar12 = thunk_EXT_FUN_8011000002c25268(*(undefined8 *)(param_1 + 0x68),0);
          param_4[2] = lVar18 + (uVar12 & 0xffffffff);
          uVar11 = thunk_EXT_FUN_8011000002c24ea8(*(undefined8 *)(param_1 + 0x68),0);
          uVar13 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),0);
          uVar14 = thunk_EXT_FUN_8011000002c24d28(*(undefined8 *)(param_1 + 0x68),0);
          uVar3 = FUN_fffffff0084d7b70(uVar11,uVar13,uVar14);
          *(undefined4 *)(param_4 + 1) = uVar3;
          uVar11 = thunk_EXT_FUN_8011000002c24ea8(*(undefined8 *)(param_1 + 0x68),0);
          uVar13 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),0);
          uVar14 = thunk_EXT_FUN_8011000002c24de8(*(undefined8 *)(param_1 + 0x68),0);
          uVar3 = FUN_fffffff0084d7be4(uVar11,uVar13,uVar14);
          *(undefined4 *)(param_4 + 3) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c25328(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)((long)param_4 + 0x2c) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c253e8(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)(param_4 + 6) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c1e680(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)((long)param_4 + 0x24) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c1e74c(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)(param_4 + 5) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c250e8(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)((long)param_4 + 0x34) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c256e8(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)(param_4 + 7) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c25628(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)((long)param_4 + 0x3c) = uVar3;
          iVar8 = thunk_EXT_FUN_8011000002c24ea8(*(undefined8 *)(param_1 + 0x68),0);
          iVar9 = thunk_EXT_FUN_8011000002c24ba8(*(undefined8 *)(param_1 + 0x68),0);
          iVar4 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),0);
          iVar5 = thunk_EXT_FUN_8011000002c24c68(*(undefined8 *)(param_1 + 0x68),0);
          *(int *)(param_4 + 4) = iVar9 * iVar8 * iVar4 * iVar5;
          *(undefined4 *)((long)param_4 + 0xc) = *(undefined4 *)((long)param_4 + 0x34);
          uVar12 = thunk_EXT_FUN_8011000002c1e4e8(*(undefined8 *)(param_1 + 0x68),1);
          param_4[8] = lVar18 + (uVar12 & 0xffffffff);
          uVar3 = thunk_EXT_FUN_8011000002c1e5b4(*(undefined8 *)(param_1 + 0x68),1);
          *(undefined4 *)(param_4 + 9) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c250e8(*(undefined8 *)(param_1 + 0x68),1);
          *(undefined4 *)((long)param_4 + 0x4c) = uVar3;
        }
      }
      else if ((*(uint *)(lVar16 + 0x18) & 0xfffffffe) == 2) {
        uVar12 = thunk_EXT_FUN_8011000002c251a8(*(undefined8 *)(param_1 + 0x68),0);
        *param_4 = lVar18 + (uVar12 & 0xffffffff);
        uVar12 = thunk_EXT_FUN_8011000002c25268(*(undefined8 *)(param_1 + 0x68),0);
        param_4[2] = lVar18 + (uVar12 & 0xffffffff);
        uVar3 = thunk_EXT_FUN_8011000002c25328(*(undefined8 *)(param_1 + 0x68),0);
        *(undefined4 *)((long)param_4 + 0x2c) = uVar3;
        uVar3 = thunk_EXT_FUN_8011000002c253e8(*(undefined8 *)(param_1 + 0x68),0);
        *(undefined4 *)(param_4 + 6) = uVar3;
        uVar3 = thunk_EXT_FUN_8011000002c1e680(*(undefined8 *)(param_1 + 0x68),0);
        *(undefined4 *)((long)param_4 + 0x24) = uVar3;
        uVar3 = thunk_EXT_FUN_8011000002c1e74c(*(undefined8 *)(param_1 + 0x68),0);
        *(undefined4 *)(param_4 + 5) = uVar3;
        if (*(int *)(lVar16 + 0x18) == 2) {
          uVar3 = thunk_EXT_FUN_8011000002c250e8(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)((long)param_4 + 0x34) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c25628(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)((long)param_4 + 0x3c) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c256e8(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)(param_4 + 7) = uVar3;
          iVar4 = thunk_EXT_FUN_8011000002c24ea8(*(undefined8 *)(param_1 + 0x68),0);
          iVar5 = thunk_EXT_FUN_8011000002c24ba8(*(undefined8 *)(param_1 + 0x68),0);
          iVar6 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),0);
          iVar7 = thunk_EXT_FUN_8011000002c24c68(*(undefined8 *)(param_1 + 0x68),0);
          iVar9 = *(int *)(lVar16 + 4);
          iVar8 = iVar9 + 0xe;
          if (-8 < iVar9) {
            iVar8 = iVar9 + 7;
          }
          *(int *)(param_4 + 4) = iVar5 * iVar4 * iVar6 * iVar7 * (iVar8 >> 3);
          uVar11 = thunk_EXT_FUN_8011000002c24ea8(*(undefined8 *)(param_1 + 0x68),0);
          uVar13 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),0);
          uVar14 = thunk_EXT_FUN_8011000002c24d28(*(undefined8 *)(param_1 + 0x68),0);
          uVar3 = FUN_fffffff0083d80cc(uVar11,uVar13,uVar14);
          *(undefined4 *)(param_4 + 1) = uVar3;
          uVar11 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),0);
          uVar13 = thunk_EXT_FUN_8011000002c256e8(*(undefined8 *)(param_1 + 0x68),0);
          uVar14 = thunk_EXT_FUN_8011000002c250e8(*(undefined8 *)(param_1 + 0x68),0);
          uVar3 = FUN_fffffff0083d8120(uVar11,uVar13,uVar14);
        }
        else {
          uVar3 = thunk_EXT_FUN_8011000002c25028(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)((long)param_4 + 0x34) = uVar3;
          uVar11 = thunk_EXT_FUN_8011000002c24ea8(*(undefined8 *)(param_1 + 0x68),0);
          uVar13 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),0);
          uVar14 = thunk_EXT_FUN_8011000002c24d28(*(undefined8 *)(param_1 + 0x68),0);
          uVar3 = FUN_fffffff0084d7b70(uVar11,uVar13,uVar14);
          *(undefined4 *)(param_4 + 1) = uVar3;
          uVar11 = thunk_EXT_FUN_8011000002c24ea8(*(undefined8 *)(param_1 + 0x68),0);
          uVar13 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),0);
          uVar14 = thunk_EXT_FUN_8011000002c24de8(*(undefined8 *)(param_1 + 0x68),0);
          uVar3 = FUN_fffffff0084d7be4(uVar11,uVar13,uVar14);
        }
        *(undefined4 *)(param_4 + 3) = uVar3;
        *(undefined4 *)((long)param_4 + 0xc) = *(undefined4 *)((long)param_4 + 0x34);
        if (1 < *(int *)(lVar16 + 8)) {
          uVar12 = thunk_EXT_FUN_8011000002c251a8(*(undefined8 *)(param_1 + 0x68),1);
          param_4[8] = lVar18 + (uVar12 & 0xffffffff);
          uVar12 = thunk_EXT_FUN_8011000002c25268(*(undefined8 *)(param_1 + 0x68),1);
          param_4[10] = lVar18 + (uVar12 & 0xffffffff);
          uVar3 = thunk_EXT_FUN_8011000002c25328(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)((long)param_4 + 0x6c) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c253e8(*(undefined8 *)(param_1 + 0x68),0);
          *(undefined4 *)(param_4 + 0xe) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c1e680(*(undefined8 *)(param_1 + 0x68),1);
          *(undefined4 *)((long)param_4 + 100) = uVar3;
          uVar3 = thunk_EXT_FUN_8011000002c1e74c(*(undefined8 *)(param_1 + 0x68),1);
          *(undefined4 *)(param_4 + 0xd) = uVar3;
          if (*(int *)(lVar16 + 0x18) == 2) {
            uVar3 = thunk_EXT_FUN_8011000002c250e8(*(undefined8 *)(param_1 + 0x68),1);
            *(undefined4 *)((long)param_4 + 0x74) = uVar3;
            uVar3 = thunk_EXT_FUN_8011000002c256e8(*(undefined8 *)(param_1 + 0x68),1);
            *(undefined4 *)(param_4 + 0xf) = uVar3;
            uVar3 = thunk_EXT_FUN_8011000002c25628(*(undefined8 *)(param_1 + 0x68),1);
            *(undefined4 *)((long)param_4 + 0x7c) = uVar3;
            iVar4 = thunk_EXT_FUN_8011000002c24ea8(*(undefined8 *)(param_1 + 0x68),1);
            iVar5 = thunk_EXT_FUN_8011000002c24ba8(*(undefined8 *)(param_1 + 0x68),1);
            iVar6 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),1);
            iVar7 = thunk_EXT_FUN_8011000002c24c68(*(undefined8 *)(param_1 + 0x68),1);
            iVar9 = *(int *)(lVar16 + 4);
            iVar8 = iVar9 + 0xe;
            if (-8 < iVar9) {
              iVar8 = iVar9 + 7;
            }
            *(int *)(param_4 + 0xc) = iVar4 * iVar5 * iVar6 * iVar7 * (iVar8 >> 3) * 2;
            uVar11 = thunk_EXT_FUN_8011000002c24ea8(*(undefined8 *)(param_1 + 0x68),1);
            uVar13 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),1);
            uVar14 = thunk_EXT_FUN_8011000002c24d28(*(undefined8 *)(param_1 + 0x68),1);
            uVar3 = FUN_fffffff0083d80cc(uVar11,uVar13,uVar14);
            *(undefined4 *)(param_4 + 9) = uVar3;
            uVar11 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),1);
            uVar13 = thunk_EXT_FUN_8011000002c256e8(*(undefined8 *)(param_1 + 0x68),1);
            uVar14 = thunk_EXT_FUN_8011000002c250e8(*(undefined8 *)(param_1 + 0x68),1);
            uVar3 = FUN_fffffff0083d8120(uVar11,uVar13,uVar14);
          }
          else {
            uVar3 = thunk_EXT_FUN_8011000002c25028(*(undefined8 *)(param_1 + 0x68),1);
            *(undefined4 *)((long)param_4 + 0x74) = uVar3;
            uVar11 = thunk_EXT_FUN_8011000002c24ea8(*(undefined8 *)(param_1 + 0x68),1);
            uVar13 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),1);
            uVar14 = thunk_EXT_FUN_8011000002c24d28(*(undefined8 *)(param_1 + 0x68),1);
            uVar3 = FUN_fffffff0084d7b70(uVar11,uVar13,uVar14);
            *(undefined4 *)(param_4 + 9) = uVar3;
            uVar11 = thunk_EXT_FUN_8011000002c24ea8(*(undefined8 *)(param_1 + 0x68),1);
            uVar13 = thunk_EXT_FUN_8011000002c24f68(*(undefined8 *)(param_1 + 0x68),1);
            uVar14 = thunk_EXT_FUN_8011000002c24de8(*(undefined8 *)(param_1 + 0x68),1);
            uVar3 = FUN_fffffff0084d7be4(uVar11,uVar13,uVar14);
          }
          *(undefined4 *)(param_4 + 0xb) = uVar3;
          *(undefined4 *)((long)param_4 + 0x4c) = *(undefined4 *)((long)param_4 + 0x74);
        }
      }
      else {
        uVar10 = 0xfffffc16;
      }
    }
  }
  else {
    iVar8 = FUN_fffffff0084f5208(0x4c,4);
    if (iVar8 != 0) {
      iVar8 = FUN_fffffff0084f5250(0x4c);
      FUN_fffffff00856bac8();
      FUN_fffffff0084f5288(4);
      if (iVar8 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007d07808,0,
                   "%lld %d AVE %s: %s::%s:%d %s | wrong parameters %p %lld %s %d %d %p");
      }
      else {
        thunk_EXT_FUN_801100000322ffdc
                  ("%lld %d AVE %s: %s::%s:%d %s | wrong parameters %p %lld %s %d %d %p\n");
      }
    }
    uVar10 = 0xfffffc17;
  }
  return uVar10;
}

