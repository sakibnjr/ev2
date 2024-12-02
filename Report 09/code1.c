#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 100

// Define the Symbol structure
typedef struct {
    char name[50];
    char type[20];
    char scope[20];
} Symbol;

// Declare symbolTable and symbolCount globally
Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

// Function to insert a symbol into the symbol table
void insertSymbol() {
    if (symbolCount >= MAX_SYMBOLS) {
        printf("Symbol table is full!\n");
        return;
    }

    Symbol newSymbol;
    printf("Enter identifier name: ");
    scanf("%s", newSymbol.name);
    printf("Enter data/return type: ");
    scanf("%s", newSymbol.type);
    printf("Enter scope: ");
    scanf("%s", newSymbol.scope);

    // Insert the new symbol into the symbolTable
    symbolTable[symbolCount++] = newSymbol;
    printf("Symbol added successfully!\n");
}

// Function to display the symbol table
void displaySymbolTable() {
    if (symbolCount == 0) {
        printf("Symbol table is empty!\n");
        return;
    }

    printf("\nSymbol Table:\n");
    printf("Index\tName\tType\tScope\n");
    printf("-------------------------------------\n");
    
    for (int i = 0; i < symbolCount; i++) {
        printf("%d\t%s\t%s\t%s\n", i + 1, symbolTable[i].name, symbolTable[i].type, symbolTable[i].scope);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nSymbol Table Menu:\n");
        printf("1. Insert symbol\n");
        printf("2. Display symbol table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertSymbol(); // Call insertSymbol function
                break;
            case 2:
                displaySymbolTable(); // Call displaySymbolTable function
                break;
            case 3:
                printf("Exiting...\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0; // Ensure main function returns an int value
}
