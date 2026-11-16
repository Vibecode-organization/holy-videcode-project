TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = S45
S45_FILES = main.m
S45_FRAMEWORKS = UIKit IOKit Foundation IOSurface
S45_CFLAGS = -Wno-everything
S45_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
S45_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
