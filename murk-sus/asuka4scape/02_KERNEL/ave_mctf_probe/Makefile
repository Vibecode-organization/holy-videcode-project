THEOS ?= /opt/theos
LDID ?= /usr/local/bin/ldid
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := AVEMCTFProbe
AVEMCTFProbe_FILES := main.m
AVEMCTFProbe_RESOURCE_FILES := Info.plist
AVEMCTFProbe_FRAMEWORKS := UIKit Foundation VideoToolbox CoreMedia CoreVideo IOSurface IOKit
AVEMCTFProbe_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-variable -Wno-unused-function
AVEMCTFProbe_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
AVEMCTFProbe_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	rm -rf .theos/ipa/Payload/AVEMCTFProbe.app
	cp -a .theos/obj/debug/AVEMCTFProbe.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/AVEMCTFProbe.app/AVEMCTFProbe
	cd .theos/ipa && rm -f ../../AVEMCTFProbe.ipa && zip -qry ../../AVEMCTFProbe.ipa Payload
