// FUN_fffffff00817169c @ fffffff00817169c size=212

ulong FUN_fffffff00817169c(long param_1,ulong param_2)

{
  long lVar1;
  long *plVar2;
  float *pfVar3;
  float fVar4;
  
  lVar1 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-sysmem-reserve-percent");
  if ((lVar1 == 0) ||
     (plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(lVar1,*(undefined8 *)PTR_DAT_fffffff007ca6090)
     , plVar2 == (long *)0x0)) {
    fVar4 = 33.333332;
  }
  else {
    pfVar3 = (float *)(**(code **)(*plVar2 + 0xd8))();
    fVar4 = *pfVar3;
  }
  return (*(long *)PTR_DAT_fffffff007ca61e8 + (long)(((100.0 - fVar4) * (float)param_2) / 100.0)) -
         1U & -*(long *)PTR_DAT_fffffff007ca61e8;
}

