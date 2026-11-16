THEOS ?= /opt/theos
LDID ?= /home/femboychik/claude_code/.tools/ldid-amd64
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := SPTMProbe8
SPTMProbe8_FILES := main.m
SPTMProbe8_RESOURCE_FILES := Info.plist
SPTMProbe8_FRAMEWORKS := UIKit Foundation IOSurface IOKit
SPTMProbe8_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-variable -fstack-protector-strong -fno-omit-frame-pointer
SPTMProbe8_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
SPTMProbe8_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/SPTMProbe8.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/SPTMProbe8.app/SPTMProbe8
	cd .theos/ipa && rm -f ../../SPTMProbe8.ipa && zip -qry ../../SPTMProbe8.ipa Payload
