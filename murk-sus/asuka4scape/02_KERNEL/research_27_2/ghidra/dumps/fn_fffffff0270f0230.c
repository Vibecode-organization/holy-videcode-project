// FUN_fffffff0270f0230 @ fffffff0270f0230 size=580
// CALLERS:
//   fffffff027022338 no-fn
// CALLEES:
//   fffffff0270f46b4 FUN_fffffff0270f46b4
//   fffffff0270ee878 FUN_fffffff0270ee878
//   fffffff0270f46f4 FUN_fffffff0270f46f4
//   fffffff0270ebe38 FUN_fffffff0270ebe38

void FUN_fffffff0270f0230(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  char *pcVar2;
  byte bVar3;
  short *psVar4;
  long lVar5;
  undefined *puVar6;
  undefined1 auVar7 [16];
  long local_48;
  
  auVar7 = FUN_fffffff0270ebe38();
  psVar4 = auVar7._0_8_;
  if (*psVar4 != 2) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46f4(0x42,auVar7._8_8_,"%s(%s:%d) - %s(%#llx)\n");
  }
  *psVar4 = 1;
  if ((&DAT_fffffff027092201)[(ulong)*(byte *)(psVar4 + 1) * 0x90] == '\x01') {
    local_48 = 0;
    puVar6 = (&PTR_PTR_fffffff027023ad0)[*(byte *)(psVar4 + 6)];
    auVar7 = FUN_fffffff0270ee878
                       (param_2,param_3,
                        0x1000000000U >> (*(ulong *)(puVar6 + 0x50) & 0x3f) & 0xffffffff,psVar4,
                        &local_48);
    if ((&DAT_fffffff027092201)[(ulong)*(byte *)(psVar4 + 1) * 0x90] == '\x01') {
      bVar3 = *(byte *)(psVar4 + 4);
      if (bVar3 == 0xff) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f46b4("%s: Unexpected shared region ID");
      }
      lVar1 = (ulong)bVar3 * 0x20;
      pcVar2 = &DAT_fffffff027104048 + lVar1;
      if (*pcVar2 == -1) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f46b4("%s: Unexpected shared region state");
      }
      lVar5 = *(long *)(puVar6 + 0x48);
      if (*pcVar2 != '\x01') {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f46f4
                  (0x4c,auVar7._8_8_,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx)\n");
      }
      *pcVar2 = '\x02';
      (&DAT_fffffff027104050)[(ulong)bVar3 * 4] = auVar7._0_8_;
      *(long *)(&DAT_fffffff027104058 + lVar1) = local_48 * lVar5;
      if (*pcVar2 == '\x02') {
        *pcVar2 = '\x03';
        *psVar4 = 0;
        return;
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f46b4("%s: Unexpected failure while attempting to configure a shared region");
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff0270f46b4
            (
            "%s: Type (%s) class of FTE (%p) does not match the type class of the type-specific-data trying to be retrieved: actual (%d) != requested (%d)."
            );
}

