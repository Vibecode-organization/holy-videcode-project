TARGET = iphone:clang:latest:14.0
ARCHS = arm64
include $(THEOS)/makefiles/common.mk
TOOL_NAME = ctcanary
ctcanary_FILES = main.c
ctcanary_CFLAGS = -O2
ctcanary_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0 -Wl,-headerpad,0x4000
include $(THEOS)/makefiles/tool.mk
