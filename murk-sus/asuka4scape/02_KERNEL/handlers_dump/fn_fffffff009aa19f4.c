// FUN_fffffff009aa19f4 @ fffffff009aa19f4 size=276 depth=1
// CALLERS:
//   fffffff00afe8807 ?
//   fffffff009aa3d94 FUN_fffffff009aa3d3c
// CALLS:
//   fffffff009abd13c thunk_FUN_fffffff00a9029a0
//   fffffff009abdbbc thunk_FUN_fffffff00aa4d114
//   fffffff009abd1cc thunk_FUN_fffffff00a9dee48

bool FUN_fffffff009aa19f4
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               int param_8,int param_9,ulong param_10)

{
  long *plVar1;
  int *piVar2;
  bool bVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  
  if ((DAT_fffffff00af449d8 & 1) == 0) {
    if (param_9 == 2) {
LAB_fffffff009aa1abc:
      bVar3 = thunk_FUN_fffffff00a9dee48(param_7,-0xff87a2b6a);
    }
    else {
      if (param_9 == 1) {
        lVar6 = (param_10 & 0xffffffff) * 0x10;
        iVar5 = (int)lVar6;
        plVar1 = (long *)((long)&PTR_DAT_fffffff008023a80 + (long)iVar5);
        if (lVar6 != iVar5) {
          plVar1 = (long *)((ulong)(&PTR_DAT_fffffff008023a80 + (param_10 & 0xffffffff) * 2) &
                            0xffffffffffff | 0x2bad000000000000);
        }
        uVar4 = (ulong)*(uint *)(plVar1 + 1);
        if (*(uint *)(plVar1 + 1) != 0) {
          lVar6 = 0;
          do {
            lVar7 = lVar6 * 4;
            piVar2 = (int *)(*plVar1 + (long)(int)lVar7);
            if (lVar7 - (int)lVar7 != 0) {
              piVar2 = (int *)(*plVar1 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
            }
            if (*piVar2 == param_8) goto LAB_fffffff009aa1abc;
            lVar6 = lVar6 + 1;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
      }
      if ((DAT_fffffff00af449d9 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_fffffff00aa4d114
                  (param_1,param_2,param_3,param_4,param_5,param_6,
                   (byte *)
                   "\"%s: client cannot execute this enum %d client type: %d index: %d\\n\" @%s:%d")
        ;
      }
      thunk_FUN_fffffff00a9029a0
                ((byte *)"%s: client cannot execute this enum %d client type: %d index: %d\n");
      bVar3 = false;
    }
  }
  else {
    bVar3 = true;
  }
  return bVar3;
}

