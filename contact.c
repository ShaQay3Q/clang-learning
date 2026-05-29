#include <stdio.h>
#include "./src/cs50.h"

int main(void)
{
    string name = get_string("Enter your name: ");
    int age = get_int("Enter your age: ");
    long number = get_long("Enter your phone number: ");
    string location = get_string("Enter your location: ");
    printf("New Contact: %s, %i, %li, %s", name, age, number, location );
}