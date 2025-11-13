#include <stdbool.h>
#include <stdio.h>

int main() {
    int input, output = 0;

    // validating user's input
    if (scanf("%d", &input) != 1) {
        printf("Error in input!\n");
        return 0;
    }

    const bool isNegative = input < 0;

    // the algorithm works with non-negative numbers only.
    // so, we're taking the absolute value of the input instead.

    if (isNegative) {
        input *= -1;
    }

    while (input > 0) {
        // inserting the last digit of the current `input` value
        // into `output` on the right side
        const int digit = input % 10;
        output = output * 10 + digit;
        input /= 10;
    }

    // adding a minus sign if user's input is negative number
    if (isNegative) {
        output *= -1;
    }

    printf("%d\n", output);

    return 0;
}
