CC = clang
CFLAGS = -O2 -Wall -W -Wno-unused-result

all: tp3fb tp3h

tp3fb: tp3fb.o
	$(CC) $(CFLAGS) tp3fb.o -o tp3fb

tp3h: tp3h.o
	$(CC) $(CFLAGS) tp3h.o -o tp3h

tp3fb.o: tp3fb.c
	$(CC) $(CFLAGS) -c tp3fb.c

tp3h.o: tp3h.c
	$(CC) $(CFLAGS) -c tp3h.c

runfb: 
	clear && ./tp3fb

runh: 
	clear && ./tp3h