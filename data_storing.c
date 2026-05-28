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

//// OPENING FILE
void openFileTxt(FILE* textFilePointer, const char* fileName) {
	textFilePointer = fopen(fileName, "w+");
}

//// POINTER CHECKUP // FAIL-SAFE
// FILE
int checkPointer(FILE* textFilePointer) {
	if (textFilePointer == NULL) {
		perror("Could not find the wanted text file.");
		return EXIT_FAILURE;
	}
	else {
		return 0;
	}
}
// PROFILE
int isPointerValidProfile(PROFILE* profilePTR) {
	if (profilePTR == NULL) {
		perror("Could not find the wanted account.");
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
void storeAccount(FILE* textFilePointer) {
	//int i = 0;
	//int accAmount = 0;
	//PROFILE* accHeapOne = NULL;
	printf(">How many accounts would you like to store?\n");
	scanf("%d", &accAmount);
	printf(">Allocating dynamic memory for %d accounts...\n", accAmount);
	if (accAmount <= 0) {
		printf("\t>Please choose a non-negative number!\n");
		printf("\n");
		storeAccount(textFilePointer);
	}
	else {
		for (i = 0; i < accAmount; i++) {
			accHeapOne = (PROFILE*)calloc(1, sizeof(PROFILE));
		}
	}
}

//// MEMORY WIPE (EMPTYING STORAGE AND FREEING UP MEMORY)
void freeAllAccounts(FILE* textFilePointer) {
	int i;
	extern int accAmount;
	extern PROFILE* accHeapOne;
	if (accHeapOne == NULL || accAmount <= 0) {
		printf(">Error: Could not find memory to free!");
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
	memset(textFilePointer, 0, accAmount*sizeof(accHeapOne));
}

void clearFileTxt(FILE* txt) {
	rewind(txt);
}