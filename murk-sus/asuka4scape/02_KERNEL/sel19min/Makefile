TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = Sel19Min
Sel19Min_FILES = main.m
Sel19Min_FRAMEWORKS = UIKit IOKit Foundation IOSurface
Sel19Min_CFLAGS = -Wno-everything
Sel19Min_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
Sel19Min_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
