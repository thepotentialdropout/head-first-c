#include <stdio.h>
#include <unistd.h>


int main(int argc, char* argv[]) {

  char* delivery = "";
  int thick = 0;
  char ch;

  while ((ch = getopt(argc, argv, "d:t")) != EOF)
    switch (ch) {
      case 'd':
        delivery = optarg;
        break;
      case 't':
        thick = 1;
        break;
      default:
        fprintf(stderr, "unrecognised option: %c\n", ch);
        return 1;
    }
  argv += optind;
  argc -= optind;

  if (thick)
    puts("thick crust");
  if (delivery[0])
    printf("deliver to: %s\n", delivery);

  puts("ingredients:");

  for(int i = 0; i < argc; i++){
    printf("%s\n", argv[i]);
  }

  return 0;
}
