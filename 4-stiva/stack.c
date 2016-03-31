#include <stdio.h>
#include <stdlib.h>

/* 
Testing
*/

typedef void (*test)();

void displayTestResult(const char *title, char passed) {
	if(passed)
		printf("PASS: %s\n", title);
	else
		printf("FAIL: %s\n", title);
}

void runTests(test tests[]) {
	test* currentTest;
	for (currentTest = tests; *currentTest != NULL; ++currentTest)
		(*currentTest)();
}

/*
Stack
*/

typedef int Stack;

Stack *createStack(size_t size) {
	Stack* stack = (Stack*) malloc(sizeof(Stack) * size);
	stack[0] = 0;
	return stack;
}

void destroyStack(Stack *stack) {
	free(stack);
}

char isEmpty(Stack *stack) {
	return !stack[0];
}

void push(Stack *stack, int value) {
	stack[++stack[0]] = value;
}

int pop(Stack *stack) {
	return stack[stack[0]--];
}

/*
Tests
*/

void afterCreatingAStackTheStackShouldBeEmpty() {
	Stack *stack = createStack(20);

	displayTestResult("After creating a stack the stack should be empty", isEmpty(stack));
	destroyStack(stack);
}

void afterPushingAStackTheStackShouldNotBeEmpty() {
	Stack *stack = createStack(20);

	push(stack, 1);

	displayTestResult("After pushing a stack the stack should not be empty", !isEmpty(stack));
	destroyStack(stack);
}

void afterPoppingAStackWithOneElementTheStackShouldBeEmpty() {
	Stack *stack = createStack(20);

	push(stack, 1);
	pop(stack);

	displayTestResult("After popping a stack with one element the stack should be empty", isEmpty(stack));
	destroyStack(stack);
}

void poppingAStackOnWhichTheFirstTenNaturalNumbersWerePushedInIncreasingOrderShouldReturnThemInDecreasingOrder() {
	Stack *stack = createStack(20);
	int i;
	char passed = 1;

	for(i=0; i<=9; ++i)
		push(stack, i);
	for(i=9; i>=0; --i) {
		int x = pop(stack);
		passed &= i == x;
	}

	displayTestResult("Popping a stack on which the first ten natural numbers were pushed in increasing order shoould return them in decreasing order", passed);
	destroyStack(stack);
}

int main() {
	test tests[] = {
		afterCreatingAStackTheStackShouldBeEmpty,
		afterPushingAStackTheStackShouldNotBeEmpty,
		afterPoppingAStackWithOneElementTheStackShouldBeEmpty,
		poppingAStackOnWhichTheFirstTenNaturalNumbersWerePushedInIncreasingOrderShouldReturnThemInDecreasingOrder,
		NULL
	};

	runTests(tests);

	return 0;
}
