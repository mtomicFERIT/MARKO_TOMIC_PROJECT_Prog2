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


//// CLOSING FILE
void closeFileTxt(FILE* textFilePointer) {
	fclose(textFilePointer);
}

//// MEMORY WIPE (EMPTYING THE TXT FILE AND FREEING UP DYNAMIC MEMORY)
void freeAllAccounts() {

}

void memsetZeros() {

}

void clearFileTxt(FILE* txt) {

}