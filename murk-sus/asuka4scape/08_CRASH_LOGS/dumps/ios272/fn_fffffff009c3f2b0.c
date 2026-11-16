// FUN_fffffff009c3f2b0 @ fffffff009c3f2b0 size=456

/* WARNING: Removing unreachable block (ram,0xfffffff009c3f374) */

undefined8 FUN_fffffff009c3f2b0(long param_1,long *param_2,ulong param_3)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  long *plVar8;
  
  uVar2 = (uint)param_3;
  if ((uVar2 == 0) || (uVar4 = *(uint *)(param_1 + 0x110), uVar4 <= uVar2)) {
    iVar1 = FUN_fffffff009c400e8(param_1);
    if (iVar1 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,"%s: alloc_handles() failed\n");
      return 0;
    }
    uVar4 = *(uint *)(param_1 + 0x110);
  }
  uVar3 = *(ulong *)(param_1 + 0x108);
  uVar5 = uVar3 + (ulong)uVar4 * 8;
  uVar6 = uVar5 - uVar3;
  if ((uVar5 < uVar3) || (uVar6 >> 0x20 != 0)) {
    FUN_fffffff009c48f64();
  }
  else {
    lVar7 = (param_3 & 0xffffffff) << 3;
    if (lVar7 == (int)lVar7) {
      if ((param_3 & 0x1fffffff) >> 0x1c == 0) {
        uVar5 = (ulong)(uVar2 * 8);
        uVar2 = uVar2 * 8 + 8;
        if ((uint)uVar6 < uVar2) goto LAB_fffffff009c3f410;
        uVar6 = -(ulong)CARRY8(uVar3,uVar5);
        if ((uVar6 != CARRY8(uVar3,uVar5)) || ((long)uVar6 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        lVar7 = *(long *)(uVar3 + uVar5);
        if ((lVar7 == 0) || (lVar7 == 0)) {
          plVar8 = param_2;
          if (param_2 == (long *)0x0) {
            plVar8 = (long *)0x0;
          }
          *(long *)(uVar3 + uVar5) = (long)plVar8;
          (**(code **)(*param_2 + 0x20))(param_2);
          return 1;
        }
        uVar3 = *(ulong *)(param_1 + 0x108);
        uVar6 = uVar3 + (ulong)*(uint *)(param_1 + 0x110) * 8;
        if (((uVar3 ^ uVar6) & 0xffc0000000000000) != 0) {
          uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar3 <= uVar6) && (uVar6 - uVar3 >> 0x20 == 0)) {
          if ((uint)(uVar6 - uVar3) < uVar2) goto LAB_fffffff009c3f470;
          uVar6 = -(ulong)CARRY8(uVar3,uVar5);
          if ((uVar6 != CARRY8(uVar3,uVar5)) || ((long)uVar6 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50(uVar3 + uVar5);
          }
          FUN_fffffff009c492f0(uVar3 + uVar5,uVar6,param_3);
        }
        FUN_fffffff009c48f64();
LAB_fffffff009c3f470:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f28();
      }
      goto LAB_fffffff009c3f410;
    }
  }
  FUN_fffffff009c48f3c();
LAB_fffffff009c3f410:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

