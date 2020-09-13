all:
	arm-linux-gcc -c -o led.o led.c
	arm-linux-gcc -c -o key.o key.c
	arm-linux-gcc -c -o main.o main.c
	arm-linux-gcc -c -o Start.o Start.s
	arm-linux-ld -Ttext 0 Start.o led.o key.o main.o -o main.elf
	arm-linux-objcopy -O binary -S main.elf main.bin
	arm-linux-objdump -D main.elf > main.dis
clean:
	rm -rf *.bin *.o *.elf