// FUN_fffffff009a781b4 @ fffffff009a781b4 size=472
// CALLERS:
//   fffffff00afe82e4 no-fn
//   fffffff009a78164 FUN_fffffff009a780fc@fffffff009a780fc
//   fffffff009a7839c FUN_fffffff009a7838c@fffffff009a7838c
//   fffffff009a98608 no-fn
//   fffffff009a98670 no-fn
// CALLEES:
//   fffffff009a99cd0 thunk_FUN_fffffff00a89460c
//   fffffff009a99b60 thunk_FUN_fffffff00a2262a8
//   fffffff009a932e4 FUN_fffffff009a932e4
//   fffffff009a99ba0 thunk_FUN_fffffff00a226de0
//   fffffff009a995ac FUN_fffffff009a995ac
//   fffffff009a99ce0 thunk_FUN_fffffff00a8945fc
//   fffffff009a99f00 thunk_FUN_fffffff00a894f30

/* WARNING: Removing unreachable block (ram,0xfffffff009a7828c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009a78384) */
/* WARNING: Removing unreachable block (ram,0xfffffff009a78328) */

long * FUN_fffffff009a781b4
                 (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                 undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                 int param_8,int param_9)

{
  undefined4 *puVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  long *plVar5;
  long *plVar6;
  ulong uVar7;
  long lVar8;
  undefined1 extraout_q0 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  
  if (*(long *)(param_7 + 0x138) != 0) {
    if (param_8 == 0) {
      iVar4 = thunk_FUN_fffffff00a89460c((int *)(param_7 + 0x260));
      if (iVar4 == 0) {
        auVar10 = FUN_fffffff009a995ac(extraout_q0,param_2,param_3,param_4,param_5,param_6);
        plVar5 = thunk_FUN_fffffff00a894f30(auVar10._0_8_,-0xff50da7a0);
        plVar6 = plVar5;
        if ((((plVar5 == (long *)0x0) || (auVar10._8_8_ == 0)) || (plVar5[0x27] == 0)) ||
           ((plVar6 = (long *)plVar5[0x4d], plVar6 == (long *)0x0 || (plVar5[0x87] == 0)))) {
          return plVar6;
        }
        auVar9 = thunk_FUN_fffffff00a2262a8((ulong)plVar6);
        if ((int)plVar5[0x6e] == 0) {
          plVar6 = (long *)thunk_FUN_fffffff00a226de0(plVar5[0x4d]);
          return plVar6;
        }
        FUN_fffffff009a932e4
                  (auVar9,param_2,param_3,param_4,param_5,param_6,(long *)plVar5[0x87],1,0);
        thunk_FUN_fffffff00a226de0(plVar5[0x4d]);
        lVar8 = *(long *)plVar5[0x27];
        (**(code **)(lVar8 + 0x3b0))
                  (lVar8 + 0x3b0,(long *)plVar5[0x27],"setIomdCacheAttribute",0,auVar10._8_8_,
                   "iomdEarlyPurge",1,0);
        thunk_FUN_fffffff00a2262a8(plVar5[0x4d]);
        uVar2 = *(uint *)(plVar5 + 0x6e);
        uVar7 = (ulong)uVar2;
        if (uVar2 != 0) {
          lVar8 = 0;
          do {
            if (*(int *)((long)plVar5 + lVar8 * 4 + 0x270) == param_9) {
              lVar3 = (ulong)(uVar2 - 1) * 4;
              puVar1 = (undefined4 *)((long)plVar5 + (long)(int)lVar3 + 0x270);
              if (lVar3 != (int)lVar3) {
                puVar1 = (undefined4 *)
                         ((long)plVar5 + lVar3 + 0x270 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *(uint *)(plVar5 + 0x6e) = uVar2 - 1;
              *(undefined4 *)((long)plVar5 + lVar8 * 4 + 0x270) = *puVar1;
              break;
            }
            lVar8 = lVar8 + 1;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        auVar10 = thunk_FUN_fffffff00a226de0(plVar5[0x4d]);
        plVar6 = (long *)FUN_fffffff009a932e4
                                   (auVar10,param_2,param_3,param_4,param_5,param_6,
                                    (long *)plVar5[0x87],0,0);
        return plVar6;
      }
    }
    else {
      thunk_FUN_fffffff00a8945fc((int *)(param_7 + 0x260));
    }
  }
  return (long *)0x0;
}

