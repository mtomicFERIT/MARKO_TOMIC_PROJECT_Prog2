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

//// SENSITIVE INFO STRUCT
typedef struct personalInfo {
	char* const region;
	char gender;
	DATE* birthday;
	char userHobby[30];
}SENSITIVE_INFO;

//// USER PROFILE STRUCT
typedef struct userData {
	char* const username;
	char* const password;
	char* const email;
	char* const confirmEmail;
	short userID;
	SENSITIVE_INFO userInfo;
}PROFILE, PROFILE_EMPTY;

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// MENU FUNCTIONS
void menuMain();
void checkSelection(int selection);

void clearHistory();
void backToMenu();

int confirmAction(char request);

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// USER ACCOUNT FUNCTIONS

void enterUsername(char* const username);
//void changeUsername(PROFILE *user_account);
void accountRegistration();
void accountLogin();
void accountDeactivation();
void accountDeletion();


