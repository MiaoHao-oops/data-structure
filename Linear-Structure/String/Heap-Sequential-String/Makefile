TAR=main.exe
OBJS=main.o operation.o BruteForce.o KMP.o
CC=gcc

$(TAR):$(OBJS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $^ -c -o $@

clean:
	$(RM) *.o $(TAR) -r