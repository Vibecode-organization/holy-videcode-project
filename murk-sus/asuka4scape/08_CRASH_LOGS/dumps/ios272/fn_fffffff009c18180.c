// FUN_fffffff009c18180 @ fffffff009c18180 size=292

undefined8 FUN_fffffff009c18180(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined8 uVar7;
  undefined4 local_3c;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  if (*(long *)(param_1 + 0x58) == 0) {
    uVar7 = 0xe00002bd;
    puVar2 = (undefined8 *)thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806bac0,0x70);
    if (puVar2 != (undefined8 *)0x0) {
      lVar3 = thunk_EXT_FUN_80110000038ff010();
      puVar2[0xd] = lVar3;
      if (lVar3 == 0) {
        puVar4 = &DAT_fffffff00806bb10;
      }
      else {
        lVar3 = 0;
        lVar6 = 4;
        do {
          puVar5 = puVar2 + lVar3 * 3 + 1;
          *(undefined1 *)puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          lVar3 = lVar3 + 1;
          lVar6 = lVar6 + -1;
        } while (lVar6 != 0);
        local_3c = 0;
        iVar1 = FUN_fffffff009c36be0
                          (*(undefined8 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x1c),&local_3c
                           ,puVar2);
        if (iVar1 != 0) {
          uVar7 = 0;
          puVar5 = (undefined8 *)*puVar2;
          puVar5[1] = 0;
          *puVar5 = 0;
          puVar5[3] = 0;
          puVar5[2] = 0;
          *(undefined8 **)(param_1 + 0x58) = puVar2;
          goto LAB_fffffff009c18270;
        }
        thunk_EXT_FUN_80110000038ff020(puVar2[0xd]);
        puVar4 = &DAT_fffffff00806bb60;
      }
      thunk_EXT_FUN_80110000038fe768(puVar4,puVar2,0x70);
    }
  }
  else {
    uVar7 = 0;
  }
LAB_fffffff009c18270:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar7;
  }
  uVar7 = thunk_EXT_FUN_8011000003a48590();
  return uVar7;
}

