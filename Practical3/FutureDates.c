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
            if (min == LLONG_MIN && max == LLONG_MAX) {
                printf("Error: number out of range.\n");
            } else {
                printf("Error: please enter a number between %lld and %lld.\n", min, max);
            }
            continue;
        }
        *out = val;
        return 1;
    }
}

int main(void)
{
    long long today;
    long long offset;
    const char *names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    if (!read_int("Enter today\'s day (0=Sunday, 1=Monday, ..., 6=Saturday): ", &today, 0, 6)) {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    if (!read_int("Enter number of days after today: ", &offset, 0, LLONG_MAX)) {
        fprintf(stderr, "Input error\n");
        return 1;
    }
    {
        int future = (int)((today + (offset % 7)) % 7);
        printf("Today is %s and the future day is %s.\n", names[today], names[future]);
    }

    return 0;
}
