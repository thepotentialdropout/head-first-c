LD_LIBRARY_PATH = ../libs
INCLUDE_PATH = ../includes

CFLAGS = -L$(LD_LIBRARY_PATH) -I$(INCLUDE_PATH)

hfcal.o: hfcal.c 
	gcc -c hfcal.c -o hfcal.o $(CFLAGS)

../libhfcal.so: hfcal.o
	gcc -shared 
