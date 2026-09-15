#include <stdio.h>
#include <unistd.h>
#include "error1.h"

int main(int argc, char* argv[])
{
  char envpass[80];
  sprintf( envpass, "P_NO=%s", argv[1]);

  FILE *f = fopen("output.txt", "w");
  if (!f) error("cant open file output.txt");

  char* vars[] = {
    envpass,
    NULL
  };

  pid_t pid = fork();
  if (pid==-1) error("cant fork process");

  if (!pid) {
    if ( dup2(fileno(f), 1)==-1) error("cant move descriptor stream");
    
    if ( execle("./sysecho", "./sysecho", NULL, vars)==-1){
      error("cant execute echoprocess");
    }
  }

  return 0;
}
