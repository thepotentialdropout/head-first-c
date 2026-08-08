#include <stdio.h>
#include <stdarg.h>

enum drinks {
  MUDSLIDE,
  FUZZY_NAVAL,
  MONKEY_GLAND,
  ZOMBIE
};

float price[] = {
          6.79,
          5.31,
          4.82,
          5.89
};


float total(int args, ...){
  va_list args_list;
  va_start( args_list, args);
  
  float total_price;
  for ( int i = 0; i< args; i++){
    total_price += price[va_arg(args_list, int)];
  }
  return total_price;
}

int main(void){
  printf("%f\n", total( 2, ZOMBIE, MUDSLIDE));

  return 0;
}
