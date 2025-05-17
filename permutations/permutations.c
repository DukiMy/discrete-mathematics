#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  for (int i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }

  printf("arg count = %d\n", argc);
  printf("%d\n");
  return EXIT_SUCCESS;
}

