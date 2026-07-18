#include <stdio.h>
#include "reverse-string.h"

int main(void) {
  char foo[] = "verylongwordeatmyass";
  reverse_string(foo);
  printf("%s", foo);
  return 0;
}
