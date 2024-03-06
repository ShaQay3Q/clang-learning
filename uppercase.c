#include "./src/cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void){

    string s = get_string("Before: ");
    printf("After: ");

    //int len = strlen(s);

    for (int i = 0, len = strlen(s); i < len; i++){
         
         if (s[i] >= 'a' && s[i] <= 'z'){
            printf("%c", s[i] - 32);
         } else{
            printf("%C", s[i]);
         }
    } 
    printf("\nuppercase: ");

    int len = strlen(s);
    for (int i = 0; i < len; i++){
            printf("%c", toupper(s[i]));

    }
    printf("\nlowercase: ");

    for (int i =  0; i < len; i++){
      printf("%c", tolower(s[i]));
    }
    printf("\n");
}