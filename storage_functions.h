//// STORAGE_FUNCTIONS.H // HEADER FILE FOR MEMORY STORAGE FUNCTIONS ////
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <corecrt_search.h>
//#include <corecrt.h>

#include "project_functions.h"
#include "sort_find.h"

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// TEXT FILE (.txt)
void openFileTxt(FILE* textFilePointer, const char* fileName);
void closeFileTxt(FILE* textFilePointer);
