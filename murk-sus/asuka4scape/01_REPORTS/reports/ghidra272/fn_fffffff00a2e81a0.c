// FUN_fffffff00a2e81a0 @ fffffff00a2e81a0 size=344

void FUN_fffffff00a2e81a0(long param_1,long *param_2,ulong *param_3,ulong *param_4,ulong param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  uint uVar5;
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 local_88;
  ulong local_80;
  ulong uStack_78;
  
  uVar2 = DAT_fffffff00700d9e0;
  local_80 = 0;
  uStack_78 = 0;
  puVar3 = (undefined8 *)*param_2;
  do {
    if (puVar3 == (undefined8 *)0x0) {
      uVar2 = FUN_fffffff00a2e4c20(param_1,param_3,&local_80,param_5);
      if ((int)uVar2 != 0) {
        return;
      }
      param_4[1] = uStack_78;
      *param_4 = local_80;
      return;
    }
    puVar4 = (undefined8 *)puVar3[1];
    if (0xfff < param_5) {
      uStack_a8 = puVar3[3];
      local_b0 = puVar3[2];
      uStack_98 = puVar3[5];
      local_a0 = *(undefined8 *)*(undefined1 (*) [16])(puVar3 + 4);
      local_88 = puVar3[7];
      uStack_90 = *(undefined8 *)*(undefined1 (*) [16])(puVar3 + 6);
      local_c0 = uVar2;
      uStack_b8 = 0;
      uVar5 = (uint)local_88 & 0xffffd00f | 0x1730;
      if ((local_88 & 0x80) != 0) {
        uVar5 = (uint)local_88 & 0xffffd08f | 0x1310;
      }
      if ((uVar5 >> 0x12 & 1) != 0) {
        FUN_fffffff00a8df19c
                  (*(undefined1 (*) [16])(puVar3 + 6),*(undefined1 (*) [16])(puVar3 + 4),in_s2,in_s3
                   ,in_s4,in_s5,&MACH_HEADER,(short *)&DAT_fffffff00ad98ba0,0,
                   (byte *)"%s: downgrading VM entry [%p, %p) from JIT to non-JIT");
        uVar5 = uVar5 & 0xfffbd7bf;
      }
      local_88 = CONCAT44(local_88._4_4_,uVar5) & 0xfffffffffffffff9;
      puVar3 = &local_c0;
    }
    uVar1 = FUN_fffffff00a2e484c(param_1,(long)puVar3,(long *)&local_80,param_5);
    puVar3 = puVar4;
  } while ((int)uVar1 == 0);
  return;
}

