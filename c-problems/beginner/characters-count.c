// https://pynative.com/c-programming-exercises-for-beginners/ excersise 52
// read any file and count the number of characters in it 

#include <stdio.h>

int main(void){
  FILE *file = fopen( "file.txt", "r");
  if (!file){
    perror("no file file.txt");
    return 1;
  }

  int i= 0, c;
  while ((c = fgetc(file)) != EOF){
    i++;
  }
  
  printf("no. of characters: %d\n", i);

  if (feof(file)) {
    fclose(file);
    printf("End of file reached.\n");
  }
  return 0;
}
