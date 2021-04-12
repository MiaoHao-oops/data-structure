TAR=main.exe
OBJ=KMP.o main.c operation
CC=gcc
CFLAGS+=-c -g -Wall

$(TAR):$(OBJ)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	$(RM) *.o $(TAR) -r