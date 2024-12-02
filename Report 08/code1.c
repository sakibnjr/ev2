#include <stdio.h>
#include <string.h>

void removeComments(const char *input, char *output) {
    int i = 0, j = 0;
    int insideSingleLineComment = 0, insideMultiLineComment = 0;

    while (input[i] != '\0') {
        if (insideSingleLineComment) {
            if (input[i] == '\n') {
                insideSingleLineComment = 0;
                output[j++] = input[i];
            }
        } else if (insideMultiLineComment) {
            if (input[i] == '*' && input[i + 1] == '/') {
                insideMultiLineComment = 0;
                i++;
            }
        } else {
            if (input[i] == '/' && input[i + 1] == '/') {
                insideSingleLineComment = 1;
                i++;
            } else if (input[i] == '/' && input[i + 1] == '*') {
                insideMultiLineComment = 1;
                i++;
            } else {
                output[j++] = input[i];
            }
        }
        i++;
    }
    output[j] = '\0';
}

int main() {
    char input[1000], output[1000];
    printf("Enter the input code (end with EOF or Ctrl+D):\n");

    int index = 0, ch;
    while ((ch = getchar()) != EOF) {
        input[index++] = (char)ch;
    }
    input[index] = '\0';

    removeComments(input, output);
    printf("\nCode without comments:\n%s\n", output);

    return 0;
}
