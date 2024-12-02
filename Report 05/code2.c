#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_KEYWORDS 32

char keywords[NUM_KEYWORDS][20] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "typedef", "union", "unsigned", "void",
    "volatile", "while"
};

// Function to check if a string is a keyword
int isKeyword(char str[]) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a string is a valid identifier
int isValidIdentifier(char str[]) {
    // Check the first character
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0;
    }
    // Check the remaining characters
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%99s", input); // Limiting input to avoid overflow

    if (isKeyword(input)) {
        printf("Keyword\n");
    } else if (isValidIdentifier(input)) {
        printf("Valid Identifier\n");
    } else {
        printf("Invalid Identifier\n");
    }

    return 0;
}
