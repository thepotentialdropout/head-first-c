#include <stdio.h>
#include <string.h>

int sports_no_beiber(char* s){
  return strstr(s, "sports") && !strstr(s, "beiber");
}

int ns_theater(char* s){
  return strstr(s, "NS") && strstr(s, "theater");
}

int arts_theater_or_dining(char* s){
  return strstr(s, "dining") || strstr(s, "theater") || strstr(s, "arts");
}

void find( int (*match)(char*), char* list[], int list_length ){
  int i;
  puts("matches:");
  for(i = 0; i < list_length; i++){
    if (match(list[i])) puts(list[i]);
  }
}
