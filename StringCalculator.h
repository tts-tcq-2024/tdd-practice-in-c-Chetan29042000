#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Helper function to check if the input is valid
int is_valid_input(const char* input) {
    return strlen(input) > 0 && (isdigit(input[0]) || input[0] == '-');
}

// Function to get custom delimiter if present
const char* get_custom_delimiter(const char* input, char** remaining_input) {
    const char* newline_pos = strchr(input, '\n');
    if (newline_pos) {
        size_t delimiter_len = newline_pos - input - 2;  // Length of the delimiter
        char* custom_delimiter = (char*)malloc(delimiter_len + 1);
        strncpy(custom_delimiter, input + 2, delimiter_len);
        custom_delimiter[delimiter_len] = '\0';
        *remaining_input = strdup(newline_pos + 1);  // Get remaining input after delimiter
        return custom_delimiter;
    }
    *remaining_input = NULL;
    return NULL;  // No valid custom delimiter found
}

// Helper function to sum up numbers from a tokenized string, ignoring numbers > 1000
int sum_tokens(char* input_copy, const char* delimiters) {
    int sum = 0;
    char* token = strtok(input_copy, delimiters);  // Split the string by the given delimiters

    while (token) {
        int number = atoi(token);  // Convert each token to an integer
        if (number <= 1000) {  // Ignore numbers greater than 1000
            sum += number;
        }
        token = strtok(NULL, delimiters);  // Move to the next token
    }

    return sum;
}

// Function to add numbers in a string
int add(const char* input) {
    if (!is_valid_input(input)) {
        return 0;  // Return 0 for an empty string or invalid first character
    }

    char* input_copy;
    const char* delimiters = ",\n";  // Default delimiters: comma and newline

    if (strncmp(input, "//", 2) == 0) {
        char* remaining_input;
        const char* custom_delimiter = get_custom_delimiter(input, &remaining_input);
        if (custom_delimiter) {
            delimiters = custom_delimiter;  // Use the custom delimiter
            input_copy = remaining_input;  // Use the remaining input
            free((void*)custom_delimiter);  // Free the custom delimiter
        } else {
            input_copy = strdup(input);  // Fallback to original input
        }
    } else {
        input_copy = strdup(input);  // No custom delimiter, just duplicate the input
    }

    int result = sum_tokens(input_copy, delimiters);  // Calculate the sum of the tokens
    free(input_copy);  // Free the duplicated string
    return result;
}
