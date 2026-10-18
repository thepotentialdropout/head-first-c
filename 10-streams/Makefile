
LD_LIBRARY_PATH = ../libs
INCLUDE_PATH = ../includes

CFLAGS = -L$(LD_LIBRARY_PATH) -I$(INCLUDE_PATH) -Wl,-rpath=$(LD_LIBRARY_PATH)

open-url.o: open-url.c 
	gcc -c -o open-url.o open-url.c $(CFLAGS) -lerror1

main.o: main.c 
	gcc -o main.o main.c -c $(CFLAGS) -lerror1

a: main.o open-url.o
	gcc -o a main.c open-url.o $(CFLAGS) -lerror1

clean:
	rm -rf *.o a

