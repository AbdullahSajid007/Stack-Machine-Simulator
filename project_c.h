#ifndef PROJECT_C_H
#define PROJECT_C_H

void resetStack();
void push(int value);
int pop();
void displayStack();
void toUpperCase(char *str);
int ADD();
int SUB();
int MUL();
int DIV();
int DUP();
int SWAP();
int executeInstruction(char *instruction);
void parseAndStore(char *line);
int hasHalt();
void resetProgram();

#endif // PROJECT_C_H
