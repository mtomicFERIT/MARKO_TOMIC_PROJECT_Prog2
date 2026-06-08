//// PROJECT_MAIN.C // MAIN.C // SOURCE.C ////
////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
#define _CRT_SECURE_NO_WARNINGS
#pragma once
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
#include <errno.h>

//// GLOBAL VARIABLES & INLINE FUNCTIONS // PROJECT_MAIN.C // PMAIN
// MACROS
#define MAX_P 32
//
extern int accQuantity;
PROFILE* activeSession = NULL;
FILE* textFilePointer = NULL;
PROFILE profileArray[MAX_P] = { 0 };
PROFILE* pArrayPTR = profileArray;
extern PROFILE* targetAccount;
extern PROFILE** activeDelSession;

inline int increment(int inputINT) {
	int resultINT;
	resultINT = inputINT + 1;
	return resultINT;
}

inline int decrement(int inputINT) {
	int resultINT;
	resultINT = inputINT - 1;
	return resultINT;
}

inline int moduloTen(int inputINT) {
	int resultINT;
	resultINT = inputINT % 10;
	return resultINT;
}

//// MAIN PROGRAM EXECUTION ////
int main() {

	extern FILE* textFilePointer;
	const char* fileName = "account_storage.txt";
	textFilePointer = fopen(fileName, "w+");

	openFileTxt(textFilePointer, "account_storage.txt");
	checkPointerTxt(textFilePointer);
	menuMain();
	queryMainMenu();
	closeFileTxt(textFilePointer);

	return 0;

}
