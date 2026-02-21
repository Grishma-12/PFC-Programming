#include<stdio.h>
int main() {
    double monthlySalary, account = 0;
    double monthlyInterestRate = 0.05 / 12;
    printf("Enter your monthly salary: ");
    scanf("%lf", &monthlySalary);
    for (int i = 1; i <= 6; i++) {
        account = (account + monthlySalary) * (1 + monthlyInterestRate);
    }
    printf("Account value after the sixth month: %.2f\n", account);
    return 0;
}
