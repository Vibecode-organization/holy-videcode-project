// FUN_fffffff008d5b7c8 @ fffffff008d5b7c8 size=2760
// CALLERS:
//   fffffff00afb9630 no-fn
//   fffffff008df2c88 FUN_fffffff008df283c@fffffff008df283c
// CALLEES:
//   fffffff008df60e0 FUN_fffffff008df60e0
//   fffffff008df5adc FUN_fffffff008df5adc
//   fffffff008df5240 FUN_fffffff008df5240
//   fffffff008cd5954 FUN_fffffff008cd5954
//   fffffff008df60a4 FUN_fffffff008df60a4
//   fffffff008df57b4 FUN_fffffff008df57b4
//   fffffff008df58bc FUN_fffffff008df58bc
//   fffffff008df518c FUN_fffffff008df518c
//   fffffff008df5b18 FUN_fffffff008df5b18
//   fffffff008df6328 FUN_fffffff008df6328
//   fffffff008df62e4 FUN_fffffff008df62e4
//   fffffff008df5058 FUN_fffffff008df5058
//   fffffff008df569c FUN_fffffff008df569c
//   fffffff008df52f4 FUN_fffffff008df52f4
//   fffffff008df527c FUN_fffffff008df527c
//   fffffff008df5cf8 FUN_fffffff008df5cf8
//   fffffff008df536c FUN_fffffff008df536c
//   fffffff008df554c FUN_fffffff008df554c
//   fffffff008df61b8 FUN_fffffff008df61b8
//   fffffff008df5d34 FUN_fffffff008df5d34
//   fffffff008df602c FUN_fffffff008df602c
//   fffffff008df584c FUN_fffffff008df584c
//   fffffff008d5e02c FUN_fffffff008d5e02c
//   fffffff008df636c FUN_fffffff008df636c
//   fffffff008df5ec4 FUN_fffffff008df5ec4
//   fffffff008df545c FUN_fffffff008df545c
//   fffffff008df5114 FUN_fffffff008df5114
//   fffffff008df6230 FUN_fffffff008df6230
//   fffffff008df54d4 FUN_fffffff008df54d4
//   fffffff008df559c FUN_fffffff008df559c
//   fffffff008df5bcc FUN_fffffff008df5bcc
//   fffffff008df571c FUN_fffffff008df571c
//   fffffff008df5c80 FUN_fffffff008df5c80
//   fffffff008df5f28 FUN_fffffff008df5f28
//   fffffff008df5d70 FUN_fffffff008df5d70
//   fffffff008df5e60 FUN_fffffff008df5e60
//   fffffff008df617c FUN_fffffff008df617c
//   fffffff008df61f4 FUN_fffffff008df61f4
//   fffffff008df5dac FUN_fffffff008df5dac
//   fffffff008df5aa0 FUN_fffffff008df5aa0
//   fffffff008df561c FUN_fffffff008df561c
//   fffffff008df55d8 FUN_fffffff008df55d8
//   fffffff008df5204 FUN_fffffff008df5204
//   fffffff008df5498 FUN_fffffff008df5498
//   fffffff008df6438 FUN_fffffff008df6438
//   fffffff008df5150 FUN_fffffff008df5150
//   fffffff008df5c44 FUN_fffffff008df5c44
//   fffffff008df6140 FUN_fffffff008df6140
//   fffffff008df5420 FUN_fffffff008df5420
//   fffffff008df50d8 FUN_fffffff008df50d8
//   fffffff008df5510 FUN_fffffff008df5510
//   fffffff008df509c FUN_fffffff008df509c
//   fffffff008df5ff0 FUN_fffffff008df5ff0
//   fffffff008df5de8 FUN_fffffff008df5de8
//   fffffff008df63f4 FUN_fffffff008df63f4
//   fffffff008df5014 FUN_fffffff008df5014
//   fffffff008df64c0 FUN_fffffff008df64c0
//   fffffff008dc7004 FUN_fffffff008dc7004
//   fffffff008df5cbc FUN_fffffff008df5cbc
//   fffffff008df593c FUN_fffffff008df593c
//   fffffff008df5994 FUN_fffffff008df5994
//   fffffff008df62a8 FUN_fffffff008df62a8
//   fffffff008df5330 FUN_fffffff008df5330
//   fffffff008df53e4 FUN_fffffff008df53e4
//   fffffff008df5a64 FUN_fffffff008df5a64
//   fffffff008df53a8 FUN_fffffff008df53a8
//   fffffff008df5f8c FUN_fffffff008df5f8c
//   fffffff008df63b0 FUN_fffffff008df63b0
//   fffffff008df626c FUN_fffffff008df626c
//   fffffff008df6068 FUN_fffffff008df6068
//   fffffff008df52b8 FUN_fffffff008df52b8
//   fffffff008df59ec FUN_fffffff008df59ec
//   fffffff008df647c FUN_fffffff008df647c
//   fffffff008df51c8 FUN_fffffff008df51c8
//   fffffff008df5b90 FUN_fffffff008df5b90
//   fffffff008df5e24 FUN_fffffff008df5e24
//   fffffff008df5a28 FUN_fffffff008df5a28
//   fffffff008df5c08 FUN_fffffff008df5c08
//   fffffff008df5b54 FUN_fffffff008df5b54

void FUN_fffffff008d5b7c8(long param_1,long param_2,undefined8 param_3)

{
  long *plVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  bool bVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  
  lVar9 = param_1 + 0x150;
  uVar5 = (*(ulong *)(param_1 + 0x1c0) & 0xaaaaaaaaaaaaaaaa) >> 1 |
          (*(ulong *)(param_1 + 0x1c0) & 0x5555555555555555) << 1;
  uVar5 = (uVar5 & 0xcccccccccccccccc) >> 2 | (uVar5 & 0x3333333333333333) << 2;
  uVar5 = (uVar5 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f0f0f0f0f) << 4;
  uVar5 = (uVar5 & 0xff00ff00ff00ff00) >> 8 | (uVar5 & 0xff00ff00ff00ff) << 8;
  uVar5 = (uVar5 & 0xffff0000ffff0000) >> 0x10 | (uVar5 & 0xffff0000ffff) << 0x10;
  uVar2 = *(uint *)(*(long *)(*(long *)(lVar9 + LZCOUNT(uVar5 >> 0x20 | uVar5 << 0x20) * 8) + 0xb8)
                   + 0x158);
  iVar4 = FUN_fffffff008cd5954(4,8);
  if (iVar4 != 0) {
    FUN_fffffff008df5014();
  }
  iVar4 = FUN_fffffff008cd5954(4,8);
  if (iVar4 != 0) {
    FUN_fffffff008df5058();
  }
  iVar4 = FUN_fffffff008cd5954(4,8);
  if (iVar4 != 0) {
    FUN_fffffff008df509c(param_2);
  }
  if ((int)param_3 != 0) {
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df50d8(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5114(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5150(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df518c(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df51c8(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5204(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5240(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df527c(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df52b8(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df52f4(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5330(param_2 + 0xa10);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df536c(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df53a8(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df53e4(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5420(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df545c(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5498(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df54d4(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5510(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df554c(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df559c(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df55d8(param_2);
    }
    uVar10 = 0;
    bVar3 = true;
    do {
      bVar6 = bVar3;
      iVar4 = FUN_fffffff008cd5954(4,8);
      if (iVar4 != 0) {
        FUN_fffffff008df561c(uVar10,param_2 + 0xb48);
      }
      uVar10 = 1;
      bVar3 = false;
    } while (bVar6);
    uVar10 = 0;
    bVar3 = true;
    do {
      bVar6 = bVar3;
      iVar4 = FUN_fffffff008cd5954(4,8);
      if (iVar4 != 0) {
        FUN_fffffff008df569c(uVar10,param_2 + 0xb38);
      }
      uVar10 = 1;
      bVar3 = false;
    } while (bVar6);
    uVar10 = 0;
    bVar3 = true;
    do {
      bVar6 = bVar3;
      lVar11 = 0;
      do {
        iVar4 = FUN_fffffff008cd5954(4,8);
        if (iVar4 != 0) {
          FUN_fffffff008df571c(uVar10,lVar11,param_2 + 0xb98,uVar10);
        }
        lVar11 = lVar11 + 1;
      } while (lVar11 != 3);
      uVar10 = 1;
      bVar3 = false;
    } while (bVar6);
    uVar10 = 0;
    bVar3 = true;
    do {
      bVar6 = bVar3;
      lVar11 = 0;
      do {
        iVar4 = FUN_fffffff008cd5954(4,8);
        if (iVar4 != 0) {
          FUN_fffffff008df57b4(uVar10,lVar11,param_2 + 0xbc8,uVar10);
        }
        lVar11 = lVar11 + 1;
      } while (lVar11 != 3);
      uVar10 = 1;
      bVar3 = false;
    } while (bVar6);
    uVar10 = 0;
    bVar3 = true;
    do {
      bVar6 = bVar3;
      iVar4 = FUN_fffffff008cd5954(4,8);
      if (iVar4 != 0) {
        FUN_fffffff008df584c(uVar10,param_2 + 0xb58);
      }
      uVar10 = 1;
      bVar3 = false;
    } while (bVar6);
    uVar10 = 0;
    bVar3 = true;
    do {
      bVar6 = bVar3;
      iVar4 = FUN_fffffff008cd5954(4,8);
      if (iVar4 != 0) {
        FUN_fffffff008df58bc(uVar10,param_2 + 0xb68);
      }
      uVar10 = 1;
      bVar3 = false;
    } while (bVar6);
    uVar10 = 0;
    bVar3 = true;
    do {
      bVar6 = bVar3;
      lVar11 = 0;
      do {
        iVar4 = FUN_fffffff008cd5954(4,8);
        if (iVar4 != 0) {
          FUN_fffffff008df593c(uVar10,lVar11,param_2 + 0xb5a,uVar10);
        }
        lVar11 = lVar11 + 1;
      } while (lVar11 != 3);
      uVar10 = 1;
      bVar3 = false;
    } while (bVar6);
    uVar10 = 0;
    bVar3 = true;
    do {
      bVar6 = bVar3;
      lVar11 = 0;
      do {
        iVar4 = FUN_fffffff008cd5954(4,8);
        if (iVar4 != 0) {
          FUN_fffffff008df5994(uVar10,lVar11,param_2 + 0xb60,uVar10);
        }
        lVar11 = lVar11 + 1;
      } while (lVar11 != 3);
      uVar10 = 1;
      bVar3 = false;
    } while (bVar6);
    uVar5 = FUN_fffffff008cd5954(4,8);
    if ((uVar5 & 1) != 0) {
      FUN_fffffff008df59ec(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5a28(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5a64(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5aa0(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5adc(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5b18(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5b54(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5b90(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5bcc(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5c08(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5c44(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5c80(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5cbc(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5cf8(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5d34(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5d70(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5dac(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5de8(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5e24(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5e60(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5ec4(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5f28(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5f8c(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df5ff0(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df602c(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df6068(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df60a4(param_2);
    }
    if (uVar2 != 0) {
      uVar5 = 0;
      do {
        iVar4 = FUN_fffffff008cd5954(4,8);
        if (iVar4 != 0) {
          FUN_fffffff008df60e0(param_2 + 0xc88,uVar5);
        }
        uVar5 = uVar5 + 1;
      } while (uVar2 != uVar5);
    }
    uVar5 = FUN_fffffff008cd5954(4,8);
    if ((uVar5 & 1) != 0) {
      FUN_fffffff008df6140(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df617c(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df61b8(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df61f4(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df6230(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df626c(param_2);
    }
    iVar4 = FUN_fffffff008cd5954(4,8);
    if (iVar4 != 0) {
      FUN_fffffff008df62a8(param_2);
    }
  }
  iVar4 = FUN_fffffff008cd5954(4,8);
  if (iVar4 != 0) {
    FUN_fffffff008df62e4();
  }
  uVar10 = FUN_fffffff008cd5954(4,8);
  if ((int)uVar10 != 0) {
    uVar10 = FUN_fffffff008df6328();
  }
  FUN_fffffff008d5e02c(uVar10,1,param_2,param_3);
  iVar4 = FUN_fffffff008cd5954(4,8);
  if (iVar4 != 0) {
    FUN_fffffff008df636c();
  }
  uVar10 = FUN_fffffff008cd5954(4,8);
  if ((int)uVar10 != 0) {
    uVar10 = FUN_fffffff008df63b0();
  }
  FUN_fffffff008d5e02c(uVar10,0,param_2,param_3);
  iVar4 = FUN_fffffff008cd5954(4,8);
  if (iVar4 != 0) {
    FUN_fffffff008df63f4();
  }
  if ((int)param_3 == 0) goto LAB_fffffff008d5c1d4;
  uVar5 = (ulong)*(uint *)(param_2 + 0x428);
  if (*(uint *)(param_2 + 0x428) < 8) {
    uVar7 = *(ulong *)(param_1 + 0x1c0);
    if ((uVar7 >> (uVar5 & 0x3f) & 1) == 0) goto LAB_fffffff008d5c13c;
  }
  else {
    uVar7 = *(ulong *)(param_1 + 0x1c0);
LAB_fffffff008d5c13c:
    uVar5 = (uVar7 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar7 & 0x5555555555555555) << 1;
    uVar5 = (uVar5 & 0xcccccccccccccccc) >> 2 | (uVar5 & 0x3333333333333333) << 2;
    uVar5 = (uVar5 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar5 = (uVar5 & 0xff00ff00ff00ff00) >> 8 | (uVar5 & 0xff00ff00ff00ff) << 8;
    uVar5 = (uVar5 & 0xffff0000ffff0000) >> 0x10 | (uVar5 & 0xffff0000ffff) << 0x10;
    uVar5 = LZCOUNT(uVar5 >> 0x20 | uVar5 << 0x20);
  }
  lVar8 = 0;
  lVar11 = uVar5 * 8;
  plVar1 = (long *)(lVar9 + (int)lVar11);
  if (lVar11 - (int)lVar11 != 0) {
    plVar1 = (long *)(lVar9 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
  }
  lVar9 = *(long *)(*plVar1 + 0xc0);
  bVar3 = true;
  do {
    bVar6 = bVar3;
    if ((*(byte *)(param_2 + 0x38 + lVar8) & 1) != 0) {
      iVar4 = FUN_fffffff008cd5954(4,8);
      if (iVar4 != 0) {
        FUN_fffffff008df6438(lVar8);
      }
      FUN_fffffff008dc7004(*(undefined8 *)(lVar9 + 0x70));
    }
    if ((*(byte *)(param_2 + 0x3a + lVar8) & 1) != 0) {
      iVar4 = FUN_fffffff008cd5954(4,8);
      if (iVar4 != 0) {
        FUN_fffffff008df647c(lVar8);
      }
      FUN_fffffff008dc7004(*(undefined8 *)(lVar9 + 0x80));
      break;
    }
    lVar8 = 1;
    bVar3 = false;
  } while (bVar6);
LAB_fffffff008d5c1d4:
  iVar4 = FUN_fffffff008cd5954(4,8);
  if (iVar4 != 0) {
    FUN_fffffff008df64c0();
  }
  return;
}

