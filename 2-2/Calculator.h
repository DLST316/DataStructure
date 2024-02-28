#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdlib.h>
#include "lls.h"

typedef enum
{
    LEFT_PARENTHESIS = '(',RIGHT_PARENTHESIS = ')',
    PLUS     = '+', MINUS  = '-',
    MULTIPLY = '*', DIVIDE = '/',
    SPACE = ' ',    OPERAND
} SYMBOL;

int          IsNumber(char cipher);
unsigned int GetNextToken(char* expression, char* token, int* type);
int          IsPrior(char op1, char op2);
int          GetPriority(char operator, int inStack);
void         GetPostFix(char* in, char* post);
double       Calculate(char* post);

#endif
