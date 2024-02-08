#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

int max(int a, int b) {
    return (a > b) ? a : b;
}

void badCharHeuristic(char *pattern, int patternLength, int badChar[MAX_CHAR]) {
    int i;

    for (i = 0; i < MAX_CHAR; i++) {
        badChar[i] = -1;
    }

    for (i = 0; i < patternLength; i++) {
        badChar[(int)pattern[i]] = i;
    }
}

void searchBoyerMoore(char *text, char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    int badChar[MAX_CHAR];

    badCharHeuristic(pattern, m, badChar);

    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            printf("Pattern found at index %d\n", shift);

            // Shift the pattern to find the next occurrence
            shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
        } else {
            // Use the bad character heuristic to shift the pattern
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

int main() {
    char text[] = "ABABCABABCABABCABX";
    char pattern[] = "ABCAB";

    searchBoyerMoore(text, pattern);

    return 0;
}
