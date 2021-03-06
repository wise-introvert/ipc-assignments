#include<stdio.h>
#include <time.h>
// #include<string>

#include "commonHelpers.h"

int i;

int len(char* string) {
	// return string.length();
	int length = 0;
	for(i = 0; string[i] != '\0'; i++) {
		length += 1;
	}

	return length;
}

int currentYear() {
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + (1900);
}

// As demonstrated in the course notes: https://ict.senecacollege.ca//~ipc144/pages/content/formi.html#buf 
// Empty the standard input buffer 
void clearStandardInputBuffer(void) {
	while (getchar() != '\n') { 
		; // On purpose: do nothing  
	}  
}

int getInteger() {
	int value;
	char end;
	scanf("%d%c", &value, &end);
	if(end == '\n') {
		return value;
	}
	while(end != '\n') {
		clearStandardInputBuffer();
		printf("ERROR: Value must be an integer: ");
		scanf("%d%c", &value, &end);
	}

	return value;
}

int getPositiveInteger() {
	int value;
	char end;
	scanf("%d%c", &value, &end);
	while(end != '\n' || value < 0) {
		if(value > 0) {
			clearStandardInputBuffer();
		}
		printf(end != '\n' ? "ERROR: Value must be an integer: " : "ERROR: Value must be a positive integer greater than zero: ");
		scanf("%d%c", &value, &end);
	}

	return value;
}

double getDouble() {
	double value;
	char end;
	scanf("%lf%c", &value, &end);
	while(end != '\n') {
		clearStandardInputBuffer();
		printf("ERROR: Value must be a double floating-point number: ");
		scanf("%lf%c", &value, &end);
	}

	return value;
}

double getPositiveDouble() {
	double value;
	char end;
	scanf("%lf%c", &value, &end);
	while(end != '\n' || value < 0) {
		if(value > 0) {
			clearStandardInputBuffer();
		}
		printf(end != '\n' ? "ERROR: Value must be a double floating-point number: " : "ERROR: Value must be a positive double floating-point number: ");
		scanf("%lf%c", &value, &end);
	}

	return value;
}

int getIntFromRange(int min, int max) {
	int value;
	char end;
	scanf("%d%c", &value, &end);
	while(end != '\n' || ((value < min) || (value > max))) {
		if(value > min && value < max) {
			clearStandardInputBuffer();
		}
		printf(end != '\n' ? "ERROR: Value must be an integer: " : "ERROR: Value must be between %d and %d inclusive: ", min, max);
		scanf("%d%c", &value, &end);
	}

	return value;
}

char getCharOption(char valid[]) {
	char value;
	char end;
	int isValid = 0;
	scanf(" %c%[\n]", &value, &end);

	if(end == '\n') {
		for(i = 0; valid[i] != '\0'; i++) {
			if(valid[i] == value) {
				isValid = 1;
				return value;
			}
		}
	}


	while(end != '\n' || isValid <= 0) {
		if(isValid > 0) {
			clearStandardInputBuffer();
		}
		printf("ERROR: Character must be one of [%s]: ", valid);
		scanf(" %c%c", &value, &end);

		for(i = 0; valid[i] != '\0'; i++) {
			if(valid[i] == value) {
				isValid = 1;
				return value;
			}
		}
	}

	return value;
}

void getCString(char *string, int min, int max) {
	char value[max];
	char end;
	scanf("%[^\n]%c", &value[0], &end);
	while(end != '\n' || len(value) < min || len(value) > max) {
		if(len(value) >= min && len(value) <= max) {
			clearStandardInputBuffer();
		}
		printf(min == max ? "ERROR: String length must be exactly %d chars: " : len(value) < min ? "ERROR: String length must be no more than %d chars: " : "ERROR: String length must be between %d and %d chars: ", min, max);
		scanf("%[^\n]%c", &value[0], &end);
	}
}
