#include <string.h>


void reverse_string(char* string) {

  int string_length = strlen(string);
  char temp_string[string_length + 1];
  strcpy(temp_string, string);

  char* backwards_pointer = temp_string + string_length - 1;
  for (int i = 0; i< string_length;i++) {
    string[i] = *backwards_pointer;
    backwards_pointer --;
  }
}
