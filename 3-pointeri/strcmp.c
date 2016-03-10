#include <stdio.h>

typedef void (*test)();

int myStrcmp(const char *first, const char *second) {
  return 0;
}

void comparingTwoEmptyStringsShouldReturnZero() {
  int result = myStrcmp("", "");

  if(result == 0)
		printf("PASS: Comparing two empty strings returned 0\n");
	else
		printf("FAIL: Comparing two empty strings should return 0, returned %d instead\n", result);
}

void comparingANonEmptyStringWithAnEmptyOneShouldReturnAPositiveNumber() {
  int result = myStrcmp("ABCDEF", "");

  if(result > 0)
		printf("PASS: Comparing a non-empty string with an empty one should return a positive number\n");
	else
		printf("FAIL: Comparing a non-empty string with an empty one should return a positive number, returned %d instead\n", result);
}

void comparingAnEmptyStringWithANonEmptyOneShouldReturnANegativeNumber() {
  int result = myStrcmp("", "ABCDEF");

  if(result < 0)
		printf("PASS: Comparing an empty string with a non-empty one should return a negative number\n");
	else
		printf("FAIL: Comparing an empty string with a non-empty one should return a negative number, returned %d instead\n", result);
}

void comparingTwoEqualNonEmptyStringsShouldReturnZero() {
  int result = myStrcmp("ABCDEF", "ABCDEF");

  if(result == 0)
		printf("PASS: Comparing two equal non-empty strings returned 0\n");
	else
		printf("FAIL: Comparing two equal non-empty strings should return 0, returned %d instead\n", result);
}

void comparingANonEmptyStringWithABiggerNonEmptyOneShouldReturnANegativeNumber() {
  int result = myStrcmp("ABCDEF", "ABCZ");

  if(result < 0)
		printf("PASS: Comparing a non-empty string with a bigger one returned a negative number\n");
	else
		printf("FAIL: Comparing a non-empty string with a bigger one should return a negative number, returned %d instead\n", result);
}

void comparingANonEmptyStringWithASmallerNonEmptyOneShouldReturnAPositiveNumber() {
  int result = myStrcmp("ABCZ", "ABCDEF");

  if(result > 0)
		printf("PASS: Comparing a non-empty string with a smaller one returned a positive number\n");
	else
		printf("FAIL: Comparing a non-empty string with a smaller one should return a positive number, returned %d instead\n", result);
}

void runTests(test tests[]) {
	test* currentTest;
	for (currentTest = tests; *currentTest != NULL; ++currentTest)
		(*currentTest)();
}

int main() {

	test tests[] = {
    comparingTwoEmptyStringsShouldReturnZero,
    comparingANonEmptyStringWithAnEmptyOneShouldReturnAPositiveNumber,
    comparingAnEmptyStringWithANonEmptyOneShouldReturnANegativeNumber,
    comparingTwoEqualNonEmptyStringsShouldReturnZero,
    comparingANonEmptyStringWithABiggerNonEmptyOneShouldReturnANegativeNumber,
    comparingANonEmptyStringWithASmallerNonEmptyOneShouldReturnAPositiveNumber,
		NULL
	};

	runTests(tests);

	return 0;
}
