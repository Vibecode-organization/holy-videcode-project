TARGET = iphone:clang:14.5:14.0
ARCHS = arm64
INSTALL_TARGET_PROCESSES = AllProbe

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME = AllProbe
AllProbe_FILES = main.m
AllProbe_FRAMEWORKS = UIKit Foundation IOKit IOSurface
AllProbe_LDFLAGS = -framework CoreFoundation -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0 -Wl,-arch,arm64
AllProbe_CODESIGN_FLAGS = -Sentitlements.plist

include $(THEOS_MAKE_PATH)/application.mk
