// FUN_fffffff00818d460 @ fffffff00818d460 size=728

/* WARNING: Removing unreachable block (ram,0xfffffff00818d568) */

long * FUN_fffffff00818d460(long param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  undefined4 uVar6;
  long lVar7;
  undefined8 uVar8;
  
  plVar3 = (long *)(**(code **)(DAT_fffffff00ae25b60 + 0x68))();
  if (plVar3 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to create work queue\n");
  }
  else {
    uVar4 = (**(code **)(*plVar3 + 0xd8))
                      (plVar3,*(undefined8 *)(param_1 + 0x530),param_1,
                       *(undefined4 *)(param_1 + 0x848),
                       *(undefined4 *)(*(long *)(param_1 + 0x610) + 0x9c),param_2);
    if ((uVar4 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to init work queue\n");
    }
    else {
      uVar8 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x610) + 0xb0) + 0x28);
      plVar5 = (long *)(**(code **)(*(long *)plVar3[0x18] + 0x848))();
      plVar3[0x43] = (long)plVar5;
      if (plVar5 == (long *)0x0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to create GTP channel\n");
      }
      else {
        thunk_EXT_FUN_8011000003890f30(plVar3[3],&DAT_fffffff00ae21f50);
        uVar4 = (**(code **)(*plVar5 + 0x168))
                          (*plVar5 + 0x168,plVar5,plVar3[3],plVar3,(int)plVar3[0x1d],
                           *(undefined4 *)((long)plVar3 + 0x54),uVar8);
        if ((uVar4 & 1) != 0) {
          uVar2 = *(uint *)(param_1 + 0x7ec);
          if (*(int *)(param_1 + 0x44c) == 1) {
            uVar6 = *(undefined4 *)(param_1 + 0x450);
          }
          else {
            uVar6 = 2;
          }
          (**(code **)(*(long *)plVar3[0x43] + 0x110))((long *)plVar3[0x43],(ulong)uVar2,uVar6);
          if ((uVar2 < 6) && ((0x37U >> (ulong)(uVar2 & 0x1f) & 1) != 0)) {
            lVar7 = (ulong)uVar2 * 4;
            puVar1 = (undefined4 *)(&DAT_fffffff007115cc0 + (int)lVar7);
            if (lVar7 - (int)lVar7 != 0) {
              puVar1 = (undefined4 *)
                       ((ulong)(&DAT_fffffff007115cc0 + lVar7) & 0xffffffffffff | 0x2bad000000000000
                       );
            }
            thunk_EXT_FUN_8011000002958c50(plVar3,*puVar1);
            return plVar3;
          }
          plVar3 = (long *)thunk_EXT_FUN_8011000003a49114
                                     (
                                     "AGXk: %s:%d:%s: !!! Invalid priority %d used for work queue 0x%p\n"
                                     );
          return plVar3;
        }
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to init GTP channel\n");
        if ((long *)plVar3[0x43] != (long *)0x0) {
          (**(code **)(*(long *)plVar3[0x43] + 0x28))();
        }
        plVar3[0x43] = 0;
      }
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return (long *)0x0;
}

