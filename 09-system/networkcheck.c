#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(void) 
{
  if (execl("/home/user/.nix-profile/bin/ifconfig","/home/user/.nix-profile/bin/ifconfig",NULL)==-1){
    if (execl("/sbin/ifconfig","/sbin/ifconfig",NULL)==-1){
      fprintf(stderr, "cannot print network: %s\n", strerror(errno));
      return 1;
    }
  }
  return 0;
}

