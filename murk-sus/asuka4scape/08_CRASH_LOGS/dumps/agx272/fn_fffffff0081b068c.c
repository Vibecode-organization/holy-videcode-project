// FUN_fffffff0081b068c @ fffffff0081b068c size=4

uint * FUN_fffffff0081b068c(long param_1)

{
  undefined *puVar1;
  long *plVar2;
  uint *puVar3;
  ulong uVar4;
  long *plVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  
  plVar2 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))();
  puVar1 = PTR_DAT_fffffff007ca61a8;
  if (plVar2 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"AGXk: alloc block handle failed");
    thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar1,1,"AGXk: alloc block handle failed");
    return (uint *)0x0;
  }
  puVar3 = (uint *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ca1208);
  if (puVar3 == (uint *)0x0) goto LAB_fffffff0081b0a68;
  uVar7 = *(undefined8 *)(param_1 + 0x50);
  uVar6 = *(undefined8 *)(param_1 + 8);
  plVar2[2] = *(long *)(param_1 + 0x20);
  uVar4 = FUN_fffffff0081e07cc(plVar2,uVar6,uVar7,0x100023);
  puVar1 = PTR_DAT_fffffff007ca61a8;
  if ((uVar4 & 1) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"AGXk: alloc block failed");
    thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar1,1,"AGXk: alloc block failed");
  }
  else {
    uVar4 = *(ulong *)(param_1 + 0xa8);
    if ((uVar4 & 6) == 0) {
LAB_fffffff0081b07ec:
      uVar8 = (uint)uVar4;
      if ((uVar4 & 1) != 0) {
        lVar10 = FUN_fffffff0081e0954(plVar2,1,*(undefined4 *)(param_1 + 0xb0),0);
        puVar1 = PTR_DAT_fffffff007ca61a8;
        if (lVar10 == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"AGXk: map block failed for fw");
          thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar1,1,"AGXk: map block failed for fw");
          goto LAB_fffffff0081b0a30;
        }
        uVar8 = (uint)*(undefined8 *)(param_1 + 0xa8);
      }
      if ((uVar8 >> 3 & 1) == 0) goto LAB_fffffff0081b0884;
      plVar5 = (long *)plVar2[0xc];
      if (plVar5 == (long *)0x0) {
        lVar10 = thunk_EXT_FUN_801100000297ea14(plVar2[9],0);
        plVar2[0xc] = lVar10;
        if (lVar10 != 0) {
          LOAcquire();
          DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar2[6];
          LORelease();
          plVar5 = (long *)plVar2[0xc];
          goto LAB_fffffff0081b0840;
        }
      }
      else {
LAB_fffffff0081b0840:
        lVar10 = (**(code **)(*plVar5 + 0x78))();
        if (lVar10 != 0) {
          uVar6 = (**(code **)(*(long *)plVar2[0xc] + 0x78))();
          *(undefined8 *)(puVar3 + 4) = uVar6;
LAB_fffffff0081b0884:
          *(long **)(puVar3 + 2) = plVar2;
          *puVar3 = (uint)(*(int *)(param_1 + 0x2c) != 0);
          return puVar3;
        }
      }
      puVar1 = PTR_DAT_fffffff007ca61a8;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"AGXk: map block failed for cpu");
      thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar1,1,"AGXk: map block failed for cpu");
    }
    else {
      lVar10 = *(long *)(param_1 + 0x18);
      plVar5 = (long *)plVar2[0xb];
      if (plVar5 == (long *)0x0) {
        uVar9 = 0x500000087;
        if ((uVar4 & 4) != 0) {
          uVar9 = 0x100000087;
        }
        plVar5 = (long *)(**(code **)(*(long *)plVar2[9] + 0x90))
                                   ((long *)plVar2[9],lVar10,uVar9 | (uVar4 & 4) << 0x22);
        if (plVar5 != (long *)0x0) {
          (**(code **)(*plVar5 + 0x20))();
          (**(code **)(*plVar5 + 0x28))(plVar5);
          plVar2[0xb] = (long)plVar5;
          goto LAB_fffffff0081b07bc;
        }
      }
      else {
LAB_fffffff0081b07bc:
        if (plVar5[4] != lVar10) {
          puVar3 = (uint *)thunk_EXT_FUN_8011000003a49114
                                     (
                                     "AGXk: %s:%d:%s: !!! Attempting to map into multiple GPU Contexts!\n"
                                     );
          return puVar3;
        }
        lVar10 = (**(code **)(*plVar5 + 0x98))();
        if (lVar10 != 0) {
          uVar4 = *(ulong *)(param_1 + 0xa8);
          goto LAB_fffffff0081b07ec;
        }
      }
      puVar1 = PTR_DAT_fffffff007ca61a8;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"AGXk: map block failed for gpu");
      thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar1,1,"AGXk: map block failed for gpu");
    }
LAB_fffffff0081b0a30:
    if (*(long **)(puVar3 + 2) != (long *)0x0) {
      (**(code **)(**(long **)(puVar3 + 2) + 0x28))();
    }
    puVar3[2] = 0;
    puVar3[3] = 0;
  }
  thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ca1248,puVar3);
LAB_fffffff0081b0a68:
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return (uint *)0x0;
}

