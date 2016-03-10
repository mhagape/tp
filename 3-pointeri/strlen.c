#include <stdio.h>

typedef void (*test)();

/* strlen */

size_t strlen(const char *str) {
	return -1;
}

void anEmptyStringShouldHaveLengthZero() {
	size_t stringLength = strlen("");

	if (stringLength != 0)
		printf("FAIL: The length of the empty string should be equal to 0, was %d instead\n", stringLength);
	else
		printf("PASS: The length of the empty string is 0\n");
}

void aStringContainingJustOneCharacterShouldHaveLengthOne() {
	size_t stringLength = strlen("0");

	if (stringLength != 1)
		printf("FAIL: The length of a string containing just one character should be equal to 1, was %d instead\n", stringLength);
	else
		printf("PASS: The length of a string containing just one character is 1\n");
}

void aStringContainingTenCharactersShouldHaveLengthTen() {
	size_t stringLength = strlen("0123456789");

	if (stringLength != 10)
		printf("FAIL: The length of a string containing ten characters should be equal to 10, was %d instead\n", stringLength);
	else
		printf("PASS: The length of a string containing ten characters is 10\n");
}

void runTests(test tests[]) {
	test* currentTest;
	for (currentTest = tests; *currentTest != NULL; ++currentTest)
		(*currentTest)();
}

int main() {

	test tests[] = {
		anEmptyStringShouldHaveLengthZero,
		aStringContainingJustOneCharacterShouldHaveLengthOne,
		aStringContainingTenCharactersShouldHaveLengthTen,
		NULL
	};

	runTests(tests);

	return 0;
}