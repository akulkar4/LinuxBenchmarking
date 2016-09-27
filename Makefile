CC=gcc
CFLAGS= -lpthread -lm

all: main.o meas_ovhd.o proc_ovhd.o syscall_ovhd.o creation_ovhd.o cswitch_ovhd.o cswitch_ovhd_thread.o pagefault_ovhd.o mem_bandwidth.o mem_latency.o
	$(CC) -o benchmark main.o meas_ovhd.o proc_ovhd.o syscall_ovhd.o creation_ovhd.o cswitch_ovhd.o cswitch_ovhd_thread.o pagefault_ovhd.o mem_bandwidth.o mem_latency.o -lm -lpthread

clean:
	rm -rf *.o *.c~ *.h~ *.md~ benchmark Makefile~
