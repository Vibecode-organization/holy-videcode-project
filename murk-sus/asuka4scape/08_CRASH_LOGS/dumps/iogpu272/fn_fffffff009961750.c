// FUN_fffffff009961750 @ fffffff009961750 size=228

undefined8 FUN_fffffff009961750(long param_1,long *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_fffffff009961834();
  if ((int)uVar2 == -0x1ffffd43) {
    uVar1 = *(uint *)(param_2 + 6) & (*(uint *)(*(long *)(param_1 + 0x1a8) + 0x1fc) & 0x3fff) >> 0xd
    ;
    (**(code **)(*param_2 + 0x88))(param_2);
    FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x1a8),uVar1);
    FUN_fffffff0099749b8(*(undefined8 *)(param_1 + 0x1a8),uVar1);
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: failed to wire down memory %p. needed %lld, used %lld, size %lld bytes.\n");
  }
  return uVar2;
}

