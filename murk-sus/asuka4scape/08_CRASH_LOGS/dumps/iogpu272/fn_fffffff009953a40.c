// FUN_fffffff009953a40 @ fffffff009953a40 size=532

/* WARNING: Removing unreachable block (ram,0xfffffff009953ab8) */

long * FUN_fffffff009953a40(long *param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 local_48;
  
  uVar8 = *(undefined8 *)(param_2 + 0x10);
  uVar2 = (**(code **)(*param_1 + 0x5d0))(param_1,uVar8);
  plVar3 = (long *)(**(code **)(*param_1 + 0x5b0))(*param_1 + 0x5b0,param_1,0,uVar2);
  if (plVar3 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: allocIOGPUResource failed to alloc texture object\n");
  }
  else {
    uVar4 = thunk_EXT_FUN_8011000002c1c364(uVar8);
    if (uVar4 >> 0x20 == 0) {
      lVar5 = thunk_EXT_FUN_80110000038ff010();
      plVar3[0xc] = lVar5;
      if ((lVar5 != 0) &&
         (plVar6 = (long *)FUN_fffffff009974014(param_1,uVar8), plVar6 != (long *)0x0)) {
        lVar5 = (**(code **)(*plVar6 + 0x88))();
        plVar3[0xf] = lVar5;
        uVar1 = *(uint *)(plVar3 + 2);
        plVar3[5] = (long)plVar6;
        plVar3[6] = param_2;
        plVar3[7] = 0;
        plVar3[8] = (long)(plVar3 + 7);
        plVar3[9] = 0;
        *(uint *)(plVar3 + 2) = uVar1 | 0x4400;
        *(int *)((long)plVar3 + 0x14) = (int)uVar4;
        thunk_EXT_FUN_80110000036da494(0x8509001c,0,plVar3[0xe],uVar1 & 0xff,lVar5,0);
        lVar7 = plVar3[0xe];
        lVar5 = plVar3[2];
        uVar2 = FUN_fffffff0099529c0(plVar3);
        local_48 = 0;
        thunk_EXT_FUN_80110000032db760(uVar2,&local_48);
        thunk_EXT_FUN_80110000036da494(0x85090020,0,lVar7,(char)lVar5,local_48,0);
        return plVar3;
      }
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Cannot store 64-bit protection options\n");
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return (long *)0x0;
}

