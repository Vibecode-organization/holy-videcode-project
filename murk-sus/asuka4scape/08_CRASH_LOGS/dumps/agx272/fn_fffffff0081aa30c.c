// FUN_fffffff0081aa30c @ fffffff0081aa30c size=3772

/* WARNING: Removing unreachable block (ram,0xfffffff0081ab060) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ab0dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081aac20) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081aad98) */

void FUN_fffffff0081aa30c(long *param_1)

{
  ulong uVar1;
  long **pplVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  long *plVar6;
  long *plVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  long *local_328;
  long *local_320;
  long **pplStack_318;
  long *local_310;
  long *plStack_308;
  long **local_300;
  long *local_2f8;
  long *plStack_2f0;
  long **local_2e8;
  long *local_2e0;
  long *plStack_2d8;
  long **local_2d0;
  long *local_2c8;
  long *plStack_2c0;
  long **local_2b8;
  long *local_2b0;
  long *plStack_2a8;
  long **local_2a0;
  long *local_298;
  long *plStack_290;
  long **local_288;
  long *plStack_280;
  long *local_278;
  long **pplStack_270;
  long *local_268;
  long *plStack_260;
  long **local_258;
  long *plStack_250;
  long *local_248;
  long **pplStack_240;
  long *local_238;
  long *plStack_230;
  long **local_228;
  long *plStack_220;
  long *local_218;
  long **pplStack_210;
  long *local_208;
  long *plStack_200;
  long **local_1f8;
  long *plStack_1f0;
  long *local_1e8;
  long **pplStack_1e0;
  long *local_1d8;
  long *plStack_1d0;
  long **local_1c8;
  long *plStack_1c0;
  long *local_1b8;
  long **pplStack_1b0;
  long *local_1a8;
  long *plStack_1a0;
  long **local_198;
  long *plStack_190;
  long *local_188;
  long **pplStack_180;
  long *local_178;
  long *plStack_170;
  long **local_168;
  long *plStack_160;
  long *local_158;
  long **pplStack_150;
  long *local_148;
  long *plStack_140;
  undefined8 local_138;
  long *plStack_130;
  long *local_128;
  undefined8 uStack_120;
  long *local_118;
  long *local_110;
  undefined8 local_108;
  long *local_100;
  long *local_f8;
  undefined8 local_f0;
  long *local_e8;
  long *local_e0;
  undefined8 local_d8;
  long *local_d0;
  long *local_c8;
  long **local_c0;
  long *local_b8;
  long *local_b0;
  undefined8 local_a8;
  long *local_a0;
  long *local_98;
  long **pplStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  long local_78;
  
  local_78 = *(long *)PTR_DAT_fffffff007ca61a0;
  lVar8 = param_1[0x50];
  iVar3 = *(int *)(lVar8 + 0x11140);
  if (iVar3 == 0) {
    iVar3 = *(int *)(lVar8 + 0x610);
  }
  (**(code **)(param_1[0x1a8] + 0x20))(param_1 + 0x1a8,lVar8,0x18,"AGFITimeStampQueue",9,0,0,0);
  uVar5 = (**(code **)(param_1[0x1a8] + 0x30))(param_1 + 0x1a8);
  if ((int)uVar5 == 0) goto LAB_fffffff0081ab130;
  (**(code **)(param_1[0x21b] + 0x20))
            (param_1 + 0x21b,param_1[0x50],8,"LateEvalEventSignal",9,0,0,0);
  uVar5 = (**(code **)(param_1[0x21b] + 0x30))(param_1 + 0x21b);
  if ((int)uVar5 == 0) goto LAB_fffffff0081ab130;
  (**(code **)(param_1[0x191] + 0x20))
            (param_1 + 0x191,param_1[0x50],0x2cc0,"AGFIChannelState",9,1,0,0);
  uVar5 = (**(code **)(param_1[0x191] + 0x30))(param_1 + 0x191);
  if ((int)uVar5 == 0) goto LAB_fffffff0081ab130;
  lVar8 = param_1[0x50];
  uVar4 = *(uint *)(lVar8 + 0x11140);
  if (uVar4 == 0) {
    uVar4 = *(uint *)(lVar8 + 0x610);
  }
  uVar10 = (ulong)(uVar4 & 0xfffffff) << 7 | 0x60;
  (**(code **)(param_1[0x1bf] + 0x20))
            (param_1 + 0x1bf,lVar8,uVar10,"UncachedFWChannelMemory",9,0,0,0);
  uVar5 = (**(code **)(param_1[0x1bf] + 0x30))(param_1 + 0x1bf);
  if ((int)uVar5 == 0) goto LAB_fffffff0081ab130;
  (**(code **)(param_1[0x1d6] + 0x20))
            (param_1 + 0x1d6,param_1[0x50],uVar10,"CachedFWChannelMemory",9,1,0,0);
  uVar5 = (**(code **)(param_1[0x1d6] + 0x30))(param_1 + 0x1d6);
  if ((int)uVar5 == 0) goto LAB_fffffff0081ab130;
  (**(code **)(*param_1 + 0x7f0))(param_1);
  lVar12 = param_1[0x43];
  param_1[0x236] = lVar12;
  lVar8 = param_1[0x50];
  param_1[0x232] = lVar8;
  uVar4 = *(uint *)PTR_DAT_fffffff007ca5f88;
  plVar6 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))();
  uVar5 = 0;
  if (plVar6 == (long *)0x0) goto LAB_fffffff0081ab130;
  uVar10 = (ulong)(uint)(iVar3 * 3);
  lVar9 = (long)(1 << (ulong)(uVar4 & 0x1f));
  uVar11 = (lVar9 + lVar12 * uVar10) - 1 & -lVar9;
  uVar4 = *(uint *)(lVar8 + 0x18b70);
  plVar6[2] = *(long *)PTR_DAT_fffffff007ca61d0;
  iVar3 = FUN_fffffff0081e07cc(plVar6,lVar8,uVar11,uVar4 | 0x23);
  if (iVar3 != 0) {
    lVar8 = thunk_EXT_FUN_8011000002971b4c(lVar8);
    plVar7 = (long *)plVar6[0xb];
    if (plVar7 == (long *)0x0) {
      plVar7 = (long *)(**(code **)(*(long *)plVar6[9] + 0x90))((long *)plVar6[9],lVar8,0x500000085)
      ;
      if (plVar7 == (long *)0x0) goto LAB_fffffff0081ab16c;
      (**(code **)(*plVar7 + 0x20))();
      (**(code **)(*plVar7 + 0x28))(plVar7);
      plVar6[0xb] = (long)plVar7;
    }
    if (plVar7[4] != lVar8) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Attempting to map into multiple GPU Contexts!\n");
      return;
    }
    lVar8 = (**(code **)(*plVar7 + 0x98))();
    if (lVar8 != 0) {
      plVar7 = (long *)plVar6[10];
      if (plVar7 == (long *)0x0) {
        plVar7 = (long *)(**(code **)(*(long *)plVar6[9] + 0x90))
                                   ((long *)plVar6[9],plVar6[3],0x20900000084);
        if (plVar7 == (long *)0x0) goto LAB_fffffff0081ab16c;
        (**(code **)(*plVar7 + 0x20))();
        (**(code **)(*plVar7 + 0x28))(plVar7);
        plVar6[10] = (long)plVar7;
      }
      lVar8 = (**(code **)(*plVar7 + 0x98))();
      if (lVar8 != 0) {
        plVar7 = (long *)plVar6[0xc];
        if (plVar7 == (long *)0x0) {
          lVar8 = thunk_EXT_FUN_801100000297ea14(plVar6[9],0);
          plVar6[0xc] = lVar8;
          if (lVar8 == 0) goto LAB_fffffff0081ab16c;
          LOAcquire();
          DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar6[6];
          LORelease();
          plVar7 = (long *)plVar6[0xc];
        }
        lVar8 = (**(code **)(*plVar7 + 0x78))();
        if (lVar8 != 0) {
          param_1[0x233] = (long)plVar6;
          lVar8 = (**(code **)(*(long *)plVar6[0xc] + 0x78))();
          param_1[0x234] = lVar8;
          if (lVar8 != 0) {
            uVar1 = 0;
            if (param_1[0x236] != 0) {
              uVar1 = uVar11 / (ulong)param_1[0x236];
            }
            *(int *)(param_1 + 0x237) = (int)uVar1;
            lVar8 = thunk_EXT_FUN_80110000038fe5cc(uVar1 & 0xffffffff);
            param_1[0x235] = lVar8;
            if (lVar8 != 0) {
              param_1[0x23e] = param_1[0x44];
              uVar5 = FUN_fffffff0081ab1c8(param_1 + 0x23a,uVar10,param_1[0x50]);
              if ((int)uVar5 != 0) {
                param_1[0x246] = param_1[0x45];
                uVar5 = FUN_fffffff0081ab1c8(param_1 + 0x242,uVar10,param_1[0x50]);
                if ((int)uVar5 != 0) {
                  param_1[0x24e] = param_1[0x46];
                  uVar5 = FUN_fffffff0081ab1c8(param_1 + 0x24a,uVar10,param_1[0x50]);
                  if ((int)uVar5 != 0) {
                    iVar3 = *(int *)(param_1[0x50] + 0x11140);
                    if (iVar3 == 0) {
                      iVar3 = *(int *)(param_1[0x50] + 0x610);
                    }
                    param_1[0x256] = param_1[0x47];
                    uVar5 = FUN_fffffff0081ab514(param_1 + 0x252,iVar3 * 0x87);
                    if ((int)uVar5 != 0) {
                      param_1[0x25e] = param_1[0x49];
                      uVar5 = FUN_fffffff0081ab514(param_1 + 0x25a,uVar10,param_1[0x50]);
                      if ((int)uVar5 != 0) {
                        param_1[0x266] = param_1[0x4a];
                        uVar5 = FUN_fffffff0081ab514(param_1 + 0x262,uVar10,param_1[0x50]);
                        if ((int)uVar5 != 0) {
                          param_1[0x26e] = param_1[0x4b];
                          uVar5 = FUN_fffffff0081ab514(param_1 + 0x26a,uVar10,param_1[0x50]);
                          if ((int)uVar5 != 0) {
                            param_1[0x276] = param_1[0x4d];
                            uVar5 = FUN_fffffff0081ab514(param_1 + 0x272,uVar10,param_1[0x50]);
                            if ((int)uVar5 != 0) {
                              param_1[0x27e] = param_1[0x4e];
                              uVar5 = FUN_fffffff0081ab514(param_1 + 0x27a,uVar10,param_1[0x50]);
                              if ((int)uVar5 != 0) {
                                param_1[0x286] = param_1[0x4f];
                                uVar5 = FUN_fffffff0081ab514(param_1 + 0x282,uVar10,param_1[0x50]);
                                if ((int)uVar5 != 0) {
                                  plVar6 = param_1 + 2;
                                  (**(code **)*plVar6)(plVar6,param_1[0x50],0);
                                  uVar5 = FUN_fffffff0082027ec(plVar6,0x340,(int)param_1[0x237]);
                                  if ((int)uVar5 != 0) {
                                    plVar6 = param_1 + 0x12;
                                    (**(code **)*plVar6)(plVar6,param_1[0x50],1);
                                    uVar5 = FUN_fffffff0082027ec
                                                      (plVar6,0x680,
                                                       (int)param_1[0x247] + (int)param_1[0x23f]);
                                    if ((int)uVar5 != 0) {
                                      (**(code **)param_1[0x22])(param_1 + 0x22,param_1[0x50],2);
                                      uVar5 = FUN_fffffff0082027ec
                                                        (param_1 + 0x22,0x340,(int)param_1[0x24f]);
                                      if ((int)uVar5 != 0) {
                                        (**(code **)param_1[0x32])(param_1 + 0x32,param_1[0x50],2);
                                        uVar5 = FUN_fffffff0082027ec
                                                          (param_1 + 0x32,0x50,
                                                           (int)param_1[0x277] + (int)param_1[0x26f]
                                                          );
                                        pplVar2 = DAT_fffffff007113f10;
                                        if ((int)uVar5 != 0) {
                                          uStack_120 = 0;
                                          local_128 = (long *)0x0;
                                          plStack_130 = (long *)0x0;
                                          local_138 = 0;
                                          plStack_140 = (long *)0x0;
                                          local_148 = (long *)0x0;
                                          pplStack_150 = (long **)0x0;
                                          local_158 = (long *)0x0;
                                          plStack_160 = (long *)0x0;
                                          local_168 = (long **)0x0;
                                          plStack_170 = (long *)0x0;
                                          local_178 = (long *)0x0;
                                          pplStack_180 = (long **)0x0;
                                          local_188 = (long *)0x0;
                                          plStack_190 = (long *)0x0;
                                          local_198 = (long **)0x0;
                                          plStack_1a0 = (long *)0x0;
                                          local_1a8 = (long *)0x0;
                                          pplStack_1b0 = (long **)0x0;
                                          local_1b8 = (long *)0x0;
                                          plStack_1c0 = (long *)0x0;
                                          local_1c8 = (long **)0x0;
                                          plStack_1d0 = (long *)0x0;
                                          local_1d8 = (long *)0x0;
                                          pplStack_1e0 = (long **)0x0;
                                          local_1e8 = (long *)0x0;
                                          plStack_1f0 = (long *)0x0;
                                          local_1f8 = (long **)0x0;
                                          plStack_200 = (long *)0x0;
                                          local_208 = (long *)0x0;
                                          pplStack_210 = (long **)0x0;
                                          local_218 = (long *)0x0;
                                          plStack_220 = (long *)0x0;
                                          local_228 = (long **)0x0;
                                          plStack_230 = (long *)0x0;
                                          local_238 = (long *)0x0;
                                          pplStack_240 = (long **)0x0;
                                          local_248 = (long *)0x0;
                                          plStack_250 = (long *)0x0;
                                          local_258 = (long **)0x0;
                                          plStack_260 = (long *)0x0;
                                          local_268 = (long *)0x0;
                                          pplStack_270 = (long **)0x0;
                                          local_278 = (long *)0x0;
                                          plStack_280 = (long *)0x0;
                                          local_288 = (long **)0x0;
                                          local_328 = param_1 + 0x54;
                                          local_320 = param_1 + 0x5c;
                                          pplStack_318 = DAT_fffffff007113ee8;
                                          local_310 = param_1 + 0x55;
                                          plStack_308 = param_1 + 0x5d;
                                          local_300 = DAT_fffffff007113ef0;
                                          local_2f8 = param_1 + 0x56;
                                          plStack_2f0 = param_1 + 0x5e;
                                          local_2e8 = DAT_fffffff007113ef8;
                                          local_2e0 = param_1 + 0x57;
                                          plStack_2d8 = param_1 + 0x5f;
                                          local_2d0 = DAT_fffffff007113f00;
                                          local_2c8 = param_1 + 0x58;
                                          plStack_2c0 = param_1 + 0x60;
                                          local_2b8 = DAT_fffffff007113f08;
                                          local_2b0 = param_1 + 0x59;
                                          plStack_2a8 = param_1 + 0x61;
                                          local_2a0 = DAT_fffffff007113f10;
                                          local_298 = param_1 + 0x5a;
                                          plStack_290 = param_1 + 0x62;
                                          uVar4 = (**(code **)(*(long *)param_1[0x50] + 0xba0))
                                                            (*(long *)param_1[0x50] + 0xba0);
                                          local_288 = (long **)(ulong)uVar4;
                                          plStack_280 = param_1 + 0x5b;
                                          local_278 = param_1 + 99;
                                          pplStack_270 = DAT_fffffff007113f18;
                                          local_268 = param_1 + 0x81;
                                          plStack_260 = param_1 + 0x82;
                                          local_258 = DAT_fffffff007113f20;
                                          plStack_250 = param_1 + 0x7c;
                                          local_248 = param_1 + 0x7d;
                                          pplStack_240 = DAT_fffffff007113f20;
                                          local_238 = param_1 + 0x77;
                                          plStack_230 = param_1 + 0x78;
                                          local_228 = DAT_fffffff007113f20;
                                          plStack_220 = param_1 + 0x72;
                                          local_218 = param_1 + 0x73;
                                          pplStack_210 = DAT_fffffff007113f20;
                                          local_208 = param_1 + 0x95;
                                          plStack_200 = param_1 + 0x96;
                                          local_1f8 = DAT_fffffff007113f20;
                                          plStack_1f0 = param_1 + 0x90;
                                          local_1e8 = param_1 + 0x91;
                                          pplStack_1e0 = DAT_fffffff007113f20;
                                          local_1d8 = param_1 + 0x8b;
                                          plStack_1d0 = param_1 + 0x8c;
                                          local_1c8 = DAT_fffffff007113f20;
                                          plStack_1c0 = param_1 + 0x86;
                                          local_1b8 = param_1 + 0x87;
                                          pplStack_1b0 = DAT_fffffff007113f20;
                                          local_1a8 = param_1 + 0xa9;
                                          plStack_1a0 = param_1 + 0xaa;
                                          local_198 = DAT_fffffff007113f20;
                                          plStack_190 = param_1 + 0xa4;
                                          local_188 = param_1 + 0xa5;
                                          pplStack_180 = DAT_fffffff007113f20;
                                          local_178 = param_1 + 0x9f;
                                          plStack_170 = param_1 + 0xa0;
                                          local_168 = DAT_fffffff007113f20;
                                          plStack_160 = param_1 + 0x9a;
                                          local_158 = param_1 + 0x9b;
                                          pplStack_150 = DAT_fffffff007113f20;
                                          local_148 = param_1 + 0x101;
                                          plStack_140 = param_1 + 0x105;
                                          local_138 = DAT_fffffff007113f28;
                                          plStack_130 = param_1 + 0x10c;
                                          local_128 = param_1 + 0x10d;
                                          uStack_120 = DAT_fffffff007113f30;
                                          uStack_80 = 0;
                                          local_a0 = param_1 + 100;
                                          local_98 = (long *)0x1;
                                          local_88 = 0x16;
                                          pplStack_90 = &local_328;
                                          uVar5 = (**(code **)(*param_1 + 0x7c0))
                                                            (*param_1 + 0x7c0,param_1,&local_a0,0);
                                          if ((int)uVar5 != 0) {
                                            param_1[0x102] = param_1[0x101] + 0x20;
                                            param_1[0x103] = param_1[0x101] + 0x1c0;
                                            lVar8 = param_1[0x5a];
                                            uVar5 = (**(code **)(*(long *)param_1[0x50] + 0xba0))();
                                            thunk_EXT_FUN_8011000003a61cc0(lVar8,uVar5);
                                            local_328 = param_1 + 0x7f;
                                            local_320 = param_1 + 0x80;
                                            pplStack_318 = DAT_fffffff007113f38;
                                            local_310 = param_1 + 0x7a;
                                            plStack_308 = param_1 + 0x7b;
                                            local_300 = DAT_fffffff007113f38;
                                            local_2f8 = param_1 + 0x75;
                                            plStack_2f0 = param_1 + 0x76;
                                            local_2e8 = DAT_fffffff007113f38;
                                            local_2e0 = param_1 + 0x70;
                                            plStack_2d8 = param_1 + 0x71;
                                            local_2d0 = DAT_fffffff007113f38;
                                            local_2c8 = param_1 + 0x93;
                                            plStack_2c0 = param_1 + 0x94;
                                            local_2b8 = DAT_fffffff007113f38;
                                            local_2b0 = param_1 + 0x8e;
                                            plStack_2a8 = param_1 + 0x8f;
                                            local_2a0 = DAT_fffffff007113f38;
                                            local_298 = param_1 + 0x89;
                                            plStack_290 = param_1 + 0x8a;
                                            local_288 = DAT_fffffff007113f38;
                                            plStack_280 = param_1 + 0x84;
                                            local_278 = param_1 + 0x85;
                                            pplStack_270 = DAT_fffffff007113f38;
                                            local_268 = param_1 + 0xa7;
                                            plStack_260 = param_1 + 0xa8;
                                            local_258 = DAT_fffffff007113f38;
                                            plStack_250 = param_1 + 0xa2;
                                            local_248 = param_1 + 0xa3;
                                            pplStack_240 = DAT_fffffff007113f38;
                                            local_238 = param_1 + 0x9d;
                                            plStack_230 = param_1 + 0x9e;
                                            local_228 = DAT_fffffff007113f38;
                                            plStack_220 = param_1 + 0x98;
                                            local_218 = param_1 + 0x99;
                                            pplStack_210 = DAT_fffffff007113f38;
                                            local_208 = param_1 + 0x10a;
                                            plStack_200 = param_1 + 0x10b;
                                            local_1f8 = DAT_fffffff007113f38;
                                            plStack_1f0 = param_1 + 0x122;
                                            local_1e8 = param_1 + 0x124;
                                            pplStack_1e0 = DAT_fffffff007113f40;
                                            local_1d8 = param_1 + 0x123;
                                            plStack_1d0 = param_1 + 0x125;
                                            local_1c8 = DAT_fffffff007113f48;
                                            plStack_1c0 = param_1 + 0x107;
                                            local_1b8 = param_1 + 0x108;
                                            pplStack_1b0 = DAT_fffffff007113f50;
                                            local_1a8 = param_1 + 0x10e;
                                            plStack_1a0 = param_1 + 0x116;
                                            local_198 = DAT_fffffff007113f38;
                                            plStack_190 = param_1 + 0x10f;
                                            local_188 = param_1 + 0x117;
                                            pplStack_180 = DAT_fffffff007113f58;
                                            local_178 = param_1 + 0x110;
                                            plStack_170 = param_1 + 0x118;
                                            local_168 = DAT_fffffff007113f38;
                                            plStack_160 = param_1 + 0x111;
                                            local_158 = param_1 + 0x119;
                                            pplStack_150 = DAT_fffffff007113f38;
                                            local_148 = param_1 + 0x112;
                                            plStack_140 = param_1 + 0x11a;
                                            plStack_130 = param_1 + 0x113;
                                            local_128 = param_1 + 0x11b;
                                            uStack_120 = DAT_fffffff007113f68;
                                            local_118 = param_1 + 0x104;
                                            local_110 = param_1 + 0x106;
                                            local_108 = DAT_fffffff007113f70;
                                            local_100 = param_1 + 0x114;
                                            local_f8 = param_1 + 0x11c;
                                            local_f0 = DAT_fffffff007113f78;
                                            local_e8 = param_1 + 0x115;
                                            local_e0 = param_1 + 0x11d;
                                            local_d0 = param_1 + 0x6b;
                                            local_c8 = param_1 + 0x6c;
                                            local_b8 = param_1 + 0x6d;
                                            local_b0 = param_1 + 0x6e;
                                            local_138 = DAT_fffffff007113f60;
                                            local_d8 = DAT_fffffff007113f60;
                                            local_c0 = pplVar2;
                                            local_a8 = DAT_fffffff007113f80;
                                            local_98 = (long *)0x0;
                                            uStack_80 = 0;
                                            local_a0 = param_1 + 0xab;
                                            local_88 = 0x1b;
                                            pplStack_90 = &local_328;
                                            uVar10 = (**(code **)(*param_1 + 0x7c0))
                                                               (*param_1 + 0x7c0,param_1,&local_a0,0
                                                               );
                                            if ((uVar10 & 1) == 0) {
                                              uVar5 = 0;
                                            }
                                            else {
                                              local_a0 = param_1 + 0x69;
                                              local_98 = param_1 + 0x6a;
                                              pplStack_90 = DAT_fffffff007113f88;
                                              local_320 = (long *)0x0;
                                              plStack_308 = (long *)0x0;
                                              local_328 = param_1 + 0xac;
                                              local_310 = (long *)0x1;
                                              pplStack_318 = &local_a0;
                                              uVar5 = (**(code **)(*param_1 + 0x7c0))
                                                                (*param_1 + 0x7c0,param_1,&local_328
                                                                 ,1);
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
              goto LAB_fffffff0081ab130;
            }
            param_1[0x234] = 0;
          }
          (**(code **)(*(long *)param_1[0x233] + 0x28))();
          uVar5 = 0;
          param_1[0x233] = 0;
          goto LAB_fffffff0081ab130;
        }
      }
    }
  }
LAB_fffffff0081ab16c:
  (**(code **)(*plVar6 + 0x28))(plVar6);
  uVar5 = 0;
LAB_fffffff0081ab130:
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_78) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar5);
  return;
}

