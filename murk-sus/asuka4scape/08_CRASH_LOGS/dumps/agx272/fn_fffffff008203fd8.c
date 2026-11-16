// FUN_fffffff008203fd8 @ fffffff008203fd8 size=17652

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff008203fd8(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  long *plVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  undefined8 in_x7;
  uint uVar14;
  ulong uVar15;
  ulong uVar16;
  uint uVar17;
  long *plVar18;
  ulong uVar19;
  byte bVar20;
  byte bVar21;
  byte bVar22;
  byte bVar23;
  byte bVar24;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  ulong local_80;
  undefined8 uStack_78;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007ca61a0;
  plVar7 = (long *)thunk_EXT_FUN_80110000039b9f34(0);
  if (plVar7 == (long *)0x0) goto LAB_fffffff0082081e4;
  lVar8 = thunk_EXT_FUN_80110000039b54c0(*(undefined8 *)(param_1 + 0x10),2,0x300007600000000);
  *(long *)(param_1 + 0x58) = lVar8;
  if (lVar8 != 0) {
    thunk_EXT_FUN_80110000039b41ec(lVar8,0x454e45524759,"GPU Energy");
    thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0x58),0x454e45524759,0);
    thunk_EXT_FUN_80110000039ba158
              (*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x58),"Energy Model",0);
    iVar6 = (**(code **)(**(long **)(param_1 + 0x20) + 0xf0))
                      (*(long **)(param_1 + 0x20),*(undefined8 *)(param_1 + 0x58));
    if (iVar6 != 0) {
      lVar8 = thunk_EXT_FUN_80110000039b54c0
                        (*(undefined8 *)(param_1 + 0x10),0x8000,0x6400000000000000);
      *(long *)(param_1 + 0xb8) = lVar8;
      if (lVar8 != 0) {
        thunk_EXT_FUN_80110000039b41ec(lVar8,0x5a4f4e4530,"GPU Power Zone Filter 0");
        thunk_EXT_FUN_80110000039b41ec
                  (*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4531,"GPU Power Zone Filter 1");
        thunk_EXT_FUN_80110000039b41ec
                  (*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4532,"GPU Power Zone Filter 2");
        thunk_EXT_FUN_80110000039b41ec
                  (*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4533,"GPU Power Zone Filter 3");
        thunk_EXT_FUN_80110000039b41ec
                  (*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4534,"GPU Power Zone Filter 4");
        thunk_EXT_FUN_80110000039b41ec
                  (*(undefined8 *)(param_1 + 0xb8),0x46494c544552,"GPU Power Filter");
        thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4530,0);
        thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4531,0);
        thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4532,0);
        thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4533,0);
        thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xb8),0x5a4f4e4534,0);
        thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xb8),0x46494c544552,0);
        thunk_EXT_FUN_80110000039ba158
                  (*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0xb8),"GPU Stats",
                   "Power Zone Filters");
        iVar6 = (**(code **)(**(long **)(param_1 + 0x20) + 0xf0))
                          (*(long **)(param_1 + 0x20),*(undefined8 *)(param_1 + 0xb8));
        if (iVar6 != 0) {
          lVar8 = *(long *)(param_1 + 0x10);
          if ((*(byte *)(lVar8 + 0x11119) & 1) == 0) {
LAB_fffffff008204558:
            lVar8 = thunk_EXT_FUN_80110000039b6fd8(lVar8,2,0x10,0x101000000000000);
            *(long *)(param_1 + 0x60) = lVar8;
            if (lVar8 != 0) {
              thunk_EXT_FUN_80110000039b41ec(lVar8,0x4750555048,0);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,0,0x4f46460000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,1,0x5031000000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,2,0x5032000000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,3,0x5033000000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,4,0x5034000000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,5,0x5035000000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,6,0x5036000000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,7,0x5037000000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,8,0x5038000000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,9,0x5039000000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,10,0x5031300000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,0xb,0x5031310000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,0xc,0x5031320000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,0xd,0x5031330000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,0xe,0x5031340000000000);
              thunk_EXT_FUN_80110000039b7850
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,0xf,0x5031350000000000);
              thunk_EXT_FUN_80110000039b74c8
                        (*(undefined8 *)(param_1 + 0x60),0x4750555048,0x4f46460000000000,0,1,0);
              *(undefined8 *)(param_1 + 0x530) = 0;
              uVar9 = thunk_EXT_FUN_8011000003397c88();
              *(undefined8 *)(param_1 + 0x538) = uVar9;
              thunk_EXT_FUN_80110000039ba158
                        (*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x60),"GPU Stats"
                         ,"GPU Performance States");
              iVar6 = (**(code **)(**(long **)(param_1 + 0x20) + 0xf0))
                                (*(long **)(param_1 + 0x20),*(undefined8 *)(param_1 + 0x60));
              if (iVar6 != 0) {
                lVar8 = thunk_EXT_FUN_80110000039b6fd8
                                  (*(undefined8 *)(param_1 + 0x10),2,0x10,0x101000000000000);
                *(long *)(param_1 + 0x68) = lVar8;
                if (lVar8 != 0) {
                  thunk_EXT_FUN_80110000039b41ec(lVar8,0x4146525354415445,0);
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,0,0x4f46460000000000
                            );
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,1,0x5031000000000000
                            );
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,2,0x5032000000000000
                            );
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,3,0x5033000000000000
                            );
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,4,0x5034000000000000
                            );
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,5,0x5035000000000000
                            );
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,6,0x5036000000000000
                            );
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,7,0x5037000000000000
                            );
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,8,0x5038000000000000
                            );
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,9,0x5039000000000000
                            );
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,10,
                             0x5031300000000000);
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,0xb,
                             0x5031310000000000);
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,0xc,
                             0x5031320000000000);
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,0xd,
                             0x5031330000000000);
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,0xe,
                             0x5031340000000000);
                  thunk_EXT_FUN_80110000039b7850
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,0xf,
                             0x5031350000000000);
                  thunk_EXT_FUN_80110000039b74c8
                            (*(undefined8 *)(param_1 + 0x68),0x4146525354415445,0x4f46460000000000,0
                             ,1,0);
                  *(undefined8 *)(param_1 + 0x540) = 0;
                  uVar9 = thunk_EXT_FUN_8011000003397c88();
                  *(undefined8 *)(param_1 + 0x548) = uVar9;
                  thunk_EXT_FUN_80110000039ba158
                            (*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x68),
                             "GPU Stats","AFR Performance States");
                  iVar6 = (**(code **)(**(long **)(param_1 + 0x20) + 0xf0))
                                    (*(long **)(param_1 + 0x20),*(undefined8 *)(param_1 + 0x68));
                  if (iVar6 != 0) {
                    lVar8 = thunk_EXT_FUN_80110000039b6fd8
                                      (*(undefined8 *)(param_1 + 0x10),2,0x10,0x101000000000000);
                    *(long *)(param_1 + 0x128) = lVar8;
                    if (lVar8 != 0) {
                      thunk_EXT_FUN_80110000039b41ec(lVar8,0x4253544750555048,0);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,0,
                                 0x4f46460000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,1,
                                 0x5031000000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,2,
                                 0x5032000000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,3,
                                 0x5033000000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,4,
                                 0x5034000000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,5,
                                 0x5035000000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,6,
                                 0x5036000000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,7,
                                 0x5037000000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,8,
                                 0x5038000000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,9,
                                 0x5039000000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,10,
                                 0x5031300000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,0xb,
                                 0x5031310000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,0xc,
                                 0x5031320000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,0xd,
                                 0x5031330000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,0xe,
                                 0x5031340000000000);
                      thunk_EXT_FUN_80110000039b7850
                                (*(undefined8 *)(param_1 + 0x128),0x4253544750555048,0xf,
                                 0x5031350000000000);
                      *(undefined8 *)(param_1 + 0x5a8) = 0;
                      *(undefined4 *)(param_1 + 0x5b0) = 1;
                      uVar9 = thunk_EXT_FUN_8011000003397c88();
                      *(undefined8 *)(param_1 + 0x5b8) = uVar9;
                      *(undefined8 *)(param_1 + 0x5c0) = 0;
                      thunk_EXT_FUN_80110000039ba158
                                (*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x128),
                                 "GPU Stats","GPU Boost Controller Performance States");
                      iVar6 = (**(code **)(**(long **)(param_1 + 0x20) + 0xf0))
                                        (*(long **)(param_1 + 0x20),*(undefined8 *)(param_1 + 0x128)
                                        );
                      if (iVar6 != 0) {
                        lVar8 = *(long *)(param_1 + 0x10);
                        if ((*(byte *)(lVar8 + 0x439) & 1) == 0) {
LAB_fffffff008204d8c:
                          lVar8 = thunk_EXT_FUN_80110000039b6fd8(lVar8,2,2,0x101000000000000);
                          *(long *)(param_1 + 0x70) = lVar8;
                          if (lVar8 != 0) {
                            thunk_EXT_FUN_80110000039b41ec(lVar8,0x46454e444552,0);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x70),0x46454e444552,0,
                                       0x4f46460000000000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x70),0x46454e444552,1,
                                       0x4f4e000000000000);
                            thunk_EXT_FUN_80110000039b74c8
                                      (*(undefined8 *)(param_1 + 0x70),0x46454e444552,
                                       0x4f46460000000000,0,1,0);
                            *(undefined8 *)(param_1 + 0x550) = 0x4f46460000000000;
                            uVar9 = thunk_EXT_FUN_8011000003397c88();
                            *(undefined8 *)(param_1 + 0x558) = uVar9;
                            uVar9 = thunk_EXT_FUN_8011000003397c88();
                            *(undefined8 *)(param_1 + 0x560) = uVar9;
                            thunk_EXT_FUN_80110000039ba158
                                      (*(undefined8 *)(param_1 + 0x10),
                                       *(undefined8 *)(param_1 + 0x70),"GPU Stats","Fender State");
                            iVar6 = (**(code **)(**(long **)(param_1 + 0x20) + 0xf0))
                                              (*(long **)(param_1 + 0x20),
                                               *(undefined8 *)(param_1 + 0x70));
                            if (iVar6 != 0) {
                              uVar9 = thunk_EXT_FUN_80110000039b6fd8
                                                (*(undefined8 *)(param_1 + 0x10),2,0xb,
                                                 0x101000000000000);
                              *(undefined8 *)(param_1 + 0x78) = uVar9;
                              thunk_EXT_FUN_80110000039b41ec(uVar9,0x47505544564448,0);
                              thunk_EXT_FUN_80110000039b7850
                                        (*(undefined8 *)(param_1 + 0x78),0x47505544564448,0,
                                         0x302d392500000000);
                              thunk_EXT_FUN_80110000039b7850
                                        (*(undefined8 *)(param_1 + 0x78),0x47505544564448,1,
                                         0x31302d3139250000);
                              thunk_EXT_FUN_80110000039b7850
                                        (*(undefined8 *)(param_1 + 0x78),0x47505544564448,2,
                                         0x32302d3239250000);
                              thunk_EXT_FUN_80110000039b7850
                                        (*(undefined8 *)(param_1 + 0x78),0x47505544564448,3,
                                         0x33302d3339250000);
                              thunk_EXT_FUN_80110000039b7850
                                        (*(undefined8 *)(param_1 + 0x78),0x47505544564448,4,
                                         0x34302d3439250000);
                              thunk_EXT_FUN_80110000039b7850
                                        (*(undefined8 *)(param_1 + 0x78),0x47505544564448,5,
                                         0x35302d3539250000);
                              thunk_EXT_FUN_80110000039b7850
                                        (*(undefined8 *)(param_1 + 0x78),0x47505544564448,6,
                                         0x36302d3639250000);
                              thunk_EXT_FUN_80110000039b7850
                                        (*(undefined8 *)(param_1 + 0x78),0x47505544564448,7,
                                         0x37302d3739250000);
                              thunk_EXT_FUN_80110000039b7850
                                        (*(undefined8 *)(param_1 + 0x78),0x47505544564448,8,
                                         0x38302d3839250000);
                              thunk_EXT_FUN_80110000039b7850
                                        (*(undefined8 *)(param_1 + 0x78),0x47505544564448,9,
                                         0x39302d3939250000);
                              thunk_EXT_FUN_80110000039b7850
                                        (*(undefined8 *)(param_1 + 0x78),0x47505544564448,10,
                                         0x3130302500000000);
                              thunk_EXT_FUN_80110000039b7668
                                        (*(undefined8 *)(param_1 + 0x78),0x3130302500000000);
                              if (((*(long *)(param_1 + 0x78) != 0) &&
                                  (iVar6 = thunk_EXT_FUN_80110000039ba158
                                                     (*(undefined8 *)(param_1 + 0x10),
                                                      *(long *)(param_1 + 0x78),"GPU Stats",
                                                      "DVD Request States"), iVar6 == 0)) &&
                                 (iVar6 = (**(code **)(**(long **)(param_1 + 0x20) + 0xf0))
                                                    (*(long **)(param_1 + 0x20),
                                                     *(undefined8 *)(param_1 + 0x78)), iVar6 != 0))
                              {
                                lVar8 = thunk_EXT_FUN_80110000039b6fd8
                                                  (*(undefined8 *)(param_1 + 0x10),2,0x11,
                                                   0x101000000000000);
                                *(long *)(param_1 + 0x80) = lVar8;
                                if (lVar8 != 0) {
                                  thunk_EXT_FUN_80110000039b41ec(lVar8,0x4750555f434c544d,0);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,0,
                                             0x4f46460000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,1,
                                             0x5031000000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,2,
                                             0x5032000000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,3,
                                             0x5033000000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,4,
                                             0x5034000000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,5,
                                             0x5035000000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,6,
                                             0x5036000000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,7,
                                             0x5037000000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,8,
                                             0x5038000000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,9,
                                             0x5039000000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,10,
                                             0x5031300000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,0xb,
                                             0x5031310000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,0xc,
                                             0x5031320000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,0xd,
                                             0x5031330000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,0xe,
                                             0x5031340000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,0xf,
                                             0x5031350000000000);
                                  thunk_EXT_FUN_80110000039b7850
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,0x10
                                             ,0x4e4f5f434c544d00);
                                  thunk_EXT_FUN_80110000039b74c8
                                            (*(undefined8 *)(param_1 + 0x80),0x4750555f434c544d,
                                             0x4e4f5f434c544d00,0,1,0);
                                  *(undefined8 *)(param_1 + 0x568) = 0x4e4f5f434c544d00;
                                  uVar9 = thunk_EXT_FUN_8011000003397c88();
                                  *(undefined8 *)(param_1 + 0x570) = uVar9;
                                  thunk_EXT_FUN_80110000039ba158
                                            (*(undefined8 *)(param_1 + 0x10),
                                             *(undefined8 *)(param_1 + 0x80),"GPU Stats",
                                             "CLTM-induced GPU Performance States");
                                  iVar6 = (**(code **)(**(long **)(param_1 + 0x20) + 0xf0))
                                                    (*(long **)(param_1 + 0x20),
                                                     *(undefined8 *)(param_1 + 0x80));
                                  if (iVar6 != 0) {
                                    uStack_a8 = _UNK_fffffff007115bd8;
                                    local_b0 = _DAT_fffffff007115bd0;
                                    uStack_98 = _UNK_fffffff007115be8;
                                    local_a0 = _DAT_fffffff007115be0;
                                    uStack_88 = _UNK_fffffff007115bf8;
                                    local_90 = _DAT_fffffff007115bf0;
                                    lVar8 = thunk_EXT_FUN_80110000039b8dac
                                                      (*(undefined8 *)(param_1 + 0x10),2,
                                                       0x47505541637448,"GPU Active Time",
                                                       0x101000000000000,3,&local_b0);
                                    *(long *)(param_1 + 0x88) = lVar8;
                                    if (lVar8 != 0) {
                                      thunk_EXT_FUN_80110000039b8f8c(lVar8,0);
                                      iVar6 = thunk_EXT_FUN_80110000039ba158
                                                        (*(undefined8 *)(param_1 + 0x10),
                                                         *(undefined8 *)(param_1 + 0x88),"GPU Stats"
                                                         ,"Active Time Histogram");
                                      if ((iVar6 == 0) &&
                                         (iVar6 = (**(code **)(**(long **)(param_1 + 0x20) + 0xf0))
                                                            (*(long **)(param_1 + 0x20),
                                                             *(undefined8 *)(param_1 + 0x88)),
                                         iVar6 != 0)) {
                                        lVar8 = thunk_EXT_FUN_80110000039b8dac
                                                          (*(undefined8 *)(param_1 + 0x10),2,
                                                           0x47505549646c48,"GPU Idle Time",
                                                           0x101000000000000,3,&local_b0);
                                        *(long *)(param_1 + 0x90) = lVar8;
                                        if (lVar8 != 0) {
                                          thunk_EXT_FUN_80110000039b8f8c(lVar8,0);
                                          iVar6 = thunk_EXT_FUN_80110000039ba158
                                                            (*(undefined8 *)(param_1 + 0x10),
                                                             *(undefined8 *)(param_1 + 0x90),
                                                             "GPU Stats","Idle Time Histogram");
                                          if ((iVar6 == 0) &&
                                             (iVar6 = (**(code **)(**(long **)(param_1 + 0x20) +
                                                                  0xf0))(*(long **)(param_1 + 0x20),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0x90)),
                                             iVar6 != 0)) {
                                            lVar8 = thunk_EXT_FUN_80110000039b8dac
                                                              (*(undefined8 *)(param_1 + 0x10),2,
                                                               0x464e445241637448,
                                                               "Fender Active Time",
                                                               0x101000000000000,3,&local_b0);
                                            *(long *)(param_1 + 0x98) = lVar8;
                                            if (lVar8 != 0) {
                                              thunk_EXT_FUN_80110000039b8f8c(lVar8,0);
                                              iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                (*(undefined8 *)(param_1 + 0x10),
                                                                 *(undefined8 *)(param_1 + 0x98),
                                                                 "GPU Stats",
                                                                 "Fender Active Time Histogram");
                                              if ((iVar6 == 0) &&
                                                 (iVar6 = (**(code **)(**(long **)(param_1 + 0x20) +
                                                                      0xf0))(*(long **)(param_1 +
                                                                                       0x20),
                                                                             *(undefined8 *)
                                                                              (param_1 + 0x98)),
                                                 iVar6 != 0)) {
                                                lVar8 = thunk_EXT_FUN_80110000039b8dac
                                                                  (*(undefined8 *)(param_1 + 0x10),2
                                                                   ,0x464e445249646c48,
                                                                   "Fender Idle Time",
                                                                   0x101000000000000,3,&local_b0);
                                                *(long *)(param_1 + 0xa0) = lVar8;
                                                if (lVar8 != 0) {
                                                  thunk_EXT_FUN_80110000039b8f8c(lVar8,0);
                                                  iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                    (*(undefined8 *)(param_1 + 0x10)
                                                                     ,*(undefined8 *)
                                                                       (param_1 + 0xa0),"GPU Stats",
                                                                     "Fender Idle Time Histogram");
                                                  if ((iVar6 == 0) &&
                                                     (uVar19 = (**(code **)(**(long **)(param_1 +
                                                                                       0x20) + 0xf0)
                                                               )(*(long **)(param_1 + 0x20),
                                                                 *(undefined8 *)(param_1 + 0xa0)),
                                                     (uVar19 & 1) != 0)) {
                                                    lVar8 = thunk_EXT_FUN_80110000039b54c0
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),2,
                                                                       0x6400000000000000);
                                                    *(long *)(param_1 + 0xa8) = lVar8;
                                                    if (lVar8 != 0) {
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (lVar8,0x5556434f554e54,
                                                                 "UVWarn Instances");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xa8),
                                                                 0x5556414354495645,"UVWarn Active")
                                                      ;
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xa8),
                                                                 0x5556434f554e54,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xa8),
                                                                 0x5556414354495645,0);
                                                      thunk_EXT_FUN_80110000039ba158
                                                                (*(undefined8 *)(param_1 + 0x10),
                                                                 *(undefined8 *)(param_1 + 0xa8),
                                                                 "GPU Stats","UV Warn State");
                                                      iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                      0x20) + 0xf0))
                                                                        (*(long **)(param_1 + 0x20),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0xa8));
                                                      if (iVar6 != 0) {
                                                        lVar8 = thunk_EXT_FUN_80110000039b54c0
                                                                          (*(undefined8 *)
                                                                            (param_1 + 0x10),0x100,
                                                                           0x6400000000000000);
                                                        *(long *)(param_1 + 0x450) = lVar8;
                                                        if (lVar8 != 0) {
                                                          local_100 = 0;
                                                          uStack_f8 = 0;
                                                          uStack_88 = 0;
                                                          local_90 = 0;
                                                          uStack_78 = 0;
                                                          local_80 = 0;
                                                          uStack_a8 = 0;
                                                          local_b0 = 0;
                                                          uStack_98 = 0;
                                                          local_a0 = 0;
                                                          thunk_EXT_FUN_80110000037693ec
                                                                    (&local_100,0x10,"%uus");
                                                          thunk_EXT_FUN_80110000037693ec
                                                                    (&local_b0,0x40,
                                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0xff0),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0xff0),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0xff8),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0xff8),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1000),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1000),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1008),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1008),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1010),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1010),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1018),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1018),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1020),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1020),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1028),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1028),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1030),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1030),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1038),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1038),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1040),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1040),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket Max (>=%s)"
                                                  );
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1048),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1048),0);
                                                  local_100 = 0;
                                                  uStack_f8 = 0;
                                                  uStack_88 = 0;
                                                  local_90 = 0;
                                                  uStack_78 = 0;
                                                  local_80 = 0;
                                                  uStack_a8 = 0;
                                                  local_b0 = 0;
                                                  uStack_98 = 0;
                                                  local_a0 = 0;
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1050),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1050),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1058),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1058),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1060),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1060),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1068),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1068),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1070),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1070),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1078),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1078),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1080),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1080),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1088),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1088),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1090),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1090),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1098),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1098),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10a0),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10a0),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket Max (>=%s)"
                                                  );
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10a8),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10a8),0);
                                                  local_100 = 0;
                                                  uStack_f8 = 0;
                                                  uStack_88 = 0;
                                                  local_90 = 0;
                                                  uStack_78 = 0;
                                                  local_80 = 0;
                                                  uStack_a8 = 0;
                                                  local_b0 = 0;
                                                  uStack_98 = 0;
                                                  local_a0 = 0;
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10b0),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10b0),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10b8),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10b8),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10c0),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10c0),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10c8),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10c8),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10d0),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10d0),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10d8),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10d8),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10e0),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10e0),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10e8),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10e8),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10f0),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10f0),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10f8),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x10f8),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_100,0x10,"%uus");
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket %d (<%s)");
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1100),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1100),0);
                                                  thunk_EXT_FUN_80110000037693ec
                                                            (&local_b0,0x40,
                                                                                                                          
                                                  "%s CtxSwitch Latency Histogram Bucket Max (>=%s)"
                                                  );
                                                  thunk_EXT_FUN_80110000039b41ec
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1108),
                                                             &local_b0);
                                                  thunk_EXT_FUN_80110000039b5574
                                                            (*(undefined8 *)(param_1 + 0x450),
                                                             *(undefined8 *)(param_1 + 0x1108),0);
                                                  iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                    (*(undefined8 *)(param_1 + 0x10)
                                                                     ,*(undefined8 *)
                                                                       (param_1 + 0x450),"GPU Stats"
                                                                     ,"Context Switch Latencies");
                                                  if ((iVar6 == 0) &&
                                                     (iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                      0x20) + 0xf0))
                                                                        (*(long **)(param_1 + 0x20),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0x450)),
                                                     iVar6 != 0)) {
                                                    lVar8 = thunk_EXT_FUN_80110000039b54c0
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),0x100,
                                                                       0x6400000000000000);
                                                    *(long *)(param_1 + 0x458) = lVar8;
                                                    if (lVar8 != 0) {
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (lVar8,0x54484d5f41435456,
                                                                 "THM Activation Count");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x458),
                                                                 0x54484d5f41435456,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0x458),
                                                                 0x5346455449455233,
                                                                 "SFE Tier3 Count");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x458),
                                                                 0x5346455449455233,0);
                                                      iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                        (*(undefined8 *)
                                                                          (param_1 + 0x10),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0x458),
                                                                         "GPU Stats","THM Counters")
                                                      ;
                                                      if ((iVar6 == 0) &&
                                                         (iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                          0x20) +
                                                                              0xf0))(*(long **)(
                                                  param_1 + 0x20),*(undefined8 *)(param_1 + 0x458)),
                                                  iVar6 != 0)) {
                                                    lVar8 = thunk_EXT_FUN_80110000039b54c0
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),2,0);
                                                    *(long *)(param_1 + 0x4e0) = lVar8;
                                                    if (lVar8 != 0) {
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (lVar8,0x5057524142525453,
                                                                 "GPU Off Abort Counter");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x4e0),
                                                                 0x5057524142525453,0);
                                                      thunk_EXT_FUN_80110000039ba158
                                                                (*(undefined8 *)(param_1 + 0x10),
                                                                 *(undefined8 *)(param_1 + 0x4e0),
                                                                 "GPU Off Abort Counter",0);
                                                      iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                      0x20) + 0xf0))
                                                                        (*(long **)(param_1 + 0x20),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0x4e0));
                                                      if (iVar6 != 0) {
                                                        lVar8 = thunk_EXT_FUN_80110000039b54c0
                                                                          (*(undefined8 *)
                                                                            (param_1 + 0x10),0x100,
                                                                           0x6400000000000000);
                                                        *(long *)(param_1 + 0xb0) = lVar8;
                                                        if (lVar8 != 0) {
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (lVar8,0x5245535441525454,
                                                                     "Total Restarts");
                                                          thunk_EXT_FUN_80110000039b5574
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x5245535441525454,0);
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x5245535441525455,
                                                                     "Unknown Restarts");
                                                          thunk_EXT_FUN_80110000039b5574
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x5245535441525455,0);
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x4d53455256455244,
                                                                     "mediaserverd Restarts");
                                                          thunk_EXT_FUN_80110000039b5574
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x4d53455256455244,0);
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x5253543336323233,"36223");
                                                          thunk_EXT_FUN_80110000039b5574
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x5253543336323233,0);
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x5253543431383139,"41819");
                                                          thunk_EXT_FUN_80110000039b5574
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x5253543431383139,0);
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x5253543432383232,"42822");
                                                          thunk_EXT_FUN_80110000039b5574
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x5253543432383232,0);
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x444d4b494c4c,"DM Kill Count"
                                                                    );
                                                          thunk_EXT_FUN_80110000039b5574
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x444d4b494c4c,0);
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x4754504b494c4c,
                                                                     "GTP Kill Count");
                                                          thunk_EXT_FUN_80110000039b5574
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x4754504b494c4c,0);
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x4652474b494c4c,
                                                                     "FRG Kill Count");
                                                          thunk_EXT_FUN_80110000039b5574
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x4652474b494c4c,0);
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x43444d4b494c4c,
                                                                     "CDM Kill Count");
                                                          thunk_EXT_FUN_80110000039b5574
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x43444d4b494c4c,0);
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x4d454d4641494c,
                                                                     "Memless Render Failed");
                                                          thunk_EXT_FUN_80110000039b5574
                                                                    (*(undefined8 *)(param_1 + 0xb0)
                                                                     ,0x4d454d4641494c,0);
                                                          iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                            (*(undefined8 *)
                                                                              (param_1 + 0x10),
                                                                             *(undefined8 *)
                                                                              (param_1 + 0xb0),
                                                                             "GPU Stats",
                                                                             "Issue Counts");
                                                          if ((iVar6 == 0) &&
                                                             (iVar6 = (**(code **)(**(long **)(
                                                  param_1 + 0x20) + 0xf0))
                                                            (*(long **)(param_1 + 0x20),
                                                             *(undefined8 *)(param_1 + 0xb0)),
                                                  iVar6 != 0)) {
                                                    lVar8 = thunk_EXT_FUN_80110000039b54c0
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),0x100,
                                                                       0x6400000000000000);
                                                    *(long *)(param_1 + 0xe0) = lVar8;
                                                    if (lVar8 != 0) {
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (lVar8,0x475450564353474c,
                                                                 "GTP Single");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x4754505643444550,"GTP Dependent")
                                                      ;
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x475450564349444c,"GTP Idle");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x4754505643414c4c,"GTP Alloc New")
                                                      ;
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x4754505643524e44,
                                                                 "GTP Round robin");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x465247564353474c,"FRG Single");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x4652475643444550,"FRG Dependent")
                                                      ;
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x465247564349444c,"FRG Idle");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x4652475643414c4c,"FRG Alloc New")
                                                      ;
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x4652475643524e44,
                                                                 "FRG Round robin");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x43444d564353474c,"CDM Single");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x43444d5643444550,"CDM Dependent")
                                                      ;
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x43444d564349444c,"CDM Idle");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x43444d5643414c4c,"CDM Alloc New")
                                                      ;
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x43444d5643524e44,
                                                                 "CDM Round robin");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x475450564353474c,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x4754505643444550,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x475450564349444c,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x4754505643414c4c,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x4754505643524e44,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x465247564353474c,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x4652475643444550,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x465247564349444c,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x4652475643414c4c,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x4652475643524e44,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x43444d564353474c,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x43444d5643444550,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x43444d564349444c,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x43444d5643414c4c,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xe0),
                                                                 0x43444d5643524e44,0);
                                                      iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                        (*(undefined8 *)
                                                                          (param_1 + 0x10),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0xe0),
                                                                         "GPU Stats",
                                                                         "vChannel Selection");
                                                      if ((iVar6 == 0) &&
                                                         (iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                          0x20) +
                                                                              0xf0))(*(long **)(
                                                  param_1 + 0x20),*(undefined8 *)(param_1 + 0xe0)),
                                                  iVar6 != 0)) {
                                                    lVar8 = thunk_EXT_FUN_80110000039b54c0
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),0x100,
                                                                       0x6400000000000000);
                                                    *(long *)(param_1 + 200) = lVar8;
                                                    if (lVar8 != 0) {
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (lVar8,0x4754503000300000,
                                                                 "Channel 0");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 200),
                                                                 0x4754503000300000,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 200),
                                                                 0x4754503100300000,"Channel 1");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 200),
                                                                 0x4754503100300000,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 200),
                                                                 0x4754503200300000,"Channel 2");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 200),
                                                                 0x4754503200300000,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 200),
                                                                 0x4754503300300000,"Channel 3");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 200),
                                                                 0x4754503300300000,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 200),
                                                                 0x475450494e56414c,"Invalid");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 200),
                                                                 0x475450494e56414c,0);
                                                      iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                        (*(undefined8 *)
                                                                          (param_1 + 0x10),
                                                                         *(undefined8 *)
                                                                          (param_1 + 200),
                                                                         "GPU Stats",
                                                                         "GTP vChannel Usage");
                                                      if ((iVar6 == 0) &&
                                                         (iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                          0x20) +
                                                                              0xf0))(*(long **)(
                                                  param_1 + 0x20),*(undefined8 *)(param_1 + 200)),
                                                  iVar6 != 0)) {
                                                    lVar8 = thunk_EXT_FUN_80110000039b54c0
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),0x100,
                                                                       0x6400000000000000);
                                                    *(long *)(param_1 + 0xd0) = lVar8;
                                                    if (lVar8 != 0) {
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (lVar8,0x4652473000300000,
                                                                 "Channel 0");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xd0),
                                                                 0x4652473000300000,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xd0),
                                                                 0x4652473100300000,"Channel 1");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xd0),
                                                                 0x4652473100300000,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xd0),
                                                                 0x4652473200300000,"Channel 2");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xd0),
                                                                 0x4652473200300000,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xd0),
                                                                 0x4652473300300000,"Channel 3");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xd0),
                                                                 0x4652473300300000,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xd0),
                                                                 0x465247494e56414c,"Invalid");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xd0),
                                                                 0x465247494e56414c,0);
                                                      iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                        (*(undefined8 *)
                                                                          (param_1 + 0x10),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0xd0),
                                                                         "GPU Stats",
                                                                         "FRG vChannel Usage");
                                                      if ((iVar6 == 0) &&
                                                         (iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                          0x20) +
                                                                              0xf0))(*(long **)(
                                                  param_1 + 0x20),*(undefined8 *)(param_1 + 0xd0)),
                                                  iVar6 != 0)) {
                                                    lVar8 = thunk_EXT_FUN_80110000039b54c0
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),0x100,
                                                                       0x6400000000000000);
                                                    *(long *)(param_1 + 0xd8) = lVar8;
                                                    if (lVar8 != 0) {
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (lVar8,0x43444d3000300000,
                                                                 "Channel 0");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xd8),
                                                                 0x43444d3000300000,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xd8),
                                                                 0x43444d3100300000,"Channel 1");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xd8),
                                                                 0x43444d3100300000,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xd8),
                                                                 0x43444d3200300000,"Channel 2");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xd8),
                                                                 0x43444d3200300000,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xd8),
                                                                 0x43444d3300300000,"Channel 3");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xd8),
                                                                 0x43444d3300300000,0);
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0xd8),
                                                                 0x43444d494e56414c,"Invalid");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0xd8),
                                                                 0x43444d494e56414c,0);
                                                      iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                        (*(undefined8 *)
                                                                          (param_1 + 0x10),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0xd8),
                                                                         "GPU Stats",
                                                                         "CDM vChannel Usage");
                                                      if ((iVar6 == 0) &&
                                                         (iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                          0x20) +
                                                                              0xf0))(*(long **)(
                                                  param_1 + 0x20),*(undefined8 *)(param_1 + 0xd8)),
                                                  iVar6 != 0)) {
                                                    *(undefined4 *)(param_1 + 0x5d8) = 0;
                                                    lVar8 = thunk_EXT_FUN_80110000039b54c0
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),2,
                                                                       0x100007980000018);
                                                    *(long *)(param_1 + 0x100) = lVar8;
                                                    if (lVar8 != 0) {
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (lVar8,0x505a454e47414745,
                                                                 "GPU Discrete Power Zone Engaged");
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x100),
                                                                 0x505a454e47414745,0);
                                                      thunk_EXT_FUN_80110000039ba158
                                                                (*(undefined8 *)(param_1 + 0x10),
                                                                 *(undefined8 *)(param_1 + 0x100),
                                                                 "GPU Discrete Power Zone Engaged",0
                                                                );
                                                      iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                      0x20) + 0xf0))
                                                                        (*(long **)(param_1 + 0x20),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0x100));
                                                      if (iVar6 != 0) {
                                                        lVar8 = thunk_EXT_FUN_80110000039b6fd8
                                                                          (*(undefined8 *)
                                                                            (param_1 + 0x10),2,7,
                                                                           0x101000000000000);
                                                        *(long *)(param_1 + 0x108) = lVar8;
                                                        if (lVar8 != 0) {
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (lVar8,0x505a5253444e4359,0);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x108),
                                                                     0x505a5253444e4359,0,
                                                                     0x4e4f5f5a4f4e4500);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x108),
                                                                     0x505a5253444e4359,1,
                                                                     0x534c4f57434c544d);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x108),
                                                                     0x505a5253444e4359,2,
                                                                     0x5a4f4e4530);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x108),
                                                                     0x505a5253444e4359,3,
                                                                     0x5a4f4e4531);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x108),
                                                                     0x505a5253444e4359,4,
                                                                     0x5a4f4e4532);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x108),
                                                                     0x505a5253444e4359,5,
                                                                     0x5a4f4e4533);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x108),
                                                                     0x505a5253444e4359,6,
                                                                     0x5a4f4e4534);
                                                          thunk_EXT_FUN_80110000039b74c8
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x108),
                                                                     0x505a5253444e4359,
                                                                     0x4e4f5f5a4f4e4500,0,1,0);
                                                          *(undefined8 *)(param_1 + 0x5c8) =
                                                               0x4e4f5f5a4f4e4500;
                                                          uVar9 = thunk_EXT_FUN_8011000003397c88();
                                                          *(undefined8 *)(param_1 + 0x5d0) = uVar9;
                                                          thunk_EXT_FUN_80110000039ba158
                                                                    (*(undefined8 *)(param_1 + 0x10)
                                                                     ,*(undefined8 *)
                                                                       (param_1 + 0x108),"GPU Stats"
                                                                     ,
                                                  "GPU Discrete Power Zone Residency");
                                                  iVar6 = (**(code **)(**(long **)(param_1 + 0x20) +
                                                                      0xf0))(*(long **)(param_1 +
                                                                                       0x20),
                                                                             *(undefined8 *)
                                                                              (param_1 + 0x108));
                                                  if (iVar6 != 0) {
                                                    lVar8 = thunk_EXT_FUN_80110000039b6fd8
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),2,0x14,
                                                                       0x101000000000000);
                                                    *(long *)(param_1 + 0x110) = lVar8;
                                                    if (lVar8 != 0) {
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (lVar8,0x5057524354524c,0);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,0,
                                                                 0x49444c455f4f4646);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,1,
                                                                 0x5045524600000000);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,2,
                                                                 0x504f574552000000);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,3,
                                                                 0x5057525f5a4f4e45);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,4,
                                                                 0x464153545f444945);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,5,
                                                                 0x5554000000000000);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,6,
                                                                 0x5052464c494d4954);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,7,
                                                                 0x50504d4c494d4954);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,8,
                                                                 0x434c544d4c494d49);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,9,
                                                                 0x50504d5441524745);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,10,
                                                                 0x444541444c494e45);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,0xb,
                                                                 0x4445414441574152);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,0xc,
                                                                 0x505246424f4f5354);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,0xd,
                                                                 0x504d554c4f4f5000);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,0xe,
                                                                 0x5354414e44425900);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,0xf,
                                                                 0x5345000000000000);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,0x10,
                                                                 0x434f52455f454646);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,0x11,
                                                                 0x5455524230000000);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,0x12,
                                                                 0x4156475045524600);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,0x13,
                                                                 0x41564d5200000000);
                                                      thunk_EXT_FUN_80110000039b74c8
                                                                (*(undefined8 *)(param_1 + 0x110),
                                                                 0x5057524354524c,0x49444c455f4f4646
                                                                 ,0,1,0);
                                                      *(undefined8 *)(param_1 + 0x578) =
                                                           0x49444c455f4f4646;
                                                      uVar9 = thunk_EXT_FUN_8011000003397c88();
                                                      *(undefined8 *)(param_1 + 0x580) = uVar9;
                                                      thunk_EXT_FUN_80110000039ba158
                                                                (*(undefined8 *)(param_1 + 0x10),
                                                                 *(undefined8 *)(param_1 + 0x110),
                                                                 "GPU Stats",
                                                                 "GPU Power Controller States");
                                                      iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                      0x20) + 0xf0))
                                                                        (*(long **)(param_1 + 0x20),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0x110));
                                                      if (iVar6 != 0) {
                                                        lVar8 = thunk_EXT_FUN_80110000039b6fd8
                                                                          (*(undefined8 *)
                                                                            (param_1 + 0x10),2,0x14,
                                                                           0x101000000000000);
                                                        *(long *)(param_1 + 0x118) = lVar8;
                                                        if (lVar8 != 0) {
                                                          thunk_EXT_FUN_80110000039b41ec
                                                                    (lVar8,0x4146524354524c,0);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,0,
                                                                     0x49444c455f4f4646);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,1,
                                                                     0x5045524600000000);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,2,
                                                                     0x504f574552000000);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,3,
                                                                     0x5057525f5a4f4e45);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,4,
                                                                     0x464153545f444945);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,5,
                                                                     0x5554000000000000);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,6,
                                                                     0x5052464c494d4954);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,7,
                                                                     0x50504d4c494d4954);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,8,
                                                                     0x434c544d4c494d49);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,9,
                                                                     0x50504d5441524745);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,10,
                                                                     0x444541444c494e45);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,0xb,
                                                                     0x4445414441574152);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,0xc,
                                                                     0x505246424f4f5354);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,0xd,
                                                                     0x504d554c4f4f5000);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,0xe,
                                                                     0x5354414e44425900);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,0xf,
                                                                     0x5345000000000000);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,0x10,
                                                                     0x434f52455f454646);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,0x11,
                                                                     0x5455524230000000);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,0x12,
                                                                     0x4156475045524600);
                                                          thunk_EXT_FUN_80110000039b7850
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,0x13,
                                                                     0x41564d5200000000);
                                                          thunk_EXT_FUN_80110000039b74c8
                                                                    (*(undefined8 *)
                                                                      (param_1 + 0x118),
                                                                     0x4146524354524c,
                                                                     0x49444c455f4f4646,0,1,0);
                                                          *(undefined8 *)(param_1 + 0x588) =
                                                               0x49444c455f4f4646;
                                                          *(undefined8 *)(param_1 + 0x590) =
                                                               *(undefined8 *)(param_1 + 0x580);
                                                          thunk_EXT_FUN_80110000039ba158
                                                                    (*(undefined8 *)(param_1 + 0x10)
                                                                     ,*(undefined8 *)
                                                                       (param_1 + 0x118),"GPU Stats"
                                                                     ,"AFR Power Controller States")
                                                          ;
                                                          iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                          0x20) +
                                                                              0xf0))(*(long **)(
                                                  param_1 + 0x20),*(undefined8 *)(param_1 + 0x118));
                                                  if (iVar6 != 0) {
                                                    lVar8 = thunk_EXT_FUN_80110000039b6fd8
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),2,0x18,
                                                                       0x101000000000000);
                                                    *(long *)(param_1 + 0x120) = lVar8;
                                                    if (lVar8 != 0) {
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (lVar8,0x504d555f52430000,0);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0,
                                                                 0x4e4f4e4500000000);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,1,
                                                                 0x475055305f544800);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,2,
                                                                 0x475055315f544800);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,3,
                                                                 0x475055325f544800);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,4,
                                                                 0x475055335f544800);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,5,
                                                                 0x475055345f544800);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,6,
                                                                 0x475055355f544800);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,7,
                                                                 0x475055365f544800);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,8,
                                                                 0x475055375f544800);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,9,
                                                                 0x414652305f544800);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,10,
                                                                 0x414652315f544800);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0xb,
                                                                 0x475055305f454d54);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0xc,
                                                                 0x475055315f454d54);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0xd,
                                                                 0x475055325f454d54);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0xe,
                                                                 0x475055335f454d54);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0xf,
                                                                 0x475055345f454d54);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0x10,
                                                                 0x475055355f454d54);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0x11,
                                                                 0x475055365f454d54);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0x12,
                                                                 0x475055375f454d54);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0x13,
                                                                 0x414652305f454d54);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0x14,
                                                                 0x414652315f454d54);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0x15,
                                                                 0x464142305f544800);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0x16,
                                                                 0x464142305f454d54);
                                                      thunk_EXT_FUN_80110000039b7850
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,0x17,
                                                                 0x494e56414c494400);
                                                      thunk_EXT_FUN_80110000039b74c8
                                                                (*(undefined8 *)(param_1 + 0x120),
                                                                 0x504d555f52430000,
                                                                 0x4e4f4e4500000000,0,1,0);
                                                      *(undefined8 *)(param_1 + 0x598) =
                                                           0x4e4f4e4500000000;
                                                      uVar9 = thunk_EXT_FUN_8011000003397c88();
                                                      *(undefined8 *)(param_1 + 0x5a0) = uVar9;
                                                      thunk_EXT_FUN_80110000039ba158
                                                                (*(undefined8 *)(param_1 + 0x10),
                                                                 *(undefined8 *)(param_1 + 0x120),
                                                                 "GPU Stats",
                                                                                                                                  
                                                  "PMU Loop Lost Performance Reason Code States");
                                                  iVar6 = (**(code **)(**(long **)(param_1 + 0x20) +
                                                                      0xf0))(*(long **)(param_1 +
                                                                                       0x20),
                                                                             *(undefined8 *)
                                                                              (param_1 + 0x120));
                                                  if (iVar6 != 0) {
                                                    uVar9 = thunk_EXT_FUN_80110000039b6fd8
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),2,0xb,
                                                                       0x101000000000000);
                                                    *(undefined8 *)(param_1 + 0x130) = uVar9;
                                                    thunk_EXT_FUN_80110000039b41ec
                                                              (uVar9,0x4750555f50504d00,0);
                                                    thunk_EXT_FUN_80110000039b7850
                                                              (*(undefined8 *)(param_1 + 0x130),
                                                               0x4750555f50504d00,0,
                                                               0x302d392500000000);
                                                    thunk_EXT_FUN_80110000039b7850
                                                              (*(undefined8 *)(param_1 + 0x130),
                                                               0x4750555f50504d00,1,
                                                               0x31302d3139250000);
                                                    thunk_EXT_FUN_80110000039b7850
                                                              (*(undefined8 *)(param_1 + 0x130),
                                                               0x4750555f50504d00,2,
                                                               0x32302d3239250000);
                                                    thunk_EXT_FUN_80110000039b7850
                                                              (*(undefined8 *)(param_1 + 0x130),
                                                               0x4750555f50504d00,3,
                                                               0x33302d3339250000);
                                                    thunk_EXT_FUN_80110000039b7850
                                                              (*(undefined8 *)(param_1 + 0x130),
                                                               0x4750555f50504d00,4,
                                                               0x34302d3439250000);
                                                    thunk_EXT_FUN_80110000039b7850
                                                              (*(undefined8 *)(param_1 + 0x130),
                                                               0x4750555f50504d00,5,
                                                               0x35302d3539250000);
                                                    thunk_EXT_FUN_80110000039b7850
                                                              (*(undefined8 *)(param_1 + 0x130),
                                                               0x4750555f50504d00,6,
                                                               0x36302d3639250000);
                                                    thunk_EXT_FUN_80110000039b7850
                                                              (*(undefined8 *)(param_1 + 0x130),
                                                               0x4750555f50504d00,7,
                                                               0x37302d3739250000);
                                                    thunk_EXT_FUN_80110000039b7850
                                                              (*(undefined8 *)(param_1 + 0x130),
                                                               0x4750555f50504d00,8,
                                                               0x38302d3839250000);
                                                    thunk_EXT_FUN_80110000039b7850
                                                              (*(undefined8 *)(param_1 + 0x130),
                                                               0x4750555f50504d00,9,
                                                               0x39302d3939250000);
                                                    thunk_EXT_FUN_80110000039b7850
                                                              (*(undefined8 *)(param_1 + 0x130),
                                                               0x4750555f50504d00,10,
                                                               0x3130302500000000);
                                                    thunk_EXT_FUN_80110000039b7668
                                                              (*(undefined8 *)(param_1 + 0x130),
                                                               0x3130302500000000);
                                                    if (((*(long *)(param_1 + 0x130) != 0) &&
                                                        (iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                           (*(undefined8 *)
                                                                             (param_1 + 0x10),
                                                                            *(long *)(param_1 +
                                                                                     0x130),
                                                                            "GPU Stats",
                                                                                                                                                        
                                                  "PPM Target as % of Max GPU Power"), iVar6 == 0))
                                                  && (iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                      0x20) + 0xf0))
                                                                        (*(long **)(param_1 + 0x20),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0x130)),
                                                     iVar6 != 0)) {
                                                    uStack_c8 = _UNK_fffffff007115c08;
                                                    local_d0 = _DAT_fffffff007115c00;
                                                    uStack_b8 = _UNK_fffffff007115c18;
                                                    uStack_c0 = _DAT_fffffff007115c10;
                                                    lVar8 = thunk_EXT_FUN_80110000039b8dac
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),2,
                                                                       0x55545f454e474147,
                                                                       "GPU UT Engagement centi-%",0
                                                                       ,2,&local_d0);
                                                    *(long *)(param_1 + 0x138) = lVar8;
                                                    if (((lVar8 != 0) &&
                                                        (iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                           (*(undefined8 *)
                                                                             (param_1 + 0x10),lVar8,
                                                                            "GPU Stats",
                                                                                                                                                        
                                                  "UT Engagement centi-% Histogram"), iVar6 == 0))
                                                  && (iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                      0x20) + 0xf0))
                                                                        (*(long **)(param_1 + 0x20),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0x138)),
                                                     iVar6 != 0)) {
                                                    lVar8 = 0;
                                                    do {
                                                      local_80 = local_80 & 0xffffffffffff0000;
                                                      uStack_98 = 0;
                                                      local_a0 = 0;
                                                      uStack_88 = 0;
                                                      local_90 = 0;
                                                      uStack_a8 = 0;
                                                      local_b0 = 0;
                                                      lVar10 = lVar8;
                                                      thunk_EXT_FUN_80110000037693ec
                                                                (&local_b0,0x32,
                                                                                                                                  
                                                  "UT Engagement centi-%% Histogram for perf state %u"
                                                  );
                                                  lVar10 = thunk_EXT_FUN_80110000039b8dac
                                                                     (*(undefined8 *)
                                                                       (param_1 + 0x10),2,
                                                                      *(undefined8 *)
                                                                       (param_1 + 0x1498 + lVar8 * 8
                                                                       ),"GPU UT Engagement centi-%"
                                                                      ,0,2,&local_d0,in_x7,lVar10);
                                                  *(long *)(param_1 + 0x140 + lVar8 * 8) = lVar10;
                                                  if (((lVar10 == 0) ||
                                                      (iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                         (*(undefined8 *)
                                                                           (param_1 + 0x10),lVar10,
                                                                          "GPU UT Engagement",
                                                                          &local_b0), iVar6 != 0))
                                                     || (uVar19 = (**(code **)(**(long **)(param_1 +
                                                                                          0x20) +
                                                                              0xf0))(*(long **)(
                                                  param_1 + 0x20),
                                                  *(undefined8 *)(param_1 + 0x140 + lVar8 * 8)),
                                                  (uVar19 & 1) == 0)) goto LAB_fffffff0082081c4;
                                                  lVar8 = lVar8 + 1;
                                                  } while (lVar8 != 0x10);
                                                  lVar8 = 0;
                                                  uStack_118 = _UNK_fffffff007113d98;
                                                  local_120 = _DAT_fffffff007113d90;
                                                  do {
                                                    local_80 = local_80 & 0xffffffffffff0000;
                                                    uStack_98 = 0;
                                                    local_a0 = 0;
                                                    uStack_88 = 0;
                                                    local_90 = 0;
                                                    uStack_a8 = 0;
                                                    local_b0 = 0;
                                                    lVar10 = lVar8;
                                                    thunk_EXT_FUN_80110000037693ec
                                                              (&local_b0,0x32,
                                                                                                                              
                                                  "AVMR Offset Histogram for perf state %u");
                                                  lVar10 = thunk_EXT_FUN_80110000039b8dac
                                                                     (*(undefined8 *)
                                                                       (param_1 + 0x10),2,
                                                                      *(undefined8 *)
                                                                       (param_1 + 0x1518 + lVar8 * 8
                                                                       ),"GPU AVMR Offset",0,1,
                                                                      &local_120,in_x7,lVar10);
                                                  *(long *)(param_1 + 0x460 + lVar8 * 8) = lVar10;
                                                  if (((lVar10 == 0) ||
                                                      (iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                         (*(undefined8 *)
                                                                           (param_1 + 0x10),lVar10,
                                                                          "AVMR Offset",&local_b0),
                                                      iVar6 != 0)) ||
                                                     (uVar19 = (**(code **)(**(long **)(param_1 +
                                                                                       0x20) + 0xf0)
                                                               )(*(long **)(param_1 + 0x20),
                                                                 *(undefined8 *)
                                                                  (param_1 + 0x460 + lVar8 * 8)),
                                                     (uVar19 & 1) == 0)) goto LAB_fffffff0082081c4;
                                                  lVar8 = lVar8 + 1;
                                                  } while (lVar8 != 0x10);
                                                  lVar10 = 0;
                                                  lVar8 = param_1 + 0x1c0;
                                                  lVar13 = param_1 + 0x15b8;
                                                  local_80 = local_80 & 0xffffffffffff0000;
                                                  uStack_98 = 0;
                                                  local_a0 = 0;
                                                  uStack_88 = 0;
                                                  local_90 = 0;
                                                  uStack_a8 = 0;
                                                  local_b0 = 0;
                                                  do {
                                                    thunk_EXT_FUN_80110000037693ec
                                                              (&local_b0,0x32,"AGX.%s_%s_%u");
                                                    lVar11 = thunk_EXT_FUN_80110000039b54c0
                                                                       (*(undefined8 *)
                                                                         (param_1 + 0x10),0x100,0);
                                                    *(long *)(lVar8 + lVar10 * 8) = lVar11;
                                                    if (lVar11 == 0) goto LAB_fffffff0082081c4;
                                                    thunk_EXT_FUN_80110000039b41ec
                                                              (lVar11,*(undefined8 *)
                                                                       (lVar13 + lVar10 * 8),
                                                               &local_b0);
                                                    thunk_EXT_FUN_80110000039b5574
                                                              (*(undefined8 *)(lVar8 + lVar10 * 8),
                                                               *(undefined8 *)(lVar13 + lVar10 * 8),
                                                               0);
                                                    thunk_EXT_FUN_80110000039ba158
                                                              (*(undefined8 *)(param_1 + 0x10),
                                                               *(undefined8 *)(lVar8 + lVar10 * 8),
                                                               "GPU UT AggD Stats",
                                                               *(undefined8 *)(param_1 + 0x1598));
                                                    uVar19 = (**(code **)(**(long **)(param_1 + 0x20
                                                                                     ) + 0xf0))
                                                                       (*(long **)(param_1 + 0x20),
                                                                        *(undefined8 *)
                                                                         (lVar8 + lVar10 * 8));
                                                    if ((uVar19 & 1) == 0)
                                                    goto LAB_fffffff0082081c4;
                                                    lVar10 = lVar10 + 1;
                                                  } while (lVar10 != 0x10);
                                                  lVar10 = 0;
                                                  local_80 = local_80 & 0xffffffffffff0000;
                                                  uStack_98 = 0;
                                                  local_a0 = 0;
                                                  uStack_88 = 0;
                                                  local_90 = 0;
                                                  uStack_a8 = 0;
                                                  local_b0 = 0;
                                                  do {
                                                    thunk_EXT_FUN_80110000037693ec
                                                              (&local_b0,0x32,"AGX.%s_%s_%u");
                                                    lVar12 = thunk_EXT_FUN_80110000039b54c0
                                                                       (*(undefined8 *)
                                                                         (param_1 + 0x10),0x100,0);
                                                    lVar11 = lVar10 * 8 + 0x80;
                                                    *(long *)(lVar8 + lVar11) = lVar12;
                                                    if (lVar12 == 0) goto LAB_fffffff0082081c4;
                                                    thunk_EXT_FUN_80110000039b41ec
                                                              (lVar12,*(undefined8 *)
                                                                       (lVar13 + lVar11),&local_b0);
                                                    thunk_EXT_FUN_80110000039b5574
                                                              (*(undefined8 *)(lVar8 + lVar11),
                                                               *(undefined8 *)(lVar13 + lVar11),0);
                                                    thunk_EXT_FUN_80110000039ba158
                                                              (*(undefined8 *)(param_1 + 0x10),
                                                               *(undefined8 *)(lVar8 + lVar11),
                                                               "GPU UT AggD Stats",
                                                               *(undefined8 *)(param_1 + 0x15a0));
                                                    iVar6 = (**(code **)(**(long **)(param_1 + 0x20)
                                                                        + 0xf0))
                                                                      (*(long **)(param_1 + 0x20),
                                                                       *(undefined8 *)
                                                                        (lVar8 + lVar11));
                                                    if (iVar6 == 0) goto LAB_fffffff0082081c4;
                                                    lVar10 = lVar10 + 1;
                                                  } while (lVar10 != 0x10);
                                                  lVar10 = 0;
                                                  local_80 = local_80 & 0xffffffffffff0000;
                                                  uStack_98 = 0;
                                                  local_a0 = 0;
                                                  uStack_88 = 0;
                                                  local_90 = 0;
                                                  uStack_a8 = 0;
                                                  local_b0 = 0;
                                                  do {
                                                    thunk_EXT_FUN_80110000037693ec
                                                              (&local_b0,0x32,"AGX.%s_%s_%u");
                                                    lVar12 = thunk_EXT_FUN_80110000039b54c0
                                                                       (*(undefined8 *)
                                                                         (param_1 + 0x10),0x100,0);
                                                    lVar11 = lVar10 * 8 + 0x100;
                                                    *(long *)(lVar8 + lVar11) = lVar12;
                                                    if (lVar12 == 0) goto LAB_fffffff0082081c4;
                                                    thunk_EXT_FUN_80110000039b41ec
                                                              (lVar12,*(undefined8 *)
                                                                       (lVar13 + lVar11),&local_b0);
                                                    thunk_EXT_FUN_80110000039b5574
                                                              (*(undefined8 *)(lVar8 + lVar11),
                                                               *(undefined8 *)(lVar13 + lVar11),0);
                                                    thunk_EXT_FUN_80110000039ba158
                                                              (*(undefined8 *)(param_1 + 0x10),
                                                               *(undefined8 *)(lVar8 + lVar11),
                                                               "GPU UT AggD Stats",
                                                               *(undefined8 *)(param_1 + 0x15a8));
                                                    iVar6 = (**(code **)(**(long **)(param_1 + 0x20)
                                                                        + 0xf0))
                                                                      (*(long **)(param_1 + 0x20),
                                                                       *(undefined8 *)
                                                                        (lVar8 + lVar11));
                                                    if (iVar6 == 0) goto LAB_fffffff0082081c4;
                                                    lVar10 = lVar10 + 1;
                                                  } while (lVar10 != 0x10);
                                                  lVar10 = 0;
                                                  local_80 = local_80 & 0xffffffffffff0000;
                                                  uStack_98 = 0;
                                                  local_a0 = 0;
                                                  uStack_88 = 0;
                                                  local_90 = 0;
                                                  uStack_a8 = 0;
                                                  local_b0 = 0;
                                                  do {
                                                    thunk_EXT_FUN_80110000037693ec
                                                              (&local_b0,0x32,"AGX.%s_%s_%u");
                                                    lVar12 = thunk_EXT_FUN_80110000039b54c0
                                                                       (*(undefined8 *)
                                                                         (param_1 + 0x10),0x100,0);
                                                    lVar11 = lVar10 * 8 + 0x180;
                                                    *(long *)(lVar8 + lVar11) = lVar12;
                                                    if (lVar12 == 0) goto LAB_fffffff0082081c4;
                                                    thunk_EXT_FUN_80110000039b41ec
                                                              (lVar12,*(undefined8 *)
                                                                       (lVar13 + lVar11),&local_b0);
                                                    thunk_EXT_FUN_80110000039b5574
                                                              (*(undefined8 *)(lVar8 + lVar11),
                                                               *(undefined8 *)(lVar13 + lVar11),0);
                                                    thunk_EXT_FUN_80110000039ba158
                                                              (*(undefined8 *)(param_1 + 0x10),
                                                               *(undefined8 *)(lVar8 + lVar11),
                                                               "GPU UT AggD Stats",
                                                               *(undefined8 *)(param_1 + 0x15b0));
                                                    iVar6 = (**(code **)(**(long **)(param_1 + 0x20)
                                                                        + 0xf0))
                                                                      (*(long **)(param_1 + 0x20),
                                                                       *(undefined8 *)
                                                                        (lVar8 + lVar11));
                                                    if (iVar6 == 0) goto LAB_fffffff0082081c4;
                                                    lVar10 = lVar10 + 1;
                                                  } while (lVar10 != 0x10);
                                                  lVar10 = 0;
                                                  lVar8 = param_1 + 0x3c0;
                                                  do {
                                                    local_80 = local_80 & 0xffffffffffff0000;
                                                    uStack_98 = 0;
                                                    local_a0 = 0;
                                                    uStack_88 = 0;
                                                    local_90 = 0;
                                                    uStack_a8 = 0;
                                                    local_b0 = 0;
                                                    thunk_EXT_FUN_80110000037693ec
                                                              (&local_b0,0x32,"%s_%u");
                                                    lVar13 = thunk_EXT_FUN_80110000039b54c0
                                                                       (*(undefined8 *)
                                                                         (param_1 + 0x10),0x100,0);
                                                    *(long *)(lVar8 + lVar10 * 8) = lVar13;
                                                    if (lVar13 == 0) goto LAB_fffffff0082081c4;
                                                    thunk_EXT_FUN_80110000039b41ec
                                                              (lVar13,*(undefined8 *)
                                                                       (param_1 + 0x17b8 +
                                                                       lVar10 * 8),&local_b0);
                                                    thunk_EXT_FUN_80110000039b5574
                                                              (*(undefined8 *)(lVar8 + lVar10 * 8),
                                                               *(undefined8 *)
                                                                (param_1 + 0x17b8 + lVar10 * 8),0);
                                                    thunk_EXT_FUN_80110000039ba158
                                                              (*(undefined8 *)(param_1 + 0x10),
                                                               *(undefined8 *)(lVar8 + lVar10 * 8),
                                                               "GPU UT AggD Stats",
                                                               "Not_Engaged_Count");
                                                    uVar19 = (**(code **)(**(long **)(param_1 + 0x20
                                                                                     ) + 0xf0))
                                                                       (*(long **)(param_1 + 0x20),
                                                                        *(undefined8 *)
                                                                         (lVar8 + lVar10 * 8));
                                                    if ((uVar19 & 1) == 0)
                                                    goto LAB_fffffff0082081c4;
                                                    lVar10 = lVar10 + 1;
                                                  } while (lVar10 != 0x10);
                                                  uStack_a8 = _UNK_fffffff007115c28;
                                                  local_b0 = _DAT_fffffff007115c20;
                                                  uStack_98 = _UNK_fffffff007115c38;
                                                  local_a0 = _DAT_fffffff007115c30;
                                                  uStack_88 = _UNK_fffffff007115c48;
                                                  local_90 = _DAT_fffffff007115c40;
                                                  lVar8 = thunk_EXT_FUN_80110000039b8dac
                                                                    (*(undefined8 *)(param_1 + 0x10)
                                                                     ,4,0x5350494c4c425546,
                                                                     "Spill Buffer Usage",
                                                                     0x9008c0000000000,3,&local_b0);
                                                  *(long *)(param_1 + 0xe8) = lVar8;
                                                  if (((lVar8 != 0) &&
                                                      (iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                         (*(undefined8 *)
                                                                           (param_1 + 0x10),lVar8,
                                                                          "GPU Stats",
                                                                                                                                                    
                                                  "Spill Buffer Usage Histogram"), iVar6 == 0)) &&
                                                  (iVar6 = (**(code **)(**(long **)(param_1 + 0x20)
                                                                       + 0xf0))
                                                                     (*(long **)(param_1 + 0x20),
                                                                      *(undefined8 *)
                                                                       (param_1 + 0xe8)), iVar6 != 0
                                                  )) {
                                                    uStack_f8 = _UNK_fffffff007115c58;
                                                    local_100 = _DAT_fffffff007115c50;
                                                    uStack_e8 = _UNK_fffffff007115c68;
                                                    uStack_f0 = _DAT_fffffff007115c60;
                                                    uStack_d8 = _UNK_fffffff007115c78;
                                                    local_e0 = _DAT_fffffff007115c70;
                                                    lVar8 = thunk_EXT_FUN_80110000039b8dac
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),4,
                                                                       0x53504d4554414441,
                                                                       "Spill Buffer Metadata Usage"
                                                                       ,0x9008c0000000000,3,
                                                                       &local_100);
                                                    *(long *)(param_1 + 0xf0) = lVar8;
                                                    if (((lVar8 != 0) &&
                                                        (iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                           (*(undefined8 *)
                                                                             (param_1 + 0x10),lVar8,
                                                                            "GPU Stats",
                                                                                                                                                        
                                                  "Spill Buffer Metadata Usage Histogram"),
                                                  iVar6 == 0)) &&
                                                  (iVar6 = (**(code **)(**(long **)(param_1 + 0x20)
                                                                       + 0xf0))
                                                                     (*(long **)(param_1 + 0x20),
                                                                      *(undefined8 *)
                                                                       (param_1 + 0xf0)), iVar6 != 0
                                                  )) {
                                                    uStack_108 = _UNK_fffffff007113d98;
                                                    local_110 = _DAT_fffffff007113d90;
                                                    lVar8 = thunk_EXT_FUN_80110000039b8dac
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),4,
                                                                       0x5350554e55534544,
                                                                                                                                              
                                                  "Spill Buffer Unused Blocks per Task",0,1,
                                                  &local_110);
                                                  *(long *)(param_1 + 0xf8) = lVar8;
                                                  if (((lVar8 != 0) &&
                                                      (iVar6 = thunk_EXT_FUN_80110000039ba158
                                                                         (*(undefined8 *)
                                                                           (param_1 + 0x10),lVar8,
                                                                          "GPU Stats",
                                                                                                                                                    
                                                  "Spill Buffer Metadata Unused Blocks Per Task Histogram"
                                                  ), iVar6 == 0)) &&
                                                  (uVar19 = (**(code **)(**(long **)(param_1 + 0x20)
                                                                        + 0xf0))
                                                                      (*(long **)(param_1 + 0x20),
                                                                       *(undefined8 *)
                                                                        (param_1 + 0xf8)),
                                                  (uVar19 & 1) != 0)) {
                                                    lVar8 = thunk_EXT_FUN_80110000039b54c0
                                                                      (*(undefined8 *)
                                                                        (param_1 + 0x10),0x102,0);
                                                    *(long *)(param_1 + 0x448) = lVar8;
                                                    if (lVar8 != 0) {
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (lVar8,0x4857504900000000,
                                                                 "Throttle Counter HWPI ");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4450450000000000,
                                                                 "Throttle Counter DPE  ");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4d49534300000000,
                                                                 "Throttle Counter Misc ");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4956444d00000000,
                                                                 "Throttle Counter IVDM ");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x544f54414c000000,
                                                                 "Throttle Counter Total");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4331505054000000,
                                                                 "Throttle Counter C1PPT   ");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4558544153594e43,
                                                                 "Throttle Counter ExtAsync");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x5554000000000000,
                                                                 "Throttle Counter UT      ");
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4956444d5f4d494e,
                                                                 "IVDM: Min Active Throttle Percent"
                                                                );
                                                      thunk_EXT_FUN_80110000039b41ec
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4956444d5f4d4158,
                                                                 "IVDM: Max Throttle Percent       "
                                                                );
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4857504900000000,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4450450000000000,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4d49534300000000,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4956444d00000000,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x544f54414c000000,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4331505054000000,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4558544153594e43,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x5554000000000000,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4956444d5f4d494e,0);
                                                      thunk_EXT_FUN_80110000039b5574
                                                                (*(undefined8 *)(param_1 + 0x448),
                                                                 0x4956444d5f4d4158,0);
                                                      thunk_EXT_FUN_80110000039ba158
                                                                (*(undefined8 *)(param_1 + 0x10),
                                                                 *(undefined8 *)(param_1 + 0x448),
                                                                 "GPU Stats",
                                                                 "GPU Throttler Counters");
                                                      iVar6 = (**(code **)(**(long **)(param_1 +
                                                                                      0x20) + 0xf0))
                                                                        (*(long **)(param_1 + 0x20),
                                                                         *(undefined8 *)
                                                                          (param_1 + 0x448));
                                                      if (iVar6 != 0) {
                                                        plVar18 = *(long **)(param_1 + 0x10);
                                                        uVar9 = thunk_EXT_FUN_80110000039ba14c
                                                                          (plVar7);
                                                        (**(code **)(*plVar18 + 200))
                                                                  (plVar18,"IOReportLegend",uVar9);
                                                        (**(code **)(**(long **)(param_1 + 0x10) +
                                                                    0xd8))(*(long **)(param_1 + 0x10
                                                                                     ),
                                                                           "IOReportLegendPublic",1)
                                                        ;
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
                        else {
                          lVar8 = thunk_EXT_FUN_80110000039b6fd8(lVar8,2,0x10,0x101000000000000);
                          *(long *)(param_1 + 0x440) = lVar8;
                          if (lVar8 != 0) {
                            thunk_EXT_FUN_80110000039b41ec(lVar8,0x4750555f53570000,0);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,0,
                                       0x53575f4f46460000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,1,
                                       0x53575f5031000000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,2,
                                       0x53575f5032000000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,3,
                                       0x53575f5033000000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,4,
                                       0x53575f5034000000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,5,
                                       0x53575f5035000000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,6,
                                       0x53575f5036000000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,7,
                                       0x53575f5037000000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,8,
                                       0x53575f5038000000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,9,
                                       0x53575f5039000000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,10,
                                       0x53575f5031300000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,0xb,
                                       0x53575f5031310000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,0xc,
                                       0x53575f5031320000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,0xd,
                                       0x53575f5031330000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,0xe,
                                       0x53575f5031340000);
                            thunk_EXT_FUN_80110000039b7850
                                      (*(undefined8 *)(param_1 + 0x440),0x4750555f53570000,0xf,
                                       0x53575f5031350000);
                            *(undefined4 *)(param_1 + 0xfe0) = 0;
                            uVar9 = thunk_EXT_FUN_8011000003397c88();
                            *(undefined8 *)(param_1 + 0xfe8) = uVar9;
                            thunk_EXT_FUN_80110000039ba158
                                      (*(undefined8 *)(param_1 + 0x10),
                                       *(undefined8 *)(param_1 + 0x440),"GPU Stats",
                                       "GPU Software Performance States");
                            iVar6 = (**(code **)(**(long **)(param_1 + 0x20) + 0xf0))
                                              (*(long **)(param_1 + 0x20),
                                               *(undefined8 *)(param_1 + 0x440));
                            if (iVar6 != 0) {
                              lVar8 = *(long *)(param_1 + 0x10);
                              goto LAB_fffffff008204d8c;
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
          else {
            lVar8 = thunk_EXT_FUN_80110000039b54c0(lVar8,2,10);
            *(long *)(param_1 + 0xc0) = lVar8;
            if (lVar8 != 0) {
              thunk_EXT_FUN_80110000039b41ec(lVar8,0x54454d5053554d00,"Average Sum");
              thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xc0),0x54454d5053554d00,0);
              thunk_EXT_FUN_80110000039b41ec
                        (*(undefined8 *)(param_1 + 0xc0),0x54454d50434e5400,"Average Sum Count");
              thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xc0),0x54454d50434e5400,0);
              thunk_EXT_FUN_80110000039b41ec
                        (*(undefined8 *)(param_1 + 0xc0),0x54454d504d494e00,"Min");
              thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xc0),0x54454d504d494e00,0);
              thunk_EXT_FUN_80110000039b41ec
                        (*(undefined8 *)(param_1 + 0xc0),0x54454d504d415800,"Max");
              thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xc0),0x54454d504d415800,0);
              uVar5 = _UNK_fffffff007113d18;
              uVar4 = _DAT_fffffff007113d10;
              uVar3 = _UNK_fffffff007113d08;
              uVar9 = _DAT_fffffff007113d00;
              lVar8 = *(long *)(param_1 + 0x10);
              uVar19 = *(ulong *)(lVar8 + 0x105f8);
              if (uVar19 != 0) {
                uVar16 = (uVar19 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar19 & 0x5555555555555555) << 1;
                uVar16 = (uVar16 & 0xcccccccccccccccc) >> 2 | (uVar16 & 0x3333333333333333) << 2;
                uVar16 = (uVar16 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar16 & 0xf0f0f0f0f0f0f0f) << 4;
                uVar16 = (uVar16 & 0xff00ff00ff00ff00) >> 8 | (uVar16 & 0xff00ff00ff00ff) << 8;
                uVar16 = (uVar16 & 0xffff0000ffff0000) >> 0x10 | (uVar16 & 0xffff0000ffff) << 0x10;
                uVar15 = LZCOUNT(uVar16 >> 0x20 | uVar16 << 0x20);
                uVar16 = uVar15;
                do {
                  local_80 = local_80 & 0xffffffffffff0000;
                  uStack_98 = 0;
                  local_a0 = 0;
                  uStack_88 = 0;
                  local_90 = 0;
                  uStack_a8 = 0;
                  local_b0 = 0;
                  iVar6 = (int)(uVar16 / 10);
                  uVar14 = iVar6 + 0x30;
                  uVar17 = (uint)uVar16;
                  uVar2 = uVar17 + iVar6 * -10 | 0x30;
                  uVar16 = (ulong)uVar2 | (ulong)uVar14 << 8;
                  lVar8 = uVar15 * 0x28;
                  puVar1 = (undefined8 *)(param_1 + 0x5e0 + (long)(int)lVar8);
                  if (lVar8 - (int)lVar8 != 0) {
                    puVar1 = (undefined8 *)
                             (param_1 + 0x5e0 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
                  }
                  bVar20 = (byte)uVar2;
                  bVar21 = (byte)(uVar16 >> 8);
                  bVar22 = (byte)(uVar16 >> 0x10);
                  bVar23 = (byte)(uVar16 >> 0x18);
                  bVar24 = (byte)(uVar14 >> 0x18);
                  puVar1[1] = CONCAT17((char)((ulong)uVar3 >> 0x38),
                                       CONCAT16((char)((ulong)uVar3 >> 0x30),
                                                CONCAT15((char)((ulong)uVar3 >> 0x28),
                                                         CONCAT14(bVar24 | (byte)((ulong)uVar3 >>
                                                                                 0x20),
                                                                  CONCAT13(bVar23 | (byte)((ulong)
                                                  uVar3 >> 0x18),
                                                  CONCAT12(bVar22 | (byte)((ulong)uVar3 >> 0x10),
                                                           CONCAT11(bVar21 | (byte)((ulong)uVar3 >>
                                                                                   8),
                                                                    bVar20 | (byte)uVar3)))))));
                  *puVar1 = CONCAT17((char)((ulong)uVar9 >> 0x38),
                                     CONCAT16((char)((ulong)uVar9 >> 0x30),
                                              CONCAT15((char)((ulong)uVar9 >> 0x28),
                                                       CONCAT14(bVar24 | (byte)((ulong)uVar9 >> 0x20
                                                                               ),
                                                                CONCAT13(bVar23 | (byte)((ulong)
                                                  uVar9 >> 0x18),
                                                  CONCAT12(bVar22 | (byte)((ulong)uVar9 >> 0x10),
                                                           CONCAT11(bVar21 | (byte)((ulong)uVar9 >>
                                                                                   8),
                                                                    bVar20 | (byte)uVar9)))))));
                  puVar1[3] = CONCAT17((char)((ulong)uVar5 >> 0x38),
                                       CONCAT16((char)((ulong)uVar5 >> 0x30),
                                                CONCAT15((char)((ulong)uVar5 >> 0x28),
                                                         CONCAT14(bVar24 | (byte)((ulong)uVar5 >>
                                                                                 0x20),
                                                                  CONCAT13(bVar23 | (byte)((ulong)
                                                  uVar5 >> 0x18),
                                                  CONCAT12(bVar22 | (byte)((ulong)uVar5 >> 0x10),
                                                           CONCAT11(bVar21 | (byte)((ulong)uVar5 >>
                                                                                   8),
                                                                    bVar20 | (byte)uVar5)))))));
                  puVar1[2] = CONCAT17((char)((ulong)uVar4 >> 0x38),
                                       CONCAT16((char)((ulong)uVar4 >> 0x30),
                                                CONCAT15((char)((ulong)uVar4 >> 0x28),
                                                         CONCAT14(bVar24 | (byte)((ulong)uVar4 >>
                                                                                 0x20),
                                                                  CONCAT13(bVar23 | (byte)((ulong)
                                                  uVar4 >> 0x18),
                                                  CONCAT12(bVar22 | (byte)((ulong)uVar4 >> 0x10),
                                                           CONCAT11(bVar21 | (byte)((ulong)uVar4 >>
                                                                                   8),
                                                                    bVar20 | (byte)uVar4)))))));
                  puVar1[4] = uVar16 | 0x4d54435552000000;
                  thunk_EXT_FUN_80110000037693ec(&local_b0,0x32,"Tg%ua Latest");
                  thunk_EXT_FUN_80110000039b41ec
                            (*(undefined8 *)(param_1 + 0xc0),puVar1[4],&local_b0);
                  thunk_EXT_FUN_80110000037693ec(&local_b0,0x32,"Tg%ua Sum");
                  thunk_EXT_FUN_80110000039b41ec(*(undefined8 *)(param_1 + 0xc0),*puVar1,&local_b0);
                  thunk_EXT_FUN_80110000037693ec(&local_b0,0x32,"Tg%ua Sum Count");
                  thunk_EXT_FUN_80110000039b41ec
                            (*(undefined8 *)(param_1 + 0xc0),puVar1[1],&local_b0);
                  thunk_EXT_FUN_80110000037693ec(&local_b0,0x32,"Tg%ua Min");
                  thunk_EXT_FUN_80110000039b41ec
                            (*(undefined8 *)(param_1 + 0xc0),puVar1[2],&local_b0);
                  thunk_EXT_FUN_80110000037693ec(&local_b0,0x32,"Tg%ua Max");
                  thunk_EXT_FUN_80110000039b41ec
                            (*(undefined8 *)(param_1 + 0xc0),puVar1[3],&local_b0);
                  thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xc0),*puVar1,0);
                  thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xc0),puVar1[1],0);
                  thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xc0),puVar1[2],0);
                  thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xc0),puVar1[3],0);
                  thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1 + 0xc0),puVar1[4],0);
                  uVar16 = 0;
                  if ((uVar17 & 0x3f) != 0x3f) {
                    uVar16 = -1L << ((ulong)((uVar17 & 0x3f) + 1) & 0x3f);
                  }
                  uVar16 = uVar19 & uVar16;
                  uVar15 = (uVar16 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar16 & 0x5555555555555555) << 1;
                  uVar15 = (uVar15 & 0xcccccccccccccccc) >> 2 | (uVar15 & 0x3333333333333333) << 2;
                  uVar15 = (uVar15 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar15 & 0xf0f0f0f0f0f0f0f) << 4;
                  uVar15 = (uVar15 & 0xff00ff00ff00ff00) >> 8 | (uVar15 & 0xff00ff00ff00ff) << 8;
                  uVar15 = (uVar15 & 0xffff0000ffff0000) >> 0x10 | (uVar15 & 0xffff0000ffff) << 0x10
                  ;
                  uVar14 = (uint)LZCOUNT(uVar15 >> 0x20 | uVar15 << 0x20);
                  if (uVar16 == 0) {
                    uVar14 = 0xffffffff;
                  }
                  uVar2 = uVar14 + (uVar17 & 0xffffffc0);
                  uVar16 = (ulong)uVar2;
                  if (0x7fffffff < uVar14) {
                    uVar2 = 0xffffffff;
                  }
                  uVar15 = (ulong)uVar2;
                } while (uVar2 != 0xffffffff);
                lVar8 = *(long *)(param_1 + 0x10);
              }
              iVar6 = thunk_EXT_FUN_80110000039ba158
                                (lVar8,*(undefined8 *)(param_1 + 0xc0),"GPU Stats","Temperature");
              if ((iVar6 == 0) &&
                 (iVar6 = (**(code **)(**(long **)(param_1 + 0x20) + 0xf0))
                                    (*(long **)(param_1 + 0x20),*(undefined8 *)(param_1 + 0xc0)),
                 iVar6 != 0)) {
                lVar8 = *(long *)(param_1 + 0x10);
                goto LAB_fffffff008204558;
              }
            }
          }
        }
      }
    }
  }
LAB_fffffff0082081c4:
  (**(code **)(*plVar7 + 0x28))(plVar7);
LAB_fffffff0082081e4:
  if (*(long *)PTR_DAT_fffffff007ca61a0 != local_70) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

