TARGET := iphone:clang:latest:14.0
ARCHS = arm64
INSTALL_TARGET_PROCESSES = 

include $(THEOS)/makefiles/common.mk

LIBRARY_NAME = DeepSeek
DeepSeekFloat_FILES = Tweak.m
DeepSeekFloat_FRAMEWORKS = UIKit CoreGraphics
DeepSeekFloat_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/library.mk
