# Compiler and flags
CC = gcc
CFLAGS = -Wall -O2

OPENTEE_PATH = /opt/OpenTee
INCLUDES = -I$(CURDIR)/../libtee/include -I$(OPENTEE_PATH)/include
LIBS = -L$(OPENTEE_PATH)/lib -ltee

# Binary name
TARGET = ca_test

# Source files
SOURCES = ca_test.c

# Libraries
LDFLAGS = -rdynamic

# Build rules
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) $(LDFLAGS) $(LIBS) -o $@

clean:
	rm -f $(TARGET)

.PHONY: all clean
