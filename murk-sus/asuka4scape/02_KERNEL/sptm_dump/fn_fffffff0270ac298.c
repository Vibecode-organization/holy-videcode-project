// FUN_fffffff0270ac298 @ fffffff0270ac298 size=892
// CALLERS:
//   fffffff02701c1c0 ?

void FUN_fffffff0270ac298(undefined8 param_1,ushort param_2)

{
  ulong *puVar1;
  byte bVar2;
  byte *pbVar3;
  undefined8 uVar4;
  char *pcVar5;
  ulong uVar6;
  long lVar7;
  byte *pbVar8;
  ulong uVar9;
  byte in_wzr;
  undefined1 auVar10 [16];
  
  auVar10 = FUN_fffffff0270be6dc(param_1,2,5);
  uVar4 = auVar10._8_8_;
  pbVar3 = auVar10._0_8_;
  if (0x3f < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x4000017,uVar4,"%s(%s:%d) - %s(%#llx)\n");
  }
  if (*(short *)(pbVar3 + 0x18) == -1) {
    lVar7 = UnkSytemRegRead(3,6,0xf,8,0);
    if (lVar7 == 0) {
      lVar7 = tpidr_el2;
    }
    else {
      lVar7 = UnkSytemRegRead(3,6,0xf,0xb,1);
    }
    if (*(byte *)(DAT_fffffff0270921b8 + 0x60) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f353c(0x400001a,uVar4,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
    }
    *(byte *)(DAT_fffffff0270921b8 + 0x60) = *(char *)(lVar7 + 0x14a8) << 1 | 1;
    *(ushort *)(pbVar3 + 0x18) = param_2;
    lVar7 = *(long *)(DAT_fffffff0270921b8 + 0x78);
    uVar6 = (ulong)param_2;
    puVar1 = (ulong *)(lVar7 + (ulong)param_2 * 0x10);
    if ((((uint)*puVar1 | (uint)puVar1[1]) & 1) == 0) {
      bVar2 = *pbVar3;
      if ((bVar2 & 5) != 0) {
        pbVar8 = pbVar3;
        if (bVar2 == 1) {
          if (*(long *)(DAT_fffffff0270921b8 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff0270f34fc("%s: Accessing Shared Mode global data outside Shared Mode");
          }
          bVar2 = **(byte **)(DAT_fffffff0270921b8 + 0x18);
          pbVar8 = *(byte **)(DAT_fffffff0270921b8 + 0x18);
        }
        if ((bVar2 & 0xe) != 0) {
          uVar9 = *(ulong *)(pbVar8 + 0x10);
          *puVar1 = *(ulong *)(pbVar3 + 8) & 0x3ffffffc000 | (uVar6 & 0x7fff) << 0x30 | 1;
          *(ulong *)(lVar7 + uVar6 * 0x10 + 8) = uVar6 << 0x30 | uVar9 & 0x3ffffffc000 | 1;
          DataMemoryBarrier(0,3);
          lVar7 = UnkSytemRegRead(3,6,0xf,8,0);
          if (lVar7 == 0) {
            lVar7 = tpidr_el2;
          }
          else {
            lVar7 = UnkSytemRegRead(3,6,0xf,0xb,1);
          }
          if (*(byte *)(DAT_fffffff0270921b8 + 0x60) == (byte)(*(char *)(lVar7 + 0x14a8) << 1 | 1U))
          {
            *(byte *)(DAT_fffffff0270921b8 + 0x60) = in_wzr;
            if (pbVar3[0x1a] == 1) {
              pbVar3[0x1a] = 2;
              if ((*pbVar3 & 5) == 0) {
                return;
              }
              FUN_fffffff0270d2f50();
              FUN_fffffff0270dfc5c();
              return;
            }
          }
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f34fc("%s: state_guard_release - %#llx, %#llx");
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: %d is not a valid UAT state object type when getting TTBR%d");
    }
    pcVar5 = "%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx)\n";
  }
  else {
    pcVar5 = "%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n";
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff0270f353c(0x4000018,uVar4,pcVar5);
}

