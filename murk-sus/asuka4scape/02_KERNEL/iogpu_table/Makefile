TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = IOGPUTbl
IOGPUTbl_FILES = main.m
IOGPUTbl_FRAMEWORKS = UIKit IOKit Foundation IOSurface
IOGPUTbl_CFLAGS = -Wno-everything
IOGPUTbl_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
IOGPUTbl_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
