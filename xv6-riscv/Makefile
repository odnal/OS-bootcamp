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

# try to generate a unique GDB port
GDBPORT = $(shell expr `id -u` % 5000 + 25000)
# QEMU's gdb stub command line changed in 0.11
QEMUGDB = $(shell if $(QEMU) -help | grep -q '^-gdb'; \
		  then echo "-gdb tcp::$(GDBPORT)"; \
		  else echo "-s -p $(GDBPORT)"; fi)

qemu-gdb: $K/kernel.elf .gdbinit
	@echo "*** Now run 'gdb' in another window." 1>&2
	$(QEMU) $(QEMUOPTS) -S $(QEMUGDB)

qemu: $K/kernel.elf
	$(QEMU) $(QEMUOPTS)

all : $K/kernel.bin

$K/kernel.bin: $(OBJS)
	$(CC)-ld $(LDFLAGS) -T $K/kernel.ld $(OBJS) -o $K/kernel.elf
	$(CC)-objcopy $K/kernel.elf -O binary $K/kernel.bin

$K/start.o : $K/start.c
	$(CC)-gcc $(CFLAGS) $K/start.c -o $K/start.o

$K/entry.o : $K/entry.S
	$(CC)-as $K/entry.S -o $K/entry.o

clean:
	rm -rf kernel/*.d
	rm -rf kernel/*.o
	rm -rf kernel/*.elf
	rm -rf kernel/*.bin


