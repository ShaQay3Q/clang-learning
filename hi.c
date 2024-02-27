#include <stdio.h>
#include "./src/cs50.h"

int main(void){
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    string s = "HI!";
    string t = "BYE!";

    string w[2];
    w[0] = "HI!";
    w[1] = "BYE!";

    printf("%i %i %i\n", c1, c2, c3);
    printf("%s\n", s);
    printf("%c %c %c\n", s[0], s[1], s[2]);
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
    printf("%i %i %i %i %i %i %i %i %i\n", t[0], t[1], t[2], t[3], t[4], t[5], t[6], t[7], t[8]);
    printf("%i %i %i %i %i %i %i %i\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7]);
    printf("%s %s\n", w[0], w[1]);
    printf("%c %c %c %s\n", w[0][0], w[0][1], w[0][2], w[1]);

}