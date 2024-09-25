#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Helper function to check if the input is valid
int is_valid_input(const char* input) {
    return strlen(input) > 0 && (isdigit(input[0]) || input[0] == '-');
}

// Helper function to sum up numbers from a tokenized string, ignoring numbers > 1000
int sum_tokens(char* input_copy) {
    int sum = 0;
    char* token = strtok(input_copy, ",");  // Split the string by commas

    while (token != NULL) {
        int number = atoi(token);  // Convert each token to an integer
        if (number <= 1000) {  // Ignore numbers greater than 1000
            sum += number;
        }
        token = strtok(NULL, ",");  // Move to the next token
    }
    
    return sum;
}

// Function to add numbers in a string
int add(const char* input) {
    // Return 0 for an empty string or invalid first character
    if (!is_valid_input(input)) {
        return 0;
    }

    char* input_copy = strdup(input);  // Duplicate input string to avoid modifying original
    int result = sum_tokens(input_copy);  // Calculate the sum of the tokens
    free(input_copy);  // Free the duplicated string
    return result;
}
