#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// Helper function to check if a string contains a number
int isNumber(const char* str) {
    if (str == NULL || strlen(str) == 0) return 0;
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i]) && str[i] != '-') {
            return 0;
        }
    }
    return 1;
}

int add(const char* input) {
    if (input == NULL || strlen(input) == 0) {
        return 0;
    }
}
