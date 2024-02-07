#include <stdio.h>
#include "./src/cs50.h"

int main(void) {

  int x = get_int("x: ");
  int y = get_int("y: ");
  if (x < y) {
    printf("%i is smaller than %i\n", x, y);
  } else if (y < x) {
    printf("%i is smaller than %i\n", y, x);
  } else {
    printf("You entered same number twice!\n");
  }
}