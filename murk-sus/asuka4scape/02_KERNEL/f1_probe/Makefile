THEOS ?= /opt/theos
LDID ?= /usr/local/bin/ldid
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := F1Probe
F1Probe_FILES := main.m
F1Probe_RESOURCE_FILES := Info.plist
F1Probe_FRAMEWORKS := UIKit Foundation IOKit IOSurface Metal CoreVideo
F1Probe_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-variable -Wno-unused-function
F1Probe_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
F1Probe_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	rm -rf .theos/ipa/Payload/F1Probe.app
	cp -a .theos/obj/debug/F1Probe.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/F1Probe.app/F1Probe
	cd .theos/ipa && rm -f ../../F1Probe.ipa && zip -qry ../../F1Probe.ipa Payload
