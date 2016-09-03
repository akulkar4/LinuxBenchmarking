CC=gcc
CFLAGS=-lpthread 

all: main.o meas_ovhd.o proc_ovhd.o syscall_ovhd.o creation_ovhd.o
	$(CC) -o benchmark main.o meas_ovhd.o proc_ovhd.o syscall_ovhd.o creation_ovhd.o -lpthread

clean:
	rm -rf *.o *.c~ *.h~ benchmark Makefile~
