#include <stdio.h>
#include <ctype.h>

#define MAX 100
#define ARR 50

char expression[MAX];
float result;
int numbers[ARR];
int operators[ARR];

int numCount = 0;
int opCount = 0;

void extractExpression();
void calculateF();
void printExpression();
void removeNumber(int index);
void removeOperator(int index);

int main() {
    printf("Enter the expression that you want to calculate: ");
    scanf("%s", expression);
    extractExpression();
    calculateF();
}

void extractExpression() {
    //going through while loop it it's the end of the expression or not
    //check if it's a number or operator with isdigit()
    //add those in the number array or operator array
    int i = 0;
    int currentNum = 0;

    while (expression[i] != '\0') {
        //check the digit or operators with if-else
        if (isdigit(expression[i])) {
            currentNum = currentNum * 10 + (expression[i] - '0');
        } else {
            numbers[numCount++] = currentNum;
            operators[opCount++] = expression[i];
            currentNum = 0;
        }
        i++;
    }
    
    numbers[numCount++] = currentNum;

    //for debug
    printf("Numbers: ");
    for (int i = 0; i < numCount; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\nOperators: ");
    for (int i = 0; i < opCount; i ++) {
        printf("%c ", operators[i]);
    }

    printf("\n");
}