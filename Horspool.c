#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256
#define MAX_PATTERN 1000

void preprocessShiftTable(int shiftTable[MAX_CHAR], const char *pattern) {
    int m = strlen(pattern);
    int i;

    for (i = 0; i < MAX_CHAR; i++) {
        shiftTable[i] = m;
    }

    for (i = 0; i < m - 1; i++) {
        shiftTable[(int)pattern[i]] = m - 1 - i;
    }
}

int horspoolSearch(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int shiftTable[MAX_CHAR];
    int i, j;

    preprocessShiftTable(shiftTable, pattern);

    i = m - 1;
    while (i < n) {
        j = 0;
        while (j < m && text[i - j] == pattern[m - 1 - j]) {
            j++;
        }
        if (j == m) {
            return i - m + 1; // pattern found at index i - m + 1
        }
        i += shiftTable[(int)text[i]];
    }

    return -1; // pattern not found
}

int main() {
    const char *text = "The quick brown fox jumps over the lazy dog";
    const char *pattern = "fox";

    int index = horspoolSearch(text, pattern);

    if (index != -1) {
        printf("Pattern found at index %d\n", index);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}
