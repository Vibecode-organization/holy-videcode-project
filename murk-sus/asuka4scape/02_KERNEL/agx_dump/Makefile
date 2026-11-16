TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = AGXDump
AGXDump_FILES = main.m
AGXDump_FRAMEWORKS = UIKit IOKit Foundation
AGXDump_CFLAGS = -Wno-everything
AGXDump_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
AGXDump_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
