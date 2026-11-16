TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = IOGPUShort
IOGPUShort_FILES = main.m
IOGPUShort_FRAMEWORKS = UIKit IOKit Foundation
IOGPUShort_CFLAGS = -Wno-everything
IOGPUShort_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
IOGPUShort_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
