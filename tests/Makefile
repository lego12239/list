CFLAGS := -Wall

tests: t001 t002
	@for i in $^; do \
		./$$i || exit 1; \
		echo; \
	done

clean:
	rm -f *.o t001 t002

t001: t001.o

t001.o: t001.c ../list.h
	$(CC) -c -o t001.o t001.c


t002: t002.o

t002.o: t002.c ../clist.h
	$(CC) -c -o t002.o t002.c
