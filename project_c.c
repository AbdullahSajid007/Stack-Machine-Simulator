#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "project_c.h"
#define STACK_SIZE 100
#define MAX_INSTRUCTIONS 100
#define MAX_LINE 500

int stack[STACK_SIZE];
int top = -1;

char program[MAX_INSTRUCTIONS][MAX_LINE];
int instructionCount = 0;


/* ================= STACK ================= */

void resetStack() {
    top = -1;
}

void push(int value) {
    if (top >= STACK_SIZE - 1) {
        printf("Error: Stack Overflow!\n");
        return;
    }

    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Error: Stack Underflow!\n");
        return 0;
    }

    return stack[top--];
}

void displayStack() {
    printf("Stack: [");

    for (int i = 0; i <= top; i++) {
        printf("%d", stack[i]);

        if (i < top)
            printf(", ");
    }

    printf("]\n");
}


/* ================= STRING ================= */

void toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}


/* ================= ARITHMETIC ================= */

int ADD() {

    if (top < 1) {
        printf("Error: ADD needs two values.\n");
        return 0;
    }

    int b = pop();
    int a = pop();

    push(a + b);

    return 1;
}


int SUB() {

    if (top < 1) {
        printf("Error: SUB needs two values.\n");
        return 0;
    }

    int b = pop();
    int a = pop();

    push(a - b);

    return 1;
}


int MUL() {

    if (top < 1) {
        printf("Error: MUL needs two values.\n");
        return 0;
    }

    int b = pop();
    int a = pop();

    push(a * b);

    return 1;
}


int DIV() {

    if (top < 1) {
        printf("Error: DIV needs two values.\n");
        return 0;
    }

    int b = pop();
    int a = pop();

    if (b == 0) {
        printf("Error: Division by zero!\n");

        push(a);
        push(b);

        return 0;
    }

    push(a / b);

    return 1;
}


/* ================= DUP ================= */

int DUP() {

    if (top < 0) {
        printf("Error: DUP needs one value.\n");
        return 0;
    }

    push(stack[top]);

    return 1;
}


/* ================= SWAP ================= */

int SWAP() {

    if (top < 1) {
        printf("Error: SWAP needs two values.\n");
        return 0;
    }

    int temp = stack[top];

    stack[top] = stack[top - 1];
    stack[top - 1] = temp;

    return 1;
}


/* ================= EXECUTE ================= */

int executeInstruction(char *instruction) {

    char command[20];
    int value;

    toUpperCase(instruction);


    /* PUSH */

    if (sscanf(instruction, "PUSH %d", &value) == 1) {

        printf("Executing: PUSH %d\n", value);

        push(value);

        displayStack();

        return 1;
    }


    sscanf(instruction, "%s", command);


    /* POP */

    if (strcmp(command, "POP") == 0) {

        printf("Executing: POP\n");

        if (top < 0) {
            printf("Error: Stack Underflow!\n");
            return 0;
        }

        int removed = pop();

        printf("Popped Value: %d\n", removed);

        displayStack();
    }


    /* ADD */

    else if (strcmp(command, "ADD") == 0) {

        printf("Executing: ADD\n");

        if (!ADD())
            return 0;

        displayStack();
    }


    /* SUB */

    else if (strcmp(command, "SUB") == 0) {

        printf("Executing: SUB\n");

        if (!SUB())
            return 0;

        displayStack();
    }


    /* MUL */

    else if (strcmp(command, "MUL") == 0) {

        printf("Executing: MUL\n");

        if (!MUL())
            return 0;

        displayStack();
    }


    /* DIV */

    else if (strcmp(command, "DIV") == 0) {

        printf("Executing: DIV\n");

        if (!DIV())
            return 0;

        displayStack();
    }


    /* DUP */

    else if (strcmp(command, "DUP") == 0) {

        printf("Executing: DUP\n");

        if (!DUP())
            return 0;

        displayStack();
    }


    /* SWAP */

    else if (strcmp(command, "SWAP") == 0) {

        printf("Executing: SWAP\n");

        if (!SWAP())
            return 0;

        displayStack();
    }


    /* INVALID */

    else {

        printf("Error: Invalid Instruction -> %s\n", instruction);

        return 0;
    }

    return 1;
}


/* ================= PARSE PROGRAM ================= */

void parseAndStore(char *line) {

    char *token;

    token = strtok(line, " \t\n");


    while (token != NULL) {

        /* PUSH needs a value */

        if (strcasecmp(token, "PUSH") == 0) {

            char *value = strtok(NULL, " \t\n");

            if (value != NULL) {

                sprintf(
                    program[instructionCount],
                    "PUSH %s",
                    value
                );

                instructionCount++;
            }
        }

        else {

            strcpy(
                program[instructionCount],
                token
            );

            instructionCount++;
        }

        token = strtok(NULL, " \t\n");
    }
}


/* ================= CHECK HALT ================= */

int hasHalt() {

    for (int i = 0; i < instructionCount; i++) {

        char temp[MAX_LINE];

        strcpy(temp, program[i]);

        toUpperCase(temp);

        if (strcmp(temp, "HALT") == 0)
            return 1;
    }

    return 0;
}


/* ================= RESET PROGRAM ================= */

void resetProgram() {

    instructionCount = 0;

    resetStack();

    for (int i = 0; i < MAX_INSTRUCTIONS; i++) {
        program[i][0] = '\0';
    }
}


/* ================= MAIN ================= */

int main() {

    char line[MAX_LINE];
    char choice;


    /* ---------- HEADER ---------- */

    printf("========================================\n");
    printf("        STACK MACHINE SIMULATOR\n");
    printf("========================================\n\n");


    /* ---------- INSTRUCTIONS ---------- */

    printf("Supported Instructions:\n\n");

    printf("PUSH n\n");
    printf("POP\n");
    printf("ADD\n");
    printf("SUB\n");
    printf("MUL\n");
    printf("DIV\n");
    printf("DUP\n");
    printf("SWAP\n");
    printf("HALT\n");


    /* ================= PROGRAM LOOP ================= */

    while (1) {

        resetProgram();


        printf("\nEnter your program (type 'HALT' to execute):\n");


        /* ---------- INPUT PHASE ---------- */

        while (1) {
            printf("> ");
            
            if (fgets(line, sizeof(line), stdin) == NULL)
                return 0;


            /* Ignore empty line */

            if (strlen(line) <= 1)
                continue;


            parseAndStore(line);


            /* Stop input when HALT appears */

            if (hasHalt())
                break;
        }


        /* ---------- EXECUTION ---------- */

        printf("\n========================================\n");
        printf("              EXECUTION\n");
        printf("========================================\n\n");


        int successful = 1;


        for (int i = 0; i < instructionCount; i++) {

            char instruction[MAX_LINE];

            strcpy(
                instruction,
                program[i]
            );

            toUpperCase(instruction);


            /* HALT */

            if (strcmp(instruction, "HALT") == 0) {

                printf("Executing: HALT\n");

                break;
            }


            /* Execute */

            if (!executeInstruction(instruction)) {

                successful = 0;

                printf("\nProgram terminated due to an error.\n");

                break;
            }
        }


        /* ---------- RESULT ---------- */

        printf("\n========================================\n");

        if (successful && top >= 0) {

            printf(
                "Final Result: %d\n",
                stack[top]
            );
        }

        else if (successful) {

            printf("Final Result: Stack is empty.\n");
        }

        printf("========================================\n");


        /* ---------- NEW PROGRAM ---------- */

        printf("\nRun another program? (y/n): ");

        scanf(" %c", &choice);

        /* Clear remaining input */

        while (getchar() != '\n');


        if (choice != 'y' && choice != 'Y') {

            printf("\nSimulator terminated.\n");

            break;
        }
    }


    return 0;
}