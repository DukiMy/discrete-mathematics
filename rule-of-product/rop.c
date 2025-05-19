#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100
#define MAX_TOKENS 100

// Create a table of products
int main() {
  int rows = 34;
  int cols = 29;

  for (int col = 0; col <= cols; col++)
  {
    if (col > 9)
    {
      printf(" %d |", col);
    }
    else
    {
      printf(" %d  |", col);
    }

    if (col == cols)
    {
        putchar('\n');
    }
  }

  for (int col = 0; col <= cols; col++)
  {
    printf("-----");

    if (col == cols)
    {
      putchar('\n');
    }

  }

  for (int h = 1; h <= rows; h++)
  {
    (h < 10) ? printf(" %d  |", h) : printf(" %d |", h);
    for (int w = 1; w <= cols; w++)
    {
      int product = h * w;
      if (product <= 9)
      {
        printf(" %d   ", product);
      }
      if (product >= 10 && product <= 99)
      {
        printf(" %d  ", product);
      }
      if (product >= 100)
      {
        printf(" %d ", product);
      }
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
