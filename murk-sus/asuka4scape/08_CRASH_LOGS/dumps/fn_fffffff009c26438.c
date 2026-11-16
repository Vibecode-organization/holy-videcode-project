// FUN_fffffff009c26438 @ fffffff009c26438 size=448
// CALLERS:
//   fffffff00afebd9d no-fn
//   fffffff007e61118 no-fn
//   fffffff00802a258 no-fn
//   fffffff009c3d890 FUN_fffffff009c3d838@fffffff009c3d838
//   fffffff008e0049c thunk_FUN_fffffff009c26438@fffffff008e00490
//   fffffff009abd9e8 thunk_FUN_fffffff009c26438@fffffff009abd9dc
// CALLEES:
//   fffffff009c49b94 thunk_FUN_fffffff00aa65cc0
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8
//   fffffff009c49c74 thunk_FUN_fffffff00aa65b10
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590

/* WARNING: Removing unreachable block (ram,0xfffffff009c264a4) */

void FUN_fffffff009c26438(long param_1,undefined8 *param_2,ulong *param_3)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined2 local_78;
  undefined2 local_76;
  undefined8 local_74;
  uint local_6c;
  undefined4 local_68;
  undefined2 local_64;
  undefined2 local_62;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_54;
  undefined2 local_50;
  undefined2 local_4e;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0x50));
  lVar2 = *(long *)(param_1 + 0x178);
  uStack_c8 = *(undefined8 *)(lVar2 + 0x3c);
  local_d0 = *(undefined8 *)(lVar2 + 0x34);
  uStack_b8 = *(undefined8 *)(lVar2 + 0x4c);
  uStack_c0 = *(undefined8 *)(lVar2 + 0x44);
  uStack_a8 = *(undefined8 *)(lVar2 + 0x5c);
  local_b0 = *(undefined8 *)(lVar2 + 0x54);
  local_a0 = *(undefined8 *)(lVar2 + 100);
  local_98 = *(undefined8 *)(lVar2 + 0x6c);
  uStack_88 = *(undefined8 *)(lVar2 + 0x7c);
  local_90 = *(undefined8 *)(lVar2 + 0x74);
  local_80 = *(undefined8 *)(lVar2 + 0x84);
  local_78 = *(undefined2 *)(lVar2 + 0x8c);
  local_76 = *(undefined2 *)(lVar2 + 0x8e);
  local_74 = *(undefined8 *)(lVar2 + 0x90);
  local_68 = *(undefined4 *)(lVar2 + 0x9c);
  local_64 = *(undefined2 *)(lVar2 + 0xa0);
  local_62 = *(undefined2 *)(lVar2 + 0xa2);
  local_60 = *(undefined4 *)(lVar2 + 0xa4);
  local_6c = (uint)*(uint3 *)(lVar2 + 0x98);
  local_5c = *(undefined8 *)(lVar2 + 0xa8);
  local_54 = *(undefined4 *)(lVar2 + 0xb0);
  local_50 = *(undefined2 *)(lVar2 + 0xb4);
  local_4e = *(undefined2 *)(lVar2 + 0xb6);
  uVar3 = *param_3;
  uVar1 = uVar3;
  if (0x83 < uVar3) {
    uVar1 = 0x84;
  }
  thunk_FUN_fffffff00aa65b10(param_2,&local_d0,uVar1);
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0x50));
  if (0 < (long)(uVar3 - uVar1)) {
    thunk_FUN_fffffff00aa65cc0((undefined8 *)((long)param_2 + uVar1),uVar3 - uVar1);
  }
  *param_3 = uVar1;
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_48) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return;
}

