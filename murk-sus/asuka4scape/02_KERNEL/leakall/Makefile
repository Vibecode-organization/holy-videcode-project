TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = LeakAll
LeakAll_FILES = main.m
LeakAll_FRAMEWORKS = UIKit IOKit Foundation
LeakAll_CFLAGS = -Wno-everything
LeakAll_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
LeakAll_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
