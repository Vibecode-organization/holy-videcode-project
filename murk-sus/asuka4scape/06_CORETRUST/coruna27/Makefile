TARGET := iphone:clang:latest:14.0
ARCHS = arm64

include $(THEOS)/makefiles/common.mk

APPLICATION_NAME = SPTMTest

SPTMTest_FILES = main.m SPTMTestViewController.m \
	entry1_src/kread_bootstrap.m \
	entry1_src/kernel_primitives.m \
	entry1_src/sptm_bypass.m \
	entry1_src/agx_doorbell_fallback.m \
	entry1_src/stabilize.m

SPTMTest_FRAMEWORKS = UIKit IOKit Metal
SPTMTest_CFLAGS = -Wno-everything
SPTMTest_LDFLAGS = -fuse-ld=/usr/bin/ld64.lld -Wl,-platform_version,ios,14.0,14.0
SPTMTest_CODESIGN_FLAGS = -Sentitlements.plist

include $(THEOS)/makefiles/application.mk

