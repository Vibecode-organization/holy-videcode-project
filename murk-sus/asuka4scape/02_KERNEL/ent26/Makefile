TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = Ent26
Ent26_FILES = main.m
Ent26_FRAMEWORKS = UIKit IOKit Foundation
Ent26_CFLAGS = -Wno-everything
Ent26_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
Ent26_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
