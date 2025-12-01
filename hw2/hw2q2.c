#include <stdbool.h>
#include <stdio.h>

#define ERROR_STRING "There was an error in input\n"
#define PARTS_COUNT 8
#define MIN_VALUES 0
#define MAX_VALUES 50
#define SPECIAL_VALUES (-1)
#define HEALTH_AMOUNT 100

int main() {
    int values[PARTS_COUNT];
    bool firstShipMarks[PARTS_COUNT], secondShipMarks[PARTS_COUNT];

    printf("Please enter ship's parts value:\n");

    // getting parts' values input
    for (int i = 0; i < PARTS_COUNT; i++) {
        if (scanf("%d", &values[i]) != 1) {
            printf("%s", ERROR_STRING);
            return 0;
        }

        const bool isValidInput =
            (values[i] >= MIN_VALUES && values[i] <= MAX_VALUES)
            || values[i] == SPECIAL_VALUES;

        if (!isValidInput) {
            printf("%s", ERROR_STRING);
            return 0;
        }
    }

    printf("Please enter first ship's hit marks:\n");

    // getting first ship marks input
    for (int i = 0; i < PARTS_COUNT; i++) {
        int input;
        if (scanf("%d", &input) != 1) {
            printf("%s", ERROR_STRING);
            return 0;
        }
        firstShipMarks[i] = input;
    }

    printf("Please enter second ship's hit marks:\n");

    // getting second ship marks input
    for (int i = 0; i < PARTS_COUNT; i++) {
        int input;
        if (scanf("%d", &input) != 1) {
            printf("%s", ERROR_STRING);
            return 0;
        }
        secondShipMarks[i] = input;
    }

    int firstShipHealth = HEALTH_AMOUNT, secondShipHealth = HEALTH_AMOUNT;

    // calculating marks damage
    for (int i = 0; i < PARTS_COUNT; i++) {
        const bool isFirstShipAlive = firstShipHealth > 0;
        const bool isSecondShipAlive = secondShipHealth > 0;

        // checking if any ship is alive
        if (!isFirstShipAlive && !isSecondShipAlive) {
            break;
        }

        const int value =
            values[i] == SPECIAL_VALUES
            ? HEALTH_AMOUNT
            : values[i];

        firstShipHealth -= firstShipMarks[i] * value;
        secondShipHealth -= secondShipMarks[i] * value;
    }

    const bool isFirstShipAlive = firstShipHealth > 0;
    const bool isSecondShipAlive = secondShipHealth > 0;

    if (!isFirstShipAlive && !isSecondShipAlive) {
        printf("Both ships have lost the battle!\n");
        return 0;
    }

    if (isFirstShipAlive && isSecondShipAlive) {
        printf("Both ships survived the battle!\n");
        return 0;
    }

    const char whoWon = isFirstShipAlive ? '1' : '2';

    printf("Ship #%c has won the battle!\n", whoWon);

    return 0;
}
