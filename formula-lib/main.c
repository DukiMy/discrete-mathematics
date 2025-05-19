#include <stdio.h>
#include <stdlib.h>
#include "dm.h"

void print_menu() {
  printf("\n=== Formula Library Menu ===\n");
  printf("1. Permutate\n");
  printf("2. Factorialize\n");
  printf("10. Formula 10\n");
  printf("0. Exit\n");
  printf("Select an option: ");
}

int main(void) {
  int choice;
  int n, r;

  while (1) {
    print_menu();
    if (scanf("%d", &choice) != 1) {
      printf("Invalid input. Exiting.\n");
      break;
    }

    switch (choice) {
      case 1: /* Permutations */

        /* Present case */
        printf("\n=== Calcualate permutations ===\n");
        printf("A linear arrangement of distinct objects.\n");
        printf("e.g. 1, 2, 3, ...\n");
        printf("not 1, 1, 2, ...\n");
        printf("n = distinct candidates\n");
        printf("r = positions\n");
        printf("P(n,r) = n!/(n - r)!\n");

        /* Take input */
        printf("Enter value for n: ");
        if (scanf("%d", &n) != 1 || n < 0) {
          printf("Invalid input for n.\n");
          break;
        }

        /* Take input */
        printf("Enter value for r: ");
        if (scanf("%d", &r) != 1 || r < 0 || r > n) {
          printf("Invalid input for r (must be 0 <= r <= n).\n");
          break;
        }

        /* Present result */
        printf("P(%d, %d) = %llu possible permutations\n", n, r, permutation(n, r));

        /* End case */
        getchar();
        getchar();
        break;

      case 2: /* Factorial */

        /* Present case */
        printf("\n=== Calcualate factorial ===\n");
        printf("n = number to factorialize\n");
        printf("F(n) = n!\n");

        /* Take input */
        printf("Enter value for n: ");
        if (scanf("%d", &n) != 1 || n < 0) {
          printf("Invalid input for n.\n");
          break;
        }

        /* Present result */
        printf("P(%d) = %llu\n", n, factorial(n));

        /* End case */
        getchar();
        getchar();
        break;
      case 10:
        formula_10();
        break;
      case 0:
        printf("Exiting program.\n");
        exit(0);
      default:
        printf("Invalid option. Try again.\n");
    }
  }

  return 0;
}
