#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

static int read_int(const char *prompt, long long *out, long long min, long long max)
{
    char buf[128];
    char *endptr;
    long long val;

    while (1) {
        printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) {
            return 0;
        }
        buf[strcspn(buf, "\n")] = '\0';
        errno = 0;
        val = strtoll(buf, &endptr, 10);
        if (endptr == buf || *endptr != '\0') {
            printf("Error: please enter a valid integer.\n");
            continue;
        }
        if ((errno == ERANGE && (val == LLONG_MAX || val == LLONG_MIN)) || val < min || val > max) {
            printf("Error: please enter a number between %lld and %lld.\n", min, max);
            continue;
        }
        *out = val;
        return 1;
    }
}

static int is_leap_year(long long year)
{
   
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(void)
{
    long long month, year;
    if (!read_int("Enter month (1-12): ", &month, 1, 12)) {
        fprintf(stderr, "Input error\n");
        return 1;
    }
    if (!read_int("Enter year (e.g. 2015): ", &year, 1, LLONG_MAX)) {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    int days;
    switch ((int)month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
            days = is_leap_year(year) ? 29 : 28;
            break;
        default:
            days = 0;
    }

    const char *mnames[] = {"", "January", "February", "March", "April",
                            "May", "June", "July", "August", "September",
                            "October", "November", "December"};

    printf("%s %lld has %d day%s.\n", mnames[month], year, days, days == 1 ? "" : "s");
    return 0;
}
