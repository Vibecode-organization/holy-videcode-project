// FUN_fffffff00995357c @ fffffff00995357c size=1208

long * FUN_fffffff00995357c
                 (long *param_1,long param_2,ulong param_3,ulong param_4,ulong param_5,ulong param_6
                 ,ulong param_7,undefined8 *param_8,int param_9)

{
  ulong uVar1;
  ulong uVar2;
  long *plVar3;
  long *plVar4;
  ulong uVar5;
  long *plVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 local_68;
  
  if (param_2 != 0) {
    if (param_4 != 0) {
      if ((*(byte *)(param_2 + 0x40) >> 1 & 1) == 0) {
        return (long *)0x0;
      }
      if (0xf < param_4) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Unsupported protecton options (%016llx) bytes\n");
        return (long *)0x0;
      }
    }
    uVar2 = thunk_EXT_FUN_8011000002c2d4f8(param_4);
    if (param_9 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: parent_resource_id is 0\n");
      return (long *)0x0;
    }
    if (uVar2 >> 0x20 != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Cannot store 64-bit protection options\n");
      return (long *)0x0;
    }
    if ((int)param_3 == 0x80) {
      if (((param_5 == 0) || (param_6 == 0)) || (param_7 == 0)) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: invalid arguments\n");
        return (long *)0x0;
      }
    }
    else {
      if ((int)param_3 != 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: failing. parent_resource_id only works with standard texture. resType=0x%x.\n"
                  );
        return (long *)0x0;
      }
      if (param_5 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: invalid arguments\n");
        return (long *)0x0;
      }
    }
    plVar3 = (long *)(**(code **)(*param_1 + 0x5b0))(param_1,param_2,param_3);
    if (plVar3 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: createResource failed\n");
      return (long *)0x0;
    }
    plVar4 = (long *)FUN_fffffff009965628(param_2,param_9);
    if (plVar4 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: failed to lookup parent resource from shared.\n");
    }
    else {
      if (uVar2 == *(uint *)((long)plVar4 + 0x14)) {
        if (((*(byte *)(plVar4 + 2) & 0x7f) == 0) && ((long *)plVar4[5] != (long *)0x0)) {
          uVar1 = param_6 - param_7;
          if (param_6 < param_7) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s: client_buffer (0x%llx) precedes client_base (0x%llx).\n");
          }
          else {
            uVar5 = (**(code **)(*(long *)plVar4[5] + 0x88))();
            if ((uVar1 < uVar5) && (param_5 == uVar5 || param_5 <= uVar5 - uVar1)) {
              lVar9 = plVar4[0xf];
              plVar6 = (long *)plVar4[5];
              plVar3[5] = (long)plVar6;
              (**(code **)(*plVar6 + 0x20))();
              (**(code **)(*plVar4 + 0x28))(plVar4);
              *(int *)((long)plVar3 + 0x14) = (int)uVar2;
              FUN_fffffff009943f9c(plVar3[5],uVar2);
              plVar3[9] = uVar1;
              plVar3[0xf] = lVar9;
              *(uint *)(plVar3 + 2) = *(uint *)(plVar3 + 2) | 0x200200;
              if (param_8 != (undefined8 *)0x0) {
                *param_8 = 0;
                lVar9 = plVar3[0xf];
              }
              thunk_EXT_FUN_80110000036da494
                        (0x8509001c,*(undefined8 *)(param_2 + 0x38),plVar3[0xe],param_3 & 0xffffffff
                         ,lVar9,0);
              uVar8 = *(undefined8 *)(param_2 + 0x38);
              lVar9 = plVar3[0xe];
              uVar7 = FUN_fffffff0099529c0(plVar3);
              local_68 = 0;
              thunk_EXT_FUN_80110000032db760(uVar7,&local_68);
              thunk_EXT_FUN_80110000036da494(0x85090020,uVar8,lVar9,param_3 & 0xffffffff,local_68,0)
              ;
              return plVar3;
            }
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s: child resource (offset=0x%llx, size=0x%llx) exceeds parent memory size 0x%llx.\n"
                      );
          }
        }
        else {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s: parent resource type mismatch.\n");
        }
      }
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return (long *)0x0;
}

