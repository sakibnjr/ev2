#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100];
    char letters[100] = "";
    char digits[100] = "";
    char specialChars[100] = "";
    char logicalOperators[100] = "";

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int i = 0;
    while (input[i] != '\0') {
        if (isalpha(input[i])) {
            strncat(letters, &input[i], 1);
        } else if (isdigit(input[i])) {
            strncat(digits, &input[i], 1);
        } else if (strchr("+-|&", input[i]) && strchr("+-|&", input[i + 1])) {
            strncat(logicalOperators, &input[i], 1);
            strncat(logicalOperators, &input[i + 1], 1);
            i++;
        } else {
            strncat(specialChars, &input[i], 1);
        }
        i++;
    }

    printf("Letters: %s\n", letters);
    printf("Digits: %s\n", digits);
    printf("Special Character: %s\n", specialChars);
    printf("Logical Operator: %s\n", logicalOperators);

    return 0;
}
