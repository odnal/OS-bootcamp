# compile for C++ below - need to install c++ cross compiler
# i686-elf-g++ -c kernel.c++ -o kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti 

all: myos.bin

myos.bin: boot.o kernel.o
	i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

kernel.o: kernel.c
	i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

boot.o: boot.s
	i686-elf-as boot.s -o boot.o

clean:
	rm -f *.o
	rm -f *.bin
