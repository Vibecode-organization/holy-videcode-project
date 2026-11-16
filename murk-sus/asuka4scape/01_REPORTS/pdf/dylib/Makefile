THEOS ?= /opt/theos
TARGET := iphone:clang:latest:14.0
ARCHS := arm64
include $(THEOS)/makefiles/common.mk
LIBRARY_NAME := pdfprobe
pdfprobe_FILES := fuzzdylib.m
pdfprobe_FRAMEWORKS := Foundation CoreGraphics
pdfprobe_CFLAGS := -fobjc-arc -O2
pdfprobe_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
include $(THEOS)/makefiles/library.mk
