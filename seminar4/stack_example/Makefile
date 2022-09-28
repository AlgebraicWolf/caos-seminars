CC=/opt/aarch64-gcc/bin/aarch64-linux-gnu-gcc

.PHONY: all build

all: build

build: main.o solve.o
	$(CC) -g -o main main.o solve.o

main.o: main.c
	$(CC) -c -g -o main.o main.c

solve.o: solve.S
	$(CC) -c -g -o solve.o solve.S
