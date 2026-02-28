#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>



static int read_pin(const char *prompt, long long *out)
{
    char buf[128];
    char *endptr;
    long long val;

    printf("%s", prompt);
    if (!fgets(buf, sizeof(buf), stdin))
        return 0;
    buf[strcspn(buf, "\n")] = '\0';
    if (buf[0] == '\0') {
        return -1; 
    }
    errno = 0;
    val = strtoll(buf, &endptr, 10);
    if (endptr == buf || *endptr != '\0') {
        return -1;
    }
    if (errno == ERANGE && (val == LLONG_MAX || val == LLONG_MIN)) {
        return -1;
    }
    *out = val;
    return 1;
}

int main(void)
{
    const long long CORRECT_PIN = 1234;
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;
    long long entered;

    while (attempts < MAX_ATTEMPTS) {
        int status = read_pin("Enter PIN: ", &entered);
        if (status == 0) {
            puts("Error reading input.");
            return 1;
        }
        if (status < 0) {
            puts("Error: Invalid input, numbers only.");
            continue; 
        }
        if (entered == CORRECT_PIN) {
            puts("Access Granted!");
            return 0;
        } else {
            attempts++;
            int left = MAX_ATTEMPTS - attempts;
            if (left > 0) {
                printf("Wrong PIN. %d attempt(s) left.\n", left);
            }
        }
    }

    puts("Access Denied. Account Locked.");
    return 0;
}
