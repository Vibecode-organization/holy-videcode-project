TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = Sel19Probe
Sel19Probe_FILES = main.m
Sel19Probe_FRAMEWORKS = UIKit IOKit Foundation IOSurface
Sel19Probe_CFLAGS = -Wno-everything
Sel19Probe_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
Sel19Probe_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
