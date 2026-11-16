// FUN_fffffff009c44170 @ fffffff009c44170 size=624
// CALLERS:
//   fffffff009c440ac FUN_fffffff009c4405c@fffffff009c4405c
//   fffffff009c37474 FUN_fffffff009c373ec@fffffff009c373ec
//   fffffff009c3adbc FUN_fffffff009c3ab8c@fffffff009c3ab8c

/* WARNING: Removing unreachable block (ram,0xfffffff009c441e0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff009c44170(long param_1,long param_2)

{
  undefined8 uVar1;
  long *plVar2;
  long lVar3;
  undefined8 *puVar4;
  long *plVar5;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  long local_48;
  
  local_48 = *_DAT_fffffff00806ca40;
  uStack_68 = uRamfffffff0078a12d8;
  local_70 = _DAT_fffffff0078a12d0;
  uStack_58 = 0;
  uStack_60 = 0;
  if (param_2 == 0) {
    FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a1219);
    uVar1 = 0xfffffff00789d8bc;
LAB_fffffff009c443a4:
    FUN_fffffff009c495f4(uVar1);
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    if ((param_2 == *(long *)(param_1 + 0x30)) || (param_2 == *_DAT_fffffff00806ca70))
    goto LAB_fffffff009c443ac;
    if (*(long **)(param_1 + 0xa8) == (long *)0x0) {
      puVar4 = (undefined8 *)*_DAT_fffffff00806ca60;
LAB_fffffff009c442dc:
      plVar2 = (long *)FUN_fffffff009c49804(param_2,0xfffffff00789ce3e);
      plVar5 = (long *)*puVar4;
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x28))(plVar2);
      }
      if (plVar5 != plVar2) {
        lVar3 = FUN_fffffff009c49bd4(param_2);
        if (lVar3 != 0) {
          uVar1 = FUN_fffffff009c49d14();
          FUN_fffffff009c49d04(uVar1,&local_70,0x20);
        }
        FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a11cc);
        uVar1 = 0xfffffff00789d854;
        goto LAB_fffffff009c443a4;
      }
    }
    else {
      uVar1 = (**(code **)(**(long **)(param_1 + 0xa8) + 0xa8))();
      plVar2 = (long *)FUN_fffffff009c49804(param_2,uVar1);
      puVar4 = (undefined8 *)*_DAT_fffffff00806ca60;
      plVar5 = (long *)*puVar4;
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x28))(plVar2);
      }
      if (plVar5 != plVar2) goto LAB_fffffff009c442dc;
    }
    uVar1 = 1;
  }
LAB_fffffff009c443ac:
  if (*_DAT_fffffff00806ca40 != local_48) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff009c49b64(uVar1);
  }
  return;
}

