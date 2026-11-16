# iOS 27.2 (24B115) vs 27.3 beta 1 (24C5037i) — полный diff ядра и кекстов
Дата: 2026-11-11  
Устройство: iPhone14,7 (D27AP, A15/T8110)  
Kernelcache: 27.2 — `02_KERNEL/kc/27.2_24B115_kernelcache`; 27.3 — `02_KERNEL/kc273/24C5037i__iPhone14,7/kernelcache.macho`.
Метод: `ipsw kernel extract -a` для всех кекстов, затем function-shape diff (capstone, нормализация операндов). Адреса и строки — из 27.3. Сырые данные: `02_KERNEL/diff_272_273/`.

## 1. Версии кекстов

Всего в 27.3: 268 кекстов; в 27.2: 267. Новый кекс: com.apple.kec.AppleEncryptedArchive.

Изменения версий:

| kext | 27.2 | 27.3 |
|---|---|---|
| com.apple.AGXFirmwareKextRTBuddy64 | 362.5 | 363.3 |
| com.apple.AGXG14P | 362.5 | 363.3 |
| com.apple.driver.ASIOKit | 27.2.9 | 27.3.3 |
| com.apple.driver.AppleDiskImages2 | 598.40.4 | 598.60.2 |
| com.apple.driver.AppleGameControllerPersonality | 14.1.2 | 14.2.2 |
| com.apple.driver.AppleH11ANEInterface | 10.102.4 | 10.203.200 |
| com.apple.driver.AppleH13CameraInterface | 11.4.0 | 11.5.0 |
| com.apple.driver.AppleHIDKeyboard | 9070.3 | 9070.3.1 |
| com.apple.driver.AppleIDV | 9.108 | 9.204 |
| com.apple.driver.AppleJPEGDriver | 8.1.7 | 8.1.8 |
| com.apple.driver.AppleProResHW | 600.53 | 602 |
| com.apple.driver.AppleProxDriver | 59 | 59.1 |
| com.apple.driver.AudioDMAController-T8110 | 600.45 | 620.2 |
| com.apple.driver.ExclavesAudioKext | 410.2 | 420.2 |
| com.apple.driver.IISAudioIsolatedStreamECProxy | 610.2 | 620.1 |
| com.apple.filesystems.apfs | 3288.42.1 | 3288.60.7 |
| com.apple.iokit.AppleARMIISAudio | 610.2 | 620.1 |
| com.apple.iokit.IOGPUFamily | 162.16.1 | 163.1.4 |
| com.apple.iokit.IOGameControllerFamily | 14.1.2 | 14.2.2 |
| com.apple.iokit.IOSCSIArchitectureModelFamily | 565.40.2 | 565.60.2 |
| com.apple.iokit.IOSCSIBlockCommandsDevice | 565.40.2 | 565.60.2 |
| com.apple.kpi.bsd | 27.2.0 | 27.3.0 |
| com.apple.kpi.dsep | 27.2.0 | 27.3.0 |
| com.apple.kpi.iokit | 27.2.0 | 27.3.0 |
| com.apple.kpi.libkern | 27.2.0 | 27.3.0 |
| com.apple.kpi.mach | 27.2.0 | 27.3.0 |
| com.apple.kpi.private | 27.2.0 | 27.3.0 |
| com.apple.kpi.unsupported | 27.2.0 | 27.3.0 |

Итого изменений версий: 28; новых: 1.

## 2. Общая картина по коду

- **181 кекстов** — 0 изменённых функций по форме. Это metadata/build-only бампы; код идентичен.
- **31 кекстов** — 1–3 изменённых региона.
- **17 кекстов** — 4–20 регионов.
- **13 кекстов** — больше 20 регионов (крупные feature-обновления).
- **com.apple.kernel** — 310 изменённых регионов, 20 571 из 20 901 функций совпали (97.8%). Это главный кластер.

### 2.1. Кексты с 0 изменений (код идентичен)

com.apple.AGXFirmwareKextRTBuddy64, com.apple.driver.ASIOKit, com.apple.driver.AppleDiskImages2, com.apple.driver.AppleGameControllerPersonality, com.apple.driver.AppleH13CameraInterface, com.apple.driver.AppleHIDKeyboard, com.apple.driver.AppleIDV, com.apple.driver.AppleProxDriver, com.apple.driver.AudioDMAController-T8110, com.apple.driver.ExclavesAudioKext, com.apple.driver.IISAudioIsolatedStreamECProxy, com.apple.iokit.IOSCSIBlockCommandsDevice, com.apple.kext.AppleMatch, com.apple.security.sandbox, com.apple.AGXFirmwareKextG14PRTBuddy, com.apple.AppleFSCompression.AppleFSCompressionTypeZlib, com.apple.EXBrightCalibrationConsumer, com.apple.IOTextEncryptionFamily, com.apple.driver.AFKHIDTBDevice, com.apple.driver.AOPTouchKext, com.apple.driver.AppleA7IOP-ASCWrap-v4, com.apple.driver.AppleALSColorSensor, com.apple.driver.AppleAOPAD5860, com.apple.driver.AppleAOPVoiceTrigger, com.apple.driver.AppleARMPMU, com.apple.driver.AppleARMWatchdogTimer, com.apple.driver.AppleAVD, com.apple.driver.AppleActuatorDriver, com.apple.driver.AppleAstrisGpioProbe, com.apple.driver.AppleAudioClockLibs, com.apple.driver.AppleAuthCP, com.apple.driver.AppleAvalancheErrorHandler, com.apple.driver.AppleBSDKextStarter, com.apple.driver.AppleBluetoothDebug, com.apple.driver.AppleBluetoothDebugService, com.apple.driver.AppleBluetoothModule, com.apple.driver.AppleCS35L27Amp, com.apple.driver.AppleCS42L77Audio, com.apple.driver.AppleCSEmbeddedAudio, com.apple.driver.AppleCallbackPowerSource, com.apple.driver.AppleDCP, com.apple.driver.AppleDCPDPTXProxy, com.apple.driver.AppleDialogPMU, com.apple.driver.AppleDockChannel, com.apple.driver.AppleEffaceableBlockDevice, com.apple.driver.AppleEffaceableStorage, com.apple.driver.AppleEmbeddedAudio, com.apple.driver.AppleEmbeddedAudioLibs, com.apple.driver.AppleEmbeddedAudioResourceManager, com.apple.driver.AppleEmbeddedGPS, com.apple.driver.AppleEmbeddedLightSensor, com.apple.driver.AppleEmbeddedMikeyBus, com.apple.driver.AppleEmbeddedPCIE, com.apple.driver.AppleEmbeddedTouchEEPROM, com.apple.driver.AppleEmbeddedUSB, com.apple.driver.AppleEmbeddedUSBHost, com.apple.driver.AppleEventLogHandler, com.apple.driver.AppleFAN53740, com.apple.driver.AppleFireStormErrorHandler, com.apple.driver.AppleFirmwareUpdateKext, com.apple.driver.AppleGPIOCanary, com.apple.driver.AppleGPIOICController, com.apple.driver.AppleGenericMultitouch, com.apple.driver.AppleH10PearlCameraInterface, com.apple.driver.AppleHIDTransport, com.apple.driver.AppleHIDTransportFIFO, com.apple.driver.AppleHIDTransportMailbox, com.apple.driver.AppleHIDTransportSCMCommon, com.apple.driver.AppleHIDTransportSPI, com.apple.driver.AppleHapticsSupportNVM, com.apple.driver.AppleIDAMInterface, com.apple.driver.AppleIISController, com.apple.driver.AppleIPAppender, com.apple.driver.AppleInputDeviceSupport, com.apple.driver.AppleInterruptControllerV2, com.apple.driver.AppleLockdownMode, com.apple.driver.AppleM68Buttons, com.apple.driver.AppleMCA2-T8110, com.apple.driver.AppleMobileApNonce, com.apple.driver.AppleMultitouchDriver, com.apple.driver.AppleMultitouchSPI, com.apple.driver.AppleNANDConfigAccess, com.apple.driver.AppleOnboardSerial, com.apple.driver.ApplePIODMA, com.apple.driver.ApplePMGR, com.apple.driver.ApplePMPFirmware, com.apple.driver.AppleParrot, com.apple.driver.ApplePhoneBTM, com.apple.driver.ApplePhotonDetector, com.apple.driver.AppleS5L8920XPWM, com.apple.driver.AppleS5L8940XI2C, com.apple.driver.AppleS5L8960XNCO, com.apple.driver.AppleS8000AES, com.apple.driver.AppleS8000DWI, com.apple.driver.AppleSART, com.apple.driver.AppleSEPKeyStore, com.apple.driver.AppleSPIMC, com.apple.driver.AppleSPMI, com.apple.driver.AppleSPUSphere, com.apple.driver.AppleSSE, com.apple.driver.AppleSamsungSerial, com.apple.driver.AppleSerialShim, com.apple.driver.AppleSmartIO2, com.apple.driver.AppleStockholmControl, com.apple.driver.AppleSynopsysMIPIDSI, com.apple.driver.AppleT8030SOCTuner, com.apple.driver.AppleT8101TypeCPhy, com.apple.driver.AppleT8110, com.apple.driver.AppleT8110DART, com.apple.driver.AppleT8110PCIe, com.apple.driver.AppleT8110PMGR, com.apple.driver.AppleTemperatureSensor, com.apple.driver.AppleTriStar, com.apple.driver.AppleTypeCPhy, com.apple.driver.AppleUSBAudio, com.apple.driver.AppleUSBCardReader, com.apple.driver.AppleUSBDeviceAudioController, com.apple.driver.AppleUSBDeviceMux, com.apple.driver.AppleUSBEthernetDevice, com.apple.driver.AppleUSBEthernetHost, com.apple.driver.AppleUSBHostMergeProperties, com.apple.driver.AppleUSBMassStorageInterfaceNub, com.apple.driver.AppleUSBMike, com.apple.driver.AppleUSBTopCaseDriver, com.apple.driver.AppleUSBXDCI, com.apple.driver.AppleUSBXDCIARM, com.apple.driver.DCPDPFamilyProxy, com.apple.driver.DiskImages.FileBackingStore, com.apple.driver.DiskImages.KernelBacked, com.apple.driver.DiskImages.RAMBackingStore, com.apple.driver.DiskImages.ReadWriteDiskImage, com.apple.driver.IOAudioCodecs, com.apple.driver.IODARTFamily, com.apple.driver.IOHIDPowerSource, com.apple.driver.IOSlaveProcessor, com.apple.driver.VideoProcessing, com.apple.driver.mDNSOffloadUserClient-Embedded, com.apple.driver.usb.AppleSynopsysUSBXHCI, com.apple.driver.usb.AppleUSBCommon, com.apple.driver.usb.AppleUSBHostCompositeDevice, com.apple.driver.usb.AppleUSBHostDeviceSupport, com.apple.driver.usb.AppleUSBHostPacketFilter, com.apple.driver.usb.AppleUSBHostiOSDevice, com.apple.driver.usb.AppleUSBXHCI, com.apple.driver.usb.IOUSBHostHIDDevice, com.apple.driver.usb.cdc, com.apple.driver.usb.cdc.ecm, com.apple.driver.usb.networking, com.apple.filesystems.tmpfs, com.apple.iokit.AppleSEPGenericTransfer, com.apple.iokit.CoreAnalyticsFamily, com.apple.iokit.IOAccessoryPortUSB, com.apple.iokit.IOAudio2Family, com.apple.iokit.IOBiometricFamily, com.apple.iokit.IOCECFamily, com.apple.iokit.IOCryptoAcceleratorFamily, com.apple.iokit.IODisplayPortFamily, com.apple.iokit.IOHDCPFamily, com.apple.iokit.IOMIPIFamily, com.apple.iokit.IOMikeyBusFamily, com.apple.iokit.IONVMeFamily, com.apple.iokit.IONetworkFamily, com.apple.iokit.IOPCIFamily, com.apple.iokit.IOPortFamily, com.apple.iokit.IOReportFamily, com.apple.iokit.IOSerialFamily, com.apple.iokit.IOSlowAdaptiveClockingFamily, com.apple.iokit.IOStreamFamily, com.apple.iokit.IOTimeSyncFamily, com.apple.iokit.IOUSBDeviceFamily, com.apple.iokit.IOUSBMassStorageDriver, com.apple.iokit.IOUserEthernet, com.apple.kec.Compression, com.apple.kec.Libm, com.apple.kec.pthread, com.apple.nke.l2tp, com.apple.nke.ppp, com.apple.plugin.IOgPTPPlugin, com.apple.security.AKSAnalytics, com.apple.security.AppleImage4, com.apple.security.Image4

### 2.2. Самые маленькие изменения (1–3 региона)

| kext | funcs | identical | ratio | regions |
|---|---|---|---|---|
| com.apple.driver.AppleAOPAudio | 1224/1224 | 1223 | 0.99918 | 1 |
| com.apple.iokit.AppleARMIISAudio | 322/322 | 321 | 0.99689 | 1 |
| com.apple.iokit.IOGameControllerFamily | 672/673 | 672 | 0.99926 | 1 |
| com.apple.iokit.IONetworkingFamily | 861/863 | 860 | 0.99768 | 3 |
| com.apple.iokit.IOSCSIArchitectureModelFamily | 733/733 | 731 | 0.99727 | 2 |
| com.apple.AUC | 239/239 | 238 | 0.99582 | 1 |
| com.apple.driver.AppleAOPHaptics | 153/153 | 152 | 0.99346 | 1 |
| com.apple.driver.AppleARMPlatform | 2237/2237 | 2236 | 0.99955 | 1 |
| com.apple.driver.AppleBasebandM20 | 843/843 | 842 | 0.99881 | 1 |
| com.apple.driver.AppleC26Charger | 602/602 | 601 | 0.99834 | 1 |
| com.apple.driver.AppleConvergedIPCOLYBTControl | 1078/1078 | 1077 | 0.99907 | 1 |
| com.apple.driver.AppleConvergedPCI | 1090/1090 | 1089 | 0.99908 | 1 |
| com.apple.driver.AppleDiagnosticDataAccessReadOnly | 35/35 | 34 | 0.97143 | 1 |
| com.apple.driver.AppleEmbeddedTempSensor | 560/560 | 557 | 0.99464 | 3 |
| com.apple.driver.AppleHapticsSupportLEAP | 1200/1200 | 1199 | 0.99917 | 1 |
| com.apple.driver.AppleMikeyBusAudio | 356/356 | 355 | 0.99719 | 1 |
| com.apple.driver.ApplePMP | 402/402 | 400 | 0.99502 | 2 |
| com.apple.driver.AppleSEPCredentialManager | 1021/1022 | 1019 | 0.99755 | 3 |
| com.apple.driver.AppleSMC | 1009/1009 | 1007 | 0.99802 | 2 |
| com.apple.driver.AppleSMCWirelessCharger | 211/211 | 207 | 0.98104 | 3 |
| com.apple.driver.AppleSPMIPMU | 191/191 | 190 | 0.99476 | 1 |
| com.apple.driver.AppleTopCaseHIDEventDriver | 162/162 | 161 | 0.99383 | 1 |
| com.apple.driver.AppleUSBDeviceNCM | 221/221 | 219 | 0.99095 | 2 |
| com.apple.driver.DCPAVFamilyProxy | 891/891 | 887 | 0.99551 | 2 |
| com.apple.driver.DiskImages | 264/264 | 263 | 0.99621 | 1 |
| com.apple.driver.DiskImages.UDIFDiskImage | 190/190 | 188 | 0.98947 | 2 |
| com.apple.driver.usb.AppleUSBHub | 252/252 | 249 | 0.9881 | 3 |
| com.apple.driver.usb.ethernet.asix | 293/293 | 291 | 0.99317 | 2 |
| com.apple.filesystems.lifs | 462/463 | 461 | 0.99676 | 2 |
| com.apple.iokit.IOAVFamily | 3447/3447 | 3446 | 0.99971 | 1 |
| com.apple.iokit.IOStorageFamily | 562/562 | 561 | 0.99822 | 1 |

Примеры: `AppleARMIISAudio` — 1 функция 1232→1192; `IOGameControllerFamily` — новая 32-байтная функция; `IOSCSIArchitectureModelFamily` — 2 функции +44/+56 байт; `IONetworkingFamily` — +20 байт и две новые функции; `AppleAOPAudio` — 1 функция 496→476.

### 2.3. Средние изменения (4–20 регионов)

| kext | funcs | identical | ratio | regions |
|---|---|---|---|---|
| com.apple.driver.AppleA7IOP | 279/193 | 191 | 0.80932 | 4 |
| com.apple.driver.AppleProResHW | 3014/3014 | 3004 | 0.99668 | 9 |
| com.apple.driver.AppleSEPManager | 2543/2547 | 2534 | 0.99568 | 10 |
| com.apple.driver.AppleSPURose | 669/677 | 657 | 0.97623 | 15 |
| com.apple.driver.usb.cdc.ncm | 354/359 | 349 | 0.97896 | 10 |
| com.apple.filesystems.apfs | 2398/2401 | 2380 | 0.99187 | 16 |
| com.apple.iokit.IOHIDFamily | 2808/2808 | 2793 | 0.99466 | 18 |
| com.apple.driver.AppleAVE2 | 2997/2997 | 2987 | 0.99666 | 10 |
| com.apple.driver.AppleMultiFunctionManager | 264/266 | 260 | 0.98113 | 5 |
| com.apple.driver.AppleOLYHAL | 584/584 | 578 | 0.98973 | 7 |
| com.apple.driver.ApplePPMCPMS | 2184/2184 | 2171 | 0.99405 | 10 |
| com.apple.driver.AppleSPU | 2329/2329 | 2320 | 0.99614 | 8 |
| com.apple.driver.AppleSmartBatteryManagerEmbedded | 695/695 | 688 | 0.98993 | 7 |
| com.apple.driver.FairPlayIOKit | 474/474 | 466 | 0.98312 | 6 |
| com.apple.driver.RTBuddy | 2455/2456 | 2452 | 0.99857 | 4 |
| com.apple.driver.corecapture | 879/879 | 870 | 0.98976 | 8 |
| com.apple.kec.corecrypto | 1954/1954 | 1948 | 0.99693 | 8 |

### 2.4. Крупные изменения (>20 регионов)

| kext | funcs | identical | ratio | regions |
|---|---|---|---|---|
| com.apple.driver.AppleBasebandPCI | 2232/2407 | 1847 | 0.79629 | 172 |
| com.apple.driver.AppleBasebandPCIMAVControl | 1078/1097 | 798 | 0.73379 | 92 |
| com.apple.driver.AppleBasebandPCIMAVPDP | 389/398 | 268 | 0.68107 | 50 |
| com.apple.driver.AppleH11ANEInterface | 5042/5175 | 2947 | 0.57688 | 138 |
| com.apple.driver.AppleMobileDispH14P-DCP | 1881/1881 | 1701 | 0.90431 | 63 |
| com.apple.driver.AppleT8110CLPC | 1343/1341 | 1299 | 0.96796 | 26 |
| com.apple.iokit.IOAccessoryManager | 5012/5018 | 4991 | 0.99521 | 22 |
| com.apple.iokit.IOMobileGraphicsFamily-DCP | 799/802 | 764 | 0.9544 | 27 |
| com.apple.driver.AppleFirmwareKit | 2639/2633 | 2568 | 0.9742 | 44 |
| com.apple.driver.ApplePearlSEPDriver | 754/754 | 731 | 0.9695 | 26 |
| com.apple.iokit.IOSkywalkFamily | 2165/2167 | 2145 | 0.9903 | 21 |
| com.apple.iokit.IOUSBHostFamily | 1976/1976 | 1946 | 0.98482 | 25 |
| com.apple.kernel | 20901/21152 | 20571 | 0.97834 | 310 |

## 3. Ядро (com.apple.kernel) — главное

Сводка diff:

```
funcs 20901 21152
identical 20571 ratio 0.97834
changed regions 310
== insert A[172:172] B[172:204]
   B 0xfffffff00a29ca50 sz=164
   B 0xfffffff00a29caf4 sz=80
```

Кластеры изменений по строкам, которые ссылает 27.3 (адрес — 27.3, функция может быть вставлена/сдвинута):

```
0xfffffff00a29ca50 sz=164 :: 
0xfffffff00a29e354 sz=1136 :: %s: debug exceptions enabled in kernel mode @%s:%d
0xfffffff00a29ec5c sz=1476 :: stackshot: final allocation failed: %d, allocating %u bytes of %u max, try %llu
0xfffffff00a29f8ec sz=528 :: stackshot_tries
0xfffffff00a29fc5c sz=332 :: 
0xfffffff00a2a6af4 sz=304 :: 
0xfffffff00a2a841c sz=228 :: 
0xfffffff00a2a8c58 sz=800 :: 
0xfffffff00a2b1e48 sz=40 :: 
0xfffffff00a2b216c sz=100 :: 
0xfffffff00a2b32ec sz=424 :: (kern_dump_seek_to_next_file) outproc(KDP_SEEK, NULL, %lu, %p) foffset = 0x%llx returned 0 | panic: spinlock acquired check done outside of kernel debugger @%s:%d
0xfffffff00a2c396c sz=1144 :: Expected to deny after handling IPC security policy violation policy %d, but got %d @%s:%d
0xfffffff00a2c43cc sz=1596 :: 0x%llx | Programming error: enum case not handled. @%s:%d
0xfffffff00a2e3fb4 sz=1168 :: panic: %s | /var/log/panic.trace | %s: debug exceptions enabled in kernel mode @%s:%d
0xfffffff00a2e4af8 sz=1828 :: panic(cpu %u caller 0x%lx):  | skipping local kernel core because core file could not be opened prior to panic (mode : 0x
0xfffffff00a2e53b8 sz=196 :: /product
0xfffffff00a2e5614 sz=32 :: 
0xfffffff00a2e5d80 sz=28 :: 
0xfffffff00a2e61b8 sz=236 :: Compressor Info: %u%% of compressed pages limit (%s) and %u%% of segments limit (%s) with 
0xfffffff00a2e6398 sz=196 :: 
0xfffffff00a309240 sz=96 :: 
0xfffffff00a31cb1c sz=4080 :: Unrecognized scheduler IPI type: %d @%s:%d
0xfffffff00a327e1c sz=460 :: 
0xfffffff00a32e8b0 sz=1648 :: idle_thread_create | sched_startup
0xfffffff00a331d38 sz=76 :: kern_invalid mach trap
0xfffffff00a3330d8 sz=756 :: 
0xfffffff00a335058 sz=852 :: task_init @%s:%d
0xfffffff00a3376bc sz=1652 :: task_deallocate(%p): volatile_objects=%d nonvolatile_objects=%d owned=%d
0xfffffff00a356e98 sz=1004 :: %s: debug exceptions enabled in kernel mode @%s:%d
0xfffffff00a37eabc sz=1560 :: corpse for pid %d disabled via SPI | Failed to generate corpse for %s[%d]:  | Corpse released, count at %d
0xfffffff00a38d37c sz=3956 :: vm: %s: vm_compressor_mode == VM_PAGER_NOT_CONFIGURED, returning early | NULL call in %s @%s:%d
0xfffffff00a38ff7c sz=92 :: 
0xfffffff00a390328 sz=408 :: 
0xfffffff00a3905e8 sz=1416 :: /chosen | /private/var | vm: vm_compressor_init: Unable to get swap volume capacity. error=%d
0xfffffff00a390dc8 sz=2696 :: vm: %s: moved %d/%d segments from MAJORQ to AGEQ in %lu.%09u seconds and %d breaks | vm: pre-compaction fragmentation level %u | vm: post-compaction fragmentation level %u
0xfffffff00a391c64 sz=4456 :: c_seg %p has bad c_state = %d @%s:%d | c_seg %p requesting bad c_state = %d @%s:%d
0xfffffff00a39307c sz=820 :: 
0xfffffff00a396e10 sz=140 :: 
0xfffffff00a3975c8 sz=2820 :: c_decompress_page: c_segno %d >= c_segments_available %d, slot_ptr(%p), slot_data(%x) @%s: | c_decompress_page: c_segno %d is free, slot_ptr(%p), slot_data(%x) @%s:%d | c_decompress_page: c_indx %d >= c_nextslot %d, c_seg(%p), slot_ptr(%p), slot_data(%x) @%s:
0xfffffff00a39b268 sz=1740 :: overflow detected @%s:%d
0xfffffff00a39f0d0 sz=512 :: 
0xfffffff00a3a1574 sz=2492 :: need corner case for fictitious page @%s:%d | %s: sptm_get_paddr_type returned failure for paddr 0x%llx @%s:%d | vm_object_upl_request: external object with non-zero paging offset @%s:%d
0xfffffff00a3a2530 sz=4632 :: vm_object_pl_req_begin(%p): overflow | vm_object_paging_begin(%p): overflow | vm_object_update: unexpected error 0x%x from vm_fault_page()
0xfffffff00a3a4248 sz=15168 :: Write fault on compressor map, va: %p type: %u bounds: %p->%p @%s:%d | vm_object_paging_begin(%p): overflow | vm_object_paging_end(%p): underflow
0xfffffff00a3a83c8 sz=400 :: 
0xfffffff00a3a86d8 sz=528 :: 
0xfffffff00a3a8c74 sz=4168 :: %s: pmap %p vaddr 0x%llx prot 0x%x options 0x%x !cs_bypass @%s:%d | %s: pmap %p vaddr 0x%llx prot 0x%x options 0x%x @%s:%d | CODE SIGNING: process %d[%s]: rejecting invalid page (phys#0x%x) at address 0x%llx from of
0xfffffff00a3aa32c sz=9304 :: vm_object_activity_end(%p): underflow | vm_object_paging_begin(%p): overflow | vm_object_paging_end(%p): underflow
0xfffffff00a3ad490 sz=876 :: 
0xfffffff00a3ae518 sz=1756 :: attempting to wire needs_copy memory @%s:%d | vm_object_paging_end(%p): underflow | vm_object_paging_begin(%p): overflow
0xfffffff00a3af218 sz=320 :: vm_object_paging_begin(%p): overflow | vm_fault_unwire_find_page: failure @%s:%d
0xfffffff00a3b2628 sz=728 :: %s: page_list too short @%s:%d | %s: page_list too long @%s:%d
0xfffffff00a3b33e4 sz=636 :: KMEM_KOBJECT or KMEM_COMPRESSOR is required @%s:%d | both KMEM_KOBJECT and KMEM_COMPRESSOR specified @%s:%d
0xfffffff00a3bc634 sz=2272 :: %s: downgrading VM entry [%p, %p) from JIT to non-JIT | vm_map_copyout: wiring %p @%s:%d
0xfffffff00a3c8548 sz=296 :: 
0xfffffff00a3cd9d8 sz=2188 :: vm: vm_map_freeze: FREEZER_ERROR_EXCESS_SHARED_MEMORY. %d pages for pid %d, versus maximum | vm: vm_map_freeze: FREEZER_ERROR_LOW_PRIVATE_SHARED_RATIO. %d/%d pages = ratio of %d for p
0xfffffff00a3cf34c sz=184 :: 
0xfffffff00a3df05c sz=3204 :: vm_object_copy_slowly: unexpected error 0x%x from vm_fault_page() | vm_object_paging_begin(%p): overflow | vm_object_paging_end(%p): underflow
0xfffffff00a3e0c4c sz=140 :: 
0xfffffff00a3e77dc sz=11320 :: 
0xfffffff00a3ea584 sz=9616 :: vm_pageout: no victim @%s:%d
0xfffffff00a3ecff0 sz=1708 :: 
0xfffffff00a3ef6a4 sz=5592 :: need corner case for fictitious page @%s:%d | vm_object_upl_request: contiguous object specified @%s:%d | vm_object_upl_request: external object with non-zero paging offset @%s:%d
0xfffffff00a3f0f68 sz=444 :: 
0xfffffff00a3f1e0c sz=8036 :: vm_object_iopl_request: unexpected error 0x%x from vm_fault_page() | vm_object_iopl_request: Wired page missing. @%s:%d | vm_object_iopl_request: missing/bad page in kernel object @%s:%d
0xfffffff00a3f4b84 sz=1232 :: iopl_valid_data: %p already wired @%s:%d | iopl_valid_data: busy+absent page on page queue @%s:%d | iopl_valid_data: busy page w/o absent @%s:%d
0xfffffff00a3f5568 sz=284 :: 
0xfffffff00a3fdc08 sz=1560 :: 
0xfffffff00a3ff4bc sz=920 :: vm_page_wire(%p): wire_count overflow @%s:%d
0xfffffff00a400f98 sz=764 :: 
0xfffffff00a403dac sz=928 :: 
0xfffffff00a405a00 sz=4540 :: 
0xfffffff00a407230 sz=524 :: 
0xfffffff00a4137f8 sz=2564 :: vm_object_paging_begin(%p): overflow | %s(): upl_request(%p, 0x%llx, 0x%llx) ret %d @%s:%d | vm_object_paging_end(%p): underflow
0xfffffff00a4153a8 sz=4380 :: %s(): delta offset > page size %lld @%s:%d | vm_object_paging_begin(%p): overflow | %s(): upl_request(%p, 0x%llx, 0x%llx) ret %d @%s:%d
0xfffffff00a417aec sz=620 :: 
0xfffffff00a4183c4 sz=2360 :: upl_abort_range: kernel_object being DUMPED @%s:%d | vm_object_activity_end(%p): underflow
0xfffffff00a4351b4 sz=256 :: afDIGHr84A84jh19Kphgp428DNPdnapq | Automatic NMI
0xfffffff00a435bc8 sz=4080 :: 
0xfffffff00a436cbc sz=3700 :: 
0xfffffff00a4380b8 sz=2064 :: 
0xfffffff00a438ecc sz=1864 :: 
0xfffffff00a4396dc sz=876 :: 
0xfffffff00a43abb4 sz=2748 :: overflow detected @%s:%d
0xfffffff00a440728 sz=300 :: 
0xfffffff00a444234 sz=2500 :: vm_object_paging_begin(%p): overflow | %s: vm_fault_page() return unexpected error 0x%x | vm_object_paging_end(%p): underflow
0xfffffff00a4479bc sz=616 :: %s: attempted execute-only mapping @%s:%d | %s: attempt to create kernel TPRO mapping, will produce kernel RX mapping instead. @%s:%d
0xfffffff00a448fd0 sz=416 :: invalid mapping type: %d @%s:%d | %s: sptm_get_paddr_type returned failure for paddr 0x%llx @%s:%d
0xfffffff00a44b654 sz=200 :: 
0xfffffff00a44f474 sz=344 :: 
0xfffffff00a44f97c sz=4700 :: compressed PTE %p 0x%llx has extra bits 0x%llx: corrupted? @%s:%d | pte is COMPRESSED: pte_p=%p ppnum=0x%x @%s:%d | %s: invalid PVH %p @%s:%d
0xfffffff00a4526c4 sz=2012 :: compressed PTE %p 0x%llx has extra bits 0x%llx: corrupted? @%s:%d | %s: sptm_get_paddr_type returned failure for paddr 0x%llx @%s:%d
0xfffffff00a454dc4 sz=6780 :: %s: changing cache attributes of page that may be UAT-mapped, pn=%#x, wimg_bits_prev=%#x,  | %s: invalid PVH %p @%s:%d | %s: unexpected null arguments - state: %p, sptm_ops: %p @%s:%d
0xfffffff00a456ad0 sz=616 :: Failed to pmap_expand for commpage, pmap=%p @%s:%d | No commpage table exists for the wanted page size: %llu @%s:%d | %s: Found something mapped at the commpage address?! @%s:%d
0xfffffff00a45a004 sz=548 :: overflow detected @%s:%d
0xfffffff00a45c630 sz=448 :: %s: sptm_get_paddr_type returned failure for paddr 0x%llx @%s:%d | %s: page 0x%llx is referenced @%s:%d | %s: sptm_check_inflight returned failure for paddr 0x%llx @%s:%d
0xfffffff00a45d3d8 sz=6332 :: chosen/memory-map | Unsupported memory configuration %lx @%s:%d | memory override is too small to boot; check the maxmem/memsize boot-args @%s:%d
0xfffffff00a45f4cc sz=172 :: 
0xfffffff00a465148 sz=40 :: 
0xfffffff00a4652e4 sz=3284 :: Panic lockdown initiated for platform error @%s:%d | Exception on 2-byte instruction, context=%p, esr=%#llx, far=%p @%s:%d | Break 0x%04X instruction exception from kernel. Panic (by design)
0xfffffff00a4661cc sz=1512 :: vm_fault() KERN_FAILURE from user fault on thread %p @%s:%d
0xfffffff00a466cf8 sz=1524 :: Kernel stack memory corruption detected @%s:%d | Kernel tag-check fault on %p @ %#llx prior to vm_map_setup @%s:%d
0xfffffff00a4687c0 sz=720 :: vm_fault() KERN_FAILURE from guest fault on state %p @%s:%d
0xfffffff00a46dc30 sz=140 :: 
0xfffffff00a472998 sz=220 :: 
0xfffffff00a4767cc sz=472 :: 
0xfffffff00a4790bc sz=256 :: 
0xfffffff00a47b6f4 sz=1264 :: %s: VA->PA translation failed for va %p @%s:%d | UAT PPL: invalid state %p @%s:%d
0xfffffff00a4a0b9c sz=1032 :: %p: b_hash.le_prev is not deadbeef @%s:%d | Couldn't register buffer cache callout for vm pressure! @%s:%d
0xfffffff00a4a1af0 sz=2452 :: buffer has UPL, but not marked BUSY: %p @%s:%d | %p: b_hash.le_prev is not deadbeef @%s:%d | blistenterhead: le_prev is deadbeef @%s:%d
0xfffffff00a4a2f58 sz=676 :: buf_biowait
0xfffffff00a4a3528 sz=568 :: buf_invalblkno
0xfffffff00a4bb3e4 sz=1748 :: missing bdev @%s:%d | vnode reclaim in progress @%s:%d | vnode_reclaim_internal: cleaned vnode isn't @%s:%d
0xfffffff00a4bc1a4 sz=348 :: vnode_drain: recursive drain @%s:%d
0xfffffff00a4c1430 sz=6204 :: %s: table is full | %d desired, %ld numvnodes, %ld free, %ld dead, %ld async, %d rage | new_vnode: vp (%p) on RAGE list not marked VLIST_RAGE @%s:%d
0xfffffff00a4c3850 sz=2460 :: vnode_iterate_prepare: newvnode when entering vnode @%s:%d | vnode_dropiocount(%p): v_iocount < 1 @%s:%d | %s: vp %p holdcount overflow from : %d v_tag = %d, v_type = %d, v_flag = %x. @%s:%d
0xfffffff00a4ceda0 sz=5576 :: mount_common(): mount of %s filesystem failed with %d, but vnode list is not empty. @%s:%d | Volume mounted on a device with invalid major number. @%s:%d
0xfffffff00a4d2fb4 sz=2416 :: dounmount: no coveredvp @%s:%d
0xfffffff00a4e33d4 sz=140 :: 
0xfffffff00a4ed128 sz=3108 :: EKEEPLOOKING, but continue flag not set? @%s:%d | Why am I trying to use VNOP_OPEN() on anything other than the root or a named stream? @%s: | EKEEPLOOKING from a filesystem that doesn't support compound VNOPs? @%s:%d
0xfffffff00a4f9584 sz=196 :: 
0xfffffff00a50e474 sz=140 :: 
0xfffffff00a52495c sz=2868 :: %s: %s: does%s support checksum 0x%x if_csum 0x%x | %s: %s: header too large for tso, mss %d | %s: %s: mss %d = len %d / seg cnt %d
0xfffffff00a525684 sz=640 :: %s: fragmented TSO packet? | %s: non-TCP (%d) IPv%c frame %d bytes | %s: m_pullup %d failed
0xfffffff00a526354 sz=2280 :: %s: Short IP packet %d < %d | %s: short IPv6 packet %d < %d | %s: bad IP header length %d < %d
0xfffffff00a529d90 sz=5788 :: %s: %s: %s not forwarding looped back packet | %s: %s from %s count %d head 0x%llx.0x%llx tail 0x%llx.0x%llx | %s: %s not running passing along
0xfffffff00a536af0 sz=9796 :: SIOCSIFESTTHROUGHPUT %s%s up: %u, down: %u | %s: %s SIOCSIFMEDIA ignore IFM_OTHER | ifioctl_req: cmd SIOCSIFMANAGEMENT on %s not allowed for %s:%u
0xfffffff00a5578a4 sz=328 :: 
0xfffffff00a559bd8 sz=1372 :: %s: last vlan on %s | %s: %s: ifnet_detach_protocol failed, %d | vlan_parent_retain: signature is bad @%s:%d
0xfffffff00a55b89c sz=2200 :: %s: %s: siocgifdevmtu failed, %d | ifvlan_retain: bad signature @%s:%d | ifvlan_retain: retain count is 0 @%s:%d
0xfffffff00a55deb0 sz=140 :: 
0xfffffff00a55e238 sz=384 :: 
0xfffffff00a55e714 sz=1088 :: %s: %s: llink remove failed, llink_id 0x%llx, error %d | %s: %s: nx not found | %s: free_provider_instance failed %d
0xfffffff00a561f90 sz=508 :: /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a564868 sz=1140 :: %s: %s: RX ring fini | %s: %s: TX ring fini | %s: %s: thread_call_cancel %s
0xfffffff00a564f88 sz=304 :: /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a5667c0 sz=892 :: %s: %s: policy delete failed (injected) | %s: %s: policy delete: unknown handle 0x%llx | %s: %s: handle 0x%llx
0xfffffff00a574eb0 sz=2968 :: %s: rejecting AF_LINK gateway on index %u with unusable link address (nlen %u, alen %u, sd | %s: bad sockaddr_in %p @%s:%d | %s: bad sockaddr_in6 %p @%s:%d
0xfffffff00a57d914 sz=4908 :: /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a587cbc sz=3776 :: %s - Sending stats report for %x | lck_rw_unlock_exclusive(): lock %p held in mode: %d @%s:%d | /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a58b224 sz=1304 :: %s - NSTAT_DEBUG_SOCKET <pid %d>: NSTAT: UDP - pid %d uid %d euuid %s persona id %d
0xfffffff00a58ba90 sz=1556 :: %s - NSTAT_DEBUG_SOCKET <pid %d>: NSTAT: TCP - pid %d uid %d euuid %s persona id %d
0xfffffff00a592760 sz=1152 :: %s: ifindex %u too big | %s: unexpected protocol %u for inp %p | lck_rw_unlock_shared(): lock %p held in mode: %d @%s:%d
0xfffffff00a5af430 sz=6780 :: %s:  ID Bucket: %d
0xfffffff00a5b165c sz=8800 :: %s: Added kernel policy: socket, id=%d, mask=%llx
0xfffffff00a5b3f68 sz=2928 :: Skip (%u) | SocketFilter (%d) | Pass (%X)
0xfffffff00a5b6a1c sz=1368 :: %s: Added kernel policy: ip output, id=%d, mask=%llx
0xfffffff00a5b8148 sz=5808 :: %s: necp_session_dump_all invalid output buffer (%zu) | %s: Policy: process: %s, result: %s | %s: Cannot write TLV in buffer (TLV length %u, buffer length %u)
0xfffffff00a5bdb2c sz=14888 :: %s: %s(%d) does not hold the necessary entitlement to delegate network traffic for other p | %s: Invalid TLV length (%u) | %s: DATA-TRACE <%s>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote
0xfffffff00a5c8bac sz=7496 :: %s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s r | %s: DATA-TRACE: Socket Policy - INP UPDATE - RESULT - CACHED <MATCHED>: %p (BoundInterface | %s: DATA-TRACE: Socket Policy: <so %llx> (BoundInterface %d Proto %d) Dropping packet beca
0xfffffff00a5cf010 sz=9928 :: %s: DATA-TRACE: <SOCKET - DATA PATH %llx>: START - RESULT - CACHED DROP - <route_allowed % | %s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s r | %s: DATA-TRACE: Socket Policy - Send/Recv - RESULT - CACHED <MATCHED>: %p (BoundInterface 
0xfffffff00a5d5b64 sz=628 :: 
0xfffffff00a5d64e8 sz=452 :: 
0xfffffff00a5dc1f8 sz=496 :: 
0xfffffff00a5dd420 sz=268 :: 
0xfffffff00a5ddb00 sz=936 :: 
0xfffffff00a5deccc sz=1576 :: /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a5df948 sz=1096 :: %s: necp_client_remove close nexus error (%d) MESSAGE TYPE %u | %s: failed to cleanup aop offload stats with error %d | necp_flow_registration_count underflow @%s:%d
0xfffffff00a5dfdd0 sz=1220 :: %s: necp_client_action find fd error (%d) | %s: necp_client_action unknown action (%u)
0xfffffff00a5e1930 sz=1332 :: %s: necp_client_remove copyin client_id error (%d) | %s: necp_client_remove flow_ifnet_stats copyin error (%d) | %s: necp_client_remove unexpected parameters length (%zu)
0xfffffff00a5e26b8 sz=4128 :: %s: necp_client_add_flow copyin client_id error (%d) | %s: necp_client_add_flow invalid client_id (length %zu) | %s: necp_client_add_flow invalid buffer (length %zu)
0xfffffff00a5e7964 sz=1512 :: %s: TLS derived PSK outbound copyin agent_uuid error (%d) | %s: TLS derived PSK outbound copyin params error (%d) | %s: TLS derived PSK outbound: user buffer too small (%zu < %zu)
0xfffffff00a5ed044 sz=68 :: /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a5eea74 sz=6496 :: 
0xfffffff00a5f1644 sz=1136 :: %s: failed to cleanup aop offload stats with error %d
0xfffffff00a5f28c0 sz=304 :: 
0xfffffff00a5f3cfc sz=924 :: 
0xfffffff00a5f6308 sz=12104 :: %s: Register message size too small for agent: (%zu < %zu) | %s: Update message size too small for agent: (%zu < %zu) | %s: Unregister message size too small for UUID: (%zu < %zu)
0xfffffff00a5f969c sz=2168 :: Basic agent parameters do not match, cannot update | netagent_handle_update_inner
0xfffffff00a5fa2a0 sz=616 :: 
0xfffffff00a5fe748 sz=1116 :: %s: TLS derived PSK outbound: service ID too long (%zu > %d)
0xfffffff00a652030 sz=2304 :: %s:%d so %llx filter_control_unit %u kcunit %u | %s:%d CFIL: Failed to get effective audit token for <sockID %llu <%llx>>  | %s:%d CFIL: Failed to get real audit token for <sockID %llu <%llx>> 
0xfffffff00a6542fc sz=1940 :: %s:%d so %llx kcunit %d | %s:%d CFIL: Failed to sign closed msg <sockID %llu <%llx>> | %s:%d ctl_enqueuedata() failed: %d
0xfffffff00a659d94 sz=2036 :: 
0xfffffff00a6797a0 sz=5552 :: %s duplicate IP address %s sent from address %s | /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR | arp: %s moved from %s to %s on %s
0xfffffff00a6a0b94 sz=16036 :: /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR | %{public}s:%d pid %d (%{public}s) is unable to transmit packets on %{public}s | /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a6afea4 sz=3728 :: /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a6b9a30 sz=16212 :: %s - %lx: snd_nxt is %u and snd_una is %u, cnt %d | %s - %lx: offset is negative! len %d off %d | soft error %d silently handled
0xfffffff00a6e0190 sz=636 :: stale RACK segment [%u, %u) flags 0x%x at or below snd_una %u | segment end(%u) can't be smaller than segment start(%u) | clamp partial-below RACK segment [%u, %u) flags 0x%x to snd_una %u
0xfffffff00a6e4628 sz=316 :: 
0xfffffff00a6e4948 sz=296 :: connect
0xfffffff00a6e4d5c sz=748 :: udp (%s:%d): [%s:%u<->%s:%u] interface: %s (skipped: %lu)
0xfffffff00a6e559c sz=6772 :: udp_check_pktinfo error %d | len %d too big error EMSGSIZE | necp_socket_is_allowed_to_send_recv_v4 error %d
0xfffffff00a6f35ac sz=1908 :: (%u): flow_divert_kctl_init - ctl_register failed: %d | /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a6f8afc sz=392 :: (%u): Closing
0xfffffff00a6ff2c4 sz=3436 :: %s - %lx: unable to create subflow socket error %d | %s - %lx: Couldn't find proc for pid %u | %s - %lx: necp_client_register_socket_flow failed with error %d
0xfffffff00a70b5c0 sz=1856 :: /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a73c768 sz=904 :: Could not configure CLAT46 address on interface %s. | /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a747cb4 sz=7388 :: %s: unexpected packet %p @%s:%d | %s: no interface match for packet from %s to %s proto %u received via %s | %s: Layer 3 unicast dst sent to layer 2 non unicast dst: from %s to %s proto %u received v
0xfffffff00a74b030 sz=12704 :: /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR | %{public}s:%d pid %d (%{public}s) is unable to transmit packets on %{public}s | /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a76a0f4 sz=1468 :: scope error in prefix list (%s)
0xfffffff00a76b884 sz=8556 :: %s: %s is blocked by %d waiters | [%s:%d]: NDP cache entry changed from %s -> %s for address %s. | %s: failed to post KEV_ND6_NDFAILURE for %s (err %d)
0xfffffff00a76e234 sz=1292 :: nd_prefix_busy_wait
0xfffffff00a76efd8 sz=664 :: 
0xfffffff00a770778 sz=3976 :: /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a77ae4c sz=1184 :: /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR
0xfffffff00a77bcf8 sz=1552 :: %s: found incorrect prefix proxy route for dst %s on %s | /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR | %s: found prefix proxy route for dst %s
0xfffffff00a77e67c sz=6072 :: %s: skipping RA from %s to %s on %s, accept RA: %d local RA=%d | nd6_ra_input: invalid hlim (%d) from %s to %s on %s | %s: accepting RA from %s to %s on %s, local RA=%d
0xfffffff00a7817c8 sz=3988 :: /Library/Caches/com.apple.xbs/0FDDB9A0-D3A0-4A6E-9008-A106A2DD778C/TemporaryDirectory.lsPR | pfxlist_onlink_check: failed to make %s/%d offlink, errno=%d | in6_init_prefix_ltimes: preferred lifetime(%d) is greater than valid lifetime(%d)
```

Что видно по строкам:

- **VM / compressor**: `c_decompress_page` — новые проверки `c_segno >= c_segments_available`, `c_indx >= c_nextslot`; `vm_object_paging_begin/end` — overflow/underflow; `vm_object_upl_request` / `vm_fault_page` — новые проверки; `vm_page_wire` — wire_count overflow; `vm_map_freeze`; pmap code-signing page rejection. Это ровно тот класс, который нужен для kernel R/W.
- **task / port / IPC**: `task_init`, `task_deallocate` (volatile/nonvolatile objects), IPC security policy violation, `kern_invalid mach trap`.
- **stackshot / panic / kdump**: stackshot allocation, panic trace, kdump seek.
- **scheduler / IPI**: `sched_startup`, idle thread, scheduler IPI type.
- **filesystem / VFS**: `vm_map_freeze`, `/private/var`, `/product`, compressor swap volume.

Вывод: 27.3 — это в первую очередь большое обновление VM/compressor/UPL и фич (ANE, baseband, display, CLPC). Если в 27.2 есть дыра, которую 27.3 закрывает, то она с большой вероятностью в этом VM-кластере. Следующий шаг — декомпилировать пары функций из `kernel_272_273.txt` (особенно `c_decompress_page`, `vm_object_paging_*`, `vm_object_upl_request`, `vm_map_*`) и найти проверку, которой нет в 27.2.

## 4. Безопасность: что реально важно

| Компонент | Что изменилось | Оценка |
|---|---|---|
| `com.apple.security.sandbox` | 0 изменённых функций | код идентичен; sandbox-политика не менялась |
| AMFI | 3 региона: launch constraints ABI + новый 40-байтный хелпер | не security-фикс; DER-проверка уже в 27.2 |
| CoreTrust | 0 изменений (138/138) | код идентичен |
| IOSurface | 0 изменений (1329/1329) | код идентичен |
| AppleJPEGDriver | 2 функции, парсеры не тронуты | не security |
| IOGPU / AGX | feature-изменения, 11 регионов AGX | не похоже на фикс памяти |
| M2Scaler | `validateCompressedTileBuffers` +628 байт, новые проверки tile-data offset/extent | **кандидат на kernel OOB write в 27.2** |
| com.apple.kernel | 310 регионов, VM/compressor/UPL hardening | **главный кандидат на kernel R/W 1-day** |
| новый `com.apple.kec.AppleEncryptedArchive` | 65 768 байт, 4 КБ кода, строки AEA1/AEA_AMK/CK/SK | новая поверхность, требует отдельного разбора |

## 5. Что делать дальше

1. Разобрать VM-пары: `c_decompress_page` (27.3 `0xa3975c8`), `vm_object_paging_begin/end`, `vm_object_upl_request`, `vm_map_*`, `pmap` code signing. Найти проверку, которой нет в 27.2, и триггер из sandbox.
2. Параллельно добить M2Scaler: новые проверки tile-data offset/extent — единственный app-reachable фикс с явным OOB-смыслом.
3. Проверить новый AEA-кекс: кто его вызывает и можно ли подать ему архив из userland.
4. Для каждой найденной пары — декомпиляция 27.2/27.3 и PoC на устройстве.

## 6. Сырые данные

- `02_KERNEL/diff_272_273/shape_summary.md` — priority-кексты.
- `02_KERNEL/diff_272_273/shape_rest_summary.md` — остальные кексты.
- `02_KERNEL/diff_272_273/kernel_272_273.txt` — полный kernel diff.
- `02_KERNEL/diff_272_273/kernel_ident.txt` — changed kernel functions + strings.
- `02_KERNEL/diff_272_273/raw/` — сырые diff-выводы по каждому кексту.
