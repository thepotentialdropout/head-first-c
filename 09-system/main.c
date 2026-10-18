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
      if (execle("/nix/store/97d5ygrvqj55f4nx1x34wfdcc7qn11c0-coreutils-9.11/bin/echo", "/nix/store/97d5ygrvqj55f4nx1x34wfdcc7qn11c0-coreutils-9.11/bin/echo", p_nos[i], NULL, vars) == -1) {
        fprintf(stderr, "cant run command: %s\n", strerror(errno));
        return 1;
      }
    }
  }

  return 0;
}
