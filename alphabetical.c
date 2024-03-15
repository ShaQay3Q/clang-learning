#include <stdio.h>
#include "./src/cs50.h"
#include <string.h>

int main(void){

    string str = get_string("Type a word: ");

    for (int i =0, l = strlen(str); i < l-1; i++){
        // printf("%c: %i\n", str[i], str[i]);
        
        // Check if letters are not in alphabetical order
        if (str[i] > str[i+1]){
            printf("Not in alphabetical order.\n");
            // When the condition met for the very first time, the pogram will be terminated
            return 0;
        }
    }

    printf("In alphabetial order.\n");
    return 0;
}