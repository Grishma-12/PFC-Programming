#include <stdio.h> 
int main() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9.0 / 5) +32;
    printf("The temperature in Fahrenheit is: %.2lf\n", fahrenheit);
    return 0;
}