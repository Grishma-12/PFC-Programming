/* Secure monthly expenditure calculator with input validation
Practical 2, Part 3 - Secure and Best Practice Programming
Grishma Shrestha
*/

#include<stdio.h>
#include<stdlib.h>

float getValidExpense(const char* expenseType) {
    float expense = -1.0;
    int result;
    
    while (expense < 0) {
        printf("Enter %s (must be >= 0): ", expenseType);
        
        result = scanf("%f", &expense);
        
        if (result != 1) {
            while (getchar() != '\n');
            printf("ERROR: Invalid input. Please enter a valid number.\n");
            expense = -1.0;
            continue;
        }
        
        if (expense < 0) {
            printf("ERROR: Expense cannot be negative. Please enter a positive value.\n");
            expense = -1.0;
        }
    }
    
    return expense;
}

int main() {
    const float ACCOMMODATION = 500.0;
    
    float foodExpenses;
    float leisureExpenses;
    float clothesExpenses;
    float travelExpenses;
    float totalSpent;
    
    printf("===== MONTHLY EXPENDITURE CALCULATOR (SECURE VERSION) =====\n");
    printf("This program calculates your total monthly spending.\n");
    printf("Accommodation is fixed at £%.2f\n\n", ACCOMMODATION);
    
    foodExpenses = getValidExpense("food expenses");
    leisureExpenses = getValidExpense("leisure expenses");
    clothesExpenses = getValidExpense("clothes expenses");
    travelExpenses = getValidExpense("travel expenses");
    
    totalSpent = foodExpenses + leisureExpenses + clothesExpenses + ACCOMMODATION + travelExpenses;
    
    printf("\n===== EXPENDITURE BREAKDOWN =====\n");
    printf("Food Expenses:        £%.2f\n", foodExpenses);
    printf("Leisure Expenses:     £%.2f\n", leisureExpenses);
    printf("Clothes Expenses:     £%.2f\n", clothesExpenses);
    printf("Accommodation:        £%.2f (fixed)\n", ACCOMMODATION);
    printf("Travel Expenses:      £%.2f\n", travelExpenses);
    printf("------------------------------\n");
    printf("TOTAL EXPENDITURE:    £%.2f\n\n", totalSpent);
    
    return 0;
}
