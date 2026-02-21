/* Print monthly expenditure with accommodation as constant
Practical 2, Part 2 (e)
Grishma Shrestha */

#include<stdio.h>

int main() {
    const float ACCOMMODATION = 500.0;

    float foodExpenses;
    float leisureExpenses;
    float clothesExpenses;
    float travelExpenses;
    float totalSpent;

    printf("\nEnter food expenses: ");
    scanf("%f", &foodExpenses);

    printf("Enter leisure expenses: ");
    scanf("%f", &leisureExpenses);

    printf("Enter clothes expenses: ");
    scanf("%f", &clothesExpenses);

    printf("Enter travel expenses: ");
    scanf("%f", &travelExpenses);

    totalSpent = foodExpenses + leisureExpenses + clothesExpenses + ACCOMMODATION + travelExpenses;

    printf("\nThe total expenditure this month was £%.2f\n", totalSpent);
    printf("(Accommodation fixed at £%.2f)\n\n", ACCOMMODATION);

    return 0;
}
