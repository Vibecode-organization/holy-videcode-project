THEOS ?= /opt/theos
LDID ?= /home/femboychik/claude_code/.tools/ldid-amd64
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := KRWProbe
KRWProbe_FILES := main.m
KRWProbe_RESOURCE_FILES := Info.plist
KRWProbe_FRAMEWORKS := UIKit Foundation IOSurface IOKit
KRWProbe_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-variable -fstack-protector-strong -fno-omit-frame-pointer
KRWProbe_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
KRWProbe_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/KRWProbe.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/KRWProbe.app/KRWProbe
	cd .theos/ipa && zip -qry ../../KRWProbe.ipa Payload
