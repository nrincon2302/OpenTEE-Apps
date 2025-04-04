# Makefile para TA Hello
CC = arm-linux-gnueabihf-gcc
CFLAGS = -Wall -O2 -fPIC -shared -I/home/nicolas/Open-TEE/emulator/include -I/home/nicolas/tee_repos/optee_os/lib/libutils/ext/include
TA_OBJS = ta_hello.o
TA_BIN = ta_hello.so

all: $(TA_BIN)

$(TA_BIN): $(TA_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TA_BIN)
