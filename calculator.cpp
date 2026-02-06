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

void calculateF() {
    //Have to do * / % first
    //then continue with + -
    int i = 0;

    // * / %
    while (i < opCount) {
        if (operators[i] == '*' || operators[i] == '/' || operators[i] == '%') {
            int a = numbers[i];
            int b = numbers[i + 1];
            int result;

            if (operators[i] == '*') {
                result = a * b;
            } else if (operators[i] == '/') {
                result = a / b;
            } else {
                result = a % b;
            }

            numbers[i] = result;
            removeNumber(i+1);
            removeOperator(i);

            printExpression();
        } else {
            i++;
        }
    }

    i = 0;

    // + -
    while (i < opCount) {
        int a = numbers[i];
        int b = numbers[i + 1];
        int tempResult;

        if (operators[i] == '+') {
            tempResult = a + b;
        } else{
            tempResult = a - b;
        }

        numbers[i] = tempResult;
        removeNumber(i+1);
        removeOperator(i);

        printExpression();
    }

    result = numbers[0];
    //print out the answer

    printf("-------------------------------\n");
    printf("Answer: %.2f\n", result);
    printf("-------------------------------\n");
}

void removeNumbers(int index) {
    //after calculate, go through a for loop
    //shift the position by 1 in number array
    //then the amount of numbers - 1
    //
    for (int i = 0; i < numCount; i++) {
        numbers[i] = numbers[i + 1];
    } numCount--;
}

//remove operators after done calculate
void removeOperator(int index) {
    //after calculate, go through a for loop
    //shift the position by 1 in operator array
    //then the amount of numbers - 1
    for (int i = 0; i < opCount; i++) {
        operators[i] = operators[i + 1];
    } opCount--;
}