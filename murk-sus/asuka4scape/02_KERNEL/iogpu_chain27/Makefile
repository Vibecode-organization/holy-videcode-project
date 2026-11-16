THEOS ?= /opt/theos
LDID ?= /usr/local/bin/ldid
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := IOGPUChain27
IOGPUChain27_FILES := main.m
IOGPUChain27_RESOURCE_FILES := Info.plist
IOGPUChain27_FRAMEWORKS := UIKit Foundation IOKit IOSurface
IOGPUChain27_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-variable -Wno-unused-function -fstack-protector-strong -fno-omit-frame-pointer
IOGPUChain27_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
IOGPUChain27_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	rm -rf .theos/ipa/Payload/IOGPUChain27.app
	cp -a .theos/obj/debug/IOGPUChain27.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/IOGPUChain27.app/IOGPUChain27
	cd .theos/ipa && rm -f ../../IOGPUChain27.ipa && zip -qry ../../IOGPUChain27.ipa Payload
