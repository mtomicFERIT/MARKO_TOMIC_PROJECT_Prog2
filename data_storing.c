//// DATA_STORING.C // EXECUTABLE C FILE FOR DYNAMIC MEMORY STORAGE ////
#pragma once
#define _CRT_SECURE_NO_WARNINGS
//// LIBRARIES
#include "project_functions.h"
#include "storage_functions.h"
#include "sort_find.h"
//// DEFAULT
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <corecrt_search.h>
//#include <corecrt.h>
//// GLOBAL VARIABLES & INLINE FUNCTIONS
// MACROS
#define MAX_P 32
//
extern int accQuantity;
extern PROFILE* activeSession;
extern FILE* textFilePointer;
extern PROFILE profileArray[32];
extern PROFILE* pArrayPTR;

//// OPENING FILE
void openFileTxt(FILE* textFilePointer, const char* fileName) {
	textFilePointer = fopen(fileName, "w+");
}

//// POINTER CHECKUP // FAIL-SAFE
// FILE
int checkPointerTxt(FILE* textFilePointer) {
	if (textFilePointer == NULL) {
		printf(">Could not find the wanted text file!");
		return EXIT_FAILURE;
	}
	else {
		return 0;
	}
}
// PROFILE
int isPointerValidProfile(PROFILE* profilePTR) {
	if (profilePTR == NULL) {
		perror("Could not find the wanted account!");
		return EXIT_FAILURE;
	}
	else {
		return 0;
	}
}
// STRING
int isPointerValidString(char* charPTR) {
	if (charPTR == NULL) {
		perror("Could not find the wanted string parameter.");
		return EXIT_FAILURE;
	}
	else {
		return 0;
	}
}

//// GLOBAL VARIABLES
int i = 0;
int accAmount = 0;
PROFILE* accHeapOne = NULL;

//// CLOSING FILE
void closeFileTxt(FILE* textFilePointer) {
	fclose(textFilePointer);
}

//// ACCOUNT STORAGE
void storeAccount(PROFILE* accHeapOne) {
	printf(">Allocating dynamic memory for one account...\n");
			accHeapOne = (PROFILE*)calloc(1, sizeof(PROFILE));
}

//// MEMORY WIPE (EMPTYING STORAGE AND FREEING UP MEMORY)
void freeAllAccounts(FILE* textFilePointer) {
	int i;
	extern int accAmount;
	extern PROFILE* accHeapOne;
	if (accHeapOne == NULL || accAmount <= 0) {
		printf(">Could not find memory to free!");
		printf("\n");
	}
	else {
		for (i = 0; i < accAmount; i++) {
			free(accHeapOne);
			if ((accHeapOne == NULL) && (i == accAmount)) {
				exit(EXIT_SUCCESS);
			}
		}
	}

}

void memsetZeros(FILE* textFilePointer) {
	extern int accAmount;
	extern PROFILE* accHeapOne;
	memset(textFilePointer, 0, accAmount * sizeof(accHeapOne));
}

void clearFileTxt(FILE* txt) {
	rewind(txt);
}