// FUN_fffffff0081e6c88 @ fffffff0081e6c88 size=448

undefined8 FUN_fffffff0081e6c88(long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined6 uStack_38;
  undefined2 local_32;
  undefined6 uStack_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff007ca61a0;
  *(undefined8 *)(param_1 + 0x268) = param_4;
  bVar1 = (bool)((byte)((uint)param_4 >> 4) & 1);
  if (*(char *)(param_2 + 0x10968) != '\0') {
    bVar1 = *(char *)(param_2 + 0x10968) == '\x02';
  }
  *(bool *)(param_1 + 0x270) = bVar1;
  iVar2 = (**(code **)(PTR_DAT_fffffff007ca6188 + 0x90))();
  if (iVar2 != 0) {
    uVar3 = thunk_EXT_FUN_801100000296d060(param_1,param_1 + 0x27c,0x24);
    *(undefined4 *)(param_1 + 0x278) = uVar3;
    lVar4 = thunk_EXT_FUN_80110000038ff3d8();
    *(long *)(param_1 + 0x1d0) = lVar4;
    if (lVar4 != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0xffffffff;
      *(undefined1 *)(param_1 + 0x2a0) = 0;
      puVar5 = (undefined8 *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ca2008);
      *puVar5 = &DAT_fffffff007c9d010;
      puVar5[3] = 0;
      *(undefined4 *)(puVar5 + 6) = 0;
      puVar5[0xf] = 0;
      puVar5[0x11] = 0;
      puVar5[0x10] = 0;
      puVar5[0x12] = 0;
      puVar5[2] = 0;
      puVar5[1] = 0;
      uVar6 = thunk_EXT_FUN_80110000038ff010();
      puVar5[10] = 0;
      *(undefined4 *)(puVar5 + 9) = 0;
      puVar5[7] = uVar6;
      puVar5[8] = 0;
      puVar5[0x13] = 0;
      puVar5[0x12] = 0;
      puVar5[0x14] = 0;
      *(undefined8 **)(param_1 + 0x1e0) = puVar5;
      uStack_30 = 0;
      uStack_38 = 0;
      local_32 = 0;
      uStack_40 = 0;
      local_48 = 0;
      uVar7 = (ulong)*(uint *)(param_1 + 0x20);
      thunk_EXT_FUN_80110000037693ec(&local_48,0x1e,"Spill_Metadata_Stack_%d");
      uVar6 = 1;
      (**(code **)(**(long **)(param_1 + 0x1e0) + 0x20))
                (*(long **)(param_1 + 0x1e0),*(long *)(param_1 + 0x10),
                 *(undefined8 *)(*(long *)(param_1 + 0x10) + 0x10a78),&local_48,10,0,param_1,1,uVar7
                );
      goto LAB_fffffff0081e6e18;
    }
  }
  uVar6 = 0;
LAB_fffffff0081e6e18:
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_28) {
    return uVar6;
  }
  uVar6 = thunk_EXT_FUN_8011000003a48590();
  return uVar6;
}

