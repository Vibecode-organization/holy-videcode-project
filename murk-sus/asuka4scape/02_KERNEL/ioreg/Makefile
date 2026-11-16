TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = IORegDump
IORegDump_FILES = main.m
IORegDump_FRAMEWORKS = UIKit IOKit Foundation
IORegDump_CFLAGS = -Wno-everything
IORegDump_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
IORegDump_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
