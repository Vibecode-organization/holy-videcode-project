// FUN_fffffff009974c30 @ fffffff009974c30 size=772

long FUN_fffffff009974c30(long *param_1)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  long *plVar5;
  long *plVar6;
  int iVar7;
  
  plVar2 = (long *)FUN_fffffff00997b310(0x430);
  lVar3 = FUN_fffffff00997b324();
  if (lVar3 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: new IOGPUAllocationInfo failed\n");
    lVar3 = 0;
  }
  else {
    uVar4 = (**(code **)(*plVar2 + 0x78))(plVar2,param_1);
    if ((uVar4 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: alloc_info->init failed\n");
      lVar3 = 0;
    }
    else {
      FUN_fffffff0099620e8(param_1[0x2c],plVar2);
      (**(code **)(*param_1 + 0x690))(param_1,plVar2);
      thunk_EXT_FUN_8011000002c30b40(param_1[0x1f],plVar2,thunk_FUN_fffffff00997c3a4);
      plVar5 = (long *)FUN_fffffff009944a54(param_1[0x39]);
      if (plVar5 != (long *)0x0) {
        iVar1 = (**(code **)(*plVar5 + 0x90))();
        if (iVar1 != 0) {
          iVar7 = 0;
          do {
            plVar6 = (long *)(**(code **)(*plVar5 + 0x118))(plVar5,iVar7);
            (**(code **)(*plVar6 + 0xc0))(plVar6,plVar2);
            iVar7 = iVar7 + 1;
          } while (iVar1 != iVar7);
        }
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
      plVar5 = (long *)FUN_fffffff009944a54(param_1[0x3a]);
      if (plVar5 != (long *)0x0) {
        iVar1 = (**(code **)(*plVar5 + 0x90))();
        if (iVar1 != 0) {
          iVar7 = 0;
          do {
            plVar6 = (long *)(**(code **)(*plVar5 + 0x118))(plVar5,iVar7);
            FUN_fffffff0099709fc();
            (**(code **)(*plVar6 + 0xa0))(plVar6,plVar2);
            FUN_fffffff009970a08(plVar6);
            iVar7 = iVar7 + 1;
          } while (iVar1 != iVar7);
        }
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
      lVar3 = FUN_fffffff00997c288(plVar2);
      if (lVar3 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: IOGPUAllocationInfo->copyToArray returned nil\n");
      }
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return lVar3;
}

