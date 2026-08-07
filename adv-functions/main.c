#include <stdio.h>
#include <string.h>

#include "testing-machine.c"

int main(void){
  int NUM_ADS = 7;
  char *ADS[] = {
    "William: SBM GSOH likes sports, TV, dining",
    "Matt: SWM NS likes art, movies, theater",
    "Luis: SLM ND likes books, theater, art",
    "Mike: DWM DS likes trucks, sports and bieber",
    "Peter: SAM likes chess, working out and art",
    "Josh: SJM likes sports, movies and theater",
    "Jed: DBM likes theater, books and dining"
  };

  int NUM_TAGS = 2;
  char *tags[] = {
    "movies",
    "sports"
  };

  testing_machine(ADS, tags, NUM_ADS, NUM_TAGS);
  return 0;
}
