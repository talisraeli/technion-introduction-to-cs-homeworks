#include <stdbool.h>
#include <stdio.h>

#define MIN_TEMP_ERROR 15.0

int main() {
    // initializing `max` and `min` variables with extreme not-real values,
    // so they'll be assigned later with real data
    double max = -10000, min = 10000;

    double sum = 0, weeklySum = 0;
    int totalDays = 0;

    // temperature assigned by the user's input
    double temp;

    // repeatedly executing the code while there is valid temperature input
    while (scanf("%lf", &temp) == 1) {
        if (temp > max) {
            max = temp;
        }

        if (temp < min) {
            min = temp;
        }

        sum += temp;
        weeklySum += temp;

        totalDays++;
        const bool isWeekend = totalDays % 7 == 0;

        if (isWeekend) {
            const int weekNumber = totalDays / 7;
            const double weeklyAverage = weeklySum / 7;

            printf("Week %d average: %.2lf\n", weekNumber, weeklyAverage);

            weeklySum = 0;
        }
    }

    // validating that there is at least 1 day for displaying temp results
    if (totalDays == 0) {
        return 0;
    }

    printf("Max temp: %.2lf\n", max);
    printf("Min temp: %.2lf\n", min);

    const double average = sum / totalDays;

    if (average < MIN_TEMP_ERROR) {
        printf("Error in input!\n");
        return 0;
    }

    printf("Average temp: %.2lf\n", average);

    return 0;
}
