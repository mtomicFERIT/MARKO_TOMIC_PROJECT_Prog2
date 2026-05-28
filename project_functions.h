//// PROJECT_FUNCTIONS.H 
#pragma once
#define _CRT_SECURE_NO_WARNINGS
//// LIBRARIES
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

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// STRUCTURES
//
//// FMTIME STRUCT (Formatted Time)
typedef struct runtime {
	int seconds;
	int minutes;
}FMTIME;

//// DATE STRUCT
typedef struct dayInTime {
	int year;
	int month;
	int day;
}DATE;

//// USER ACCOUNT STRUCT
typedef struct userData {
	char username[30];
	char password[30];
	char email[50];
	char confirmEmail[50];
	char region[50];
	char gender;
	DATE birthday;
	char userHobby[30];
	DATE userSince;
	short userID;
}PROFILE;

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// MENU FUNCTIONS
void menuMain();
void checkSelection(int selection);

void clearHistory();
void backToMenu();

int confirmAction();

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// GENERIC FUNCTIONS
int isPointerValidProfile(PROFILE* profilePTR);
int isPointerValidString(char* charPTR);

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// USER ACCOUNT FUNCTIONS
// 
// SUBFUNCTIONS

void enterUsername(char* nickname, PROFILE* currentProfile);
void enterEmail(char* email, char* emailVerif, PROFILE* currentProfile);
void enterRegion(char* region, PROFILE* currentProfile);
void enterGender(char oneLetter, PROFILE* currentProfile);
void enterDate(DATE* chosenDate, PROFILE* currentProfile);
void enterHobby(char* hobbyPointer, PROFILE* currentProfile);

// MAIN MENU FUNCTIONS
void chooseAccount();
void displayAccountMenu();

void accountRegistration();
void copyToTxt(PROFILE* currentProfile, FILE* storage);

void accountLogin();
void accountLogout();

void settingsMenu();
int chooseSetting();

void refreshPage();
FMTIME fetchDisplayRuntime();


