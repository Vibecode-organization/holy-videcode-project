// FUN_fffffff00a6981ac @ fffffff00a6981ac size=1048

undefined8
FUN_fffffff00a6981ac
          (long param_1,long param_2,undefined8 param_3,undefined8 param_4,long param_5,long param_6
          )

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined4 in_wzr;
  long local_58;
  
  if (param_1 == 0) {
    return 0x16;
  }
  if (param_2 == 0) {
    return 0x16;
  }
  if (*(char *)(param_2 + 1) != '\x1e') {
    return 0x2f;
  }
  if (((*(ushort *)(param_1 + 0xd2) ^ 0xffff) & 0x41) != 0) {
    return 0x32;
  }
  local_58 = param_5;
  if ((param_5 != 0) && (uVar2 = FUN_fffffff00a4a14f0(param_2,param_5,&local_58), (int)uVar2 != 0))
  {
    return uVar2;
  }
  lVar4 = local_58;
  if (((param_6 == 0) || ((*(ushort *)(param_6 + 0x1e) >> 9 & 1) == 0)) &&
     ((-1 < *(short *)(param_1 + 0xd2) || (*(char *)(param_2 + 8) != -1)))) {
    if (local_58 == 0) {
      lVar4 = tpidr_el1;
      uVar1 = (ulong)*(uint *)(lVar4 + 0x4e8);
      if (DAT_fffffff00ad95480 != 0) {
        FUN_fffffff00a2262d4(&DAT_fffffff00ad95478,lVar4,0);
        uVar1 = DAT_fffffff00ad95480;
      }
      DAT_fffffff00ad95480 = uVar1;
      lVar5 = FUN_fffffff00a4992fc
                        (1,0,param_2,0,DAT_fffffff00ad85c50,*(undefined2 *)(param_1 + 0xcc));
      local_58 = lVar5;
      if ((int)DAT_fffffff00ad95480 == *(int *)(lVar4 + 0x4e8)) {
        DAT_fffffff00ad95480 = CONCAT44(DAT_fffffff00ad95480._4_4_,in_wzr);
      }
      else {
        FUN_fffffff00a226e08(&DAT_fffffff00ad95478,lVar4);
      }
      if ((lVar5 == 0) || (FUN_fffffff00a49df74(lVar5,0), local_58 == 0)) {
        return 0x37;
      }
    }
    lVar4 = local_58;
    lVar5 = *(long *)(local_58 + 0x80);
    if (*(char *)(lVar5 + 1) != '\x12') {
      FUN_fffffff00a663bbc(param_2 + 8);
      FUN_fffffff00a8df19c
                (&MACH_HEADER,&DAT_fffffff00ad98ba0,0x10,
                 "%s: route %s on %s%d gateway address not AF_LINK\n");
      uVar2 = 0x31;
      goto LAB_fffffff00a698530;
    }
    if (*(char *)(lVar5 + 6) == '\0') {
      FUN_fffffff00a663bbc(param_2 + 8);
      FUN_fffffff00a8df19c
                (&MACH_HEADER,&DAT_fffffff00ad98ba0,0x10,"%s: route %s on %s%d sdl_alen == 0\n");
      uVar2 = 0x41;
      goto LAB_fffffff00a698530;
    }
    uVar2 = FUN_fffffff00a498250(lVar5,param_3,param_4);
    if ((int)uVar2 != 0) {
      FUN_fffffff00a663bbc(param_2 + 8);
      FUN_fffffff00a8df19c
                (&MACH_HEADER,&DAT_fffffff00ad98ba0,0x10,
                 "%s: route %s on %s%d link address does not fit (sdl_alen %u, error %d)\n");
      goto LAB_fffffff00a698530;
    }
  }
  else {
    if (local_58 == 0) {
      uVar2 = FUN_fffffff00a4700c8();
      return uVar2;
    }
    FUN_fffffff00a49deb4(local_58);
    uVar2 = FUN_fffffff00a4700c8(param_1,param_2,param_3,param_4);
    FUN_fffffff00a49df74(lVar4,0);
    if ((int)uVar2 != 0) goto LAB_fffffff00a698530;
  }
  if (*(int *)(param_1 + 0xa68) == 0) {
    uVar2 = 0;
  }
  else {
    uVar3 = FUN_fffffff00a4a2d8c(lVar4,1);
    if (2 < DAT_fffffff00ad95470) {
      FUN_fffffff00a8df19c(&MACH_HEADER,&DAT_fffffff00ad98ba0,1,"nd6_lookup_ipv6:  qset_id=%lld");
    }
    uVar2 = 0;
    if (param_6 != 0) {
      *(uint *)(param_6 + 0xcc) = *(uint *)(param_6 + 0xcc) | 0x8000000;
      *(undefined8 *)(param_6 + 0xd0) = uVar3;
    }
  }
LAB_fffffff00a698530:
  if (lVar4 == param_5) {
    FUN_fffffff00a49e4c4(lVar4);
    FUN_fffffff00a49deb4(lVar4);
  }
  else {
    FUN_fffffff00a49deb4();
    FUN_fffffff00a498684(lVar4,0);
  }
  return uVar2;
}

