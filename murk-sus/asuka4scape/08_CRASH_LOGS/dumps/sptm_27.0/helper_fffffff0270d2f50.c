// FUN_fffffff0270d2f50 @ fffffff0270d2f50 size=424
// caller fffffff02709b110 FUN_fffffff02709b0c8
// caller fffffff0270bd4bc FUN_fffffff0270bd494
// caller fffffff0270bd4d8 FUN_fffffff0270bd494
// caller fffffff0270bdd14 FUN_fffffff0270bd58c
// caller fffffff0270d2e34 FUN_fffffff0270d2e00
// caller fffffff0270dd500 FUN_fffffff0270dd464
// caller fffffff0270d36e0 FUN_fffffff0270d34c8
// caller fffffff0270d3b38 FUN_fffffff0270d3970
// caller fffffff0270abe64 FUN_fffffff0270abc74
// caller fffffff0270be71c FUN_fffffff0270be6dc
// caller fffffff0270be730 FUN_fffffff0270be6dc
// caller fffffff0270ac3fc FUN_fffffff0270ac298
// caller fffffff0270ac7bc FUN_fffffff0270ac614
// caller fffffff0270ad414 FUN_fffffff0270ad28c
// caller fffffff0270ad7bc FUN_fffffff0270ad5a4
// caller fffffff0270ad960 FUN_fffffff0270ad8a4
// caller fffffff0270addc0 FUN_fffffff0270ada40
// caller fffffff0270ae3b0 FUN_fffffff0270ae210
// caller fffffff0270ae6a4 FUN_fffffff0270ae534
// caller fffffff0270ae998 FUN_fffffff0270ae830
// caller fffffff0270aed08 FUN_fffffff0270aeb0c
// caller fffffff0270af0ec FUN_fffffff0270aeed4
// caller fffffff0270afeb4 FUN_fffffff0270af4d4
// caller fffffff0270aff94 FUN_fffffff0270af4d4
// caller fffffff0270b67f4 FUN_fffffff0270b6710
// caller fffffff0270b6bf4 FUN_fffffff0270b6b70
// caller fffffff0270b6c58 FUN_fffffff0270b6b70
// caller fffffff0270d3d1c FUN_fffffff0270d3c9c
// caller fffffff0270dba8c FUN_fffffff0270dba08
// caller fffffff0270dbc4c FUN_fffffff0270dbbf8
// caller fffffff0270b386c FUN_fffffff0270b2224
// caller fffffff0270b3ef4 FUN_fffffff0270b3e48
// caller fffffff0270b3f40 FUN_fffffff0270b3e48
// caller fffffff0270d4b30 FUN_fffffff0270d4730
// caller fffffff0270d4b58 FUN_fffffff0270d4730
// caller fffffff0270d5f84 FUN_fffffff0270d4730
// caller fffffff0270d5fa0 FUN_fffffff0270d4730
// caller fffffff0270d9690 FUN_fffffff0270d841c
// caller fffffff0270b507c FUN_fffffff0270b5000
// caller fffffff0270b7480 FUN_fffffff0270b7378
// caller fffffff0270ddd28 FUN_fffffff0270dd9c0
// caller fffffff0270ddd48 FUN_fffffff0270dd9c0
// caller fffffff0270e9d44 FUN_fffffff0270e97bc
// caller fffffff0270eb1b8 FUN_fffffff0270eae10
// caller fffffff0270ebd3c FUN_fffffff0270eba08
// caller fffffff0270ec348 FUN_fffffff0270ec14c
// caller fffffff0270ed4dc FUN_fffffff0270ecff0
// caller fffffff0270ee758 FUN_fffffff0270ee388
// caller fffffff0270ef428 FUN_fffffff0270ef2bc
// caller fffffff0270efac8 FUN_fffffff0270ef77c
// caller fffffff0270f050c FUN_fffffff0270f00f4
// caller fffffff0270f08f8 FUN_fffffff0270f0840
// caller fffffff0270f0e58 FUN_fffffff0270f0a4c
// caller fffffff0270f17dc FUN_fffffff0270f1668
// caller fffffff0270f19e8 FUN_fffffff0270f1940
// caller fffffff0270f19f4 FUN_fffffff0270f1940
// caller fffffff0270f1b94 FUN_fffffff0270f1940
// caller fffffff0270f1fd8 FUN_fffffff0270f1eac
// caller fffffff0270f1368 FUN_fffffff0270f1224
// caller fffffff0270abb40 FUN_fffffff0270ab9e0

long FUN_fffffff0270d2f50(ulong param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  ulong *puVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  ulong uVar7;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: papt_to_phys(0) encountered.");
  }
  if (((uint)DAT_fffffff027102040 >> 8 & 1) == 0) {
    uVar7 = param_1 - DAT_fffffff027090ff0;
    uVar4 = DAT_fffffff0270921c8;
  }
  else {
    uVar4 = (ulong)DAT_fffffff0270fd9f8;
    if (DAT_fffffff0270fd9f8 != 0) {
      lVar5 = 0;
      do {
        plVar6 = &DAT_fffffff0270fda00 + lVar5 * 3;
        if ((((ulong)plVar6 ^ 0xfffffff0270fda00) & 0xffc0000000000000) != 0) {
          plVar6 = (long *)((ulong)plVar6 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar7 = plVar6[1];
        if ((uVar7 <= param_1) && (param_1 < uVar7 + (ulong)*(uint *)(plVar6 + 2) * 0x4000)) {
          return (param_1 - uVar7) + *plVar6;
        }
        lVar5 = lVar5 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    if (DAT_fffffff0270921f8 < DAT_fffffff0270921c8 || DAT_fffffff0270921d0 <= DAT_fffffff0270921f8)
    {
      puVar1 = (undefined2 *)FUN_fffffff0270de884();
      puVar2 = &DAT_fffffff0270fdec0;
      if (puVar1 != (undefined2 *)0x0) {
        puVar2 = puVar1;
      }
    }
    else {
      puVar2 = (undefined2 *)
               (DAT_fffffff0270914f0 +
               (DAT_fffffff0270921f8 - DAT_fffffff0270921c8 >> 0xe & 0xffffffff) * 0x10);
    }
    puVar3 = (ulong *)FUN_fffffff0270d13d4(puVar2,param_1,3,0,0);
    if (puVar3 == (ulong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: %s: No leaf table present for PAPT va %p");
    }
    if (((~(uint)*puVar3 & 3) != 0) &&
       ((param_1 < DAT_fffffff027091000 || (DAT_fffffff027091008 <= param_1)))) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: No valid PAPT mapping found while traversing the page tables");
    }
    uVar7 = *puVar3 & 0xfffffffff000;
    uVar4 = param_1 & 0x3fff;
  }
  return uVar7 + uVar4;
}

