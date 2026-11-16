TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = Surf28Raw
Surf28Raw_FILES = main.m
Surf28Raw_FRAMEWORKS = UIKit IOKit Foundation
Surf28Raw_CFLAGS = -Wno-everything
Surf28Raw_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
Surf28Raw_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
