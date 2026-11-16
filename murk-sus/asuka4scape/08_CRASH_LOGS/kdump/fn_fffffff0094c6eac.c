// FUN_fffffff0094c6eac @ fffffff0094c6eac size=572
// CALLERS:
//   fffffff00afb80b4 ?
//   fffffff0094c717c FUN_fffffff0094c70e8@fffffff0094c70e8
//   fffffff0094c0e6c FUN_fffffff0094c06d0@fffffff0094c06d0
// CALLS:
//   fffffff0094c6bf4 FUN_fffffff0094c6bf4
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c51c8 FUN_fffffff0094c51c8
//   fffffff0094c2f4c FUN_fffffff0094c2f4c
//   fffffff0094c3158 FUN_fffffff0094c3158
//   fffffff0094c519c FUN_fffffff0094c519c

ulong FUN_fffffff0094c6eac(uint param_1,uint param_2,long param_3,long *param_4,undefined8 param_5)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  long local_88;
  long lStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff007f5bb60;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  lStack_80 = 0;
  if (param_3 + 0x58U <= param_3 + 0x68U) {
    uVar4 = FUN_fffffff0094c6bf4(param_3 + 0x58U,&local_68,&local_78,&local_88);
    if ((int)uVar4 == 0) {
      uVar4 = 0xa0111;
      iVar3 = FUN_fffffff0094c2f4c(&local_68);
      if (iVar3 == 0) {
        iVar3 = FUN_fffffff0094c519c(&local_68,&DAT_fffffff007f5add8);
        if (iVar3 == 0) {
          pcVar2 = FUN_fffffff0094c3364;
        }
        else {
          iVar3 = FUN_fffffff0094c519c(&local_68,&DAT_fffffff007f5ade8);
          if (iVar3 != 0) {
            uVar4 = 0xa0101;
            goto LAB_fffffff0094c6f48;
          }
          pcVar2 = FUN_fffffff0094c3658;
          param_2 = param_2 >> 1;
        }
      }
      else {
        pcVar2 = FUN_fffffff0094c3158;
        param_2 = param_2 >> 2;
      }
      if (((param_2 & 1) != 0) &&
         (((((param_1 & 1) != 0 &&
            (iVar3 = FUN_fffffff0094c51c8(param_5,&DAT_fffffff00777071e,5), iVar3 == 0)) ||
           (((param_1 >> 2 & 1) != 0 &&
            (iVar3 = FUN_fffffff0094c51c8(param_5,&DAT_fffffff007770723,9), iVar3 == 0)))) ||
          ((((param_1 >> 3 & 1) != 0 &&
            (iVar3 = FUN_fffffff0094c51c8(param_5,&DAT_fffffff00777072c,9), iVar3 == 0)) ||
           ((uVar4 = 0xa0110, (param_1 >> 4 & 1) != 0 &&
            (iVar3 = FUN_fffffff0094c51c8(param_5,&DAT_fffffff007770735,9), iVar3 == 0)))))))) {
        if (((lStack_80 == 0) && (local_88 != 0)) || ((param_4[1] == 0 && (*param_4 != 0))))
        goto LAB_fffffff0094c70e0;
        iVar3 = (*pcVar2)();
        uVar1 = 0;
        if (iVar3 == 0) {
          uVar1 = 0xa0120;
        }
        uVar4 = (ulong)uVar1;
      }
    }
LAB_fffffff0094c6f48:
    if (*(long *)PTR_DAT_fffffff007f5bb60 == local_58) {
      return uVar4;
    }
    uVar4 = thunk_EXT_FUN_8011000003a48590();
    return uVar4;
  }
LAB_fffffff0094c70e0:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c70e4);
  (*pcVar2)();
}

