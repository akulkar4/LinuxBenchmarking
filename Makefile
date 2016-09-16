CC=gcc
CFLAGS= -O3 -lpthread

all: main.o meas_ovhd.o proc_ovhd.o syscall_ovhd.o creation_ovhd.o cswitch_ovhd.o cswitch_ovhd_thread.o
	$(CC) -o benchmark main.o meas_ovhd.o proc_ovhd.o syscall_ovhd.o creation_ovhd.o cswitch_ovhd.o cswitch_ovhd_thread.o -lpthread

clean:
	rm -rf *.o *.c~ *.h~ *.md~ benchmark Makefile~
