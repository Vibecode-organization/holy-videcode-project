// FUN_fffffff008169bec @ fffffff008169bec size=240

uint FUN_fffffff008169bec(long param_1,uint param_2,undefined1 *param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  *param_3 = 0;
  if (param_2 < 0x42) {
    switch(param_2) {
    default:
      return *(uint *)(param_1 + 0x3e0);
    case 1:
      return *(uint *)(param_1 + 0x3e0) >> 1;
    case 2:
    case 6:
    case 7:
    case 9:
      return *(uint *)(param_1 + 0x3f4);
    case 3:
      return *(uint *)(param_1 + 0x3f8);
    case 4:
      return *(uint *)(param_1 + 0x3fc);
    case 5:
      return *(uint *)(param_1 + 0x400);
    case 8:
    case 10:
    case 0xb:
    case 0xc:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
      break;
    case 0xd:
      return *(uint *)(param_1 + 0x410);
    case 0x11:
    case 0x12:
    case 0x33:
    case 0x34:
    case 0x35:
      uVar1 = *(uint *)(param_1 + 0x414);
      break;
    case 0x3f:
      return *(uint *)(param_1 + 0x404);
    case 0x40:
      return *(uint *)(param_1 + 0x408);
    case 0x41:
      return *(uint *)(param_1 + 0x40c);
    }
  }
  return uVar1;
}

