//// USER_FUNCTIONS.C
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

extern FILE* textFilePointer;

int confirmAction() {
	char request = '0';
	printf("\n");
	printf(">Are you sure you wish to proceed?\n Enter 'Y' to confirm, or 'N' to exit: \n");
	scanf(" %c", &request);
	if (request == 'Y' || request == 'y') {
		return 0;
	}
	else if (request == 'N' || request == 'n') {
		printf(">Exiting program...");
		exit(EXIT_SUCCESS);
	}
	else {
		printf(">Something went wrong while requesting confirmation of a decision.");
		confirmAction();
		return 0;
	}
}

void checkSelection(int selection) {

	enum startMenu { EXIT, AREG, LOGIN, LOGOUT, DELETE, SORTSEARCH, ERASE_MENU, FILE_MENU };
	if (selection == EXIT) {
		freeAllAccounts(textFilePointer);
		memsetZeros(textFilePointer);
		printf("\n>Exiting application...");
		exit(0);
	}
	else if (selection == AREG) {
		accountRegistration();
		//copyToTxt();
	}
	else if (selection == LOGIN) {
		//displayAccountMenu();
		//chooseAccount();
		//loginToAccount();
	}
	else if (selection == LOGOUT) {
		//displayAccountMenu();
		//chooseAccount();
		//logoutOfAccount();
	}
	else if (selection == DELETE) {
		//displayAccountMenu();
		//chooseAccount();
		//deleteAccount();
	}
	else if (selection == SORTSEARCH) {
		
	}
	else if (selection == ERASE_MENU) {
		
	}
	else if (selection == FILE_MENU) {

	}

}

//// ACCOUNT REGISTRATION

void accountRegistration() {

	int accQuantity = 0;
	printf("How many accounts to register?\n");
	scanf("%d", &accQuantity);

	printf(">REGISTRATION WINDOW ------------------------------------------------ \n");
	printf(">Register new User: \n");
	//void enterUsername();
	//void enterPassword();
	printf("\t>E-mail: \n");
	//void enterEmail();
	printf("\t>Age:");
	//void enterAge();
	printf("\t>Country/Region: \n");
	//void enterRegion();
	printf("\t>Interests/Hobbies: \n");
	//void enterHobby();
	printf(">REGISTRATION WINDOW ------------------------------------------------ \n ");
}
/*
	char username[24];
	char* const password;
	char* const email;
	char* const confirmEmail;
	char* const region;
	char userHobby[30];
	short userID;
*/

void enterUsername(int* profileID) {
	printf(">Enter account username: \n");
	//scanf("%[^\n]", &nickname);
}

void enterPassword(int* profileID) {
	char* password = { 0 };
	printf(">Enter password: \n");
	scanf("%31s", password);
	hidePassword(password);
}

int hidePassword(char* password) {
	int passPos;
	for (passPos = 0; password[passPos] != '\0'; passPos++) {
		password[passPos] = '*';
	}
	return passPos;
}

void enterEmail(int* profileID) {
	/*scanf("%[^\n]", &email);
	printf("\t>Confirm e-mail: \n");
	scanf("%[^\n]", &emailVerif);
	do {
		enterEmail(email, emailVerif);
		if (emailVerif != email) {
			printf("\t\t>Could not verify e-mail! Please try again.");
		}
	} while (emailVerif != email);
	if (emailVerif == email) {
		printf("\t\t>E-mail verification successful.");
	}*/
}

void enterRegion(int* profileID) {

}

void enterHobby(int* profileID) {

}

void printAccount() {
	PROFILE* currentProfile;
	currentProfile = NULL;
	printf(">Account ID: %d \n", currentProfile->userID);
	printf(">Username: %31s \n", currentProfile->username);
	printf(">Age: %d \n", currentProfile->age);
	printf(">Region: %51s \n", currentProfile->region);
	printf(">Hobby: %31s \n", currentProfile->userHobby);
}

void copyToTxt(PROFILE* currentProfile, FILE* storage) {

}

//// LOG INTO ACCOUNT
void chooseAccount() {

}

void loginToAccount() {

}

//// LOG OUT OF ACCOUNT
void logoutOfAccount() {

}

//// DELETION

void deleteAccount() {

}

//// SORTING & SEARCHING ACCOUNTS

void sortGeneric(int iter, PROFILE* profile) {

}

void sortByAlphabet(int iter, PROFILE* profile) {

}

void sortByUser(int iter, PROFILE* profile) {

}

void sortByRegion(int iter, PROFILE* profile) {

}

void sortByHobby(int iter, PROFILE* profile) {

}

void searchByUsername(char* username, char* usernameMatch) {

}

void searchByRegion(char* region, char* regionMatch) {

}

void searchByHobby(char* hobby, char* hobbyMatch) {

}