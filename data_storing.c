//// DATA_STORING.C // EXECUTABLE C FILE FOR DYNAMIC MEMORY STORAGE ////
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <corecrt.h>
#include "project_functions.h"
#include "storage_functions.h"
#include "sort_find.h"

//// OPENING FILE
void openFileTxt(FILE* textFilePointer, const char* fileName) {
	textFilePointer = fopen(fileName, "w+");
}

//// CLOSING FILE
void closeFileTxt(FILE* textFilePointer) {
	fclose(textFilePointer);
}