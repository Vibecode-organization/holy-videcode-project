THEOS ?= /opt/theos
LDID ?= /home/femboychik/claude_code/.tools/ldid-amd64
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := SPTMProbe6
SPTMProbe6_FILES := main.m
SPTMProbe6_RESOURCE_FILES := Info.plist
SPTMProbe6_FRAMEWORKS := UIKit Foundation IOSurface IOKit
SPTMProbe6_CFLAGS := -fobjc-arc -O2 -Wall -Wno-unused-variable -Wno-unused-function -fstack-protector-strong -fno-omit-frame-pointer
SPTMProbe6_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
SPTMProbe6_CODESIGN_FLAGS := -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/SPTMProbe6.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.plist .theos/ipa/Payload/SPTMProbe6.app/SPTMProbe6
	cd .theos/ipa && rm -f ../../SPTMProbe6.ipa && zip -qry ../../SPTMProbe6.ipa Payload
