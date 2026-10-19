#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int score = 0;

int catch_signal(int sig, void (*handler)(int)) {
  struct sigaction action;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  return sigaction(sig, &action, NULL);
}

void error(char *msg) {
  fprintf(stderr, "%s: %s", msg, strerror(errno));
  exit(1);
}

void end_game(int sig) {
  printf("final score: %d\n", score);
  exit(1);
}

void alarm_handler(int sig) { raise(SIGINT); }

int main(void) {
  if (catch_signal(SIGINT, end_game) == -1) {
    error("could not map handler");
  }
  if (catch_signal(SIGALRM, alarm_handler) == -1) {
    error("could not map handler");
  }
  srandom(time(0));

  while (1){
    int a = random() % 11;
    int b = random() % 11;
    char txt[4];

    alarm(5);
    printf("what is %d times %d ?\n", a, b);
    fgets(txt, 4, stdin);
    int answer = atoi(txt);

    if (answer == a * b)
      score++;
  }

  return 0;
}
