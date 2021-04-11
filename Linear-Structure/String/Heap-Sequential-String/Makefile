TAR=main.exe
OBJ=main.o operation.o BruteForce.o KMP.o
CC=gcc
CFLAGS+=-c -g -Wall

$(TAR):$(OBJ)
	$(CC) -o $@ $^
# $@ = $(TAR), $^ = $(OBJ)

%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	$(RM) *.o $(TAR) -r
# $(RM) = rm -f