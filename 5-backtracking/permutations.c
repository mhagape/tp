#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Stack
*/

typedef int Stack;

Stack *createStack(size_t size) {
	//TODO: Make size -> size+1 in all stacks
	Stack* stack = (Stack*) malloc(sizeof(Stack) * (size+1));
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

int peek(Stack *stack) {
	return stack[stack[0]];
}

int count(Stack *stack) {
	return stack[0];
}

int pop(Stack *stack) {
	return stack[stack[0]--];
}

void print(Stack *stack) {
	int i, stackSize=count(stack);

	for(i=1; i<stackSize; ++i)
		printf("%d, ", stack[i]);
	printf("%d\n", stack[i]);

}


/*
Permutations
*/

bool isSolution(Stack *stack, int n) {
	int i, nrElem = count(stack);
	
	if(nrElem != n)
		return false;
	for(i=1; i<=nrElem; ++i)
		if(stack[i] > n)
			return false;
	return true;
	
}

bool isPartialSolution(Stack *stack, int n) {
	int i, nrElem = count(stack);

	if(nrElem >= n)
		return false;
	for(i=1; i<=nrElem; ++i)
		if(stack[i] > n)
			return false;
	return true;
}

void generatePermutations(Stack *stack, int n) {
	do {
		while(isPartialSolution(stack, n))
			push(stack, 1);

		if(isSolution(stack, n))
			print(stack);

		while(!isEmpty(stack) && peek(stack) == n)
			pop(stack);
		if(!isEmpty(stack))
			push(stack, pop(stack) + 1);
	} while(!isEmpty(stack)); 
}

int main() {
	int n = 3;

	Stack *stack = createStack(n);
	generatePermutations(stack, n);
	destroyStack(stack);

	return 0;
}
