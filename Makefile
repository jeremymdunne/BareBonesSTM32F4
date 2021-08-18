SOURCEDIR=src
BUILDDIR=bin
LIBDIR=lib
COREDIR=$(LIBDIR)/stm32f40x_core
LINKER=$(COREDIR)/stm32f4.ld
TARGET=cortex-m4

INCLUDE_DIRS = -I . -I $(COREDIR)

CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
BIN=arm-none-eabi-objcopy
SIZE=arm-none-eabi-size

CFLAGS= -mthumb -mcpu=$(TARGET) -Wall -o0 -c -I.\src

all: $(BUILDDIR)/app.bin
	$(SIZE) $(BUILDDIR)/app.elf

# startup
$(BUILDDIR)/stm32f407.o: $(COREDIR)/startup/stm32f407.s
	$(AS) -o $@ $^

# system
$(BUILDDIR)/stm32f40x_system.o: $(COREDIR)/stm32f40x_system.c
	$(CC) $(CFLAGS) -c -o $@ $^

# main
$(BUILDDIR)/main.o: $(SOURCEDIR)/main.c
	$(CC) $(CFLAGS) -c -o $@ $^ $(INCLUDE_DIRS)

$(BUILDDIR)/app.elf: $(LINKER) $(BUILDDIR)/stm32f407.o $(BUILDDIR)/main.o $(BUILDDIR)/stm32f40x_system.o
	$(LD) -o $@ -T $^

$(BUILDDIR)/app.bin: $(BUILDDIR)/app.elf
	$(BIN) -O binary $^ $@

flash: $(BUILDDIR)/app.bin
	st-flash --reset write $(BUILDDIR)/app.bin 0x8000000

erase:
	st-flash --reset erase

clean:
	-del /S *.o *.elf *.bin
