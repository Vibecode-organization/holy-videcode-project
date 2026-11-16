TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = SurfTypes
SurfTypes_FILES = main.m
SurfTypes_FRAMEWORKS = UIKit IOKit Foundation IOSurface
SurfTypes_CFLAGS = -Wno-everything
SurfTypes_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
SurfTypes_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
