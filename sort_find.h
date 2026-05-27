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
void sortGeneric(int iter, PROFILE* profile);
void sortByAlphabet(int iter, PROFILE* profile);
void sortByUser(int iter, PROFILE* profile);
void sortByRegion(int iter, PROFILE* profile);
void sortByHobby(int iter, PROFILE* profile);
//// SEARCH FUNCTIONS
void searchByUsername(char* username, char* usernameMatch);
void searchByRegion(char* region, char* regionMatch);
void searchByHobby(char* hobby, char* hobbyMatch);