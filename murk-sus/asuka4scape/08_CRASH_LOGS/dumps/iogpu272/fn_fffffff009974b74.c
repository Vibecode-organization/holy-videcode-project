// FUN_fffffff009974b74 @ fffffff009974b74 size=64

ulong FUN_fffffff009974b74(undefined8 param_1,ulong param_2)

{
  param_2 = param_2 / 3;
  if (param_2 < 0x4000001) {
    param_2 = 0x4000000;
  }
  return (param_2 + *(long *)PTR_DAT_fffffff007ff2838) - 1 & -*(long *)PTR_DAT_fffffff007ff2838;
}

