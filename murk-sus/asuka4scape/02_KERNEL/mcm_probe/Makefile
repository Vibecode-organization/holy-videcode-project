TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = MCMProbe
MCMProbe_FILES = main.m
MCMProbe_FRAMEWORKS = UIKit IOKit Foundation Security
MCMProbe_CFLAGS = -Wno-everything
MCMProbe_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
MCMProbe_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
