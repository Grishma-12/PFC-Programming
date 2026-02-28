/* Electricity bill
Practical 2, Part 2

Grishma Shrestha */

#include<stdio.h>

int main()
{
    int previousMetre, currentMetre, day, month;
    printf("Enter readings and date (previous metre, current metre, day and month): ");

    if (scanf("%d %d %d %d", &previousMetre, &currentMetre, &day, &month) != 4) {
        printf("Error: Invalid input format\n");
        return 1;
    }

    printf("%d %d %d %d\n", previousMetre, currentMetre, day, month);

    if (currentMetre < 0 || currentMetre > 9999)
        printf("Error: current meter reading out of range\n");

    if (previousMetre < 0 || previousMetre > 9999)
        printf("Error: previous meter reading out of range\n");


    if (previousMetre > currentMetre)
        printf("Error: previous reading is more than present reading\n");

    int electricityUsed = currentMetre - previousMetre;
    if (electricityUsed > 1000)
        printf("Error: electricity used is more than 1000\n");

    if (month < 1 || month > 12)
        printf("Error: month is out of range\n");

    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) &&
        (day < 1 || day > 31))
        printf("Error: day is out of range for this month\n");

    if ((month == 4 || month == 6 || month == 9 || month == 11) &&
        (day < 1 || day > 30))
        printf("Error: day is out of range for this month\n");

    if (month == 2 && (day < 1 || day > 29))
        printf("Error: day is out of range for this month\n");

    return 0;
}
