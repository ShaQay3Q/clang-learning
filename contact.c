#include <stdio.h>
#include "./src/cs50.h"

int main(void)
{
    string name = get_string("Enter your name: ");
    int age = get_int("Enter your age: ");
    string phone_number = get_string("Enter your phone number: ");
    string location = get_string("Enter your location: ");
    printf("New Contact: %s, %i, lives at %s, can be reach at %s\n", name, age, location,phone_number );
}