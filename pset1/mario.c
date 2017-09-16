/***********************
*       Solved         *
*         by           *
*     alanthony333     *
***********************/

#include <cs50.h>
#include <stdio.h>

int main(void) {

    int height, line;

    //establish user input rules: not less than 0 and not more than 23
    do {
        printf("Height: ");
        height = get_int();
    } while (height < 0 || height > 23);


    //line control formula
    for (line = 0; line < height; line++) {

        //define values of space and hash
        int space = height - line - 1;
        int hash = line + 2;

        //define formula of printing space
        for (int x = 0; x < space; x++) {
            printf(" ");
        }

        //define formula of printing hashtag
        for (int y = 0; y < hash; y++) {
            printf("#");
        }

        printf("\n");
    }

}