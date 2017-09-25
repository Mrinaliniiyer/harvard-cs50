/*
 * greedy.c
 *
 * Anthony Catantan
 * Harvard Computer Science 50
 * Week 1 Problem Set
 *
 * Implements a program that calculates the minimum number of coins required to give a user change.
 */

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) {


    //declare variables
    float dollars;
    int cents, quotient_25, coins, quotient_10, quotient_5, quotient_1;


    //user input specifications: input should not be < 0
    do {
        printf("O hai! How much change is owed?\n");
        dollars = get_float();
    } while (dollars < 0);


    //convert input (dollars) to integer (cents)
    cents = round(dollars * 100.0);     //put round() to round off the imprecise float to nearest integer


    //check if quotient of cents divided by the coin change (25) used is more than 1
    //if more than 1, it means the coin change can be used since the cent is higher than the coin change
    quotient_25 = cents / 25.0;


    //declare the initial amount of the coin counter
    coins = 0.0;



    if (quotient_25 >= 1.0) {
        cents = cents - (25.0 * quotient_25);   //formula to compute the remaining cents
        coins = coins + (1.0 * quotient_25);    //add 1 per 25 cent used to the coin counter
    }

    //the rest are patterned with the 25 change
    quotient_10 = cents / 10.0;


    if (quotient_10 >=1) {
        cents = cents - (10 * quotient_10);
        coins = coins + (1 * quotient_10);
    }


    quotient_5 = cents / 5;


    if (quotient_5 >= 1) {
        cents = cents - (5 * quotient_5);
        coins = coins + (1 * quotient_5);
    }


    quotient_1 = cents / 1;


    if (quotient_1 >=1) {
        cents = cents - (1 * quotient_1);
        coins = coins + (1 * quotient_1);
    }


    //print overall count from coin counter
    printf("%i\n", coins);

}