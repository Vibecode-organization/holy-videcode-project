THEOS ?= /opt/theos
LDID ?= /home/femboychik/claude_code/.tools/ldid-amd64
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := SPTM272Probe
SPTM272Probe_FILES := main.m probes.m logger.m fuzz.m
SPTM272Probe_RESOURCE_FILES := Info.plist
SPTM272Probe_FRAMEWORKS := UIKit Foundation IOSurface IOKit Metal
SPTM272Probe_CFLAGS := -fobjc-arc -O2 -Wall -Wextra
SPTM272Probe_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
SPTM272Probe_CODESIGN_FLAGS := -Sentitlements.xml

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/SPTM272Probe.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.xml .theos/ipa/Payload/SPTM272Probe.app/SPTM272Probe
	cd .theos/ipa && zip -qry ../../SPTM272Probe.ipa Payload
