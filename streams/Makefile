
LD_LIBRARY_PATH = ../libs
INCLUDE_PATH = ../includes

CFLAGS = -L$(LD_LIBRARY_PATH) -I$(INCLUDE_PATH) -Wl,-rpath=$(LD_LIBRARY_PATH)

main: main.c 
	gcc -o main main.c $(CFLAGS) -lerror1
