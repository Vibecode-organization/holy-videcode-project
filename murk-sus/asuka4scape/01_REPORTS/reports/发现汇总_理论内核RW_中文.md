# iOS 27.2（24B115）iPhone14,7 / T8110 — 发现汇总与理论内核 R/W

> 本文只记录**在设备上验证过**的事实与**有依据的理论路径**，不写推测当真。

---

## 一、已确认（真机 iPhone14,7，27.2 24B115，uid=501）

| 项 | 结果 |
|---|---|
| `IOServiceOpen("IOSurfaceRoot")` | **kr=0x0** — 沙箱 App 可直接打开内核 user client |
| `AppleAVE2Driver` | 0xe00002bd（NoMemory） |
| `AGXAcceleratorG14P` | 0xe00002c7（Unsupported） |
| `AppleAVE2Interface` / `AppleH11ANEInterface` | `no service` |
| 对照组：不存在的类 | `no service` |
| 对照组：`AppleMobileFileIntegrity` | 0xe00002e2（NotPermitted） |

对照组证明日志是真实内核返回值，不是伪造。

### 直接调用 user client（sel 0..12 实测）

| 选择子 | 功能 | 输入 | 输出 | 实测 |
|---|---|---|---|---|
| **0** | **创建 IOSurface** | 1 个标量（parent id，0=无）+ NUL 结尾 XML plist | 0xc68 字节 | **kr=0x0，id=13** |
| 2 | 增加引用 + 信息 | struct 0xc | struct 0xc68 | kr=0x0 |
| 3 | 减少引用 | struct 0xc | 4 字节 | kr=0x0 |
| 9 | 设置属性 | struct 0xc + plist | 4 字节 | kr=0x0 |
| 10 | 读取属性 | struct 0xc + key | 变长 | kr=0x0（返回序列化值） |
| 11 | 删除属性 | struct 0xc + key | 4 字节 | kr=0x0 |
| 1 | 按 ID 释放 | 1 个标量 | — | 0xe00002c2（格式不同，未深究） |

创建成功的返回结构：`0x88` 头 + 20 条平面记录 × `0x98`；surface id 位于 `info+0x18`。

### 关键修正

`0xfffffff008069e50` 处的 13 项表**不是方法表**，而是 `IOConnectTrap0..6` 的 trap 表
（处理函数直接吃 x1..x6 原始寄存器）。真正的分发在
`0x9c3ee10 → IOUserClient2022::dispatchExternalMethod`，方法表 **60 项**：
普通客户端 `0xfffffff008068b90`，`com.apple.private.gpu-restricted` 客户端
`0xfffffff0080694f0`（后者**收回**权限，不是增加）。

---

## 二、27.2 修了什么（静态确认，含地址）

| CVE | 组件 | 类型 | 27.2 修复函数 |
|---|---|---|---|
| 2026-112507 | `rt_setgate` | OOB write | `0xfffffff00a49c4e0` |
| 2026-112476 | `rtsock_msg_buffer` / `nd6_lookup_ipv6` | OOB read | `0xa497e90` / `0xa6981ac` |
| 2026-112576 | `vm_fault_copy` | COW 完整性 | `0xa2cf230` |
| 2026-112665 | NECP / CFIL DATA-TRACE | 内核指针泄露 | `0xa4ecdf8` / `0xa396010` |
| 2026-84495 / 112474 | IGMP / MLD | UAF→写 | `0xa590dbc` / `0xa68a1d0` |
| 2026-65350 / 112679 | `tty_ptmx` knote | UAF | `0xa783590` |
| 2026-112517 | `mach_exception_raise` | UAF（端口引用） | `0xa211aa8` |
| 2026-112606 | skywalk | 类型混淆 | `0xa8760d8` |
| 2026-112477 | IOSurface | 竞态 | `0x9c35850` / `0x9c35ad4` |

审计结论：**未发现 27.2 中仍然存活的、App 可达的内存破坏同级路径**。
唯一未定的 App 可达候选是 `vm_map_remap_extract` 中 `vmkf_remap_prot_copy` 的 COW 豁免分支（`0xa2e902c`）。

---

## 三、理论内核 R/W 路径

### 路径 A：回退到 ≤27.1（漏洞仍在）

1. **KASLR**：CVE-2026-112665，NECP/CFIL trace 打印内核指针 → `slide = leak - 静态地址`。
2. **写原语**：CVE-2026-112507，`PF_ROUTE` + `RTM_ADD`，`sockaddr_dl.sdl_alen` 超长 → `rt_setgate` 堆越界写，长度与内容可控。
3. **变成任意读写**：堆喷 `IOSurface` 对象（0x3e0）；用越界写改某个 surface 的 `base` / `allocSize`；
   调用 `IOSurfaceGetBaseAddress` → 用户态直接映射任意内核内存 → 得到 kread/kwrite。
   （备选目标：`struct pipe` 的 `pipe_buffer`、`task->cred`。）

### 路径 B：27.2 上（本文重点）

已确认可以直接调用 **属性解析器**：`sel 0` → `FUN_0x9c1a914` → `FUN_0x9c1af14`
（14 KB 几何校验，**27.2 未改动**）。

理论链条：
1. 用 sel 0 发送构造好的压缩平面属性，触发校验器中的越界/整数问题；
2. 越界写目标是内核堆对象（surface 的 plane 数组 `0x3c` 记录、或相邻对象）；
3. 改 `IOSurface.base/allocSize` → `IOSurfaceGetBaseAddress` 得到任意映射；
4. 封装 `kread64/kwrite64`。

目前已排查：
- plane 记录数组写入 `base[idx*0x3c+0x20]` 有边界检查（`(end-base) < (idx+1)*0x3c`），32 位比较带溢出保护；
- `(DataRegionBytesPerSlice + HeaderRegionBytesPerSlice) * sliceCount` 是 32 位乘，会溢出，
  但实测四个溢出配置全部 `rejected` —— 该校验在 27.2 有效，且该乘积不参与内核内存操作。

尚待排查的：校验器其余 3000+ 行中的派生几何（tile header、slice 布局、HTPC 预测选择器）。

### 路径 C：已确认但未利用

`IOSurfaceRootUserClient` sel 0 的返回结构里包含 surface 的映射基址（用户态 VA）；
若能把 `allocSize` 或 plane 偏移改大，`IOSurfaceGetBaseAddress` 会映射超出真实分配，
即越界映射 → 内核/相邻进程内存可读写。这是路径 B 成功后的标准收尾。

---

## 四、当前工具状态

| 工具 | 状态 |
|---|---|
| `probe/out/KRWProbe.ipa` | 已验证 1.0：CREATE 全链路 kr=0x0 |
| 1.1 MUTATE | 已构建（变异 fuzzer，基于有效配置） |
| 1.2 HARD | 构建中：几何矩阵 + 结构形状滥用 + 并发竞态 |
| `reports/DISPATCHER_RE.md` | 完整 ABI（60 方法） |
| `reports/KCORE_FIX_AUDIT.md` | 27.2 修复审计（8 个 CVE，含地址与判定） |
| `reports/COW_SIBLING.md` | `vm_map_remap_extract` 候选（进行中） |

---

## 五、结论

- **27.2 上目前没有拿到内核 R/W**：已知漏洞全部修复，未发现存活同级路径。
- **但入口已经打通**：沙箱 App 可以直接、按正确 ABI 调用 IOSurface 内核解析器，
  这是之前没有的能力。下一步是把这个入口当作 fuzz 面，针对 `FUN_0x9c1af14` 的几何校验找 0day。
- **回退到 ≤27.1 时**，路径 A 是完整可实施的：泄露 + 写 + IOSurface 映射，三步入 kread/kwrite。
