CC=gcc
CFLAGS=-I .

all: main.o meas_ovhd.o
	$(CC) -o benchmark main.o meas_ovhd.o -I .

clean:
	rm -rf *.o *.c~ *.h~ benchmark