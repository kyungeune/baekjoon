#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[102];
    char answer;

    while (1) {
        answer = fgets(s, sizeof(s), stdin);
        if (answer == NULL)
            break;
        if (s[strlen(s) + 1] == NULL)
            break;
        printf("%s", s);
    }

    return 0;
}