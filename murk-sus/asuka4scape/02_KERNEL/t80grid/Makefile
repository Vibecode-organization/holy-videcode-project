TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = T80Grid
T80Grid_FILES = main.m
T80Grid_FRAMEWORKS = UIKit IOKit Foundation IOSurface
T80Grid_CFLAGS = -Wno-everything
T80Grid_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
T80Grid_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
