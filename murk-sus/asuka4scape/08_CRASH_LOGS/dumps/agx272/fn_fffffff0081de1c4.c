// FUN_fffffff0081de1c4 @ fffffff0081de1c4 size=172

void FUN_fffffff0081de1c4(long param_1,undefined8 *param_2)

{
  FUN_fffffff008168d44();
  *(undefined4 *)(param_2 + 1) = 0x42d60000;
  *(undefined4 *)(param_2 + 2) = 0x41100000;
  *param_2 = 0x1a;
  *(undefined4 *)((long)param_2 + 0x2c) = 0x4107d70a;
  *(undefined8 *)((long)param_2 + 0x34) = DAT_fffffff007114008;
  if (*(ulong *)(param_1 + 0x105f8) == 0 || (*(ulong *)(param_1 + 0x105f8) & 0x1a) == 0x1a) {
    return;
  }
  thunk_EXT_FUN_8011000003a49114
            (
            "AGXk: %s:%d:%s: !!! Not all MTR Sensors required for FastDie are enabled (en: %.16llx exp: %.16llx)\n"
            );
  return;
}

