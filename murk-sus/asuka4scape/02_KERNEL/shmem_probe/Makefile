TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = ShmemProbe
ShmemProbe_FILES = main.m
ShmemProbe_FRAMEWORKS = UIKit IOKit Foundation
ShmemProbe_CFLAGS = -Wno-everything
ShmemProbe_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
ShmemProbe_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
