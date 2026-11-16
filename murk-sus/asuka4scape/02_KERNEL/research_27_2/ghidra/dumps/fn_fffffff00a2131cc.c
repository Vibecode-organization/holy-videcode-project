// FUN_fffffff00a2131cc @ fffffff00a2131cc size=356
// CALLERS:
//   fffffff00afb8532 no-fn
//   fffffff00a211de8 FUN_fffffff00a211aa8@fffffff00a211aa8
//   fffffff00a213404 FUN_fffffff00a213330@fffffff00a213330
//   fffffff00a2125e4 FUN_fffffff00a2124e0@fffffff00a2124e0
//   fffffff00a212650 FUN_fffffff00a2124e0@fffffff00a2124e0
//   fffffff00a2126bc FUN_fffffff00a2124e0@fffffff00a2124e0
// CALLEES:
//   fffffff00a29bafc FUN_fffffff00a29bafc
//   fffffff00a9dee48 FUN_fffffff00a9dee48
//   fffffff00a1f040c FUN_fffffff00a1f040c
//   fffffff00a29b0b4 FUN_fffffff00a29b0b4
//   fffffff00a764470 FUN_fffffff00a764470
//   fffffff00a1eec1c FUN_fffffff00a1eec1c
//   fffffff00a22b804 FUN_fffffff00a22b804

uint FUN_fffffff00a2131cc(long param_1,undefined1 (*param_2) [16])

{
  uint uVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  uint uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined1 auVar10 [16];
  
  uVar7 = 1;
  if ((param_1 == 0) || (DAT_fffffff007bc7030 == param_2)) goto LAB_fffffff00a21330c;
  uVar8 = *(undefined8 *)(*(long *)(param_1 + 0x310) + 0x58);
  auVar10 = FUN_fffffff00a1f040c(param_2);
  if (((*param_2)[2] & 1) == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a213330);
    (*pcVar2)();
  }
  uVar1 = auVar10._0_4_ & 0xff;
  (*param_2)[2] = 0;
  FUN_fffffff00a22b804((long)(param_2[1] + 4));
  if (((uint)uVar8 >> 3 & 1) == 0) goto LAB_fffffff00a213258;
  lVar9 = *(long *)(param_1 + 0x310);
  uVar7 = 1;
  if ((uVar1 == 2) || (uVar1 == 8)) goto LAB_fffffff00a21330c;
  uVar5 = FUN_fffffff00a29b0b4(param_1);
  iVar4 = FUN_fffffff00a764470(uVar5);
  if (iVar4 == 0) {
LAB_fffffff00a213258:
    if (8 < uVar1) {
      uVar7 = 0;
      goto LAB_fffffff00a21330c;
    }
  }
  else {
    lVar6 = tpidr_el1;
    lVar6 = FUN_fffffff00a29bafc(lVar6);
    bVar3 = FUN_fffffff00a9dee48(lVar6,-0xff8fb9b7e);
    if ((bVar3) || (bVar3 = FUN_fffffff00a9dee48(lVar6,-0xff8fb4d28), bVar3))
    goto LAB_fffffff00a213258;
    uVar5 = FUN_fffffff00a1eec1c(0xd,lVar9,0,0,param_2,0);
    uVar7 = 0;
    if (((uVar5 & 1) != 0) || (8 < uVar1)) goto LAB_fffffff00a21330c;
  }
  uVar7 = 0x116 >> (ulong)(auVar10._0_4_ & 0x1f);
LAB_fffffff00a21330c:
  return uVar7 & 1;
}

