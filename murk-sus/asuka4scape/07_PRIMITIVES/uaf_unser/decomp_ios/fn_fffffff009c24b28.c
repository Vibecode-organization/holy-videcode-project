// FUN_fffffff009c24b28 @ fffffff009c24b28 size=684
// CALLERS:
//   fffffff009c25608 FUN_fffffff009c255c8@fffffff009c255c8
//   fffffff009c25a88 FUN_fffffff009c25a44@fffffff009c25a44
//   fffffff009c28694 FUN_fffffff009c28650@fffffff009c28650
//   fffffff009c25af0 FUN_fffffff009c25a44@fffffff009c25a44
//   fffffff009c286fc FUN_fffffff009c28650@fffffff009c28650

/* WARNING: Removing unreachable block (ram,0xfffffff009c24ba8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_fffffff009c24b28(long param_1,long *param_2,undefined8 param_3,int *param_4)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined1 *local_a0;
  undefined8 local_98;
  undefined8 *puStack_90;
  undefined8 *local_88;
  long lStack_80;
  undefined8 local_78;
  undefined8 *local_70;
  undefined8 local_68;
  undefined1 local_60;
  undefined8 local_58;
  undefined8 *local_50;
  undefined8 local_48;
  undefined1 local_40;
  long local_38;
  
  local_38 = *_DAT_fffffff00806ca40;
  local_50 = &local_58;
  local_58 = 0;
  local_48 = _DAT_fffffff0078a1288;
  local_40 = 0;
  local_70 = &local_78;
  local_78 = 0;
  local_68 = _DAT_fffffff0078a1288;
  local_60 = 0;
  iVar3 = (*(uint *)(*(long *)(param_1 + 0x178) + 0x20) | 1) + 2;
  *(int *)(*(long *)(param_1 + 0x178) + 0x20) = iVar3;
  *param_4 = iVar3;
  if ((*(long *)(param_1 + 0x1a8) == 0) &&
     (FUN_fffffff009c20460(param_1), *(long *)(param_1 + 0x1a8) == 0)) {
    *(undefined1 *)(local_50 + 3) = 0;
  }
  else if (param_2 == (long *)0x0) {
    lVar4 = FUN_fffffff009c498d4(param_3,*_DAT_fffffff00806c9c8);
    if (lVar4 != 0) {
      local_b0 = _DAT_fffffff00806c9b8;
      local_a8 = _DAT_fffffff0078a1290;
      local_a0 = &LAB_fffffff009c24dd4;
      puStack_90 = &local_58;
      local_98 = 0xfffffff008067268;
      local_88 = &local_78;
      lStack_80 = param_1;
      FUN_fffffff009c49874(lVar4,&local_b0);
    }
  }
  else {
    iVar3 = (**(code **)(*param_2 + 0xb8))(param_2,0xfffffff00789b3c1);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*param_2 + 0xb8))(param_2,0xfffffff00789b3e2);
      if (iVar3 != 0) {
        *(undefined1 *)(local_70 + 3) = 1;
      }
      uVar2 = (**(code **)(**(long **)(param_1 + 0x1a8) + 0xf0))
                        (*(long **)(param_1 + 0x1a8),param_2,param_3);
      *(undefined1 *)(local_50 + 3) = uVar2;
    }
    else {
      *(undefined1 *)(local_50 + 3) = 1;
    }
  }
  FUN_fffffff009c23c30(param_1,0);
  FUN_fffffff009c23c94(param_1);
  if ((((*(byte *)(local_70 + 3) & 1) != 0) && (*(long *)(param_1 + 0x30) != 0)) &&
     (*(long *)(param_1 + 0x378) == 0)) {
    plVar5 = (long *)FUN_fffffff009c2cf30(param_1);
    FUN_fffffff009c49924(*(undefined8 *)(param_1 + 0x30),plVar5);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  bVar1 = *(byte *)(local_50 + 3);
  FUN_fffffff009c49744(&local_78,8);
  FUN_fffffff009c49744(&local_58,8);
  if (*_DAT_fffffff00806ca40 != local_38) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff009c49b64();
  }
  return bVar1 & 1;
}

