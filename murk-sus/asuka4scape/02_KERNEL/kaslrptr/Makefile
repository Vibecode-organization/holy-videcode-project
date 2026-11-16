TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = KaslrPtr
KaslrPtr_FILES = main.m
KaslrPtr_FRAMEWORKS = UIKit IOKit Foundation IOSurface
KaslrPtr_CFLAGS = -Wno-everything
KaslrPtr_LDFLAGS := -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
KaslrPtr_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
