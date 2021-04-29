TAR=main.exe
OBJ=main.o HString.o GList.o 
CFLAGS=-Wall -g -c

$(TAR):$(OBJ)
	gcc -o $@ $^

main.o:main.c main.h HString.h GList.h 
	gcc $(CFLAGS) -o $@ $<

HString.o:HString.c HString.h 
	gcc $(CFLAGS) -o $@ $<

GList.o:GList.c HString.h GList.h 
	gcc $(CFLAGS) -o $@ $<

clean:
	$(RM) -r *.o $(TAR)