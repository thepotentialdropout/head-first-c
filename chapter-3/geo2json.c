#include <stdio.h>

int main(void) {
  float latitude;
  float longitude;
  char info[80];
  int started = 0;

  printf("data = [\n");
  while(scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3){
    if(latitude<-90 || latitude>90){
      fprintf(stderr, "invalid latitude: %f", latitude);
      continue;
    }
    if(longitude<-180 || longitude>180){
      fprintf(stderr, "invalid longitude: %f", longitude);
      continue;
    }

    if(started)
      printf(",\n");
    else
     started = 1;
      
    printf("{ latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);

  }
  printf("\n]");


  return 0;
}
