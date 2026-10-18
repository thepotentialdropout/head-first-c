#include <error1.h>
#include <sys/wait.h>
#include <unistd.h>

void open_url(char *url) {

  pid_t pid = fork();
  if (pid == -1)
    error("cant fork process");

  if (!pid) {

    if (execl("/run/current-system/sw/bin/xdg-open", "/run/current-system/sw/bin/xdg-open", url, NULL) == -1) {
      error("cant execute xdg open");
    }

    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1)
      error("cant wait for child process");
  }
}
