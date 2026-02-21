/* Print monthly expenditure with accommodation and travel
Practical 2, Part 2 (c)
Grishma Shrestha */

#include<stdio.h>

int main() {
    float foodExpenses = 450.0;
    float leisureExpenses = 75.0;
    float clothesExpenses = 120.0;
    float accommodationExpenses = 500.0;
    float travelExpenses = 200.0;
    float totalSpent;

    totalSpent = foodExpenses + leisureExpenses + clothesExpenses + accommodationExpenses + travelExpenses;

    printf("The total expenditure this month was £%.2f\n\n", totalSpent);

    return 0;
}
