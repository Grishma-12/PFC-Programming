/* Print monthly expenditure
Practical 2, Part 2 (b)
Grishma Shrestha */

#include<stdio.h>

int main() {
    float foodExpenses = 450.0;
    float leisureExpenses = 75.0;
    float clothesExpenses = 120.0;
    float totalSpent;

    totalSpent = foodExpenses + leisureExpenses + clothesExpenses;

    printf("The total expenditure this month was £%.2f\n\n", totalSpent);

    return 0;
}
