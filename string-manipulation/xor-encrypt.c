#include "xor-encrypt.h"

void xor_encrypt(char* string) {
  while(*string){
    *string = *string ^ 31;
    string++;
  }
}
