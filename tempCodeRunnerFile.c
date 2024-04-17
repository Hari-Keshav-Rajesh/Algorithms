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