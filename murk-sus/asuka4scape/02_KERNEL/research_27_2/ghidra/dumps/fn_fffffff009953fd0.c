// FUN_fffffff009953fd0 @ fffffff009953fd0 size=1296
// CALLERS:
//   fffffff00afb83a6 no-fn
//   fffffff00996712c FUN_fffffff0099669e0@fffffff0099669e0
// CALLEES:
//   fffffff009980b50 FUN_fffffff009980b50
//   fffffff009984fac thunk_EXT_FUN_80110000032ed234
//   fffffff00996647c FUN_fffffff00996647c
//   fffffff009981d00 FUN_fffffff009981d00
//   fffffff009984cec thunk_EXT_FUN_80110000032977b0
//   fffffff009984d2c thunk_EXT_FUN_80110000036da494
//   fffffff00998475c thunk_EXT_FUN_8011000003976e84
//   fffffff009984c2c thunk_EXT_FUN_80110000038db19c
//   fffffff00998477c thunk_EXT_FUN_801100000396cb64

long * FUN_fffffff009953fd0(long *param_1,long param_2,long *param_3,undefined4 *param_4)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long lVar10;
  long *plVar11;
  undefined4 uVar12;
  ulong uVar13;
  uint uVar14;
  ulong uVar15;
  undefined8 uVar16;
  
  if (*(long *)(param_4 + 6) != 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: disallowing protected resource\n");
    return (long *)0x0;
  }
  if (param_2 == 0) {
LAB_fffffff0099541bc:
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: invalid arguments\n");
    return (long *)0x0;
  }
  uVar13 = *(ulong *)(param_4 + 0xe);
  uVar2 = *(ulong *)(param_4 + 0x10);
  if ((uVar13 == 0 || uVar2 == 0) || 0xfffffffe < uVar2) goto LAB_fffffff0099541bc;
  uVar16 = *(undefined8 *)(param_2 + 0x50);
  plVar7 = (long *)(**(code **)(*param_1 + 0x5b0))(param_1,param_2,0x80);
  if (plVar7 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: createResource failed\n");
    return (long *)0x0;
  }
  thunk_EXT_FUN_80110000032977b0(uVar16);
  iVar6 = thunk_EXT_FUN_80110000032ed234();
  iVar3 = (int)*(long *)PTR_DAT_fffffff007ff2838;
  if (*(long *)PTR_DAT_fffffff007ff2838 != (long)iVar6) {
    iVar3 = iVar6;
  }
  uVar15 = (ulong)(iVar3 - 1U & (uint)uVar13);
  plVar8 = (long *)thunk_EXT_FUN_8011000003976e84
                             (uVar13 & -(long)iVar6,uVar15 + uVar2 * 0x10,0,uVar16);
  if (plVar8 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to create descriptor\n");
    plVar11 = (long *)0x0;
    goto LAB_fffffff00995449c;
  }
  plVar9 = (long *)(**(code **)(*plVar8 + 0xe8))(plVar8,0x1000);
  if (plVar9 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to create mapping\n");
    plVar11 = (long *)0x0;
  }
  else {
    lVar10 = (**(code **)(*plVar9 + 0x78))();
    bVar4 = (param_4[5] & 0x30) != 0;
    bVar5 = (param_4[5] & 0x20) == 0;
    bVar1 = bVar5 && bVar4;
    plVar11 = (long *)FUN_fffffff009980b50(param_1,uVar16,lVar10 + uVar15,uVar2,bVar1);
    if (plVar11 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to make allocation\n");
LAB_fffffff0099542bc:
      plVar11 = (long *)0x0;
    }
    else {
      uVar16 = FUN_fffffff009981d00();
      plVar7[5] = (long)plVar11;
      if (((uint)param_4[5] >> 0xd & 1) == 0) {
        if (((uint)param_4[5] >> 0xf & 1) == 0) {
          uVar12 = 0x1001;
          if (!bVar5 || !bVar4) {
            uVar12 = 1;
          }
          lVar10 = thunk_EXT_FUN_801100000396cb64
                             (uVar16,*(undefined8 *)(param_2 + 0x50),0,uVar12,0,0);
        }
        else {
          if (bVar1) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s: Refusing to create mapping for readonly memory\n");
            goto LAB_fffffff0099542bc;
          }
          lVar10 = (**(code **)(*param_1 + 0x5e0))(param_1,param_2,uVar16,param_4);
        }
        if (lVar10 == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to create client map\n")
          ;
          goto LAB_fffffff0099542bc;
        }
        plVar7[0x12] = lVar10;
        plVar11 = (long *)plVar7[5];
      }
      lVar10 = (**(code **)(*plVar11 + 0x88))(plVar11);
      plVar7[0xf] = lVar10;
      uVar14 = *(uint *)(plVar7 + 2) | 0x200;
      *(uint *)(plVar7 + 2) = uVar14;
      plVar11 = plVar7;
      while ((uVar14 & 0xff) == 0x82) {
        plVar11 = (long *)plVar11[6];
        uVar14 = *(uint *)(plVar11 + 2);
      }
      if (((uVar14 & 0xff) == 0x40) || ((uVar14 & 0xf) != 0)) {
        lVar10 = 0;
      }
      else {
        lVar10 = plVar11[0xf];
      }
      FUN_fffffff00996647c(param_2,lVar10);
      if (param_3 != (long *)0x0) {
        if ((long *)plVar7[0x12] == (long *)0x0) {
          lVar10 = 0;
        }
        else {
          lVar10 = (**(code **)(*(long *)plVar7[0x12] + 0x78))();
          if ((*(byte *)(plVar7 + 2) & 0x7f) == 0) {
            uVar13 = plVar7[9];
          }
          else if (*(byte *)(plVar7 + 2) == 0x82) {
            uVar13 = (ulong)*(uint *)((long)plVar7 + 0x4c);
          }
          else {
            uVar13 = 0;
          }
          lVar10 = uVar13 + lVar10;
        }
        *param_3 = lVar10;
      }
      thunk_EXT_FUN_80110000036da494
                (0x8509001c,*(undefined8 *)(param_2 + 0x38),plVar7[0xe],*param_4,plVar7[0xf],0);
      plVar11 = plVar7;
      plVar7 = (long *)0x0;
    }
    (**(code **)(*plVar9 + 0x28))();
  }
  (**(code **)(*plVar8 + 0x28))(plVar8);
  if (plVar7 == (long *)0x0) {
    return plVar11;
  }
LAB_fffffff00995449c:
  (**(code **)(*plVar7 + 0x28))(plVar7);
  return plVar11;
}

