#include <stdio.h>
#include "xor-encrypt.h"
#include "checksum.h"

int main(void){
  char s[] = "brathar";
  xor_encrypt(s);
  printf("the message is now: %s\n", s);
  printf("checksum is: %d\n", checksum(s) );
  xor_encrypt(s);
  printf("the decrypted message is: %s\n", s);
  printf("checksum is: %d\n", checksum(s) );


  return 0;
}
