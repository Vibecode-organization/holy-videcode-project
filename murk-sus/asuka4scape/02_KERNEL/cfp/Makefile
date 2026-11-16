TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = CFP
CFP_FILES = main.m
CFP_FRAMEWORKS = UIKit Foundation
CFP_CFLAGS = -Wno-everything
CFP_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
CFP_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
