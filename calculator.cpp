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