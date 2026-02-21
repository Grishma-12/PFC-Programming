/* Secure monthly expenditure calculator with fgets (safer string input)
Practical 2, Part 3 - Alternative Secure Implementation
Grishma Shrestha
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_LEN 50

float getValidExpenseFgets(const char* expenseType) {
    float expense = -1.0;
    char inputBuffer[MAX_INPUT_LEN];
    int result;
    
    while (expense < 0) {
        printf("Enter %s (must be >= 0): ", expenseType);
        
        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) {
            printf("ERROR: Failed to read input.\n");
            continue;
        }
        
        result = sscanf(inputBuffer, "%f", &expense);
        
        if (result != 1) {
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
    
    printf("===== MONTHLY EXPENDITURE CALCULATOR (FGETS SECURE VERSION) =====\n");
    printf("This program calculates your total monthly spending.\n");
    printf("Accommodation is fixed at £%.2f\n", ACCOMMODATION);
    printf("Note: This version uses fgets() for enhanced input security.\n\n");
    
    foodExpenses = getValidExpenseFgets("food expenses");
    leisureExpenses = getValidExpenseFgets("leisure expenses");
    clothesExpenses = getValidExpenseFgets("clothes expenses");
    travelExpenses = getValidExpenseFgets("travel expenses");
    
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
