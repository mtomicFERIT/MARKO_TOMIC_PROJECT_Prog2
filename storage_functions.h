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
#include <io.h>
#include <errno.h>

//// GLOBAL VARIABLES // STORAGE_FUNCTIONS.H
// MACROS
#define MAX_P 32

typedef struct userData PROFILE;
////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// TEXT FILE (.txt)
void openFileTxt(FILE* textFilePointer, const char* fileName);
int checkPointerTxt(FILE* textFilePointer);
void closeFileTxt(FILE* textFilePointer);
FILE* renameFileTxt(FILE* txt, const char* oldName);
FILE* clearFileTxt(FILE* txt);
//// ACCOUNT CREATE//READ//INSERT//UPDATE//DELETE (CRUD) FUNCTIONS
void storeAccount(PROFILE* accHeapOne);
void copyToTxt(const PROFILE* currentProfile, FILE* storage);
void deleteAccount(PROFILE* profileArray, int* numAccounts, int targetID, PROFILE** activeDelSession);
void freeAllAccounts(FILE* textFilePointer);
void memsetZeros(FILE* textFilePointer);
//// ACCOUNT SETTINGS CONFIGURATION
void changeUsername(PROFILE* user_account);

