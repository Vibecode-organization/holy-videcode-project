TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = OAT2
OAT2_FILES = main.m
OAT2_FRAMEWORKS = UIKit Foundation
OAT2_CFLAGS = -Wno-everything
OAT2_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
OAT2_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
