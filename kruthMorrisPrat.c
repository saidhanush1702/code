#include <stdio.h>
#include <string.h>

// Function to build the lps (longest proper prefix which is also suffix) array
void computeLPSArray(char *pattern, int patternLength, int *lps) {
    int len = 0; // Length of the previous longest prefix suffix

    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < patternLength) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // Move len characters backward in the pattern
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function
void searchKMP(char *text, char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    int lps[m]; // Array to store the longest proper prefix which is also suffix

    // Preprocess the pattern to build the lps array
    computeLPSArray(pattern, m, lps);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                // Move j characters backward in the pattern
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char text[] = "ABABCABABCABABCABX";
    char pattern[] = "ABCAB";

    // Search for the pattern in the text using KMP algorithm
    searchKMP(text, pattern);

    return 0;
}
