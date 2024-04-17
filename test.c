#include <stdio.h>
#include <string.h>

#define MAX 256

void createShiftTable(int shiftTable[MAX],char* pattern){
    int m = strlen(pattern);

    for(int i=0;i<MAX;i++)
        shiftTable[i] = m;

    for(int i=0;i<m;i++)
        shiftTable[(int)pattern[i]] = m-i-1;
}

int horspool(char* text,char * pattern){
    int m = strlen(pattern);
    int n = strlen(text);

    int shiftTable[MAX];

    createShiftTable(shiftTable,pattern);

    int i = m - 1,j;

    while(i<n){
        j = 0;
        while(j<m&&text[i-j]==pattern[m-1-j])
            j++;
        if(j==m)
            return i-m+1;
        else
            i+=shiftTable[(int)text[i]];
    }
    return -1;
}

int main() {
    char *text = "The quick brown fox jumps over the lazy dog";
    char *pattern = "fox";

    int index = horspool(text, pattern);

    if (index != -1) {
        printf("Pattern found at index %d\n", index);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}