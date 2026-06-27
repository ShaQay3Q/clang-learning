#include "./src/cs50.h"
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

// creating and instant of type candidate
    candidate president;
// A declaration introduces a name

// int x = 3.1415
// Because grammatically, C defines it as a declaration with an initializer.
// initilazer != assignment

// double y;     // declaration
// y = 3.14;     // assignment statement

//! Declaration with initialization:
candidate deputy =
{
    .name = "George",
    .votes = 10
};


//! A declaration with an initializer is still a declaration:
//! The compiler treats them completely differently.


int main(void)
{
    // Statement
    // A statement is an instruction
    // (tells the program to do something.
    // -> These are actions that happen when the program runs.)
    president.name = "Alice";
    president.votes = 13;

    candidate user_input =
{
    .name = get_string("Candidate name: "),
    .votes = get_int("Number of votes: ")
};

    printf("%s won the election with %i votes.\n",
        president.name, president.votes);

    printf("%s has %i votes.\n",
        user_input.name, user_input.votes);
}



