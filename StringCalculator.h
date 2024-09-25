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

// Helper function to process custom delimiters
const char* get_custom_delimiter(const char* input, char** remaining_input) {
    const char* newline_pos = strchr(input, '\n');
    if (newline_pos != NULL) {
        size_t delimiter_len = newline_pos - input - 2;
        char* custom_delimiter = (char*)malloc(delimiter_len + 1);
        strncpy(custom_delimiter, input + 2, delimiter_len);
        custom_delimiter[delimiter_len] = '\0';
        *remaining_input = strdup(newline_pos + 1);  // Set the remaining part of the input
        return custom_delimiter;
    }
    return NULL;  // Invalid format, return NULL
}

// Main function to add numbers in a string
int add(const char* input) {
    // Return 0 for an empty string or invalid first character
    if (!is_valid_input(input)) {
        return 0;
    }

    const char* delimiters = ",\n";  // Default delimiters: comma and newline
    char* input_copy;

    // Handle custom delimiter
    if (strncmp(input, "//", 2) == 0) {
        char* remaining_input;
        const char* custom_delimiter = get_custom_delimiter(input, &remaining_input);
        if (custom_delimiter == NULL) {
            return 0;  // Invalid format
        }
        delimiters = custom_delimiter;  // Use the custom delimiter
        input_copy = remaining_input;
    } else {
        input_copy = strdup(input);  // No custom delimiter, just duplicate the input
    }

    int result = sum_tokens(input_copy, delimiters);  // Calculate the sum of the tokens

    free(input_copy);  // Free the duplicated string
    if (strncmp(input, "//", 2) == 0) {
        free((void*)delimiters);  // Free the custom delimiter if it was used
    }

    return result;
}
