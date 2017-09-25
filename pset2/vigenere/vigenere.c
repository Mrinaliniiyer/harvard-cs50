/*
 * vigenere.c
 *
 * Anthony Catantan
 * Harvard Computer Science 50
 * Week 2 Problem Set
 *
 * Implements a program that encrypts messages using Vigenère’s cipher.
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {

    // check if command-line arguments are 2
    if(argc != 2) {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    //check if only letters are in the key
    for(int i = 0; i < strlen(argv[1]); i++) {
        if(!isalpha(argv[1][i])) {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    printf("plaintext: ");
    string message = get_string();

    printf("ciphertext: ");

    // declare variables for upper and lower case
    int upperCaseIndex = 65;
    int lowerCaseIndex = 97;

    // for control of message and key char numbers
    for(int messageIndex = 0, keyIndex = 0; messageIndex < strlen(message); messageIndex++, keyIndex++) {

        // declare local variables (self-explanatory except for the first one, thus the meaning)
        int keyGroup = keyIndex % strlen(argv[1]);  // to control loop of key and make a wrap
        char charOfMessageIndex = message[messageIndex];
        char initialCharOfKeyIndex = argv[1][keyIndex];
        char charOfKeyIndex = toupper(initialCharOfKeyIndex);
        char keyIndexValue = charOfKeyIndex - upperCaseIndex;

        // check if char is a space or symbol and print
        if(!isalpha(charOfMessageIndex)) {
            printf("%c", charOfMessageIndex);

        // if alphabet, proceed to conditions and print
        } else if(isalpha(charOfMessageIndex)) {

            if(isupper(charOfMessageIndex)) {
                printf("%c", ((charOfMessageIndex - upperCaseIndex) + keyIndexValue) % 26 + upperCaseIndex);

            } else if(!isupper(charOfMessageIndex)) {
                printf("%c", ((charOfMessageIndex - lowerCaseIndex) + keyIndexValue) % 26 + lowerCaseIndex);
            }
        }

        // if char is not an alphabet, delay increment of key index
        // important to be at the last for the above loop to work right
        if(!isalpha(charOfMessageIndex)) {
            keyIndex = keyIndex - 1;
        }

        // restarts the key index loop whenever it reaches near the end
        if(keyGroup == strlen(argv[1]) - 1 && isalpha(charOfMessageIndex)) {
            keyIndex = -1;
        }
    }

    printf("\n");
    return 0;
}