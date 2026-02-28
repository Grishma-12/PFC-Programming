#include <stdio.h>

int validate_date(int day, int month) {
    if (month < 1 || month > 12) 
    return 0;
    if (day < 1) 
    return 0;
    if (month == 2) {
        return day <= 29; 
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    }
    return day <= 31;
}

int main(void) {
    int n;
    const int MAX_CUSTOMERS = 10;
    int totalUnits = 0;
    int processed = 0;

    printf("How many customers to process (max %d): ", MAX_CUSTOMERS);
    if (scanf("%d", &n) != 1) {
        printf("Error: Invalid input\n");
        return 1;
    }
    if (n < 1 || n > MAX_CUSTOMERS) {
        printf("Error: Number of customers must be between 1 and %d\n", MAX_CUSTOMERS);
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        int prev, curr, day, month;
        int ok = 1;
        printf("\nCustomer %d - enter: previous metre, current metre, day, month: ", i);
        if (scanf("%d %d %d %d", &prev, &curr, &day, &month) != 4) {
            printf("Error: Invalid input format\n");
            while (getchar() != '\n');
            continue;
        }

        printf("%d %d %d %d\n", prev, curr, day, month);

        if (prev < 0 || prev > 9999) {
            printf("Error: previous meter reading out of range\n");
            ok = 0;
        }
        if (curr < 0 || curr > 9999) {
            printf("Error: current meter reading out of range\n");
            ok = 0;
        }
        if (prev > curr) {
            printf("Error: previous reading is more than present reading\n");
            ok = 0;
        }
        if (ok) {
            int used = curr - prev;
            if (used > 1000) {
                printf("Error: electricity used is more than 1000\n");
                ok = 0;
            }
            if (!validate_date(day, month)) {
                printf("Error: day is out of range for this month\n");
                ok = 0;
            }
            if (ok) {
                totalUnits += used;
                processed++;
                printf("Customer %d processed: units=%d\n", i, used);
            }
        }
    }

    printf("\nSummary:\n");
    printf("Requested customers: %d\n", n);
    printf("Successfully processed: %d\n", processed);
    printf("Total electricity units across processed customers: %d\n", totalUnits);
    return 0;
}
