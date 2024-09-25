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
    
    // Convert the input string to an integer and return it
    return atoi(numbers);
}

// Test case function
void TEST_StringCalculatorAddTests_ExpectZeroForSingleZero() {
    int expectedresult = 0;
    const char* input = "0";
    int result = add(input);
    assert(result == expectedresult);
    printf("Test Passed: Expected %d, Got %d\n", expectedresult, result);
}

int main() {
    // Run the test
    TEST_StringCalculatorAddTests_ExpectZeroForSingleZero();
    return 0;
}
