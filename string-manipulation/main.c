#include <stdio.h>
#include <unistd.h>
#include "xor-encrypt.h"


int main(int argc, char* argv[]) {

  char message[80];
  while(fgets(message, 80, stdin)){
    xor_encrypt(message);
    printf("%s\n", message);
  }

  return 0;
}

