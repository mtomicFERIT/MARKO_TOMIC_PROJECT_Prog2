//// ACCOUNT_CONFIG.C // ACCOUNT SETTINGS CONFIGURATION ////
#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
//// GLOBAL VARIABLES & INLINE FUNCTIONS
// MACROS
#define MAX_P 32
extern int accQuantity;
extern PROFILE* activeSession;
extern FILE* textFilePointer;
extern PROFILE profileArray[32];
extern PROFILE* pArrayPTR;

//// ACCOUNT SETTINGS CONFIGURATION
int chooseSetting() {
	int accSettingChosen = 0;
	return accSettingChosen;
}

//// CHANGING SPECIFIC SETTING(S)
void changeUsername(PROFILE* user_account) {

}
