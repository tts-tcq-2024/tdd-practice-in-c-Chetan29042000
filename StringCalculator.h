#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Helper function to check if the input is valid
int is_valid_input(const char* input) {
    return strlen(input) > 0 && (isdigit(input[0]) || input[0] == '-');
}

// Helper function to sum up numbers from a tokenized string, ignoring numbers > 1000
int sum_tokens(char* input_copy, const char* delimiters) {
    int sum = 0;
    char* token = strtok(input_copy, delimiters);  // Split the string by the given delimiters

    while (token != NULL) {
        int number = atoi(token);  // Convert each token to an integer
        if (number <= 1000) {  // Ignore numbers greater than 1000
            sum += number;
        }
        token = strtok(NULL, delimiters);  // Move to the next token
    }
    
    return sum;
}

// Helper function to prepare input and extract custom delimiter
char* prepare_input(const char* input, const char** delimiters) {
    if (strncmp(input, "//", 2) == 0) {
        const char* newline_pos = strchr(input, '\n');
        if (newline_pos != NULL) {
            size_t delimiter_len = newline_pos - input - 2;
            char* custom_delimiter = (char*)malloc(delimiter_len + 1);
            strncpy(custom_delimiter, input + 2, delimiter_len);
            custom_delimiter[delimiter_len] = '\0';
            *delimiters = custom_delimiter;  // Use the custom delimiter
            
            return strdup(newline_pos + 1);  // Return the remaining input
        }
    }
    return strdup(input);  // No custom delimiter, return the original input
}

// Function to add numbers in a string
int add(const char* input) {
    // Return 0 for an empty string or invalid first character
    if (!is_valid_input(input)) {
        return 0;
    }

    const char* delimiters = ",\n";  // Default delimiters: comma and newline
    char* input_copy = prepare_input(input, &delimiters);  // Prepare input and get custom delimiter if present

    // If custom delimiter is defined, adjust strtok to use it correctly
    char* result = input_copy; // Store the input_copy to prevent memory leaks
    for (char* p = input_copy; *p; p++) {
        if (*p == ';') {
            *p = ','; // Replace custom delimiter with the default
        }
    }

    int result_sum = sum_tokens(result, delimiters);  // Calculate the sum of the tokens

    free(input_copy);  // Free the duplicated string
    if (strncmp(input, "//", 2) == 0) {
        free((void*)delimiters);  // Free the custom delimiter if it was used
    }

    return result_sum;
}
