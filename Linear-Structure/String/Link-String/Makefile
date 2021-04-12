TAR=main.exe
OBJ=KMP.o main.c operation
CC=gcc
CFLAGS+=-c -g -Wall
CCNAME=-o $@

$(TAR):$(OBJ)
	$(CC) $(CCNAME) $^

%.o:%.c
	$(CC) $^ $(CFLAGS) $(CCNAME)

clean:
	$(RM) *.o $(TAR) -r