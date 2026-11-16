// FUN_fffffff009a7fdfc @ fffffff009a7fdfc size=1204
// CALLERS:
//   fffffff00afb818d no-fn
//   fffffff009a816c8 FUN_fffffff009a80844@fffffff009a80844
// CALLEES:
//   fffffff009a9a7d0 thunk_EXT_FUN_8011000002c2671c
//   fffffff009a9a7e0 thunk_EXT_FUN_8011000002c24af0
//   fffffff009a99bc0 thunk_EXT_FUN_80110000038fe9a0
//   fffffff009a802b0 FUN_fffffff009a802b0
//   fffffff009a9a8a0 thunk_EXT_FUN_80110000036da494
//   fffffff009a9a7b0 thunk_EXT_FUN_8011000002c1e264
//   fffffff009a7f68c FUN_fffffff009a7f68c
//   fffffff009a9a760 thunk_EXT_FUN_8011000002c1e3bc
//   fffffff009a9a670 thunk_EXT_FUN_8011000002c2371c
//   fffffff009a9a750 thunk_EXT_FUN_8011000002c1e35c
//   fffffff009a99fe0 thunk_EXT_FUN_8011000002c150fc

undefined4 FUN_fffffff009a7fdfc(long *param_1,undefined8 *param_2,long *param_3,undefined8 *param_4)

{
  ulong uVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  long lVar13;
  long lVar14;
  ulong uVar15;
  uint uVar16;
  char *in_stack_ffffffffffffff10;
  undefined4 local_c4;
  long local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  ulong uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  
  if ((*(byte *)((long)param_3 + 0x625) & 1) == 0) {
    if ((param_3[0x1a5] == 0) && ((*(byte *)((long)param_2 + 0x34f) & 1) == 0)) {
      lVar7 = thunk_EXT_FUN_8011000002c150fc(param_1);
      param_3[0x1a5] = lVar7;
    }
    uVar15 = 0;
    local_c4 = 0;
    do {
      if (param_3[uVar15 + 0x170] == 0) {
        uVar9 = 1L << (uVar15 & 0x3f);
        if ((uVar9 & *(uint *)((long)param_2 + 0x14c)) != 0) {
          *(uint *)(param_2 + 0x2a) = *(uint *)(param_2 + 0x2a) | (uint)uVar9;
        }
      }
      else {
        uVar3 = *(undefined4 *)(param_2 + 0x13);
        uVar4 = thunk_EXT_FUN_8011000002c1e35c();
        (**(code **)(*param_3 + 0x20))(param_3);
        (**(code **)(*(long *)param_3[uVar15 + 0x170] + 0x20))();
        if ((int)(param_3 + uVar15 * 3 + 0x18a)[1] == 0) {
          thunk_EXT_FUN_80110000036da494(0x31800308,uVar3,uVar15,uVar4,0,0);
          in_stack_ffffffffffffff10 =
               (char *)((ulong)in_stack_ffffffffffffff10 & 0xffffffff00000000);
          iVar5 = thunk_EXT_FUN_8011000002c2371c
                            (param_3[uVar15 + 0x170],param_3[0x1a5],param_3 + uVar15 + 0x16c,1,0,
                             FUN_fffffff009a7ed6c,param_1,param_3,in_stack_ffffffffffffff10);
          if (iVar5 == 0) goto LAB_fffffff009a8022c;
          thunk_EXT_FUN_80110000036da494(0x3180030c,uVar3,uVar15,uVar4,0,0);
          thunk_EXT_FUN_80110000036da494(0x31800551,uVar3,uVar15,uVar4,0,0);
LAB_fffffff009a7ffec:
          uVar8 = thunk_EXT_FUN_8011000002c2671c(param_3[uVar15 + 0x170]);
          uVar9 = param_2[6];
          if (uVar9 == 0) {
            uVar9 = (**(code **)(*param_1 + 0x7e8))(param_1);
          }
          uVar1 = uVar8;
          if (uVar9 <= uVar8) {
            uVar1 = uVar9;
          }
          if (uVar8 != 0) {
            uVar9 = uVar1;
          }
          param_2[6] = uVar9;
          uVar8 = param_3[0x79];
          if ((ulong)param_3[0x79] <= uVar9) {
            uVar8 = uVar9;
          }
          param_3[0x79] = uVar8;
          plVar12 = (long *)param_1[0x77];
          if (plVar12 != (long *)0x0) {
            local_68 = 0;
            local_a0 = (ulong)*(uint *)(param_2 + 0x13) << 0x20;
            local_70 = *param_2;
            uStack_98 = param_2[1];
            uStack_88 = param_2[4];
            local_90 = param_2[3];
            local_80 = param_2[5];
            uStack_78 = uVar9;
            (**(code **)(*plVar12 + 0x80))(plVar12,uVar15,param_3[uVar15 + 0x170],&local_a0);
            *param_4 = local_68;
            local_c4 = 1;
          }
          *(undefined1 *)((long)param_3 + uVar15 + 0x626) = 0;
          if ((*(byte *)((long)param_1 + 0x5861) & 1) != 0) {
            lVar7 = param_3[uVar15 + 0x170];
            plVar12 = (long *)thunk_EXT_FUN_8011000002c1e264(lVar7);
            plVar12 = (long *)(**(code **)(*plVar12 + 0xe8))(plVar12,0);
            if (plVar12 != (long *)0x0) {
              lVar10 = (**(code **)(*plVar12 + 0x78))();
              if ((lVar10 != 0) && (iVar5 = thunk_EXT_FUN_8011000002c1e3bc(lVar7), iVar5 != 0)) {
                uVar16 = 0;
                do {
                  lVar11 = thunk_EXT_FUN_8011000002c24af0(lVar7,uVar16);
                  if ((lVar11 != 0) && (*(char *)(lVar11 + 0x20) != '\0')) {
                    lVar13 = 0;
                    lVar11 = lVar10 + (ulong)*(uint *)(lVar11 + 8);
                    lVar14 = 0x10;
                    do {
                      pcVar2 = (char *)(lVar11 + (int)lVar13);
                      if (lVar13 != (int)lVar13) {
                        pcVar2 = (char *)(lVar11 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
                      }
                      if (*pcVar2 != '\0') goto LAB_fffffff009a801a4;
                      lVar13 = lVar13 + 1;
                      lVar14 = lVar14 + -1;
                    } while (lVar14 != 0);
                    thunk_EXT_FUN_8011000002c1e35c(lVar7);
                    in_stack_ffffffffffffff10 = "swap_apply_fences";
                    thunk_EXT_FUN_80110000038fe9a0
                              (
                              "IOMFB: [%s] SurfaceID 0x%x GP Decompression Error Debug - Detected 16 bytes of zero values in metadata buffer \n"
                              );
                  }
LAB_fffffff009a801a4:
                  uVar16 = uVar16 + 1;
                  uVar6 = thunk_EXT_FUN_8011000002c1e3bc(lVar7);
                } while (uVar16 < uVar6);
              }
              (**(code **)(*plVar12 + 0x28))(plVar12);
            }
          }
          *(uint *)(param_2 + 0x2a) = *(uint *)(param_2 + 0x2a) | 1 << (ulong)((uint)uVar15 & 0x1f);
          (**(code **)(*(long *)param_3[uVar15 + 0x170] + 0x28))();
          (**(code **)(*param_3 + 0x28))(param_3);
        }
        else {
          iVar5 = FUN_fffffff009a7f68c
                            (param_1,param_3 + uVar15 * 3 + 0x18a,param_3[uVar15 + 0x170],param_3,
                             uVar15,1,0,1);
          if (iVar5 != 0) goto LAB_fffffff009a7ffec;
LAB_fffffff009a8022c:
          *(undefined1 *)((long)param_3 + uVar15 + 0x626) = 1;
        }
        *(undefined1 *)((long)param_3 + 0x625) = 1;
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 != 4);
    plVar12 = (long *)param_3[0x1a5];
    if ((*(byte *)((long)param_3 + 0x625) & 1) == 0) {
      if (plVar12 != (long *)0x0) {
        (**(code **)(*plVar12 + 0x28))();
      }
      param_3[0x1a5] = 0;
    }
    else if (plVar12 != (long *)0x0) {
      FUN_fffffff009a802b0(param_1);
    }
  }
  else {
    local_c4 = 0;
  }
  return local_c4;
}

