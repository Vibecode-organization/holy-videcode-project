TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = DTProbe
DTProbe_FILES = main.m
DTProbe_FRAMEWORKS = UIKit IOKit Foundation
DTProbe_CFLAGS = -Wno-everything
DTProbe_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
DTProbe_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
