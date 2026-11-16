THEOS ?= /opt/theos
LDID ?= /home/femboychik/claude_code/.tools/ldid-amd64
TARGET := iphone:clang:latest:14.0
ARCHS := arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME := PDFProbe
PDFProbe_FILES := main.m
PDFProbe_RESOURCE_FILES := Info.plist type5_8.pdf type5_32.pdf type5_64.pdf
PDFProbe_FRAMEWORKS := UIKit Foundation CoreGraphics
PDFProbe_CFLAGS := -fobjc-arc -O2 -Wall -Wextra
PDFProbe_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
PDFProbe_CODESIGN_FLAGS := -Sentitlements.xml

include $(THEOS)/makefiles/application.mk

.PHONY: ipa
ipa: all
	mkdir -p .theos/ipa/Payload
	cp -a .theos/obj/debug/PDFProbe.app .theos/ipa/Payload/
	$(LDID) -Sentitlements.xml .theos/ipa/Payload/PDFProbe.app/PDFProbe
	cd .theos/ipa && zip -qry ../../PDFProbe.ipa Payload
