// FUN_fffffff009955258 @ fffffff009955258 size=124

char * FUN_fffffff009955258(long param_1)

{
  char *pcVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_1 + 0x10);
  if (bVar2 < 0x80) {
    if (bVar2 == 0) {
      return "SysMemPrivate";
    }
    if (bVar2 == 3) {
      return "Group";
    }
  }
  else {
    if (bVar2 == 0x82) {
      return "IOSurface";
    }
    if (bVar2 == 0x80) {
      pcVar1 = "SysMemShared";
      if (*(long *)(param_1 + 0x30) != 0) {
        pcVar1 = "SysMemShared(IOSurface)";
      }
      return pcVar1;
    }
  }
  return "Unknown";
}

