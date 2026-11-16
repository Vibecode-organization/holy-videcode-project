// FUN_fffffff0270de884 @ fffffff0270de884 size=596
// caller fffffff0270e1e38 FUN_fffffff0270e1c90
// caller fffffff0270e1e84 FUN_fffffff0270e1c90
// caller fffffff0270debf4 FUN_fffffff0270debdc
// caller fffffff0270d02e8 FUN_fffffff0270d0298
// caller fffffff0270d3008 FUN_fffffff0270d2f50
// caller fffffff0270d33b4 FUN_fffffff0270d30f8
// caller fffffff0270d1a3c FUN_fffffff0270d1924
// caller fffffff0270d1ae8 FUN_fffffff0270d1924
// caller fffffff0270d220c FUN_fffffff0270d21cc
// caller fffffff0270d2d30 FUN_fffffff0270d2c84
// caller fffffff0270d2e54 FUN_fffffff0270d2e00
// caller fffffff0270dd524 FUN_fffffff0270dd464
// caller fffffff0270dd6a4 FUN_fffffff0270dd66c
// caller fffffff0270df240 FUN_fffffff0270df108
// caller fffffff0270d2b74 FUN_fffffff0270d26a8
// caller fffffff0270d3714 FUN_fffffff0270d34c8
// caller fffffff0270d3a90 FUN_fffffff0270d3970
// caller fffffff0270d3b68 FUN_fffffff0270d3970
// caller fffffff0270dd828 FUN_fffffff0270dd7ec
// caller fffffff0270e02ec FUN_fffffff0270e029c
// caller fffffff0270dfc94 FUN_fffffff0270dfc5c
// caller fffffff0270dfd34 FUN_fffffff0270dfc5c
// caller fffffff0270dffcc FUN_fffffff0270dff8c
// caller fffffff0270e0a60 FUN_fffffff0270e0a18
// caller fffffff0270be7b4 FUN_fffffff0270be6dc
// caller fffffff0270bea18 FUN_fffffff0270be9ec
// caller fffffff0270aebec FUN_fffffff0270aeb0c
// caller fffffff0270aec54 FUN_fffffff0270aeb0c
// caller fffffff0270aef7c FUN_fffffff0270aeed4
// caller fffffff0270af020 FUN_fffffff0270aeed4
// caller fffffff0270bea9c FUN_fffffff0270bea54
// caller fffffff0270b8a3c FUN_fffffff0270b8980
// caller fffffff0270b1598 FUN_fffffff0270b13a4
// caller fffffff0270d3d34 FUN_fffffff0270d3c9c
// caller fffffff0270d3d90 FUN_fffffff0270d3c9c
// caller fffffff0270dbaac FUN_fffffff0270dba08
// caller fffffff0270dbc6c FUN_fffffff0270dbbf8
// caller fffffff0270f2aa4 FUN_fffffff0270f2a54
// caller fffffff0270d5d5c FUN_fffffff0270d4730
// caller fffffff0270d5e24 FUN_fffffff0270d4730
// caller fffffff0270d6204 FUN_fffffff0270d4730
// caller fffffff0270d6268 FUN_fffffff0270d4730
// caller fffffff0270b4214 FUN_fffffff0270b4160
// caller fffffff0270db930 FUN_fffffff0270db85c
// caller fffffff0270b9f04 FUN_fffffff0270b9eb8
// caller fffffff0270c6d74 FUN_fffffff0270c6b24
// caller fffffff0270c7f58 FUN_fffffff0270c7c40
// caller fffffff0270c8054 FUN_fffffff0270c7c40
// caller fffffff0270c81c8 FUN_fffffff0270c7c40
// caller fffffff0270c8264 FUN_fffffff0270c7c40
// caller fffffff0270c9b30 FUN_fffffff0270c9984
// caller fffffff0270dd638 FUN_fffffff0270dd614
// caller fffffff0270dda8c FUN_fffffff0270dd9c0
// caller fffffff0270e8e4c FUN_fffffff0270e8d9c
// caller fffffff0270e9da4 FUN_fffffff0270e97bc
// caller fffffff0270eaf5c FUN_fffffff0270eae10
// caller fffffff0270eb210 FUN_fffffff0270eae10
// caller fffffff0270ebd94 FUN_fffffff0270eba08
// caller fffffff0270ec3a0 FUN_fffffff0270ec14c
// caller fffffff0270ed53c FUN_fffffff0270ecff0
// caller fffffff0270ee798 FUN_fffffff0270ee388
// caller fffffff0270ef460 FUN_fffffff0270ef2bc
// caller fffffff0270efb00 FUN_fffffff0270ef77c
// caller fffffff0270f0404 FUN_fffffff0270f00f4
// caller fffffff0270f053c FUN_fffffff0270f00f4
// caller fffffff0270f0930 FUN_fffffff0270f0840
// caller fffffff0270f0e90 FUN_fffffff0270f0a4c
// caller fffffff0270f182c FUN_fffffff0270f1668
// caller fffffff0270f1be4 FUN_fffffff0270f1940
// caller fffffff0270f2028 FUN_fffffff0270f1eac
// caller fffffff0270f13c0 FUN_fffffff0270f1224

ulong FUN_fffffff0270de884(ulong param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  
  uVar4 = 0;
  if ((param_1 >> 0x2e == 0) && (DAT_fffffff0270914c0 != 0 || DAT_fffffff0270914c4 != 0)) {
    local_40 = 0;
    local_38 = (undefined4)(param_1 >> 0xe);
    uStack_34 = 1;
    if (((uint)DAT_fffffff027102040 >> 0xb & 1) == 0) {
      if (DAT_fffffff0270914c0 != 0) {
        uVar4 = 0;
        do {
          uVar2 = DAT_fffffff0270914c8 + uVar4 * 0x10;
          if (((DAT_fffffff0270914c8 ^ uVar2) & 0xffc0000000000000) != 0) {
            uVar2 = uVar2 & 0xffffffffffff | 0xc8a2000000000000;
          }
          iVar1 = FUN_fffffff0270dead8(&local_40,uVar2);
          if (iVar1 == 0) {
            uVar4 = DAT_fffffff0270914c8 + uVar4 * 0x10;
            if (((DAT_fffffff0270914c8 ^ uVar4) & 0xffc0000000000000) == 0) {
              return uVar4;
            }
            return uVar4 & 0xffffffffffff | 0xc8a2000000000000;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < DAT_fffffff0270914c0);
      }
      if (DAT_fffffff0270914c4 == 0) {
        uVar4 = 0;
      }
      else {
        uVar2 = 0;
        do {
          uVar4 = DAT_fffffff0270914d0 + uVar2 * 0x10;
          if (((DAT_fffffff0270914d0 ^ uVar4) & 0xffc0000000000000) != 0) {
            uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
          }
          iVar1 = FUN_fffffff0270dead8(&local_40,uVar4);
          if (iVar1 == 0) {
            uVar4 = DAT_fffffff0270914d0 + uVar2 * 0x10;
            if (((DAT_fffffff0270914d0 ^ uVar4) & 0xffc0000000000000) == 0) {
              return uVar4;
            }
            return uVar4 & 0xffffffffffff | 0xc8a2000000000000;
          }
          uVar4 = 0;
          uVar2 = uVar2 + 1;
        } while (uVar2 < DAT_fffffff0270914c4);
      }
    }
    else {
      lVar3 = UnkSytemRegRead(3,6,0xf,8,0);
      if (lVar3 == 0) {
        lVar3 = tpidr_el2;
        uVar4 = *(ulong *)(lVar3 + 0x1628);
      }
      else {
        lVar3 = UnkSytemRegRead(3,6,0xf,0xb,1);
        uVar4 = *(ulong *)(lVar3 + 0x1628);
      }
      if (((uVar4 == 0) || (iVar1 = FUN_fffffff0270dead8(&local_40,uVar4), iVar1 != 0)) &&
         ((uVar4 = FUN_fffffff0270a59cc
                             (&local_40,DAT_fffffff0270914c8,DAT_fffffff0270914c0,0x10,
                              FUN_fffffff0270dead8), uVar4 != 0 ||
          (uVar4 = FUN_fffffff0270a59cc
                             (&local_40,DAT_fffffff0270914d0,DAT_fffffff0270914c4,0x10,
                              FUN_fffffff0270dead8), uVar4 != 0)))) {
        if (*(char *)(uVar4 + 2) == '\x1a') {
          if (DAT_fffffff0270930a1 != '\x06') {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff0270f34fc
                      (
                      "%s: Type (%s) class of FTE (%p) does not match the type class of the type-specific-data trying to be retrieved: actual (%d) != requested (%d)."
                      );
          }
          if ((*(byte *)(uVar4 + 4) & 1) != 0) {
            return uVar4;
          }
        }
        lVar3 = UnkSytemRegRead(3,6,0xf,8,0);
        if (lVar3 == 0) {
          lVar3 = tpidr_el2;
        }
        else {
          lVar3 = UnkSytemRegRead(3,6,0xf,0xb,1);
        }
        *(ulong *)(lVar3 + 0x1628) = uVar4;
      }
    }
  }
  return uVar4;
}

