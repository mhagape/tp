#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000000

/*
   Stack
 */

typedef int Stack;

Stack *createStack(size_t size) {
	Stack* stack = (Stack*) malloc(sizeof(Stack) * (size + 1));
	stack[0] = 0;
	return stack;
}

void destroyStack(Stack *stack) {
	free(stack);
}

bool isEmpty(Stack *stack) {
	return !stack[0];
}

void push(Stack *stack, int value) {
	stack[++stack[0]] = value;
}

int pop(Stack *stack) {
	return stack[stack[0]--];
}

int peek(Stack *stack) {
	return stack[stack[0]];
}

/*
   Eval
 */

int evaluateOne(char operator, int left, int right) {
	switch(operator) {
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		default: return left / right;
	}
}

int evaluate(char *expression, Stack *stack) {
	char *currentCharacter;

	for(currentCharacter = expression; *currentCharacter; ++currentCharacter) {
		if(isdigit(*currentCharacter))
			push(stack, *currentCharacter - '0');
		else {
			char operator = *currentCharacter;
			int right = pop(stack);
			int left = pop(stack);
			int result = evaluateOne(operator, left, right);
			push(stack, result);
		}
	}

	return pop(stack);
}

int getOperatorPrecedence(char operator) {
	switch(operator) {
		case '+':
		case '-': return 2;
		case '*': 
		case '/': return 1;
		default: return 0;
	}
}

void append(char **expression, char character) {
	**expression = character;
	++*expression;
}

char *getPostfixNotation(char *infixExpression, char* postfixExpressionO) {
	char *currentCharacter, *postfixExpression = postfixExpressionO;
	Stack *operators = createStack(STACK_SIZE);

	for(currentCharacter = infixExpression; *currentCharacter; ++currentCharacter) {
		if(isdigit(*currentCharacter))
			append(&postfixExpression, *currentCharacter);
		else if(*currentCharacter == ')') {
			while(!isEmpty(operators) && peek(operators) != '(')
				append(&postfixExpression, pop(operators));
			pop(operators);
		}
		else {
			int currentOperatorPrecedence = getOperatorPrecedence(*currentCharacter);
			while(!isEmpty(operators) && peek(operators) != '(' && currentOperatorPrecedence >= getOperatorPrecedence(peek(operators)))
				append(&postfixExpression, pop(operators));
			push(operators, *currentCharacter);
		}
	}
	while(!isEmpty(operators))
		append(&postfixExpression, pop(operators));
	append(&postfixExpression, '\0');

	destroyStack(operators);

	return postfixExpressionO;
}

int main() {
	char expression[] = "2*(3-(1))";
	char postfixExpression[STACK_SIZE];

	Stack *stack = createStack(STACK_SIZE);
	printf("%s\n", getPostfixNotation(expression, postfixExpression));
	printf("%d\n", evaluate(getPostfixNotation(expression, postfixExpression), stack));
	destroyStack(stack);

	return 0;
}
