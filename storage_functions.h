//// STORAGE_FUNCTIONS.H // HEADER FILE FOR MEMORY STORAGE FUNCTIONS ////
#pragma once
#define _CRT_SECURE_NO_WARNINGS
//// LIBRARIES
#include "project_functions.h"
#include "sort_find.h"
//// DEFAULT
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <corecrt_search.h>
//#include <corecrt.h>

typedef struct userData PROFILE;
////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// TEXT FILE (.txt)
void openFileTxt(FILE* textFilePointer, const char* fileName);
int checkFileTxt(FILE* txt);
void closeFileTxt(FILE* textFilePointer);
//// ACCOUNT CREATE//READ//INSERT//UPDATE//DELETE (CRUD) FUNCTIONS
void storeAccount(FILE* textFilePointer);
void deleteAccount();
void freeAllAccounts(FILE* textFilePointer);
void memsetZeros(FILE* textFilePointer);
void clearFileTxt(FILE* txt);
//// ACCOUNT SETTINGS CONFIGURATION
void changeUsername(PROFILE* user_account);

