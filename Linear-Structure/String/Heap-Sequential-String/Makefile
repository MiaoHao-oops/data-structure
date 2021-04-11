TAR=main.exe
OBJS=main.o operation.o BruteForce.o KMP.o
CC=gcc
CFLAGS+=-c -g -Wall

$(TAR):$(OBJS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	$(RM) *.o $(TAR) -r