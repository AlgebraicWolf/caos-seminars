CC = gcc

.PHONY : all build clean

all : build

build : main.so executable

clean :
	${RM} main.o
	${RM} main.so
	${RM} executable

main.o : main.c
	${CC} -g -fPIC -c -o main.o main.c

main.so : main.o
	${CC} -shared -o main.so main.o

executable : main.o
	${CC} -g -o executable main.o
