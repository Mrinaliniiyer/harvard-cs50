/*
 * water.c
 *
 * Anthony Catantan
 * Harvard Computer Science 50
 * Week 1 Problem Set
 *
 * Implements a program that reports a user’s water usage, converting minutes spent in the shower to bottles of drinking water.
 */

#include <cs50.h>
#include <stdio.h>

int main(void) {
	
	//provide user input and convert to integer
    printf("Minutes: ");
    int minutes = get_int();
	
	
	//convert minutes to bottles by multiplying the minutes by 12 then printing it
    printf("Bottles: %i\n", minutes * 12);
}