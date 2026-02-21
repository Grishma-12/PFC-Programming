#include <stdio.h>

int main() {
    long currentPopulation = 312032486;
    int secondsPerYear = 365 * 24 * 60 * 60;

    int birthRate  = 7;
    int deathRate  = 13;
    int immigrantRate = 45;

    printf("U.S. Population for the Next 5 Years:\n");
    printf("------------------------------------------------\n");

    for (int i= 1; i <= 5; i++) {
        long births     = secondsPerYear / birthRate;
        long deaths     = secondsPerYear / deathRate;
        long immigrants = secondsPerYear / immigrantRate;

        currentPopulation += births + immigrants - deaths;

        printf("Year %d: %ld\n", i, currentPopulation);
    }

    return 0;
}




