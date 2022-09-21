CC=/opt/aarch64-gcc/bin/aarch64-linux-gnu-gcc

build: main.o func.o
	$(CC) -g -o main main.o func.o

main.o: main.c
	$(CC) -c -o main.o -g main.c

func.o: func.S
	$(CC) -c -o func.o -g func.S
