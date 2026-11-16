# Что реально открывается из песочницы приложения (27.2 / 24B115)

Источник: `work/sb272/all.json` (293 SBPL-профиля, сняты из kernelcache), профиль
`container` — база любого стороннего приложения. Плюс живой лог SBX на устройстве.

## 1. Правило, которое всё решает

В `container` есть **безусловное** `(allow iokit-open-service)` и ровно один
`(allow iokit-open-user-client (require-any …))`, где перечислены классы клиентов,
доступные без энтайтлментов и без подписи Apple:

```
AGXCommandQueue                     IOAccelContext
AGXDevice                           IOAccelContext2
AGXSharedUserClient                 IOAccelDevice
AppleJPEGDriverUserClient           IOAccelDevice2
AppleKeyStoreUserClient             IOAccelSharedUserClient
AppleVirtIONeuralEngineDeviceUserClient   IOAccelSharedUserClient2
H11ANEInDirectPathClient            IOAccelSubmitter2
H1xANELoadBalancerDirectPathClient  IOGPUDeviceUserClient
IOSurfaceAcceleratorClient          IOMobileFramebufferUserClient
IOSurfaceRootUserClient             IOSurfaceSendRight
```

Полный список: `sb272/container_allowed_clients.txt` (20 классов).

Это объясняет живой лог: `IOSurfaceRoot open -> kr=0x0`, а `AppleAVE2Driver`
(`0xe00002bd`) и `AGXAcceleratorG14P` (`0xe00002c7`) — отказ, потому что в списке
нет ни `AppleAVE2Driver`, ни голого `AGXAcceleratorG14P` (есть `AGXDevice/AGXCommandQueue`).

## 2. Условно доступные (не для обычного app)

| класс | условие в профиле |
|---|---|
| `AppleAPFSUserClient` | `signing-identifier` = `com.apple.DocumentsApp` или `com.apple.DocumentManagerUICore.Service` — только системные |
| `IOHIDLibUserClient` | `process-attribute is-apple-signed-executable` |
| `IOHIDEventServiceFastPathUserClient` | `extension "com.apple.tcc.kTCCServiceMotionSensors"` (TCC-разрешение пользователя) **или** platform binary |
| `IOUSBHostDevice` | только `accessoryd`, `iapd` |
| `AppleCLPC` | только `temporary-sandbox` |

## 3. Что это значит для var-output (результат C3)

Из 12 пар (таблица, селектор), которые пишут в `structureVariableOutputData` во всём
кеше, из обычного приложения достижимы только IOSurface:

| kext | класс | достижимость |
|---|---|---|
| apfs | `AppleAPFSUserClient` sel 2/8 | нужна подпись Apple — **нет** |
| AppleT8110CLPC | `AppleCLPCUserClient` | только temporary-sandbox — **нет** |
| IOUSBHostFamily | device UC | только accessoryd/iapd — **нет** |
| IOAVFamily | `IOAVServiceUserClient` | класса нет в списке — **нет** |
| IOGameControllerFamily | `IOGCDynamicDeviceProbeUserClient` | класса нет в списке — **нет** |
| IOHIDFamily | sel 4 | только TCC MotionSensors / Apple-подпись — **условно** |
| IOSurface | sel 30 | гейт `com.apple.private.iosurfaceinfo` — **нет** |
| IOSurface | sel 49 | открыт, но буфер пустой — **бесполезно** |

Вывод: легального канала «ядро → app» через var-output у обычного приложения в 27.2 нет.

## 4. Где остаётся поверхность

Реально достижимые из песочницы классы (20 выше) — это в первую очередь
GPU/дисплей/ANE-direct/JPEG/KeyStore. IOSurface уже разобран (60 селекторов,
гейты, memcpy проверены). GPU/MFB-клиенты — следующий непаханый пласт:
их таблицы внешних методов, парсеры пользовательских структур и descriptor-пути.

## 5. Ограничения анализа

- Профили сняты статически из kernelcache; фактическое применение проверено только
  для `IOSurfaceRoot` (живой `kr=0x0`).
- Имена классов взяты из SBPL, не из символов (символов в кеше нет).
