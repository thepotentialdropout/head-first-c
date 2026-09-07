
C_LIB = /home/user/src/clib
C_HEADER_DIR = $(C_LIB)/headers
C_LIB_DIR = .
C_OBJ_DIR = .

CFLAGS= -I$(C_HEADER_DIR) -L$(C_LIB_DIR) -Wall -Wextra

xor-encrypt.o: xor-encrypt.c  
	gcc -c xor-encrypt.c 

checksum.o: checksum.c 
	gcc -c checksum.c 

libhfsecurity.a: checksum.o xor-encrypt.o
	ar -rcs libhfsecurity.a checksum.o xor-encrypt.o

main: main.c libhfsecurity.a
	gcc main.c $(CFLAGS) -lhfsecurity -o main

clean:
	rm -rf main
