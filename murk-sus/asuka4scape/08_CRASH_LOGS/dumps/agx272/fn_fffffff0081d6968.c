// FUN_fffffff0081d6968 @ fffffff0081d6968 size=168

/* WARNING: Type propagation algorithm not settling */

ulong FUN_fffffff0081d6968(long param_1,uint param_2,undefined1 *param_3,long *param_4)

{
  ulong uVar1;
  long lVar2;
  
  *param_3 = 0;
  if (param_2 < 0x14) {
    switch(param_2) {
    default:
      lVar2 = *(long *)(param_1 + 0x3b0);
      if (*(long *)(param_1 + 0x3b8) != 0 || lVar2 != 0) {
        *param_3 = 1;
        *param_4 = lVar2;
        param_4[1] = *(long *)(param_1 + 0x3b8);
        return 0;
      }
      return (ulong)*(uint *)(param_1 + 0x3f4);
    case 1:
    case 3:
    case 4:
    case 5:
    case 0xd:
    case 0x10:
    case 0x11:
    case 0x12:
      break;
    case 8:
    case 0xc:
      return 2;
    case 10:
      return 0x40;
    case 0xb:
      return 4;
    case 0xf:
    case 0x13:
      return (ulong)*(uint *)(param_1 + 0x414);
    }
  }
  uVar1 = FUN_fffffff008169bec(param_1);
  return uVar1;
}

