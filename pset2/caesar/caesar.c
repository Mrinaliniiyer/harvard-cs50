#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {

    // check if arguments in command line including ./caesar is more than 2
    if (argc != 2) {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // assigning of variables
    int key = atoi(argv[1]);
    char charOfMessage;
    int upperIndex = 65;
    int lowerIndex = 97;

    // ask for user input
    printf("plaintext: ");
    string message = get_string();

    printf("ciphertext: ");

    // to iterate through the inputted message
    for (int index = 0; index < strlen(message); index++) {

        // store in a variable the iterated char from the message
        charOfMessage = message[index];

        // to touch only the alphabetized char of the message
        if (isalpha(charOfMessage)) {

            // to check the case per char of the message
            if (isupper(charOfMessage)) {

                //applies only to upper case char of message
                printf("%c", ((charOfMessage - upperIndex + key) % 26) + upperIndex);

            } else {

                //applies only to upper case char of message
                printf("%c", ((charOfMessage - lowerIndex + key) % 26) + lowerIndex);
            }
        }
    }

    printf("\n");

    return 0;
}