// https://pynative.com/c-programming-exercises-for-beginners/ excersise 53
// read any file and count the number of lines in it 

#include <stdio.h>

int main(void){
  FILE *file = fopen( "file.txt", "r");
  if (!file){
    perror("no file file.txt");
    return 1;
  }

  int i= 0, c, pc;
  while ((c = fgetc(file)) != EOF){
    if (c=='\n'){
      pc = ftell(file);
      i++;
    }
  }

  // if no trailing \n 
  fseek(file, 0, SEEK_END);
  if ((i==0) && (!(ftell(file)==0))) i++;
  else if (ftell(file)>pc) i++;
  
  printf("no. of lines: %d\n", i);

  if (feof(file)) {
    fclose(file);
    printf("End of file reached.\n");
  }
  return 0;
}
