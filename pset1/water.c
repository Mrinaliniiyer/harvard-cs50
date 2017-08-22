#include <cs50.h>
#include <stdio.h>

int main(void) {
	
	//provide user input and convert to integer
    printf("Minutes: ");
    int minutes = get_int();
	
	
	//convert minutes to bottles by multiplying the minutes by 12 then printing it
    printf("Bottles: %i\n", minutes * 12);
}