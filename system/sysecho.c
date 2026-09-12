#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
  if (system("echo $P_NO")==-1){
    fprintf( stderr, "couldnt execute command echo:%s\n", strerror(errno));
    return 1;
  }
  
  return 0;
}
