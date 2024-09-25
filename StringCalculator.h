#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Function to add numbers in a string
int add(const char* numbers) {
    // Handle empty string
    if (strlen(numbers) == 0) {
        return 0;
    }
    
    // Check if the input contains only digits
    for (int i = 0; numbers[i] != '\0'; i++) {
        if (!isdigit(numbers[i])) {
            return 0;  // Return 0 for non-numeric input
        }
    }

    // Convert the valid numeric string to an integer and return it
    return atoi(numbers);
}

