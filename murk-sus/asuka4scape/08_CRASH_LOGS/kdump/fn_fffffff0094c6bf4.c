// FUN_fffffff0094c6bf4 @ fffffff0094c6bf4 size=516
// CALLERS:
//   fffffff00afb80b1 ?
//   fffffff0094c6e60 FUN_fffffff0094c6df8@fffffff0094c6df8
//   fffffff0094c6f3c FUN_fffffff0094c6eac@fffffff0094c6eac
//   fffffff0094c8954 FUN_fffffff0094c8638@fffffff0094c8638
//   fffffff0094c8f8c FUN_fffffff0094c8f38@fffffff0094c8f38
//   fffffff0094c7ee8 FUN_fffffff0094c7e00@fffffff0094c7e00
//   fffffff0094c7b00 FUN_fffffff0094c7a20@fffffff0094c7a20
// CALLS:
//   fffffff0094c99e4 thunk_EXT_FUN_8011000003137b18
//   fffffff0094c9a04 thunk_EXT_FUN_8011000003138628
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590

ulong FUN_fffffff0094c6bf4
                (undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  ulong uVar5;
  ulong local_68;
  undefined1 *local_60;
  undefined1 *local_58;
  undefined1 *local_50;
  undefined1 *local_48;
  undefined1 *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff007f5bb60;
  puVar4 = (undefined1 *)*param_1;
  if (CARRY8((ulong)puVar4,param_1[1])) {
LAB_fffffff0094c6dec:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5513,0xfffffff0094c6df0);
    (*pcVar2)();
  }
  if (puVar4 + param_1[1] < puVar4) goto LAB_fffffff0094c6dc4;
  uVar5 = 0xa0001;
  local_50 = &DAT_aaaaaaaaaaaaaaaa;
  local_48 = puVar4;
  local_40 = puVar4 + param_1[1];
  iVar3 = thunk_EXT_FUN_8011000003138628(&local_48,0x2000000000000010,&local_50);
  if (iVar3 != 0) {
    iVar3 = thunk_EXT_FUN_8011000003138628(&local_48,0x2000000000000010,&local_50);
    if (iVar3 != 0) {
      if (CARRY8((ulong)local_48,(ulong)local_50)) goto LAB_fffffff0094c6dec;
      puVar4 = local_48 + (long)local_50;
      if ((local_48 <= puVar4) && (puVar4 <= local_40)) {
        local_60 = local_48;
        local_58 = puVar4;
        iVar3 = thunk_EXT_FUN_8011000003138628(&local_60,6,&local_50);
        if (iVar3 == 0) {
          uVar5 = 0xa0002;
          goto LAB_fffffff0094c6d28;
        }
        if (param_2 != (undefined8 *)0x0) {
          if ((local_58 < local_60) || (local_58 + -(long)local_60 < local_50))
          goto LAB_fffffff0094c6dc4;
          *param_2 = local_60;
          param_2[1] = local_50;
        }
        if (CARRY8((ulong)local_60,(ulong)local_50)) goto LAB_fffffff0094c6dec;
        puVar4 = local_60 + (long)local_50;
        if (local_60 <= puVar4) {
          if (puVar4 <= local_58) {
            if (puVar4 == local_58) {
              if (param_3 != (undefined8 *)0x0) {
                *param_3 = 0;
                param_3[1] = 0;
              }
            }
            else if (param_3 != (undefined8 *)0x0) {
              *param_3 = puVar4;
              param_3[1] = (long)local_58 - (long)puVar4;
            }
            if ((local_58 <= local_40) && (local_48 <= local_58)) {
              local_48 = local_58;
              local_68 = 0;
              local_60 = &DAT_aaaaaaaaaaaaaaaa;
              local_58 = &DAT_aaaaaaaaaaaaaaaa;
              iVar3 = thunk_EXT_FUN_8011000003137b18(&local_48,&local_60,&local_68);
              if (iVar3 == 0) {
                uVar5 = 0xa0004;
                goto LAB_fffffff0094c6d28;
              }
              if (local_68 == 0) {
                uVar5 = 0;
                puVar4 = (undefined1 *)0x0;
              }
              else {
                if (0xfffffffffffffff8 < local_68) {
                    /* WARNING: Does not return */
                  pcVar2 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c6df8);
                  (*pcVar2)();
                }
                if ((local_58 < local_60) ||
                   (uVar5 = local_68 + 7 >> 3, puVar4 = local_60,
                   (ulong)((long)local_58 - (long)local_60) < uVar5)) goto LAB_fffffff0094c6dc4;
              }
              *param_4 = puVar4;
              param_4[1] = uVar5;
              uVar1 = 0;
              if (local_48 != local_40) {
                uVar1 = 0xa0005;
              }
              uVar5 = (ulong)uVar1;
              goto LAB_fffffff0094c6d28;
            }
          }
        }
      }
LAB_fffffff0094c6dc4:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c6dc8);
      (*pcVar2)();
    }
    uVar5 = 0xa0003;
  }
LAB_fffffff0094c6d28:
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_38) {
    return uVar5;
  }
  uVar5 = thunk_EXT_FUN_8011000003a48590();
  return uVar5;
}

