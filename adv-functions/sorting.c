// qsort ( void* list_ptr, int list_size, int item_size, void (* functionptr)(const void* void_a, const void* void_b)
// function returns 1 if a>b, 0 if a=b, and -1 if a>b

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare( const void* void_a, const void* void_b ){
  int a = *(int*)void_a;
  int b = *(int*)void_b;

  return a-b;
}

int compare_descending( const void* void_a, const void* void_b ){
  int a = *(int*)void_a;
  int b = *(int*)void_b;

  return b-a;
}

typedef struct {
  int x;
  int y;
} rectangle;

int compare_area( const void* void_a, const void* void_b ){
  rectangle a = *(rectangle*)void_a;
  rectangle b = *(rectangle*)void_b;

  int area_a = a.x * a.y;
  int area_b = b.x * b.y;

  return 0;
}

int compare_area_descending( const void* void_a, const void* void_b ){
  return compare_area(void_b, void_a);
}

int compare_alphabetical( const void* void_a, const void* void_b ){
  char** a = (char**)void_a;
  char** b = (char**)void_b;

  return strcmp(*a, *b);
}

int compare_alphabetical_descending( const void* void_a, const void* void_b){
  return compare_alphabetical(void_b, void_a);
}

enum sort_type {
  COMPARE,
  COMPARE_DESCENDING,
  COMPARE_AREA,
  COMPARE_AREA_DESCENDING,
  COMPARE_ALPHABETICAL,
  COMPARE_ALPHABETICAL_DESCENDING
};

int (*sort_type_list[])(const void*, const void*) = {
  compare,
  compare_descending,
  compare_area,
  compare_area_descending,
  compare_alphabetical,
  compare_alphabetical_descending
};

typedef struct {
  enum sort_type type;
  int list[5];
} to_sort;

int main(void){
  to_sort sort_obj_array[] = { { COMPARE, {1, 2, 3, 5, 4 } }, {COMPARE_DESCENDING, {3, 4, 5, 2, 8 } } };

  for ( int i = 0; i < 2; i++){
    qsort(sort_obj_array[i].list, 5, sizeof(int),sort_type_list[sort_obj_array[i].type]);

    puts("start");
    for( int j = 0; j < 5; j++) printf("%d\n", sort_obj_array[i].list[j]);
    
    puts("end");
  }

  return 0;
}
