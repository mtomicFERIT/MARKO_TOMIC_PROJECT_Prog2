//// PROJECT_MAIN.C // MAIN.C // SOURCE.C ////
////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#define BOOLTRUE 1
#define BOOLFALSE 0
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

////CODE VISIBLE TO ALL FUNCTIONS // GLOBAL VARIABLES & INLINE FUNCTIONS
FILE* textFilePointer = NULL;

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

//// MAIN PROGRAM EXECUTION
int main() {

	extern FILE* textFilePointer;
	const char* fileName = "account_storage.txt";
	textFilePointer = fopen(fileName, "w+");

	openFileTxt(textFilePointer, "account_storage.txt");
	extern checkFileTxt(textFilePointer);
	menuMain();
	confirmAction();
	closeFileTxt(textFilePointer);

	return 0;

}
