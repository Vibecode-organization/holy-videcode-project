TARGET = iphone:clang:latest:15.0
ARCHS = arm64
INSTALL_TARGET_PROCESSES = kaslr_probe

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME = kaslr_probe
kaslr_probe_FILES = main.m
kaslr_probe_RESOURCE_FILES = Info.plist
kaslr_probe_FRAMEWORKS = UIKit IOKit IOSurface
kaslr_probe_CFLAGS := -fobjc-arc -O2 -Wall -Wextra
kaslr_probe_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
# no private SDK headers needed

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	rm -rf .theos/ipa && mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/kaslr_probe.app .theos/ipa/Payload/
	/usr/local/bin/ldid -S .theos/ipa/Payload/kaslr_probe.app/kaslr_probe
	cd .theos/ipa && zip -qry ../../kaslr_probe.ipa Payload
