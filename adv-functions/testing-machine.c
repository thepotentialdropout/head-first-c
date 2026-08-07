#include <stdio.h>
#include <string.h>

void testing_machine( char* list[], char* tags[], int list_length, int tags_length){
  int x, i, cont = 0;

  puts("search results:");
  for (i = 0; i < list_length; i++){
    for(x = 0; x < tags_length; x++){
      if (!strstr( list[i], tags[x])) {
        cont = 1;
        break;
      }
    }
    if (cont){
      cont = 0;
      continue;
    }
    puts(list[i]);
  }
}

