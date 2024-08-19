K=kernel

OBJS = \
	   $K/entry.o \
	   $K/start.o \

CC = riscv64-unknown-elf
CFLAGS = -c -ggdb -gdwarf-2 -Wall -Werror -ffreestanding -nostartfiles -nostdlib 
CFLAGS += -MD
CFLAGS += -mcmodel=medany
LDFLAGS = -z max-page-size=4096

QEMU = qemu-system-riscv64
QEMUOPTS = -machine virt -bios none -kernel $K/kernel.elf -m 128M -smp 4 -nographic

qemu: $K/kernel.elf
	$(QEMU) $(QEMUOPTS)

all : $K/kernel.bin

$K/kernel.bin: $(OBJS)
	$(CC)-ld $(LDFLAGS) -T $K/kernel.ld $(OBJS) -o $K/kernel.elf
	$(CC)-objcopy $K/kernel.elf -O binary $K/kernel.bin

$K/start.o : $K/start.c 
	$(CC)-gcc $(CFLAGS) $K/start.c -o $K/start.o

$K/entry.o : $K/entry.s 
	$(CC)-as $K/entry.s -o $K/entry.o

clean:
	rm -rf kernel/*.o
	rm -rf kernel/*.elf
	rm -rf kernel/*.bin


