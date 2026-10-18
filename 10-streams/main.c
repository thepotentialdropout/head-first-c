#include <error1.h>
#include <open-url.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int fd[2];
  if (pipe(fd) == -1)
    error("couldnt open pipe");

  pid_t pid = fork();
  if (pid == -1)
    error("cant fork process");

  if (!pid) {
    if (dup2(fd[1], 1) == -1)
      error("cant move descriptor stream");
    close(fd[0]);

    if (execl("/nix/store/97d5ygrvqj55f4nx1x34wfdcc7qn11c0-coreutils-9.11/bin/echo", "/nix/store/97d5ygrvqj55f4nx1x34wfdcc7qn11c0-coreutils-9.11/bin/echo", argv[1], NULL) == -1) {
      error("cant execute echoprocess");
    }

    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1)
      error("cant wait for child process");
  }

  if (dup2(fd[0], 0) == -1)
    error("cant move descriptor stream");
  close(fd[1]);

  char line[255];
  while (fgets(line, 255, stdin)) {
    open_url(line);
  }

  return 0;
}
