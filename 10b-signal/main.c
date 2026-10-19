#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void death(int sig){
  puts("goodbye cruel world.....");
  exit(1);
}

int catch_signal(int sig, void (*handler)(int)){
  struct sigaction action;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  return sigaction(sig, &action, NULL);
}
int main(void){
  if (catch_signal(SIGINT, death)==-1){
    fprintf( stderr, "Cant map the handler");
    exit(2);
  }

  char name[30];
  printf("enter your name:");
  fgets(name, 30, stdin);
  printf("hello %s\n", name);

  return 0;
}
