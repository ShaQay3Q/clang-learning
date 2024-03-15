#include "./src/cs50.h"
#include <stdio.h>
#include <string.h>

void swapChar(char *Str, int index1, int index2);
void sort(char *str, int length);

int main(void){

  char Str[] = "SHAGHAYEGH";
  char modStr[] = "AAEGGHHHSY";
  int l = strlen(Str);

  while (*Str != *modStr) {

    sort(Str, l);

    // for (int i = 0; i < l-1; i++) {
    //     printf("%c\n", Str[i]);
    //   if (Str[i] > Str[i + 1]) {
    //     swapChar(Str, i, (i+1));
    //     printf("Str[i]: %c\nStr[i+1]: %c\n", Str[i], Str[i+1]);
    //   }
    // }
  }
  printf("\nStr: %s\nmodStr: %s\n", Str, modStr);
}

void swapChar(char *Str, int index1, int index2)
{
    char temp = Str[index1];
    Str[index1] = Str[index2];
    Str[index2] = temp;
}

void sort(char *str, int length){
    
    for (int i = 0; i < length-1; i++) {
      if (str[i] > str[i + 1]) {
        swapChar(str, i, (i+1));
      }
    }

}