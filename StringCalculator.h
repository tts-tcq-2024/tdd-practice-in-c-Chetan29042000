
Copy code
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to add numbers in a string with reduced CCN
int add(const char* input) {
    // If input is empty or starts with an invalid character, return 0
    if (strlen(input) == 0 || (!isdigit(input[0]) && input[0] != '-')) {
        return 0;
    }

    int sum = 0;
    const char* ptr = input;
    
    while (*ptr) {
        // Convert the current number to integer and add to sum
        sum += strtol(ptr, (char**)&ptr, 10);

        // If there is a comma, move past it
        if (*ptr == ',') {
            ptr++;
        }
    }

    return sum;
}
