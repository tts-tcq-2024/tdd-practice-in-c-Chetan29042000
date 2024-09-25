#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to add numbers in a string
int add(const char* input) {
    // Return 0 for an empty string or invalid first character
    if (strlen(input) == 0 || (!isdigit(input[0]) && input[0] != '-')) {
        return 0;
    }
    
    int sum = 0;
    char* input_copy = strdup(input);  // Duplicate input string to avoid modifying original
    char* token = strtok(input_copy, ",");  // Split the string by commas

    while (token != NULL) {
        // Convert each token to an integer and add to the sum
        sum += atoi(token);
        token = strtok(NULL, ",");  // Move to the next token
    }

    free(input_copy);  // Free the duplicated string
    return sum;
}

