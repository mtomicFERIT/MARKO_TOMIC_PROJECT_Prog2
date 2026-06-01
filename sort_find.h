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
//#include <corecrt.h>

typedef struct userData PROFILE;
//// SORTING FUNCTIONS
void genericSort(PROFILE* profileArray, int numAccounts, int (*compareFunc)(PROFILE*, PROFILE*));
int compareByUsername(PROFILE* firstAcc, PROFILE* secondAcc);
int compareByAge(PROFILE* firstAcc, PROFILE* secondAcc);
int compareByRegions(PROFILE* firstAcc, PROFILE* secondAcc);
int compareByHobbies(PROFILE* firstAcc, PROFILE* secondAcc);
int compareByID(PROFILE* firstAcc, PROFILE* secondAcc);
//// SEARCH FUNCTIONS
void searchByUsername(char* username, char* usernameMatch);
void searchByRegion(char* region, char* regionMatch);
void searchByHobby(char* hobby, char* hobbyMatch);