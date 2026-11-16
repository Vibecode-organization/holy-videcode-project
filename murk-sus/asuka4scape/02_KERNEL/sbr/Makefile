TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = Sbracer
Sbracer_FILES = main.m
Sbracer_FRAMEWORKS = UIKit Foundation
Sbracer_CFLAGS = -Wno-everything
Sbracer_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
Sbracer_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
