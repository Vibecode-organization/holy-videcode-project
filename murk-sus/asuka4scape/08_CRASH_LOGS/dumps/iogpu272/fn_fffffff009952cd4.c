// FUN_fffffff009952cd4 @ fffffff009952cd4 size=820

long * FUN_fffffff009952cd4
                 (long *param_1,long param_2,undefined4 param_3,long param_4,ulong param_5,
                 ulong param_6,undefined8 *param_7)

{
  undefined8 *puVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  long *plVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  ulong uVar12;
  long local_68;
  
  if (((param_4 == 0) || ((param_5 & 0xf0ffffffffffffff) == 0)) ||
     ((param_6 & 0xf0ffffffffffffff) == 0)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: invalid arguments\n");
    plVar3 = (long *)0x0;
  }
  else {
    puVar1 = (undefined8 *)PTR_DAT_fffffff007ff2830;
    if (param_2 != 0) {
      puVar1 = (undefined8 *)(param_2 + 0x50);
    }
    uVar11 = *puVar1;
    plVar3 = (long *)(**(code **)(*param_1 + 0x5b0))();
    if (plVar3 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: createResource failed\n");
    }
    else {
      thunk_EXT_FUN_80110000032977b0(uVar11);
      iVar2 = thunk_EXT_FUN_80110000032ed234();
      lVar10 = (long)iVar2;
      lVar9 = *(long *)PTR_DAT_fffffff007ff2838;
      uVar5 = (param_4 + lVar10 + (ulong)((uint)param_6 & iVar2 - 1U)) - 1 & -lVar10;
      if (lVar9 != iVar2) {
        uVar5 = (param_4 + lVar10 + (ulong)(iVar2 - 1U & (uint)param_6)) - 1 & (long)-iVar2;
      }
      uVar12 = -lVar10 & param_6 & 0xf0ffffffffffffff;
      lVar4 = FUN_fffffff009980714(param_1,uVar11,0,uVar12,uVar5);
      plVar3[5] = lVar4;
      if (lVar4 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: fMemory is NULL.\n");
        (**(code **)(*plVar3 + 0x28))(plVar3);
        plVar3 = (long *)0x0;
      }
      else {
        plVar3[9] = (param_5 & 0xf0ffffffffffffff) - uVar12;
        if (lVar9 != lVar10) {
          uVar11 = FUN_fffffff009981d00();
          local_68 = 0;
          uVar5 = thunk_EXT_FUN_8011000003977d8c(uVar11,&local_68);
          plVar3[9] = plVar3[9] + local_68;
        }
        plVar3[0xf] = uVar5;
        if (param_2 == 0) {
          *(uint *)(plVar3 + 2) = *(uint *)(plVar3 + 2) | 0x400;
        }
        else {
          uVar8 = *(uint *)(plVar3 + 2) | 0x200;
          *(uint *)(plVar3 + 2) = uVar8;
          plVar7 = plVar3;
          while ((uVar8 & 0xff) == 0x82) {
            plVar7 = (long *)plVar7[6];
            uVar8 = *(uint *)(plVar7 + 2);
          }
          if (((uVar8 & 0xff) == 0x40) || ((uVar8 & 0xf) != 0)) {
            lVar9 = 0;
          }
          else {
            lVar9 = plVar7[0xf];
          }
          FUN_fffffff00996647c(param_2,lVar9);
        }
        if (param_7 != (undefined8 *)0x0) {
          *param_7 = 0;
        }
        if (param_2 == 0) {
          thunk_EXT_FUN_80110000036da494(0x8509001c,0,plVar3[0xe],param_3,plVar3[0xf],0);
          uVar11 = 0;
        }
        else {
          thunk_EXT_FUN_80110000036da494
                    (0x8509001c,*(undefined8 *)(param_2 + 0x38),plVar3[0xe],param_3,plVar3[0xf],0);
          uVar11 = *(undefined8 *)(param_2 + 0x38);
        }
        lVar9 = plVar3[0xe];
        uVar6 = FUN_fffffff0099529c0(plVar3);
        local_68 = 0;
        thunk_EXT_FUN_80110000032db760(uVar6,&local_68);
        thunk_EXT_FUN_80110000036da494(0x85090020,uVar11,lVar9,param_3,local_68,0);
      }
    }
  }
  return plVar3;
}

