TARGET := iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
APPLICATION_NAME = IOGPUShmem
IOGPUShmem_FILES = main.m
IOGPUShmem_FRAMEWORKS = UIKit IOKit Foundation IOSurface
IOGPUShmem_CFLAGS = -Wno-everything
IOGPUShmem_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
IOGPUShmem_CODESIGN_FLAGS = -Sentitlements.plist
include $(THEOS)/makefiles/application.mk
