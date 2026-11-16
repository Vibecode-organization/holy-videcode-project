THEOS ?= /opt/theos
LDID ?= /usr/local/bin/ldid
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := IOGPUProbe27
IOGPUProbe27_FILES := main.m
IOGPUProbe27_RESOURCE_FILES := Info.plist
IOGPUProbe27_FRAMEWORKS := UIKit Foundation IOKit IOSurface
IOGPUProbe27_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-variable -Wno-unused-function -fstack-protector-strong -fno-omit-frame-pointer
IOGPUProbe27_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
IOGPUProbe27_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	rm -rf .theos/ipa/Payload/IOGPUProbe27.app
	cp -a .theos/obj/debug/IOGPUProbe27.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/IOGPUProbe27.app/IOGPUProbe27
	cd .theos/ipa && rm -f ../../IOGPUProbe27.ipa && zip -qry ../../IOGPUProbe27.ipa Payload
