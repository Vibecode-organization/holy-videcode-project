TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = OMNI
OMNI_FILES = main.m
OMNI_FRAMEWORKS = UIKit Foundation
OMNI_CFLAGS = -Wno-everything
OMNI_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
OMNI_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
