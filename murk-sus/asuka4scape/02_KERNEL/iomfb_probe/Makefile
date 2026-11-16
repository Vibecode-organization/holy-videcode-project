TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = IOMFBProbe
IOMFBProbe_FILES = main.m
IOMFBProbe_FRAMEWORKS = UIKit IOKit Foundation
IOMFBProbe_CFLAGS = -Wno-everything
IOMFBProbe_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
IOMFBProbe_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
