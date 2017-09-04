/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if needle is in array of size haystack, else false.
 */
bool search(int needle, int haystack[], int size)
{
    // declare upper and lower limits
    int upper = size - 1;
    int lower = 0;


    while(lower <= upper) {

        // initialize the middle where the search would start
        int middle = (upper + lower) / 2;

        // return true right away if needle is found in the middle
        if(needle == haystack[middle]) {
            return true;

        // if needle, or the number, is on the left of the middle
        } else if(needle < haystack[middle]) {

            // move the upper limit to the middle
            // there is a middle - 1 since we're done searching on the middle
            upper = middle - 1;

        // if needle, or the number, is on the right of the middle
        } else if(needle > haystack[middle]) {

            // move the lower limit to the middle
            // there is a middle + 1 since we're done searching on the middle
            lower = middle + 1;
        }
    }

    //return false when the needle is not found
    return false;
}

/**
 * Sorts array of size haystack.
 */
void sort(int haystack[], int size)
{

    // iterate through the i'th in of an array
    // this array would contain the sorted ints
    for(int i = 0; i < (size - 1); i++) {

        // initialized the first i'th int as the minimum for now
        int minimum = i;


        // iterate through the j'th int of an array
        // this is the unsorted array
        for(int j = (i + 1); j < (size - 1); j++) {

            // if the j'th int is less than the temporary minimum
            if(haystack[j] < haystack[minimum]) {

                // that j'th int would be the new temporary minimum
                minimum = j;
            }
        }

        // swap to put the new minimum to its proper place on the sorted array
        // put the new minimum to a new variable temp
        // put the old i'th, the initialized one, to the minimum that is now empty
        // put the temp, the previous j'th that was less than the old i'th
        // to the new i'th
        // basically, the new minimum will become the new i'th
        int temp = haystack[minimum];
        haystack[minimum] = haystack[i];
        haystack[i] = temp;
    }
    return;
}
