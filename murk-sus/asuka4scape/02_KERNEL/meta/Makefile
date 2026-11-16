TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = META
META_FILES = main.m
META_FRAMEWORKS = UIKit Foundation
META_CFLAGS = -Wno-everything
META_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
META_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
