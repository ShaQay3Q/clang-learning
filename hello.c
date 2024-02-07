#include "./src/cs50.h"
#include <stdio.h>

int main(void) {

  string fisrt_name = get_string("What is your first name?\n> ");
  string last_name = get_string("What is your last name?\n> ");
  string from = get_string("Where are you from?\n> ");
  printf("Hello %s %s from %s.\n", fisrt_name, last_name, from);

  return 42;
}
