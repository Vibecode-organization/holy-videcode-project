TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = Scaler11
Scaler11_FILES = main.m
Scaler11_FRAMEWORKS = UIKit IOKit Foundation
Scaler11_CFLAGS = -Wno-everything
Scaler11_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
Scaler11_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
