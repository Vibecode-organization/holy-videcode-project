TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = TRAV
TRAV_FILES = main.m
TRAV_FRAMEWORKS = UIKit Foundation
TRAV_CFLAGS = -Wno-everything
TRAV_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
TRAV_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
