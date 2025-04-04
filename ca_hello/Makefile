# Makefile para CA Hello

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# OpenTEE paths and libraries
OPENTEE_PATH = /opt/OpenTee
INCLUDES = -I$(CURDIR)/../libtee/include -I$(OPENTEE_PATH)/include
LIBS = -L$(OPENTEE_PATH)/lib -ltee

# Binary name
CA_BIN = ca_hello

# Source files
SRCS = ca_hello.c
OBJS = $(SRCS:.c=.o)

# Build rules
all: $(CA_BIN)

$(CA_BIN): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(CA_BIN)

.PHONY: all clean
