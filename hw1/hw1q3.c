#include <stdbool.h>
#include <stdio.h>

int main() {
    int maxDigitCount, maxUniqueDigits, maxDigitShows;

    printf("Please enter condition numbers:\n");
    scanf("%d%d%d", &maxDigitCount, &maxUniqueDigits, &maxDigitShows);

    if (maxUniqueDigits < 1 || maxUniqueDigits > 10) {
        printf("Number of unique digits must be between 1 to 10\n");
        return 0;
    }

    // initializing variables
    int digitCount = 0, uniqueDigits = 0, digitShows[10];
    for (int i = 0; i < 10; i++) {
        digitShows[i] = 0;
    }

    bool areValidConditions = true;

    char input;
    printf("Please enter test number:\n");

    // repeatedly executing the code while there is valid input
    while (scanf(" %c", &input) == 1) {

        // converting the char input to int digit
        const int digit = input - '0';
        const bool isValidDigit = digit >= 0 && digit <= 9;

        // if it's not a digit, end the loop
        if (!isValidDigit) {
            break;
        }

        digitCount++;
        digitShows[digit]++;

        // checking if this digit first shown (a new unique digit)
        if (digitShows[digit] == 1) {
            uniqueDigits++;
        }

        const bool isValidDigitCount = digitCount <= maxDigitCount;
        const bool isValidUniqueDigits = uniqueDigits <= maxUniqueDigits;
        const bool isValidDigitShows = digitShows[digit] <= maxDigitShows;

        if (!isValidDigitCount || !isValidDigitShows || !isValidUniqueDigits) {
            areValidConditions = false;
        }
    }

    printf(areValidConditions
        ? "The number given meets all the conditions\n"
        : "The number given does not meet all the conditions\n");

    return 0;
}
