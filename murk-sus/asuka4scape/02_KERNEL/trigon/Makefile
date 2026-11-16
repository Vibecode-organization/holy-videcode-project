TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = TrigonTest
TrigonTest_FILES = main.m
TrigonTest_FRAMEWORKS = UIKit IOKit Foundation IOSurface
TrigonTest_CFLAGS = -Wno-everything
TrigonTest_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
TrigonTest_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
