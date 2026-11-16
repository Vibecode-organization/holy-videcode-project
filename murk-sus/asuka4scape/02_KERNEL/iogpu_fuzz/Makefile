TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = IOGPUFuzz
IOGPUFuzz_FILES = main.m
IOGPUFuzz_FRAMEWORKS = UIKit IOKit Foundation IOSurface
IOGPUFuzz_CFLAGS = -Wno-everything
IOGPUFuzz_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
IOGPUFuzz_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
