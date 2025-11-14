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

    // initializing digit counters
    int n0 = 0, n1 = 0, n2 = 0, n3 = 0, n4 = 0,
        n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0;

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

        // increasing the counter for this digit
        switch (digit) {
            case 0:
                n0++;
                break;
            case 1:
                n1++;
                break;
            case 2:
                n2++;
                break;
            case 3:
                n3++;
                break;
            case 4:
                n4++;
                break;
            case 5:
                n5++;
                break;
            case 6:
                n6++;
                break;
            case 7:
                n7++;
                break;
            case 8:
                n8++;
                break;
            case 9:
                n9++;
                break;
        }
    }

    const int digitCount = n0 + n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9;
    const bool isValidDigitCount = digitCount <= maxDigitCount;

    // checking for each digit if it exists in user's number
    const int uniqueDigits =
        (n0 > 0 ? 1 : 0) + (n1 > 0 ? 1 : 0) + (n2 > 0 ? 1 : 0) +
        (n3 > 0 ? 1 : 0) + (n4 > 0 ? 1 : 0) + (n5 > 0 ? 1 : 0) +
        (n6 > 0 ? 1 : 0) + (n7 > 0 ? 1 : 0) + (n8 > 0 ? 1 : 0) +
        (n9 > 0 ? 1 : 0);

    const bool isValidUniqueDigits = uniqueDigits <= maxUniqueDigits;

    // checking for each digit if it's shows are valid (<= max shows allowed)
    const bool isValidDigitShows =
        n0 <= maxDigitShows && n1 <= maxDigitShows && n2 <= maxDigitShows &&
        n3 <= maxDigitShows && n4 <= maxDigitShows && n5 <= maxDigitShows &&
        n6 <= maxDigitShows && n7 <= maxDigitShows && n8 <= maxDigitShows &&
        n9 <= maxDigitShows;

    const bool areValidConditions =
        isValidDigitCount && isValidDigitShows && isValidUniqueDigits;

    printf(areValidConditions
        ? "The number given meets all the conditions\n"
        : "The number given does not meet all the conditions\n");

    return 0;
}
