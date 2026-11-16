// FUN_fffffff008202e54 @ fffffff008202e54 size=492

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff008202e54
               (long param_1,uint param_2,int *param_3,long param_4,undefined8 param_5,int param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  
  puVar2 = *(undefined4 **)(param_1 + 0x68);
  *(undefined4 **)(param_1 + 0x68) = puVar2 + 0x13;
  uVar3 = 0x80000003;
  if (param_6 == 0) {
    uVar3 = 3;
  }
  *puVar2 = uVar3;
  iVar1 = *param_3;
  if (iVar1 < 2) {
    if (iVar1 == 0) {
      lVar4 = param_4 + 0x5d4;
      lVar5 = 0x5d4;
      if (param_6 == 0) {
        lVar5 = 0x5dc;
      }
      if ((*(long *)(param_3 + 0x179) == 0) && (*(long *)(param_3 + 0x17b) == 0)) {
        lVar6 = 0;
      }
      else {
        lVar6 = param_4 + 0x5e4;
      }
      lVar7 = 0x5f4;
      lVar8 = 0x5fc;
      lVar10 = 0x5cc;
      lVar11 = _DAT_fffffff007113cf0;
      lVar12 = _UNK_fffffff007113cf8;
    }
    else {
      if (iVar1 != 1) {
code_r0xfffffff00820300c:
        thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Invalid Channel Command Type\n");
        return;
      }
      lVar4 = param_4 + 0x938;
      lVar5 = 0x938;
      if (param_6 == 0) {
        lVar5 = 0x940;
      }
      if ((*(long *)(param_3 + 0x252) == 0) && (*(long *)(param_3 + 0x254) == 0)) {
        lVar6 = 0;
      }
      else {
        lVar6 = param_4 + 0x948;
      }
      lVar7 = 0x958;
      lVar8 = 0x960;
      lVar10 = 0x930;
      lVar11 = _DAT_fffffff007113ce0;
      lVar12 = _UNK_fffffff007113ce8;
    }
  }
  else if (iVar1 == 2) {
    lVar4 = param_4 + 0x640;
    lVar5 = 0x640;
    if (param_6 == 0) {
      lVar5 = 0x648;
    }
    if ((*(long *)(param_3 + 0x194) == 0) && (*(long *)(param_3 + 0x196) == 0)) {
      lVar6 = 0;
    }
    else {
      lVar6 = param_4 + 0x650;
    }
    lVar7 = 0x660;
    lVar8 = 0x668;
    lVar10 = 0x634;
    lVar11 = _DAT_fffffff007113cd0;
    lVar12 = _UNK_fffffff007113cd8;
  }
  else {
    if (iVar1 != 3) goto code_r0xfffffff00820300c;
    lVar4 = param_4 + 0x2cc;
    lVar5 = 0x2cc;
    if (param_6 == 0) {
      lVar5 = 0x2d4;
    }
    if ((*(long *)(param_3 + 0xb7) == 0) && (*(long *)(param_3 + 0xb9) == 0)) {
      lVar6 = 0;
    }
    else {
      lVar6 = param_4 + 0x2dc;
    }
    lVar7 = 0x2ec;
    lVar8 = 0x2f4;
    lVar10 = 0x2c4;
    lVar11 = _DAT_fffffff007113cc0;
    lVar12 = _UNK_fffffff007113cc8;
  }
  lVar9 = *(long *)((long)param_3 + lVar8);
  *(long *)(puVar2 + 1) = param_4 + lVar10;
  lVar8 = 0;
  if (lVar9 != 0) {
    lVar8 = param_4 + lVar7;
  }
  *(long *)(puVar2 + 3) = lVar4;
  *(long *)(puVar2 + 5) = lVar5 + param_4;
  *(undefined8 *)(puVar2 + 7) = param_5;
  *(long *)(puVar2 + 9) = lVar6;
  *(long *)(puVar2 + 0xd) = param_4 + lVar12;
  *(long *)(puVar2 + 0xb) = param_4 + lVar11;
  *(ulong *)(puVar2 + 0x11) = (ulong)param_2;
  *(long *)(puVar2 + 0xf) = lVar8;
  return;
}

