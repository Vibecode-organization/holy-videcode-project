// FUN_fffffff0099544e0 @ fffffff0099544e0 size=520

long * FUN_fffffff0099544e0(long *param_1,long param_2,undefined8 param_3)

{
  long *plVar1;
  long lVar2;
  undefined8 *puVar3;
  ulong uVar4;
  undefined8 uVar5;
  uint uVar6;
  
  uVar6 = (uint)param_3;
  if (uVar6 < 0x40) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: newResourceGroup failed - initial capacity (%u) less than minimum required (%u)\n"
              );
  }
  else if ((uVar6 & uVar6 - 1) == 0) {
    plVar1 = (long *)(**(code **)(*param_1 + 0x5b0))(param_1,param_2,3);
    if (plVar1 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: newResourceGroup failed to alloc texture object\n");
    }
    else {
      lVar2 = thunk_EXT_FUN_80110000038ff010();
      plVar1[0xc] = lVar2;
      lVar2 = FUN_fffffff009968ad4(param_1,param_3);
      plVar1[5] = lVar2;
      if (lVar2 != 0) {
        puVar3 = (undefined8 *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ff0528);
        puVar3[1] = 0;
        *puVar3 = 0;
        puVar3[3] = 0;
        puVar3[2] = 0;
        puVar3[4] = 0;
        puVar3[5] = 0;
        puVar3[6] = 0;
        puVar3[7] = 0;
        *(undefined1 *)(puVar3 + 8) = 0;
        plVar1[6] = (long)puVar3;
        uVar4 = FUN_fffffff0099546e8(puVar3,param_3,0x40000);
        if ((uVar4 & 1) != 0) {
          *(uint *)(plVar1 + 2) = *(uint *)(plVar1 + 2) | 0x200;
          *(undefined8 *)plVar1[3] = 0;
          if (param_2 == 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = *(undefined8 *)(param_2 + 0x38);
          }
          thunk_EXT_FUN_80110000036da494(0x8509001c,uVar5,plVar1[0xe],3,0,0);
          return plVar1;
        }
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: newResourceGroup failed to initialize resource map\n");
      }
      (**(code **)(*plVar1 + 0x28))(plVar1);
    }
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: newResourceGroup bad initial capacity: %d\n");
  }
  return (long *)0x0;
}

