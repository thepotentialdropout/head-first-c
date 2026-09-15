#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void error(char* message){
  printf( "%s: %s\n", message, strerror(errno));
  exit(1);
}
