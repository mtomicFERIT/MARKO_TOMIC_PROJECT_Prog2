//// PROJECT_FUNCTIONS.H 
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <corecrt_search.h>
//#include <corecrt.h>
#include "storage_functions.h"
#include "sort_find.h"

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// STRUCTURES
//
//// DATE STRUCT
typedef struct dayInTime {
	char year[5];
	char month[3];
	char day[3];
}DATE, DATE_UNDEFINED;

//// USER PROFILE STRUCT
typedef struct userData {
	char* const username;
	char* const password;
	char* const email;
	char* const confirmEmail;
	char* const region;
	char gender;
	DATE* birthday;
	char userHobby[30];
	DATE* userSince;
	short userID;
}PROFILE, PROFILE_EMPTY;

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// MENU FUNCTIONS
void menuMain();
void checkSelection(int selection);

void clearHistory();
void backToMenu();

int confirmAction();

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// USER ACCOUNT FUNCTIONS
// 
// SUBFUNCTIONS

void enterUsername(const char* nickname);
void enterEmail(const char* email, const char* emailVerif);
void enterRegion(const char* region);
void enterGender(char oneLetter);
void enterDate(DATE* chosenDate);
void enterHobby(char* hobbyPointer);

// MAIN MENU FUNCTIONS
void chooseAccount();
void displayAccountMenu();

void accountRegistration();
void copyToTxt();

void accountLogin();
void accountLogout();
void deleteAccount();
void deactivateAccount();

void settingsMenu();
void chooseSetting();

void freeAllAccounts();
void memsetZeros();
void clearFileTxt();

void refreshPage();
void fetchRuntime();
void displayTotalRuntime();


