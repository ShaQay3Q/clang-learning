#include <iso646.h>
#include <stdio.h>
#include "./src/cs50.h"

int main(void) {
    char answer = get_char("Are you hungry?[Y/N]: ");
    if (answer == 'y' || answer == 'Y'){
        printf("Come and eat me!\n");
    } else if (answer == 'n' || answer =='N'){
        printf("Can I eat you?!\n");
    } else{
        printf("You can't even answer a simple yes/no question!\nFUCK YOU!\n");
    }
}