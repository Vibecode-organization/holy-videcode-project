// FUN_fffffff00a49e4c4 @ fffffff00a49e4c4 size=360

undefined4 FUN_fffffff00a49e4c4(long param_1)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 *puVar6;
  
  if (*(int *)(param_1 + 0x70) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("%s(%p) bad refcnt @%s:%d");
  }
  iVar2 = *(int *)(param_1 + 0x70) + -1;
  *(int *)(param_1 + 0x70) = iVar2;
  if ((iVar2 == 0) && (*(long *)(param_1 + 0x120) != 0)) {
    if ((*(uint *)(param_1 + 0x74) & 0x4002000) != 0x4000000) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("(rt->rt_flags & (RTF_NOIFREF | RTF_IFREF)) == RTF_IFREF",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/net/route.c"
                 ,0xf82);
    }
    FUN_fffffff00a227018(param_1 + 0x60);
    (**(code **)(param_1 + 0x120))(*(undefined8 *)(param_1 + 0x88),0xffffffff);
    *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) & 0xfbffffff;
    *(undefined8 *)(param_1 + 0x120) = 0;
  }
  uVar4 = DAT_fffffff00ad7cd2c;
  if ((DAT_fffffff00ad7cd2c & 1) != 0) {
    if (*(int *)(param_1 + 0x370) != -0x1120532) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114("rtunref: on freed rte=%p @%s:%d");
    }
    uVar1 = *(ushort *)(param_1 + 0x376);
    *(ushort *)(param_1 + 0x376) = uVar1 + 1;
    if ((uVar4 >> 1 & 1) != 0) {
      puVar6 = (undefined8 *)(param_1 + 0x530U) + (ulong)(uVar1 & 3) * 9;
      if ((puVar6 != (undefined8 *)0x0) &&
         ((undefined8 *)(param_1 + 0x650U) <= puVar6 || puVar6 < (undefined8 *)(param_1 + 0x530U)))
      {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a49e62c);
        (*pcVar5)();
      }
      uVar3 = tpidr_el1;
      *puVar6 = uVar3;
      puVar6[4] = 0;
      puVar6[3] = 0;
      puVar6[6] = 0;
      puVar6[5] = 0;
      puVar6[8] = 0;
      puVar6[7] = 0;
      puVar6[2] = 0;
      puVar6[1] = 0;
      FUN_fffffff00a8949d8(puVar6 + 1,8);
    }
  }
  return *(undefined4 *)(param_1 + 0x70);
}

