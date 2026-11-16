# BadKernel — Standalone compilation
# Builds a static library (.a) and optional test binary

CC      = xcrun clang
SDK     = iphoneos
ARCH    = arm64
CFLAGS  = -arch $(ARCH) -isysroot $(shell xcrun --sdk $(SDK) --show-sdk-path) \
          -O2 -Wall -Wextra -Werror -fobjc-arc \
          -Iheaders \
          -DIOS_BUILD
LDFLAGS = -framework Foundation -framework IOSurface \
          -lresolv -lz -ldl

LIB_SRC = BadKernel/BadKernel.m
LIB_OUT = libBadKernel.a
TEST_SRC = test/BadKernelTest.m
TEST_OUT = BadKernelTest

.PHONY: all lib test clean install

all: lib test

lib: $(LIB_OUT)

$(LIB_OUT): $(LIB_SRC) headers/BadKernel.h
	@echo "==> Building libBadKernel.a"
	$(CC) $(CFLAGS) -c $(LIB_SRC) -o BadKernel.o
	ar rcs $(LIB_OUT) BadKernel.o
	@echo "==> Built $(LIB_OUT)"

test: $(TEST_OUT)

$(TEST_OUT): $(TEST_SRC) $(LIB_OUT)
	@echo "==> Building test binary"
	$(CC) $(CFLAGS) $(TEST_SRC) $(LIB_OUT) $(LDFLAGS) -o $(TEST_OUT)
	@echo "==> Built $(TEST_OUT)"

clean:
	rm -f *.o $(LIB_OUT) $(TEST_OUT)
	@echo "==> Cleaned"

# Install into DopamineX or other project
install: $(LIB_OUT)
	@echo "==> Install to ~/DopamineX/Application/Dopamine/Exploits/BadKernel/"
	mkdir -p ~/DopamineX/Application/Dopamine/Exploits/BadKernel/
	cp $(LIB_OUT) ~/DopamineX/Application/Dopamine/Exploits/BadKernel/
	cp headers/BadKernel.h ~/DopamineX/Application/Dopamine/Exploits/BadKernel/
	cp Info.plist ~/DopamineX/Application/Dopamine/Exploits/BadKernel/
	@echo "==> Installed"
