TAR=main.exe
OBJ=main.o OLList.o Vector.o
CFLAGS=-Wall -c -g

$(TAR):$(OBJ)
	gcc -o $@ $^

OLList.o:OLList.c
	gcc $(CFLAGS) -o $@ $<

Vector.o:Vector.c
	gcc $(CFLAGS) -o $@ $<

main.o:main.c
	gcc $(CFLAGS) -o $@ $<

clean:
	$(RM) -r *.o $(TAR)