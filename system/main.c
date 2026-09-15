#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *p_nos[] = {
      "1",
      "2",
      "3",
      "4",
  };
  char *message = argv[1];
  int times = 4;

  for (int i = 0; i < times; i++) {
    char var[10];
    sprintf(var, "P_NO=%s", p_nos[i]);
    char *vars[] = {var, NULL};

    pid_t pid = fork();
    if (pid == -1) {
      fprintf(stderr, "cant fork process: %s\n", strerror(errno));
      return 1;
    }

    if (!pid) {
      if (execle("./sysecho", "./sysecho", NULL, vars) == -1) {
        fprintf(stderr, "cant run command: %s\n", strerror(errno));
        return 1;
      }
    }
  }

  return 0;
}
