TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = VMTest
VMTest_FILES = main.m
VMTest_FRAMEWORKS = UIKit IOKit Foundation
VMTest_CFLAGS = -Wno-everything
VMTest_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
VMTest_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
