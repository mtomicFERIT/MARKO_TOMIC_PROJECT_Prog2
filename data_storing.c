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
#include <io.h>
//// GLOBAL VARIABLES & INLINE FUNCTIONS
// MACROS
#define MAX_P 32
//
extern int accQuantity;
extern PROFILE* activeSession;
extern FILE* textFilePointer;
extern PROFILE profileArray[32];
extern PROFILE* pArrayPTR;
PROFILE* targetAccount;
extern PROFILE** activeDelSession;

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
	if (accHeapOne == NULL) {
		fprintf(stderr, ">Error: Could not find an account to store!\n Pointer is NULL!\n\n");
	}

	printf(">Allocating dynamic memory for one account...\n");
	accHeapOne = (PROFILE*)calloc(1, sizeof(PROFILE));
	if (accHeapOne != NULL) {
		printf(">Memory allocated successfully!\n");
	}
}

//// MEMORY WIPE (EMPTYING STORAGE AND FREEING UP MEMORY)
void freeAllAccounts(FILE* textFilePointer) {
	checkPointerTxt(textFilePointer);
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

FILE* renameFileTxt(FILE* txt, const char* oldFilename) {
	char newFilename[256];

	printf("Enter the new filename (include .txt): ");
	if (scanf("%255s", newFilename) != 1) {
		printf(">Error reading new filename.\n");
		return txt;
	}

	if (txt != NULL) {
		fclose(txt);
	}

	if (rename(oldFilename, newFilename) == 0) {
		printf(">File successfully renamed to '%s'.\n", newFilename);

		FILE* newTxt = fopen(newFilename, "a+");
		if (newTxt == NULL) {
			perror("Error reopening renamed file!\n");
		}
		return newTxt;
	}
	else {
		perror("Error: Rename failed!\n");

		return fopen(oldFilename, "a+");
	}
}

FILE* clearFileTxt(FILE* txt) {
	if (txt == NULL) {
		printf(">Error: Invalid file pointer!\n");
		return NULL;
	}

	fseek(txt, 0, SEEK_END);
	long fileSize = ftell(txt);

	printf("> Current file size before clearing: %ld bytes.\n", fileSize);
	int fileDescriptor = fileno(txt);

	if (_chsize(fileDescriptor, 0) == 0) {
		printf(">File contents successfully cleared.\n");
	}
	else {
		perror("Error: Failed to clear file contents!\n");
		return EOF;
	}
	rewind(txt);
	return(txt);
}