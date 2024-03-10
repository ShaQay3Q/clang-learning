#include "./src/cs50.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

void swapChar(char *Str, int index1, int index2);

int main(void){

  char Str[] = "GHDEF";
  char modStr[] = "DEFGH";
  int l = strlen(Str);

  while (*Str != *modStr) {
    for (int i = 0; i < l-1; i++) {
        printf("%c\n", Str[i]);
      if (Str[i] > Str[i + 1]) {
        swapChar(Str, i, (i+1));
        printf("Str[i]: %c\nStr[i+1]: %c\n", Str[i], Str[i+1]);
      }
    }
  }
  printf("\nStr: %s\nmodStr: %s\n", Str, modStr);
}

void swapChar(char *Str, int index1, int index2)
{
    char temp = Str[index1];
    Str[index1] = Str[index2];
    Str[index2] = temp;
}