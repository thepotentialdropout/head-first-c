#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node_s{
  char* name;
  struct node_s* next;
} node;

node* create(char* name){
  node* temp = (node*)malloc(sizeof(node));
  temp->name = strdup(name);
  temp->next = NULL;
  
  return temp;
}

void release(node* start){
  node * i, * next = NULL;
  for(; i != NULL; i = next){
    next = i->next;
    free(i->name);
    free(i);
  }
}

void display(node* start){
  node * i = start;
  while(i!=NULL){
    printf("name: %s", i->name);
    i = i->next;
  }

}


int main(void){
  char name[80];
  node *start, *next, *i = NULL;

  for(; fgets(name, 80, stdin)!=NULL; i = next){
    next = create(name);
    if(start == NULL) start = next;
    if(i != NULL) i->next = next;
  }
  display(start);
  release(start);
}
