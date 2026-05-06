CROSS ?= aarch64-none-elf
CFLAGS =  -mcpu=cortex-a53 -fpic -ffreestanding -std=gnu99 -Wno-sign-compare -O2 -Wall -Wextra -I$(INCLUDEPATH1) -I$(INCLUDEPATH2) -I$(INCLUDEPATH3) -I$(INCLUDEPATH4) -I$(INCLUDEPATH5) -I$(INCLUDEPATH6) -I$(INCLUDEPATH7) -I$(INCLUDEPATH8) -I$(INCLUDEPATH9) -I$(INCLUDEPATH10) -include stdbool.h -include stddef.h -include Drivers/Linux/include/compat.h
ASMFLAGS = -mcpu=cortex-a53

BUILDPATH = build
INCLUDEPATH1 ?= FreeRTOS/Source/include
INCLUDEPATH2 ?= FreeRTOS/Source/portable/GCC/ARM_CA53_64_RaspberryPi3
INCLUDEPATH3 ?= Demo
INCLUDEPATH4 ?= FreeRTOS_Plus_Cli
INCLUDEPATH5 ?= Drivers/serial
INCLUDEPATH6 ?= Drivers/Linux/net/wireless
INCLUDEPATH7 ?= Drivers/Linux/net/mac80211
INCLUDEPATH8 ?= Drivers/Linux/drivers/net/wireless/virtual
INCLUDEPATH9 ?= Drivers/Linux/include
INCLUDEPATH10 ?= Drivers/Linux/include/uapi

OBJS = build/startup.o 
OBJS +=build/FreeRTOS_asm_vector.o
OBJS +=build/FreeRTOS_tick_config.o
OBJS +=build/uart_string.o
OBJS +=build/uart.o
OBJS +=build/Sample-CLI-commands.o
OBJS +=build/UARTCommandConsole.o
#OBJS +=build/UDP-Related-CLI-commands.o
#OBJS +=build/File-Related-CLI-commands.o
OBJS +=build/FreeRTOS_CLI.o
OBJS +=build/serial.o
OBJS +=build/main.o

OBJS +=build/port.o
OBJS +=build/portASM.o

OBJS +=build/list.o
OBJS +=build/tasks.o
OBJS +=build/queue.o
OBJS +=build/timers.o

OBJS +=build/heap_1.o

#WIRELESS_SRCS := \
    Drivers/Linux/net/wireless/ap.c

WIRELESS_SRCS := $(wildcard Drivers/Linux/net/wireless/*.c)

OBJS += $(patsubst Drivers/Linux/net/wireless/%.c,build/wireless/%.o,$(WIRELESS_SRCS))

#MAC80211_SRCS := $(wildcard Drivers/Linux/net/mac80211/*.c)

#OBJS += $(patsubst Drivers/Linux/net/mac80211/%.c,build/mac80211/%.o,$(MAC80211_SRCS))

#HWSIM_SRCS := $(wildcard Drivers/Linux/drivers/net/wireless/virtual/*.c)

#OBJS += $(patsubst Drivers/Linux/drivers/net/wireless/virtual/%.c,build/hwsim/%.o,$(HWSIM_SRCS))

kernel8.elf : raspberrypi3.ld $(OBJS)
	$(CROSS)-gcc -Wl,--build-id=none -std=gnu11 -T raspberrypi3.ld -o $@ -ffreestanding -O2 -nostdlib $(OBJS)
	$(CROSS)-objdump -D kernel8.elf > kernel8.list

build/%.o : Demo/%.S $(BUILDPATH)
	$(CROSS)-as $(ASMFLAGS) -c -o $@ $<
	
build/%.o : Demo/%.c
	$(CROSS)-gcc $(CFLAGS)  -c -o $@ $<

build/%.o : FreeRTOS_Plus_Cli/%.c
	$(CROSS)-gcc $(CFLAGS)  -c -o $@ $<

build/%.o : Drivers/serial/%.c
	$(CROSS)-gcc $(CFLAGS)  -c -o $@ $<

build/%.o : FreeRTOS/Source/%.c
	$(CROSS)-gcc $(CFLAGS)  -c -o $@ $<

build/%.o : FreeRTOS/Source/portable/GCC/ARM_CA53_64_RaspberryPi3/%.c
	$(CROSS)-gcc $(CFLAGS)  -c -o $@ $<

build/%.o : FreeRTOS/Source/portable/GCC/ARM_CA53_64_RaspberryPi3/%.S
	$(CROSS)-as $(ASMFLAGS) -c -o $@ $<

build/%.o : FreeRTOS/Source/portable/MemMang/%.c
	$(CROSS)-gcc $(CFLAGS)  -c -o $@ $<

build/wireless/%.o : Drivers/Linux/net/wireless/%.c
	@mkdir -p $(dir $@)
	$(CROSS)-gcc $(CFLAGS) -c -o $@ $<

#build/mac80211/%.o : Drivers/Linux/net/mac80211/%.c
#	@mkdir -p $(dir $@)
#	$(CROSS)-gcc $(CFLAGS) -c -o $@ $<

#build/hwsim/%.o : Drivers/Linux/drivers/net/wireless/virtual/%.c
#	@mkdir -p $(dir $@)
#	$(CROSS)-gcc $(CFLAGS) -c -o $@ $<

$(BUILDPATH):
	@if [ ! -d $(BUILDPATH) ]; then \
	  echo " mkdir $(BUILDPATH)"; mkdir $(BUILDPATH); \
	fi

clean :
	rm -f build/*.o
	rm -f *.elf
	rm -f *.list

run :
	$(MAKE) kernel8.elf
	qemu-system-aarch64 -M raspi3b -m 1024 -serial null -serial mon:stdio -nographic -kernel kernel8.elf

runasm :
	$(MAKE) kernel8.elf
	qemu-system-aarch64 -M raspi3b -m 1024 -serial null -serial mon:stdio -nographic -kernel kernel8.elf -d in_asm

