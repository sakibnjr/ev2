#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(const char *str) {
    const char *keywords[] = {
        "int", "float", "char", "double", "string", "if", "else", "for", 
        "while", "do", "return", "void", "switch", "case", "default"
    };
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isDelimiter(char ch) {
    char delimiters[] = " ,;(){}[]";
    for (int i = 0; delimiters[i] != '\0'; i++) {
        if (ch == delimiters[i]) {
            return 1;
        }
    }
    return 0;
}

int isBinaryOperator(char ch) {
    char operators[] = "+-*/=%";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (ch == operators[i]) {
            return 1;
        }
    }
    return 0;
}

int isConstant(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void analyzeTokens(const char *input) {
    char token[100] = "";
    int i = 0, j = 0;
    int insideString = 0;

    while (input[i] != '\0') {
        char ch = input[i];
        if (ch == '"' && !insideString) {
            insideString = 1;
            j = 0;
            token[j++] = ch;
        } else if (insideString) {
            token[j++] = ch;
            if (ch == '"') {
                token[j] = '\0';
                printf("%s is a string literal\n", token);
                insideString = 0;
                j = 0;
            }
        } else if (isDelimiter(ch)) {
            if (j > 0) {
                token[j] = '\0';
                if (isKeyword(token)) {
                    printf("%s is a keyword\n", token);
                } else if (isConstant(token)) {
                    printf("%s is a constant\n", token);
                } else {
                    printf("%s is an identifier\n", token);
                }
                j = 0;
            }
            if (ch != ' ') {
                printf("%c is a delimiter\n", ch);
            }
        } else if (isBinaryOperator(ch)) {
            if (j > 0) {
                token[j] = '\0';
                if (isKeyword(token)) {
                    printf("%s is a keyword\n", token);
                } else if (isConstant(token)) {
                    printf("%s is a constant\n", token);
                } else {
                    printf("%s is an identifier\n", token);
                }
                j = 0;
            }
            printf("%c is a binary operator\n", ch);
        } else {
            token[j++] = ch;
        }
        i++;
    }

    if (j > 0) {
        token[j] = '\0';
        if (isKeyword(token)) {
            printf("%s is a keyword\n", token);
        } else if (isConstant(token)) {
            printf("%s is a constant\n", token);
        } else {
            printf("%s is an identifier\n", token);
        }
    }
}

int main() {
    char input[200];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    analyzeTokens(input);
    return 0;
}
