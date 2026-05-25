//// PROJECT_MAIN.C // MAIN.C // SOURCE.C ////
////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#define BOOL_FALSE 0
#define BOOL_TRUE 1
//// LIBRARIES
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <corecrt_search.h>
//#include <corecrt.h>
#include "project_functions.h"
#include "storage_functions.h"
#include "sort_find.h"

//// MAIN PROGRAM EXECUTION
int main() {

	FILE* textFilePointer = NULL;
	const char* fileName = "account_storage.txt";
	textFilePointer = fopen(fileName, "w+");

	openFileTxt(textFilePointer, "account_storage.txt");
	menuMain();
	confirmAction();
	closeFileTxt(textFilePointer);

	return 0;

}
