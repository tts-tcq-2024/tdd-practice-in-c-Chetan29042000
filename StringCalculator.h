#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


// Function to add numbers in a string
int add(const char* numbers) {
    // Early return for empty string
    if (strlen(numbers) == 0 || !isdigit(numbers[0])) {
        return 0;
    }
    
    // Convert the valid numeric string to an integer and return it
    return atoi(numbers);
}

