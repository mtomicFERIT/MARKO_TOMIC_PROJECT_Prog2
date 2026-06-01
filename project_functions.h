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
//// USER ACCOUNT STRUCT
typedef struct userData {
	short userID;
	int age;
	char username[30];
	char password[30];
	char email[50];
	char region[50];
	char userHobby[30];
}PROFILE;

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// MENU NAVIGATION 
void menuMain();
void checkSelection(int selection);
int queryMainMenu();
void settingsMenu();
void memoryMenu();
void fileMenu();

int confirmAction();

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// GENERIC FUNCTIONS
int isPointerValidProfile(PROFILE* profilePTR);
int isPointerValidString(char* charPTR);

////-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-////
//// USER ACCOUNT FUNCTIONS

void displayAccountMenu(int accQuantity);
void printAccount();
void chooseAccount();
int chooseSetting();
void hidePassword(char* password);

void accountRegistration();
void enterUsername(PROFILE* profilePTR);
void enterPassword(PROFILE* profilePTR);
void enterEmail(PROFILE* profilePTR);
void enterAge(PROFILE* profilePTR);
void enterRegion(PROFILE* profilePTR);
void enterHobby(PROFILE* profilePTR);

void loginToAccount();
void logoutOfAccount();

void copyToTxt(PROFILE* currentProfile, FILE* storage);


