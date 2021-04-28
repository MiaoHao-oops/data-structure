TAR=main.exe
OBJ=main.o OLList.o Vector.o
CFLAGS=-Wall -c -g

$(TAR):$(OBJ)
	gcc -o $@ $^

OLList.o:OLList.c OLList.h Vector.h
	gcc $(CFLAGS) -o $@ $<

Vector.o:Vector.c Vector.h
	gcc $(CFLAGS) -o $@ $<

main.o:main.c main.h OLList.h Vector.h
	gcc $(CFLAGS) -o $@ $<

clean:
	$(RM) -r *.o $(TAR)