# Compiler and flags
CC = gcc
CFLAGS = -Wall -O2 -fPIC -shared -I/home/nicolas/Open-TEE/emulator/include -I/home/nicolas/tee_repos/optee_os/lib/libutils/ext/include

OPENTEE_PATH = /opt/OpenTee
# Include directories
INCLUDES = -I$(CURDIR)/../../include \
          -I$(CURDIR)/../../../emulator/include \
			-I$(CURDIR)/../libtee/include -I$(OPENTEE_PATH)/include

# Source files
SOURCES = ta_test.c
HEADERS = ./include/tee_ta_properties.h

# Target library name
TARGET = lib_test_ta.so

# Default target
all: $(TARGET)

# Build the shared library
$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) -o $@

# Clean target
clean:
	rm -f $(TARGET)

.PHONY: all clean