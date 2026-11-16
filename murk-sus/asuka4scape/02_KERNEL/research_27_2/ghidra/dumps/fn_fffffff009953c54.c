// FUN_fffffff009953c54 @ fffffff009953c54 size=740
// CALLERS:
//   fffffff00afb83a2 no-fn
//   fffffff009966d28 FUN_fffffff0099669e0@fffffff0099669e0
// CALLEES:
//   fffffff009984bbc thunk_EXT_FUN_8011000002c1c364
//   fffffff0099745c4 FUN_fffffff0099745c4
//   fffffff0099529c0 FUN_fffffff0099529c0
//   fffffff00996647c FUN_fffffff00996647c
//   fffffff009984b5c thunk_EXT_FUN_8011000002c1e35c
//   fffffff009984f9c thunk_EXT_FUN_80110000032db760
//   fffffff009984b9c thunk_EXT_FUN_8011000002c1e4e8
//   fffffff009953f38 FUN_fffffff009953f38
//   fffffff009984d2c thunk_EXT_FUN_80110000036da494
//   fffffff009984bcc thunk_EXT_FUN_8011000002c1e410
//   fffffff009984c2c thunk_EXT_FUN_80110000038db19c

long FUN_fffffff009953c54
               (long *param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 local_48;
  
  lVar3 = thunk_EXT_FUN_8011000002c1c364(param_3);
  if (((param_2 == 0) || (lVar3 == 0)) || ((*(byte *)(param_2 + 0x40) >> 1 & 1) != 0)) {
    plVar4 = (long *)FUN_fffffff0099745c4(param_1,param_3,param_5);
    if (plVar4 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to create a device cache\n")
      ;
      lVar3 = 0;
    }
    else {
      lVar3 = (**(code **)(*param_1 + 0x5b0))(param_1,param_2,0x82);
      if (lVar3 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: allocIOGPUResource failed to alloc texture object\n");
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
      else {
        plVar4 = (long *)plVar4[4];
        *(undefined4 *)(lVar3 + 0x14) = *(undefined4 *)((long)plVar4 + 0x14);
        *(long **)(lVar3 + 0x30) = plVar4;
        *(int *)(lVar3 + 0x48) = (int)param_4;
        iVar1 = thunk_EXT_FUN_8011000002c1e410(param_3);
        iVar2 = thunk_EXT_FUN_8011000002c1e4e8(param_3,param_4);
        *(int *)(lVar3 + 0x4c) = iVar2 + iVar1;
        (**(code **)(*plVar4 + 0x20))(plVar4);
        uVar10 = *(uint *)(lVar3 + 0x10) | 0x200;
        *(uint *)(lVar3 + 0x10) = uVar10;
        lVar9 = lVar3;
        if (param_2 == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s: device handle is null and failed to add texture buffer size to device allocation size\n"
                    );
        }
        else {
          while ((uVar10 & 0xff) == 0x82) {
            uVar10 = *(uint *)(*(long *)(lVar9 + 0x30) + 0x10);
            lVar9 = *(long *)(lVar9 + 0x30);
          }
          if (((uVar10 & 0xff) == 0x40) || ((uVar10 & 0xf) != 0)) {
            uVar8 = 0;
          }
          else {
            uVar8 = *(undefined8 *)(lVar9 + 0x78);
          }
          FUN_fffffff00996647c(param_2,uVar8);
        }
        plVar5 = (long *)plVar4[5];
        *(long **)(lVar3 + 0x28) = plVar5;
        (**(code **)(*plVar5 + 0x20))();
        FUN_fffffff009953f38(plVar4,lVar3);
        if (param_2 == 0) {
          thunk_EXT_FUN_80110000036da494(0x8509001c,0,*(undefined8 *)(lVar3 + 0x70),0x82,0,0);
          uVar8 = 0;
        }
        else {
          thunk_EXT_FUN_80110000036da494
                    (0x8509001c,*(undefined8 *)(param_2 + 0x38),*(undefined8 *)(lVar3 + 0x70),0x82,0
                     ,0);
          uVar8 = *(undefined8 *)(param_2 + 0x38);
        }
        uVar11 = *(undefined8 *)(lVar3 + 0x70);
        uVar6 = thunk_EXT_FUN_8011000002c1e35c(param_3);
        uVar7 = FUN_fffffff0099529c0(lVar3);
        local_48 = 0;
        thunk_EXT_FUN_80110000032db760(uVar7,&local_48);
        thunk_EXT_FUN_80110000036da494
                  (0x85090020,uVar8,uVar11,(uVar6 & 0xffffffff) << 8 | 0x82,local_48,0);
      }
    }
  }
  else {
    lVar3 = 0;
  }
  return lVar3;
}

