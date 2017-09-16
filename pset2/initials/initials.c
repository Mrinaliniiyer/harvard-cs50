/***********************
*       Solved         *
*         by           *
*     alanthony333     *
***********************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    // get user input
    string name = get_string();

    // print in caps the first char in string if it is not a space
    if (name[0] != ' ') {
            printf("%c", toupper(name[0]));
        }

    // run loop until end of string using strlen funt8ction
    for (int i = 0; i < strlen(name); i++) {


        // print char in caps after the space only if the next char is not a space
        // and is not NULL end of string
        if (name[i] == ' ' && name[i + 1] != ' ' && name[i + 1] != '\0') {
            printf("%c", toupper(name[i + 1]));
        }
    }

    // new line after the loop
    printf("\n");
}
