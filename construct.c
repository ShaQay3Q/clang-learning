#include "./src/cs50.h"
#include <stdio.h>
#include<string.h>

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

candidate get_candidate(void);
void print_candidates(candidate candidates[],int length);


int main(void)
{
    // Statement
    // A statement is an instruction
    // (tells the program to do something.
    // -> These are actions that happen when the program runs.)
    // president.name = "Alice";
    // president.votes = 13;

    candidate candidates[3];
    // candidate user_input =
    // {
    //     .name = get_string("Candidate name: "),
    //     .votes = get_int("Number of votes: ")
    // };

    // printf("%s won the election with %i votes.\n",
    //     president.name, president.votes);

    // printf("%s has %i votes.\n",
    //     user_input.name, user_input.votes);

    for (int i = 0; i < 3; i++)
    {
        candidates[i] = get_candidate();
    }


    // candidate new_candidate = get_candidate();
    // printf("%s has %i votes.\n",
    //     new_candidate.name, new_candidate.votes);

    print_candidates(candidates, 3);
}

// Function to get a new_candidate candidate
candidate get_candidate(void)
{
    // Solution 1
    candidate candidate = 
    {
        .name = get_string("Candidate name: "),
        .votes = get_int("Number of votes: ")
    };

    return candidate;

    // Solution 2
    // string name = get_string("Candidate name: ");
    // int votes = get_int("Number of votes: ");
    
    // candidate new_candidate = {.name = name, .votes = votes};
    // return new_candidate;
}

void print_candidates(candidate candidates[],int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Candidate %i: %s has %i votes\n",
            i+1, candidates[i].name, candidates[i].votes);
    }
}