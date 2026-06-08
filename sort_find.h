//// SORT_FIND.H // SORT_SEARCH.H ////
#pragma once
#define _CRT_SECURE_NO_WARNINGS
//// LIBRARIES
#include "project_functions.h"
#include "storage_functions.h"
//// DEFAULT
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <corecrt_search.h>
#include <io.h>
#include <errno.h>

//// GLOBAL VARIABLES // SORT_FIND.H
// MACROS
#define MAX_P 32

typedef struct userData PROFILE;

//// SORTING FUNCTIONS
void sortMenu(PROFILE* profiles, int numProfiles);

void genericSort(PROFILE* profileArray, int numAccounts, int (*compareFunc)(PROFILE*, PROFILE*));
int compareByUsernameNAlph(PROFILE* firstAcc, PROFILE* secondAcc);
int compareByUsernameRAlph(PROFILE* firstAcc, PROFILE* secondAcc);
int compareByAge(PROFILE* firstAcc, PROFILE* secondAcc);
int compareByRegions(PROFILE* firstAcc, PROFILE* secondAcc);
int compareByHobbies(PROFILE* firstAcc, PROFILE* secondAcc);
int compareByID(PROFILE* firstAcc, PROFILE* secondAcc);

//// SEARCH FUNCTIONS
void genericSearch(PROFILE* profileArray, int numAccounts, void* searchTerm, int (*matchFunc)(PROFILE*, void*));
int matchByUsername(PROFILE* p, void* searchTerm);
int matchOlderThan(PROFILE* p, void* searchTerm);
int matchYoungerThan(PROFILE* p, void* searchTerm);
int matchByRegion(PROFILE* p, void* searchTerm);
int matchByHobby(PROFILE* p, void* searchTerm);
int matchByID(PROFILE* p, void* searchTerm);




